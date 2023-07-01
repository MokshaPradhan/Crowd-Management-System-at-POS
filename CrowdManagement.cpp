#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Terminal 
{
    private:
    int TerminalNo;
    int QueueLen;
    int Limit;

    public:
    Terminal(int id, int limit)
    {
        TerminalNo=id;
        QueueLen=0;
        Limit=limit;
    }
    const int GetTerminalNo()// Functions to access private variables
    {
        return TerminalNo;
    }
    const int GetQueueLen()  
    {
        return QueueLen;
    }
    const int GetLimit()  
    {
        return Limit;
    }
    
    ~Terminal() {} // Destructor

friend class NewQueueLen;
};

class NewQueueLen 
{
public:
static void UpdateQueueLen(Terminal& terminal, int people)
 {
    terminal.QueueLen += people;
}
static void Checkfull(vector<Terminal> &terminals)
    {
        int x=0;
        for(Terminal& terminal:terminals)
        {
            if(terminal.GetQueueLen()>=50)
            {
                x++;
                //int sumn=terminal.GetQueueLen()-50;
                //terminal.UpdateQueueLen(-sumn);
            }
        }
        if(x==5)
        {
            cout<<"All terminals are full\nKindly self check out at Mobile terminal"<<endl;
            exit(0);
        }
    }
};


namespace CrowdManagement 
{

    typedef NewQueueLen NQL;
    Terminal* GetMinTerminal(vector<Terminal> &terminals)//Function to decide least queue length terminal which returns pointer to a Terminal object
    // used reference to avoid making copy of vector
    {
        if (terminals.empty()) 
        {
            cout << "Terminals are empty"<<endl;
            return nullptr;
        }
        Terminal* MinTerminal= &terminals[0];//Assume first terminal has minimum queue length

        for (int i = 1; i < terminals.size(); i++) 
        {
            if (terminals[i].GetQueueLen() < MinTerminal->GetQueueLen()) 
            {
                MinTerminal = &terminals[i];
            }
        }
        return MinTerminal;
    }
    //Redirecting ppl if the queue is full
    void RedirectNewPeople(vector<Terminal>& terminals, int val,int terminalid)
    {
        Terminal* MinTerminal = GetMinTerminal(terminals);
        NQL::UpdateQueueLen(*MinTerminal, val);//Friend class use
        //NQL::Checkfull(terminals);
        if (terminalid==0) 
        {
            cout << "Redirected " <<val <<" people to Terminal "<< MinTerminal->GetTerminalNo() <<endl;
        }
        
        else cout << "\nRedirected " <<val <<" people from Terminal "<<terminalid<<" to Terminal "<< MinTerminal->GetTerminalNo() <<endl;
        
        for (Terminal& terminal:terminals) 
        {
            cout << "Terminal " << terminal.GetTerminalNo() << ": " << terminal.GetQueueLen() << " people" <<endl;
        }
        //NQL::Checkfull(terminals);
    }
}

//checking if the condition is satisfied
void check(vector<Terminal>& terminals) 
{
    //Terminal *x;
    //x->Checkfull(terminals);
    typedef NewQueueLen NQL;
    for (Terminal& terminal : terminals)
    {
        int count = terminal.GetQueueLen();
        if (count > 50)
        {
            int term=terminal.GetTerminalNo();
            int excess = count - 50;
                
            NQL::UpdateQueueLen(terminal, -excess);//friend class use
            CrowdManagement::RedirectNewPeople(terminals, excess,term);
            //terminal.updateQueuelen(excess);
            NQL::Checkfull(terminals);
        }
    }
}

int main()
{
    const int numTerminals = 5;
    int val,g;
    vector<Terminal> terminals;
    //Terminal tx;
    for (int i = 1; i <= numTerminals; i++)// Create Terminals and push to vector 
    {
        terminals.push_back(Terminal(i,50));//Make limit for each terminal 50
    }
    for (Terminal  &terminal: terminals)//Get number of people of already in queue in each terminal
    {
        int people;
        cout << "Enter the number of people entering Terminal " << terminal.GetTerminalNo() << ": ";
        cin >> people;
        NewQueueLen::UpdateQueueLen(terminal,people);
    }
    check(terminals);
    while (true)
    {
        try
        {
            cout << "Enter the number of people entering (enter 0 to exit): ";
            cin >> val;
            
            // Check if the input is a valid integer
            if (cin.fail())
            {
                cin.clear(); // Clear the error state
                cin.ignore(10, '\n'); // Discard the invalid input
                throw runtime_error("");
            }
            if (val == 0)
            {
                exit(0);
            }
            else
            {  
                CrowdManagement::RedirectNewPeople(terminals, val, g = 0); // Redirect people to the terminal with the least queue length
                check(terminals);
            }
        }
        catch ( exception &e)
        {
        cerr << "\n \nError: Invalid input. Please enter an integer. " << e.what() << endl;            
        }
    }
    //tx->Checkfull(terminals);
    check(terminals);
    
    return 0;
}