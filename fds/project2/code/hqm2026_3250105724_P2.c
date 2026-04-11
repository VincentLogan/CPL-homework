#include <stdio.h>
#include <stdlib.h>
#define EMPTY -2000000005
/* Used for initialization of lastout in inorder_iterator,let the lastout smaller than any value in
the BST*/

#include <time.h>
/*Global Variables used for timing measurements*/
clock_t start, stop, ticks; /* Variables to store clock ticks before/after performance */
double duration;            /* Average time per single search operation */
double total_time;          /* Total time for K repetitions */

// Define the structure of a node of the binary search tree
typedef struct {
    long long int value;       /*The value reserved in the Node*/
    int leftIndex, rightIndex; /*The index of the left and right child of the Node in the array*/
} Node;

// Define the structure of the binary search tree and the index of the root node in the array
typedef Node *BST;
BST BST_A, BST_B;
int BST_A_ROOT, BST_B_ROOT;

// Define a array to store the answers
long long int *answer; /*Initialize the answer array*/
int answerCount = 0;   /*Initialize the count of the answers*/

// Define the structure of the stack used for the traversal of BST
typedef struct stack {
    int data;           /*The index of the node in the BST*/
    struct stack *next; /*The pointer to the next node in the stack*/
} StackNode;
typedef StackNode *head;

int ArraySize = 0; /*Initialize the size of the SearchArray*/

// The declaration of the function prototypes
int buildBST(BST ptrBST, int size);
void preorder_prt(BST ptrBST, int root);
long long int *buildSearchArray(BST ptrBST, int root, int size);
int search(long long int *searchArray, int size, long long int value);
void inorder_iterator(BST ptrBST, int root, long long int key, long long int *searchArray);

/*
    Main function of the program

    Paramenter:
    argv[]: the file test for the program

    The method to run this program(in terminal):
    1.Liunx:    cd the directory containing main.c
                gcc -o main main.c
                ./main test/test1.txt

    2.Windows:  cd the directory containing main.c
                gcc -o main.exe main.c
                main.exe test\test1.txt

    3.MacOS:    cd the directory containing main.c
                clang(/gcc) -o main main.c
                ./main test/test1.txt

    The output:
    1. true/false
    2. the answer(in ascending order)
    3. the preorder travesal of two BST
*/
int main(int arc, char *argv[]) {
    int N, M;                     /*The numbers of the two BST*/
    long long int key;            /*The target value*/
    freopen(argv[1], "r", stdin); /*Open the file provided as inpput*/

    // Build the A_BST
    scanf("%d", &N);                  /*Read the size of the BST_A*/
    BST_A = malloc(sizeof(Node) * N); /*Apply for a large enough space for BST_A*/
    BST_A_ROOT = buildBST(BST_A, N);  /*Build the tree from the input file and store the root*/

    // Build the B_BST
    scanf("%d", &M);                  /*Read the size of the BST_A*/
    BST_B = malloc(sizeof(Node) * M); /*Apply for a large enought space for BST_B*/
    BST_B_ROOT = buildBST(BST_B, M);  /*Build the tree form the input file and store the root*/

    // Build the a ascending array from BST_B for search
    long long int *searchArray = buildSearchArray(BST_B, BST_B_ROOT, M);

    // Declare a array to restore the answer
    answer = malloc(sizeof(long long int) * N); /*number of answers is smaller than size of BST_A*/

    // Read the target value
    scanf("%lld", &key);

    // Use this function to search all answer
    inorder_iterator(BST_A, BST_A_ROOT, key, searchArray);

    // Print the answer
    if (answerCount == 0) {
        printf("false\n"); /*If the answerCount = 0 then this key is no soultion*/
    }
    else {
        printf("true\n");
        for (int i = 0; i < answerCount; i++) {
            printf("%lld = %lld + %lld\n", key, answer[i], key - answer[i]);
        } /*Print the answer as requested*/
    }

    // Print the BST_A BST_B in preorder travesal
    preorder_prt(BST_A, BST_A_ROOT);
    preorder_prt(BST_B, BST_B_ROOT);
    return 0;
}

