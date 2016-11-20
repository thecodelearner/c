#include <stdio.h>

int array[100], position, c, n, value, ch;
int del();
int ins();

int main()
{
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
 
   printf("Enter %d elements\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

   do
      {
         printf("Menu\n");
         printf("1. insertion\n");
         printf("2. deletion\n");
         printf("1 or 2 ?\t:");
         scanf("%d", &ch);

         switch(ch)
         {
            case 1: ins();
            break;
            case 2: del();
            break;
         }
      } while (ch < 3);
 
   return 0;
}

int ins()
{
   printf("Enter the location where you wish to insert an element\n");
   scanf("%d", &position);
 
   printf("Enter the value to insert\n");
   scanf("%d", &value);
 
   for (c = n - 1; c >= position - 1; c--)
      array[c+1] = array[c];
 
   array[position-1] = value;
 
   printf("Resultant array is\n");
 
   for (c = 0; c <= n; c++)
      printf("%d\n", array[c]);
 
   return 0;
}

int del()
{
    printf("Enter the location where you wish to delete element\n");
   scanf("%d", &position);
 
   if ( position >= n+1 )
      printf("Deletion not possible.\n");
   else
   {
      for ( c = position - 1 ; c < n - 1 ; c++ )
         array[c] = array[c+1];
 
      printf("Resultant array is\n");
 
      for( c = 0 ; c < n - 1 ; c++ )
         printf("%d\n", array[c]);
   }
   return 0;
}