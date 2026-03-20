#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//algorithm1:brute-force 
//Time Complexity:  O(N squared) 
//check all possible pairs of elements and use two nested loops.
int algorithm1(int arr[],int N,int target,int *a,int *b)
{
	for(int i =0;i<N;i++){ // outer loop	
		for(int j=i+1;j<N;j++){ // inner loop
			if(arr[i]+arr[j]==target){ // judgement 
				*a=arr[i];//store one addend
				*b=arr[j];//store another addend
				return 1;//1 represents we get what we want.	
			}
		}				
	}
	return 0;//0 represents we failed to find a,b s.t. a+b=target.
}
//the thought is little yet the consumption is huge,especially on a large input.

//Necessary for the qsort function.
//Confirm the rule of compare.
int  my_compare(const void  *a,const void *b){ // here most be const void ,it is a requirement of qsort function
	return *(int *)a - *(int *)b;
}

//algorithm2:sort the array first,then search by two pointers.
//Time Complexity O(NlogN)
//Sorting uses the qsort function by C standard library
int algorithm2(int arr[],int N,int target,int *a,int*b)
{
	qsort(arr,N,sizeof(int),my_compare);	
	int left,right; // two indexs for searching.
	left=0;//initial element(the smallest one)
 	right = N-1;// last element(also the largest one)
	while(left<right){//judging if it's repetitive.
		int sum= arr[left] + arr[right];//calculating temp sum.
		if(sum == target){
			*a = arr[left];//store one addend
			*b = arr[right];//store another addend
			return 1;//representing a,b is found.
		}else if(sum<target){
		left++;  //make the small one larger. 
		}else{
		right--; //make the big one smaller.
		}
	}
	return 0;//representing there isn't such a,b.
}

// Using this function to generate a random array between 1 and V
// S is the array,N represents how many numbers are in the array,V determines the range of the elements.
void generatearray(int S[],int N,int V){
			if(RAND_MAX>40000){
				for(int i =0;i<N;i++){
					S[i]=rand() %V +1;
				}
			}//if the range of random number is big enough,use it directly.
			else{
				for(int i =0;i<N;i++){
					S[i]=((rand()<<15)|rand()) %V +1;
				}
			}//if not , we shall connect two random number in order to produce what we want.
}

//Used for counting the time.
clock_t start,stop;
double duration;

void MeasureTime(int N,int T);//prototype,detailed implement are behind.

int main(){
	srand(42); 
	//set pseudo random seed.
	// as 42 is a certain number,everytime the program run, we will get the same array.
	// but for a single time,we can treat it as random.
	//N is small ,run for several times 
	MeasureTime(1000,1000);
	MeasureTime(5000,1000);
	MeasureTime(10000,1000);
	//N is huge,run for 10 times in a bid to eliminate the affect of random number.
	MeasureTime(20000,10);
	MeasureTime(40000,10);
	MeasureTime(60000,10);
	MeasureTime(80000,10);
	MeasureTime(100000,10);
}

void MeasureTime(int N,int T){
	int  *s =(int *)malloc(sizeof(int)*N);
	int x,y;
	int *a,*b;
	a=&x,b=&y;//confirming pointer a ,b is legal.
	int total=0;//counting total ticks.
	double average,sum;//counting the average running time and the total running time.
	sum=0;
	for(int i =1;i<=T;i++){//run for T times.
    generatearray(s,N,N);
	int target = rand()<<15|rand();
	start=clock();
	algorithm1(s,N,target,a,b);
	stop = clock();
	duration = ((double)(stop-start))/CLOCKS_PER_SEC;
	//The CLK_TCK is not used anymore,so here we use 
	//CLOCKS_PER_SEC,which behaviours samely.
	sum+=duration;//counting the total time.
	total+=(int)(stop-start);//counting the total ticks.
	}
	average = sum/T;//calculating the average time for a single run.
	printf("%d %f %f\n",total,sum,average);//print out the results.

	total =0;
	sum =0;
 	average=0;
	//reset all these variables for algorithm2.
	for(int i =1;i<=T;i++){
    generatearray(s,N,N);
	int target = rand()<<15|rand();
	start=clock();
	algorithm2(s,N,target,a,b);
	stop = clock();
	duration = ((double)(stop-start))/CLOCKS_PER_SEC;	
	sum+=duration;
	total+=(int)(stop-start);
	}
	average = sum/T;
	printf("%d %f %f\n",total,sum,average);
}