/*
    buildBST:
    Paramenter explansion:
        ptrBST: the pointer of the BST
        size: the size of the BST
    Returns:
        the index of the root node in the array
*/
int buildBST(BST ptrBST, int size) {
    if (size <= 0) {
        return -1; /*root = -1 mean the tree is empty*/
    }
    int rootIndex = -1;                       /*Initialize the index of the root node*/
    int value;                                /*Declare the value of the node*/
    int *Parent = malloc(sizeof(int) * size); /*Initialize the parent array*/

    // First read the value and the parent of each node, and store them in the array
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &value, &Parent[i]);
        ptrBST[i].value = value;   /*Store the value of the node*/
        ptrBST[i].leftIndex = -1;  /*Initialize the left index*/
        ptrBST[i].rightIndex = -1; /*Initialize the right index*/
    }

    // Second loop: build the tree according to the parent array, and find the root index
    for (int i = 0; i < size; i++) {
        if (Parent[i] == -1) {
            rootIndex = i; /*Store the index of the root node*/
        }
        else if (ptrBST[Parent[i]].value > ptrBST[i].value) { /*smaller than parent*/
            ptrBST[Parent[i]].leftIndex = i; /*Store index of the left child of the parent node*/
        }
        else {
            ptrBST[Parent[i]].rightIndex = i; /*Store index of the right child of the parent node*/
        }
    }
    free(Parent);     /*Free the memory allocated for the parent array*/
    return rootIndex; /*Return the index of the root node*/
}

/*
    preorder_prt:
    Paramenter explansion:
        ptrBST: the pointer of the BST
        root: the index of the BST's root
    Returns:
        None
    print the preorder travesal of the BST, and the value in each node will be separated by a space.
    Since the data size is 2000000, I use an iterative method to avoid stack overflow caused by
    recursion
*/
void preorder_prt(BST ptrBST, int root) {
    if (root == -1) {
        return; /*return when the size of the BST is 0*/
    }
    int flagSpace = 0; /*Used to control the space between values*/
    // Initial the stack for the preorder travesal
    head stack = NULL;
    StackNode *newNode = malloc(sizeof(StackNode));
    newNode->data = root; /*Initial the data of the new node*/
    newNode->next = NULL;
    stack = newNode;

    StackNode *currentNode = stack; /*point to the top of the stack*/

    while (stack != NULL) {  /*Run the loop until the stack is empty*/
        currentNode = stack; /*Update the pointer to the top of the stack*/
        stack = stack->next; /*Update the stack pointer*/

        // Print the value of the top of the stack
        int current = currentNode->data;
        if (flagSpace == 0) { /*The first value will not be separated by a space*/
            printf("%lld", ptrBST[current].value);
            flagSpace = 1; /*Update the flag*/
        }
        else {
            printf(" %lld", ptrBST[current].value);
        }

        free(currentNode); /*Free the top node since it is no longer needed*/

        // Push the right child of the top node into the stack if it exists
        if (ptrBST[current].rightIndex != -1) {
            StackNode *newNode = malloc(sizeof(StackNode));
            newNode->data = ptrBST[current].rightIndex;
            newNode->next = stack;
            stack = newNode;
        }

        // Push the left child of the top node into the stack if it exists
        if (ptrBST[current].leftIndex != -1) {
            StackNode *newNode = malloc(sizeof(StackNode));
            newNode->data = ptrBST[current].leftIndex;
            newNode->next = stack;
            stack = newNode;
        }
    }
    printf("\n");
}

