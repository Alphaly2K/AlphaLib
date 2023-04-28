#include "bignum.h"
#include <iostream>
#include <cstring>

using alp::BigDecimical;
using alp::BigNumber;
using alp::RadixNotEqualException;
using std::cin;
using std::cout;
using std::endl;
using std::isalpha;
using std::strlen;
#pragma region BigNumber class
/// @brief Decimical
/// @param ch
/// @return
int BigNumber::GetDec(char ch)
{
	if (isalpha(ch))
		return ch - 'A' + 10;
	else
		return ch - '0';
}
/// @brief Itoa int to array
/// @param num
/// @param str
/// @param radix
/// @return The pointer of the result
char *itoa(int num, char *str, int radix)
{
	char index[] = "0123456789ABCDEF";
	unsigned unum;
	int i = 0, j, k;
	if (radix == 10 && num < 0)
	{
		unum = (unsigned)-num;
		str[i++] = '-';
	}
	else
		unum = (unsigned)num;
	do
	{
		str[i++] = index[unum % (unsigned)radix];
		unum /= radix;
	} while (unum);
	str[i] = '\0';
	if (str[0] == '-')
		k = 1;
	else
		k = 0;

	for (j = k; j <= (i - 1) / 2; j++)
	{
		char temp;
		temp = str[j];
		str[j] = str[i - 1 + k - j];
		str[i - 1 + k - j] = temp;
	}
	return str;
}
/// @brief Get the result of a and b(radix=radi)
/// @param a
/// @param b
/// @param radi
/// @return char*
char *BigNumber::GetTotal(char *a, char *b, int radi)
{
	const char *output = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int lena = strlen(a);
	const int lenb = strlen(b);
	int m[lena + 1], n[lenb + 1], tmpAns[lenb + 1];
	int maxLen = (lena < lenb) ? lenb : lena;
	for (int i = 0; i < lena; i++)
		m[i] = GetDec(a[lena - i - 1]);
	for (int i = 0; i < lenb; i++)
		n[i] = GetDec(b[lenb - i - 1]);
	for (int i = 0; i < maxLen; i++)
	{
		tmpAns[i] += m[i] + n[i];
		tmpAns[i + 1] = tmpAns[i] / radi;
		tmpAns[i] %= radi;
	}
	if (tmpAns[maxLen])
		maxLen++;
	char *Ans = new char[maxLen];
	for (int i = maxLen - 1; i >= 0; i--)
	{
		Ans[maxLen - i - 1] = char(output[tmpAns[i]]);
	}
	return Ans;
}
/// @brief Default construction function
BigNumber::BigNumber()
{
	number = new char[1];
	number[0] = '0';
	radi = 10;
}
/// @brief BigNumber construction function
/// @param num
/// @param nadv
BigNumber::BigNumber(char *num, int nradi = 10)
{
	int numlen = strlen(num);
	number = new char[numlen];
	radi = nradi;
}
/// @brief BigNumber add with BigNumber
/// @param num
/// @return BigNumber class
BigNumber BigNumber::Add(BigNumber num)
{
	try
	{
		return *this + num;
	}
	catch (RadixNotEqualException &e)
	{
		e.Print();
		return BigNumber(0, 10);
	}
}
/// @brief BigNumber add with char*
/// @param num
/// @param nradi
/// @return BigNumber class
BigNumber BigNumber::Add(char *num, int nradi)
{
	BigNumber newBN(num, nradi);
	try
	{
		return *this + newBN;
	}
	catch (RadixNotEqualException &e)
	{
		e.Print();
		return BigNumber(0, 10);
	}
}
/// @brief BigNumber add with integer
/// @param num
/// @return BigNumber class
BigNumber BigNumber::Add(int num)
{
	char snum[32];
	itoa(num, snum, this->radi);
	BigNumber newBN(snum, this->radi);
	return *this + newBN;
}
/// @brief Operator+ override
/// @param num
/// @return BigNumber class
BigNumber BigNumber::operator+(const BigNumber num)
{
	BigNumber newBN(num.number, num.radi);
	if (this->radi == num.radi)
		newBN.number = BigNumber::GetTotal(this->number, newBN.number, num.radi);
	else
	{
		throw RadixNotEqualException(this->radi, num.radi); // Use try-catch to detect RadixNotEqualException.
	}
	return newBN;
}
#pragma endregion
#pragma region BigDecimical class
/// @brief Default construction function
BigDecimical::BigDecimical()
{
	number = new char[1];
	number[0] = '0';
}
/// @brief BigDecimical construction function
/// @param num
BigDecimical::BigDecimical(char *num)
{
	int numlen = strlen(num);
	number = new char[numlen];
}
#pragma endregion
#pragma region RadixNotEqualExeption class
/// Print the exception
void RadixNotEqualException::Print() const
{
	switch (m_flag)
	{
	case 1:
		cout << "The radix of the value left is bigger than that of the right one." << endl;
		break;
	case 2:
		cout << "The radix of the value right is bigger than that of the left one." << endl;
	default:
		cout << "Unknown exception detected." << endl;
		break;
	}
}
#pragma endregion