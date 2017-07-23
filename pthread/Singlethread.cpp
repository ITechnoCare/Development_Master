#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
using namespace std;
namespace TC   ///TC-Techno Care
{

    

class ThreadC
{

public:
	ThreadC();
	virtual ~ThreadC();
    void create_thread();
    void *function(void *ptr);
protected:
private:
int ret,ret1;
const char *message1;
const char *message2;


};

	ThreadC::ThreadC()
	{
		message1 = "Thread 1";
		message2 = "Thread 2";
	}
	ThreadC::~ThreadC(){}


void ThreadC::create_thread()
{


     pthread_t thread1, thread2;
     

    /* Create independent threads each of which will execute function */

     ret = pthread_create( &thread1, NULL, function,(void*)message1);
     if(ret)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",ret);
         exit(EXIT_FAILURE);
     }

     ret1 = pthread_create( &thread2, NULL, function,(void*)message2);
     if(ret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",ret1);
         exit(EXIT_FAILURE);
     }

     printf("Thread 1 returns: %d\n",ret);
     printf("Thread 2 returns: %d\n",ret1);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     exit(EXIT_SUCCESS);
}





void *ThreadC::function(void *ptr)
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}

int main()
{

ThreadC t1;
t1.create_thread();

return 0;
}

}//namespace TC
