#include <string>

class FC
{

private:
    int flag;
    bool debug = true;
    bool inst = false;
    static const int size = 61;
    static const int clauseSize = 240;
    std::string conditionVariableQueue[size], variableList[size],clauseVariableList[clauseSize],c,v;
    int instantiatedList[size];/* instantiated list*/
    std::string fedint,interest,stock,dollar,fedmon;
    int f, i, j, k, statementActive, frontPointer   /* front pointer */;
    int  backPointer  /* back pointer */,  statementNumber; /* statement number */
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
