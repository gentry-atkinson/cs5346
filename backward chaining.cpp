/*Enclosed a program, which comprises the inference engine based on backward chaining.  You need it for your
project #1.  The program contains some errors and it is not designed to be efficient.
Modify the program to make it better and efficient.  Explain in your report how you have modified the
program to make it better.*/

//TO DO:
//1- Remove globals
    //1a- change variable list
//2- Remove gotos
//3- Use cpp libraries rather than c
    //3a- change printf to cout
    //3b- use string instead of char[]
    //3c- use string.compare instead of strcmp
    //3d- use cin instead of gets
//4- re-write question to make sense





/*****backward chaining *******/
/* Install your IF clauses in sequence in the first case
   statement of the main program
   example: if((a1==2) && (a2==6)) s=1;
                      if(strcmp(j,NO") != 0) s=1;
   the then part of the above construction always
   contains s=1;
   install your the clauses in sequence in the second
   case statement of the main program
   example strcpy(po,"YES");*/

   #include<string>
   #include<cstdio>
   #include<cstring>
   #include<iostream>

   using namespace std;


/*  conclusion list */
string conclusionList[21];
/*  variable list */
string variableList[18];
/*  clause vairable list */
string clauseVariableList[69];
string variable;
string /* qualify */ goodGrades, /* degree*/ degree;
string /* discovery */ labwork, /* position */ profession;
string outdoorWork, leadership, groupWork;
int coursesWithLabs;
char buff[128];

/* instantiated list */
int instantiatedList[18];
/* statement stack */
int statementStack[11];
int /* clause stack */ clauseStack[11], sn, f, s, /*stack pointer */ stackPointer;

float /* grade */ grade, /*experience */ ex;

void determine_member_concl_list(void);
void push_on_stack(void);
void instantiate(void);


