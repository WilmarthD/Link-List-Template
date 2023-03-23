#include <iostream>
#include <string>
#include <iomanip>
#include "ZLL.h"
#include "zany.h"
#include "Crayon.h"

using namespace std;

template <typename T>
void reportZany(const T &param) {
	cout << param << " is ";
	if (!isZany(param)) cout << "not ";
	cout << "zany" << endl;
}

int main(){
    
    ZLL<int> myzll;
    ZLL<int> zll1;
	ZLL<string> zll2;
	ZLL<Crayon> zll3;

    int one = 1;
	int two = 2;
	string one_str = "one";
	string two_str = "Two";
    Crayon one_crayon("Purple", 5);
	Crayon two_crayon("Yellow", 3);
    Crayon three_crayon("Black", 4);

    reportZany(one);
	reportZany(two);
	reportZany(one_str);
	reportZany(two_str);
	reportZany(one_crayon);
	reportZany(two_crayon);

    //Random ints to insert
    int randInts[] = {5, 2, 3, 6, 7, 18, 25, 4};
    int randInts2[] = {5, 6, 7, 8, 11, 12, 1};
    bool worked = false;

    //Add elements to zll
    for(int i = 0; i < 7; i++)
    {
        worked = myzll.front(randInts2[i]);
    }

    for(int i = 0; i < 8; i++)
    {
        zll1.front(randInts[i]);
    }
	zll1.back(1);
    zll1.back(65);

	zll2.back("bird");
    zll2.front("Three");
	zll2.back("Snape");
    zll2.front("canyon");
    zll2.front("Fodder");
    zll2.front("darth");

	zll3.back(one_crayon);
    zll3.front(two_crayon);
    zll3.front(three_crayon);

    cout << endl << "zll1: ";
    zll1.printList();
    cout << "myzll: ";
    myzll.printList();
    cout << "myzll - zll1 = ";
    myzll-=zll1;
    zll1.removeZany();
    zll1.removeNonZany(); //Checking there's no error here
    myzll.printList();

    cout << endl << "Promoting zanny: "<< endl;
    zll2.printList();
    zll2.promoteZany();
    zll2.printList();

    //Iterator check
    cout << endl << "Stepping through with iterator: ";
    myzll.start();
    while(!myzll.done())
    {
        cout << myzll.getNext() << " ";
    }
    cout << endl << endl << "default value when going past done: " << myzll.getNext() << endl;

    return 0;
}
