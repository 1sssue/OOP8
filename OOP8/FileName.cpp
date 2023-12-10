#include <iostream>
#include <string>
#include <Windows.h>

// Базовий клас "Car"
class Car {
protected:
    std::string brand;  // Торговельна марка
    int cylinders;      // Кількість циліндрів
    double power;       // Потужність

public:
    // Конструктор класу
    Car(const std::string& brand, int cylinders, double power)
        : brand(brand), cylinders(cylinders), power(power) {}

    // Метод для виведення інформації про машину
    void displayInfo() const {
        std::cout << "Брент: " << brand << ", Циліндри: " << cylinders << ", Power: " << power << " HP\n";
    }

    // Метод для перепризначення торговельної марки
    void setBrand(const std::string& newBrand) {
        brand = newBrand;
    }

    // Метод для зміни потужності
    void changePower(double newPower) {
        power = newPower;
    }
};

// Похідний клас "Lorry"
class Lorry : public Car {
private:
    double cargoCapacity;  // Вантажопідйомність кузова

public:
    // Конструктор класу Lorry
    Lorry(const std::string& brand, int cylinders, double power, double cargoCapacity)
        : Car(brand, cylinders, power), cargoCapacity(cargoCapacity) {}

    // Метод для виведення інформації про вантажівку
    void displayInfo() const {
        // Викликаємо метод базового класу для виведення загальної інформації про машину
        Car::displayInfo();
        std::cout << "Вантажопідйомність: " << cargoCapacity << " тонн\n";
    }

    // Метод для перепризначення вантажопідйомності
    void setCargoCapacity(double newCargoCapacity) {
        cargoCapacity = newCargoCapacity;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Car car("Toyota", 4, 150.5);

    std::cout << "Інформація про автомобіль:\n";
    car.displayInfo();

    car.setBrand("Honda");
    car.changePower(180.3);

    std::cout << "\nОновлена інформація про автомобіль:\n";
    car.displayInfo();

    Lorry lorry("Volvo", 6, 300.8, 10.5);

    std::cout << "\nІнформація про вантажнівку";
    lorry.displayInfo();

    lorry.setBrand("Scania");
    lorry.setCargoCapacity(12.8);

    std::cout << "\nОновлена інформація про вантажнівку:\n";
    lorry.displayInfo();

    return 0;
}
