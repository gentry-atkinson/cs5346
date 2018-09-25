#include "bc.h"
#include <cstdio>
#include <iostream>

using namespace std;

void BC::initialization()
{
	// Stack space is 10 we initially place stack space at 10+1
    sp = size;
	for (i=1; i < size; i++)
        {
            conclt[i] = "";
            varlt[i] = "";
            instlt[i]=0;
            statsk[i]=0;
            clausk[i]=0;
        }
    for (i=1; i < clauseSize + 1; i++)
        clvarlt[i] = "";

    // Initializing Conclusion List
    conclt[1] = "PO";
    conclt[2] = "QU";
    conclt[3] = "PO";
    conclt[4] = "PO";
    conclt[5] = "PO";
    conclt[6] = "PO";

    // Printing Conclusion list
    cout<<"*** CONCLUSION LIST ***"<<endl;
    for (i=1; i < size; i++)
    	cout<<"CONCLUSION "<<i<<" "<<conclt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

    // Initializing Variable List
    varlt[1] = "DE";
    varlt[2] = "DI";
    varlt[3] = "EX";
    varlt[4] = "GR";

    // Printing Variable List
    cout<<"*** VARIABLE LIST ***"<<endl;
    for(i=1; i < size; i++)
    	cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

    // Initializing Clause Variable List
    clvarlt[1] = "DE";
    clvarlt[5] = "DE";
    clvarlt[9] = "DE";
    clvarlt[10] = "DI";
    clvarlt[13] = "QU";
    clvarlt[14] = "GR";
    clvarlt[15] = "EX";
    clvarlt[17] = "QU";
    clvarlt[18] = "GR";
    clvarlt[19] = "EX";
    clvarlt[21] = "QU";
    clvarlt[22] = "GR";

    //Printing Clause Variable List
    cout<<"*** CLAUSE VARIABLE LIST ***"<<endl;
    for(i=1; i < clauseSize/4; i++)
        {
            cout<<"** CLAUSE "<<i<<" **"<<endl;
            for(j=1; j<5; j++)
            {
                k = 4 * (i-1) + j;
                cout<<"VARIABLE "<<j<<" "<<clvarlt[k]<<endl;
            }
            if (i==4)
            {
    			cout<<"HIT RETURN TO CONTINUE";
                gets(buff);
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
    while((varble!=conclt[i]) && (i<8))
        i=i+1; /* test for membership */
    if (varble == conclt[i])
    	sn = i;  /* a member */
}

void BC::push_on_stack()
{
    sp=sp-1;
    statsk[sp] = sn;
    clausk[sp] = 1;
}

void BC::instantiate()
{
    i=1;
    /* find variable in the list */
    while (varble != varlt[i] && i<10)
    	i=i+1;
    if (varble == varlt[i] && instlt[i] != 1)
    {
      	/*found variable and not already instantiated */
      	/*mark instantiated */
        instlt[i]=1;
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
        i= (statsk[sp] -1) *4 + clausk[sp];
        /* clause variable */
        varble = clvarlt[i];
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
    sn = statsk[sp];
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
        i = statsk[sp];
        varble = conclt[i];
        /* search for conclusion starting at the next statement number */
        f = statsk[sp] + 1;
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
