#pragma once

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <utility>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace dawn {
	class BigInteger {
	private:
		inline static const int Base = 100000000, Len = 8;
		bool negative;
		std::vector<int> a;
		BigInteger& normalize();
	public:
		BigInteger(int x = 0);
		BigInteger(const std::string& s);
		BigInteger& operator = (const BigInteger& x);
		BigInteger& operator = (int x);
		BigInteger& operator = (const std::string& s);
		const bool operator < (const BigInteger& x) const;
		const bool operator > (const BigInteger& x) const;
		const bool operator <= (const BigInteger& x) const;
		const bool operator >= (const BigInteger& x) const;
		const bool operator != (const BigInteger& x) const;
		const bool operator == (const BigInteger& x) const;
		BigInteger operator -() const;
		BigInteger& operator += (const BigInteger& x);
		BigInteger& operator -= (const BigInteger& x);
		BigInteger& operator *= (const BigInteger& x);
		BigInteger& operator /= (const BigInteger& x);
		BigInteger& operator %= (const BigInteger& x);
		const BigInteger operator + (const BigInteger& x) const;
		const BigInteger operator - (const BigInteger& x) const;
		const BigInteger operator * (const BigInteger& x) const;
		const BigInteger operator / (const BigInteger& x) const;
		const BigInteger operator % (const BigInteger& x) const;
		friend BigInteger factorial(BigInteger x);
		friend std::pair<BigInteger, BigInteger> divmod(const BigInteger& lhs, const BigInteger& rhs);
	    friend std::istream& operator >> (std::istream& is, BigInteger& x);
	    friend std::ostream& operator << (std::ostream& os, const BigInteger& x);
	    friend const BigInteger abs(BigInteger x);
	};
}


#endif
