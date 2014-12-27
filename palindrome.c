#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 10
	
   int main(void)
   {
   char c=EOF;
	unsigned int len_max=128;
	unsigned int i=0;
	unsigned int current_size;
	current_size=len_max;
   char *ptr=malloc(len_max);

   /*
   Changing the pointer malloc'd will produce undefined behavior for free()
   If pointer incrementing were to be used after a malloc, the original starting
   address must be maintained and used at the argument to free().
   
   */
   	
	if(ptr!=NULL)
	{  	
   		while((c=getchar())!='\n'&& c!=EOF)
   		{
   			if(isalpha(c))
            ptr[i++]=(char)c; 
   			
   			if(i>=current_size)
   			{
   				
   				current_size=i+len_max;
   				ptr=realloc(ptr, current_size);
   				
   			}
   		}
   		
   		ptr[i]='\0';
   		printf("%s\n", ptr);
	      if(isPalindrome(ptr, i))
		printf("is a palindrome\n");
              else 
		printf("is not a palindrome\n");
   		
   		free(ptr);
   		ptr=NULL;
	}
		return 0;
   }

   int isPalindrome(char *ptr, int i)
   {
      int x = 0;
      int mid_point = i/2;
      char *ptr2=ptr; //ptr2 is at the end of the array//
      while(i>=mid_point)
         if(ptr[x++]!=ptr2[--i])
	{
            ptr2=NULL;
            return 0;
	}
      ptr2=NULL;
      return 1;


   }
