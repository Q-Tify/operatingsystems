#include <stdio.h>


typedef struct Page{
  int pageNumber;
  int bits;
  int r_bit;
}page;


int pageExists(page table[], int number, int n){
  for(int i=0;i<n;i++){
    if(table[i].pageNumber==number){
      return i;
    }
  }
  return -1;
}


int freeFrame(page table[], int n){
  for(int i=0;i<n;i++){
    if(table[i].pageNumber==-1){
      return i;
    }
  }
  return -1;
}


int leastActive(page table[], int n){
  int lActive=0;
  for(int i=0;i<n;i++){
    if(table[i].bits<table[lActive].bits){
      lActive=i;
    }else if(table[i].bits==table[lActive].bits){
      if(table[i].pageNumber<table[lActive].pageNumber){
        lActive=i;
      }
    }
  }
  return lActive;
}

void insertPage(page table[],int index, int number){
  table[index].pageNumber=number;
  table[index].bits=00000000;
  table[index].r_bit=1;
};

int main(void){

  double bSum;
  int n, m;
  scanf("%d %d",&n,&m);

  page frameTable[n];
  for(int i=0;i<n;i++){
    frameTable[i].pageNumber=-1;
    frameTable[i].bits=00000000;
    frameTable[i].r_bit=0;
  }

  
  int oldTick, newTick;
  int clckCycle, pageNum;

  //For each memory access
  for(int i=0;i<m;i++){
    
    scanf("%d %d",&clckCycle,&pageNum);

    newTick = clckCycle;
    
    //if cycle is new then we shift everything and r_bit=0
    if(i!=0 && newTick!=oldTick){
      for(int j=0;j<n;j++){
        frameTable[j].bits = (frameTable[j].bits >> 1)|(frameTable[j].r_bit << 7);
        frameTable[j].r_bit = 0;
      }
    }

    //if page doesn't exist
    int flag1 = pageExists(frameTable,pageNum,n);
    if(flag1==-1){
      printf("0\n");
      int flag2 = freeFrame(frameTable,n);

      //if there is no free place
      if(flag2==-1){

        int flag3 = leastActive(frameTable,n);
        insertPage(frameTable,flag3,pageNum);

      //if there is a free place
      }else{

        insertPage(frameTable,flag2,pageNum);
        
      }
    //if page exists
    }else{
      printf("1\n");
      bSum+=1;
      frameTable[flag1].r_bit=1;
    }

    oldTick = newTick;
  }

  double ratio=(bSum)/(m-bSum);
  printf("%f\n", ratio);

  return 0;
}
