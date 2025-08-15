#include <iostream>
#include <string>

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки

// Максимальное количество городов
const size_t MAX_CITIES = 1000;

// Объявления структур
struct Country;
struct Capital;
struct Region;
struct City;

struct Continent {
    std::string name;
    Country** countries = nullptr; // массив указателей на страны
    size_t countryCount = 0;       // количество стран
};

struct Country {
    std::string name;
    Continent* continent = nullptr; // указатель на материк
    Capital* capital = nullptr;     // указатель на столицу
};

struct Capital {
    std::string name;
    Country* country = nullptr; // указатель на страну
};

struct Region {
    std::string name;
    Country* country = nullptr; // указатель на страну
};

struct City {
    std::string name;
    Region* region = nullptr;      // регион
    Capital* capital = nullptr;    // столица
    Country* country = nullptr;    // страна
    Continent* continent = nullptr;// материк
};

// Глобальные массивы
Region* allRegions[MAX_CITIES] = { nullptr };
size_t regionCount = 0;

Capital* allCapitals[MAX_CITIES] = { nullptr };
size_t capitalCount = 0;

City* allCities[MAX_CITIES] = { nullptr };
size_t totalCities = 0;

// Добавление страны в материк
void addCountryToContinent(Continent* continent, Country* country) {
    // Создаем новый массив указателей на страны
    Country** newArray = new(std::nothrow) Country*[continent->countryCount + 1];
    if (!newArray) {
        std::cerr << "Ошибка выделения памяти для стран!\n";
        return;
    }

    // Копируем старые указатели
    for (size_t i = 0; i < continent->countryCount; ++i) {
        newArray[i] = continent->countries[i];
    }

    // Добавляем новую страну
    newArray[continent->countryCount] = country;

    // Удаляем старый массив, если он был
    delete[] continent->countries;

    // Сохраняем новый массив в континент
    continent->countries = newArray;
    ++continent->countryCount;
}

// Поиск города по имени
City* findCity(City** cities, size_t count, const std::string& cityName) {
    for (size_t i = 0; i < count; ++i) {
        if (cities[i] && cities[i]->name == cityName) {
            return cities[i];
        }
    }
    return nullptr;
}

// Добавление города и связанных объектов
void addCity(const std::string& countryName,
             const std::string& capitalName,
             const std::string& regionName,
             const std::string& cityName,
             Continent* continent) {

    // Создаем страну
    Country* country = new(std::nothrow) Country;
    if (!country) { std::cerr << "Ошибка выделения памяти для страны!\n"; return; }
    country->name = countryName;
    country->continent = continent;

    // Создаем столицу
    Capital* capitalPtr = new(std::nothrow) Capital;
    if (!capitalPtr) { std::cerr << "Ошибка выделения памяти для столицы!\n"; return; }
    capitalPtr->name = capitalName;
    capitalPtr->country = country;
    allCapitals[capitalCount++] = capitalPtr;

    // Привязываем столицу к стране
    country->capital = capitalPtr;

    // Создаем регион
    Region* regionPtr = new(std::nothrow) Region;
    if (!regionPtr) { std::cerr << "Ошибка выделения памяти для региона!\n"; return; }
    regionPtr->name = regionName;
    regionPtr->country = country;
    allRegions[regionCount++] = regionPtr;

    // Создаем город
    City* city = new(std::nothrow) City;
    if (!city) { std::cerr << "Ошибка выделения памяти для города!\n"; return; }
    city->name = cityName;
    city->region = regionPtr;
    city->capital = capitalPtr;
    city->country = country;
    city->continent = continent;

    // Добавляем страну в континент
    addCountryToContinent(continent, country);

    // Добавляем город в глобальный массив
    if (totalCities < MAX_CITIES) {
        allCities[totalCities++] = city;
    } else {
        std::cerr << "Превышен лимит городов!\n";
        delete city;
    }
}

// Главная функция Task_3
void Task_3() {

    // Создаем континенты
    Continent* asia = new Continent;
    asia->name = "Азия";

    Continent* europe = new Continent;
    europe->name = "Европа";

    Continent* america = new Continent;
    america->name = "Америка";

    // Заполняем данными
    addCity("Россия", "Москва", "Московская область", "Москва", asia);
    addCity("Франция", "Париж", "Иль-де-Франс", "Париж", europe);
    addCity("США", "Вашингтон", "Д.C.", "Вашингтон", america);
    addCity("Великобритания", "Лондон", "Лондонский район", "Лондон", europe);
    addCity("Япония", "Токио", "Канто", "Токио", asia);
    addCity("Китай", "Пекин", "Пекинский регион", "Пекин", asia);
    addCity("Германия", "Берлин", "Берлинская область", "Берлин", europe);
    addCity("Канада", "Оттава", "Онтарио", "Оттава", america);
    addCity("Мексика", "Мехико", "Федеральный округ", "Мехико", america);
    addCity("Италия", "Рим", "Лацио", "Рим", europe);

    // Основной цикл поиска
    while (true) {
        std::string inputCity = in_string("Введите название города (или q для выхода): ");
        if (inputCity == "q" || inputCity == "Q")
            break;

        City* foundCity = findCity(allCities, totalCities, inputCity);
        if (!foundCity) {
            std::cout << "Данная информация отсутствует.\n\n";
            continue;
        }

        std::cout << "\nОбласть/регион: "
                  << (foundCity->region ? foundCity->region->name : "Нет данных") << '\n';
        std::cout << "Столица: "
                  << (foundCity->capital ? foundCity->capital->name : "Нет данных") << '\n';
        std::cout << "Страна/государство: "
                  << (foundCity->country ? foundCity->country->name : "Нет данных") << '\n';
        std::cout << "Материк: "
                  << (foundCity->continent ? foundCity->continent->name : "Нет данных") << "\n\n";
    }

    // Удаление памяти
    for (size_t i = 0; i < regionCount; ++i) {
        delete allRegions[i];
        allRegions[i] = nullptr;
    }
    regionCount = 0;

    for (size_t i = 0; i < capitalCount; ++i) {
        delete allCapitals[i];
        allCapitals[i] = nullptr;
    }
    capitalCount = 0;

    for (size_t i = 0; i < totalCities; ++i) {
        delete allCities[i]->country; // страна (если не удалена ранее)
        delete allCities[i];
        allCities[i] = nullptr;
    }
    totalCities = 0;

    // Удаляем континенты
    Continent* continents[] = { asia, europe, america };
    for (auto& cont : continents) {
        delete[] cont->countries;
        cont->countries = nullptr;
        delete cont;
        cont = nullptr;
    }
}
