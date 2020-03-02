/*
 Created by: 		Ahmed Gad
 Creation Date:	20SEP2018
 Functionality:  to format data in json format


 */
#ifndef __JSON_H__
#define __JSON_H__
#include "num2str.h"
//---------------------- Methods--------------------------------
void jW_Start_obj(uint8_t * JS,uint16_t * JS_start);
void jW_End_obj(uint8_t * JS,uint16_t *  JS_len);
void jW_String(uint8_t * key ,uint8_t * value,uint8_t * JS,uint16_t * JS_idx);
void jW_Object(uint8_t * key ,uint8_t * value,uint8_t * JS,uint16_t * JS_idx);
void jW_Num(uint8_t * key ,FP64 value,NUMBER_t IntegerOrFloat,uint8_t * JS,uint16_t * JS_idx);
void jW_array(uint8_t * key, uint8_t * value, uint8_t * JS, uint16_t * JS_idx);
#endif
