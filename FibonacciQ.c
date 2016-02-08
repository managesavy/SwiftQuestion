/*In the programming language of your choice, write a program 
generating the first n Fibonacci numbers F(n), printing ...
- ... "Buzz" when F(n) is divisible by 3.
- ... "Fizz" when F(n) is divisible by 5.
- ... "BuzzFizz" when F(n) is prime.
- ... the value F(n) otherwise.
*/

/*
* Author : Navjot (Joti) Singh Dhalla
* Date 	 : 02/07/2016
*/

#include <math.h>
#include <stdio.h>
#include <limits.h>

#define ISPRIME			1
#define ISNOTPRIME		0

/***********************************************************************************
 * Function:        int isPrime(unsigned long long parm)
 *
 * PreCondition:    none
 *
 * Input:       	parameter to checked
 *                  
 * Output:         	none  
 *
 * Side Effects:    none
 *
 * Overview:        Test if number is prime. Algorithm is to check if parm 
 * 					is divisible by any integer less than or equal to sqrt(parm). 
 * 					If divisible, it's prime otherwise not
 *
 * Note:          	I could have used more complex algorithm such as "AKS", 
 * 				    but I think it's outside the scope of an interview question.
 ***********************************************************************************/
int isPrime(unsigned long long parm){
  
  static unsigned long long numb;
  
  for(numb = 2; numb <= (unsigned long long)sqrt(parm); numb++){
  
	if((parm%numb) == 0)
		return ISNOTPRIME;
  }
	  
  return ISPRIME;
}

/***************************************************************************************
 * Function:        int main()
 *
 * PreCondition:    none
 *
 * Input:       	none
 *                  
 * Output:         	none  
 *
 * Side Effects:    none
 *
 * Overview:        This is the main function
 *
 * Note:          	The limitation of this program is that it could work max for F(93)
 ***************************************************************************************/
int main()
{
  static unsigned long long t1, t2, n, qNumb, count;
  
  printf("Enter n for F(n) Fibonacci number of terms (n >= 0 and n <= 93):\r\n");
  scanf("%llu", &n);
   
  /* For first two terms, just print the numbers */ 
  if((n <= 1)&&(n > 0)){
	printf("\r\n%llu", n);  
    return 0;
  }
  else if(n == 2){
	printf("\r\n%llu", (n-1));  
    return 0;  
  }
	  
  /* count is 3 because first three terms are already tested. */
  count = 3;
  
  /* Initialize two terms t1 and t2; t0 was 0 */
  t1 = 1;
  t2 = 1;
  
  /* Just basic implementation of Fibonacci Function F(n+1) = F(n) + F(n-1) */
  while(count <= n){
    
    qNumb = t1+t2;
    t1 = t2;
    t2 = qNumb;
    ++count;
  }

  /* Print the Fibonacci F(n) value */
  printf("\r\nThe F(%llu) is %llu", n, qNumb);
  
  /* Test number for various conditions, and display as mentioned */
	  
	if(qNumb == 2){ /* 2 is prime number */
		
		printf("\r\nBuzzFizz");
		return 0;
	}
	else {

		if((qNumb % 3) == 0){
			printf("\r\nBuzz");
			if((qNumb % 5) == 0)
				printf("\r\nFizz");
		}	
		else if((qNumb % 5) == 0)
			printf("\r\nFizz");
		else if((qNumb % 2) == 0)
			printf("\r\n%llu", qNumb);	
		else if(isPrime(qNumb))
			printf("\r\nBuzzFizz");
		else
			printf("\r\n%llu", qNumb);
  
		return 0;
	}
}

/***********************************EOF***********************************************/
