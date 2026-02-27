//ClassUser.cpp
#include <iostream>
#include "ClassUser.hpp"

User::User(int id, const std::string& n) : id(id), name(n), tasks(id) {}


void User::set_name(const std::string& new_name) {
	name = new_name;
}

void User::add_task(const Task& task) {
	tasks.add_task(task);
}

void User::show_all_tasks()const {
	auto all_tasks = tasks.get_all_tasks();
	for (const auto& task : all_tasks) {
		task.display();
	}
}