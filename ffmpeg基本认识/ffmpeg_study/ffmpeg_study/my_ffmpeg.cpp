#include <stdio.h>
#include <stdlib.h>

//C/C++��ָ࣬ʾ����������C���Խ��б���
extern "C"
{
#include "libavcodec\avcodec.h"
};

void main(){
	printf("%s", avcodec_configuration());	

	system("pause");
}
