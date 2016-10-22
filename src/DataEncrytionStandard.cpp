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
//IP
const int DataEncrytionStandard::IP[64] = {
		     58,   50,   42,   34,   26,   18,   10,   2,
		     60,   52,   44,   36,   28,   20,   12,   4,
		     62,   54,   46,   38,   30,   22,   14,   6,
		     64,   56,   48,   40,   32,   24,   16,   8,
		     57,   49,   41,   33,   25,   17,    9,   1,
		     59,   51,   43,   35,   27,   19,   11,   3,
		     61,   53,   45,   37,   29,   21,   13,   5,
		  	 63,   55,   47,   39,   31,   23,   15,   7
			};
//E bit-selection table
const int DataEncrytionStandard::eOperator[48]={
  32,1,2,3,4,5,
  4,5,6,7,8,9,
  8,9,10,11,12,13,
  12,13,14,15,16,17,
  16,17,18,19,20,21,
  20,21,22,23,24,25,
  24,25,26,27,28,29,
  28,29,30,31,32,1
};
//S box
const int DataEncrytionStandard::sBox[8][64]={
  {
    14, 4, 13, 1, 1, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
      0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
      4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
      15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
  },

  {
    15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
      3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
      0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
      13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
    },

    {
      10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
        13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
        13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
        1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
    },

    {
      7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
        13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
        10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
        3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
      },

      {
        2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
      },

      {
        12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
        },

        {
          4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
            13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
            1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
            6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
        },

        {
          13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 13, 14, 5, 0, 12, 7,
            1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
            7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
            2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
          }
};
//P operator
const int DataEncrytionStandard::pOperator[32]={
			  16,	7,		20,		21,
			  29,	12,		28,		17,
			  1,	15,		23,		26,
			  5,	18,		31,		10,
			  2,	8,		24,		14,
			  32,	27,		3,		9,
			  19,	13,		30,		6,
			  22,	11,		4,		25
};
const int DataEncrytionStandard::backIp[64]={
				  40,8,48,16,56,24,64,32,
				  39,7,47,15,55,23,63,31,
				  38,6,46,14,54,22,62,30,
				  37,5,45,13,53,21,61,29,
				  36,4,44,12,52,20,60,28,
				  35,3,43,11,51,19,59,27,
				  34,2,42,10,50,18,58,26,
				  33,1,41,9,49,17,57,25
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

array<array<bool,48>,16> DataEncrytionStandard::SubKeysGenerate()
{
	array<bool,64> keyInit = CharToBits(this->key);

/********************************************************/
	//TODO change the key
	string test = "0011101100111000100110000011011100010101001000001111011101011110";
//	string test = "0011000100110010001100110011010000110101001101100011011100111000";
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
//	for(int i=0;i<16;i++)
//	{
//		cout<<"KS"<<i+1<<":";
//		for(int j=0;j<48;j++)
//			cout<<subKeys[i][j];
//		cout<<endl;
//	}
	return subKeys;
}

array<bool,56> DataEncrytionStandard::SubKeyOff(array<bool,56>& _key56,int off)
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
/**************************明文加密*******************************/
//设置明文的内容，截取或补齐
bool DataEncrytionStandard::SetMsg(const char* _msg)
{
	int lengthCout=0;
	while(_msg!='\0' && lengthCout<8)
	{
		this->msg[lengthCout] = _msg[lengthCout];////密码的长度只截取前面8位，不够的话用‘0’补齐。
		lengthCout++;
	}
	return true;
}

array<bool,64> DataEncrytionStandard::Encryption()
{
	//明文字符串转64位bit
	SubKeysGenerate();
	array<bool,64> msgInit = CharToBits(this->msg);

	//通过初试变换IP,64bits重新排位
	array<bool,64> msgIP;
	for(int counter=0;counter<64;counter++)
		msgIP[counter] = msgInit[IP[counter]-1];

	//拆分明文成两个32位
	for(int counter=0;counter<32;counter++)
		this->msgLeft.push_back(msgIP[counter]);
	for(int counter=0;counter<32;counter++)
		this->msgRight.push_back(msgIP[counter+32]);

	//16轮加密
	vector<bool> tempMsgLeft;
	vector<bool> tempMsgRight;
	for(int iterator=0;iterator<16;iterator++)
	{
		tempMsgLeft = this->msgRight;
		tempMsgRight = XorDes(this->msgLeft,RightEncryption(this->msgRight,this->subKeys[iterator]));
		msgLeft = tempMsgLeft;
		msgRight= tempMsgRight;
		cout<<"L"<<iterator+1<<":";
		for(int i=0;i<msgLeft.size();i++)
			cout<<msgLeft[i];
		cout<<endl;
		cout<<"R"<<iterator+1<<":";
		for(int i=0;i<msgRight.size();i++)
			cout<<msgRight[i];
		cout<<endl;
	}

	//R16L16拼接
	vector<bool> r16L16;
	vector<bool>::iterator itR16L16;
	itR16L16 = msgRight.begin();
	while(itR16L16!=msgRight.end())
	{
		r16L16.push_back(*itR16L16);
		itR16L16++;
	}
	itR16L16 = msgLeft.begin();
		while(itR16L16!=msgLeft.end())
		{
			r16L16.push_back(*itR16L16);
			itR16L16++;
		}

	//IP(-1)变换
	for(int counter = 0;counter<64;counter++)
		this->cipher[counter] = r16L16[backIp[counter]-1];

	//将64位bit强制转换成字符串，会有乱码
	for(int counter=0;counter<8;counter++)
	{
		char tempByte = 0x00;
		for(int i=0;i<8;i++)
			//注意顺序
			tempByte = tempByte|(cipher[8*counter+i]<<(7-i));
		msgCipher[counter] = tempByte;
	}

	return this->cipher;
}
//实现异或操作，不受位数限制
vector<bool> DataEncrytionStandard::XorDes(vector<bool> para1, vector<bool> para2)
{
	vector<bool> result;
	vector<bool>::iterator it1,it2;
	it1 = para1.begin();
	it2 = para2.begin();
	while(it1!=para1.end() && it2!=para2.end())
	{
		result.push_back(*it1 ^ *it2);
		it1++;
		it2++;
	}
	return result;

}

vector<bool> DataEncrytionStandard::RightEncryption(vector<bool>& _msg,array<bool,48>&  _key)
{
	vector<bool> nextRight;
	//根据E选择表将32位bits的右半边明文转换为48位bits
	for(int counter=0;counter<48;counter++)
		nextRight.push_back(_msg[eOperator[counter]-1]);

	//经过E变换的48位右半边bits和子密钥异或，得到48位结果
	vector<bool> keyVector;
	for(int counter=0;counter<48;counter++)
		keyVector.push_back(_key[counter]);
	nextRight = XorDes(nextRight, keyVector);

	for(int i=0;i<48;i++)
			cout<<keyVector[i];
	cout<<endl;
	for(int i=0;i<48;i++)
			cout<<nextRight[i];
	cout<<endl;

	//S盒处理
	vector<bool> temp;
	vector<bool> fourBitsResults;
	vector<bool>::iterator sandBox=nextRight.begin();
	int sandBoxNumber = 0;
	while(sandBox!=nextRight.end())
	{
		temp.push_back(*sandBox);
		//删除该元素后，迭代器自动到下end一个
		nextRight.erase(sandBox);
		//6个一组已经达成
		if(temp.size()>=6)
		{
			//获取sandbox的行数与列数
			int sandBoxRow = (temp[0]<<1)|temp[5];
			int sandBoxCol = (temp[1]<<3)|(temp[2]<<2)|(temp[3]<<1)|temp[4];
			temp.clear();
			//获取一个0-15的值
			int sBoxValue = sBox[sandBoxNumber][sandBoxRow*16+sandBoxCol];
			sandBoxNumber++;
			//2进制转换，注意顺序
			for(int i=0;i<4;i++)
				fourBitsResults.push_back(sBoxValue>>(3-i)&1);
		}
	}

	//对S盒变换之后的32位bits再做P变换
		for(int counter = 0;counter<32;counter++)
			nextRight.push_back(fourBitsResults[pOperator[counter]-1]);

	return nextRight;
}

array<array<bool,48>,16> DataEncrytionStandard::DecryptKeysGenerate()
{
	SubKeysGenerate();
	for(int counter=0;counter<16;counter++)
	{
		decryptKeys[counter] = (subKeys[15-counter]);
	}


	//TODO
	for(int i=0;i<16;i++)
	{
		cout<<endl;
		cout<<"KS"<<i+1<<":";
		for(int j=0;j<48;j++)
			cout<<decryptKeys[i][j];
	}

	return decryptKeys;
}


array<bool,64> DataEncrytionStandard::Decryption()
{
	//明文字符串转64位bit
	DecryptKeysGenerate();

	array<bool,64> msgInit = CharToBits(this->msgCipher);
	for(int i=0;i<64;i++)
		cout<<msgInit[i];
	cout<<endl;

	//通过初试变换IP,64bits重新排位
	array<bool,64> msgIP;
	for(int counter=0;counter<64;counter++)
		msgIP[counter] = msgInit[IP[counter]-1];

	//拆分明文成两个32位
	this->msgLeft.clear();
	this->msgRight.clear();
	for(int counter=0;counter<32;counter++)
		this->msgLeft.push_back(msgIP[counter]);
	for(int counter=0;counter<32;counter++)
		this->msgRight.push_back(msgIP[counter+32]);

	//16轮加密
	vector<bool> tempMsgLeft;
	vector<bool> tempMsgRight;
	for(int iterator=0;iterator<16;iterator++)
	{
		tempMsgLeft = this->msgRight;
		tempMsgRight = XorDes(this->msgLeft,RightEncryption(this->msgRight,this->decryptKeys[iterator]));
		msgLeft = tempMsgLeft;
		msgRight= tempMsgRight;
		cout<<"L"<<iterator+1<<":";
		for(unsigned int i=0;i<msgLeft.size();i++)
			cout<<msgLeft[i];
		cout<<endl;
		cout<<"R"<<iterator+1<<":";
		for(unsigned int i=0;i<msgRight.size();i++)
			cout<<msgRight[i];
		cout<<endl;
	}

	//R16L16拼接
	vector<bool> r16L16;
	vector<bool>::iterator itR16L16;
	itR16L16 = msgRight.begin();
	while(itR16L16!=msgRight.end())
	{
		r16L16.push_back(*itR16L16);
		itR16L16++;
	}
	itR16L16 = msgLeft.begin();
		while(itR16L16!=msgLeft.end())
		{
			r16L16.push_back(*itR16L16);
			itR16L16++;
		}

	//IP(-1)变换
	for(int counter = 0;counter<64;counter++)
		this->decipher[counter] = r16L16[backIp[counter]-1];

	//将64位bit强制转换成字符串
		for(int counter=0;counter<8;counter++)
		{
			char tempByte = 0x00;
			for(int i=0;i<8;i++)
			{
				if(decipher[8*counter+i])
					tempByte = tempByte|(1<<(7-i));
			}
			msgDecipher[counter] = tempByte;
		}

	return this->decipher;
}