/*
    buildSearchArray:
    Parameter expansion:
        ptrBST: the pointer of the BST
        root: the index of the BST's root
        size: the size of the search array
    Returns:
        A pointer to the search array

    Time complexity of this function is O(N)

    If the member of BST_B is stored in asscending order,then the search algorithm will be O(N)
    which is not efficient enough for the data size of 2000000. So I build a search array for binary
    search, and the time complexity of the search algorithm will be O(logN).

    Build a search array containing all unique asscending values in the BST in inorder traversal.
    Since the data size is 2000000, I use an iterative method to avoid stack overflow caused by
    recursion. And the variable lastOut is used to avoid storing duplicate values in searcharray
*/
long long int *buildSearchArray(BST ptrBST, int root, int size) {
    if (root == -1) { /*If BST is empty, return NULL*/
        return NULL;
    }

    // Initial the search array
    long long int *searchArray = malloc(sizeof(long long int) * size);
    int index = 0;                 /*Initial index*/
    long long int lastOut = EMPTY; /*Initial lastout value by EMPTY which beyond the value range*/

    // inorder iterator
    // Initial the stack for the inorder travesal
    head stack = NULL;
    int current = root;                      /*Initial the current node*/
    StackNode *currentNode;                  /*Used to store the current node in the stack*/
    while (current != -1 || stack != NULL) { /*Run the loop until the stack is empty*/
        while (current != -1) {              /*Run until the node have left child*/
            StackNode *newNode = malloc(sizeof(StackNode)); /*Store currentNode into stack*/
            newNode->data = current;
            newNode->next = stack;
            stack = newNode;
            current = ptrBST[current].leftIndex;
        }

        // Pop the top of stack
        currentNode = stack;
        stack = stack->next;

        // Store the value of the top of the stack into searcharry
        current = currentNode->data;
        if (ptrBST[current].value != lastOut) { /* Ignore this value when duplicated*/
            searchArray[index++] = ptrBST[current].value;
            lastOut = ptrBST[current].value; /*Update the lastout pop from the stack*/
        }
        free(currentNode);
        // turn to right child tree
        current = ptrBST[current].rightIndex;
    }
    // Store the number of different elements
    ArraySize = index;
    return searchArray; /*Return the pointer to the search array*/
}

/*
    search
    Parameter expansion:
        searchArray: the search array built from BST_B
        size: the size of the search array
        value: the value to be searched
    Returns:
        1 if the value is found in the search array, otherwise return 0
    total time complexity of this function is O(logN).
    Use binary search to search the value in the search array
*/
int search(long long int *searchArray, int size, long long int value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;    /*Calculate the middle index*/
        if (searchArray[mid] == value) { /*key found*/
            return 1;
        }
        else if (searchArray[mid] < value) { /*key lies in the left half*/
            left = mid + 1;
        }
        else { /*key lies in the right half*/
            right = mid - 1;
        }
    }
    return 0; /*key not found*/
}

/*
    inorder_iterator
    Parameter expansion:
        ptrBST: the BST structure
        root: the root node index
        key: the target sum
        searchArray: the search array built from BST_B
    Returns:
        None

    total time complexity of this function is O(NlogN).

    Use inorder iterator to traverse the BST_A, and for each value in the BST_A, search the
    complementary value in the searchArray and if found, store it in the answer array.
*/
void inorder_iterator(BST ptrBST, int root, long long int key, long long int *searchArray) {
    if (root == -1) { /*Return if the BST is empty*/
        return;
    }
    // Avoid the duplicate value in the BST_A,use the variable lastout to store the last value
    // output from the stack, and ignore the value when it's same to latout
    long long int lastout = EMPTY; /*Initialize the lastout variable*/

    // Initial the stack for the inorder travesal
    head stack = NULL;
    int current = root;
    StackNode *currentNode;

    while (current != -1 || stack != NULL) {
        while (current != -1) { /*Run until the node have no left child*/
            StackNode *newNode = malloc(sizeof(StackNode)); /*store the current node in the stack*/
            newNode->data = current;
            newNode->next = stack;
            stack = newNode;
            current = ptrBST[current].leftIndex;
        }

        // Pop the top of stack
        currentNode = stack;
        stack = stack->next;

        // check value of the top of the stack, and search complementary value in the searchArray
        current = currentNode->data;
        if (ptrBST[current].value != lastout) { /* check if it not a duplicate value*/
            long long int complement = key - ptrBST[current].value;
            if (search(searchArray, ArraySize,
                       complement)) { /*If the complementary value is found*/
                answer[answerCount++] =
                    ptrBST[current].value; /*store the value in the answer array*/
            }
            lastout = ptrBST[current].value; /*Update the lastout variable*/
        }
        free(currentNode);                    /*free the memory allocated for the stack node*/
        current = ptrBST[current].rightIndex; /*Turn to the right child*/
    }
}