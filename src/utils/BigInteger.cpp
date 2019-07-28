#include "utils/BigInteger.hpp"

#include <utility>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

dawn::BigInteger& dawn::BigInteger::normalize() {
	int i = a.size() - 1;
	while (i >= 0 && a[i] == 0) --i;
	a.resize(i+1);
	if (a.size() == 0) negative = false;
	return *this;
}

dawn::BigInteger::BigInteger(int x) : negative(x < 0) {
	x = std::abs(x);
	for (; x > 0; x /= BigInteger::Base) a.push_back(x % BigInteger::Base);
}

dawn::BigInteger::BigInteger(const std::string& s): negative(false) {
	int p = 0;
	if (s[p] == '-') { ++p; negative = true; }
	else if (s[p] == '+') { ++p; }
	for (int i = s.size()-1, v = BigInteger::Base; i >= p; --i, v*=10) {
		int x = s[i]-'0';
		if (x < 0 || 9 < x) {
			spdlog::critical("Unable to parse Big Integer for {}", s);
			return;
		}
		if (v == BigInteger::Base) {
			v = 1;
			a.push_back(x);
		} else a.back() += (x)*v;
	}
	normalize();
}
dawn::BigInteger& dawn::BigInteger::operator = (const dawn::BigInteger& x) {
	negative = x.negative;
	a = x.a;
	return *this;
}

dawn::BigInteger& dawn::BigInteger::operator = (int x) { 
	return *this = BigInteger(x); 
}

dawn::BigInteger& dawn::BigInteger::operator = (const std::string& s) { 
	return *this = BigInteger(s); 
}

const bool dawn::BigInteger::operator < (const dawn::BigInteger& x) const {
	if (negative != x.negative) return negative < x.negative;
	if (a.size() != x.a.size()) return (a.size() < x.a.size())^negative;
	for(int i = a.size()-1; i >= 0; --i)
		if (a[i] != x.a[i]) return (a[i] < x.a[i])^negative;
	return false;
}
const bool dawn::BigInteger::operator > (const dawn::BigInteger& x) const { 
	return x < (*this); 
}
const bool dawn::BigInteger::operator <= (const dawn::BigInteger& x) const { 
	return !(x < (*this)); 
}
const bool dawn::BigInteger::operator >= (const dawn::BigInteger& x) const { 
	return !((*this) < x); 
}
const bool dawn::BigInteger::operator != (const dawn::BigInteger& x) const { 
	return (*this)<x || x<(*this); 
}
const bool dawn::BigInteger::operator == (const dawn::BigInteger& x) const { 
	return !((*this)<x || x<(*this)); 
}

dawn::BigInteger dawn::BigInteger::operator -() const {
	dawn::BigInteger ret(*this);
	if (a.size()) ret.negative = !ret.negative;
	return ret;
}
dawn::BigInteger& dawn::BigInteger::operator += (const dawn::BigInteger& x) {
	if (negative != x.negative) return *this -= -x;
	if (a.size() < x.a.size()) a.resize(x.a.size());
	int tmp = 0;
	for (int i = 0; i < a.size(); ++i) {
		a[i] += (i<x.a.size()?x.a[i]:0) + tmp;
		tmp = a[i] / BigInteger::Base;
		a[i] %= BigInteger::Base;
	}
	if (tmp) a.push_back(1);
	return *this;
}
dawn::BigInteger& dawn::BigInteger::operator -= (const dawn::BigInteger& x) {
	if (negative != x.negative) return *this += -x;
	std::vector<int> b(x.a);
	if ((*this < x) ^ negative) {
		a.swap(b);
		negative = !negative;
	}
	for (int i = 0, tmp = 0; i < a.size(); ++i) {
		a[i] += BigInteger::Base - (i<b.size()?b[i]:0) + tmp;
		tmp = a[i] / BigInteger::Base - 1;
		a[i] %= BigInteger::Base;
	}
	return this->normalize();
}
dawn::BigInteger& dawn::BigInteger::operator *= (const dawn::BigInteger& x) {
	negative ^= x.negative;
	std::vector<int> c(a.size()*x.a.size()+1);
	for (int i = 0; i < a.size(); ++i) {
		int64_t tmp = 0;
		for (int j = 0; j < x.a.size(); ++j) {
			int64_t v = (int64_t)a[i] * x.a[j] + c[i+j] + tmp;
			tmp = v / BigInteger::Base;
			c[i+j] = (int)(v % BigInteger::Base);
		}
		if (tmp) c[i+x.a.size()] += (int)tmp;
	}
	a.swap(c);
	return this->normalize();
}
dawn::BigInteger& dawn::BigInteger::operator /= (const dawn::BigInteger& x) {
	return *this = divmod(*this,x).first;
}
dawn::BigInteger& dawn::BigInteger::operator %= (const dawn::BigInteger& x) {
	return *this = divmod(*this,x).second;
}
const dawn::BigInteger dawn::BigInteger::operator + (const dawn::BigInteger& x) const {
	dawn::BigInteger res(*this); 
	return res += x;
}
const dawn::BigInteger dawn::BigInteger::operator - (const dawn::BigInteger& x) const {
	dawn::BigInteger res(*this); 
	return res -= x;
}
const dawn::BigInteger dawn::BigInteger::operator * (const dawn::BigInteger& x) const {
	dawn::BigInteger res(*this); 
	return res *= x;
}
const dawn::BigInteger dawn::BigInteger::operator / (const dawn::BigInteger& x) const {
	dawn::BigInteger res(*this); 
	return res /= x;
}
const dawn::BigInteger dawn::BigInteger::operator % (const dawn::BigInteger& x) const {
	dawn::BigInteger res(*this); 
	return res %= x;
}

std::pair<dawn::BigInteger, dawn::BigInteger> dawn::divmod(const dawn::BigInteger& lhs, 
	const dawn::BigInteger& rhs) {
	if (!rhs.a.size()) {
		spdlog::critical("Division by zero by");
		return  { BigInteger(-1), BigInteger(-1) };
	}
	dawn::BigInteger x(abs(rhs)), q, r;
	for (int i = lhs.a.size()-1; i >= 0; --i) {
		r = r * BigInteger::Base + lhs.a[i];
		int head = 0, tail = BigInteger::Base;
		if (r >= x) {
			while (head + 1 < tail) {
				int mid = (head + tail) / 2;
				if (x * dawn::BigInteger(mid) > r) tail = mid;
				else head = mid;
			}
			r -= x * head;
		}
		q.a.emplace_back(head);
	}
	reverse(q.a.begin(), q.a.end());
	bool neg = lhs.negative ^ lhs.negative;
	q.negative = neg; r.negative = neg;
	return std::make_pair(q.normalize(), r.normalize());
}
std::istream& dawn::operator >> (std::istream& is, dawn::BigInteger& x) {
	std::string tmp; is >> tmp;
	x = dawn::BigInteger(tmp);
	return is;
}
std::ostream& dawn::operator << (std::ostream& os, const dawn::BigInteger& x) {
	if (x.negative) os << '-';
	if (!x.a.size()) os << 0;
	else os << x.a.back();
	for (int i = x.a.size()-2; i >= 0; --i) {
		os.width(dawn::BigInteger::Len);
		os.fill('0');
		os << x.a[i];
	}
	return os;
}
const dawn::BigInteger dawn::abs(dawn::BigInteger x) {
	x.negative = false;
	return x;
}

dawn::BigInteger dawn::factorial(dawn::BigInteger x) {
	return x==0 ? 1 : x * factorial(x-1);
}
