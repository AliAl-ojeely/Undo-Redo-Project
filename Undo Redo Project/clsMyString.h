// My Solution:
//#pragma once
//#include <iostream>
//#include <string>
//#include "clsMyStackArr.h"
//using namespace std;
//
//
//class clsMyString
//{
//private:
//	string _Value;
//	clsMyStackArr <string> _UndoStack;
//	clsMyStackArr <string> _RedoStack;
//	
//public:
//
//	void SetValue(string NewValue)
//	{
//		_UndoStack.push(_Value);
//
//		_Value = NewValue;
//
//		while (!_RedoStack.IsEmpty())
//		{
//			_RedoStack.pop();
//		}
//	}
//
//	string GetValue()
//	{
//		return _Value;
//	}
//
//	__declspec(property(get = GetValue, put = SetValue)) string Value;
//
//	void Undo()
//	{
//		if (_UndoStack.IsEmpty()) return;
//
//		_RedoStack.push(_Value);
//
//
//		_Value = _UndoStack.Top();
//		_UndoStack.pop();
//	}
//
//	void Redo()
//	{
//		if (_RedoStack.IsEmpty()) return;
//
//		_UndoStack.push(_Value);
//
//		_Value = _RedoStack.Top();
//		_RedoStack.pop();
//	}
//};

// other solution
#pragma
#include <stack>

using namespace std;

class clsMyString
{
private:
	stack <string> _Undo;
	stack <string> _Redo;
	string _Value;

public:

	void Set(string value)
	{
		_Undo.push(_Value);

		_Value = value;
	}

	string Get()
	{
		return _Value;
	}

	__declspec(property(get = Get, put = Set)) string Value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}
};