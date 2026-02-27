#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>
#include "ClassUser.hpp"

class Application {
private:
	std::vector<User> users;
	User* current_user;

	void show_main_menu();
	void handle_main_menu_choice(int choice);

	void show_user_menu();
	void handle_user_menu_choice(int choice);

	void create_user();
	void select_user();
	void add_task_for_user();
	void show_user_tasks();
	void mark_task_complete();
	void delete_task();

public:
	Application();
	void run();
};

#endif