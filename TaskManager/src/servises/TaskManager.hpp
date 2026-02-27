//TaskManager.hpp
#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <vector>
#include "ClassTask.hpp"

class Task_Manager {
private:
	std::vector<Task> tasks;
	int owner_id;

public:
	Task_Manager(int own_id);

	int get_owner_id() const;
	size_t get_count_tasks() const;

	void add_task(const Task& task);
	void delete_task(int index);

	std::vector<Task> get_all_tasks() const;

};


#endif