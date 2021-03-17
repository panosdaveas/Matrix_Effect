#include<iostream>
#include<string>
#include<time.h>
#include<thread>
#include<chrono>
using namespace std;

#define gotoxy printf("%c[%d;%df",0x1B,0,0); 
#define clear printf("\033[H\033[J");
#define GRN printf("\033[0;32m");
#define RST printf("\033[0m");
#define width 80
#define height 70

int main(){
	clear;
	int  i = 0;
	int j = 0;
	int x = 0;
	char b[width];
	
	memset(b,32,width);
	
	const string ch = "1234567890qwertyuiopasdfghjkl"
                      "zxcvbnm,./';[]!@#$%^&*()-=_+"; 
	const int c = ch.size();

	srand(time(NULL));
	RST;
	char matrix [height+1][width+1] = {0};
	for(int x=0; x<height; x++){
		for(int y=0; y<width; y++){
			matrix[x][y]=32;
		}
	}
	while(1){
		for (i = 0; i < width; i+=2){
			if(0 != rand() % 3 ){//play with this for rain spread
				b[rand() % width]=32;
			}else{
				b[i] = ch[rand() % c];
				b[i+1]=32;
			}
		}
		for(int k = 0; k < width; k++){
			matrix[0][k]=b[k];
		}
		for (int h=height; h>0; h--){
			strcpy(matrix[h],matrix[h-1]);
		}
		gotoxy;
		for(int x=0; x<height; x++){
			for( int y=0; y< width; y++){
				int flag=0;
				if(0 != rand() % 7  && matrix[x][y]!=32){
					matrix[x][y] = ch[rand() % c];
				}
				if(0 == rand() % 10){
					flag=1;
				}
				if(matrix[x+1][y]==32 && matrix[x+2][y]==32 && matrix[x-1][y]!=32 && flag==1){
					cout<<"\033[1;37m"<<matrix[x][y];
				}
				else if(matrix[x+1][y]!=32 && matrix[x+2][y]==32){
					cout<<"\033[1;32m"<<matrix[x][y];
				}
				else{
					cout<<"\033[0;32m"<<matrix[x][y];
				}
			}
			cout<<'\n';
		}
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	return 0;
}
