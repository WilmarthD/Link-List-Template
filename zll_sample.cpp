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
    /*
    ZLL<int> myzll;
    ZLL<int> myzllBack;
    ZLL<string> myzllS;
    ZLL<string> myzllSback;

    //Radnom ints to insert
    int randInts[] = {5, 2, 3, 6, 7, 18, 25, 4};
    int randInts2[] = {5, 6, 7, 8, 11, 12, 1};
    string randStrings[] = {"my", "Humps", "little", "Lumps"};
    string randStrings2[] = {"My", "humps", "Little", "lumps", "Trump"};
    bool worked = false;

    //Add elements to zll
    for(int i = 0; i < (int)sizeof(randInts)/sizeof(int); i++)
    {
        worked = myzll.front(randInts[i]);
    }
    for(int i = 0; i < (int)sizeof(randInts2)/sizeof(int); i++)
    {
        worked = myzllBack.back(randInts2[i]);
    }
    for(int i = 0; i < 4; i++)
    {
        worked = myzllS.front(randStrings[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        worked = myzllSback.back(randStrings2[i]);
    }

    if(worked)
    {
        myzll.printList();
        myzllBack.printList();
        myzllS.printList();
        myzllSback.printList();
        cout << endl;
    }
    //myzll.removeZany();
    //myzll.removeNonZany();
    //myzll.removeZany();

    //myzll-=myzllBack;
    //myzll.removeZany();
    //myzllBack.removeNonZany();
    myzll.promoteZany();
    myzllSback.promoteZany();

    myzll.printList();
    myzllSback.printList();

    //Iterator check
    myzll.start();
    while(!myzll.done())
    {
        cout << myzll.getNext() << " " << endl;
    }
    cout << endl << endl;
    cout << endl << myzll.getNext() << endl;
    */

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

	ZLL<int> zll1;
	ZLL<string> zll2;
	ZLL<Crayon> zll3;

    int randInts[] = {5, 2, 3, 6, 7, 18, 25, 4};
    for(int i = 0; i < 8; i++)
    {
        zll1.front(randInts[i]);
    }
	zll1.back(1);
    zll1.back(65);

	zll2.back("bird");
    zll2.front("Three");
	zll2.back("Snape");

	zll3.back(one_crayon);
    zll3.front(two_crayon);
    zll3.front(three_crayon);

    return 0;
}
