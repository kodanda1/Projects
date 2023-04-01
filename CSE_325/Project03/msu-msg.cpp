#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

#define NUM_THREADS 5

// data structure for passing parameters to threads
struct thread_data {
  int  thread_id;
  string message;
};

// declare the structures that will hold the thread parameters (needs to be global variable!)
struct thread_data td[NUM_THREADS];

// mutex for critical sections when threads print
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

// semaphores for synchronizing printing of keys, one for each thread
sem_t sem[NUM_THREADS];

// two sets of keys, one simple, one less so...
string key[2][NUM_THREADS] = {
  {"bbbb",
   "cccc",
   "dddd",
   "eeee",
   "ffff"},
  {"X!bp!!t\vubtf(dv!jT(mbKpo!fo!!!inoffpvkoi;xudbw5c",
   "iitvxuoBim!\"tlqNhutfuboett!mqpffcw\"sspuu0/vpu>9b",
   "pf!cjibofmg\v!f!jbb!oud/!d\"ubmg!\"fb\v!!z;u0zcndENR",
   "b!umufqe!!sJqecdouK!tl\vip\vitb!h\vmc\vzfn!qxpf0irx\v",
   "-isfi!\"!cjfuj!zi!fbX.tBfsPfuzubVjmGpof!txv/x@wF\v"}
};

// print message if usage is incorrect
void usage();

// ascii to integer conversion
int atoi();


// function to implement thread; coordinate with other threads to print characters
// from keys in round-robin order
void *printMsg(void *threadarg) {

  // local variable to point to parameters
  struct thread_data *my_data = (struct thread_data *) threadarg;

  // thread identifier: 0, 1, 2, 3, 4
  int myid = my_data->thread_id ;  

  // string holding key used by this thread
  string s = (string) my_data->message;

  // counter for printing one character at a time
  int k;  

  // print a message identifying the thread with  myid (0, 1, 2, 3, or 4)
  // surround any I/O with the mutex lock/unlock
  // [*** insert your code here]

  pthread_mutex_lock(&print_mutex);

  cout<< "Thread id : "<<myid<<" starting up"<<endl<<endl;
  pthread_mutex_unlock(&print_mutex);


  
  // step through the string s, one character at a time
  // you can use a C++ iterator or just step through the string with counting variable k
  for (k=0; k < s.length(); k++) {
    
  

	// wait on my semaphore, sem[myid]
	// [*** insert your code here]
    sem_wait(&sem[myid]);



	// use usleep to add a little delay between each character printed, e.g. 70 milliseconds
	// [*** insert your code here]
    usleep(70000);

	// print out the ascii character immediately preceding 
	// this example is using k to step through the string
	// note the std::flush at the end to make sure the character is printed in timely manner
	  cout << static_cast<char>(s[k] - 1) << std::flush;

	// post semaphore for the next thread to print, handle wrap-around from thread 4 back to 0
	// [*** insert your code here

    if(myid == NUM_THREADS-1){
      sem_post(&sem[0]);
    }
    else{
      sem_post(&sem[myid+1]);
    }
  }
  pthread_exit(NULL);
}

// main function for msu-msg program
// takes one integer command-line argument (0 or 1), identifying key set to translate.
int main(int argc, char * argv[]) {

  pthread_t threads[NUM_THREADS]; // for creating threads, will hold their internal IDs
  int keyindex; // identify which key set to use
  int rc; // return value
  int i;  // loop counter

  // there should be one command-line parameters, 0 or 1
  if(argc != 2)
	{
	  usage();
	  return(-1);
	}
  if ((keyindex < 0) || (keyindex > 1))
	{
	  usage();
	  return(-1);
	}
  
  keyindex = atoi(argv[1]);

  // for each thread, initialize its semaphore and create the thread
  for( i = 0; i < NUM_THREADS; i++ ) {
    

	// initialize its semaphore to have initial value of 0 (locked)
	// [*** insert your code here]

    sem_init(&sem[i],0,0);


	// print a message about creating this thread
	  cout <<"main() : creating thread, " << i << endl;

	// set up the parameters for the thread
	  td[i].thread_id = i;
	  td[i].message = key[keyindex][i];

	// create the thread and check for errors in return value
	// Note: last parameter must be a *pointer* to td[i]!
	// [***	insert your code here]

    rc = pthread_create(& threads[i],NULL,printMsg, (void*)&td[i]);

    if(rc!=0){
      cout<<"error building creating thread"<<endl;
      exit(-1);
    }
    //pthread_exit(NULL);

  

  }
  
  // post sem[0] to get things started
  // [*** insert your code here]

  sem_post(&sem[0]);
  


  // wait for other threads to finish by using pthread_join()
  // [***
  
  for( i = 0; i < NUM_THREADS; i++ )
  {
    rc = pthread_join(threads[i],NULL);
    if(rc){
      cerr<< " Error with pthread join.  error code = "<< rc <<endl;

      return (EXIT_FAILURE);
    }  
  }
  // call pthread_exit to finish cleanly, though not absolutely necessary after joins
  pthread_exit(NULL);
}

void usage()
{
  cout << "Usage: msu-msg keyindex\n";
  cout << "Where:\n";
  cout << "msu-msg - name of the executable.\n";
  cout << "keyindex - 0 or 1\n";
}

