#include <iostream>
#include <cstring>
using namespace std;

class Wheel 
{
private:
    int radius;
public:
    Wheel(int r) : radius(r) 
    {
        cout << "Створено колесо з радіусом: " << radius << endl;
    }

    int getRadius() const 
    {
        return radius;
    }

    void setRadius(int r) 
    {
        radius = r;
    }

    ~Wheel() 
    {
        cout << "Знищено колесо з радіусом: " << radius << endl;
    }
};

class Car
{
private:
    char* brand;
    int price;
    Wheel wheel;
public:
    Car(const char* b, int p, int r) : price(p), wheel(r)
    {
        brand = new char[strlen(b) + 1];
        strcpy_s(brand, strlen(b) + 1, b); 
        cout << "Створено автомобіль марки: " << brand << " з ціною: " << price << endl;
    }

    void showCar() const
    {
        cout << "Марка автомобіля: " << brand << ", ціна: " << price << ", радіус колеса: " << wheel.getRadius() << endl;
    }

    ~Car() 
    {
        delete[] brand;
        cout << "Знищено автомобіль марки: " << brand << endl;
    }
};

class Truck : public Car 
{
private:
    int loadCapacity;
public:
    Truck(const char* b, int p, int r, int lc) : Car(b, p, r), loadCapacity(lc) 
    {
        cout << "Створено вантажівку з вантажопідйомністю: " << loadCapacity << " кг" << endl;
    }

    void showTruck() const
    {
        showCar();
        cout << "Вантажопідйомність: " << loadCapacity << " кг" << endl;
    }

    ~Truck() 
    {
        cout << "Знищено вантажівку" << endl;
    }
};

int main() 
{
    Truck myTruck("Volvo", 50000, 18, 10000);
    myTruck.showTruck();

    return 0;
}
