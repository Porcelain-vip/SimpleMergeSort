#include<iostream>
#include<memory>

template<typename Type>
void simplemergesorthelp(Type* a, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		simplemergesorthelp<Type>(a, left, mid);
		simplemergesorthelp<Type>(a, mid + 1, right);

		int i, low, high;
		std::unique_ptr<Type[]> b(new Type[right + 1]);
		for (i = left, low = left, high = mid + 1; low <= mid && high <= right;)
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
void simplemergesort(Type* a, int n)
{
	simplemergesorthelp<Type>(a, 0, n - 1);
}

int main()
{
	using namespace std;
	int a[10];
	cout << "Please enter 10 numbers as you like: ";
	for (int& value : a) cin >> value;
	simplemergesort<int>(a, 10);
	cout << "Low-to-High: ";
	for (int& value : a) cout << value << "   "; cout << endl;
	return 0;
}