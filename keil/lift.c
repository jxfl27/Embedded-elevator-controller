#include"reg51.h"

unsigned char flagL1=0,flagL2=0,flagL3=0;
unsigned char flagR1=0,flagR2=0,flagR3=0;
unsigned char flagO1=0,flagO2=0,flagO3=0,flagO4=0;
unsigned char lift[3]={0,0,0};
unsigned char rift[3]={0,0,0};
unsigned char outdoor[6]={0,0,0,0,0,0};
unsigned char lDir=0,rDir=0,lFloor=1,rFloor=1;
unsigned char change[6]={0,0,0,0,0,0};
unsigned char i,j;

sbit keyL1=P0^0; sbit keyL2=P0^1; sbit keyL3=P0^2;
sbit keyR1=P0^3; sbit keyR2=P0^4; sbit keyR3=P0^5;
sbit keyO1=P2^7; sbit keyO2=P2^6; sbit keyO3=P2^5; sbit keyO4=P2^4;

sbit LEDL1=P1^0; sbit LEDL2=P1^1; sbit LEDL3=P1^2;
sbit LEDR1=P1^3; sbit LEDR2=P1^4; sbit LEDR3=P1^5;
sbit LEDO1=P3^0; sbit LEDO2=P3^1; sbit LEDO3=P3^2; sbit LEDO4=P3^3;

sbit LUP=P3^4; sbit LDOWN=P3^5; sbit LOPEN=P1^6;
sbit RUP=P3^6; sbit RDOWN=P3^7; sbit ROPEN=P1^7;

sbit LIFT1=P2^0; sbit LIFT0=P2^1;
sbit RIFT1=P2^2; sbit RIFT0=P2^3;




/*void init_timer(void){
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	ET0=1;
	EA=1;
	TR0=1;
}

void timer_isr(void) interrupt 1{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	timer0_cnt++;
	if(timer0_cnt%10==0){
		time++;
	}
}*/

//delay  t   ms
void delay(unsigned int t){
		unsigned int i=0, j=0;
		for(i=0;i<=t;i++)
		{
			for(j=0;j<=120;j++);
			
		}
		
}

char abs(char number)
{
	return (number&0x80 ? -number : number);
}

void initLed(){
	LEDL1=0;LEDL2=0;LEDL3=0;
	LEDR1=0;LEDR2=0;LEDR3=0;
	LEDO1=0;LEDO2=0;LEDO3=0;LEDO4=0;
	LUP=0;LDOWN=0;LOPEN=0;
	RUP=0;RDOWN=0;ROPEN=0;
	LIFT1=0;LIFT0=1;
	RIFT1=0;RIFT0=1;
}

void check(){
	//L1
	if(keyL1==0&&flagL1==0)
		{
			flagL1=1;
		}
	if(keyL1==1&&flagL1==1)
		{
			lift[0]=1;
			LEDL1=1;
			flagL1=0;
		}
	//L2
	if(keyL2==0&&flagL2==0)
		{
			flagL2=1;
		}
	if(keyL2==1&&flagL2==1)
		{
			lift[1]=1;
			LEDL2=1;
			flagL2=0;
		}

	//L3
	if(keyL3==0&&flagL3==0)
		{
			flagL3=1;
		}
	if(keyL3==1&&flagL3==1)
		{
			lift[2]=1;
			LEDL3=1;
			flagL3=0;
		}

	//R1
	if(keyR1==0&&flagR1==0)
		{
			flagR1=1;
		}
	if(keyR1==1&&flagR1==1)
		{
			rift[0]=1;
			LEDR1=1;
			flagR1=0;
		}

	//R2
	if(keyR2==0&&flagR2==0)
		{
			flagR2=1;
		}
	if(keyR2==1&&flagR2==1)
		{
			rift[1]=1;
			LEDR2=1;
			flagR2=0;
		}

	//R3
	if(keyR3==0&&flagR3==0)
		{
			flagR3=1;
		}
	if(keyR3==1&&flagR3==1)
		{
			rift[2]=1;
			LEDR3=1;
			flagR3=0;
		}

	//O1
	if(keyO1==0&&flagO1==0)
		{
			flagO1=1;
		}
	if(keyO1==1&&flagO1==1)
		{
			outdoor[1]=1;
			LEDO1=1;
			flagO1=0;
		}
	//O2
	if(keyO2==0&&flagO2==0)
		{
			flagO2=1;
		}
	if(keyO2==1&&flagO2==1)
		{
			outdoor[2]=1;
			LEDO2=1;
			flagO2=0;
		}
	//O3
	if(keyO3==0&&flagO3==0)
		{
			flagO3=1;
		}
	if(keyO3==1&&flagO3==1)
		{
			outdoor[3]=1;
			LEDO3=1;
			flagO3=0;
		}
	//O4
	if(keyO4==0&&flagO4==0)
		{
			flagO4=1;
		}
	if(keyO4==1&&flagO4==1)
		{
			outdoor[4]=1;
			LEDO4=1;
			flagO4=0;
		}
}

