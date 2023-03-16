#include <iostream>
#include <string>
#include <iomanip>
#include "ZLL.h"

using namespace std;

int main(){
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
    for(int i = 0; i < sizeof(randInts)/sizeof(int); i++)
    {
        worked = myzll.front(randInts[i]);
    }
    for(int i = 0; i < sizeof(randInts2)/sizeof(int); i++)
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

    myzll.printList();
    myzllBack.printList();
    myzllS.printList();
    myzllSback.printList();
    cout << endl;

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
        cout << myzll.getNext() << " ";
    }
    cout << endl << endl;
    cout << endl << myzll.getNext() << endl;

    return 0;
}
