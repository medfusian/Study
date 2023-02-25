#include <iostream>
#include <string>

using namespace std;


class Automobile                //Автомобиль
{
protected:
    string brandAutomobile;     //Марка автомобиля
    string engineType;          //Тип двигателя
    int enginePower;            //Мощность двигателя
    int weightAutomobile;       //Масса автомобиля
    int mileageAutomobile;      //Пробег автомобиля

public:
    Automobile()
    {
        this->brandAutomobile = "";
        this->engineType = "";
        this->enginePower = 0;
        this->weightAutomobile = 0;
        this->mileageAutomobile = 0;
    }

    Automobile(string ba, string et, int ep, int wa, int ma)
    {
        this->brandAutomobile = ba;
        this->engineType = et;
        this->enginePower = ep;
        this->weightAutomobile = wa;
        this->mileageAutomobile = ma;
    }

    virtual void Load(int) = 0;
    virtual void Print() = 0;
};

class Car : public Automobile   //Легковой автомобиль
{
protected:
    int fuelConsumption;        //Расход топлива
    int accelerationTime;       //Время разгона
    int passengerSeats;         //Количество пассажирских мест

public:
    Car() : Automobile()
    {
        this->fuelConsumption = 0;
        this->accelerationTime = 0;
        this->passengerSeats = 0;
    }

    Car(string ba, string et, int ep, int wa, int ma,
        int fc, int at, int ps) : Automobile(ba, et, ep, wa, ma)
    {
        this->fuelConsumption = fc;
        this->accelerationTime = at;
        this->passengerSeats = ps;
    }


    void Load(int count) override
    {
        cout << "Посадка " << count << " пассажиров:   ";

        if (count <= passengerSeats) cout << "Пассажирам хватает мест!" << endl;
        else cout << "Пассажирам не хватает места!" << endl;
    }

    void Print() override
    {
        cout << "Марка автомобиля: " << this->brandAutomobile << "\t\t";
        cout << "Тип двигателя: " << this->engineType << "\t\t";
        cout << "Мощность двигателя: " << this->enginePower << endl;
        cout << "Масса автомобиля: " << this->weightAutomobile << "\t\t";
        cout << "Пробег автомобиля: " << this->mileageAutomobile << "\t\t";
        cout << "Расход топлива: " << this->fuelConsumption << endl;
        cout << "Время разгона: " << this->accelerationTime << "\t\t";
        cout << "Количество пассажирских мест: " << this->passengerSeats << endl;
    }
};

class Lorry : public Automobile //Грузовой автомобиль
{
protected:
    int loadCapacity;           //Грузоподъемность в тоннах
    string bodyType;            //Тип кузова

public:
    Lorry() : Automobile()
    {
        this->loadCapacity = 0;
        this->bodyType = "";
    }

    Lorry(string ba, string et, int ep, int wa, int ma,
        int lc, string bt) : Automobile(ba, et, ep, wa, ma)
    {
        this->loadCapacity = lc;
        this->bodyType = bt;
    }


    void Load(int count) override
    {
        cout << "Загрузка груза " << count << " тонн:   ";

        if (count <= loadCapacity) cout << "Грузоподъемность не превышена!" << endl;
        else cout << "Грузоподъемность превышена!" << endl;
    }

    void Print() override
    {
        cout << "Марка автомобиля: " << this->brandAutomobile << "\t\t";
        cout << "Тип двигателя: " << this->engineType << "\t\t";
        cout << "Мощность двигателя: " << this->enginePower << endl;
        cout << "Масса автомобиля: " << this->weightAutomobile << "\t\t";
        cout << "Пробег автомобиля: " << this->mileageAutomobile << "\t\t";
        cout << "Грузоподъемность в тоннах: " << this->loadCapacity << endl;
        cout << "Тип кузова: " << this->bodyType << endl;
    }

};

class Bus : public Car          //Автобус
{
protected:
    int standingSeats;          //Количество стоячих мест

public:
    Bus() : Car()
    {
        this->standingSeats = 0;
    }

    Bus(string ba, string et, int ep, int wa, int ma,
        int fc, int at, int ps, int ss) : Car(ba, et,
            ep, wa, ma, fc, at, ps)
    {
        this->standingSeats = ss;
    }


    void Load(int count) override
    {
        cout << "Посадка " << count << " пассажиров:   ";

        if (count <= passengerSeats + standingSeats) cout << "Пассажирам хватает мест!" << endl;
        else cout << "Пассажирам не хватает места!" << endl;
    }

    void Print() override
    {
        cout << "Марка автомобиля: " << this->brandAutomobile << "\t\t";
        cout << "Тип двигателя: " << this->engineType << "\t\t";
        cout << "Мощность двигателя: " << this->enginePower << endl;
        cout << "Масса автомобиля: " << this->weightAutomobile << "\t\t";
        cout << "Пробег автомобиля: " << this->mileageAutomobile << "\t\t";
        cout << "Расход топлива: " << this->fuelConsumption << endl;
        cout << "Время разгона: " << this->accelerationTime << "\t\t";
        cout << "Количество пассажирских мест: " << this->passengerSeats << "\t";
        cout << "Количество стоячих мест: " << this->standingSeats << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    int numberAutomobile;
    cout << "Введите количество автомобилей: ";
    cin >> numberAutomobile;
    cout << endl;

    string engineTypeDefault, bodyTypeDefault;

    Automobile** autopark = new Automobile * [numberAutomobile];

    for (int i = 0; i < numberAutomobile; i++)
    {
        switch (rand() % 3 + 1)
        {
        case 1:
            if (i % 3 == 0) engineTypeDefault = "дизельный";
            else engineTypeDefault = "карбюраторный";

            autopark[i] = new Car(to_string(i+1), engineTypeDefault,
                rand() % 600 + 1, rand() % 1000 + 300, (rand() % 3000 + 400) * 100, rand() % 10 + 8,
                rand() % 15 + 5, rand() % 7 + 2);

            break;
        case 2:
            if (i % 3 == 0) engineTypeDefault = "дизельный";
            else engineTypeDefault = "карбюраторный";

            if (i % 2 == 0) bodyTypeDefault = "открытый";
            else bodyTypeDefault = "закрытый";

            autopark[i] = new Lorry(to_string(i+1), engineTypeDefault,
                rand() % 600 + 1, rand() % 3000 + 1000, (rand() % 3000 + 400) * 100, rand() % 10 + 5,
                bodyTypeDefault);

            break;
        case 3:
            if (i % 3 == 0) engineTypeDefault = "дизельный";
            else engineTypeDefault = "карбюраторный";

            autopark[i] = new Bus(to_string(i+1), engineTypeDefault,
                rand() % 600 + 1, rand() % 4000 + 1000, (rand() % 3000 + 400) * 100, rand() % 15 + 10,
                rand() % 30 + 15, rand() % 20 + 9, rand() % 20 + 1);

            break;

        default:
            break;
        }
    }

    for (int i = 0; i < numberAutomobile; i++)
    {
        autopark[i]->Print();
        cout << endl;
        autopark[i]->Load(rand() % 12 + 1);
        cout << "\n\n-------------------------------------\n\n";
    }

    return 0;
}