//ClassTask.hpp
#ifndef TASK_HPP
#define TASK_HPP

#include <string>

enum class Priority {LOW, MEDIUM, HIGH};
enum class Status {PENDING, IN_PROGRESS, COMPLETED};

class Task {
private:
	int id;
	std::string title;
	std::string description;
	Priority priority;
	Status status;

public:
	
	Task(int id, const std::string& title, const std::string& desc, Priority p = Priority::MEDIUM);

	void display() const;

	std::string to_string() const;


	int get_id() const { return id; }
	std::string get_title() const { return title; }
	Priority get_priority()const { return priority; }
	Status get_status()const { return status; }


	void set_title(const std::string& new_title);

	void set_description(const std::string& new_desc);

	void set_priority(Priority volume);

	void set_status(Status volume);

};

#endif