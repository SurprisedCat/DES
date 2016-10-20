/*
 * DataEncrytionStandard.h
 *
 *  Created on: 2016年10月18日
 *      Author: lelouch
 */

#ifndef DATAENCRYTIONSTANDARD_H_
#define DATAENCRYTIONSTANDARD_H_

#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <list>
using std::vector;
using std::array;
using std::list;
using std::cout;
using std::endl;
using std::string;

class DataEncrytionStandard {
public:
	DataEncrytionStandard();
	virtual ~DataEncrytionStandard();

//	bool CharToBitSet

//Step 1.Genenrate the key
	//设置密码
	bool SetKey(const char* _key);
	//字符转换成二进制码
	array<bool,64> CharToBits(char _keyChar[8]);
	//生成16轮密钥
	array<array<bool,48>,16> SubKeys();
	array<bool,56> SubKeyOff(array<bool,56> _key56,int off);

private:
	  //密钥
	  char key[8]={};
	  bool keyInit[64];//????
	  //16个子密钥
	  array<array<bool,56>,16>offKeys;
	  array<array<bool,48>,16>subKeys;

	  const static int PC_1[56];
	  const static int keyOff[16];
	  const static int PC_2[48];
};

#endif /* DATAENCRYTIONSTANDARD_H_ */
