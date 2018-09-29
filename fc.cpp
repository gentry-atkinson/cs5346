#include <iostream>
#include<stdio.h>
#include<cstdlib>

#include "fc.h"

using namespace std;

void FC::start()
{
    initialize();
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



void FC::initialize()
{
    /******** INITIALIZATION SECTION ***********/
    for (i=1;i < clauseSize; i++)
        clauseVariableList[i] = "";
    for (i=1;i < size; i++)
    {
        conditionVariableQueue[i] = "";
        variableList[i] = "";
        instantiatedList[i] = 0;
    }
    /* enter variables which are in the IF part, 1 at a time in
     the exact order that they occur. Up to 3 variables per
     IF statement. Do not duplicate any variable names. Any
     name is used only once. If no more variables left, just
     hit return key */
    /****** comment 367 *************/

    variableList[1] = "IN";
    variableList[2] = "DO";
    variableList[3] = "FT";
    variableList[4] = "FM";

    cout<<"*** VARIABLE LIST ***"<<endl;
    for (i=1;i < size; i++)
        cout<<"VARIABLE "<<i<<" "<<variableList[i]<<endl;
    cout<<"HIT RETURN TO CONTINUE";
    getchar();

    /* enter variables as they appear in the IF clauses, Up to 3
     variables per IF statement. If no more variables left, just
     hit return key */
    /****** comment 407, 408 *************/
    clauseVariableList[1]  = "IN";
    clauseVariableList[5]  = "IN";
    clauseVariableList[9]  = "DO";
    clauseVariableList[13] = "DO";
    clauseVariableList[17] = "FT";
    clauseVariableList[18] = "FM";

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