void lArrival(){
	LOPEN=1;
	delay(300);
	lift[lFloor-1]=0;
	if(lFloor==1){	
		LEDL1=0;		
	}
	if(lFloor==2){
		LEDL2=0;
	}
	if(lFloor==3){
		LEDL3=0;
	}
	switch(lDir){
		case 0:
			if(lFloor==1){
				outdoor[1]=0;
				LEDO1=0;
			}
			if(lFloor==2){
				outdoor[2]=0;
				outdoor[3]=0;
				LEDO2=0;
				LEDO3=0;
			}
			if(lFloor==3){
				outdoor[4]=0;
				LEDO4=0;
			}			
		case 1:
			if(lFloor==1){
				outdoor[1]=0;
				LEDO1=0;
			}
			if(lFloor==2){
				outdoor[3]=0;
				LEDO3=0;
			}		
		case 2:
			if(lFloor==2){
				outdoor[2]=0;
				LEDO2=0;
			}
			if(lFloor==3){
				outdoor[4]=0;
				LEDO4=0;
			}				
	}

	LOPEN=0;
}

void rArrival(){
	ROPEN=1;
	delay(300);
	rift[rFloor-1]=0;
	if(rFloor==1){	
		LEDR1=0;		
	}
	if(rFloor==2){
		LEDR2=0;
	}
	if(rFloor==3){
		LEDR3=0;
	}
	switch(rDir){
		case 0:
			if(rFloor==1){
				outdoor[1]=0;
				LEDO1=0;
			}
			if(rFloor==2){
				outdoor[2]=0;
				outdoor[3]=0;
				LEDO2=0;
				LEDO3=0;
			}
			if(rFloor==3){
				outdoor[4]=0;
				LEDO4=0;
			}			
		case 1:
			if(rFloor==1){
				outdoor[1]=0;
				LEDO1=0;
			}
			if(rFloor==2){
				outdoor[3]=0;
				LEDO3=0;
			}		
		case 2:
			if(rFloor==2){
				outdoor[2]=0;
				LEDO2=0;
			}
			if(rFloor==3){
				outdoor[4]=0;
				LEDO4=0;
			}				
	}

	ROPEN=0;
}

void lDisplayFloor(){
	if(lFloor==1){
		LIFT1=0;
		LIFT0=1;
	}
	if(lFloor==2){
		LIFT1=1;
		LIFT0=0;
	}
	if(lFloor==3){
		LIFT1=1;
		LIFT0=1;
	}	
}


void rDisplayFloor(){
	if(rFloor==1){
		RIFT1=0;
		RIFT0=1;
	}
	if(rFloor==2){
		RIFT1=1;
		RIFT0=0;
	}
	if(rFloor==3){
		RIFT1=1;
		RIFT0=1;
	}	
}

