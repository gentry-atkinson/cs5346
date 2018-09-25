#include "bc.h"
#include <cstdio>
#include <iostream>

using namespace std;

BC::BC()
{
	// Stack space is 10 we initially place stack space at 10+1
    sp = size;
	for (i=1; i < size; i++)
        {
            conclusionList[i] = "";
            variableList[i] = "";
            instantiatedList[i]=0;
            statementStack[i]=0;
            clausk[i]=0;
        }
    for (i=1; i < clauseSize + 1; i++)
        clauseVariableList[i] = "";

    // Initializing Conclusion List
    /*** comment 305 *****/
    //strcpy(conclt[1], "PO");
    conclusionList[1].assign("GOODGRADES");
    //strcpy(conclt[2], "QU");
    conclusionList[2].assign("GOODGRADES");
    //strcpy(conclt[3], "PO");
    conclusionList[3].assign("LABWORK");
    //strcpy(conclt[4], "PO");
    conclusionList[4].assign("LEADERSHIP");
    //strcpy(conclt[5], "PO");
    conclusionList[5].assign("PROFESSION");
    //strcpy(conclt[6], "PO");
    conclusionList[6].assign("PROFESSION");
    conclusionList[7].assign("PROFESSION");
    conclusionList[8].assign("WORKALONE");
    conclusionList[9].assign("PROFESSION");
    conclusionList[10].assign("PROFESSION");
    conclusionList[11].assign("OUTDOOR WORK");
    conclusionList[12].assign("PROFESSION");
    conclusionList[13].assign("PROFESSION");
    conclusionList[14].assign("PROFESSION");
    conclusionList[15].assign("MEDICALCERTIFICATE");
    conclusionList[16].assign("PROFESSION");
    conclusionList[17].assign("TEACHINGCERTIFICATE");
    conclusionList[18].assign("PROFESSION");
    conclusionList[19].assign("PROFESSION");
    conclusionList[20].assign("PROFESSION");
    //printf("*** CONCLUSION LIST ***\n");
    for (int i=1; i<21; i++) /*printf("CONCLUSION %d %s\n", i,conclt[i])*/
        cout << "Conclusion: " << i << " " << conclusionList[i] << endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

    cout << "Variable List:" << endl;
    /**** comment 367 *****/
    //strcpy(varlt[1], "DE");
    variableList[1].assign("DEGREE");
    //strcpy(varlt[2], "DI");
    variableList[2].assign("GOOD GRADES");
    //strcpy(varlt[3], "EX");
    variableList[3].assign("LAB WORK");
    //strcpy(varlt[4], "GR");
    variableList[4].assign("LEADERSHIP");
    variableList[5].assign("MED SCHOOL");
    variableList[6].assign("GROUP WORK");
    variableList[7].assign("WORK ALONE");
    variableList[8].assign("OUTDOOR WORK");
    variableList[9].assign("MEDICAL CERTIFICATE");
    variableList[10].assign("TEACHER CERTIFICATE");
    variableList[11].assign("GPA");
    variableList[12].assign("PROFESSION");
    variableList[13].assign("COURSES WITH LABS");
    variableList[14].assign("GROUP LEADER");
    variableList[15].assign("HOURS OUTSIDE");
    variableList[16].assign("MED FIELD");
    variableList[17].assign("CRIMINAL BACKGROUND");
    for(int i=1; i<18; i++) /*printf("VARIABLE %d %s\n", i, varlt[i])*/
        cout << "Variable: " << i << " " << variableList[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

    // Initializing Clause Variable List
    cout<<"****Clause variable list****"<<endl;
    /***** comment 407 through 409 ***/
    //strcpy(clvarlt[1], "DE");
    clauseVariableList[1].assign("GPA");
    //strcpy(clvarlt[5], "DE");
    clauseVariableList[5].assign("GPA");
    //strcpy(clvarlt[9], "DE");
    clauseVariableList[9].assign("COURSES WITH LABS");
    //strcpy(clvarlt[10], "DI");
    clauseVariableList[13].assign("GROUP LEADER");
    //strcpy(clvarlt[13], "QU");
    clauseVariableList[17].assign("DEGREE");
    clauseVariableList[18].assign("GOOD GRADES");
    //strcpy(clvarlt[14], "GR");
    clauseVariableList[21].assign("DEGREE");
    clauseVariableList[22].assign("GOOD GRADES");
    clauseVariableList[23].assign("LAB WORK");
    //strcpy(clvarlt[15], "EX");
    clauseVariableList[25].assign("DEGREE");
    clauseVariableList[26].assign("LEADERSHIP");
    //strcpy(clvarlt[17], "QU");
    clauseVariableList[29].assign("GROUP WORK");
    //strcpy(clvarlt[18], "GR");
    clauseVariableList[33].assign("DEGREE");
    clauseVariableList[34].assign("MED SCHOOL");
    clauseVariableList[35].assign("GROUP WORK");
    //strcpy(clvarlt[19], "EX");
    clauseVariableList[37].assign("DEGREE");
    clauseVariableList[38].assign("WORK ALONE");
    clauseVariableList[41].assign("HOURS OUTSODE");
    clauseVariableList[45].assign("DEGREE");
    clauseVariableList[46].assign("OUTDOOR WORK");
    clauseVariableList[49].assign("DEGREE");
    clauseVariableList[50].assign("GROUP WORK");
    clauseVariableList[53].assign("DEGREE");
    clauseVariableList[54].assign("OUTDOOR WORK");
    clauseVariableList[57].assign("MED SCHOOL");
    clauseVariableList[58].assign("MED FIELD");
    clauseVariableList[61].assign("DEGREE");
    clauseVariableList[62].assign("MEDICAL CERTIFICATE");
    clauseVariableList[63].assign("GROUP WORK");
    clauseVariableList[65].assign("CRIMINAL BACKGROUND");
    clauseVariableList[69].assign("DEGREE");
    clauseVariableList[70].assign("TEACHING CERTIFICATE");
    clauseVariableList[73].assign("DEGREE");
    clauseVariableList[74].assign("OUTDOOR WORK");
    clauseVariableList[77].assign("DEGREE");
    clauseVariableList[78].assign("GOOD GRADES");
    clauseVariableList[79].assign("GROUP WORK");

    //Printing Clause Variable List
     for(int i=1; i<21; i++)
    {
        // printf("** CLAUSE %d\n", i);
        cout<<"***CLAUSE*** "<<i << endl;
        for(int j=1; j<5; j++)
        {
            int k = 4 * (i-1) + j;

            //printf("VARIABLE %d  %s\n", j, clvarlt[k]); }
            cout<<" VARIABLE: "<< j << " " << clauseVariableList[k]<<endl;
        }


        if (i==20)
        {
            //printf("HIT RETURN KEY TO CONTINUE"); gets(buff); }
            cout<<"HIT THE RETURN KEY TO CONTINUE..."<<endl;
            getchar();
        }
    }
}

void BC::inferenceSection()
{
    cout<<"** ENTER CONCLUSION ? ";
    cin>>varble;
    /* get conclusion statement number (sn) from the conclusion list
    (conclt).First statement starts search */
    B520();
}

void BC::B520()
{
	f=1;
    determine_member_concl_list();
    if (sn != 0)
    {
        /* if sn = 0 then no conclusion of that name */
        KeepProcessing();
        if(sn != 0)
        {
        	InBetweenFunction();
        	popStack();
        }
        //thenPart();
    }
}

void BC::KeepProcessing()
{
   	do
    /* push statement number (sn) and clause number=1 on
    goal stack which is composed of the statement stack (statsk) and clause stack (clausk) */
    {
        push_on_stack();
        B545();
    }
    while((s != 1) && (sn !=0));
}

void BC::determine_member_concl_list()
{
    /* routine to determine if a variable (varble) is a member of the
       conclusion list (conclt).  if yes return sn != 0.
       if not a member sn=0;
    */
    /* initially set to not a member */
    sn = 0;
    /* member of conclusion list to be searched is f */
    i = f;
    while((varble!=conclusionList[i]) && (i<20))
        i=i+1; /* test for membership */
    if (varble == conclusionList[i])
    	sn = i;  /* a member */
}

void BC::push_on_stack()
{
    sp=sp-1;
    statementStack[sp] = sn;
    clausk[sp] = 1;
}

void BC::instantiate()
{
    i=1;
    /* find variable in the list */
    while (varble != variableList[i] && i<10)
    	i=i+1;
    if (varble == variableList[i] && instantiatedList[i] != 1)
    {
      	/*found variable and not already instantiated */
      	/*mark instantiated */
        instantiatedList[i]=1;
    	/* the designer of the knowledge base places the input statements to
        instantiate the variables below in the case statement */
        initkbase();
    }
}

void BC::initkbase()
{
	switch (i)
    {
        /* input statements for sample position knowledge base */
        case 1:
            cout<<"INPUT YES OR NOW FOR DE-? ";
            cin>>de;
            break;
        case 2:
            cout<<"INPUT YES OR NO FOR DI-? ";
            cin>>di;
            break;
        case 3:
            cout<<"INPUT A REAL NUMBER FOR EX-? ";
            cin>>ex;
            break;
        case 4:
            cout<<"INPUT A REAL NUMBER FOR GR-? ";
            cin>>gr;
            break;
    }
}

void BC::B545()
{
    do
    {
        /* calculate clause location in clause-variable list */
        //B545:
        i= (statementStack[sp] -1) *4 + clausk[sp];
        /* clause variable */
        varble = clauseVariableList[i];
        if(varble != "")
        {
            /*is this clause variable a conclusion? */
            f = 1;
            determine_member_concl_list();
            if(sn != 0)
                B520(); /* it is a conclusion push it */
            /* check instantiation of this clause */
            instantiate();
            clausk[sp] = clausk[sp] + 1;
        }
    }
    while(varble != "");
    sn = statementStack[sp];
    s = 0;

     switch (sn)
    {
        /* if part of statement 1 */
        /****** comment 1500 ****/
        case 1:
        	if(de == "NO")
        		s = 1;
            break;
        /* if part of statement 2 */
        /***** comment 1510 ******/
        case 2:
        	if(de == "YES")
        		s = 1;
            break;
        /* if part of statement 3 */
        case 3:
        	if(de == "YES" && di == "YES")
        		s =1;
            break;
        /* if part of statement 4 */
        /******** comment 1560 ******/
        case 4:
        	if(qu == "YES" && gr<3.5 && ex >= 2)
        		s = 1;
            break;
        /******** comment 1570 ********/
        /* if part of statement 5 */
        case 5:
        	if(qu == "YES" && gr<3 && ex<2)
        		s = 1;
            break;
        /* if part of statement 6 */
        case 6:
        	if(qu == "YES" && gr >=3.5)
        		s = 1;
        	break;
        /********* comment 1680 ******/
    }


    //ifkbase();
    if( s != 1)
    {
        /* failed..search rest of statements for same conclusion */
        /* get conclusion */
        i = statementStack[sp];
        varble = conclusionList[i];
        /* search for conclusion starting at the next statement number */
        f = statementStack[sp] + 1;
        determine_member_concl_list();
        sp = sp+1;
    }
}


void BC::InBetweenFunction()
{
    switch (sn)
    {
        /* then part of statement 1 */
        /******* comment 1500 *******/
        case 1:
            po = "NO";
            cout<<"PO=NO"<<endl;
        break;
        /* then part of statement 2 */
        /****** comment 1510 ******/
        case 2:
            qu = "YES";
            cout<<"QU=YES"<<endl;
       	break;
    	/* then part of statement 3 */
        case 3:
            po = "YES";
            cout<<"PO=RESEARCH"<<endl;
        break;
        /* then part of statement 4 */
        /******** comment 1560 ******/
        case 4:
            po = "YES";
            cout<<"PO=SERVICE ENGINEER"<<endl;
        break;
        /* then part of statement 5 */
        /****** comment 1570 *****/
        case 5:
            po = "NO";
            cout<<"PO=NO"<<endl;
        break;
        /* then part of statement 6 */
        case 6:
            po = "YES";
            cout<<"PO=PRODUCT ENGINEER"<<endl;
        break;
    	/****** comment 1680 ********/
    }
}

void BC::popStack()
{
    /* pop the stack */
    sp = sp+1;
    if(sp >= size)
   	{
   		// Finished
        cout<<"*** SUCCESS ***"<<endl;
       // exit(0);
    }
    else
    {
        /* stack is not empty */
        /* get next clause then continue */
        clausk[sp] = clausk[sp]+1;
        B545();
        if((s != 1) && (sn !=0))
        {
            KeepProcessing();
        }
        else if(sn != 0)
        {
            InBetweenFunction();
            popStack();
        }
    }
}
