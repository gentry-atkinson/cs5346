#include <string>

class FC
{

private:
    int flag;
    bool debug = true;
    bool inst = false;
    static const int size = 61;
    static const int clauseSize = 241;
    std::string conditionVariableQueue[size], variableList[size],clauseVariableList[clauseSize],c,v;
    int instantiatedList[size];/* instantiated list*/
    std::string fedint,interest,stock,dollar,fedmon;
    std::string likePhysics, likeMath, groupWork, likeBology;
    std::string likeChemistry, likeMarketing, likeManagement;
    std::string goodCredit, likeMedicalEthics, stateLicensure;
    std::string likeWriting, likeOriginality, likeMedia;
    std::string likeSocialScience, likeEnglish;
    std::string likeReading, likeClimate, likeStones;
    std::string likeLand, likeSoil, likeWaterResources;
    std::string likeAnalyticalSkills, likeInternship, likeAnatomy;
    std::string likeChildren, reliable, likeRepairs;
    std::string profession, area;
    int f, i, j, k, statementActive, frontPointer   /* front pointer */;
    int  backPointer  /* back pointer */,  statementNumber; /* statement number */
    int cn;  /* clause number */

public:
    FC(std::string);
    //void initialize();
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
