#include<stdio.h>
#include<stdlib.h>
   #define BITS_PER_CHAR (8)       /* not true on all machines! */
   #define MAX_STRING_SIZE (128)   /* we'll stop hashing after this many */
   #define MAX_BITS (BITS_PER_CHAR * MAX_STRING_SIZE)
    /* treat strings as base-256 integers */
    /* with digits in the range 1 to 255 */

    unsigned long int  hashdiv(const char *s, unsigned long int m)
    {
        unsigned long h;
        unsigned const char *us;
   
       /* cast s to unsigned const char * */
       /* this ensures that elements of s will be treated as having values >= 0 */
       us = (unsigned const char *) s;
   
       h = 0;
       while(*us != '\0')
       {
           h = (h * (256) + *us) % m;
           us++;
    	} 
 
       return h; 
     }
   
   unsigned long int hashmul(const char *s)
   {
       unsigned long h;
       unsigned const char *us;
   
       /* cast s to unsigned const char * */
       /* this ensures that elements of s will be treated as having values >= 0 */
       us = (unsigned const char *) s;
   
       h = 0;
       while(*us != '\0') {
           h = h * 37 + *us;
           us++;
       } 
   
       return h;
   } 
   /* implements universal hashing using random bit-vectors in x */
   /* assumes number of elements in x is at least BITS_PER_CHAR * MAX_STRING_SIZE */
   

   
   unsigned long int hashuniv(const char *s, unsigned long int x[])
   {
       unsigned long h;
       unsigned const char *us;
       int i;
       unsigned char c;
       int shift;
   
       /* cast s to unsigned const char * */
       /* this ensures that elements of s will be treated as having values >= 0 */
       us = (unsigned const char *) s;
   
       h = 0;
       for(i = 0; *us != 0 && i < MAX_BITS; us++) {
           c = *us;
           for(shift = 0; shift < 8; shift++, i++) {
               /* is low bit of c set? */
               if(c & 0x1) {
                   h ^= x[i];
               }
               
               /* shift c to get new bit in lowest position */
               c >>= 1;
           }
       }
   
       return h;
   }
   
   
void main()
{
	int choice, key, value, n, c;
	unsigned long int x[30];
	char a[20];

	 printf("Enter Elements to insert in hash table :\n");
	 scanf("%s",a);
	 printf("The hash for the element using universal hashing is: %lu\n",hashuniv(a,x));
	 printf("The hash for the element using multiplication  hashing is: %lu\n",hashmul(a));
	 printf("The hash for the element using division  hashing is: %lu\n",hashdiv(a,256));
 
	
 
	
 
}
