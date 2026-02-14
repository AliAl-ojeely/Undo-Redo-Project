#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;

public:

	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
		{
			return false;
		}

		OriginalArray[Index] = Value;
		return true;
	}


	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " ";
		}

		cout << "\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0) NewSize = 0;

		T* NewArray = new T[NewSize];

		// Limit the original size of the array to the new size if it is less
		if (NewSize < _Size)
			_Size = NewSize;

		// copy data from OriginalArray to TempArray
		for (int i = 0; i < _Size; i++)
		{
			NewArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = NewArray;
	}

	T GetItem(int Index)
	{
		//if (Index >= _Size || Index < 0)
		//{
		//	return T();
		//}
		return OriginalArray[Index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		int Counter = 0;

		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[Counter] = OriginalArray[i];
			Counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;

		//T temp;
		//for (int i = 0; i < _Size / 2; ++i)
		//{
		//	temp = OriginalArray[i];
		//	OriginalArray[i] = OriginalArray[_Size - 1 - i];
		//	OriginalArray[_Size - 1 - i] = temp;
		//}
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;


		//Resize(0);
	}

	//void DeleteItamAt(int Index)
	//{
	//	if (Index >= _Size || Index < 0)
	//	{
	//		return;
	//	}
	//	_Size--;
	//	for (int i = Index; i < _Size; i++)
	//	{	
	//		OriginalArray[i] = OriginalArray[i + 1];
	//	}
	//	
	//}

	// Reallocation & Copying:
	// Physical Deletion for Memory Optimization
	bool DeleteItamAt(int Index)
	{
		if (Index >= _Size || Index < 0)
		{
			return false;
		}

		_Size--;

		_TempArray = new T[_Size];

		//Copy all Before Index:
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		//Copy all After Index:
		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;

		OriginalArray = _TempArray;
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItamAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItamAt(_Size - 1);
	}

	int Find(T Value)
	{

		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
			{
				return i;
			}
		}

		return -1;
	}

	// By Value:
	bool DeleteItem(T Value)
	{

		int Index = Find(Value);

		if (Index == -1)
		{
			return false;
		}

		DeleteItamAt(Index);
		return true;
	}

	bool InsertAt(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
		{
			return false;
		}

		_Size++;
		_TempArray = new T[_Size];

		//Copy all Before Index:
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[Index] = Value;

		// Copy all after Index:
		for (int i = Index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;

		return true;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
			return InsertAt(0, Value);
		else
			return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(T Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size - 1, Value);
		else
			return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}

	//void DeleteItem(int Value)
	//{
	//	int Index = Find(Value);
	//	while (Index != -1)
	//	{
	//		DeleteItamAt(Index);
	//		// Verification if the value repated or not
	//		Index = Find(Value);
	//	}
	//}

	// By Value:
	//void DeleteItem(T Value)
	//{
	//	//if (IsEmpty()) return;
	//	for (int i = 0; i < _Size; i++)
	//	{
	//		if (OriginalArray[i] == Value)
	//		{
	//			DeleteItamAt(i);
	//			// As a verification step, if the value repated
	//			i--;
	//		}
	//	}
	//}
};