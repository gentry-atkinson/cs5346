#include<string>

class BC
{
	private:
		/* Variables declared here */
        static const int size = 11;
        static const int clauseSize = 40;
        std::string conclt[size], varlt[size], clvarlt[clauseSize];
        std::string varble, qu, de, di, po;
        char buff[256];
        int instlt[size];
        int statsk[size], clausk[size], sn, f, i, j, s, k, sp;
        float gr, ex;
    public:
    	void initialization();
    	void inferenceSection();
    	void B520();
    	void KeepProcessing();
    	void determine_member_concl_list();
    	void push_on_stack();
    	void instantiate();
    	void initkbase();
    	void InBetweenFunction();
    	void popStack();
        void B545();
};
