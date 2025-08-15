#include <iostream>

// ������� ��६����� � ᥪ樨 .bss (�� ���樠����஢����� ������쭠� ��६�����)
int uninitialized_bss_var[3]; // �� 㬮�砭�� �㫥�� ���祭��, �������� ᥪ�� .bss

// ������� ��६����� � ᥪ樨 .data (���樠����஢����� ������쭠� ��६�����)
int initialized_data_var[3] = {1, 2, 3};

// ������� �㭪樨 � �ந����쭮� ᨣ����ன
void sampleFunction() {

}

// ������� �㭪�� Task_1
void Task_1(void *ptr) {

    // ��६����� �� �⥪�
    int stack_var = 10;

    // ���ᨢ �� �⥪�
    int stack_array[3] = {4, 5, 6};

    // �뢮� ���� �㭪樨 main
    //std::cout << "���� �㭪樨 main: " << (void*)main << '\n';
    std::cout << "���� �㭪樨 main: " << ptr << '\n';

    // �뢮� ���� �ந����쭮� �㭪樨
    std::cout << "\n���� �㭪樨 sampleFunction: " << (void*)sampleFunction << '\n';

    // ���� ��६����� �� �⥪�
    std::cout << "\n���� ��६����� stack_var: " << (void*)&stack_var << '\n';

    // ���� � ������ ���ᨢ� �� �⥪�
    std::cout << "\n���� ���ᨢ� stack_array: " << (void*)stack_array << '\n';
    for(int i = 0; i < 3; ++i) {
        std::cout << "stack_array[" << i << "] (" << (void*)&stack_array[i] << ") = "
                       << stack_array[i] << '\n';
    }

    // ���� ��६����� � ᥪ樨 .bss
    std::cout << "\n���� uninitialized_bss_var: " << (void*)uninitialized_bss_var << '\n';

    // ���� ��६����� � ᥪ樨 .data
    std::cout << "���� initialized_data_var: " << (void*)initialized_data_var << '\n';
    std::cout << '\n';

    // ���� � ������ ���ᨢ� � ����᪮� ����� (.bss)
    for(int i = 0; i < 3; ++i) {
        std::cout << "uninitialized_bss_var[" << i << "] ("
                       << (void*)&uninitialized_bss_var[i] << ") = " << uninitialized_bss_var[i] << '\n';
    }
    std::cout << '\n';
    for(int i = 0; i < 3; ++i) {
        std::cout << "initialized_data_var[" << i << "] ("
                       << (void*)&initialized_data_var[i] << ") = " << initialized_data_var[i] << '\n';
    }

    // �������� ��६����� � ���
    int *heap_var = new int(100);

    // ���ᨢ � ���
    int *heap_array = new int[3]{7,8,9};

    // �뢮� ���� 㪠��⥫� �� ���� � ��� ���祭��
    std::cout << "\n���� 㪠��⥫� heap_var: " << &heap_var << '\n';
    std::cout << "\n���祭�� heap_var (���� ��ꥪ�): " << (void*)heap_var << '\n';

    // ���� � ������ ���ᨢ� �� ���
    for(int i=0; i<3; ++i) {
        std::cout << "heap_array[" << i << "] (" << (void*)(heap_array + i) << ") = " << *(heap_array + i) << std::endl;
    }

    // �᢮�������  ������
    delete heap_var;
    delete[] heap_array;
}
