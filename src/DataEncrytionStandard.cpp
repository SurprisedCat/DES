/*
 * DataEncrytionStandard.cpp
 *
 *  Created on: 2016骞�10鏈�18鏃�
 *      Author: lelouch
 */

#include "DataEncrytionStandard.h"

//PC-1
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
//子密钥位移表
const int DataEncrytionStandard::keyOff[16]={
  1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
};
//PC-2
const int DataEncrytionStandard::PC_2[48] = {
			 14,   17,  11,   24,    1,   5,
			  3,   28,  15,    6,   21,  10,
			 23,   19,  12,    4,   26,   8,
			 16,    7,  27,   20,   13,   2,
			 41,   52,  31,   37,   47,  55,
			 30,   40,  51,   45,   33,  48,
			 44,   49,  39,   56,   34,  53,
			 46,   42,  50,   36,   29,  32
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
			//这里注意顺序
			bits[i*8+7-j] = (_inChar[i]>>j)&1;
	return bits;
}

array<array<bool,48>,16> DataEncrytionStandard::SubKeys()
{
	array<bool,64> keyInit = CharToBits(this->key);

/********************************************************/
	//TODO change the key
//	string test = "0011101100111000100110000011011100010101001000001111011101011110";
	string test = "0011000100110010001100110011010000110101001101100011011100111000";
	array<bool,64> testKey;
	for(int i=0;i<64;i++)
		testKey[i] =(test[i]=='0'?0:1);
	keyInit = testKey;
/********************************************************/

	//第一次转换，将64bit的密钥根据PC-1变换转换成56bit。
	array<bool,56> keyPC_1;
	for(int counter=0;counter<56;counter++)
	{
		keyPC_1[counter] = keyInit[PC_1[counter]-1];
	}

	//进行16轮移位，获取16个子密钥块
	//array<array<bool,48>,16>subKeys; defined in the head file
	//array<array<bool,48>,16>subKeys; defined in the head file
	for(int iterator=0;iterator<16;iterator++)
	{
		if(iterator==0)
			offKeys[iterator] = SubKeyOff(keyPC_1,keyOff[iterator]);
		else
			offKeys[iterator] = SubKeyOff(offKeys[iterator-1],keyOff[iterator]);
	}

	//第二次转换，通过PC-2将56位子密钥变成48位子密钥，得到最后的第n轮加密使用的子密钥。
	for(int iterator=0;iterator<16;iterator++)
	{
		for(int counter=0;counter<48;counter++)
			{
				subKeys[iterator][counter] = offKeys[iterator][PC_2[counter]-1];
			}
	}
	for(int i=0;i<16;i++)
	{
		cout<<"KS"<<i+1<<":";
		for(int j=0;j<48;j++)
			cout<<subKeys[i][j];
		cout<<endl;
	}
	return subKeys;
}

array<bool,56> DataEncrytionStandard::SubKeyOff(array<bool,56>_key56,int off)
{
	//将密钥拆分成左右两半，各28位。
	list<bool> keyC;
	list<bool> keyD;
	//移位后的结果
	array<bool,56> keyOffResult;
	//前28位
	for(int counter=0;counter<28;counter++)
	{
		keyC.push_back(_key56[counter]);
	}
	//后28位
	for(int counter=28;counter<56;counter++)
	{
		keyD.push_back(_key56[counter]);
	}
	//循环移位,for内是一次移位
	for(int i=0;i<off;i++)
	{
		bool temp = keyC.front();
		keyC.pop_front();
		keyC.push_back(temp);

		temp = keyD.front();
		keyD.pop_front();
		keyD.push_back(temp);
	}
	for(int counter = 0;counter<28;counter++)
	{
		keyOffResult[counter] = keyC.front();
		keyC.pop_front();
	}
	for(int counter = 28;counter<56;counter++)
	{
		keyOffResult[counter] = keyD.front();
		keyD.pop_front();
	}

	return keyOffResult;
}
DataEncrytionStandard::~DataEncrytionStandard() {
	// TODO Auto-generated destructor stub
}

