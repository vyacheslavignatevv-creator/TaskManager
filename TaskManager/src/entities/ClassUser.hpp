//ClassUser.hpp
#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "TaskManager.hpp"

class User {
private:
	int id;
	std::string name;
	Task_Manager tasks;

public:
	User(int id, const std::string& n);

	int get_id() const { return id; }
	const std::string& get_name() const { return name; }

	void set_name(const std::string& new_name);

	void add_task(const Task& task);
	void show_all_tasks()const;
	Task_Manager& get_task_manager() { return tasks; }

};



#endif