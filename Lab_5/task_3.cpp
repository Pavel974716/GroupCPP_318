#include <iostream>
#include <string>
#include <memory>

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки

// Объявляем константу до использования
const size_t MAX_CITIES = 1000;

// Объявления структур
struct Country;
struct Capital;
struct Region;
struct City;

struct Continent {
    std::string name;
    std::shared_ptr<Country> *countries = nullptr; // Динамический массив стран
    size_t countryCount = 0; // Число элементов массива
};

struct Country {
    std::string name;
    std::weak_ptr<Continent> continent;
    std::shared_ptr<Capital> capital;
};

struct Capital {
    std::string name;
    std::weak_ptr<Country> country;
};

struct Region {
    std::string name;
    std::weak_ptr<Country> country;
};

struct City {
    std::string name;
    std::shared_ptr<Region> region; // Используем shared_ptr для региона
    std::shared_ptr<Capital> capital; // Используем shared_ptr для столицы
    std::weak_ptr<Country> country; // Ссылка на страну
    std::weak_ptr<Continent> continent; // Ссылка на материк
};

// Глобальные массивы для хранения регионов и столиц
Region *allRegions[MAX_CITIES];
size_t regionCount = 0;

Capital *allCapitals[MAX_CITIES];
size_t capitalCount = 0;

// Массив городов
std::shared_ptr<City> allCities[MAX_CITIES];
size_t totalCities = 0;

// Функция для добавления страны к континенту (расширение массива)
void addCountryToContinent(std::shared_ptr<Continent> & continent, std::shared_ptr<Country> country) {
    auto newArray = new std::shared_ptr<Country>[continent->countryCount + 1];
    for (size_t i = 0; i < continent->countryCount; ++i) {
        newArray[i] = continent->countries[i];
    }
    newArray[continent->countryCount] = country;
    delete[] continent->countries; // Освобождаем старый массив
    continent->countries = newArray;
    ++continent->countryCount;
}

// Функция поиска города по имени
std::shared_ptr<City> findCity(const std::shared_ptr<City> *cities, size_t count, const std::string & cityName) {
    for (size_t i = 0; i < count; ++i) {
        if (cities[i]->name == cityName) {
            return cities[i];
        }
    }
    return nullptr;
}

// Функция для добавления города
void addCity(const std::string & countryName,
             const std::string & capitalName,
             const std::string & regionName,
             const std::string & cityName,
             std::shared_ptr<Continent> continent) {

    // Создаем страну
    auto country = std::make_shared<Country>();
    country->name = countryName;
    country->continent = continent;

    // Создаем столицу и сохраняем в глобальный массив
    auto capitalPtr = new Capital();
    capitalPtr->name = capitalName;

    // Связываем столицу с страной через weak_ptr
    capitalPtr->country = country;

    allCapitals[capitalCount++] = capitalPtr;

    // Связываем страну с ее столицей через shared_ptr
    country->capital.reset(capitalPtr);

    // Создаем регион через make_shared и сохраняем в глобальный массив
    auto regionSharedPtr = std::make_shared<Region>();
    regionSharedPtr->name = regionName;
    regionSharedPtr->country = country;

    allRegions[regionCount++] = regionSharedPtr.get();

    // Создаем город и связываем его с регионом, страной и материком
    auto city = std::make_shared<City>();
    city->name = cityName;
    city->region = regionSharedPtr;
    city->capital = std::shared_ptr<Capital>(capitalPtr);
    city->country = country;
    city->continent = continent;

    // Добавляем страну в континент
   addCountryToContinent(continent, country);

   // Добавляем город в глобальный массив городов
   if (totalCities < MAX_CITIES) {
       allCities[totalCities++] = city;
   } else {
       std::cerr << "Превышен лимит городов!\n";
   }
}

// Главная функция Task_3
void Task_3() {

   // Создаем континенты
   auto asia = std::make_shared<Continent>();
   asia->name = "Азия";

   auto europe = std::make_shared<Continent>();
   europe->name = "Европа";

   auto america = std::make_shared<Continent>();
   america->name = "Америка";

   // Добавляем города и страны
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

   while (true) {
        std::string inputCity;
        inputCity = in_string("Введите название города (или q для выхода): ");

       if (inputCity == "q" || inputCity == "Q")
           break;

       auto foundCity= findCity(allCities, totalCities, inputCity);
       if (!foundCity) {
           std::cout << "Данная информация отсутствует.\n\n";
           continue;
       }

       auto regionPtr= foundCity->region;
       auto capitalPtr= foundCity->capital;
       auto countryPtr= foundCity->country.lock();
       auto continentPtr= foundCity->continent.lock();

       std::cout << "\nОбласть/регион: "
                 << (regionPtr ? regionPtr->name : "Нет данных") << '\n';

       std::cout << "\nСтолица: "
                 << (capitalPtr ? capitalPtr->name : "Нет данных") << '\n';

       std::cout << "\nСтрана/государство: "
                 << (countryPtr ? countryPtr->name : "Нет данных") << '\n';

       std::cout << "\nМатерик: "
                 << (continentPtr ? continentPtr->name : "Нет данных") << std::endl;
       std::cout << '\n';
   }

   // Освобождение памяти для объектов регионов и столиц
   for (size_t i=0; i < regionCount; ++i)
       delete allRegions[i];

   for (size_t i=0; i < capitalCount; ++i)
       delete allCapitals[i];
}
