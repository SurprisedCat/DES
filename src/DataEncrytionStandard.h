/*
 * DataEncrytionStandard.h
 *
 *  Created on: 2016年10月18日
 *      Author: lelouch
 */

#ifndef DATAENCRYTIONSTANDARD_H_
#define DATAENCRYTIONSTANDARD_H_

#include <bitset>
#include <vector>
#include <iostream>
using std::bitset;
using std::vector;
using std::cout;
using std::endl;

class DataEncrytionStandard {
public:
	DataEncrytionStandard();
	virtual ~DataEncrytionStandard();

//	bool CharToBitSet

//Step 1.Genenrate the key
	//设置密码
	bool SetKey(const char* _key);
	//字符转换成二进制码
	bitset<64> CharToBits(char _keyChar[8]);
	//生成16轮密钥
	vector<bitset<48> > SubKeys();

private:
	  //密钥
	  char key[8]={};
	  bitset<64> keyInit[64];//????
	  //16个子密钥
	  bool subkey[16][48];

	  const static int PC_1[64];
};

#endif /* DATAENCRYTIONSTANDARD_H_ */
