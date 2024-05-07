#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#define NUM_THREADS 4
pthread_t threads [NUM_THREADS]; // Global variable to store thread IDS
void sigusr1_handler(int signum) { // signal handler
int i = gettid(), j = getppid(), k = getpid(); fprintf(stdout, "Thread %u received SIGUSR1 signal (parent=%d [pid=%d]\n", (unsigned long)pthread_self(), getppid(), getpid()); while (1)
sleep(1); // Keep the thread alive
}
void *thread_function(void *arg) { // thread function //signal(SIGUSR1, sigusr1_handler); // register signal handler
while (1) sleep(1); // Keep the thread alive
return NULL;
}
int main() {
signal(SIGUSR1, sigusr1_handler); // register signal handler
for (int i = 0; i < NUM_THREADS; ++i) {
if (pthread_create(&threads [i], NULL, thread_function, NULL) != 0) { perror("pthread_create"); exit(EXIT_FAILURE);
}
}
int i = gettid(), j = getpid(), k = getppid();
fprintf(stdout, "Parent Process ID: %u, Process ID: %u, main() thread ID: %u\n", k, j, i);
fprintf(stdout, "Thread IDS: 0=%u, 1=%u, 2=%u and 3=%u\n", threads [0], threads [1],
threads [2], threads [3]);

kill(j, SIGUSR1); // send signal to process

pthread_kill(threads [2], SIGUSR1); // send signal to 3rd thread

for (int i = 0; i < NUM_THREADS; ++i) {
if (pthread_join(threads[i], NULL) != 0) { perror("pthread_join"); exit(EXIT_FAILURE);

}

}


return 0;
}

