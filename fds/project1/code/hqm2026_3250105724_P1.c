#include <stdio.h>
#include <time.h>
/*Global Variables used for timing measurements*/
clock_t start, stop, ticks; /* Variables to store clock ticks before/after performance */
double duration;            /* Average time per single search operation */
double total_time;          /* Total time for K repetitions */

/* Function prototypes for all algorithms*/
int Iterative_Binary_Search(int a[], int N, int key);
int Recursive_Binary_Search(int a[], int low, int high, int key);
int Recursive_Binary_Search_Wrapper(int a[], int N, int key);
int Iterative_Sequential_Search(int a[], int N, int key);
int Recursive_Sequential_Search(int a[], int N, int key);
void Test_Algorithms(int a[], int N, int key, int (*search_func)(int[], int, int));

/*
    Iterative Binary Search:

    Paramenter explanation:
        a[]: An order list implemented using an array
        N:   number of elements in the array
        key: value to search for
    Returns:
        1 if key is found,0 otherwise
*/
int Iterative_Binary_Search(int a[], int N, int key) {
    int low = 0, high = N - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2; /*Calculate middle index*/
        if (a[mid] == key) {    /*Key found*/
            return 1;
        }
        else if (a[mid] < key) { /*Key lies in right half of mid*/
            low = mid + 1;
        }
        else { /*Key lies in left half of mid*/
            high = mid - 1;
        }
    }
    return 0; /*Key is not in the array*/
}

/*
    Recursive Binary Search:

    Paramenter explanation:
        a[]: An order list implemented using an array
        low:   starting index of the array
        high:  ending index of the array
        key: value to search for
    Returns:
        1 if key is found,0 otherwise
*/

int Recursive_Binary_Search(int a[], int low, int high, int key) {
    if (low > high) { /*Base case: minus interval*/
        return 0;
    } /*Key is not in the array*/
    int mid = (low + high) / 2;
    if (a[mid] == key) { /*Key found*/
        return 1;
    }
    else if (a[mid] < key) { /*Search right half*/
        return Recursive_Binary_Search(a, mid + 1, high, key);
    }
    else { /*Search left half*/
        return Recursive_Binary_Search(a, low, mid - 1, key);
    }
}

/*
    Wrapper function for Recursive Binary Search to match the signature of other search functions.
    expected by Test_Algorithms(int a[], int N, int key, int (*search_func)(int[], int, int)).
    Paramenter explanation:
        a[]: An order list implemented using an array
        N:   number of elements in the array
        key: value to search for
    Returns:
        Recuriseve_Binary_Search(a, 0, N - 1, key)
*/
int Recursive_Binary_Search_Wrapper(int a[], int N, int key) {
    return Recursive_Binary_Search(a, 0, N - 1, key);
}

/*
    Iterative Sequential Search:

    Paramenter explanation:
        a[]: An order list implemented using an array
        N:   number of elements in the array
        key: value to search for
    Returns:
        1 if key is found,0 otherwise
*/
int Iterative_Sequential_Search(int a[], int N, int key) {
    for (int i = 0; i < N; i++) {
        if (a[i] == key) {
            return 1; /*Key found*/
        }
    }
    return 0; /*Key is not in the array*/
}

/*
    Recursive Sequential Search:

    Paramenter explanation:
        a[]: An order list implemented using an array
        N:   number of elements in the array
        key: value to search for
    Returns:
        1 if key is found,0 otherwise
*/
int Recursive_Sequential_Search(int a[], int N, int key) {
    if (N == 0) { /*Base case: empty array*/
        return 0; /*Key is not in the array*/
    }
    if (a[N - 1] == key) { /*Key found at the last position of the current array*/
        return 1;
    }
    return Recursive_Sequential_Search(a, N - 1, key); /*Search in the remaining N-1 elements*/
}

/*
    Test_Algorithms:use this function to test the performance of a search funtion

    Paramenter explanation:
        a[]: An order list implemented using an array
        N:   number of elements in the array
        key: value to search for
        search_func: pointer to the search function to be tested
    Returns:
        void, but prints the result of the search function.

*/
void Test_Algorithms(int a[], int N, int key, int (*search_func)(int[], int, int)) {
    int K = 10; /*Inital number of repetitions*/
    while (1) {
        start = clock(); /*Record start time*/
        for (int i = 0; i < K; i++) {
            search_func(a, N, key); /*Execute the search function repeatedly*/
        }
        stop = clock();                              /*Record stop time*/
        ticks = stop - start;                        /*total clock ticks for K calls*/
        total_time = (double)ticks / CLOCKS_PER_SEC; /*Convert to seconds*/
        duration = total_time / K;                   /*Average time per call*/

        // if ticks exceed 10 or K exceeds 1 million, break the loop to avoid excessive runtime
        if (ticks > 10 || K > 1000000) {
            break;
        }
        K += 2; /* increase K for the next iteration to get a more accurate measurement for longer
                   durations*/
    }
    // print the results in a formatted way
    printf("%6d %10d %10ld %12.6f %12.8f \n", N, K, (long)ticks, total_time, duration);
}

int main() {
    int N;
    scanf("%d", &N); /*Read the size of the array*/
    int key = N + 1; /*Use a value not in the array*/
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i; /*Fill the array with sequential values*/
    }
    printf("Algorithm                   %6s %10s %10s %12s %12s \n", "N", "K", "Ticks",
           "Total Time", "Duration");
    // Measure the time taken by Iterative Binary Search
    printf("Iterative Binary Search     ");
    Test_Algorithms(a, N, key, Iterative_Binary_Search);

    // Measure the time taken by Recursive Binary Search
    printf("Recursive Binary Search     ");
    Test_Algorithms(a, N, key, Recursive_Binary_Search_Wrapper);

    // Measure the time taken by Iterative Sequential Search
    printf("Iterative Sequential Search ");
    Test_Algorithms(a, N, key, Iterative_Sequential_Search);

    // Measure the time taken by Recursive Sequential Search
    printf("Recursive Sequential Search ");
    Test_Algorithms(a, N, key, Recursive_Sequential_Search);

    return 0;
}
