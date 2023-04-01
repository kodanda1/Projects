#include <stdio.h>
#include <signal.h>
#include <x86intrin.h>
#include <sys/time.h>
#include <cstdint>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;

// state of this process
int chainseq;
pid_t mypid;
pid_t nextpid;
string tracefile;
ofstream tracestream;

// function to print message in case of invalid usage
void usage();

// function to trace execution
void trace(string s);


//	main(int argc, char * argv[])
//	This is a 'C' standard format to handle command-line parameters
//		argc -	the number of command-line parameters.  This includes
//				the name of the executable, so argc will always be >= 1.
//		argv -	An array of pointers to 'C' strings, not instances of the 'C++'
//				String class.  This array of pointers is NULL terminated.

void sigint_handler(int signo)
{
  char c;
  if (signo == SIGINT)
  {
	alarm(0); // stop timer
    cout << "received SIGINT\n";
	trace("proc-sig: PID " + to_string(mypid) + " received SIGINT\n");
    cout << "What do you want to do?\n";
    cout << "  Enter 'a' to terminate all three processes.\n";
    cout << "  Enter 'b' to continue execution of all processes.\n";
	cin >> c;
    switch (c) {
	case 'a' :
	  cout << "  user entered a\n";
	  trace("  user entered a\n");

	  // [enter code here]
	  // send a SIGUSR1 signal to second process in chain (chainseq 1)
	  // use usleep() to delay for 6 seconds
	  // print a final message
	  kill (nextpid, SIGUSR1);
	  usleep(600000);
	  cout<<"Process "<<to_string(mypid)<<" exiting." <<" Goodbye cruel world.\n";

	  cout<<"\nSee you later... in the matrix!!\n";

	  trace("proc-sig: PID " + to_string(mypid) + " exiting.\n");
	  
	  exit(0);
	  break;

	case 'b' :
	  cout << "  user entered b\n";
	  trace("  user entered b\n");
	  

	  // [enter code here]
	  // use ualarm() to set an alarm to fire in 0.8 seconds   
	  ualarm(800000,0);


	  break;
	default: 
	  cout << "  illegal answer\n";

	  // [enter code here]
	  // use ualarm() to set an alarm to fire in 0.8 seconds 
	  ualarm(800000,0);
	  

	}
	
  }
}

void sigusr1_handler(int signo)
{
  if (signo == SIGUSR1)
  {
	alarm(0); // stop timer
	trace("proc-sig: PID " + to_string(mypid) + " received SIGUSR1\n");
    cout << "received SIGUSR1\n";
	
	// [enter code here]
	// send SIGUSR2 signal to first process in chain (chainseq 0)
	// use usleep() to sleep for 4 seconds
	// print final message 
	kill (nextpid, SIGUSR2);
	usleep(400000);
	cout<<"\nProcess "<<to_string(mypid)<<" exiting." <<" Goodbye cruel world.\n";

    trace("proc-sig: PID " + to_string(mypid) + " exiting.\n");
	exit(0);
  }
}

void sigusr2_handler(int signo)
{
  if (signo == SIGUSR2)
  {
	alarm(0); // stop timer
	trace("proc-sig: PID " + to_string(mypid) + " received SIGUSR2\n");
    cout << "received SIGUSR2\n";
	
	// [enter code here]
	// use usleep() to sleep for 2 seconds
	// print final message 
	usleep(200000);
	cout<<"\nProcess "<<to_string(mypid)<<" exiting."<<" Goodbye cruel world\n";


	trace("proc-sig: PID " + to_string(mypid) + " exiting.\n");
	exit(0);
  }
}

void sigalrm_handler(int signo)
{
  // [enter code here]
  // print a looping message
  // use ualarm() to set alarm timer to fire in 0.8 seconds
  
  if(signo == SIGALRM)
  {
	cout<<"Process "<<to_string(mypid)<< " looping happily along... \n";
  }
  ualarm(800000,0);
} 