int main()
{
        /***** initialization section ******/
        /* stack space is 10 we initially place stack space at 10+1 */
        stackPointer=11;
        for (int i=0; i<11; i++)
        {
                //strcpy(conclt[i],"");
                //strcpy(varlt[i],"");
                instantiatedList[i]=0;
                statementStack[i]=0;
                clauseStack[i]=0;
        }

        for (int i = 0; i < 21; i++)
            conclusionList[i].assign(" ");
        for (int i = 0; i < 18; i++)
            variableList[i].assign(" ");
        for (int i=0; i<69; i++)
            clauseVariableList[i].assign(" ");
        /* enter conclusions which are the variables in the then part,
1 at
        a time.  enter the conclusions in exact order starting at the 1st
        if-then.  after last conclusion hit return key for rest of
        conclusions */

        /*** comment 305 *****/
        //strcpy(conclt[1], "PO");
        conclusionList[1].assign("GOOD GRADES");
        //strcpy(conclt[2], "QU");
        conclusionList[2].assign("GOOD GRADES");
        //strcpy(conclt[3], "PO");
        conclusionList[3].assign("LAB WORK");
        //strcpy(conclt[4], "PO");
        conclusionList[4].assign("LEADERSHIP");
        //strcpy(conclt[5], "PO");
        conclusionList[5].assign("PROFESSION");
        //strcpy(conclt[6], "PO");
        conclusionList[6].assign("PROFESSION");
        conclusionList[7].assign("PROFESSION");
        conclusionList[8].assign("WORK ALONE");
        conclusionList[9].assign("PROFESSION");
        conclusionList[10].assign("PROFESSION");
        conclusionList[11].assign("OUTDOOR WORK");
        conclusionList[12].assign("PROFESSION");
        conclusionList[13].assign("PROFESSION");
        conclusionList[14].assign("PROFESSION");
        conclusionList[15].assign("MEDICAL CERTIFICATE");
        conclusionList[16].assign("PROFESSION");
        conclusionList[17].assign("TEACHING CERTIFICATE");
        conclusionList[18].assign("PROFESSION");
        conclusionList[19].assign("PROFESSION");
        conclusionList[20].assign("PROFESSION");
        //printf("*** CONCLUSION LIST ***\n");
        for (int i=1; i<21; i++) /*printf("CONCLUSION %d %s\n", i,conclt[i])*/ cout << "Conclusion: " << i << conclusionList[i] << endl;

        //printf("HIT RETURN TO CONTINUE");
        cout << "Hit Return to continue..." << endl;
        //gets(buff);
        getchar();
        /* enter variables which are in the if part, 1 at a time in the
exact
        order that they occur, up to 3 variables per if statement.  do not
        duplicate any variable names.  any name is used only once.  if no
        more variables left just hit return key. */
        //printf("*** VARIABLE LIST *\n");
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
        for(int i=1; i<18; i++) /*printf("VARIABLE %d %s\n", i, varlt[i])*/ cout << "Variable: " << i << " " << variableList[i]<<endl;
        //printf("HIT RETURN KEY TO CONTINUE");
        cout << "Hit Return to continue..."<<endl;
        //gets(buff);
        getchar();
        /* enter variables as they appear in the if clauses.  a maximum
of 3
        variables per if statement.  if no more variables hit return
key. */
       // printf("*** CLAUSE VARIABLE LIST ***\n");
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
        clauseVariableList[79].assign("GOOD WORK");

        //strcpy(clvarlt[21], "QU");
        //strcpy(clvarlt[22], "GR");
        for(int i=1; i<18; i++)
        {
               // printf("** CLAUSE %d\n", i);
               cout<<"***CLAUSE***"<<i;
                for(int j=1; j<5; j++)
                {
                    int k = 4 * (i-1) + j;

                  //printf("VARIABLE %d  %s\n", j, clvarlt[k]); }
                cout<<"VARIABLE "<< j <<clauseVariableList[k]<<endl;
                }


                if (i==17)
                {
                    //printf("HIT RETURN KEY TO CONTINUE"); gets(buff); }
                    cout<<"HIT THE RETURN KEY TO CONTINUE..."<<endl;
                    getchar();
                }

        /****** inference section *****/
        //printf("** ENTER CONCLUSION ? "); gets(varble);

       // cout<<"****ENTER CONCLUSION? "<<endl;
        cout<<"Conclusion here is....PROFESSION"<<endl;
        variable.assign("PROFESSION");



        /* get conclusion statement number (sn) from the conclusion list
           (conclt) */
        /* first statement starts search */
b520: f=1;
          determine_member_concl_list();
          if (sn != 0){
                  /* if sn = 0 then no conclusion of that name */ do
                  /* push statement number (sn) and clause number=1 on
goal
                     stack which is composed of the statement stack
(statsk)
                     and clause stack (clausk) */
                  {
                          push_on_stack();
                          do
                          {
                           /* calculate clause location in clause-variable
                              list */
b545: i= (statementStack[stackPointer] -1) *4 + clauseStack[stackPointer];
          /* clause variable */
          //strcpy(variable, clauseVariableList[i]);
          variable.assign(clauseVariableList[i]);
          if(strcmp(variable.c_str(), "") != 0) {
                  /*is this clause variable a conclusion? */
                  f = 1;
                  determine_member_concl_list();
                  if(sn != 0)
                          /* it is a conclusion push it */
                          goto b520;
                  /* check instantiation of this clause */
                  instantiate();
                  clauseStack[stackPointer] = clauseStack[stackPointer] + 1;
          }
                          } while(strcmp(variable.c_str(), "") != 0); /*do-while*/
                          /*no more clauses check if part of statement */
                          sn = statementStack[stackPointer];
                          s = 0;
                          /**** if then statements ****/
                          /* sample if parts of if then statements from
                             the position knowledge base */

                          switch (sn) {
                                  /* if part of statement 1 */
                                  /****** comment 1500 ****/
                          case 1: if(strcmp(degree.c_str(), "NO") == 0) s = 1;
                                  break;
                                  /* if part of statement 2 */
                                  /***** comment 1510 ******/
                          case 2: if(strcmp(degree.c_str(), "YES") == 0) s = 1;
                                  break;
                                  /* if part of statement 3 */
                          case 3: if((strcmp(degree.c_str(), "YES") == 0) &&
                                     (strcmp(labwork.c_str(), "YES") == 0)) s =1;
                                  break;
                                  /* if part of statement 4 */
                                  /******** comment 1560 ******/
                          case 4: if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                                     (grade<3.5) && (grade >= 2)) s = 1;
                                  break;
                                  /******** comment 1570 ********/
                                  /* if part of statement 5 */
                          case 5: if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                                     (grade<3) && (grade<2)) s = 1;
                                  break;
                                  /* if part of statement 6 */
                          case 6: if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                                     (grade >=3.5)) s = 1;

                                  break;
                                  /********* comment 1680 ******/
                          }
                          /* see if the then part should be invoked */
                          if( s != 1) {
                                  /* failed..search rest of statements for
                                     same conclusion */
                                  /* get conclusion */
                                  i = statementStack[stackPointer];
                                  //strcpy(variable, clauseVariableList[i]);
                                  variable.assign(clauseVariableList[i]);
                                  /* search for conclusion starting at the
                                     next statement number */
                                  f = statementStack[stackPointer] + 1;
                                  determine_member_concl_list();
                                  stackPointer = stackPointer+1;
                          }
                          /* pop old conclusion and put on new one */
                  } while((s != 1) && (sn !=0));  /* outer do-while loop */
                  if(sn != 0){
                          /* if part true invoke then part */
                          /* then part of if-then statements from the
                             position knowledge base */
                          switch (sn) {
                                  /* then part of statement 1 */
                                  /******* comment 1500 *******/
                          case 1: strcpy(po, "NO");
                                  printf("PO=NO\n");
                                  break;
                                  /* then part of statement 2 */
                                  /****** comment 1510 ******/
                          case 2: strcpy(qu, "YES");
                                  printf("QU=YES\n");
                                  break;
                                  /* then part of statement 3 */
                          case 3: strcpy(po, "YES");
                                  printf("PO=RESEARCH\n");
                                  break;
                                  /* then part of statement 4 */
                                  /******** comment 1560 ******/
                          case 4: strcpy(po, "YES");
                                  printf("PO=SERVICE ENGINEER\n");
                                  break;
                                  /* then part of statement 5 */
                                  /****** comment 1570 *****/
                          case 5: strcpy(po, "NO");
                                  printf("PO=NO");
                                  break;
                                  /* then part of statement 6 */
                          case 6: strcpy(po, "YES");
                                  printf("PO=PRODUCT ENGINEER\n");
                                  break;
                                  /****** comment 1680 ********/
                          }
                          /* pop the stack */
                          stackPointer=stackPointer+1;
                          if(stackPointer >= 11)
                                  /* finished */
                                  printf("*** SUCCESS\n");
                          else {
                                  /* stack is not empty */
                                  /* get next clause then continue */
                                  clauseStack[stackPointer] = clauseStack[stackPointer]+1;
                                  goto b545;
                          }
                  }
        }
}

