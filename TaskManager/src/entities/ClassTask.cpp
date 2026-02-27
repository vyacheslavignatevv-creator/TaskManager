//ClassTask.cpp
#include <iostream>
#include "ClassTask.hpp"

Task::Task(int id, const std::string& title, const std::string& desc, Priority p) :
	id(id), title(title), description(desc), priority(p), status(Status::PENDING) {}


void Task::display() const {
	std::cout << "[" << id << "] " << title << " - " << description << std::endl;
}


std::string Task::to_string()const {
	return std::to_string(id) + ", " + title + ", " + description;
}


void Task::set_title(const std::string& new_title) {
	title = new_title;
}


void Task::set_description(const std::string& new_desc) {
	description = new_desc;
}


void Task::set_priority(Priority volume) {
	priority = volume;
}


void Task::set_status(Status volume) {
	status = volume;
}


