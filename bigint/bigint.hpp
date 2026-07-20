#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
private:
    std::string digits;

    bool read_shift(std::size_t limit, std::size_t& value) const;

public:
    bigint();
    bigint(unsigned int value);

    bigint& operator+=(const bigint& other);
    bigint  operator+(const bigint& other) const;

    bigint& operator++();
    bigint  operator++(int);

    bigint& operator<<=(unsigned int shift);
    bigint& operator<<=(const bigint& shift);
    bigint  operator<<(unsigned int shift) const;
    bigint  operator<<(const bigint& shift) const;

    bigint& operator>>=(unsigned int shift);
    bigint& operator>>=(const bigint& shift);
    bigint  operator>>(unsigned int shift) const;
    bigint  operator>>(const bigint& shift) const;

    bool operator<(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;

    friend std::ostream& operator<<(std::ostream& out,
                                   const bigint& value);
};

#endif