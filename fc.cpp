#include <iostream>
#include<stdio.h>
#include<cstdlib>

#include "fc.h"

using namespace std;

void FC::start()
{
    inference();
    gotoF();
}


void FC::check_instantiation()
{
    int i=1;
    /* find variable in the variable list */
    while ((v != variableList[i]) && (i < size))
        i = i+1;
    /* check if already instantiated */
    if (instantiatedList[i] != 1)
    {
        /* mark instantiated */
        instantiatedList[i] = 1;
        /* the designer of this knowledge base places the input
         statements to instantiate the variables in this case
         statement */
        takingInput();
    }
}

void FC::instantiate()
{
    int i=1;
    /* find varialbe in the varialbe list (varlt) */
    while ((v != variableList[i]) && (i < size))
        i=i+1;

    /* instantiate it */
    instantiatedList[i] = 1;
    i = 1;

    /* determine if (v) is or already has been on the queue (cndvar) */
    while ((v != conditionVariableQueue[i]) && (i < size))
        i=i+1;
    /* variable has not been on the queue. Store it in the back of the queue */
    if (v != conditionVariableQueue[i])
    {
        conditionVariableQueue[backPointer] = v;
        backPointer=backPointer+1;
    }
}

void FC::inference()
{
    frontPointer=1;
    backPointer=1;
    /****** INFERENCE SECTION *****************/
    printf("ENTER CONDITION VARIABLE? ");
    cin>>c;
    /* place condition variable c on condition var queue cndvar */
    conditionVariableQueue[backPointer] = c;
    /* move backpointer (bp) to back */
    backPointer = backPointer + 1;
    /* set the condition variable pointer consisting of the
     statement number (sn) and the clause number (cn) */
    statementNumber = 1;
    cn = 1;
    /* find the next statement number containing the condition variable
     which is in front of the queue (cndvar), this statement number
     is located in the clause variable list (clvarlt) */
    /* start at the beginning */
    f=1;
}

void FC::gotoF()
{
    search();
    /* point to first clause in statement */
    cn=1;
    if (statementNumber != 0)/* more statements */
    {
        /* locate the clause */
        i = 4 * (statementNumber-1) + cn;
        /* clause variable */
        v = clauseVariableList[i];
        /* are there any more clauses for this statement */
        while (v != "")
        /* more clauses */
        {
            /* check instantiation of this clause */
            check_instantiation();
            cn = cn+1;
            /* check next clause */
            i = 4 * (statementNumber-1) + cn;
            v = clauseVariableList[i];
        }

        /* no more clauses - check IF part of statement */
        statementActive = 0;

        ifcondtions();

        /* see if the THEN part should be inovked, i.e., s=1 */
        if (statementActive != 1)
        {
            f = statementNumber + 1;
            gotoF();
        }

        Result();
        if(inst)
        {
            instantiate();
            inst = false;
        }
        f = statementNumber + 1;
        gotoF();
    }

    /* no more clauses in the clause variable list (clvarlt)
     containing the variable in front of the queue (cndvar(fp))
     then remove front variable (cndvar(fp)) and replace it by
     the next variable (cndvar(fp+1)). If no more variables are
     at the front of the queue, stop. */
    /* next queue variable */
    frontPointer=frontPointer+1;
    if (frontPointer < backPointer)
    {
        /* check out the condition variable */
        f = 1;
        gotoF();
    }
    /* no more conclusion variables on queue */
    cout<<"*** Success ***";
    exit(1);
}

void FC::search()
{
    flag = 0;
    statementNumber = f;
    while ((flag == 0) && (statementNumber <= (clauseSize-1)/4))
    {
        cn=1;
        k = (statementNumber-1)*4+cn;
        while ((clauseVariableList[k] != conditionVariableQueue[frontPointer]) && (cn < 4))
        {
            cn = cn+1;
            k = (statementNumber-1)*4+cn;
        }

        if (clauseVariableList[k] == conditionVariableQueue[frontPointer])
            flag = 1;
        if (flag == 0)
            statementNumber = statementNumber+1;
    }
    if (flag == 0)
        statementNumber=0;
}



