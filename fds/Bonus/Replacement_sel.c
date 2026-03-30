#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct queue {
    struct Node *head;
    struct Node *tail;
};

typedef struct Node *ptrNode;
typedef struct queue *Run;
Run *run;
int runCount;

typedef struct minPQ {
    int *data;
    int *cache;
    int dataSize;
    int cacheSize;
    int lastout;
} *Memory;
Memory memory;

int isEmpty(Memory memory);
int isFull(Memory memory);
void insert(int value);
void popMin();
void swim(int *minPQ, int index, int size);
void sink(int *minPQ, int index, int size);
Run Run_init();
int Run_isEmpty(Run run);
void Run_enqueue(Run run, int value);
void Run_Prt(Run run);

int main() {
    int N, M;
    int value;
    scanf("%d %d", &N, &M);
    run = malloc((N / M + 1) * sizeof(Run));
    for (int i = 0; i < N / M + 1; i++) {
        run[i] = Run_init();
    }
    runCount = 0;
    memory = malloc(sizeof(struct minPQ));
    memory->data = malloc(sizeof(int) * M);
    memory->cache = malloc(sizeof(int) * M);
    memory->dataSize = 0;
    memory->cacheSize = 0;
    memory->lastout = -1;

    for (int i = 0; i < M && i < N; i++) {
        scanf("%d", &value);
        memory->data[i] = value;
        memory->dataSize++;
        swim(memory->data, memory->dataSize - 1, memory->dataSize);
    }

    for (int i = 0; i < N - M; i++) {
        scanf("%d", &value);
        insert(value);
    }

    while (memory->dataSize) {
        popMin();
    }
    if (memory->cacheSize) {
        runCount++;
        int *temp;
        temp = memory->data;
        memory->data = memory->cache;
        memory->cache = temp;
        memory->dataSize = memory->cacheSize;
        memory->cacheSize = 0;
        memory->lastout = -1;
        while (memory->dataSize) {
            popMin();
        }
    }

    for (int i = 0; i <= runCount; i++) {
        Run_Prt(run[i]);
    }

    return 0;
}

void insert(int value) {
    if (memory->dataSize == 0 && memory->cacheSize > 0) {
        int *temp;
        temp = memory->data;
        memory->data = memory->cache;
        memory->cache = temp;
        memory->dataSize = memory->cacheSize;
        memory->cacheSize = 0;
        memory->lastout = -1;
        runCount++;
    }
    popMin();
    if (value >= memory->lastout) {
        memory->data[memory->dataSize] = value;
        swim(memory->data, memory->dataSize, memory->dataSize + 1);
        memory->dataSize++;
    }
    else {
        memory->cache[memory->cacheSize] = value;
        swim(memory->cache, memory->cacheSize, memory->cacheSize + 1);
        memory->cacheSize++;
    }
}

void popMin() {
    if (memory->dataSize == 0) {
        return;
    }
    int minValue = memory->data[0];
    memory->lastout = minValue;
    Run_enqueue(run[runCount], minValue);
    memory->data[0] = memory->data[memory->dataSize - 1];
    memory->dataSize--;
    if (memory->dataSize > 0) {
        sink(memory->data, 0, memory->dataSize);
    }
}

void swim(int *minPQ, int index, int size) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (minPQ[index] < minPQ[parent]) {
            int temp = minPQ[index];
            minPQ[index] = minPQ[parent];
            minPQ[parent] = temp;
            index = parent;
        }
        else {
            break;
        }
    }
}

void sink(int *minPQ, int index, int size) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < size && minPQ[left] < minPQ[smallest]) {
            smallest = left;
        }
        if (right < size && minPQ[right] < minPQ[smallest]) {
            smallest = right;
        }
        if (smallest == index) {
            break;
        }
        int temp = minPQ[index];
        minPQ[index] = minPQ[smallest];
        minPQ[smallest] = temp;
        index = smallest;
    }
}

Run Run_init() {
    Run run = malloc(sizeof(struct queue));
    run->head = NULL;
    run->tail = NULL;
    return run;
}

int Run_isEmpty(Run run) { return run->head == NULL; }

void Run_enqueue(Run run, int value) {
    ptrNode newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (Run_isEmpty(run)) {
        run->head = newNode;
        run->tail = newNode;
    }
    else {
        run->tail->next = newNode;
        run->tail = newNode;
    }
}

void Run_Prt(Run run) {
    int flag = 0;
    ptrNode current = run->head;
    while (current != NULL) {
        if (flag == 0) {
            printf("%d", current->data);
            flag = 1;
        }
        else {
            printf(" %d", current->data);
        }
        current = current->next;
    }
    printf("\n");
}