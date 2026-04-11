//A+B Search Tree
/*
核心思路：
1. 读入两棵树（存放在结构体数组中）：
   结构体中存储结点的值和父结点的下标索引
   若父结点下标为 -1，则该结点为根结点，记录下来并最终返回
2. 构建两棵树（CreateTree）：
   遍历所有结点，根据 BST 性质（左小右大）将当前结点连接到父结点上
3. 中序遍历两棵树：
   由于是 BST，中序遍历得到的是严格递增的有序序列
4. 双指针法寻找 A + B = N：
   i 指向序列 A 的头部（最小值），j 指向序列 B 的尾部（最大值）
   若和 < N：i++（增大 A 的值）
   若和 > N：j--（减小 B 的值）
   若和 = N：输出，并跳过重复值（i++ 且 j--）
5. 先序遍历输出两棵树
*/
#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct node *Tree;
struct node{
    int key; // 结点存储的数值
    Tree left;  // 左子树指针
    Tree right; // 右子树指针
};

// 辅助结构：用于读入时暂存结点信息和父结点索引
struct input{
    int parent;  // 父结点在数组中的下标
    Tree cell;   // 指向当前结点的指针
};
typedef struct input Input;

//工具函数（堆栈）
void Push(Tree Stack[],Tree node,int* top){ Stack[++(*top)] = node;} // 入栈
Tree Pop(Tree Stack[],int* top){return Stack[(*top)--];}  // 出栈并返回栈顶元素
 
Tree CreateTree(int N);  // 根据输入构建二叉搜索树，返回根结点
int* InOrder(Tree T,int N);  // 中序遍历，返回有序数组
void PreOrder(Tree T,int N);  // 先序遍历并输出结点值

int main (){
    // 读入并生成两棵树
    int N1;
    scanf("%d",&N1);
    Tree A = CreateTree(N1);

    int N2;
    scanf("%d",&N2);
    Tree B = CreateTree(N2);

    // 读入目标和 N
    int N;
    scanf("%d",&N);

    // 中序遍历得到两个有序序列
    int *a = InOrder(A,N1);
    int *b = InOrder(B,N2);

    // (Debug 检查数据传输是否成功)打印前三个数
    //printf("Debug A: %d %d %d\n", a[0], a[1], a[2]);
    //printf("Debug B: %d %d %d\n", b[0], b[1], b[2]);

    // 查找 A + B = N 的所有不重复数对
    int i = 0;    // 指向序列 A 开头（最小值）
    int j = N2-1; // 指向序列 B 末尾（最大值）
    bool flag = false; // 标记是否找到至少一个数对
    while(i<N1&&j>=0){
        long long sum = (long long)a[i] + (long long)b[j];  // 防止溢出选择long long
        if(sum==N) {
            if(!flag){
                printf("true\n");
                flag = true;
            }
            printf("%d = %d + %d\n",N,*(a+i),*(b+j));
            // 跳过重复的值
            do{i++;}while(i<N1&&a[i]==a[i-1]);
            do{j--;} while(j>=0&&b[j]==b[j+1]);
        }
        // 和太小，需要增大 A 的值
        else if(sum<N) do{i++;}while(i<N1&&a[i]==a[i-1]);
        // 和太大，需要减小 B 的值
        else do{j--;} while(j>=0&&b[j]==b[j+1]);
    }
    // 未找到任何数对，输出 false
    if(!flag) printf("false\n");

    //后序遍历
    PreOrder(A,N1);
    PreOrder(B,N2);

    return 0;
}

// CreateTree
// 输入格式：共 N 行，每行两个整数 key 和 parent_index
// parent_index 为 -1 表示根结点
// 根据 BST 性质（左小右大）自动挂载为父结点的左孩子或右孩子
Tree CreateTree(int N){
    Input *a = (Input *)malloc(sizeof(Input) * N);
    Tree root = NULL;

    // 读取所有结点的值和父结点索引，并分配内存
    for(int i=0;i<N;i++){
        a[i].cell = (Tree)malloc(sizeof(struct node));
        scanf("%d %d",&a[i].cell->key,&a[i].parent);
        a[i].cell->left = a[i].cell->right = NULL;

        // 记录根节点
        if (a[i].parent == -1) root = a[i].cell;
    }
    // 结点连接
    for(int i=0;i<N;i++){
        if(a[i].parent!=-1){
            // 当前结点值小于父结点值 → 左孩子，否则 → 右孩子
            if(a[i].cell->key<a[a[i].parent].cell->key) a[a[i].parent].cell->left = a[i].cell;
            else a[a[i].parent].cell->right = a[i].cell;
        }
    }

    //释放空间
    free(a);

    //返回根节点
    return root;
}



// 返回一个包含所有结点值的动态数组，按升序排列

int* InOrder(Tree T,int N){
    //创建堆栈
    Tree *Stack = (Tree *)malloc(sizeof(Tree) * N);
    int top = -1;

    int *result = (int *)malloc(sizeof(int)*N);
    int *s = result; // 用于顺序填充结果数组

    while(top!=-1||T){
        // 一直向左走，将路径上的结点压栈
        while(T){ 
        Push(Stack,T,&top);
        T = T->left;
        }
        // 弹出栈顶结点并访问
        if(top!=-1){
            Tree node = Pop(Stack,&top);
            *(s++) = node->key;  // 存入结果数组
            T = node->right; // 遍历右子树
        }
    }

    free(Stack);
    return result;
}

// 按先序顺序输出结点值，结点间以空格分隔，末尾换行
void PreOrder(Tree T,int N){
    Tree *Stack = (Tree *)malloc(sizeof(Tree) * N);
    int top = -1;
    bool is_first = true; // 控制输出格式，避免行首多余空格

    while(top!=-1||T){
        // 一直向左走，每遇到一个结点就立即输出并压栈
        while(T){ 
            if(is_first) {
                printf("%d",T->key);
                is_first = false;
            }
            else printf(" %d",T->key);
            Push(Stack,T,&top);
            T = T->left;
        }
        // 弹出结点并转向右子树
        if(top!=-1){
            Tree node = Pop(Stack,&top);
            T = node->right; 
        }
    }
    printf("\n");
    free(Stack);
}