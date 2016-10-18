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


#include"des.h"
using namespace std;
#include <iostream>
int main()
{
    char msg[8]={'r','o','m','a','n','t','i','\0'};
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
    	 cout<<std::hex<<(int)key[i];
     return 0;


}
