
#include"basic.h"


using std::endl;
using std::cout;
using std::cin;
int main() {
	
	Currency g, h(plus, 3, 50), i, j;
	g.Set(minus, 2, 25);
	i.Set(-6.45);
	j = h + g;
	std::cout<<j<< std::endl;
	i += h;
	std::cout <<i<< std::endl;
	j = (i += g) + h;
	cout << j << endl;
	cout << i << endl;
	cin >> j>>i;
	cout << j << endl;
	cout << i << endl;
}