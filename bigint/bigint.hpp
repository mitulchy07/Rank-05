#ifndef BIGINT
#define BIGINT

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string str;

		// Strip leading zeros, but always keep at least one digit
		void normalize();

	public:
		// Canonical form
		bigint();
		bigint(unsigned int number);
		bigint(const bigint& source);
		bigint& operator=(const bigint& source);

		// Access
		std::string getStr() const;

		// Addition
		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);

		// Increment
		bigint& operator++();    // prefix ++x
		bigint operator++(int);  // postfix x++

		// Digit-shift by an unsigned int amount
		bigint operator<<(unsigned int n) const;
		bigint operator>>(unsigned int n) const;
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);

		// Digit-shift by another bigint's value
		bigint operator<<(const bigint& other) const;
		bigint operator>>(const bigint& other) const;
		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);

		// Comparison
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;

		// ~bigint();
};

std::ostream& operator<<(std::ostream& output, const bigint& obj);

#endif
