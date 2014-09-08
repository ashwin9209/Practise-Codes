#include <iostream.h>

int main()
{
	int n, a = 0, b = 1, c;
	cout<<"Generate how many Fibonacci numbers: ";
	cin>>n;
	cout<<a<<" "<<b<<" ";

	for ( int i = 0; i < n; i++)
	{
		c = a + b;
		cout<<" "<<c;
		a = b;
		b = c;
	}

	return 0;
}