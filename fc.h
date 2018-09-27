#include <string>

class FC
{

private:
    int flag;
    bool inst = false;
    static const int size = 11;
    static const int csize = 41;
    std::string cndvar[size], varlt[size],clvarlt[csize],c,v;
    int instlt[size];/* instantiated list*/
    std::string fedint,interest,stock,dollar,fedmon;
    int f, i, j, k, s, fp   /* front pointer */;
    int  bp  /* back pointer */,  sn; /* statement number */
    int cn;  /* clause number */

public:
    void initialize();
    void ifcondtions();
    void Result();
    void takingInput();
    void search();
    void check_instantiation();
    void instantiate();
    void inference();
    void gotoF();
    void start();
};
