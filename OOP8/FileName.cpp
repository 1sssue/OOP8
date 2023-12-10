#include <iostream>
#include <string>
#include <Windows.h>

// ������� ���� "Car"
class Car {
protected:
    std::string brand;  // ����������� �����
    int cylinders;      // ʳ������ �������
    double power;       // ���������

public:
    // ����������� �����
    Car(const std::string& brand, int cylinders, double power)
        : brand(brand), cylinders(cylinders), power(power) {}

    // ����� ��� ��������� ���������� ��� ������
    void displayInfo() const {
        std::cout << "�����: " << brand << ", �������: " << cylinders << ", Power: " << power << " HP\n";
    }

    // ����� ��� ��������������� ����������� �����
    void setBrand(const std::string& newBrand) {
        brand = newBrand;
    }

    // ����� ��� ���� ���������
    void changePower(double newPower) {
        power = newPower;
    }
};

// �������� ���� "Lorry"
class Lorry : public Car {
private:
    double cargoCapacity;  // ���������������� ������

public:
    // ����������� ����� Lorry
    Lorry(const std::string& brand, int cylinders, double power, double cargoCapacity)
        : Car(brand, cylinders, power), cargoCapacity(cargoCapacity) {}

    // ����� ��� ��������� ���������� ��� ���������
    void displayInfo() const {
        // ��������� ����� �������� ����� ��� ��������� �������� ���������� ��� ������
        Car::displayInfo();
        std::cout << "����������������: " << cargoCapacity << " ����\n";
    }

    // ����� ��� ��������������� ����������������
    void setCargoCapacity(double newCargoCapacity) {
        cargoCapacity = newCargoCapacity;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Car car("Toyota", 4, 150.5);

    std::cout << "���������� ��� ���������:\n";
    car.displayInfo();

    car.setBrand("Honda");
    car.changePower(180.3);

    std::cout << "\n�������� ���������� ��� ���������:\n";
    car.displayInfo();

    Lorry lorry("Volvo", 6, 300.8, 10.5);

    std::cout << "\n���������� ��� ����������";
    lorry.displayInfo();

    lorry.setBrand("Scania");
    lorry.setCargoCapacity(12.8);

    std::cout << "\n�������� ���������� ��� ����������:\n";
    lorry.displayInfo();

    return 0;
}
