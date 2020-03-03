#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

void *time_count();
void *read_inport();
double get_time_ms();
int program_time;

int main() {
    program_time = 0;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, time_count, NULL);

    pthread_create(&t2, NULL, read_inport, NULL);



    double start_time;
    double current_time;

    start_time = get_time_ms();
    while ( program_time < 50){
        current_time = get_time_ms();
        if((current_time-start_time) >= 1000){
            printf("Time is %d \n", program_time);
            start_time = get_time_ms();
        }
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

void *time_count() {
    double start_time;
    double current_time;

    start_time = get_time_ms();
    while ( program_time < 50){
        current_time = get_time_ms();
        if((current_time-start_time) >= 1000){
            program_time++;
            start_time = get_time_ms();
        }

    }
    pthread_exit(0);
}
void *read_inport(){
    double start_time;
    double current_time;

    start_time = get_time_ms();
    while ( program_time < 50){
        current_time = get_time_ms();
        if((current_time-start_time) >= 5000){
            puts("Reading value now");
            start_time = get_time_ms();
        }

    }

}
double get_time_ms(){
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
