#include<iostream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<string.h>
using namespace std;
int left(int a){
	a-=2;
	if(a<=0){
		a=0;
	}
	return a;
}
int right(int a){
		a+=2;
		if(a>=4){
			a=4;
		}
		return a;
	}
string up(){
	string up="      ■■      ";
		return up;
	}
string up2(){
		string up2="「    ■■    」";	
		return up2;
	}
string middle(){
	string middle="    ■■■■    ";
		return middle;	
	}
string middle2(){
		string middle2="「  ■■■■  」";	
		return middle2;
	}
string down(){
	string down="  ■■■■■■  ";	
	return down;
	}
string down2(){
	string down2="「■■■■■■」";	
	return down2;
	}
void play(){
	for(int i=0;i<=3;i++){
		cout <<"\n    開始遊戲\n    ";
		for(int k=0;k<=2;k++){
		if (i<=k)
		cout <<"○";
		else
		cout <<"●";

		}
		_sleep(500);
		system("cls");
		}
	}
void display(string table[3][5],int step){
	system("cls");
	cout<<endl;
	for(int i=0;i<=2;i++){
		for(int j=0;j<=4;j+=2){
		cout<<setw(16)<<table[i][j];
		if(j<4){
		cout<<table[i][j+1];
		}	
		}
		cout <<endl;
		}
		cout<<"\n移動次數:"<<step;
	} 
