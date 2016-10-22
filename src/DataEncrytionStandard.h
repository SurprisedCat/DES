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

private:
	  //密钥
	  char key[8]={};
	  //16个子密钥
	  array<array<bool,56>,16>offKeys;
	  array<array<bool,48>,16>subKeys;

	  const static int PC_1[56];
	  const static int keyOff[16];
	  const static int PC_2[48];
public:
//Step 1.Genenrate the key
	//设置密码
	bool SetKey(const char* _key);
	//字符转换成二进制码
	array<bool,64> CharToBits(char _keyChar[8]);
	//生成16轮密钥
	array<array<bool,48>,16> SubKeysGenerate();
	array<bool,56> SubKeyOff(array<bool,56>& _key56,int off);

//step 2. Encrypt the 64 bits
private:
	  char msg[8];
	  //分为左右两个部分,每个32位
	  vector<bool> msgLeft;
	  vector<bool> msgRight;
	  //IP变换表
	  const static int IP[64];
	  //e变换表
	  const static int eOperator[48];
	  //S盒
	  const static int sBox[8][64];
	  //p变换表
	  const static int pOperator[32];
	  //逆IP变换
	  const static int backIp[64];

	  //加密结果
	  array<bool,64> cipher;

public:
	  //加密字符串
	  char msgCipher[8];
	  //设置密码
	  bool SetMsg(const char* _key);
	  //加密主函数
	  array<bool,64> Encryption();
	  vector<bool> XorDes(vector<bool> para1, vector<bool> para2);
	  vector<bool> RightEncryption(vector<bool>& _msg,array<bool,48>&_key);

private:
	  //解密密钥，是加密密钥的16位逆序
	  array<array<bool,48>,16>decryptKeys;
	  //解密结果
	  array<bool,64> decipher;

public:
	  //解密字符串
	  char msgDecipher[8];
	  array<array<bool,48>,16> DecryptKeysGenerate();
	  array<bool,64> Decryption();

};
#endif /* DATAENCRYTIONSTANDARD_H_ */