void determine_member_concl_list() {
/* routine to determine if a variable (varble) is a member of the
   conclusion list (conclt).  if yes return sn != 0.
   if not a member sn=0;
*/
        /* initially set to not a member */
        sn = 0;
        /* member of conclusion list to be searched is f */
        i = f;
        while((strcmp(variable.c_str(), conclusionList[i].c_str()) != 0) && (i<8))
                /* test for membership */
                i=i+1;
        if (strcmp(variable.c_str(), conclusionList[i].c_str()) == 0) sn = i;  /* a member */
}

void push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (statsk) and the
clause stack (clausk)..to push decrement stack pointer (sp) */
{
        stackPointer=stackPointer-1;
        statementStack[stackPointer] = sn;
        clauseStack[stackPointer] = 1;
}

void instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
variable list (varlt) contains the variable (varble). */
{
        i=1;
        /* find variable in the list */
        while((strcmp(variable.c_str(), variableList[i].c_str()) != 0) && (i<10)) i=i+1;
        if((strcmp(variable.c_str(), variableList[i].c_str()) == 0) && (instantiatedList[i] != 1))
                /*found variable and not already instantiated */
        {
                instantiatedList[i]=1; /*mark instantiated */
                /* the designer of the
               knowledge base places the input statements to
               instantiate the variables below in the case statement */
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
                case 4: printf("INPUT A REAL NUMBER FOR GR-? ");
                        scanf("%f", &gr);
                        break;
                        /***** comment 1715 ****/
                }
                /* end of inputs statements for sample position knowledge
                   base */
        }
}