FC::FC(string profession)
{
    /******** INITIALIZATION SECTION ***********/
    for (i=1;i < clauseSize; i++)
        //clauseVariableList[i] = "";
        clauseVariableList[i].assign("");
    for (i=1;i < size; i++)
    {
        //conditionVariableQueue[i] = "";
        conditionVariableQueue[i].assign("");
        //variableList[i] = "";
        variableList[i].assign("");
        instantiatedList[i] = 0;
    }
    /* enter variables which are in the IF part, 1 at a time in
     the exact order that they occur. Up to 3 variables per
     IF statement. Do not duplicate any variable names. Any
     name is used only once. If no more variables left, just
     hit return key */
    /****** comment 367 *************/

    //variableList[1] = "IN";
    //variableList[2] = "DO";
    //variableList[3] = "FT";
    //variableList[4] = "FM";

    variableList[1].assign("LIKEPHYSICS");
    variableList[2].assign("LIKEMATH");
    variableList[3].assign("GROUPWORK");
    variableList[4].assign("LIKEBIOLOGY");
    variableList[5].assign("LIKECHEMISTRY");
    variableList[6].assign("LIKEMARKETING");
    variableList[7].assign("LIKEMANAGEMENT");
    variableList[8].assign("GOODCREDIT");
    variableList[9].assign("LIKEMEDICALETHICS");
    variableList[10].assign("STATELICENSURE");
    variableList[11].assign("LIKEWRITING");
    variableList[12].assign("LIKEORIGINALITY");
    variableList[13].assign("LIKEMEDIA");
    variableList[14].assign("LIKESOCIALSCIENCE");
    variableList[15].assign("LIKEENGLISH");
    variableList[16].assign("LIKEREADING");
    variableList[17].assign("LIKECLIMATE");
    variableList[18].assign("LIKESTONES");
    variableList[19].assign("LIKELAND");
    variableList[20].assign("LIKESOIL");
    variableList[21].assign("LIKEWATERRESOURCES");
    variableList[22].assign("LIKEANALYTICALSKILLS");
    variableList[23].assign("LIKEINTERNSHIPS");
    variableList[24].assign("LIKEANATOMY");
    variableList[25].assign("LIKECHILDREN");
    variableList[26].assign("RELIABLE");
    variableList[27].assign("LIKEREPAIRS");
    variableList[28].assign("PROFESSION");
    variableList[29].assign("AREA");

    cout<<"*** VARIABLE LIST ***"<<endl;
    for (i=1;i < size; i++) {
        if (variableList[i].compare("") == 0) break;
        cout<<"VARIABLE "<<i<<" "<<variableList[i]<<endl;
    }
    cout<<"HIT RETURN TO CONTINUE";
    getchar();

    /* enter variables as they appear in the IF clauses, Up to 3
     variables per IF statement. If no more variables left, just
     hit return key */
    /****** comment 407, 408 *************/
    //clauseVariableList[1]  = "IN";
    //clauseVariableList[5]  = "IN";
    //clauseVariableList[9]  = "DO";
    //clauseVariableList[13] = "DO";
    //clauseVariableList[17] = "FT";
    //clauseVariableList[18] = "FM";

    clauseVariableList[1].assign("PROFESSION");
    clauseVariableList[2].assign("LIKEMATH");
    clauseVariableList[3].assign("LIKEPHYSICS");
    clauseVariableList[5].assign("PROFESSION");
    clauseVariableList[6].assign("LIKEPHYSICS");
    clauseVariableList[7].assign("GROUPWORK");
    clauseVariableList[9].assign("PROFESSION");
    clauseVariableList[10].assign("LIKELAW");
    clauseVariableList[11].assign("LIKEPHYSICS");
    clauseVariableList[13].assign("PROFESSION");
    clauseVariableList[14].assign("LIKEMATH");
    clauseVariableList[15].assign("LIKEBIOLOGY");
    clauseVariableList[17].assign("PROFESSION");
    clauseVariableList[18].assign("LIKECHEMISTRY");
    clauseVariableList[19].assign("GROUPWORK");
    clauseVariableList[21].assign("PROFESSION");
    clauseVariableList[22].assign("LIKEBIOLOGY");
    clauseVariableList[23].assign("LIKECHEMISTRY");
    clauseVariableList[25].assign("PROFESSION");
    clauseVariableList[26].assign("LIKEBIOLOGY");
    clauseVariableList[27].assign("GROUPWORK");
    clauseVariableList[29].assign("PROFESSION");
    clauseVariableList[30].assign("LIKEMATH");
    clauseVariableList[33].assign("PROFESSION");
    clauseVariableList[34].assign("LIKEPHYSICS");
    clauseVariableList[37].assign("PROFESSION");
    clauseVariableList[38].assign("LIKEBIOLOGY");
    clauseVariableList[39].assign("LIKEPHYSICS");
    clauseVariableList[41].assign("PROFESSION");
    clauseVariableList[42].assign("GOODCREDIT");
    clauseVariableList[45].assign("PROFESSION");
    clauseVariableList[46].assign("LIKEMARKETING");
    clauseVariableList[47].assign("LIKEMANAGEMENT");
    clauseVariableList[49].assign("PROFESSION");
    clauseVariableList[50].assign("LIKEMATH");
    clauseVariableList[53].assign("PROFESSION");
    clauseVariableList[54].assign("GROUPWORK");
    clauseVariableList[57].assign("PROFESSION");
    clauseVariableList[58].assign("GOODCREDIT");
    clauseVariableList[59].assign("LIKEMANAGEMENT");
    clauseVariableList[61].assign("PROFESSION");
    clauseVariableList[62].assign("GROUPWORK");
    clauseVariableList[65].assign("PROFESSION");
    clauseVariableList[66].assign("LIKECHEMISTRY");
    clauseVariableList[69].assign("PROFESSION");
    clauseVariableList[70].assign("STATELICENSURE");
    clauseVariableList[71].assign("LIKECHEMISTRY");
    clauseVariableList[73].assign("PROFESSION");
    clauseVariableList[74].assign("LIKEMEDICALETHICS");
    clauseVariableList[77].assign("PROFESSION");
    clauseVariableList[78].assign("LIKEBIOLOGY");
    clauseVariableList[79].assign("LIKECHEMISTRY");
    clauseVariableList[81].assign("PROFESSION");
    clauseVariableList[82].assign("LIKEWRITING");
    clauseVariableList[83].assign("LIKEORIGINALITY");
    clauseVariableList[85].assign("PROFESSION");
    clauseVariableList[86].assign("LIKEMEDIA");
    clauseVariableList[87].assign("LIKESOCIALSCIENCE");
    clauseVariableList[89].assign("PROFESSION");
    clauseVariableList[90].assign("LIKEENGLISH");
    clauseVariableList[91].assign("LIKEREADING");
    clauseVariableList[93].assign("PROFESSION");
    clauseVariableList[94].assign("LIKEMARKETING");
    clauseVariableList[95].assign("LIKEENGLISH");
    clauseVariableList[97].assign("PROFESSION");
    clauseVariableList[98].assign("LIKEREADING");
    clauseVariableList[99].assign("LIKEORIGINALITY");
    clauseVariableList[101].assign("PROFESSION");
    clauseVariableList[102].assign("LIKECLIMATE");
    clauseVariableList[103].assign("LIKESTONES");
    clauseVariableList[105].assign("PROFESSION");
    clauseVariableList[106].assign("LIKELAND");
    clauseVariableList[107].assign("LIKEORIGINALITY");
    clauseVariableList[109].assign("PROFESSION");
    clauseVariableList[110].assign("LIKESOIL");
    clauseVariableList[111].assign("LIKECLIMATE");
    clauseVariableList[113].assign("PROFESSION");
    clauseVariableList[114].assign("LIKEWATERESOURCES");
    clauseVariableList[115].assign("LIKESOIL");
    clauseVariableList[117].assign("PROFESSION");
    clauseVariableList[118].assign("LIKEMATH");
    clauseVariableList[121].assign("PROFESSION");
    clauseVariableList[122].assign("LIKESOCIALSCIENCE");
    clauseVariableList[125].assign("PROFESSION");
    clauseVariableList[126].assign("GROUPWORK");
    clauseVariableList[127].assign("LIKEANALYTICALSKILLS");
    clauseVariableList[129].assign("PROFESSION");
    clauseVariableList[130].assign("LIKEINTERNSHIPS");
    clauseVariableList[133].assign("PROFESSION");
    clauseVariableList[134].assign("GROUPWORK");
    clauseVariableList[135].assign("LIKESOCIALSCIENCE");
    clauseVariableList[137].assign("PROFESSION");
    clauseVariableList[138].assign("LIKECOMMUNICATION");
    clauseVariableList[139].assign("LIKEANALYTICALSKILLS");
    clauseVariableList[141].assign("PROFESSION");
    clauseVariableList[142].assign("GOODCREDIT");
    clauseVariableList[143].assign("LIKEMANAGEMENT");
    clauseVariableList[145].assign("PROFESSION");
    clauseVariableList[146].assign("GROUPWORK");
    clauseVariableList[147].assign("LIKEMANAGEMENT");
    clauseVariableList[149].assign("PROFESSION");
    clauseVariableList[150].assign("LIKEMANAGEMENT");
    clauseVariableList[151].assign("LIKEMARKETING");
    clauseVariableList[153].assign("PROFESSION");
    clauseVariableList[154].assign("LIKECHEMISTRY");
    clauseVariableList[157].assign("PROFESSION");
    clauseVariableList[158].assign("LIKEWATERRESOURCES");
    clauseVariableList[161].assign("PROFESSION");
    clauseVariableList[162].assign("LIKECOMMUNICATION");
    clauseVariableList[165].assign("PROFESSION");
    clauseVariableList[166].assign("LIKEMANAGEMENT");
    clauseVariableList[169].assign("PROFESSION");
    clauseVariableList[170].assign("LIKEIOLOGY");
    clauseVariableList[173].assign("PROFESSION");
    clauseVariableList[174].assign("LIKEMANAGEMENT");
    clauseVariableList[175].assign("GROUPWORK");
    clauseVariableList[177].assign("PROFESSION");
    clauseVariableList[178].assign("LIKEANATOMY");
    clauseVariableList[179].assign("LIKECHEMISTRY");
    clauseVariableList[181].assign("PROFESSION");
    clauseVariableList[182].assign("LIKECHILDREN");
    clauseVariableList[185].assign("PROFESSION");
    clauseVariableList[186].assign("LIKEREADING");
    clauseVariableList[187].assign("LIKECOMMUNICATION");
    clauseVariableList[189].assign("PROFESSION");
    clauseVariableList[190].assign("LIKEMATH");
    clauseVariableList[191].assign("LIKECHEMISTRY");
    clauseVariableList[193].assign("PROFESSION");
    clauseVariableList[194].assign("LIKECOMMUNICATION");

    printf("*** CLAUSE-VARIABLE LIST ***\n");
    for (i = 1; i < (clauseSize-1)/4 ; i++)
    {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 5; j++)
        {
            k = 4 * (i - 1) + j;
            cout<<"VARIABLE "<<j<< " "<<clauseVariableList[k]<<endl;
        }

        if (i==4)
        {
            cout<<"HIT RETURN TO CONTINUE";
            getchar();
        }
    }
    this->profession.assign(profession);
}

