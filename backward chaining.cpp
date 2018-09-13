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
string variables[18];
string /* qualify */ goodGrades, /* degree*/ degree;
string /* discovery */ labwork, /* position */ profession, ;
string outdoorWork, leadership, groupWork;
char buff[128];

/* instantiated list */
int instantiatedList[11];
/* statement stack */
int statementStack[11];
int /* clause stack */ clauseStack[11], sn, f, s, /*stack pointer */ stackPointer;

float /* grade */ gr, /*experience */ ex;

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


        conclusionList.copy("");
        variableList.copy("");
        for (int i=0; i<69; i++)  clauseVariableList[i].copy("");
        /* enter conclusions which are the variables in the then part,
1 at
        a time.  enter the conclusions in exact order starting at the 1st
        if-then.  after last conclusion hit return key for rest of
        conclusions */

        /*** comment 305 *****/
        //strcpy(conclt[1], "PO");
        conclusionList[1].copy("GOOD GRADES");
        //strcpy(conclt[2], "QU");
        conclusionList[2].copy("GOOD GRADES");
        //strcpy(conclt[3], "PO");
        conclusionList[3].copy("LAB WORK");
        //strcpy(conclt[4], "PO");
        conclusionList[4].copy("LEADERSHIP");
        //strcpy(conclt[5], "PO");
        conclusionList[5].copy("PROFESSION");
        //strcpy(conclt[6], "PO");
        conclusionList[6].copy("PROFESSION");
        conclusionList[7].copy("PROFESSION");
        conclusionList[8].copy("WORK ALONE");
        conclusionList[9].copy("PROFESSION");
        conclusionList[10].copy("PROFESSION");
        conclusionList[11].copy("OUTDOOR WORK");
        conclusionList[12].copy("PROFESSION");
        conclusionList[13].copy("PROFESSION");
        conclusionList[14].copy("PROFESSION");
        conclusionList[15].copy("MEDICAL CERTIFICATE");
        conclusionList[16].copy("PROFESSION");
        conclusionList[17].copy("TEACHING CERTIFICATE");
        conclusionList[18].copy("PROFESSION");
        conclusionList[19].copy("PROFESSION");
        conclusionList[20].copy("PROFESSION");
        //printf("*** CONCLUSION LIST ***\n");
        for (i=1; i<21; i++) /*printf("CONCLUSION %d %s\n", i,conclt[i])*/ cout << "Conclusion: " << i << conclusionList[i] << endl;

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
        variableList[1].copy("DEGREE");
        //strcpy(varlt[2], "DI");
        variableList[2].copy("GOOD GRADES");
        //strcpy(varlt[3], "EX");
        variableList[3].copy("LAB WORK");
        //strcpy(varlt[4], "GR");
        variableList[4].copy("LEADERSHIP");
        variableList[5].copy("MED SCHOOL");
        variableList[6].copy("GROUP WORK");
        variableList[7].copy("WORK ALONE");
        variableList[8].copy("OUTDOOR WORK");
        variableList[9].copy("MEDICAL CERTIFICATE");
        variableList[10].copy("TEACHER CERTIFICATE");
        variableList[11].copy("PROJECT WORK");
        variableList[12].copy("PROFESSION");
        variableList[13].copy("COURSES WITH LABS");
        variableList[14].copy("GROUP LEADER");
        variableList[15].copy("HOURS OUTSIDE");
        variableList[16].copy("MED FIELD");
        variableList[17].copy("CRIMINAL BACKGROUND");
        for(int i=1; i<18; i++) /*printf("VARIABLE %d %s\n", i, varlt[i])*/ cout << "Variable: " << i << " " << variableList[i];
        //printf("HIT RETURN KEY TO CONTINUE");
        cout << "Hit Return to continue...";
        //gets(buff);
        getchar();
        /* enter variables as they appear in the if clauses.  a maximum
of 3
        variables per if statement.  if no more variables hit return
key. */
        printf("*** CLAUSE VARIABLE LIST ***\n");
        /***** comment 407 through 409 ***/
        strcpy(clvarlt[1], "DE");
        strcpy(clvarlt[5], "DE");
        strcpy(clvarlt[9], "DE");
        strcpy(clvarlt[10], "DI");
        strcpy(clvarlt[13], "QU");
        strcpy(clvarlt[14], "GR");
        strcpy(clvarlt[15], "EX");
        strcpy(clvarlt[17], "QU");
        strcpy(clvarlt[18], "GR");
        strcpy(clvarlt[19], "EX");
        strcpy(clvarlt[21], "QU");
        strcpy(clvarlt[22], "GR");
        for(i=1; i<9; i++)
        {
                printf("** CLAUSE %d\n", i);
                for(j=1; j<5; j++)
                { k = 4 * (i-1) + j;
                  printf("VARIABLE %d  %s\n", j, clvarlt[k]); }
                if (i==4)
                { printf("HIT RETURN KEY TO CONTINUE"); gets(buff); }
        }
        /****** inference section *****/
        printf("** ENTER CONCLUSION ? "); gets(varble);
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
b545: i= (statsk[sp] -1) *4 + clausk[sp];
          /* clause variable */
          strcpy(varble, clvarlt[i]);
          if(strcmp(varble, "") != 0) {
                  /*is this clause variable a conclusion? */
                  f = 1;
                  determine_member_concl_list();
                  if(sn != 0)
                          /* it is a conclusion push it */
                          goto b520;
                  /* check instantiation of this clause */
                  instantiate();
                  clausk[sp] = clausk[sp] + 1;
          }
                          } while(strcmp(varble, "") != 0); /*do-while*/
                          /*no more clauses check if part of statement */
                          sn = statsk[sp];
                          s = 0;
                          /**** if then statements ****/
                          /* sample if parts of if then statements from
                             the position knowledge base */
                          switch (sn) {
                                  /* if part of statement 1 */
                                  /****** comment 1500 ****/
                          case 1: if(strcmp(de, "NO") == 0) s = 1;
                                  break;
                                  /* if part of statement 2 */
                                  /***** comment 1510 ******/
                          case 2: if(strcmp(de, "YES") == 0) s = 1;
                                  break;
                                  /* if part of statement 3 */
                          case 3: if((strcmp(de, "YES") == 0) &&
                                     (strcmp(di, "YES") == 0)) s =1;
                                  break;
                                  /* if part of statement 4 */
                                  /******** comment 1560 ******/
                          case 4: if((strcmp(qu, "YES") == 0) &&
                                     (gr<3.5) && (ex >= 2)) s = 1;
                                  break;
                                  /******** comment 1570 ********/
                                  /* if part of statement 5 */
                          case 5: if((strcmp(qu, "YES") == 0) &&
                                     (gr<3) && (ex<2)) s = 1;
                                  break;
                                  /* if part of statement 6 */
                          case 6: if((strcmp(qu, "YES") == 0) &&
                                     (gr >=3.5)) s = 1;

                                  break;
                                  /********* comment 1680 ******/
                          }
                          /* see if the then part should be invoked */
                          if( s != 1) {
                                  /* failed..search rest of statements for
                                     same conclusion */
                                  /* get conclusion */
                                  i = statsk[sp];
                                  strcpy(varble, conclt[i]);
                                  /* search for conclusion starting at the
                                     next statement number */
                                  f = statsk[sp] + 1;
                                  determine_member_concl_list();
                                  sp = sp+1;
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
                          sp=sp+1;
                          if(sp >= 11)
                                  /* finished */
                                  printf("*** SUCCESS\n");
                          else {
                                  /* stack is not empty */
                                  /* get next clause then continue */
                                  clausk[sp] = clausk[sp]+1;
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
        while((strcmp(varble, conclt[i]) != 0) && (i<8))
                /* test for membership */
                i=i+1;
        if (strcmp(varble, conclt[i]) == 0) sn = i;  /* a member */
}

void push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (statsk) and the
clause stack (clausk)..to push decrement stack pointer (sp) */
{
        sp=sp-1;
        statsk[sp] = sn;
        clausk[sp] = 1;
}

void instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
variable list (varlt) contains the variable (varble). */
{
        i=1;
        /* find variable in the list */
        while((strcmp(varble, varlt[i]) != 0) && (i<10)) i=i+1;
        if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1))
                /*found variable and not already instantiated */
        {
                instlt[i]=1; /*mark instantiated */
                /* the designer of the
               knowledge base places the input statements to
               instantiate the variables below in the case statement */
                switch (i)
                {
                        /***** input statement *****/
                        /* input statements for sample position knowledge
                           base */
                        /***** comment 1700 ******/
                case 1: printf("INPUT YES OR NOW FOR DE-? ");
                        gets(de);
                        break;
                case 2: printf("INPUT YES OR NO FOR DI-? ");
                        gets(di);
                        break;
                case 3: printf("INPUT A REAL NUMBER FOR EX-? ");
                        scanf("%f", &ex);
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