// main function for proc-sig.cpp
// Usage: proc-sig chainseq pid tracefile
// Parameters:
//   chainseq - 0, 1, or 2.
//   pid - Linux PID of the next process in the chain.
//   tracefile - file used by the trace function.

int main(int argc, char * argv[]) 
{

    // should be two command line parameters, number of pages and probe value
    if(argc != 4)
    {
        usage();
        return(-1);
    }

	// convert ascii command line parameters to integers
    chainseq = atoi( argv[1] );
	mypid = getpid();
    nextpid = (pid_t) atoi( argv[2] );
	tracefile = argv[3];

	// open the trace file for writing
	tracestream.open (tracefile, ios::app);
	trace("proc-sig: process " + to_string(mypid) + " starting with parameters " + to_string(chainseq) + ", " + to_string(nextpid) + "\n");

	// declare structures for catching signals
	struct sigaction salarm;
	struct sigaction sint;
	struct sigaction susr1;
	struct sigaction susr2;

	/* register signal handler for SIGALRM */
	memset(&salarm, 0, sizeof salarm);
	salarm.sa_handler = sigalrm_handler;
	if (sigaction(SIGALRM, &salarm, NULL) < 0)
	  cout << "\ncan't catch SIGALRM\n";

	//set an alarm to go off and print a message
	ualarm(800000,0);

	switch(chainseq) {
	case 0  :
	  cout << "I am process 0 (the end) in the chain.  My pid is " + to_string(mypid) + "\n";
	  
	  memset(&susr2, 0, sizeof susr2);
	  susr2.sa_handler = sigusr2_handler;
	  if (sigaction(SIGUSR2, &susr2, NULL) < 0)
		cout << "\ncan't catch SIGALRM\n";

	  while(1) 
		usleep(100000);

	  // [enter code here]
      // register sigusr2_handler to catch SIGUSR2 signals

	  // Loop, sleeping for 0.1 seconds at a time 
	

	case 1  :
	  cout << "I am process 1 (the middle) in the chain.   My pid is " + to_string(mypid) + "\n";
	  
	  memset(&susr1, 0, sizeof susr1);
	  susr1.sa_handler = sigusr1_handler;
	  if (sigaction(SIGUSR1, &susr1, NULL) < 0)
		cout << "\ncan't catch SIGALRM\n";

	  // [enter code here]
      // register sigusr1_handler to catch SIGUSR1 signals

	  // Loop, sleeping 0.1 seconds at a time
	  while(1) 
		usleep(100000);

	case 2  :
	  cout << "I am process 2 (the beginning) in the chain.  My pid is " + to_string(mypid) + "\n";
	  
	  memset(&sint, 0, sizeof sint);
	  sint.sa_handler = sigint_handler;
	  if (sigaction(SIGINT, &sint, NULL) < 0)
		cout << "\ncan't catch SIGALRM\n";

	  // [enter code here]
      // register sigint_handler to catch SIGINT signals

      // Loop, sleeping for 0.1 seconds at a time
	  while(1) 
		usleep(100000);

	  // you can have any number of case statements.
	default : //Optional
	  cout << "Invalid chain sequence number; exiting\n";
	  exit(0);
	}

	return(0);
}


void usage()
{
  cout << "Usage: proc-sig chainseq pid tracefile\n";
  cout << "Where:\n";
  cout << "proc-sig - The name of the executable.\n";
  cout << "chainseq - 0, 1, or 2.\n";
  cout << "pid - Linux PID of the next process in the chain.\n";
  cout << "tracefile - file used by the trace function.\n";
}

void trace(string s)
{
    struct timeval t;
	gettimeofday(&t, NULL);
	tracestream << "Time: " << to_string(t.tv_sec % 10000) << "." << to_string((int) t.tv_usec/100) << ": " << s;
	usleep(100000);
	tracestream.flush();
}
