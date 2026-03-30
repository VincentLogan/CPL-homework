/*王文浩 3250105724 No.01*/
#include <stdio.h>
#include <stdlib.h>

// 定义哈希表，来记录每个key出现的次数，初设为0
int Harsh1[20005] = {0};

// 定义双向链表节点
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

// 定义第一个Historical Acess Queue
typedef struct Access {
    int capacity;
    Node *head;
    Node *tail;
} Access;

// 定义Cache Queue
typedef struct Cache {
    int capacity;
    Node *head;
    Node *tail;
} Cache;

typedef Node *ptrNode;

// 在指定的Queue的tail插入一个节点，并用哈希表对应
void insertTail(Node *head, Node **tail, int key, ptrNode *Harsh);

// 删除指定的Queue的头节点，并更新哈希表映射
void removeHead(Node *head, Node **tail, ptrNode *Harsh);

// 将指定的节点移动到Queue的tail，并更新哈希表映射
void moveToTail(Node *head, Node **tail, int key, ptrNode *Harsh);

// 删除指定的节点，并更新哈希表映射
void removeNode(Node *head, Node **tail, int key, ptrNode *Harsh);

// 打印Cache Queue
void printCache(Cache *cache);

// 打印Historical Access Queue
void printAccess(Access *access);

int main() {
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);

    // 初始化access
    Access access;
    ptrNode head = (ptrNode)malloc(sizeof(Node));
    head->next = NULL;
    access.head = head;
    access.tail = head;
    access.capacity = 0;

    // 初始化cache
    Cache cache;
    head = (ptrNode)malloc(sizeof(Node));
    head->next = NULL;
    cache.tail = head;
    cache.head = head;
    cache.capacity = 0;

    // 初始化哈希表映射
    ptrNode access_Harsh[20005] = {NULL};
    ptrNode cache_Harsh[20005] = {NULL};

    int key;
    for (int i = 0; i < m; i++) {
        scanf("%d", &key);
        Harsh1[key]++;

        // key第一次出现，加入access
        if (Harsh1[key] == 1) {
            // access未满，直接插入
            if (access.capacity < n) {
                insertTail(access.head, &access.tail, key, access_Harsh);
                access.capacity++;
            }
            // access已满，删除头节点，即最久没访问的，插入新节点
            else {
                removeHead(access.head, &access.tail, access_Harsh);
                insertTail(access.head, &access.tail, key, access_Harsh);
            }
        }

        // 不是第一次出现但不用存入cache，更新access位置
        else if (Harsh1[key] < k) {
            moveToTail(access.head, &access.tail, key, access_Harsh);
        }

        // key出现次数达到k，加入cache
        else if (Harsh1[key] == k) {
            removeNode(access.head, &access.tail, key, access_Harsh);
            access.capacity--;

            // cache未满，直接插入
            if (cache.capacity < n) {
                insertTail(cache.head, &cache.tail, key, cache_Harsh);
                cache.capacity++;
            }

            // cache已满，删除头节点，即最久没访问的，插入新节点
            else {
                removeHead(cache.head, &cache.tail, cache_Harsh);
                insertTail(cache.head, &cache.tail, key, cache_Harsh);
            }
        }

        // key出现次数超过k，更新cache位置
        else if (Harsh1[key] > k) {
            moveToTail(cache.head, &cache.tail, key, cache_Harsh);
        }
    }
    // 最后打印access和cache
    printAccess(&access);
    printCache(&cache);
    return 0;
}

void insertTail(Node *head, Node **tail, int key, ptrNode *Harsh) {
    ptrNode node = (ptrNode)malloc(sizeof(Node));
    node->value = key;
    node->next = NULL;
    node->prev = *tail;
    (*tail)->next = node;
    *tail = node;
    Harsh[key] = node;
}

void removeHead(Node *head, Node **tail, ptrNode *Harsh) {
    if (head->next == NULL) {
        return;
    }
    ptrNode toDelete = head->next;
    Harsh1[toDelete->value] = 0;
    Harsh[toDelete->value] = NULL;

    head->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = head;
    }
    else {
        *tail = head;
    }
    free(toDelete);
}

void moveToTail(Node *head, Node **tail, int key, ptrNode *Harsh) {
    ptrNode node = Harsh[key];
    if (node == *tail) {
        return;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    else {
        head->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    else {
        *tail = node->prev;
    }
    node->prev = *tail;
    node->next = NULL;
    (*tail)->next = node;
    *tail = node;
}

void removeNode(Node *head, Node **tail, int key, ptrNode *Harsh) {
    ptrNode node = Harsh[key];
    if (node == NULL) {
        return;
    }
    Harsh[node->value] = NULL;

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    else {
        head->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    else {
        *tail = node->prev;
    }
    free(node);
}

void printCache(Cache *cache) {
    if (cache->head->next == NULL) {
        printf("-\n");
        return;
    }
    ptrNode temp = cache->head->next;
    int flag = 0;
    while (temp != NULL) {
        if (flag == 0) {
            printf("%d", temp->value);
            flag = 1;
        }
        else {
            printf(" %d", temp->value);
        }
        temp = temp->next;
    }
    printf("\n");
}

void printAccess(Access *access) {
    if (access->head->next == NULL) {
        printf("-\n");
        return;
    }
    ptrNode temp = access->head->next;
    int flag = 0;
    while (temp != NULL) {
        if (flag == 0) {
            printf("%d", temp->value);
            flag = 1;
        }
        else {
            printf(" %d", temp->value);
        }
        temp = temp->next;
    }
    printf("\n");
}