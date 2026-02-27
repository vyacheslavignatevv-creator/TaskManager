//main
#include <iostream>
#include "ClassUser.hpp"


int main() {

    // Создаём пользователя
    User user(1, "Alice");

    // Создаём задачи
    Task task1(1, "Купить продукты", "Молоко, хлеб, яйца", Priority::HIGH);
    Task task2(2, "Сделать домашку", "Задача по C++", Priority::MEDIUM);

    // Добавляем задачи пользователю
    user.add_task(task1);
    user.add_task(task2);

    // Показываем все задачи
    std::cout << "Задачи пользователя " << user.get_name() << ":\n";
    user.show_all_tasks();

	return 0;
}