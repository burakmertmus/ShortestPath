#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#include<conio.h>
#define R 1000
#define N 23
int dist[N];
int komsulukMat[N][N];
int dijkstraBul(int komsulukMat[][N], int basla, int bitis);	
main()
{	
		system("mode con: cols=135 lines=42");
		setlocale(LC_ALL, "Turkish");
	  FILE *dosyaKod,*dosyaSehir;
	  dosyaKod = fopen("sehir kod.txt", "r");
	  
	  
	  char sehirMat[23][20],ayrac;
	  char sehirKod[23][2],sehir;
	  int sehirKodi[23]={0};
	  char *point,*point2;
      int i =0,j=0;
    	bool satirBas=true;
    	
    
   
    
    for(int i=1;i< N;i++){
		for(int j=1;j< N;j++){
			komsulukMat[i][j] = R;
	   	}
        
		} 
    
		 while( !feof(dosyaKod))                    /* dosyanýn sonuna kadar */
   {
   		
   				
   				fscanf(dosyaKod,"%s",sehirMat[i]);
   					
   				strtok_r (sehirMat[i], "-", &point);
   				strcpy(sehirKod[i], point);
   				
   				
   			if (i>0){
   				sehirKodi[i]=atoi(sehirKod[i]);	
			   }
			   if(i==22){
				break;			   	
			   }
   			//printf("%s %d\n",sehirMat[i],sehirKodi[i]);	
			i++;
			
   }	
		  printf("\n Bulunan Sehir sayisi: %d\n\n",i);
      fclose(dosyaKod);
      
      dosyaSehir=fopen("sehir mesafe.txt","r");
      int sayac1=0;
      char komsuluk[30][20],komsuluk2[30][20],mesafe[30][15];
	  int  intkomsuluk[30] = { 0 },intkomsuluk2[30]={ 0 },intmesafe[30] = { 0 };
      
      
      while(!feof(dosyaSehir)){
      	fscanf(dosyaSehir, "%s", komsuluk[sayac1]);
    	
	 	strtok_r (komsuluk[sayac1], "-", &point2);
	 	strcpy(komsuluk2[sayac1], point2);
	 	strtok_r (komsuluk2[sayac1], "-", &point2);
	 	strcpy(mesafe[sayac1], point2);
	 	if(sayac1 > 0)
	 	{
	 		//komsu1Int[a]=atoi(komsu1Char[a]);
			//komsu2Int[a]=atoi(komsu2Char[a]);
			intmesafe[sayac1] = atoi(mesafe[sayac1]);
			
	 	}  
		//printf ("%s  %s     %d\n", komsuluk[sayac1], komsuluk2[sayac1], intmesafe[sayac1]);
     	sayac1++;
	  }
	  
	  	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			komsulukMat[i][j] = -1;
		}
    }
    
	  komsuluk[0][0]=-1;
	  int ilk=0,son=0;
	  
	  for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 23; j++)
		{
			int kiyas=0;
			kiyas = strcmp(sehirMat[j], komsuluk[i]);
			if(kiyas == 0)
			{
				intkomsuluk[i] = sehirKodi[j];
				//printf ("\n%d\n", intkomsuluk[i]);
			}
		}	
	}
	
	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 23; j++)
		{
			int kiyas2;
			kiyas2 = strcmp(sehirMat[j], komsuluk2[i]);
			if(kiyas2 == 0)
			{
				intkomsuluk2[i] = sehirKodi[j];
				//printf ("\n%d\n", komsu2Int[x]);
				//printf ("%d  %d     %d\n", intkomsuluk[i], intkomsuluk2[i], intmesafe[i]);
			}
		}	
	}
	
	for(int i = 0; i < 30; i++)
	{
	
			komsulukMat[intkomsuluk[i]][intkomsuluk2[i]] =  intmesafe[i];
			komsulukMat[intkomsuluk2[i]][intkomsuluk[i]] =  intmesafe[i];
		
    }
    
   
    
    for(int i = 0; i < 23; i++)
	{
		for(int j = 0; j < 23; j++)
		{
			if(komsulukMat[i][j] == -1 || komsulukMat[i][j] == 0)
			komsulukMat[i][j] = 999;
		}
    }
    
    
    int basla=0,bitis=0,enKisa=0,secim=0;
    		system("cls");
			printf("\n\n\nSehirler arasý en kisa yolu görmek icin: 1\n");
    		printf("    Ýki sehir arasý en yolu görmek icin: 2\n");
    		printf("       Txtleri ve matrisler görmek için: 3\n");
    		printf("       Ekraný Temizlemek için 4\n");
    		printf("\t!!!1Çýkýs icin -1 giriniz!!!!\n");
    		printf("-----------------------------------------\n");
    		printf("Secim: ");
    		
    		scanf("%d",&secim);
			
			while(secim!=-1){  		
			switch(secim)
    		{
    			case 1:{
    				
    				printf("Kýyaslama yapýlacak ilin kodunu giriniz.");
					scanf("%d",&basla);
					for(int i=1;i<23;i++){
					
					enKisa= dijkstraBul(komsulukMat,basla,i);
        			printf("yolu üzerinden %s ile %s sehirleri arasýndaki en kýsa yol: %d dur.\n",sehirMat[basla],sehirMat[i],enKisa);
        		
					}
					
					break;
				}
				case 2:{  
					char op;
					printf("\nBaslangýc ve bitis sehirin kodunu giriniz(Örn;1-3):");
        			scanf("%d%c%d",&basla,&op,&bitis);
        			enKisa= dijkstraBul(komsulukMat,basla,bitis);
        			printf("yolu üzerinden %s ile %s sehirleri arasýndaki en kýsa yol: %d dur.\n",sehirMat[basla],sehirMat[bitis],enKisa);
					
					break;
				}
				case 3:{
					int secim3=0;
					printf("Sehirkodlarý .txt si için 1\n");
					printf("Sehirler arasý mesafe .txt si için 2 giriþini yapýnýz.\n");
					scanf("%d",&secim3);
					switch(secim3)
					{
						case 1:{
							for(int i=1;i<N;i++){
							printf("%s %d\n",sehirMat[i],sehirKodi[i]);			
							}
							
							break;
						}
						case 2:{
							
							for(int i=1;i<30;i++){
							printf ("%s  %s     %d\n", komsuluk[i], komsuluk2[i], intmesafe[i]);
								
							}
							
							break;
						}
					
						
						default:{
							printf("\aSecim sýnýrlarý dýþýnda bir giriþ yaptýnýz.");
							break;
						}
					}
					
					
					break;
				}
				case 4 :{system("cls");
					break;
				}
				default:{
					printf("\aYanlýþ secim yaptýnýz!!\n");
					break;
				}
				
			}
			
			printf("\n\n\nSehirler arasý en kisa yolu görmek icin: 1\n");
    		printf("    Ýki sehir arasý en yolu görmek icin: 2\n");
    		printf("       Txtleri ve matrisler görmek için: 3\n");
    		printf("       Ekraný Temizlemek için 4\n");
    		printf("\t!!!1Çýkýs icin -1 giriniz!!!!\n");
    		
    		printf("-----------------------------------------\n");
    		printf("Secim: ");
			scanf("%d",&secim);
    		
    		
		}
		
        
        fclose(dosyaSehir);
      return 0;
      
      //fclose(oku1);
}
int dijkstraBul(int cost[][N],int basla,int bitis){
	int onceki[N],secim[N]={ 0 },d=0,j=0;
	int min=0,m=0,x=0;
	char yol[N];
	for (int i=1;i<N;i++){
		dist[i]=R;
		onceki[i]=-1;
	}
	int bas=basla;
	secim[bas]=1;
	dist[bas]=0;
	while(secim[bitis]==0){
		min=R;
		m=0;
		for(int i=1;i<N;i++){
			d=dist[bas]+cost[bas][i];
			 if(d< dist[i]&&secim[i]==0)
                {
                    dist[i] = d;
                    onceki[i] = bas;
                }
                if(min>dist[i] && secim[i]==0)
                {
                    min = dist[i];
                    m = i;
                }	
			}
			bas=m;
			secim[bas]=1;
		
		}
		bas=bitis;
		j=0;
		int deneme[N];
			for (int i=0;i<N;i++){
			deneme[i]=999;
		}
		
		while(bas != -1)
		{
			deneme[j]=bas;
			bas= onceki[bas];
			j++;
			
		}
		
		
		 
		 for (int i=N;i>=0;i--){
			if(deneme[i]!=999 && deneme[i]!=0){
			printf("%d-",deneme[i]);
			}
	}
	
		
		
	
		return dist[bitis];
	
	
}

