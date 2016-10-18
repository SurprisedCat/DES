/*
 * DataEncrytionStandard.h
 *
 *  Created on: 2016年10月18日
 *      Author: lelouch
 */

#ifndef DATAENCRYTIONSTANDARD_H_
#define DATAENCRYTIONSTANDARD_H_

class DataEncrytionStandard {
public:
	DataEncrytionStandard();
	virtual ~DataEncrytionStandard();

//Step 1.Genenrate the key
	bool SetKey(const char* _key);

private:
	  //密钥
	  char key[8];
	  bool bkey[64];//????
	  //16个子密钥
	  bool subkey[16][48];

	  const static int PC_1[64];
};

#endif /* DATAENCRYTIONSTANDARD_H_ */