void lRun(){
	switch(lDir){
		case 0:
			change[0]=0; 
			if(lift[lFloor-1]==1||outdoor[(lFloor-1)*2]==1||outdoor[(lFloor-1)*2+1]==1){
				lArrival();
			}
			for(i=lFloor+1;i<=3;i++){
				if(lift[i-1]==1&&change[0]==0){
					lDir=1;
					change[0]=1;
					break;
				}
			} 
			for(i=lFloor-1;i>=1;i--){
				if(lift[i-1]==1&&change[0]==0){
					lDir=2; 
					change[0]=1;
					break;
				}
			}
			for(i=lFloor+1;i<=3;i++){
				if((outdoor[(i-1)*2+1]==1||outdoor[(i-1)*2]==1)&&change[0]==0&&(rDir!=0||(rDir==0&&abs(lFloor-i)<=abs(rFloor-i)))){
					lDir=1;
					change[0]=1;
					break;
				}
			}
			for(i=lFloor-1;i>=1;i--){
				if((outdoor[(i-1)*2+1]==1||outdoor[(i-1)*2]==1)&&change[0]==0&&(rDir!=0||(rDir==0&&abs(lFloor-i)<=abs(lFloor-i)))){
					lDir=2;
					change[0]=1;
					break;
				}
			}
			break;
		case 1:
			LOPEN=0;
			LUP=1;
			delay(100);
			lFloor++;
			lDisplayFloor();
			delay(100);
			change[1]=0;
			if(lift[lFloor-1]==1||outdoor[(lFloor-1)*2+1]==1){
				lArrival();
			}
			for(i=lFloor+1;i<=3;i++){
				if(lift[i-1]==1||outdoor[(i-1)*2+1]==1){
					lDir=1;
					change[1]=1;
					break;
				}
			}	
			if(change[1]==0){
				lDir=0;	
				LUP=0;
			}
			break;
		case 2:
			LOPEN=0;
			LDOWN=1;
			delay(100);
			lFloor--;
			lDisplayFloor();
			delay(100);
			change[2]=0;
			if(lift[lFloor-1]==1||outdoor[(lFloor-1)*2==1]){
				lArrival();
			}
			for(i=lFloor-1;i>=1;i--){
				if(lift[i-1]==1||outdoor[(i-1)*2]==1){
					lDir=2;
					change[2]=1;
					break;
				}
			}	
			if(change[2]==0){
				lDir=0;		
				LDOWN=0;
			}
			break;					
	}
}

void rRun(){
	switch(rDir){
		case 0:
			change[3]=0; 
			if(rift[rFloor-1]==1||outdoor[(rFloor-1)*2]==1||outdoor[(rFloor-1)*2+1]==1){
				rArrival();
			}
			for(j=rFloor+1;j<=3;j++){
				if(rift[j-1]==1&&change[3]==0){
					rDir=1;
					change[3]=1;
					break;
				}
			} 
			for(j=rFloor-1;j>=1;j--){
				if(rift[j-1]==1&&change[3]==0){
					rDir=2; 
					change[3]=1;
					break;
				}
			}
			for(j=rFloor+1;j<=3;j++){
				if((outdoor[(j-1)*2+1]==1||outdoor[(j-1)*2]==1)&&change[3]==0&&(lDir!=0||(lDir==0&&abs(rFloor-j)<=abs(lFloor-j)))){
					rDir=1;
					change[3]=1;
					break;
				}
			}
			for(j=rFloor-1;j>=1;j--){
				if((outdoor[(j-1)*2+1]==1||outdoor[(j-1)*2]==1)&&change[3]==0&&(lDir!=0||(lDir==0&&abs(rFloor-j)<=abs(lFloor-j)))){
					rDir=2;
					change[3]=1;
					break;
				}
			}
			break;
		case 1:
			ROPEN=0;
			RUP=1;
			delay(100);
			rFloor++;
			rDisplayFloor();
			delay(100);
			change[4]=0;
			if(rift[rFloor-1]==1||outdoor[(rFloor-1)*2+1]==1){
				rArrival();
			}
			for(j=rFloor+1;j<=3;j++){
				if(rift[j-1]==1||outdoor[(j-1)*2+1]==1){
					rDir=1;
					change[4]=1;
					break;
				}
			}	
			if(change[4]==0){
				rDir=0;	
				RUP=0;
			}
			break;
		case 2:
			ROPEN=0;
			RDOWN=1;
			delay(100);
			rFloor--;
			rDisplayFloor();
			delay(100);
			change[5]=0;
			if(rift[rFloor-1]==1||outdoor[(rFloor-1)*2==1]){
				rArrival();
			}
			for(j=rFloor-1;j>=1;j--){
				if(rift[j-1]==1||outdoor[(j-1)*2]==1){
					rDir=2;
					change[5]=1;
					break;
				}
			}	
			if(change[5]==0){
				rDir=0;		
				RDOWN=0;
			}
			break;					
	}
}


void main(){
	initLed();
	//init_timer();
	while(1){
		check();
		rRun();
		lRun();
		
		delay(300);
	}
}