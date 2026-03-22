#include <iostream>
#include <string>

using namespace std;

class Flight {
private:
    string pilotName;
    string aircraftType;
    int flightDuration;
    string status;

public:
    Flight() {
        pilotName = "Не указано";
        aircraftType = "Не указан";
        flightDuration = 0;
        status = "запланирован";
        cout << "Создан объект Flight (конструктор по умолчанию)" << endl;
    }

    Flight(string name, string type, int duration, string st) {
        pilotName = name;
        aircraftType = type;

        if (duration >= 0) {
            flightDuration = duration;
        }
        else {
            flightDuration = 0;
            cout << "Длительность полёта не может быть отрицательной. Установлено 0." << endl;
        }

        if (st == "запланирован" || st == "выполнен" || st == "отменён") {
            status = st;
        }
        else {
            status = "запланирован";
            cout << "Некорректный статус. Установлен 'запланирован'." << endl;
        }

        cout << "Создан объект Flight (конструктор с параметрами)" << endl;
    }

    ~Flight() {
        cout << "Уничтожен объект Flight (пилот: " << pilotName << ")" << endl;
    }

    string getPilotName() const {
        return pilotName;
    }

    string getAircraftType() const {
        return aircraftType;
    }

    int getFlightDuration() const {
        return flightDuration;
    }

    string getStatus() const {
        return status;
    }

    void setPilotName(string newName) {
        if (newName != "") {
            pilotName = newName;
        }
        else {
            cout << "Ошибка: ФИО пилота не может быть пустым!" << endl;
        }
    }

    void setFlightDuration(int newDuration) {
        if (newDuration >= 0) {
            flightDuration = newDuration;
        }
        else {
            cout << "Ошибка: длительность полёта не может быть отрицательной!" << endl;
        }
    }

    void completeFlight(int actualDuration) {
        if (status != "запланирован") {
            cout << "Ошибка: полёт можно завершить только из статуса 'запланирован'!" << endl;
            return;
        }

        if (actualDuration <= 0) {
            cout << "Ошибка: фактическая длительность полёта должна быть положительной!" << endl;
            return;
        }

        status = "выполнен";
        flightDuration = actualDuration;
        cout << "Полёт успешно завершён. Длительность: " << actualDuration << " минут." << endl;
    }

    void cancelFlight() {
        if (status == "выполнен") {
            cout << "Ошибка: нельзя отменить уже выполненный полёт!" << endl;
            return;
        }

        if (status == "отменён") {
            cout << "Полёт уже был отменён ранее." << endl;
            return;
        }

        status = "отменён";
        flightDuration = 0;
        cout << "Полёт успешно отменён." << endl;
    }

    void rescheduleFlight(int newDuration) {
        if (status != "запланирован") {
            cout << "Ошибка: можно перенести только запланированный полёт!" << endl;
            return;
        }

        if (newDuration <= 0) {
            cout << "Ошибка: длительность полёта должна быть положительной!" << endl;
            return;
        }

        flightDuration = newDuration;
        cout << "Полёт перенесён. Новая длительность: " << newDuration << " минут." << endl;
    }

    string getFormattedDuration() const {
        int hours = flightDuration / 60;
        int minutes = flightDuration % 60;
        return to_string(hours) + " ч " + to_string(minutes) + " мин";
    }

    void printInfo() const {
       
        cout << "        ИНФОРМАЦИЯ О ПОЛЁТЕ" << endl;
        cout << "ФИО пилота:           " << pilotName << endl;
        cout << "Тип воздушного судна: " << aircraftType << endl;
        cout << "Длительность полёта:   " << flightDuration << " минут" << endl;
        cout << "                       (" << getFormattedDuration() << ")" << endl;
        cout << "Статус:               " << status << endl;
        
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    

    cout << "Создание объекта 1 (конструктор по умолчанию)" << endl;
    Flight flight1;
    flight1.printInfo();

    cout << "--- Создание объекта 2 (конструктор с параметрами)" << endl;
    Flight flight2("Иванов Иван Иванович", "Boeing 737", 90, "запланирован");
    flight2.printInfo();

    cout << "ДЕМОНСТРАЦИЯ МЕТОДОВ ДЛЯ flight2" << endl;

    cout << "Геттеры:" << endl;
    cout << "Пилот: " << flight2.getPilotName() << endl;
    cout << "Тип судна: " << flight2.getAircraftType() << endl;
    cout << "Длительность: " << flight2.getFlightDuration() << " минут" << endl;
    cout << "Статус: " << flight2.getStatus() << endl;
    cout << "Форматированная длительность: " << flight2.getFormattedDuration() << endl;
    cout << endl;

    cout << "Сеттеры:" << endl;
    flight2.setPilotName("Петров Пётр Петрович");
    cout << "Новый пилот: " << flight2.getPilotName() << endl;

    cout << "\nПроверка валидации в сеттере:" << endl;
    flight2.setFlightDuration(-30);
    cout << "Текущая длительность: " << flight2.getFlightDuration() << " минут" << endl;
    cout << endl;

    cout << "Методы поведения:" << endl;

    cout << "1. Попытка завершить полёт:" << endl;
    flight2.completeFlight(120);
    flight2.printInfo();

    cout << "2. Попытка отменить выполненный полёт:" << endl;
    flight2.cancelFlight();
    flight2.printInfo();

    cout << "3. Попытка перенести выполненный полёт:" << endl;
    flight2.rescheduleFlight(150);
    cout << endl;

    cout << "Создание объекта 3 для демонстрации других методов" << endl;
    Flight flight3("Сидоров Сидор Сидорович", "Airbus A320", 60, "запланирован");
    flight3.printInfo();

    cout << "Демонстрация отмены полёта:" << endl;
    flight3.cancelFlight();
    flight3.printInfo();

    cout << "Попытка завершить отменённый полёт:" << endl;
    flight3.completeFlight(90);
    flight3.printInfo();

    cout << "Демонстрация валидации в конструкторе" << endl;
    Flight flight4("", "Як-40", -45, "в процессе");
    flight4.printInfo();

    cout << "Конец" << endl;

    return 0;
}