#include <stdio.h>

int ISSET(unsigned char BitSet, int BitPos);
void ADDBIT(unsigned char *BitSet, int BitPos);
void DELBIT(unsigned char *BitSet, int BitPos);
void PrintBits(unsigned char BitSet);

int main(){
	unsigned char x = 93;
	PrintBits(x);
	ADDBIT(&x, 1);
	PrintBits(x);
	DELBIT(&x, 1);
	PrintBits(x);
	return 0;
}

int ISSET(unsigned char BitSet, int BitPos){
	unsigned char bitmask = 0x01;
	bitmask = bitmask << BitPos;
	
	if((BitSet & bitmask) > 0){
		return 1;
	}else{
		return 0;
	}
}

void ADDBIT(unsigned char *BitSet, int BitPos){
	unsigned char bitmask = 0x01;
	bitmask = bitmask << BitPos;
	
	*BitSet = *BitSet | bitmask;
}

void DELBIT(unsigned char *BitSet, int BitPos){
	unsigned char bitmask = 0x01;
	bitmask = ~(bitmask << BitPos);
	
	*BitSet = *BitSet & bitmask;
}

void PrintBits(unsigned char BitSet){
	for(int i = 0; i < 8; i++){
		//(BitSet >> i) right shifts the BitSet until the bit of interest is in the lowest order position
		//& 0x01 preforms a & operation with the mask 0000 0001
		printf("The bit in position %d is %d \n", i, ((BitSet >> i) & 0x01));
	}
}