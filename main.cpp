#include "bc.h"
#include "fc.h"
#include <iostream>

using namespace std;

int main () {
    cout << "This recomender will help you choose a profession and an area..." << endl;

    //BC backChainer(false);
    //backChainer.inferenceSection();
    //cout << "Your recomended profession is: ";
    //backChainer.printProfession();

    FC f;
    f.start();

    return 0;
}
