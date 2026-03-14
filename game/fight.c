#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_monster(i)  100+i*20
#define MAX_player(stone,grade)  100+stone*10+grade*20
int monster1_hp=100;//狮虎兽 
int monster1_defence=0;
int player_hp=100;//玩家 
int player_defence=0;
int boss_hp=500;//死灵王 
int boss_defence=0;
int coin=1000000000;//基础金币 
int i=0,muscle=0,stone=0,poison=0;//怪物和人物的buff 
int grade=0,e=10,xp=0;//等级和经验 
int r=0;//逃跑次数 
int old_muscle,old_stone,old_poison;
int monster1_hurt1=10,monster_hurt2=20;
int player_hurt1(void){return 20+muscle*10+grade*10;}
int player_hurt2(void){return 35+muscle*10+grade*10;}
int boss_hurt1=50,boss_hurt2=75,boss_hurt3=60,boss_hurt4=85;
int monster_damaged;
int boss_damaged;
void grades(void){//等级加20血加10伤 
	if(xp>=e){
		printf("level up!\n");
		grade++;
		xp=xp-e;
		e=e+5;
	}
	else{
		printf("%d / %d\n",xp,e);
	}
}
void reset(void){//在每次战斗开始前重置数值 
    monster1_hp = MAX_monster(i);
    monster1_defence = 0;
    player_hp = MAX_player(stone,grade);
    player_defence = 0;
}
void boss1(void){
	int random_value=rand()%100;
    	if(random_value<50){
    		printf("soul roar!\n");
    		if(player_defence>0){
			player_defence=player_defence-boss_hurt1;
			if(player_defence<0){
				player_defence=0;
				player_hp=player_hp-(boss_hurt1-player_defence);
			}
		    }
		    else player_hp=player_hp-boss_hurt1;
		}
		else if(random_value>=50&&random_value<85){
			printf("death grasp!\n");
    		if(player_defence>0){
			player_defence=player_defence-boss_hurt2;
			if(player_defence<0){
				player_defence=0;
				player_hp=player_hp-(boss_hurt2-player_defence);
			}
		    }
		    else player_hp=player_hp-boss_hurt2;
		}
		else{
			if(boss_hp<500-50){
    		printf("the corpse is moving!\n");
		    boss_hp=boss_hp+50;
		    if(boss_hp>500-50&&boss_damaged==0){
			boss_hp=500;
			} 
		    }
    	    else {
    		printf("undead armor!\n");
    		boss_defence=boss_defence+60;
            }
		}
}
void ETV(void){//彩蛋 0 
	int n;
	printf("where did you come from and where will you go...\n");
	scanf("%d",&n);
	switch(n){
		case 0:{
			printf("yes,everything will back to zero someday\n");
			break;
		}
		default:{
			printf("how do you value lives,hero?\n");
			break;
		}
	}
	printf("you wake up\nwhat a nightmare\n");
}
void boss2(void){
	printf("surroundings is getting colder...\n");
	int random_value=rand()%100;
    	if(random_value<55){
    		printf("echo of madness!\n");
    		if(player_defence>0){
			player_defence=player_defence-boss_hurt3;
			if(player_defence<0){
				player_defence=0;
				player_hp=player_hp-(boss_hurt3-player_defence);
			}
		    }
		    else player_hp=player_hp-boss_hurt3;
		}
		else if(random_value>=55&&random_value<95){
			printf("gaze of the abyss!\n");
    		if(player_defence>0){
			player_defence=player_defence-boss_hurt4;
			if(player_defence<0){
				player_defence=0;
				player_hp=player_hp-(boss_hurt4-player_defence);
			}
		    }
		    else player_hp=player_hp-boss_hurt4;
		}
		else{
			printf("embrace the void\n");
			printf("you hear a gentle voice\nit seems come from void\nyou fall asleep soundly\n");
			ETV();
		}
}
void boss(void){//一阶段尸体在动40，亡灵铠甲60，灵魂尖啸50，死亡之握75；二阶段狂乱回响60，深渊凝视85，拥抱虚空（彩蛋） 
	int p=0,q=0;
	if(q==0){
		printf("dark sweep across the battlefield\n");
		q=1;
	}
    if(boss_hp>=200){boss1(); }
	else{
		if(p==0){
		    printf("surroundings is getting colder...\n");
		    p=1;
		}
	    boss2(); }
}
void player (void){//回血20，加盾50，一般幸运击20，好砍兄弟好砍35，毒药30
	int n;
	printf("Choice:1.defence 2.lucky hit 3.heal ");
	if(poison==0){
		printf("\n");
	}
	else{
		printf("4.poison\n");
	}
		scanf("%d",&n);
		switch(n){
		case 1:{
			printf("defence！\n");
			player_defence=player_defence+50;
			break;
		    }
		case 2:{
			printf("lucky hit！  ");
			int random_value=rand()%5;
			if(random_value<3){
				printf("just so so\n");
				if(monster1_defence>player_hurt1()){
					monster1_defence=monster1_defence-player_hurt1();
				    }
				else if(monster1_defence<player_hurt1()&&monster1_defence>0){
						monster1_defence=0;
						monster1_hp=monster1_hp-(player_hurt1()-monster1_defence);
					}
				
			    else monster1_hp=monster1_hp-player_hurt1();
			    }
			if(random_value>=3){
				printf("nice shot\n");
				if(monster1_defence>player_hurt2()){
					monster1_defence=monster1_defence-player_hurt2();
				    }
				else if(monster1_defence<player_hurt2()&&monster1_defence>0){
						monster1_defence=0;
						monster1_hp=monster1_hp-(player_hurt2()-monster1_defence);
					}
				else monster1_hp=monster1_hp-player_hurt2();
			    }
			    monster_damaged=1;
			break;
		    }
		case 3:{
			printf("heal！\n");
			player_hp=player_hp+20; 
			if(player_hp>MAX_player(stone,grade)){
				player_hp=MAX_player(stone,grade);
			} 
			break;
		}
		case 4:{
			printf("you use the poison,\nwhat a cruel man");
			monster1_hp=monster1_hp-30;
			break;
		}
		default: {
            printf("invalid choice\n");
            break;
        }
	    }
}
void player1(void){//回血20，加盾50，一般幸运击10，好砍兄弟好砍25，毒药30
	int n;
	printf("Choice:1.defence 2.lucky hit 3.heal ");
	if(poison==0){
		printf("\n");
	}
	else{
		printf("4.poison\n");
	}
		scanf("%d",&n);
		switch(n){
		case 1:{
			printf("defence！\n");
			player_defence=player_defence+50;
			break;
		    }
		case 2:{
			printf("lucky hit！  ");
			int random_value=rand()%5;
			if(random_value<3){
				printf("just so so\n");
				if(boss_defence>(10+muscle*10+grade*10)){
					boss_defence=boss_defence-(10+muscle*10+grade*10);
				    }
				else if(boss_defence<(10+muscle*10+grade*10)&&boss_defence>0){
						boss_defence=0;
						boss_hp=boss_hp-((10+muscle*10+grade*10)-boss_defence);
					}
				
			    else boss_hp=boss_hp-(10+muscle*10+grade*10);
			    }
			if(random_value>=3){
				printf("nice shot\n");
				if(boss_defence>(25+muscle*10+grade*10)){
					boss_defence=boss_defence-(25+muscle*10+grade*10);
				    }
				else if(boss_defence<(25+muscle*10+grade*10)&&boss_defence>0){
						boss_defence=0;
						boss_hp=boss_hp-((25+muscle*10+grade*10)-boss_defence);
					}
				else boss_hp=boss_hp-(25+muscle*10+grade*10);
			    }
			    boss_damaged=1;
			break;
		    }
		case 3:{
			printf("heal！\n");
			player_hp=player_hp+20; 
			if(player_hp>MAX_player(stone,grade)){
				player_hp=MAX_player(stone,grade);
			} 
			break;
		}
		case 4:{
			printf("you use the poison,\nwhat a cruel man");
			boss_hp=boss_hp-30;
			break;
		}
		default: {
            printf("invalid choice\n");
            break;
        }
	    }
}
void monster1(void){//回血15，皮糙肉厚40，抓挠10，冲撞20
	int random_value=rand()%8;
	if(random_value<5&&random_value>1){
		printf("scratch！\n");
		if(player_defence>0){
			player_defence=player_defence-monster1_hurt1;
			if(player_defence<0){
				player_defence=0;
				player_hp=player_hp-(monster1_hurt1-player_defence);
			}
		}
		else player_hp=player_hp-monster1_hurt1;
    }
    if(random_value>=5){
    	printf("crash！\n");
    	if(player_defence>0){
			player_defence=player_defence-monster_hurt2;
			if(player_defence<0){
				player_defence=0;
				player_hp=player_hp-(monster_hurt2-player_defence);
			}
		}
		else player_hp=player_hp-monster_hurt2;
    }
    if(random_value<=1){
    	if(monster1_hp<MAX_monster(i)-15){
    		printf("heal！\n");
		    monster1_hp=MAX_monster(i)+15;
		if(monster1_hp>MAX_monster(i)&&monster_damaged==0){
			monster1_hp=MAX_monster(i);
			} 
			else monster1_hp=monster1_hp+15;
		}
    	else {
    		printf("tough skin！\n");
    		monster1_defence=monster1_defence+40;
    }
    }
}
int check1(void){// 不同结局，为下一周目埋下伏笔 
	if(boss_hp<=0&&player_hp<=0){
		printf("\n");
    	printf("you both die in the battle\nwho will remember the thrill story\n"); 
    	xp=xp+5;
    	return 0;
	}
	if(boss_hp<=0){
    	printf("\n");
    	printf("you kill the undead\nbut\nthis is the ending?\n"); 
	}
	if(player_hp<=0){
		printf("\n");
    	printf("sorry you lose\nyou are not who I am waiting\n"); 
    	xp=xp+3;
    	return 0;
	}
}
int check(void){//胜利掉落3、5、8金币
	if(monster1_hp<=0&&player_hp<=0){
		printf("\n");
    	printf("both dead!\n"); 
    	xp=xp+5;
    	return 0;
	}
	if(monster1_hp<=0){
    	printf("\n");
    	printf("win!\n"); 
    	int random_value=rand()%8;
        if(random_value>5){
        	printf("gain 8 coin\n");
	        coin=coin+8;
	        xp=xp+10;
	        return 0;
        }
        else if(random_value<2){
        	printf("gain 3 coin\n");
        	coin=coin+3;
        	xp=xp+10;
	        return 0;
        }
        else {
        	printf("gain 5 coin\n");
        	coin=coin+5;
        	xp=xp+10;
        	return 0;
		}
	}
	if(player_hp<=0){
		printf("\n");
    	printf("lose!\n"); 
    	xp=xp+3;
    	return 0;
	}
}
void print1(void){//boss战用 
	printf("Boss: HP:%d   DEF:%d\n",boss_hp,boss_defence);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("You: HP:%d   DEF:%d   Poison:%d\n",player_hp,player_defence,poison);
}
void print(void){//野怪用 
	printf("Liger: HP:%d   DEF:%d\n",monster1_hp,monster1_defence);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("You: Level:%d HP:%d   DEF:%d   Poison:%d\n",grade,player_hp,player_defence,poison);
}
void fighting (void){//野怪战斗 
	reset(); 
	printf("you encounter a monster\n");
	while(monster1_hp>0&&player_hp>0){
		print();
		player();
		monster1();
	}
	check();
	grades();
	i++;
}
int shop(void){//肌肉魔咒加10伤，磐石魔咒加10血，毒药，leaf（小彩蛋）
	old_muscle=muscle;
	old_stone=stone;
	old_poison=poison;
	int n;
	printf("WLecome!\n");
	printf("serve yourself:\n1.muscle charm(hurt +10)/5coin  2.stone charm(hp+10)/8coin  3.poison(unknown)/10coin  4.leave\n");
	printf("coin:%d\n",coin); 
	scanf("%d",&n);
	switch(n){
		case 1:{
			printf("your muscle is strenghtened\n");
			coin=coin-5;
			muscle++;
			break;
		}
		case 2:{
			printf("your skin gets tougher\n");
			coin=coin-8;
			stone++;
			break;
		}
		case 3:{
			printf("you get a bottle of poison,\nyou will not want to taste it\n");
			coin=coin-10;
			poison++;
			break;
		}
		case 4:{
			printf("you want a leaf?\nthat strange,\nbut we have it\n");
			printf("you get a leaf with nothing lose\n");
			break;
		}
		default: {
            printf("invalid choice\n");
            break;
        }
	}
	printf("See you again!\n");
		if(coin<0){
			printf("hey!\nwe do not welcome beggar\nreturn what you got\n");
			printf("you lose what you bought\n");
			muscle=old_muscle;
	        stone=old_stone;
	        poison=old_poison;
	}
	return 0;
}
int showpath(void){//路径选择 逃离彩蛋 
	int n;
	printf("where did you come from and where will you go:\n1.fight   2.shop   3.back\n");
	scanf("%d",&n);
	switch(n){
		case 1:{
			fighting();
			break;
		}
		case 2:{
			shop();
			break;
		}
		case 3:{
			printf("you back to where you came from\nmany things happen after that\nbut they cannot bother you\n"); 
			printf("another young man walks into a forest\nfrankly\nhe gets lost\nwhat is waiting for him?\n");
			r++;
			break;
		}
		default: {
            printf("invalid choice\n");
            break;
        }
	}
	return 0;
}
int endingpath(void){//终末路（boss战） 
	printf("dark sweep across the battlefield\n");
	while(boss_hp>0&&player_hp>0){
		print1();
		player1();
	    boss();
	}
	check1();
	return 0;
}
int main(){
	int k; 
	srand(time(NULL));
	printf("you walk into a forest\nfrankly\nyou get lost\nwhat is waiting for you?\n");
	for(k=0;k<=30;k++){
		printf("a old man(?) come and say:\n");
		showpath();
	}
	if(r==30){
		printf("what the f*ck are you going to?\nback home\nfor the sake of god\n");
	}
	else {
		printf("are you ready?\nanyway,wheather you prepare or not\nwe gonna go\n");
	    endingpath();
	}
	
	return 0;
}
