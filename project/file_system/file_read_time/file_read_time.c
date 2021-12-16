#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//declaration
void say_hello();
void create_file(int length);
void delete_file();
void read_file_seq(int line_size);
void read_file_random(int line_size);
void run_test();
void get_file_size();

int main(){
    say_hello();

    int number_of_tests = 50;

    run_test(10, number_of_tests);
    run_test(25, number_of_tests);
    run_test(50, number_of_tests);
    run_test(100, number_of_tests);
    run_test(250, number_of_tests);
    run_test(500, number_of_tests);
    run_test(1000, number_of_tests);
    run_test(1500, number_of_tests);
    run_test(2000, number_of_tests);
    run_test(2500, number_of_tests);
    printf("Program Ended\n");
    return 0;
}


void run_test(int line_size, int number_of_tests){

    clock_t t;
    t = clock();
    
    int my_counter = 0;
    double time_seq_sum = 0;
    double time_ran_sum = 0;

    while(my_counter < number_of_tests){
        create_file(line_size);
        // delete_file();

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
        // printf("create_file() took %f seconds to execute \n", time_taken);



        t = clock();
        read_file_seq(line_size);
        t = clock() - t;
        double time_seq = ((double)t)/CLOCKS_PER_SEC; // in seconds

        time_seq_sum = time_seq + time_seq_sum;




        t = clock();
        read_file_random(line_size);
        t = clock() - t;
        double time_random = ((double)t)/CLOCKS_PER_SEC; // in seconds

        time_ran_sum = time_random + time_ran_sum;

        my_counter++;
    }

    printf("_________________________________________________________\n");
    printf("ON AVERAGE: read_file_seq() took %f seconds to execute \n", time_seq_sum / number_of_tests);
    printf("ON AVERAGE: read_file_random() took %f seconds to execute \n", time_ran_sum / number_of_tests);
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
    printf("Number of tests done: %d \n", number_of_tests);
    printf("Line size is: %d \n", line_size);

    get_file_size();
    delete_file();

}

void create_file(int length){
    FILE * fpointer = fopen("blocks.txt", "w");
    // printf("%d\n", length);
    int count = 0;
    while(count < length){
        fprintf(fpointer, "%d\n", count);
        count = count + 1;
    }
    fclose(fpointer);

    return;
}

void delete_file(){
    remove("blocks.txt");
    return;
}

void say_hello(){
    printf("Program Starting\n");
}

void read_file_seq(int line_size){
    // printf("This is the line size: ");
    // printf("%d\n", line_size);

    int a = line_size;

    char strArray[line_size][line_size];

    FILE * fpointer = fopen("blocks.txt", "r");

    if(fpointer == NULL){
        perror("Can't open file");
        exit(1);
    }

    char line[100];


    // printf("File to array has started\n");
    int count = 0;
    while(fgets(line, sizeof(line), fpointer)){

        int i = 0;
        while(line[i] != '\n'){
            strArray[count][i] = line[i];
            i ++;
        }

        count++;
    }


    count = 0;

    // printf("file has gone to the array\n");

    while(count < line_size){

        // printf("%s\n", strArray[count]);
        count += 1;
    }

    return;
}

void read_file_random(int line_size){
    // printf("This is the line size: ");
    // printf("%d\n", line_size);

    int a = line_size;

    char strArray[2500][2500];


    int random_loop = 0;
    while(random_loop < line_size){
        int r = rand() % line_size;
        // printf("The random number is: ");
        // printf("%d\n", r);

        // printf("File to array has started\n");
        int count = 0;

        char line[100];
        FILE * fpointer = fopen("blocks.txt", "r");
            if(fpointer == NULL){
                perror("Can't open file");
                exit(1);
            }
        while(fgets(line, sizeof(line), fpointer)){

            int line_as_int = atoi(line);
            
            if(line_as_int == r){
                // printf("The random number has been found!\n");
                // printf("We are on line:");
                // printf("%d\n", line_as_int);
                break;

            }
            // printf("We are on line:");
            // printf("%d\n", line_as_int);

            int i = 0;
            while(line[i] != '\n'){
                strArray[count][i] = line[i];
                i ++;
            }

            count++;
    }


        random_loop++;
    }




    int count = 0;

    // printf("file has gone to the array\n");

    while(count < line_size){

        // printf("%s\n", strArray[count]);
        count += 1;
    }

    return;
}

void get_file_size(){
    FILE * fpointer = fopen("blocks.txt", "r");
    fseek(fpointer, 0L, SEEK_END);
    printf("File size is: %ld bytes \n", ftell(fpointer));
}