#include <iostream>
#include <string>
#include <memory>

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�

// ���塞 ����⠭�� �� �ᯮ�짮�����
const size_t MAX_CITIES = 1000;

// ������� �������
struct Country;
struct Capital;
struct Region;
struct City;

struct Continent {
    std::string name;
    std::shared_ptr<Country> *countries = nullptr; // �������᪨� ���ᨢ ��࠭
    size_t countryCount = 0; // ��᫮ ����⮢ ���ᨢ�
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
    std::shared_ptr<Region> region; // �ᯮ��㥬 shared_ptr ��� ॣ����
    std::shared_ptr<Capital> capital; // �ᯮ��㥬 shared_ptr ��� �⮫���
    std::weak_ptr<Country> country; // ��뫪� �� ��࠭�
    std::weak_ptr<Continent> continent; // ��뫪� �� ���ਪ
};

// �������� ���ᨢ� ��� �࠭���� ॣ����� � �⮫��
Region *allRegions[MAX_CITIES];
size_t regionCount = 0;

Capital *allCapitals[MAX_CITIES];
size_t capitalCount = 0;

// ���ᨢ ��த��
std::shared_ptr<City> allCities[MAX_CITIES];
size_t totalCities = 0;

// �㭪�� ��� ���������� ��࠭� � ���⨭���� (���७�� ���ᨢ�)
void addCountryToContinent(std::shared_ptr<Continent> & continent, std::shared_ptr<Country> country) {
    auto newArray = new std::shared_ptr<Country>[continent->countryCount + 1];
    for (size_t i = 0; i < continent->countryCount; ++i) {
        newArray[i] = continent->countries[i];
    }
    newArray[continent->countryCount] = country;
    delete[] continent->countries; // �᢮������� ���� ���ᨢ
    continent->countries = newArray;
    ++continent->countryCount;
}

// �㭪�� ���᪠ ��த� �� �����
std::shared_ptr<City> findCity(const std::shared_ptr<City> *cities, size_t count, const std::string & cityName) {
    for (size_t i = 0; i < count; ++i) {
        if (cities[i]->name == cityName) {
            return cities[i];
        }
    }
    return nullptr;
}

// �㭪�� ��� ���������� ��த�
void addCity(const std::string & countryName,
             const std::string & capitalName,
             const std::string & regionName,
             const std::string & cityName,
             std::shared_ptr<Continent> continent) {

    // ������� ��࠭�
    auto country = std::make_shared<Country>();
    country->name = countryName;
    country->continent = continent;

    // ������� �⮫��� � ��࠭塞 � �������� ���ᨢ
    auto capitalPtr = new Capital();
    capitalPtr->name = capitalName;

    // ���뢠�� �⮫��� � ��࠭�� �१ weak_ptr
    capitalPtr->country = country;

    allCapitals[capitalCount++] = capitalPtr;

    // ���뢠�� ��࠭� � �� �⮫�楩 �१ shared_ptr
    country->capital.reset(capitalPtr);

    // ������� ॣ��� �१ make_shared � ��࠭塞 � �������� ���ᨢ
    auto regionSharedPtr = std::make_shared<Region>();
    regionSharedPtr->name = regionName;
    regionSharedPtr->country = country;

    allRegions[regionCount++] = regionSharedPtr.get();

    // ������� ��த � ��뢠�� ��� � ॣ�����, ��࠭�� � ���ਪ��
    auto city = std::make_shared<City>();
    city->name = cityName;
    city->region = regionSharedPtr;
    city->capital = std::shared_ptr<Capital>(capitalPtr);
    city->country = country;
    city->continent = continent;

    // ������塞 ��࠭� � ���⨭���
   addCountryToContinent(continent, country);

   // ������塞 ��த � �������� ���ᨢ ��த��
   if (totalCities < MAX_CITIES) {
       allCities[totalCities++] = city;
   } else {
       std::cerr << "�ॢ�襭 ����� ��த��!\n";
   }
}

// ������� �㭪�� Task_3
void Task_3() {

   // ������� ���⨭����
   auto asia = std::make_shared<Continent>();
   asia->name = "����";

   auto europe = std::make_shared<Continent>();
   europe->name = "��ய�";

   auto america = std::make_shared<Continent>();
   america->name = "���ਪ�";

   // ������塞 ��த� � ��࠭�
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

   while (true) {
        std::string inputCity;
        inputCity = in_string("������ �������� ��த� (��� q ��� ��室�): ");

       if (inputCity == "q" || inputCity == "Q")
           break;

       auto foundCity= findCity(allCities, totalCities, inputCity);
       if (!foundCity) {
           std::cout << "������ ���ଠ�� ���������.\n\n";
           continue;
       }

       auto regionPtr= foundCity->region;
       auto capitalPtr= foundCity->capital;
       auto countryPtr= foundCity->country.lock();
       auto continentPtr= foundCity->continent.lock();

       std::cout << "\n�������/ॣ���: "
                 << (regionPtr ? regionPtr->name : "��� ������") << '\n';

       std::cout << "\n�⮫��: "
                 << (capitalPtr ? capitalPtr->name : "��� ������") << '\n';

       std::cout << "\n��࠭�/���㤠��⢮: "
                 << (countryPtr ? countryPtr->name : "��� ������") << '\n';

       std::cout << "\n���ਪ: "
                 << (continentPtr ? continentPtr->name : "��� ������") << std::endl;
       std::cout << '\n';
   }

   // �᢮�������� ����� ��� ��ꥪ⮢ ॣ����� � �⮫��
   for (size_t i=0; i < regionCount; ++i)
       delete allRegions[i];

   for (size_t i=0; i < capitalCount; ++i)
       delete allCapitals[i];
}
