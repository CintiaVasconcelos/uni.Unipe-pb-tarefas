#include <stdio.h>
#include<graphics.h>
#include<time.h>

void opcao1();
void opcao2();
void opcao3();
void opcao4();
void opcao5();
void menu();


int main()

{
	
		menu();
	
		return 0;
	}

	void menu ()
	{
	int menu1esc;

	
	printf("Menu - Digite o numero respectivo\n\n");
	printf("1 - Jogo nivel facil\n\n");
	printf("2 - Jogo nivel medio\n\n");
	printf("3 - Jogo nivel dificil\n\n");
	printf("4 - Creditos\n\n");
	printf("5 - Ranking\n\n");
	scanf("%d", &menu1esc);
	
	switch (menu1esc)
	{
	case 1:
	{
		opcao1();
		int i,X[100],Y[100],rx,ry,gd,gm,l,A=2,B=16;
		break;
	}
	case 2:
		{
			opcao2();
			int i,X[100],Y[100],rx,ry,gd,gm,l,A=2,B=16;
			break;
		}
		
	case 3:
		{
			opcao3();
			int i,X[100],Y[100],rx,ry,gd,gm,l,A=2,B=16;
			break;
		}
		
	case 4:
		{
			opcao4();
			printf ("creditos");
			break;
		}
		
	case 5:
		{
			opcao5();
			printf ("ranking");
			break;
		}
}
}

void opcao1()
	{

	system ("CLS");
	int i,X[100],Y[100],rx,ry,gd,gm,l,A=2,B=16;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1);
	bar(B-B/2,B-B/2,(B/2)+B*(1350/B),B+B/2); //topo
	bar(B-B/2,(-B/2)+B*(700/B),(B/2)+B*(1350/B),(B/2)+B*(700/B));	//baixo
	bar(B-B/2,B-B/2,B+B/2,(B/2)+B*(700/B)); //esquerda
	bar((-B/2)+B*(1350/B),B-B/2,(B/2)+B*(1350/B),(B/2)+B*(700/B)); //direta
	X[0]=B*(1350/(2*B)); Y[0]=B*(700/(2*B));
	bar(X[0]-B/2,Y[0]-B/2,X[0]+B/2,Y[0]+B/2);
	l=5;
	for(i=1;i<l;i++)
		{
			X[i]=X[0]-(i*B);
			Y[i]=Y[0];
			bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
		}
		rx=B; ry=B;
		setfillstyle(1,2);
		while(getpixel(rx,ry)!=0)
		{
			rx=B*(1+rand()%(1350/B-1));
			ry=B*(1+rand()%(700/B-1));
		}
		bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
		delay(2000);
		while(1)
		{
			//atualizar Snake
			setfillstyle(1,0);
			bar(X[l-1]-B/2,Y[l-1]-B/2,X[l-1]+B/2,Y[l-1]+B/2);
			for(i=l;i>0;i--)
			{
				X[i]=X[i-1];
				Y[i]=Y[i-1];
			}
			//atualizar a parte superior
			if(A==0)
				X[0]=X[0]-B;
			else if(A==1)
				Y[0]=Y[0]-B;
			else if(A==2)
				X[0]=X[0]+B;
			else if(A==3) 
				Y[0]=Y[0]+B;
			//condição término
			if(getpixel(X[0],Y[0])==1)
				break;
			//atualizar direção
			if(GetAsyncKeyState(VK_RIGHT)&&A!=0)
				A=2;
			else if(GetAsyncKeyState(VK_UP)&&A!=3)
				A=1;
			else if(GetAsyncKeyState(VK_LEFT)&&A!=2)
				A=0;
			else if(GetAsyncKeyState(VK_DOWN)&&A!=1)
				A=3;
			if(getpixel(X[0],Y[0])==2) //condição caso a comida seja pega
			{
				rx=B; ry=B;
				setfillstyle(1,2);
				while(getpixel(rx,ry)!=0)
				{
					rx=B*(1+rand()%(1350/B-1));
					ry=B*(1+rand()%(700/B-1));
				}
				bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
				l=l+1;
			}
			//Fazer Snake surgir
			setfillstyle(1,1);
			for(i=0;i<l;i++)
				bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
			delay(100);
		}
		printf("score : %d",l-5); //record
		while(!GetAsyncKeyState(VK_RETURN));
		closegraph();
		getch();		
		menu();
	}
			
