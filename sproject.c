#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    int Life=5 ;
    int Money=0;
    int Key=0 ; 
char recovery (char I);
void display_card(char a[20][20]);
void display_LifeMoney(int Life,int Money,int Key);
int main()
{   
    int character[1][2]={0,0}; //棋子坐标，显示棋子的位置
    
	printf(" 0 : grass 草\n 1 : a flower 一朵花\n 2 : an obstacle: a tree 障碍物：树\n 3 : an obstacle: a rock 障碍物：岩石\n 4 : an object: a key 一个物品：一把钥匙\n 5 : an object: a gold coin 一个物品：金币\n 6 : an object: a padlock 一个物品：挂锁\n 7 : a trap 一个陷阱\n 8 : a monster 一个怪物\n");
	char init_card[20][20];//将所有20x20的元素 初始化为草	
	for(int i=0;i<=19;i++){
		for(int j=0;j<=19;j++){
           init_card[i][j]='0';            							
		}
	}	
    int a,b; //用随机函数设置不同的障碍，以及物品；以便使每局的元素位置不同
    srand(time(NULL));
	for(int i=1;i<=6;i++){        //i代表生成同一个物品的多个数目，但并不等于生成的数目，因为即使是随机函数在多次运用下也会有数据覆盖的情况。通过对i数目的改变，控制该物品变量的发生概率  
    a=(rand()%21)-1;
	b=(rand()%21)-1;  
	init_card[a][b]='1';
	}
	for(int i=1;i<=9;i++){         // 树大约出现的次数；
    a=(rand()%21)-1;
	b=(rand()%21)-1;
    if((a==1&&b==0)&&(b==1&&a==0)){     //避免起步时 卡死在原地；下同
		i=i-1;
		}
	init_card[a][b]='2';	
	}
    for(int i=1;i<=5;i++){          //岩石大约出现的次数
    a=(rand()%21)-1;
	b=(rand()%21)-1;
    if((a==1&&b==0)&&(b==1&&a==0)){
		i=i-1;
		}
	init_card[a][b]='3';	
	}
    for(int i=1;i<=8;i++){          //钥匙大约出现的次数
    a=(rand()%21)-1;
	b=(rand()%21)-1;
	init_card[a][b]='4';	
	}
    for(int i=1;i<=20;i++){          //金币大约出现的次数
    a=(rand()%21)-1;
	b=(rand()%21)-1;
	init_card[a][b]='5';	
	} 
    for(int i=1;i<=5;i++){          //挂锁大约出现的次数
    a=(rand()%21)-1;
	b=(rand()%21)-1;
	init_card[a][b]='6';	
	}
    int degree;
    printf("请输入游戏难度，困难输入30，适中输入20，简易输入4\n也可自行调节游戏难度，输入数字越大难度越大,但不可超过100\n");//游戏难度即：陷阱数，怪物数。
	scanf("%d",&degree);
	for(int i=1;i<=(degree-2);i++){          
    a=(rand()%21)-1;
	b=(rand()%21)-1;
	if((a==1&&b==0)&&(b==1&&a==0)){
		i=i-1;
   }
	init_card[a][b]='7';	
	}	
    for(int i=1;i<=degree;i++){          
    a=(rand()%21)-1;
	b=(rand()%21)-1;
    if((a==1&&b==0)&&(b==1&&a==0)){
		i=i-1;
   }
	init_card[a][b]='8';
   }	
     init_card[0][0]='x';  //棋子初始位置
	
	display_card(init_card);
   int abs=0;       //此处为第二阶段的开始，循环执行直到退出游戏,abs横坐标，ord纵坐标
	int ord=0;   
    int move;
   int c,d;     //存储前一个变量的位置   
   char I;       //存储前一个变量              
   printf("请输入数字\n ");
   printf("2=向下 4=向左 6=向右 8=向上 0=退出游戏\n");  
   scanf("%d",&move);
	if(move==0)
	{printf("game over");}
    while(move!=0&&Life!=0&&Money!=10){
    if(move==2)
{
	system("cls");
printf("2=向下 4=向左 6=向右 8=向上 0=退出游戏\n");
	c=abs;
	d=ord;
    I=init_card[c][d];
	abs=abs+1;
    
    if(abs>19){
       abs=abs-1;
        printf("超出边界 请重新输入\n");
			
			}
    else if(init_card[abs][ord]=='2')
    {printf("所去方向有树阻挡\n");
     abs=abs-1;}
     else if (init_card[abs][ord]=='3')
     {printf("所去方向有岩石阻挡\n");
     abs=abs-1;
     }
	else if(init_card[abs][ord]=='4'){
	  printf("恭喜你获得一把钥匙\n");
		Key=Key+1;
	}
	 else if(init_card[abs][ord]=='5'){
	   printf("恭喜你获得一枚金币\n");
	     Money=Money+1;
    }
     else if(init_card[abs][ord]=='6'){
	    if(Key>=1){
		 printf("恭喜你打开一个挂锁：生命值+1\n");
		  Life=Life+1; 
		  Key=Key-1;
	   }
	    else if(Key==0){
		printf("你没有钥匙，无法开启挂锁,无法前进\n");
        abs=abs-1;
     }
  }
		else if(init_card[abs][ord]=='7'){
		printf("你掉落陷阱：生命值-1\n");
       Life=Life-1;
  }
	    else if(init_card[abs][ord]=='8'){
	     printf("你遇见怪兽：生命值-1\n");
		  Life=Life-1;
  }
    
}

else if(move==4)
{
	system("cls");
printf("2=向下 4=向左 6=向右 8=向上 0=退出游戏\n");
      c=abs;
	  d=ord;
	  I=init_card[c][d];
      ord=ord-1;
  
     if(ord<0){
         ord=ord+1;
         printf("超出边界 请重新输入\n");
         
			}
     else if(init_card[abs][ord]=='2')
        {
	 printf("所去方向有树阻挡\n");
     ord=ord+1;
			}
      else if (init_card[abs][ord]=='3')
      {printf("所去方向有岩石阻挡\n");
      ord=ord+1;
      }
	else if(init_card[abs][ord]=='4'){
	  printf("恭喜你获得一把钥匙\n");
		Key=Key+1;
	}
	 else if(init_card[abs][ord]=='5'){
	   printf("恭喜你获得一枚金币\n");
	     Money=Money+1;
    }
     else if(init_card[abs][ord]=='6'){
	    if(Key>=1){
		 printf("恭喜你打开一个挂锁：生命值+1\n");
		  Life=Life+1;
		  Key=Key-1;
	   }
	    else if(Key==0){
		printf("你没有钥匙，无法开启挂锁，无法前进\n");
		ord=ord+1;
     }
  }
		else if(init_card[abs][ord]=='7'){
		printf("你掉落陷阱：生命值-1\n");
		Life=Life-1;
  }
	    else if(init_card[abs][ord]=='8'){
	     printf("你遇见怪兽：生命值-1\n");
		  Life=Life-1;
  }
     
}

else if(move==6)
{ 
	system("cls");
printf("2=向下 4=向左 6=向右 8=向上 0=退出游戏\n");
	c=abs;
	d=ord;
	I=init_card[c][d];
    ord=ord+1;
	  
      if(ord>19){
      ord=ord-1;
      printf("超出边界 请重新输入\n");
      
			}
      else if(init_card[abs][ord]=='2')
      {printf("所去方向有树阻挡\n");
       ord=ord-1;}
      else if (init_card[abs][ord]=='3')
     {printf("所去方向有岩石阻挡\n");
       ord=ord-1;
     }
	else if(init_card[abs][ord]=='4'){
	  printf("恭喜你获得一把钥匙\n");
		Key=Key+1;
	}
	 else if(init_card[abs][ord]=='5'){
	   printf("恭喜你获得一枚金币\n");
	     Money=Money+1;
    }
     else if(init_card[abs][ord]=='6'){
	    if(Key>=1){
		 printf("恭喜你打开一个挂锁：生命值+1\n");
		  Life=Life+1; 
		 Key=Key-1;
	   }
	    else if(Key==0){
		printf("你没有钥匙，无法开启挂锁，无法前进\n");
		ord=ord-1;
     }
  }
		else if(init_card[abs][ord]=='7'){
		printf("你掉落陷阱：生命值-1\n");
		Life=Life-1;
  }
	    else if(init_card[abs][ord]=='8'){
	     printf("你遇见怪兽：生命值-1\n");
		  Life=Life-1;
  }
     
}

else if(move==8)
 {
	system("cls");
printf("2=向下 4=向左 6=向右 8=向上 0=退出游戏\n");
    c=abs;
	d=ord;
	I=init_card[c][d];
  abs=abs-1;

    if(abs<0){
       abs=abs+1;
        printf("超出边界 请重新输入\n");
			
			}
    else if(init_card[abs][ord]=='2')
    {
	 printf("所去方向有树阻挡\n");
      abs=abs+1;
			}
     else if (init_card[abs][ord]=='3')
     {printf("所去方向有岩石阻挡\n");
      abs=abs+1;
      }
	else if(init_card[abs][ord]=='4'){
	  printf("恭喜你获得一把钥匙\n");
		Key=Key+1;
	}
	 else if(init_card[abs][ord]=='5'){
	   printf("恭喜你获得一枚金币\n");
	     Money=Money+1;
    }
     else if(init_card[abs][ord]=='6'){
	    if(Key>=1){
		 printf("恭喜你打开一个挂锁：生命值+1\n");
		  Life=Life+1; 
		  Key=Key-1;
	   }
	   else if(Key==0){
		printf("你没有钥匙，无法开启挂锁，无法前进\n");
		 abs=abs+1;
     }
  }
		else if(init_card[abs][ord]=='7'){
		printf("你掉落陷阱：生命值-1\n");
       Life=Life-1;
  }
	    else if(init_card[abs][ord]=='8'){
	     printf("你遇见怪兽：生命值-1\n");
		  Life=Life-1;
  }

}
display_LifeMoney(Life,Money,Key);
init_card[c][d]=recovery (I); //如果因为岩石等阻挡无法前进时，下一行输出x可以覆盖当前位置，而不受影响
init_card[abs][ord]='x';
display_card(init_card); 
    if(Life==0){
	 printf("当前生命为0，Game Over!\a\n");
		break;	
	}
     else if(Money==10){
      printf("You are Winner!\a\n");
			break;
	}
    scanf("%d",&move);
      if(move==0){
			printf("game over\a\n");
		}
	
		} 
	}
  	

