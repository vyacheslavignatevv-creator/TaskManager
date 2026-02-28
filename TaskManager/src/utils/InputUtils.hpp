//InputUtils.hpp
#ifndef INPUT_UTILS_HPP
#define INPUT_UTILS_HPP


#include <iostream>
#include <limits>
#include <string>


/**
* @brief Очищает буфер ввода от оставшихся символов.
*/
inline void clear_input_buffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
* @brief Запрашивает у пользователя целое число с проверкой.
* @param promt Сообщение для пользователя.
* @return Корректное целое число
*/
inline int get_valid_integer(const std::string& promt) {
	int value;
	std::string leftover;

	while (true) {
		std::cout << promt;
		std::cin >> value;

		if (std::cin.fail()) {
			std::cout << "Ошибка! Введите число.\n";
			clear_input_buffer();
			continue;
		}
		
		std::getline(std::cin, leftover);

		if (!leftover.empty() && leftover.find_first_not_of(" \t") != std::string::npos) {
			std::cout << "Введите только число.\n";
			continue;
		}
		return value;
	}
}

/**
* @brief Запрашивает целое число в заданном диапазоне.
* @param promt Сообщение пользователю.
* @param min Минимальное значение.
* @param max Максимальное значение.
* @return Корректное число в диапазоне.
*/
inline int get_valid_integer_in_range(const std::string& promt, int min, int max) {
	while (true) {
		int value = get_valid_integer(promt);
		if (value >= min && value <= max) {
			return value;
		}
		std::cout << "Ошибка! Введите число от " << min << " до " << max << " включительно.\n";
	}
}

/**
* @brief Запрашивает непустую строку.
* @param promt Сообщение.
* @return Введённая строка (без лишних пробелов).
*/
inline std::string get_non_empty_string(const std::string& promt) {
	std::string value;
	while (true) {
		std::cout << promt;
		std::getline(std::cin, value);

		size_t start = value.find_first_not_of(" \t");
		size_t end = value.find_last_not_of(" \t");

		if (start == std::string::npos) {
			std::cout << "Ошибка! Строка не может быть пустой.\n";
			continue;
		}
		return value.substr(start, end - start + 1);
	}
}

/**
* @brief Запрашивает подтверждение (ДА / НЕТ).
* @param promt Сообщение.
* @return true если ДА, false если НЕТ.
*/
inline bool get_yes_no(const std::string& promt) {
	std::string answer;
	while (true) {
		std::cout << promt << " (да/нет): ";
		std::getline(std::cin, answer);

		if (answer == "да" || answer == "Да" || answer == "ДА") {
			return true;
		}
		if (answer == "нет" || answer == "Нет" || answer == "НЕТ") {
			return false;
		}
		std::cout << "Пожалуйста, введите 'да' или 'нет'. \n";
	}
}

#endif