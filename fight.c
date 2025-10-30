#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a=100;
int c=0;
int b=100;
int d=0;
int coin=0;
void player (void){
	int n;
	printf("Chioce:1.defence 2.lucky hit 3.heal\n");
		scanf("%d",&n);
		switch(n){
		case 1:{
			printf("defence!\n");
			d=d+50;
			break;
		    }
		case 2:{
			printf("lucky hit��  ");
			int random_value=rand()%5;
			if(random_value<3){
				printf("just so so\n");
				if(c>0){
					c=c-10;
					if(c<10){
						a=a+c-10;
						c=0;
					}
				}
				else a=a-10;
			    }
			if(random_value>=3){
				printf("nice shot\n");
				if(c>25){
					a=a+c-25;
					if(c<25){
						a=a+c-25;
						c=0;
					}
				}
				a=a-25;
			    }
			break;
		    }
		case 3:{
			printf("heal!\n");
			b=b+20;
			if(b+20>100){
				b=100;
			} 
			break;
		} 
	    }
}
void monster(void){
	int random_value=rand()%8;
	if(random_value<5&&random_value>1){
		printf("scartch!\n");
		if(d>0){
			d=d-20;
			if(d<10){
				d=0;
				b=b-(10-d);
			}
		}
		else b=b-10;
    }
    if(random_value>=5){
    	printf("crash!\n");
    	if(d>0){
			d=d-20;
			if(d<20){
				d=0;
				b=b-(20-d);
			}
		}
		else b=b-20;
    }
    if(random_value<=1){
    	if(a<85){
    		printf("heal!\n");
		    a=a+15;
		if(a>80){
			a=100;
			} 
		}
    	else {
    		printf("tough skin!\n");
    		c=c+40;
    }
    }
}
int check(void){
	if(b<=0&&a<=0){
		printf("\n");
    	printf("both dead!"); 
    	return 0;
	}
	if(a<=0){
    	printf("\n");
    	printf("win!"); 
    	int random_value=rand()%8;
        if(random_value>5){
        	printf("gain 8 coin\n");
	        coin=coin+8;
        }
        else if(random_value<2){
        	printf("gain 3 coin\n");
	        coin=coin+3;
        }
        else {
        	printf("gain 5 coin\n");
        	coin=coin+5;
		}
		return 0;
	}
	if(b<=0){
		printf("\n");
    	printf("lose!"); 
    	return 0;
	}
}
void print(void){
	printf("Monster:  HP:%d   DEF:%d\n",a,c);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("You:  HP:%d   DEF:%d\n",b,d);
}
void fighting (void){
	printf("you encounter a monster\n");
	while(a>0&&b>0){
		print();
		player();
		monster();
	}
	check();
}
void shop(void){
	printf("WLecome!\n");
	printf("serve yourself\n");
	printf("See you again!\n");
}
int showpath(void){
	int n;
	printf("where did you come from and where will you go:\n1.fight   2.shop   3.back\n");
	scanf("%d",&n);
	switch(n){
		case 1:fighting();
		case 2:shop();
		case 3:break;
	}
}
int main(){
	srand(time(NULL));
	showpath();
	showpath();
}