int main(){
	int keyb,a=0,j=0,j2,a2,high[5]={0},len,h,step=0;
	bool select_check,check,warning=false;
	string table[3][5],record[3][5];
	cout << "\t\t河內塔遊戲\t\t\n\n操作說明:\nA和D鍵為操作左右的按鍵\nspace鍵為選取鍵，可以\n調整位置\nR鍵為resert\nesc鍵為退出遊戲\n\n\t(按下空白鍵開始遊戲)";
while(1){
	if(kbhit()){
		keyb=getch();
		if(keyb==32){
			R:
			step=0;
			select_check=false;
			check=true;
			for(int i=0;i<=2;i++){
			table[i][1]="|";
			table[i][3]="|";
			table[i][0]="";
			table[i][2]="";
			table[i][4]="";
		}
			table[0][0]=up();
			table[1][0]=middle();
			table[2][0]=down();	
			system("cls");
   			play();
   			display(table,step);
   			while(1){
   			back:
   				for(int i=0;i<=2;i++){
					for(int j=0;j<=4;j++){
						record[i][j]=table[i][j];
					} 
				}
   				if(kbhit()){
   					keyb=getch();
   					if(keyb==97 or keyb==97-32){							//left head 
   						a=left(a);
   						warning=false;
						if(a==0){
							for(j=2;j>=0;j--){
								if(table[j][a].size()!=0){
									if(select_check==true){ 
										if(high[a2]>high[a]){
											warning=true;
										}
										else
										warning=false;
										if(table[j][a]!=table[j2][a2])
										continue;
										} 
									check=false;
									for(j=0;j<=2;j++){
										if(table[j][a]==up()){
											table[j][a]=up2();
											goto la;
										}
										else if(table[j][a]==middle()){
											table[j][a]=middle2();
											goto la;
										}
										else if(table[j][a]==down()){
											table[j][a]=down2();
											goto la;
											}
										}
							}
								else if(table[j][a].size()==0){
									table[j][a]="「  」     ";
									break;
							}
							}	
						}
						else if(a==2){
								for( j=2;j>=0;j--){
								if(table[j][a].size()!=0){
										if(select_check==true){
											if(high[a2]>high[a]){
												warning=true; 
												
											}
											else
											warning=false;
											if(table[j][a]!=table[j2][a2])
										continue;
									}
									
								for(j=0;j<=2;j++){
									if(table[j][a]==up()){
											table[j][a]=up2();
											goto la;
										}
										else if(table[j][a]==middle()){
											table[j][a]=middle2();
											goto la;
										}
										else if(table[j][a]==down()){
											table[j][a]=down2();
											goto la;
											}
								}
							}
								else if(table[j][a].size()==0){
									table[j][a]="「  」     ";
									break;
							}
							}
						}
						la:
   						display(table,step);
   						for(int i=0;i<=2;i++){
							for(int j=0;j<=4;j++){
								table[i][j]=record[i][j];
							} 
					 	  }
					 }													//left end
					else if(keyb==100 or keyb==100-32){					//right head
						a=right(a);
						warning=false;
						if(a==2){
							for( j=2;j>=0;j--){
								if(table[j][a].size()!=0){
										if(select_check==true){
											if(high[a2]>high[a]){
											warning=true; 
											}
											else
											warning=false;
											if(table[j][a]!=table[j2][a2])
										continue;
										} 
										check=false;
									for(j=0;j<=2;j++){
									if(table[j][a]==up()){
									table[j][a]=up2();
									goto ra;
									}
									else if(table[j][a]==middle()){
									table[j][a]=middle2();
									goto ra;
									}
									else if(table[j][a]==down()){
									table[j][a]=down2();
									goto ra;
									}
								}
							}
								else if(table[j][a].size()==0){
									table[j][a]="「  」     ";
									break;
							}
							}	
						}
						else if(a==4){
								for( j=2;j>=0;j--){
								if(table[j][a].size()!=0){
										if(select_check==true){
											if(high[a2]>high[a]){
												warning=true; 
												
											}
											if(table[j][a]!=table[j2][a2])
										continue;
									}
									check=false;
								for(j=0;j<=2;j++){
									for(j=0;j<=2;j++){
									if(table[j][a]==up()){
									table[j][a]=up2();
									goto ra;
									}
									else if(table[j][a]==middle()){
									table[j][a]=middle2();
									goto ra;
									}
									else if(table[j][a]==down()){
									table[j][a]=down2();
									goto ra;
									}
								}
								}
							}
								else if(table[j][a].size()==0){
									table[j][a]="「  」     ";
									break;
							}
							}
						}
						ra:
   						display(table,step);
   						for(int i=0;i<=2;i++){
							for(int j=0;j<=4;j++){
								table[i][j]=record[i][j];
							} 
					 	  }
					}														//right end
					else if(keyb==32){
						if(select_check==true){
							if(warning==false){
							swap(table[j][a],table[j2][a2]);
							select_check=false;
							if(a2!=a)
							//if((table[j][a]!="")and(table[j2][a2]!=""))
							step++;
							display(table,step);
							}
							else
							cout<<"△大的不能疊在小的上";
						}
						else{
							if(table[j][a]!="")
							select_check=true;
							a2=a;
							j2=j;
						}
					}
					else if(keyb==114 or keyb==114-32){goto R;}
					else if(keyb==27){
						while(1){
						cout << "\n\n確認要退出?(Y/N)\n";
						keyb=getch();
						if(keyb==121 or keyb==-32){
							char end[]="have a nice day ^^";
							len=strlen(end);
							for(int i=0;i<=len;i++){
								cout<<end[i];
								_sleep(100);
						}
						goto y;}
						else if(keyb==110 or keyb==110-32){
						display(table,step);
						select_check=false;
						goto back;
						}
					}
					}
				//	cout<<high[0]<<","<<high[2]<<","<<high[4]; //驗證行 
					int h;
					for(int k=0;k<=4;k+=2){
						for(int l=2;l>=0;l--){
							if(table[l][k].size()!=0){	//紀錄每一層高度啦幹 
								for(h=0;h<=2;h++){
										if(table[h][k]==up()){
											high[k]=1;
											break;
										}
										else if(table[h][k]==middle()){
											high[k]=2;	
											break;
										}
										else if(table[h][k]==down()){
											high[k]=3;	
											break;
											}
								}
							}
							else if(table[h][k].size()==0){
								high[k]=0;
								break;
							}
						for(int i=2;i<=4;i+=2){
						if(table[0][i]==up())
							if(table[1][i]==middle())
								if(table[2][i]==down()){
									cout<<"\n你用"<<step<<"次完成!\n\n按下按鍵重新開始";
									getch();
									goto R;
								} 
							}
					}		
						}
					}
		}
	}
	}
}
y:
	return 0;  
}