void opcao2()
	{
	int i,X[100],Y[100],rx,ry,gd,gm,l,A=2,B=16;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1);
	bar(B-B/2,B-B/2,(B/2)+B*(1350/B),B+B/2); //topo
	bar(B-B/2,(-B/2)+B*(700/B),(B/2)+B*(1350/B),(B/2)+B*(700/B));	//baixo
	bar(B-B/2,B-B/2,B+B/2,(B/2)+B*(700/B)); //esquerda
	bar((-B/2)+B*(1350/B),B-B/2,(B/2)+B*(1350/B),(B/2)+B*(700/B)); //direta
	X[0]=B*(1350/(2*B)); Y[0]=B*(700/(2*B));
	bar(X[0]-B/2,Y[0]-B/2,X[0]+B/2,Y[0]+B/2);
	l=5;
	for(i=1;i<l;i++)
		{
			X[i]=X[0]-(i*B);
			Y[i]=Y[0];
			bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
		}
		rx=B; ry=B;
		setfillstyle(1,2);
		while(getpixel(rx,ry)!=0)
		{
			rx=B*(1+rand()%(1350/B-1));
			ry=B*(1+rand()%(700/B-1));
		}
		bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
		delay(2000);
		while(1)
		{
			//atualizar Snake
			setfillstyle(1,0);
			bar(X[l-1]-B/2,Y[l-1]-B/2,X[l-1]+B/2,Y[l-1]+B/2);
			for(i=l;i>0;i--)
			{
				X[i]=X[i-1];
				Y[i]=Y[i-1];
			}
			//atualizar a parte superior
			if(A==0)
				X[0]=X[0]-B;
			else if(A==1)
				Y[0]=Y[0]-B;
			else if(A==2)
				X[0]=X[0]+B;
			else if(A==3)
				Y[0]=Y[0]+B;
				//condição término
				if(getpixel(X[0],Y[0])==1)
				break;
			//atualizar direção
			if(GetAsyncKeyState(VK_RIGHT)&&A!=0)
				A=2;
			else if(GetAsyncKeyState(VK_UP)&&A!=3)
				A=1;
			else if(GetAsyncKeyState(VK_LEFT)&&A!=2)
				A=0;
			else if(GetAsyncKeyState(VK_DOWN)&&A!=1)
				A=3;
			if(getpixel(X[0],Y[0])==2) //condição caso a comida seja pega
			{
				rx=B; ry=B;
				setfillstyle(1,2);
				while(getpixel(rx,ry)!=0)
				{
					rx=B*(1+rand()%(1350/B-1));
					ry=B*(1+rand()%(700/B-1));
				}
				bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
				l=l+1;
			}
			//Fazer Snake surgir
			setfillstyle(1,1);
			for(i=0;i<l;i++)
				bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
			delay(50);
		}
		printf("score : %d",l-5); //record
		while(!GetAsyncKeyState(VK_RETURN));
		closegraph();
		getch();		
		
		
			menu();	
			}
			
void opcao3()
	{
	
	int i,X[100],Y[100],rx,ry,gd,gm,l,A=2,B=16;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1);
	bar(B-B/2,B-B/2,(B/2)+B*(1350/B),B+B/2); //topo
	bar(B-B/2,(-B/2)+B*(700/B),(B/2)+B*(1350/B),(B/2)+B*(700/B));	//baixo
	bar(B-B/2,B-B/2,B+B/2,(B/2)+B*(700/B)); //esquerda
	bar((-B/2)+B*(1350/B),B-B/2,(B/2)+B*(1350/B),(B/2)+B*(700/B)); //direta
	X[0]=B*(1350/(2*B)); Y[0]=B*(700/(2*B));
	bar(X[0]-B/2,Y[0]-B/2,X[0]+B/2,Y[0]+B/2);
	l=5;
	for(i=1;i<l;i++)
		{
			X[i]=X[0]-(i*B);
			Y[i]=Y[0];
			bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
		}
		rx=B; ry=B;
		setfillstyle(1,2);
		while(getpixel(rx,ry)!=0)
		{
			rx=B*(1+rand()%(1350/B-1));
			ry=B*(1+rand()%(700/B-1));
		}
		bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
		delay(2000);
		while(1)
		{
			//atualizar Snake
			setfillstyle(1,0);
			bar(X[l-1]-B/2,Y[l-1]-B/2,X[l-1]+B/2,Y[l-1]+B/2);
			for(i=l;i>0;i--)
			{
				X[i]=X[i-1];
				Y[i]=Y[i-1];
			}
			//atualizar a parte superior
			if(A==0)
				X[0]=X[0]-B;
			else if(A==1)
				Y[0]=Y[0]-B;
			else if(A==2)
				X[0]=X[0]+B;
			else if(A==3)
				Y[0]=Y[0]+B;
				//condição término
				if(getpixel(X[0],Y[0])==1)
				break;
			//atualizar direção
			if(GetAsyncKeyState(VK_RIGHT)&&A!=0)
				A=2;
			else if(GetAsyncKeyState(VK_UP)&&A!=3)
				A=1;
			else if(GetAsyncKeyState(VK_LEFT)&&A!=2)
				A=0;
			else if(GetAsyncKeyState(VK_DOWN)&&A!=1)
				A=3;
			if(getpixel(X[0],Y[0])==2) //condição caso a comida seja pega
			{
				rx=B; ry=B;
				setfillstyle(1,2);
				while(getpixel(rx,ry)!=0)
				{
					rx=B*(1+rand()%(1350/B-1));
					ry=B*(1+rand()%(700/B-1));
				}
				bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
				l=l+1;
			}
			//Fazer Snake surgir
			setfillstyle(1,1);
			for(i=0;i<l;i++)
				bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
			delay(30);
		}
		system ("CLS");
		printf("score : %d",l-5); //record
		while(!GetAsyncKeyState(VK_RETURN));
		closegraph();
		getch();		
		
			menu();	
		}
			
void opcao4()
	{
		system ("CLS");
		printf ("Feito por: Cintia Vasconcelos\n\n\n");
			menu();	
		}
	
void opcao5()
	{	
		system ("CLS");
		printf("Ranking");
			menu();	
			}