void display_card(char a[20][20]){
	  for(int i=0;i<=19;i++){
		for(int j=0;j<=19;j++){
			switch(a[i][j]){
			case 'x':
					printf(" 人  ");
					break;
			 case '0':
					printf(" 草  ");
					break;
			 case '1':
					printf(" 花  ");
			        break;
			case '2':
					printf(" 树  ");
					break;
			case '3':
					printf("石头 ");
					break;
			case '4':
					printf("钥匙 ");
			        break;
			case '5':
					printf("金币 ");
					break;
			case '6':
			        printf("挂锁 ");
			        break;
			case '7':
					printf("陷阱 ");
					break;
			case '8':
					printf("怪物 ");
					break;
			
			}
			if(j%20==19){
				printf("\n");
			}
		}
	}
}

char recovery (char I){
	char R;
   if(I =='1'){R='1';}
 else if(I=='2'){R='2';}
  else if(I=='3'){R='3';}
  else if(I=='8'){R='8';}
	else{R='0';}
  return R;
}

void display_LifeMoney(int Life,int Money,int Key){
  printf("当前生命值 = %d 金币数 = %d 钥匙数 = %d\n",Life,Money,Key);
  printf(" 1:一朵花 2:树 3:岩石 4 :钥匙 5:金币 6:挂锁 7:陷阱 8:怪物\n");
}




