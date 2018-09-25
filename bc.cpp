#include "bc.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

BC::BC(bool debug)
{
	// Stack space is 10 we initially place stack space at 10+1
    stackPointer = size;
	for (int i=1; i < size; i++)
        {
            conclusionList[i] = "";
            variableList[i] = "";
            instantiatedList[i]=0;
            statementStack[i]=0;
            clauseStack[i]=0;
        }
    for (int i=1; i < clauseSize + 1; i++)
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

    cout<<"HIT RETURN TO CONTINUE"<<endl;

    getchar();

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

    cout<<"HIT RETURN TO CONTINUE"<<endl;

    getchar();

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
            cout<<endl;
            getchar();
        }
    }
}

void BC::inferenceSection()
{
    //cout<<"** ENTER CONCLUSION ? ";
    //cin>>varble;
    varble.assign("PROFESSION");
    cout << "Conclusion is set to: " << varble << endl;
    /* get conclusion statement number (sn) from the conclusion list
    (conclt).First statement starts search */
    B520();
}

void BC::B520()
{
	f=1;
    determine_member_concl_list();
    if (statementNumber != 0)
    {
        /* if sn = 0 then no conclusion of that name */
        KeepProcessing();
        if(statementNumber != 0)
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
    while((statementActive != 1) && (statementNumber !=0));
}

void BC::determine_member_concl_list()
{
    /* routine to determine if a variable (varble) is a member of the
       conclusion list (conclt).  if yes return sn != 0.
       if not a member sn=0;
    */
    /* initially set to not a member */
    statementNumber = 0;
    /* member of conclusion list to be searched is f */
    int i = f;
    while((varble!=conclusionList[i]) && (i<20))
        i=i+1; /* test for membership */
    if (varble == conclusionList[i])
    	statementNumber = i;  /* a member */
}

void BC::push_on_stack()
{
    stackPointer=stackPointer-1;
    statementStack[stackPointer] = statementNumber;
    clauseStack[stackPointer] = 1;
}

void BC::instantiate()
{
    int i=1;
    /* find variable in the list */
    while ((strcmp(varble.c_str(), variableList[i].c_str()) != 0) && i<18)
    	i=i+1;
    //if (varble == variableList[i] && instantiatedList[i] != 1)
    if ((strcmp(varble.c_str(), variableList[i].c_str()) == 0) && instantiatedList[i] != 1)
    {
      	/*found variable and not already instantiated */
      	/*mark instantiated */
        instantiatedList[i]=1;
    	/* the designer of the knowledge base places the input statements to
        instantiate the variables below in the case statement */
        initkbase(i);
    }
}

void BC::initkbase(int i)
{
	switch (i)
        {
                /***** input statement *****/
                /* input statements for sample position knowledge
                 base */
                /***** comment 1700 ******/
                //case 1: printf("INPUT YES OR NO FOR DE-? ");
                //        gets(de);
            case 1: cout << "What degree are you working towards?";
                cin >> degree;
                cout << endl;
                break;
                //case 2: printf("INPUT YES OR NO FOR DI-? ");
                //        gets(di);
            case 2: cout << "What GPA do you maintain?";
                cin >> grade;
                if (grade > 3.5)
                    goodGrades.assign("true");
                else
                    goodGrades.assign("false");
                break;
                //case 3: printf("INPUT A REAL NUMBER FOR EX-? ");
                //        scanf("%f", &ex);
            case 3: cout << "How many courses will you take that include a lab section?";
                cin >> coursesWithLabs;
                break;
            case 4:// printf("INPUT A REAL NUMBER FOR GR-? ");
                // scanf("%f", &gr);
                cout << "How many group projects have you been the leader off?";
                cin >> groupLeader;
                if (groupLeader >= 1) leadership.assign("true");
                else leadership.assign("false");
                break;
            case 5: cout << "Will you go to med school after college? ";
                cin >> buff;
                if (buff.compare("yes") == 0 || buff.compare("y") == 0)
                    medSchool.assign("true");
                else medSchool.assign("false");
                break;
                /***** comment 1715 ****/
            case 6: cout << "Do you like working in groups? ";
                cin >> buff;
                if (buff.compare("yes") == 0 || buff.compare("y") == 0)
                    groupWork.assign("true");
                else groupWork.assign("false");
                break;
            case 7: cout << "Do you like working in groups? ";
                cin >> buff;
                if (buff.compare("yes") == 0 || buff.compare("y") == 0)
                    workAlone.assign("false");
                else workAlone.assign("true");
                break;
            case 8: cout << "How many hours do you spend outside every week? ";
                cin >> hoursOutside;
                if (hoursOutside > 15)
                    outdoorWork.assign("true");
                else
                    outdoorWork.assign("false");
                break;
            case 9: cout << "Will you get a medical certification? ";
                cin >> buff;
                if (buff.compare("yes") == 0 || buff.compare("y") == 0)
                    medCert.assign("true");
                else medCert.assign("false");
                break;

            case 10: cout<< "Will you get a Teaching certification? ";
                cin>>buff;
                if(buff.compare("yes")==0||buff.compare("y")==0)
                    teachCert.assign("true");
                else
                    teachCert.assign("false");
                break;

            case 11: cout<<"What is your GPA?";
                cin >> grade;
                if (debug) cout << "Grade is " << grade << endl;
                break;

            case 12 : cout<< "What do you want to do?";
                cin>>profession;
                break;

            case 13: cout << "How many courses will you take that include a lab section?";
                cin >> coursesWithLabs;
                break;

            case 14: cout<< "How many projects have you been a group leader for?";
                cin>>groupLeader;
                break;

            case 15: cout<<"How many hours are you outside per week? " ;
                cin>>hoursOutside;
                break;

            case 16: cout<<"Are you interested to study regarding the health care?";
                cin>>buff;
                if(buff.compare("yes")==0||buff.compare("y")==0)
                    medField.assign("true");
                else
                    medField.assign("false");
                break;

            case 17 : cout<<"Do you have a criminal background?";
                cin>>buff;
                if(buff.compare("yes")==0||buff.compare("y")==0)
                    criminal.assign("true");
                else
                    criminal.assign("false");
                break;

            default: cout<<"********************";
                break;



        } //end of switch
}

void BC::B545()
{
    int i;
    do
    {
        /* calculate clause location in clause-variable list */
        //B545:
        i= (statementStack[stackPointer] -1) *4 + clauseStack[stackPointer];
        /* clause variable */
        varble = clauseVariableList[i];
        if(varble != "")
        {
            /*is this clause variable a conclusion? */
            f = 1;
            determine_member_concl_list();
            if(statementNumber != 0)
                B520(); /* it is a conclusion push it */
            /* check instantiation of this clause */
            instantiate();
            clauseStack[stackPointer] = clauseStack[stackPointer] + 1;
        }
    }
    while(varble != "");
    statementNumber = statementStack[stackPointer];
    statementActive = 0;

     switch (statementNumber) { //Left hand side of Rules
            /* if part of statement 1 */
            /****** comment 1500 ****/
        case 1: //if(strcmp(degree.c_str(), "NO") == 0) s = 1;
            if (grade >= 3.5) statementActive = 1;
            break;
            /* if part of statement 2 */
            /***** comment 1510 ******/
        case 2: //if(strcmp(degree.c_str(), "YES") == 0) s = 1;
            if (grade < 3.5) statementActive = 1;
            break;
            /* if part of statement 3 */
        case 3: //if((strcmp(degree.c_str(), "YES") == 0) &&
                //   (strcmp(labwork.c_str(), "YES") == 0)) s =1;
            if (coursesWithLabs > 2) statementActive = 1;
            break;
            /* if part of statement 4 */
            /******** comment 1560 ******/
        case 4: //if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                //   (grade<3.5) && (grade >= 2)) s = 1;
            if (groupLeader >= 1) statementActive = 1;
            break;
            /******** comment 1570 ********/
            /* if part of statement 5 */
        case 5: //if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                //   (grade<3) && (grade<2)) s = 1;
            if (strcmp(degree.c_str(), "engineering\0") == 0 && strcmp(goodGrades.c_str(), "true\0") == 0) statementActive = 1;
            break;
            /* if part of statement 6 */
        case 6: //if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                //   (grade >=3.5)) s = 1;
            if (strcmp(degree.c_str(), "science") == 0 && strcmp(goodGrades.c_str(), "true") && strcmp(labwork.c_str(), "true")) statementActive = 1;
            break;
        case 7: if(strcmp(degree.c_str(), "none") != 0 && strcmp(leadership.c_str(), "true")) statementActive = 1;
            break;
        case 8: if (strcmp(groupWork.c_str(), "false") == 0) statementActive = 1;
            break;
        case 9: if (strcmp(degree.c_str(), "none") != 0 && strcmp(medSchool.c_str(), "true") == 0 && strcmp(groupWork.c_str(), "true") == 0) statementActive = 1;
            break;
        case 10: if (strcmp(degree.c_str(), "english") == 0 && strcmp(workAlone.c_str(), "true")) statementActive = 1;
            break;
        case 11: if (hoursOutside >= 16) statementActive = 1;
            break;
        case 12: if (strcmp(degree.c_str(), "science") == 0 && strcmp(outdoorWork.c_str(), "true") == 0) statementActive = 1;
            break;
        case 13: if (strcmp(degree.c_str(), "psychology") == 0 && strcmp(groupWork.c_str(), "true") == 0) statementActive = 1;
            break;
        case 14: if (strcmp(degree.c_str(), "none") == 0 && strcmp(outdoorWork.c_str(), "true") == 0) statementActive = 1;
            break;
        case 15: if (strcmp(medSchool.c_str(), "false") == 0 && strcmp(medField.c_str(), "true") == 0) statementActive = 1;
            break;
        case 16: if (strcmp(degree.c_str(), "none") != 0 && strcmp(medCert.c_str(), "true") == 0 && strcmp(groupWork.c_str(), "true") == 0) statementActive = 1;
            break;
        case 17: if (strcmp(criminal.c_str(), "true") == 0) statementActive = 1;
            break;
        case 18: if (strcmp(degree.c_str(), "none") != 0 && strcmp(teachCert.c_str(), "true") == 0) statementActive = 1;
            break;
        case 19: if (strcmp(degree.c_str(), "none") == 0 && strcmp(outdoorWork.c_str(), "false") == 0) statementActive = 1;
            break;
        case 20: if (strcmp(degree.c_str(), "cs") == 0 && strcmp(goodGrades.c_str(), "true") == 0 && strcmp(groupWork.c_str(), "true")) statementActive = 1;
            break;
        default : cout << "Unusable statement number." << endl;
            /********* comment 1680 ******/
    } //end of switch


    //ifkbase();
    if( statementActive != 1)
    {
        /* failed..search rest of statements for same conclusion */
        /* get conclusion */
        i = statementStack[stackPointer];
        varble = conclusionList[i];
        /* search for conclusion starting at the next statement number */
        f = statementStack[stackPointer] + 1;
        determine_member_concl_list();
        stackPointer = stackPointer+1;
    }
}


void BC::InBetweenFunction()
{
    switch (statementNumber)
        {
                /* then part of statement 1 */
                /******* comment 1500 *******/
            case 1: //strcpy(po, "NO");
                //printf("PO=NO\n");
                goodGrades.assign("true");
                cout<<"Good Grades = YES" << endl;
                break;
                /* then part of statement 2 */
                /****** comment 1510 ******/
            case 2: //strcpy(qu, "YES");
                //printf("QU=YES\n");
                goodGrades.assign("false");
                cout<<"Good Grades = NO" << endl;
                break;

                /* then part of statement 3 */
            case 3: labwork.assign("true");
                cout<<"LAB WORK = YES" << endl;
                break;
                /* then part of statement 4 */
                /******** comment 1560 ******/
            case 4: leadership.assign("true");
                cout<<"leadership = YES" << endl;
                break;
                /* then part of statement 5 */
                /****** comment 1570 *****/
            case 5: profession.assign("Engineering");
                cout<<"Profession = Engineering" << endl;
                break;
                /* then part of statement 6 */
            case 6: profession.assign("Science");
                cout<<"Profession = Science" << endl;
                break;
            case 7: profession.assign("Business");
                cout<<"Profession = Business";
                break;

            case 8: workAlone.assign("true");
                cout<<"workAlone = YES" << endl;
                break;


            case 9: profession.assign("Medical");
                cout<<"Profession = Medical" << endl;
                break;

            case 10 : profession.assign("English");
                cout<<"Profession = English" << endl;
                break;

            case 11: outdoorWork.assign("true");
                cout<<"outdoorWork = YES" << endl;
                break;

            case 12 : profession.assign("geography");
                cout<<"Profession = geography";
                break;

            case 13 : profession.assign("psychology");
                cout<<"Profession = psychology" << endl;
                break;

            case 14 : profession.assign("agriculture");
                cout<<"Profession = agriculture" << endl;
                break;

            case 15: medCert.assign("true");
                cout<<"medCert = YES" << endl;
                break;

            case 16 : profession.assign("Health care");
                cout<<"Profession = Health" << endl;
                break;

            case 17: teachCert.assign("true");
                cout<<"Teaching certification = YES" << endl;
                break;

            case 18: profession.assign("education");
                cout<<"Profession = education" << endl;
                break;

            case 19: profession.assign("property management");
                cout<<"Profession = prop management" << endl;
                break;

            case 20: profession.assign("Computer science");
                cout<<"Profession = CS" << endl;
                break;
                /****** comment 1680 ********/
        }
}

void BC::popStack()
{
    /* pop the stack */
    stackPointer = stackPointer+1;
    if(stackPointer >= size)
   	{
   		// Finished
        cout<<"*** SUCCESS ***"<<endl;
        exit(0);
    }
    else
    {
        /* stack is not empty */
        /* get next clause then continue */
        clauseStack[stackPointer] = clauseStack[stackPointer]+1;
        B545();
        if((statementActive != 1) && (statementNumber !=0))
        {
            KeepProcessing();
        }
        else if(statementNumber != 0)
        {
            InBetweenFunction();
            popStack();
        }
    }
}
