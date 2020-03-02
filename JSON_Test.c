#include <stdio.h>
#include <stdlib.h>
#include "json.h"
int main()
{
    unsigned char JSON[512]={0};
    unsigned short JSON_Index=0;

    unsigned char IntNum=227;
    float FloatNum=3.14;
    char arr1[]="Ali,Gad,Henry";
    char arr2[]="0,1,2";
    char str[]="JSON String";
    char obj[]="{\"string\":\"Hello\",\"IntNum\":3}";

    jW_Start_obj(JSON,&JSON_Index);
	
    jW_String("myString",str,JSON,&JSON_Index);
    jW_Num("myIntegerNumber",IntNum,INTEGER,JSON,&JSON_Index);
    jW_Num("myFloatNumber",FloatNum,FLOAT,JSON,&JSON_Index);
    jW_array("myArray1",arr1,JSON,&JSON_Index);
    jW_array("myArray2",arr2,JSON,&JSON_Index);
    jW_Object("myObject",obj,JSON,&JSON_Index);

    jW_End_obj(JSON,&JSON_Index);

    printf("your JSON is\n %s\n",JSON);
    return 0;
}
