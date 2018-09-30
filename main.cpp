#include "bc.h"
#include "fc.h"
#include <iostream>

using namespace std;

int main () {
    cout << "This recomender will help you choose a profession and an area..." << endl;

    BC backChainer(false);
    backChainer.inferenceSection();

    FC forwardChainer (backChainer.getProfession(), false);
    forwardChainer.start();

    cout << "Congratulation! Your future profession will be " << forwardChainer.getProfession();
    cout << " with a focus in " << forwardChainer.getArea() << endl;
    //cout << "Congratulations! Your future profession will be: " << backChainer.getProfession();

    return 0;
}
