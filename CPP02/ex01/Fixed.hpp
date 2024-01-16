#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed{
	public:
		Fixed();
		~Fixed();
		explicit Fixed(const int value);
		explicit Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);

		int getRawBits() const;
		void setRawBits(const int raw);

		int toInt() const;
		float toFloat() const;

	private:
		int _numberValue;
		static const int _fractBits;
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif
