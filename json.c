/*
 Created by: 		Ahmed Gad
 Creation Date:	20SEP2018
 Functionality:  to format data in json format

 */
#include <string.h>
#include "json.h"
/************************************************************************
** function name: jW_Start_obj
** function description: put cerly opening bracket { in the first index of JS
** inputs: -JS : json string buffer
		   -JS_start: index to put {
** output: None
************************************************************************/
void jW_Start_obj(uint8_t * JS,uint16_t * JS_start)
{
	//if(!(*JS_start))
	JS[(*JS_start)++]='{';
	return;
}
/************************************************************************
** function name: jW_End_obj
** function description: put cerly closing bracket } in the last index of JS
** inputs: -JS : json string buffer
		   -JS_len: index to put }
** output: None
************************************************************************/
void jW_End_obj(uint8_t * JS,uint16_t *  JS_len)
{
	JS[(*JS_len)-1]='}';
}
/************************************************************************
** function name: jW_String
** function description: add key and value of string token in JS
** inputs: -key: attribute always string
		   -value: value of corresponding key and it must be string
		   -JS: json string buffer
		   -JS_idx: current index of JS
** output: None
************************************************************************/
void jW_String(uint8_t * key ,uint8_t * value,uint8_t * JS,uint16_t * JS_idx)
{
    uint8_t idx=0;
    uint8_t key_len=strlen(key);
    uint8_t value_len=strlen(value);

    JS[(*JS_idx)++]='\"';

    for(idx=0;idx<(key_len);idx++,(*JS_idx)++)
        JS[(*JS_idx)]=key[idx];
    JS[(*JS_idx)++]='\"';
    JS[(*JS_idx)++]=':';
    if(value){
            JS[(*JS_idx)++]='\"';
            for(idx=0;idx<(value_len);idx++,(*JS_idx)++)
                JS[(*JS_idx)]=value[idx];
            JS[(*JS_idx)++]='\"';
    }else{
    	JS[(*JS_idx)++]='n';
    	JS[(*JS_idx)++]='u';
    	JS[(*JS_idx)++]='l';
    	JS[(*JS_idx)++]='l';
    }

    JS[(*JS_idx)++]=',';
}
/************************************************************************
** function name: jW_Object
** function description: add key and value of object token in JS
** inputs: -key: attribute always string
		   -value: value of corresponding key and it must be object_string
		   -JS: json string buffer
		   -JS_idx: current index of JS
** output: None
************************************************************************/
void jW_Object(uint8_t * key ,uint8_t * value,uint8_t * JS,uint16_t * JS_idx)
{
    uint16_t idx=0;
    uint8_t key_len=strlen(key);
    uint8_t value_len=strlen(value);

    JS[(*JS_idx)++]='\"';

    for(idx=0;idx<(key_len);idx++,(*JS_idx)++)
        JS[(*JS_idx)]=key[idx];
    JS[(*JS_idx)++]='\"';
    JS[(*JS_idx)++]=':';
    for(idx=0;idx<(value_len);idx++,(*JS_idx)++)
                JS[(*JS_idx)]=value[idx];
    JS[(*JS_idx)++]=',';
}
/************************************************************************
** function name: jW_Num
** function description: add key and value of number token in JS
** inputs: -key: attribute always string
		   -value: value of corresponding key and it must be number
		   -fI: indicate if fi is equal 1 this float number else fi equal 0 this integer number
		   -JS: json string buffer
		   -JS_idx: current index of JS
		   -
** output: None
************************************************************************/

void jW_Num(uint8_t * key ,FP64 value,NUMBER_t IntegerOrFloat,uint8_t * JS,uint16_t * JS_idx)
{
     uint8_t idx=0,num[15];
    uint8_t key_len=strlen(key);
    JS[(*JS_idx)++]='\"';

    for(idx=0;idx<(key_len);idx++,(*JS_idx)++)
        JS[(*JS_idx)]=key[idx];
    JS[(*JS_idx)++]='\"';
    JS[(*JS_idx)++]=':';
    if(IntegerOrFloat==FLOAT)
		ftos(num,value,5);//5 number of characters +1
	else if(IntegerOrFloat==INTEGER)
		itos(num,value);
	else
		return;//Error invalid argument value

    for(idx=0;num[idx]!=0;(*JS_idx)++)
		JS[(*JS_idx)]=num[idx++];
    JS[(*JS_idx)++]=',';
}
/************************************************************************
** function name: jW_array
** function description: add key and value of array token in JS inside sqaure bracketss
** inputs: -key: attribute always string
-value: value of corresponding key and it must be string
-JS: json string buffer
-JS_idx: current index of JS
** output: None
************************************************************************/


void jW_array(uint8_t * key, uint8_t * value,uint8_t * JS, uint16_t * JS_idx) {

	uint8_t idx=0;
    uint8_t key_len=strlen(key);
    uint8_t value_len=strlen(value);

	JS[(*JS_idx)++]='\"';

    for(idx=0;idx<(key_len);idx++,(*JS_idx)++)
        JS[(*JS_idx)]=key[idx];
    JS[(*JS_idx)++]='\"';
    JS[(*JS_idx)++]=':';

	JS[(*JS_idx)++] = '\[';
 for(idx=0;idx<(value_len);idx++,(*JS_idx)++)
                JS[(*JS_idx)]=value[idx];

	JS[(*JS_idx)++] = '\]';
	JS[(*JS_idx)++] = ',';
}
