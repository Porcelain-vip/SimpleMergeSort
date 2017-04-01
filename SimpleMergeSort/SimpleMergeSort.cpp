#include<iostream>
#include<memory>
using namespace std;

template<typename Type>
void SimpleMergeSortHelp(Type* a, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;                                                       //also      int mid = (left + right) / 2;
		SimpleMergeSortHelp<Type>(a, left, mid);                            //sort left part
		SimpleMergeSortHelp<Type>(a, mid + 1, right);                  //sort right part

		int i = left, low = left, high = mid + 1;
		unique_ptr<Type[]> b(new Type[right + 1]);
		for (; low <= mid && high <= right;)                                             //merge two parts
		{
			if (a[low] <= a[high]) { b[i] = a[low]; ++low; }
			else { b[i] = a[high]; ++high; }
			++i;
		}
		for (; low <= mid;) { b[i] = a[low]; ++low; ++i; }
		for (; high <= right;) { b[i] = a[high]; ++high; ++i; }
		for (i = left; i <= right; ++i) a[i] = b[i];
	}
}

template<typename Type>
void SimpleMergeSort(Type* a, int n)
{
	SimpleMergeSortHelp<Type>(a, 0, n - 1);
}

int main()
{
	int a[10];
	cout << "Please enter 10 numbers as you like: ";
	for (int& value : a) cin >> value;
	SimpleMergeSort<int>(a, 10);
	cout << "Low-to-High: ";
	for (int& value : a) cout << value << "   "; cout << endl;
	return EXIT_SUCCESS;
}