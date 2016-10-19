/*
 * DataEncrytionStandard.cpp
 *
 *  Created on: 2016年10月18日
 *      Author: lelouch
 */

#include "DataEncrytionStandard.h"


const int PC_1[64]=
			  {57,  49,    41,   33,    25,    17,    9,
               1,   58,    50,   42,    34,    26,   18,
              10,    2,    59,   51,    43,    35,   27,
              19,   11,     3,   60,    52,    44,   36,
              63,   55,    47,   39,    31,    23,   15,
               7,   62,    54,   46,    38,    30,   22,
              14,    6,    61,   53,    45,    37,   29,
              21,   13,     5,   28,    20,    12,    4
			  };

DataEncrytionStandard::DataEncrytionStandard() {
	// TODO Auto-generated constructor stub

}
//设置密钥的内容，截取或补齐
bool DataEncrytionStandard::SetKey(const char* _key)
{
	int lengthCout=0;
	while(_key!='\0' && lengthCout<8)
	{
		this->key[lengthCout] = _key[lengthCout];//密码的长度只截取前面8位，不够的话用‘0’补齐。
		lengthCout++;
	}
	return true;
}
bitset<64> DataEncrytionStandard::CharToBits(char _inChar[8])
{
	bitset<64> bits;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			bits[(8-i)*8+j] = (_inChar[i]>>j)&1;
	return bits;
}

vector<bitset<48> > DataEncrytionStandard::SubKeys()
{
	vector<bitset<48> >subkeys;
	cout<<CharToBits(this->key);
	return subkeys;
}


DataEncrytionStandard::~DataEncrytionStandard() {
	// TODO Auto-generated destructor stub
}

