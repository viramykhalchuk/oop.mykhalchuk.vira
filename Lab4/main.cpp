#include <iostream>
#include "AccessControlSystem.h"

using namespace std;

int main() {
    AccessControlSystem accessControlSystem;

    // Створення кімнат
    Room room1("Room1");
    Room room2("Room2");

    // Додавання кімнат в систему
    accessControlSystem.addRoom(&room1);
    accessControlSystem.addRoom(&room2);

    // Створення турнікетів
    Turnstile turnstile1;
    Turnstile turnstile2;

    // Додавання турнікетів в кімнати
    room1.addTurnstile(&turnstile1);
    room2.addTurnstile(&turnstile2);

    // Видача пропусків
    auto pass1 = accessControlSystem.issuePass("123", chrono::system_clock::now() + chrono::hours(1), "Room1");
    auto pass2 = accessControlSystem.issuePass("456", chrono::system_clock::now() + chrono::hours(2), "Room2");

    // Відкриття турнікету та пропуск через нього
    cout << "Passing through turnstile1 with pass1: " << accessControlSystem.openTurnstile("Room1", turnstile1, "123") << endl;
    cout << "Passing through turnstile2 with pass2: " << accessControlSystem.openTurnstile("Room2", turnstile2, "456") << endl;

    // Перевірка вичерпання строку дії пропуску
    cout << "Pass1 is expired: " << pass1->isExpired() << endl;

    // Відкликання пропуску
    accessControlSystem.revokePass("123");
    cout << "Passing through turnstile1 with revoked pass1: " << accessControlSystem.openTurnstile("Room1", turnstile1, "123") << endl;

    return 0;
}
