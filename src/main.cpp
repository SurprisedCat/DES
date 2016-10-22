//============================================================================
// Name        : DES.cpp
// Author      : SurprisedCat
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//using namespace std;

//int main() {
//	cout << "Welcome to DES" << endl; // prints Welcome to DES
//	return 0;
//}

/*************************************************************************
    > File Name: Des.cpp
    > Author: SongLee
    > E-mail: lisong.shine@qq.com
    > Created Time: 2014年06月01日 星期日 19时46分32秒
    > Personal Blog: http://songlee24.github.com
 ************************************************************************/

#include <bitset>
#include"des.h"
#include <iostream>
#include <string>
#include "DataEncrytionStandard.h"
using namespace std;

int main()
{
	DataEncrytionStandard des;
	des.SetKey("12345678");
	des.SetMsg("helloDES");
	array<bool,64> cipher = des.Encryption();
	for(int i=0;i<64;i++)
		cout<<cipher[i];
	cout<<endl;
	cout<<des.msgCipher<<endl;

	array<bool,64> decipher = des.Decryption();
	for(int i=0;i<64;i++)
		cout<<decipher[i];
	cout<<endl;
	for(int i=0;i<8;i++)
		cout<<des.msgDecipher[i];

	bool test = 1;
	test = test<<7;
	cout<<(int)test;//证明bool不支持移位

	char testChar[8] = {'n','i','h','a','o','c','h','a'};
	cout<<testChar<<endl;



   /* char msg[8]={'r','o','m','a','n','t','i','\0'};
    char key[8]={'1'};
     cout<<"明文：";
     for (int i = 0; i < 8; i++)
     {
       cout<<msg[i]<<' ';
     }

     DES des;
     //设置明文
     des.SetMsg(msg,8);
     //设置密钥
     des.SetKey(key,8);
     //生产子密钥
     des.ProduceSubKey();
     //加密
     des.Crypte();
     //输出密文
     des.OutPutCryptedMsg();
     //解密
     des.Decipher();
     //输出解密后的明文
     des.OutPutDecipher();
     for(int i=0;i<8;i++)
    	 cout<<std::hex<<(int)key[i];*/



     return 0;


}
