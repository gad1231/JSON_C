#include "num2str.h"
/********************************************************
**function description: convert from floating number to string
**input: pointer to string,floating number , length
**output: none
note: the length musn't exceede the sizeof(string)
***********************************************************/
void ftos(uint8_t * s, FP64 number, uint8_t length)
{
	 uint8_t s_index = 0; // G:start of index of integer part and then it will be the start of index of firiction part
	 uint8_t index = 0, temp_index = 0;
	 int32_t i_part = 0;
	 FP64 f_part = 0;
	 uint8_t icount = 0; // to count digits of integral part even though it's -ve
	 uint8_t digits_after_point = 0;
	 //uint32_t hold_f_part = 0; // to hold firction part as integer part
	 /*if number is - ve put sign (-) at the first element in array*/
	  if (number<0)
	  {
	   s[index++] = '-';
	   s_index++;
	   number *= -1;
	   icount++;
	  }
	 i_part = (int32_t)number; // G: store integer part
	 f_part = (number)-((FP64)i_part); // store firction part

	  if (0 == i_part)
	  {
	   s[index++] = 48;
	   icount++;
	  }
	  else
	  {
	   while (i_part>0)
		{
		 s[index++] = (i_part % 10) + 48;
		 i_part /= 10;
		 icount++;
		}
	   reverse(s, index, s_index);
	  }
	 s[index++] = '.';

	 /*convert firction into integer number */
	 digits_after_point = length - (icount + 2); // to know how many digits of friction should be stored , +2 because '-' &'\0' count as 2 charachter
	  while (digits_after_point)
	  {
	   f_part *= 10;
	   s[index++] = (uint8_t)f_part + 48; // store each digit as a chrachter
	   f_part -= (uint8_t)f_part; // contains the rest of friction only
	   digits_after_point--;
	  }
	 s[index++] = '\0';

}
/********************************************************
**function description: convert from integer number to string
**input: pointer to string,integer number
**output: none
***********************************************************/
void itos(uint8_t * s, int number){
    uint8_t index=0,s_index=0;
if(!number)
   { s[index++]='0';
   	 s[index]=0;
    return;
   }
 if (number<0)
	  {
	   s[index++] = '-';
	   s_index++;
	   number *= -1;
	  }
	  while (number>0)
		{
		 s[index++] = (number % 10) + 48;
		 number /= 10;
		}
	  if(index!=1) // to not call fn if number is only one digit
	  	reverse(s, index, s_index);
	  s[index]=0;
	 }
/********************************************************
**function describtion: reverse the contents of string
**input: pointer to string,length of string ,start index
**output: none
***********************************************************/
void reverse(uint8_t* s, uint8_t len, uint8_t start_index)
{
	uint8_t j = len - 1, temp = 0;
	while (start_index<j)
	{
		temp = s[j];
		s[j--] = s[start_index];
		s[start_index++] = temp;
	}
}