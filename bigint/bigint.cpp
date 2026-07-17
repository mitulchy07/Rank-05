#include "bigint.hpp"

bigint::bigint()
{
	bignum.push_back(0);
}

bigint::~bigint()
{

}

bigint::bigint(const bigint& other) : bignum(other.bignum)
{

}

bigint::bigint(unsigned int nb)
{
	if (nb <= 0)
	{
		bignum.push_back(0);
	}
	else
	{
		while (nb > 0)
		{
			bignum.push_back(nb % 10);
			nb /= 10;
		}
	}
}

bigint&	bigint::operator=(const bigint& rhs)
{
	bignum = rhs.bignum;
	return (*this);
}

int	bigint::get_size() const
{
	return ((int)bignum.size());
}

int	bigint::operator[](int index) const
{
	return (bignum[index]);
}

bigint&	bigint::operator+=(const bigint& rhs)
{
	int	m = rhs.get_size();
	int n = get_size();
	int max = n > m ? n : m;

	bignum.resize(max, 0);					
												

	int	carry = 0;

	for (int i = 0; i < max; ++i)
	{
		int	rhs_digits = i < m ? rhs.bignum[i] : 0;
		int result = rhs_digits + carry + bignum[i];

		bignum[i] = result % 10;
		carry = result / 10;
	}
	if (carry)
		bignum.push_back(carry);
	while (get_size() > 1 && bignum.back() == 0)
		bignum.pop_back();
	return (*this);
}

bigint	bigint::operator+(const bigint& rhs) const
{
	bigint	result(*this);

	result += rhs;
	return (result);
}

bigint	bigint::operator+(int nb) const
{
	bigint	result(*this);
	bigint	tmp(nb);

	result += tmp;
	return (result);
}

bigint& bigint::operator++()
{
	bigint tmp(1);

	*this += tmp;
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint	tmp(*this);

	++*this;
	return (tmp);
}

bigint	bigint::operator<<(int nb) const
{
	bigint	result(*this);

	if (nb <= 0 || (result.get_size() == 1 && result.bignum.back() == 0))
		return (result);
	result.bignum.insert(result.bignum.begin(), nb, 0);
	return (result);
}

bigint&	bigint::operator<<=(int nb)
{
	*this = *this << nb;
	return (*this);
}

bigint&	bigint::operator>>=(const bigint& rhs)
{
	int 	digit_shift = 0;
	size_t	multiple = 1;

	for (int i = 0; i < rhs.get_size(); ++i)
	{
		digit_shift += rhs.bignum[i] * multiple;
		if (digit_shift >= get_size())
		{
			bignum.clear();
			bignum.push_back(0);
			return (*this);
		}
		multiple *= 10;
	}
	bignum.erase(bignum.begin(), bignum.begin() + digit_shift);
	return (*this);
}

bigint	bigint::operator>>(int nb) const
{
	bigint	result(*this);
	bigint	tmp(nb);

	result >>= tmp;
	return (result);
}


bool	bigint::operator<(const bigint& rhs) const
{
	if (get_size() != rhs.get_size())
		return (get_size() < rhs.get_size());
	for (int i = get_size() - 1; i >= 0; --i)
	{
		if (bignum[i] != rhs.bignum[i])
			return (bignum[i] < rhs.bignum[i]);
	}
	return (false);
}

bool	bigint::operator==(const bigint& rhs) const
{
	if (get_size() != rhs.get_size())
		return (false);
	for (int i = get_size() - 1; i >= 0; --i)
	{
		if (bignum[i] != rhs.bignum[i])
			return (false);
	}
	return (true);
}

bool	bigint::operator<=(const bigint& rhs) const
{
	if (*this < rhs || *this == rhs)
		return (true);
	return (false);
}

bool	bigint::operator>(const bigint& rhs) const
{
	return (rhs < *this);
}

bool	bigint::operator>=(const bigint& rhs) const
{
	return (rhs <= *this);
}

bool	bigint::operator!=(const bigint& rhs) const
{
	if (*this == rhs)
		return (false);
	return (true);
}

std::ostream&	operator<<(std::ostream& os, const bigint& bignum)
{
	if (bignum.get_size() == 0)
	{
		os << "0";
		return (os);
	}
	for (int i = bignum.get_size() - 1; i >= 0; --i)
	{
		os << bignum[i];
	}
	return (os);
}