void FC::ifcondtions()
{
    /* sample IF-THEN statements from the position knowledge base */
    switch(statementNumber)
    {
            /* statement 1 */
            /***** comment 1500 *****/
        case 1:
            if (interest == "FALL")
                statementActive=1;
            break;
            /* statement 2 */
            /***** comment 1510 *****/
        case 2:
            if (interest == "RISE")
                statementActive=1;
            break;
            /* statement 3 */
            /***** comment 1540 *****/
        case 3:
            if (dollar == "FALL")
                statementActive=1;
            break;
            /* statement 4 */
            /***** comment 1550 *****/
        case 4:
            if (dollar == "RISE")
                statementActive=1;
            break;
            /* statement 5 */
        case 5:
            if ((fedint == "FALL") && (fedmon == "ADD"))
                statementActive=1;
            break;
            /***** comment 1610 *****/
    }
}

void FC::Result()
{
    /* invoke THEN part */
    switch (statementNumber)
    {
            /*********** comment 1500 ***********/
            /* put variable on the conclusion variable queue */
        case 1:
            stock = "RISE";
            cout<<"ST=RISE"<<endl;
            v = "ST";
            inst = true;
            break;
            /*********** comment 1510 ***********/
            /* put variable on the conclusion variable queue */
        case 2:
            stock = "FALL";
            cout<<"ST=FALL"<<endl;
            v = "ST";
            inst = true;
            break;
            /*********** comment 1540 ***********/
            /* put variable on the conclusion variable queue */
        case 3:
            interest = "RISE";
            cout<<"IN=RISE"<<endl;
            v = "IN";
            inst = true;
            break;
            /*********** comment 1550 ***********/
            /* put variable on the conclusion variable queue */
        case 4:
            interest = "FALL";
            cout<<"IN=FALL"<<endl;
            v = "IN";
            inst = true;
            break;
            /* put variable on the conclusion variable queue */
        case 5:
            interest = "FALL";
            cout<<"IN=FALL"<<endl;
            v = "IN";
            inst = true;
            break;
            /*********** comment 1610 ***********/
    }
}

void FC::takingInput()
{
    switch (i)
    {
            /* input statements for sample position knowledge base */
        case 1:
            cout<<"RISE OR FALL FOR IN? ";
            cin>>interest;
            break;
        case 2:
            cout<<"RISE OR FALL FOR DO? ";
            cin>>dollar;
            break;
        case 3:
            cout<<"RISE OR FALL FOR FT? ";
            cin>>fedint;
            break;
        case 4:
            cout<<"ADD OR SUBTRACT FOR FM? ";
            cin>>fedmon;
            break;
    }
}
