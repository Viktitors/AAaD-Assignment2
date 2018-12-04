#include <stdio.h>

void dynamic(int goods[],int numPackets, int truckTotal,int M[][truckTotal+1]);

void main(){
    int i,j,n,numPackets, truckTotal=400;
    
    int sum=0;
    
    printf("Introduce the number of goods\n");
    scanf("%d",&numPackets);
    numPackets++;               //SET OF GOODS+1 that is the empty set {0}
    int goods[numPackets];
    //int chosengoods[numPackets];//array to show the chosen goods to be carried
    //initialize:
    goods[0]=0;//empty
    
    //SCAN AND PRINT THE PACKETS:
    for(j=1;j<numPackets;j++){        
        printf("Introduce the weight of the packet[%d]\n",j);
        scanf("%d",&i);
        goods[j]=i;   
    }
    for(j=1;j<numPackets;j++){        
        printf("packet[%d]=%d\n",j, goods[j]);           
    }        
    int M[numPackets][truckTotal+1];
    
    dynamic(goods,numPackets,truckTotal,M);
    //PRINT THE MATRIX://///////////////////////////////////////////
    /*
    for(n=0;n<numPackets;n++){
        printf("\n");
        printf("%d |", goods[n]);
        for(i=0;i<truckTotal+1;i++){
          printf("%d ",M[n][i]);  
        }
    }
    */
    
    
    //FIND CHOSEN PACKETS://////////////////////////////
    returning(truckTotal,numPackets,goods,M);

  system("pause");  
}

void dynamic(int goods[],int numPackets, int truckTotal, int M[][truckTotal+1]){
    int i,j;  
    i=0;
    //INITIALIZE THE FIRST ROW
    for(j=0;j<truckTotal+1;j++){
        M[i][j]=j;
    }   
    //SELECTION:
    for(i=1;i<numPackets;i++){
        for(j=0;j<truckTotal+1;j++){
            if(goods[i]>j){
                M[i][j]=M[i-1][j];
            }
            else{               
                if( M[i-1][j-goods[i]] < M[i-1][j]){
                    M[i][j] = M[i-1][j-goods[i]];                    
                }
                else{
                    M[i][j]=M[i-1][j];                   
                }                                              
            }
        }
    }           
}
void returning(int truckTotal, int numPackets, int goods[], int M[][truckTotal+1]){
    int i,j,sum=0;
    j=truckTotal;
    printf("\nChosen goods for weight %d:", truckTotal); 
    for(i=numPackets-1;i>=0;i--){
        if(M[i][j]<M[i-1][j]){
            j=j-goods[i];
            if(goods[i]>0){
                printf(" %d, ",goods[i]);          
                sum+=goods[i];
            }
        }  
    }         
/*
    for(n=0;n<m;n++){
        if(chosengoods[m]>0){
            printf(" %d, ",chosengoods[m]);          
            sum+=chosengoods[m];
        }
    }
*/
    //////////////////////////////////////////////////////
    printf("\nWeight left: %d \n", truckTotal-sum);
}