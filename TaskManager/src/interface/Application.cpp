//Application.cpp
#include <iostream>
#include "Application.hpp"
#include "InputUtils.hpp"

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
	
	int choice = get_valid_integer_in_range("Выберите действие: ", 1, 3);
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
	}
}

void Application::create_user() {
	static int next_id = 1;
	std::string name = get_non_empty_string("Введите имя пользователя: ");

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

	int id = get_valid_integer("Введите ID пользователя: ");

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

	int choice = get_valid_integer_in_range("Выберите действие: ", 1, 6);
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
	}
}


void Application::add_task_for_user() {
	static int next_task_id = 1;
	
	std::string title = get_non_empty_string("Введите назвние задачи: ");
	std::string description = get_non_empty_string("Введите описание задачи: ");
	


	std::cout << "Выберите приоритет задачи: \n";
	std::cout << "1. - НИЗКИЙ\n";
	std::cout << "2. - СРЕДНИЙ\n";
	std::cout << "3. - ВЫСОКИЙ\n";

	int priority_choice = get_valid_integer_in_range("Ваш выбор: ", 1, 3);

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
	std::cout << "\nЗадачи пользователя " << current_user->get_name() << ":\n";
	current_user->show_all_tasks();
}

void Application::mark_task_complete() {
	auto& task_manager = current_user->get_task_manager();
	auto tasks = task_manager.get_all_tasks();

	if(tasks.empty()){
		std::cout << "У пользователя нет задач.\n";
		return;
	}

	std::cout << "\nСписок задач:\n";
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << i + 1 << ". ";
		tasks[i].display();
	}

	int index = get_valid_integer_in_range("Введите номер выполненной задачи: ", 1, tasks.size());
	//Функция в разработке
	std::cout << "Функция в разработке.\n";
}

void Application::delete_task() {
	auto& task_manager = current_user->get_task_manager();
	auto tasks = task_manager.get_all_tasks();

	if(tasks.empty()){
		std::cout << "У пользователя нет задач.\n";
		return;
	}

	std::cout << "\nСписок задач:\n";
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << i + 1 << ". ";
		tasks[i].display();
	}

	int index = get_valid_integer_in_range("Введите номер удаляемой задачи: ", 1, tasks.size());

	if (get_yes_no("Вы уверены, что хотите удалить задачу?")) {
		task_manager.delete_task(index - 1); //Переводим в 0-индексацию
		std::cout << "Задача удалена.\n";
	}
	else { "Удаление отменено.\n"; }
}