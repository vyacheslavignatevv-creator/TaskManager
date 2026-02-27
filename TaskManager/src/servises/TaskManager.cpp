//TaskManager.cpp
#include "TaskManager.hpp"
#include <algorithm>

Task_Manager::Task_Manager(int own_id) : owner_id(own_id){}

int Task_Manager::get_owner_id() const { return owner_id; }
size_t Task_Manager::get_count_tasks() const { return tasks.size(); }

void Task_Manager::add_task(const Task& task) {
	tasks.push_back(task);
}

void Task_Manager::delete_task(int index) {
	if (index >= 0 && index < tasks.size()) {
		tasks.erase(tasks.begin() + index);
	}
}

std::vector<Task> Task_Manager::get_all_tasks() const { return tasks; }