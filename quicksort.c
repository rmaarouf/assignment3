#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "simulator.h"

static int psize;
static int winsize;

void swap(int i, int j){
  int temp = get(i);
  put(i, get(j));
  put(j, temp);
}

int partition(int left, int right){
  int pivot, begin, end, i;
 
  pivot=get(right);
  begin = left - 1;
  for (i = left; i <= right-1; i++)
    {
      if(get(i)<=pivot)
	{
	  begin++;
	  swap(begin, i);
	}
    }
  swap(begin+1,right);
  return(begin+1);
}

void quicksort(int begin,int end)
{
  int q;
  while(begin < end)
    {
      q = partition(begin, end);

      if (q - begin < end - q)
	{
	  quicksort(begin, q-1);
	  begin = q + 1;
	}
      else
	{
	  quicksort(q + 1, end);
	  end = q-1;
	}
    }    	  
}

void process()
{
  srand(time(NULL));
  int N, i;
  printf("Please enter the number of keys to sort: ");
  scanf("%d", &N);
  printf("Sorting %d keys\n", N);

  init(psize, winsize);
  
  i = 0;
  for (i=0;i<N;i++)
    {
      put(i, rand());
    }

  quicksort(0, N-1);
  done();
}


int main(int argc, char *argv[]){

  psize = atoi(argv[1]);
  winsize = atoi(argv[2]);
  process();
}

