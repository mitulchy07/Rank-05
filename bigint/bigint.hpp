#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <vector>
#include <iostream>

class bigint
{
	private :
		std::vector<int>	bignum;

	public:
		bigint();
		~bigint();
		bigint(unsigned int nb);
		bigint(const bigint& other);

		bigint&	operator=(const bigint& rhs);
		int		get_size() const;
		int		operator[](int index) const;

		bigint&	operator+=(const bigint& rhs);
		bigint	operator+(const bigint& rhs) const;
		bigint	operator+(int nb) const;

		bigint&	operator++();
		bigint 	operator++(int);

		bigint 	operator<<(int nb) const;
		bigint&	operator<<=(int nb);
		
		bigint&	operator>>=(const bigint& rhs);
		bigint 	operator>>(int nb) const;

		bool	operator<(const bigint& rhs) const;
		bool	operator==(const bigint& rhs) const;
		bool	operator<=(const bigint& rhs) const;
		bool	operator>(const bigint& rhs) const;
		bool	operator>=(const bigint& rhs) const;
		bool	operator!=(const bigint& rhs) const;
};

std::ostream&	operator<<(std::ostream& os, const bigint& bignum);

#endif