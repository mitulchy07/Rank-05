#include "bigint.hpp"

bigint::bigint() : str("0")
{
}

bigint::bigint(unsigned int number) : str("0")
{
	if (number == 0)
		return;

	std::string digits;
	while (number > 0)
	{
		digits = char('0' + number % 10) + digits;
		number /= 10;
	}
	str = digits;
}

bigint::bigint(const bigint& source) : str(source.str)
{
}

bigint& bigint::operator=(const bigint& source)
{
	if (this != &source)
		str = source.str;
	return *this;
}

std::string bigint::getStr() const
{
	return str;
}

// Strip leading zeros, but always keep at least one digit ("0" stays "0")
void bigint::normalize()
{
	size_t firstNonZero = 0;
	while (firstNonZero + 1 < str.size() && str[firstNonZero] == '0')
		firstNonZero++;
	if (firstNonZero > 0)
		str.erase(0, firstNonZero);
}

// Add two decimal number-strings, digit by digit, right to left, with carry
static std::string addStrings(const std::string& a, const std::string& b)
{
	std::string result;
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';
		carry = sum / 10;
		result = char(sum % 10 + '0') + result;
	}
	return result.empty() ? "0" : result;
}

bigint bigint::operator+(const bigint& other) const
{
	bigint result;
	result.str = addStrings(str, other.str);
	result.normalize();
	return result;
}

bigint& bigint::operator+=(const bigint& other)
{
	return *this = *this + other;
}

bigint& bigint::operator++() // prefix ++x
{
	return *this += bigint(1);
}

bigint bigint::operator++(int) // postfix x++
{
	bigint old = *this;
	++(*this);
	return old;
}

// Digit-shift left: append n zeros (e.g. 42 << 3 == 42000)
bigint bigint::operator<<(unsigned int n) const
{
	bigint result = *this;
	if (result.str != "0")
		result.str.append(n, '0');
	return result;
}

bigint& bigint::operator<<=(unsigned int n)
{
	return *this = *this << n;
}

// Digit-shift right: drop the last n digits (e.g. 1337 >> 2 == 13)
bigint bigint::operator>>(unsigned int n) const
{
	bigint result = *this;
	if (n >= result.str.size())
		result.str = "0";
	else
		result.str.erase(result.str.size() - n, n);
	result.normalize();
	return result;
}

bigint& bigint::operator>>=(unsigned int n)
{
	return *this = *this >> n;
}

// Convert a decimal string to unsigned int, used by the bigint-shift overloads
static unsigned int toUnsignedInt(const std::string& s)
{
	unsigned int value = 0;
	for (size_t i = 0; i < s.size(); i++)
		value = value * 10 + (s[i] - '0');
	return value;
}

bigint bigint::operator<<(const bigint& other) const
{
	return *this << toUnsignedInt(other.str);
}

bigint& bigint::operator<<=(const bigint& other)
{
	return *this = *this << other;
}

bigint bigint::operator>>(const bigint& other) const
{
	return *this >> toUnsignedInt(other.str);
}

bigint& bigint::operator>>=(const bigint& other)
{
	return *this = *this >> other;
}

bool bigint::operator==(const bigint& other) const
{
	return str == other.str;
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
	if (str.size() != other.str.size())
		return str.size() < other.str.size();
	return str < other.str;
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator<=(const bigint& other) const
{
	return !(other < *this);
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
	return os << obj.getStr();
}
