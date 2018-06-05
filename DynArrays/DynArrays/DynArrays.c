// DynArrays.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include "linear_sequence.h"

int main()
{
	int size;
	LSQ_HandleT  m  = LSQ_CreateSequence();
	LSQ_IteratorT iter;
	for (int i = 0; i < 32; ++i) {
		LSQ_InsertRearElement(m, i);
	}
	for (int i = 0; i > -32; --i) {
		LSQ_InsertFrontElement(m, i);
	}
	size = LSQ_GetSize(m);
	iter = LSQ_GetElementByIndex(m,5);
	//LSQ_ShiftPosition(iter,-5);
	LSQ_DeleteGivenElement(iter);
	int boo = LSQ_IsIteratorBeforeFirst(iter);
	//LSQ_SetPosition(iter, 25);
	int elem = *LSQ_DereferenceIterator(iter);
	size = LSQ_GetSize(m);
    return 0;
}

