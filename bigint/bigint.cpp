#include "bigint.hpp"
#include <algorithm>
#include <stdexcept>

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int value)
{
    if (value == 0)
        digits = "0";

    while (value > 0)
    {
        digits += static_cast<char>('0' + value % 10);
        value /= 10;
    }
    std::reverse(digits.begin(), digits.end());
}

bool bigint::read_shift(std::size_t limit, std::size_t& value) const
{
    value = 0;
    for (std::size_t i = 0; i < digits.size(); ++i)
    {
        unsigned int digit = digits[i] - '0';

        if (value > limit / 10
            || (value == limit / 10 && digit > limit % 10))
            return false;
        value = value * 10 + digit;
    }
    return true;
}

bigint& bigint::operator+=(const bigint& other)
{
    std::string result;
    int i = static_cast<int>(digits.size()) - 1;
    int j = static_cast<int>(other.digits.size()) - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += digits[i--] - '0';
        if (j >= 0)
            sum += other.digits[j--] - '0';
        result += static_cast<char>('0' + sum % 10);
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    digits = result;
    return *this;
}

bigint bigint::operator+(const bigint& other) const
{
    bigint result(*this);

    result += other;
    return result;
}

bigint& bigint::operator++()
{
    return *this += bigint(1);
}

bigint bigint::operator++(int)
{
    bigint old(*this);

    ++(*this);
    return old;
}

bigint& bigint::operator<<=(unsigned int shift)
{
    if (digits != "0")
        digits.append(shift, '0');
    return *this;
}

bigint& bigint::operator<<=(const bigint& shift)
{
    std::size_t amount;
    std::size_t limit = digits.max_size() - digits.size();

    if (!shift.read_shift(limit, amount))
        throw std::length_error("bigint shift is too large");
    if (digits != "0")
        digits.append(amount, '0');
    return *this;
}

bigint bigint::operator<<(unsigned int shift) const
{
    bigint result(*this);

    result <<= shift;
    return result;
}

bigint bigint::operator<<(const bigint& shift) const
{
    bigint result(*this);

    result <<= shift;
    return result;
}

bigint& bigint::operator>>=(unsigned int shift)
{
    if (shift >= digits.size())
        digits = "0";
    else
        digits.erase(digits.size() - shift);
    return *this;
}

bigint& bigint::operator>>=(const bigint& shift)
{
    std::size_t amount;

    if (!shift.read_shift(digits.size() - 1, amount))
        digits = "0";
    else
        digits.erase(digits.size() - amount);
    return *this;
}

bigint bigint::operator>>(unsigned int shift) const
{
    bigint result(*this);

    result >>= shift;
    return result;
}

bigint bigint::operator>>(const bigint& shift) const
{
    bigint result(*this);

    result >>= shift;
    return result;
}

bool bigint::operator<(const bigint& other) const
{
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();
    return digits < other.digits;
}

bool bigint::operator==(const bigint& other) const
{
    return digits == other.digits;
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

bool bigint::operator<=(const bigint& other) const
{
    return !(other < *this);
}

bool bigint::operator>(const bigint& other) const
{
    return other < *this;
}

bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& out, const bigint& value)
{
    return out << value.digits;
}