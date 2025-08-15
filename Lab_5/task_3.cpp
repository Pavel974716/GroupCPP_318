#include <iostream>
#include <string>

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�

// ���ᨬ��쭮� ������⢮ ��த��
const size_t MAX_CITIES = 1000;

// ������� �������
struct Country;
struct Capital;
struct Region;
struct City;

struct Continent {
    std::string name;
    Country** countries = nullptr; // ���ᨢ 㪠��⥫�� �� ��࠭�
    size_t countryCount = 0;       // ������⢮ ��࠭
};

struct Country {
    std::string name;
    Continent* continent = nullptr; // 㪠��⥫� �� ���ਪ
    Capital* capital = nullptr;     // 㪠��⥫� �� �⮫���
};

struct Capital {
    std::string name;
    Country* country = nullptr; // 㪠��⥫� �� ��࠭�
};

struct Region {
    std::string name;
    Country* country = nullptr; // 㪠��⥫� �� ��࠭�
};

struct City {
    std::string name;
    Region* region = nullptr;      // ॣ���
    Capital* capital = nullptr;    // �⮫��
    Country* country = nullptr;    // ��࠭�
    Continent* continent = nullptr;// ���ਪ
};

// �������� ���ᨢ�
Region* allRegions[MAX_CITIES] = { nullptr };
size_t regionCount = 0;

Capital* allCapitals[MAX_CITIES] = { nullptr };
size_t capitalCount = 0;

City* allCities[MAX_CITIES] = { nullptr };
size_t totalCities = 0;

// ���������� ��࠭� � ���ਪ
void addCountryToContinent(Continent* continent, Country* country) {
    // ������� ���� ���ᨢ 㪠��⥫�� �� ��࠭�
    Country** newArray = new(std::nothrow) Country*[continent->countryCount + 1];
    if (!newArray) {
        std::cerr << "�訡�� �뤥����� ����� ��� ��࠭!\n";
        return;
    }

    // �����㥬 ���� 㪠��⥫�
    for (size_t i = 0; i < continent->countryCount; ++i) {
        newArray[i] = continent->countries[i];
    }

    // ������塞 ����� ��࠭�
    newArray[continent->countryCount] = country;

    // ����塞 ���� ���ᨢ, �᫨ �� ��
    delete[] continent->countries;

    // ���࠭塞 ���� ���ᨢ � ���⨭���
    continent->countries = newArray;
    ++continent->countryCount;
}

// ���� ��த� �� �����
City* findCity(City** cities, size_t count, const std::string& cityName) {
    for (size_t i = 0; i < count; ++i) {
        if (cities[i] && cities[i]->name == cityName) {
            return cities[i];
        }
    }
    return nullptr;
}

// ���������� ��த� � �易���� ��ꥪ⮢
void addCity(const std::string& countryName,
             const std::string& capitalName,
             const std::string& regionName,
             const std::string& cityName,
             Continent* continent) {

    // ������� ��࠭�
    Country* country = new(std::nothrow) Country;
    if (!country) { std::cerr << "�訡�� �뤥����� ����� ��� ��࠭�!\n"; return; }
    country->name = countryName;
    country->continent = continent;

    // ������� �⮫���
    Capital* capitalPtr = new(std::nothrow) Capital;
    if (!capitalPtr) { std::cerr << "�訡�� �뤥����� ����� ��� �⮫���!\n"; return; }
    capitalPtr->name = capitalName;
    capitalPtr->country = country;
    allCapitals[capitalCount++] = capitalPtr;

    // �ਢ�뢠�� �⮫��� � ��࠭�
    country->capital = capitalPtr;

    // ������� ॣ���
    Region* regionPtr = new(std::nothrow) Region;
    if (!regionPtr) { std::cerr << "�訡�� �뤥����� ����� ��� ॣ����!\n"; return; }
    regionPtr->name = regionName;
    regionPtr->country = country;
    allRegions[regionCount++] = regionPtr;

    // ������� ��த
    City* city = new(std::nothrow) City;
    if (!city) { std::cerr << "�訡�� �뤥����� ����� ��� ��த�!\n"; return; }
    city->name = cityName;
    city->region = regionPtr;
    city->capital = capitalPtr;
    city->country = country;
    city->continent = continent;

    // ������塞 ��࠭� � ���⨭���
    addCountryToContinent(continent, country);

    // ������塞 ��த � �������� ���ᨢ
    if (totalCities < MAX_CITIES) {
        allCities[totalCities++] = city;
    } else {
        std::cerr << "�ॢ�襭 ����� ��த��!\n";
        delete city;
    }
}

// ������� �㭪�� Task_3
void Task_3() {

    // ������� ���⨭����
    Continent* asia = new Continent;
    asia->name = "����";

    Continent* europe = new Continent;
    europe->name = "��ய�";

    Continent* america = new Continent;
    america->name = "���ਪ�";

    // ������塞 ����묨
    addCity("�����", "��᪢�", "��᪮�᪠� �������", "��᪢�", asia);
    addCity("�࠭��", "��ਦ", "���-��-�࠭�", "��ਦ", europe);
    addCity("���", "��設�⮭", "�.C.", "��設�⮭", america);
    addCity("��������⠭��", "������", "������᪨� ࠩ��", "������", europe);
    addCity("������", "�����", "����", "�����", asia);
    addCity("��⠩", "�����", "�����᪨� ॣ���", "�����", asia);
    addCity("��ଠ���", "��૨�", "��૨�᪠� �������", "��૨�", europe);
    addCity("������", "��⠢�", "���ਮ", "��⠢�", america);
    addCity("���ᨪ�", "��娪�", "����ࠫ�� ����", "��娪�", america);
    addCity("�⠫��", "���", "��樮", "���", europe);

    // �᭮���� 横� ���᪠
    while (true) {
        std::string inputCity = in_string("������ �������� ��த� (��� q ��� ��室�): ");
        if (inputCity == "q" || inputCity == "Q")
            break;

        City* foundCity = findCity(allCities, totalCities, inputCity);
        if (!foundCity) {
            std::cout << "������ ���ଠ�� ���������.\n\n";
            continue;
        }

        std::cout << "\n�������/ॣ���: "
                  << (foundCity->region ? foundCity->region->name : "��� ������") << '\n';
        std::cout << "�⮫��: "
                  << (foundCity->capital ? foundCity->capital->name : "��� ������") << '\n';
        std::cout << "��࠭�/���㤠��⢮: "
                  << (foundCity->country ? foundCity->country->name : "��� ������") << '\n';
        std::cout << "���ਪ: "
                  << (foundCity->continent ? foundCity->continent->name : "��� ������") << "\n\n";
    }

    // �������� �����
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
        delete allCities[i]->country; // ��࠭� (�᫨ �� 㤠���� ࠭��)
        delete allCities[i];
        allCities[i] = nullptr;
    }
    totalCities = 0;

    // ����塞 ���⨭����
    Continent* continents[] = { asia, europe, america };
    for (auto& cont : continents) {
        delete[] cont->countries;
        cont->countries = nullptr;
        delete cont;
        cont = nullptr;
    }
}
