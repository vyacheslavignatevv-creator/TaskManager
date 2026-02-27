#include <iostream>
#include <limits>
#include "Application.hpp"

Application::Application() : current_user(nullptr) {}

void Application::run() {
	while (true) {
		if (current_user == nullptr) {
			show_main_menu();
		}
		else {
			show_user_menu();
		}
	}
}

void Application::show_main_menu() {
	std::cout << "\n=== ГЛАВНОЕ МЕНЮ===\n";
	std::cout << "1. Создать пользователя\n";
	std::cout << "2. Выбрать пользователя\n";
	std::cout << "3. Выход\n";
	std::cout << "Выберите действие: ";
	
	int choice;
	std::cin >> choice;
	handle_main_menu_choice(choice);
}

void Application::handle_main_menu_choice(int choice) {
	switch (choice) {
	case 1:
		create_user();
		break;

	case 2:
		select_user();
		break;

	case 3:
		std::cout << "До свидания.\n";
		exit(0);

	default:
		std::cout << "Неверный выбор. Попробуйте снова.\n";
		break;
	}
}

void Application::create_user() {
	static int next_id = 1;
	std::string name;

	std::cout << "Введите имя пользователя: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	users.emplace_back(next_id++, name);
	std::cout << "Пользователь " << name << " создан.\n";
}

void Application::select_user() {
	if (users.empty()) {
		std::cout << "Нет пользователей. Сначала создайте пользователя.\n";
		return;
	}

	std::cout << "\nДоступные пользователи: \n";
	for (const auto& user : users) {
		std::cout << user.get_id() << ". " <<user.get_name() << "\n";
	}

	std::cout << "Выберите ID пользователя: ";
	int id;
	std::cin >> id;

	for (auto& user : users) {
		if (user.get_id() == id) {
			current_user = &user;
			std::cout << "Вы вошли как " << user.get_name()<< "\n";
			return;
		}
	}

	std::cout << "Пользователь с ID " << id << " не найден.\n";
}


void Application::show_user_menu() {
	std::cout << "\n=== МЕНЮ ПОЛЬЗОВАТЕЛЯ: " << current_user->get_name() << " ===\n";
	std::cout << "1. Добавить задачу\n";
	std::cout << "2. Показать все задачи\n";
	std::cout << "3. Отметить задачу выполненной\n";
	std::cout << "4. Удалить задачу\n";
	std::cout << "5. Выйти из аккаунта\n";
	std::cout << "6. Завершить программу\n";
	std::cout << "Выберите действие: ";

	int choice;
	std::cin >> choice;
	handle_user_menu_choice(choice);
}

void Application::handle_user_menu_choice(int choice) {
	switch (choice) {
	case 1:
		add_task_for_user();
		break;
	case 2:
		show_user_tasks();
		break;
	case 3:
		mark_task_complete();
		break;
	case 4:
		delete_task();
		break;
	case 5:
		current_user = nullptr;
		std::cout << "Вы вышли из аккаунта.\n";
		break;
	case 6:
		std::cout << "До свидания.\n";
		exit(0);
	default:
		std::cout << "Неверный выбор. Попробуйте снова.\n";
	}
}


void Application::add_task_for_user() {
	static int next_task_id = 1;
	std::string title, description;
	int priority_choice;

	std::cout << "Введите название задачи: ";
	std::cin.ignore();
	std::getline(std::cin, title);

	std::cout << "Введите описание задачи: ";
	std::getline(std::cin, description);

	std::cout << "Выберите приоритет задачи (1 - НИЗКИЙ, 2 - СРЕДНИЙ, 3 - ВЫСОКИЙ): ";
	std::cin >> priority_choice;

	Priority priority = Priority::MEDIUM;
	switch (priority_choice) {
	case 1:priority = Priority::LOW; break;
	case 2:priority = Priority::MEDIUM; break;
	case 3:priority = Priority::HIGH; break;
	}

	Task new_task(next_task_id++, title, description, priority);
		current_user->add_task(new_task);
		std::cout << "Задача добавлена.\n";
}


void Application::show_user_tasks(){
	std::cout << "\n Задачи пользователя: " << current_user->get_name() << ":\n";
	current_user->show_all_tasks();
}

void Application::mark_task_complete() {
	//Функция в разработке
	std::cout << "Функция в разработке.\n";
}

void Application::delete_task() {
	//Функция в разработке
	std::cout << "Функция в разработке.\n";
}