#pragma once
#include <iostream>

using namespace std;

class EjemploConstCast
{

	static void ejemploConstCast()
	{
		const int x = 10;
		int* p = const_cast<int*>(&x);
		*p = 20;
		cout << "Valor de x: " << x << endl;
	}

};

