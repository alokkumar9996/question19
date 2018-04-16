//***************************************** QUESTION NO 8 ***********************************************


#include <stdio.h>
#include <stdlib.h>

int main () 
{

   int n[11];
   int a[11];
   int b[10];
   int p[25];

 /* n is an array of 10 integers */
  
 int i,j,temp,x=10,k;
   srand(time(0));
 /* students purchasing gifts randomly from different gift shops */         
    printf("\n no of gifts purchased by students:\n");
for ( i = 1; i < 11; i++ )
 {
        
  n[ i ] =  rand() % 100; 
  a[i]=n[i];
/* set gifts to students */
   
}
 
  /* output each array element's value */
  
 for (j = 1; j<11; j++ ) 
{
      printf("Student[%d] = %d\n", j, n[j] );
   }
   
  
  //sort array
    
for(i=1;i< 11;i++)
    
{
        for(j=i+1;j< 11;j++)
       
 {
            if(n[i]< n[j])
          
  {
                temp  =n[i];
 		n[i]  =n[j];
		n[j]  =temp;
			    
          
  }
       
 }
   
 }
//printing sorted array
        // printf("sorted array:\n");
        // for(i=1;i<11;i++)
        // {
        //     printf("n[%d]=%d\n",i,n[i]);
        // }

   
   //Order in which billing is done by accountant
//printf("\nOrder in which billing is done by accountant:\n");

    int num=0;
    int count=0;
    for(i=1;i< 11;i++)
    {
    
      
            for(j=1;j<11;j++)
            {
                if(n[i]==a[j])
               {
              //  printf("\nStudent no:%d ",j);
                p[num]=j;
                num++;
                count++;
               }
               
            }
            
    }
    
    //printing new array:
    // printf("\nprinting new array:\n");
    // for(i=0;i<count;i++)
    // {
    //     printf("\nstudent[%d]=%d",i+1,p[i]);
    // }
    
    
    //assigning 0 to duplicate values
    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(p[i]==p[j])
            {
                p[j]=0;
            }
        }
    }
    
    printf("\n actual order of billing done by accountant:\n");
    
    for(i=0;i<count;i++)
    {
        if(p[i]!=0)
        {
            printf("\nstudent[%d]",p[i]);
        }
    }
  
 return 0;

}











