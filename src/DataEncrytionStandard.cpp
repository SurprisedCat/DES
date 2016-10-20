/*
 * DataEncrytionStandard.cpp
 *
 *  Created on: 2016骞�10鏈�18鏃�
 *      Author: lelouch
 */

#include "DataEncrytionStandard.h"


const int DataEncrytionStandard::PC_1[56]=
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
////设置密钥的内容，截取或补齐
bool DataEncrytionStandard::SetKey(const char* _key)
{
	int lengthCout=0;
	while(_key!='\0' && lengthCout<8)
	{
		this->key[lengthCout] = _key[lengthCout];////密码的长度只截取前面8位，不够的话用‘0’补齐。
		lengthCout++;
	}
	return true;
}
array<bool,64> DataEncrytionStandard::CharToBits(char _inChar[8])
{
	array<bool,64> bits;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			bits[i*8+7-j] = (_inChar[i]>>j)&1;
	return bits;
}

array<array<bool,48>,16> DataEncrytionStandard::SubKeys()
{
	array<array<bool,48>,16>subkeys;
	array<bool,64> keyInit = CharToBits(this->key);

	//TODO change the key
	string test = "0011101100111000100110000011011100010101001000001111011101011110";
	array<bool,64> testKey;
	for(int i=0;i<64;i++)
	{
		testKey[i] = test[i]=='0'?0:1;
		cout<<testKey[i];
	}
	cout<<endl;
	keyInit = testKey;

	//第一次转换，将
	array<bool,56> keyPC_1;
	for(int counter=0;counter<56;counter++)
	{
		keyPC_1[counter] = keyInit[PC_1[counter]-1];
	}



	return subkeys;
}


DataEncrytionStandard::~DataEncrytionStandard() {
	// TODO Auto-generated destructor stub
}

