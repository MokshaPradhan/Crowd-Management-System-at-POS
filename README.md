# Crowd-Management-System-at-POS
Code to direct and/or redirect people to appropriate aisles at the point of sale

->This C++ program simulates a crowd management system for multiple terminals. 
->The system keeps track of the number of people in each terminal's queue and redirects new people to the terminal with the least queue length.
->It also checks if any terminal becomes full (queue length reaches 50) and prompts users to self-checkout at the mobile terminal.

# Prerequisites
- C++ compiler (supporting C++11 or later)

# Compilation
To compile the program, use the following command:
g++ main.cpp -o crowd_management

# Execution
./CrowdManagement

# Usage
-Upon running the program, it will prompt you to enter the number of people already present in each terminal.
-The program will then check if any terminal's queue length exceeds the limit (50) and redirect the excess people to the terminal with the least queue length.
-You can continue to add more people entering the terminals by entering a positive integer or exit the program by entering 0.
-The program will continue to redirect new people until all terminals exceed the limit in which case it will redirect to mobile terminals.

# Functions
-Terminal::Terminal(int id, int limit): Constructor to initialize the terminal with an ID and limit.
-Terminal::GetTerminalNo(): Function to get the terminal number.
-Terminal::GetQueueLen(): Function to get the current queue length of the terminal.
-Terminal::GetLimit(): Function to get the maximum limit of the terminal's queue.
-NewQueueLen::UpdateQueueLen(Terminal& terminal, int people): Function to update the queue length of a terminal.
-NewQueueLen::Checkfull(vector<Terminal> &terminals): Function to check if all terminals are full (queue length >= 50).
-CrowdManagement::GetMinTerminal(vector<Terminal> &terminals): Function to get the terminal with the least queue length.
-CrowdManagement::RedirectNewPeople(vector<Terminal>& terminals, int val, int terminalid): Function to redirect new people to a terminal and manage the crowd.

  

