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

    FC forwardChainer("engineering");
    forwardChainer.start();

    cout << "*************************************" << endl;
    //cout << "Congratulations! Your future profession will be: " << backChainer.getProfession();

    return 0;
}
