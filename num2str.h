/*
 Created by: 		Ahmed Gad
 Creation Date:	20SEP2018
 Functionality: to convert number to string

 */
#ifndef __NUM2STR_H__
#define __NUM2STR_H__
//-----------------------Type Definition Compiler and Architecture dependent ---------------------------------
typedef unsigned char  BOOLEAN;
typedef unsigned char  uint8_t;
typedef signed   char  int8_t;
typedef unsigned short uint16_t;
typedef signed   short int16_t;
typedef unsigned long  uint32_t;
typedef signed   long  int32_t;
typedef float          FP32;
typedef double         FP64;
typedef enum NUMBER{INTEGER,FLOAT,STRING} NUMBER_t;
void ftos(uint8_t * s, FP64 number, uint8_t length);
void itos(uint8_t * s, int number);
#endif
