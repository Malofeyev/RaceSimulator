#pragma once

#include <string>

namespace Consts {

    using my_cstr_t = const char*;

    const std::string startMsg = "Добро пожаловать в гоночный симулятор!\n";

    const std::string raceTypeListMsg = "1. Гонка для наземного транспорта\n\
2. Гонка для воздушного транспорта\n\
3. Гонка для наземного и воздушного транспорта\n\
Выберите тип гонки: ";

    const std::string distanceMsg = "Укажите длину дистанции\
 (должна быть положительна): ";
 
    const std::string transportMsg = 
        "Должно быть зарегистрировано хотя бы 2 транспортных средства\n\
1. Зарегистрировать транспорт\nВыберите действие: ";

    const std::string landMsg = "наземного транспорта";
    const std::string airMsg = "воздушного транспорта";
    const std::string landAirMsg = "наземного и воздушного транспорта";


    const std::string registratedTransportListPrefix = "Зарегистрированные транспортные средства: ";
    constexpr my_cstr_t transportListPrefixTemplate = "Гонка для {}. Расстояние: {}\n";
    const std::string transportListMsg = "1. Ботинки-вездеходы\n\
2. Метла\n\
3. Верблюд\n\
4. Кентавр\n\
5. Орёл\n\
6. Верблюд-быстроход\n\
7. Ковёр-самолёт\n\
0. Закончить регистрацию\n\
Выберите транспорт или 0 для оканчания процесса регистрации: ";

    constexpr my_cstr_t successfulRegistrationTemplate = "{} успешно зарегистрирован!\n";

    const std::string registrationOrStartMsg = "1. Зарегистрировать транспорт\n\
2. Начать гонку\nВыберите действие: ";
    
    const std::string resultPrefixMsg = "Результаты гонки:\n";

    constexpr my_cstr_t placeTemplate = "{}. {}. Время: {}\n";

    const std::string startOrQuitMsg = "1. Провести ещё одну гонку\n\
2. Выйти\nВыберите действие: ";

    const std::string raceTypeErr = "Неверный тип гонки!\n";
    const std::string transportTypeErr = "Попытка зарегистрировать \
неправильный тип транспортного средства!\n";
    constexpr my_cstr_t alreadyHasRegistrationTemplate = "{} уже зарегистрирован!\n";
    const std::string distanceErr = "Недопустимое значение дистанции!\n";
    const std::string actionErr = "Неверный тип действия!\n";
}
