#pragma once
#include <iostream>
#include <string>
#include "clsMyStackArr.h"
using namespace std;


class clsMyString
{
private:
	string _Value;
	
public:

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


};

