#include "linear_sequence.h"
#include <string.h>
const size_t initial_size = 16;
typedef struct {
	LSQ_IntegerIndexT cur_size;
	LSQ_IntegerIndexT allocated_size;
	LSQ_BaseTypeT *data;
}LSQ_Sequence_Header;

typedef struct {
	LSQ_HandleT parent_handler;
	LSQ_BaseTypeT *data;
}LSQ_Interator_Header;


LSQ_IntegerIndexT get_new_allocated_size(LSQ_IntegerIndexT allocated_size) {
	//return allocated_size * 1.5;
	return (allocated_size << 1)-(allocated_size >> 1);
}
LSQ_HandleT LSQ_Resize(LSQ_HandleT handle, LSQ_IntegerIndexT new_size) {
	LSQ_Sequence_Header *sequence_header = handle;
	if (new_size > sequence_header->allocated_size) {
		sequence_header->data = realloc(sequence_header->data, get_new_allocated_size(sequence_header->allocated_size)*sizeof(LSQ_BaseTypeT));
	}
	sequence_header->cur_size = new_size;
	return sequence_header;
}

/* �������, ��������� ������ ���������. ���������� ����������� ��� ���������� */
LSQ_HandleT LSQ_CreateSequence(void) {
	LSQ_Sequence_Header *sequence_header = malloc(sizeof(LSQ_Sequence_Header));
	sequence_header->allocated_size = initial_size;
	sequence_header->cur_size = 0;
	sequence_header->data = malloc(initial_size*sizeof(LSQ_BaseTypeT));
	return sequence_header;
}
/* �������, ������������ ��������� � �������� ������������. ����������� ������������� ��� ������ */
void LSQ_DestroySequence(LSQ_HandleT handle) {
	LSQ_Sequence_Header *sequence_header = handle;
	free(sequence_header->data);
	free(sequence_header);
}
/* �������, ������������ ������� ���������� ��������� � ���������� */
LSQ_IntegerIndexT LSQ_GetSize(LSQ_HandleT handle) {
	return ((LSQ_Sequence_Header*)handle)->cur_size;
}

/* �������, ������������, ����� �� ������ �������� ���� ����������� */
int LSQ_IsIteratorDereferencable(LSQ_IteratorT iterator) {
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	int ptrs_dif = interator_header->data - sequence_header->data;
	return ptrs_dif >= 0 && ptrs_dif < sequence_header->cur_size * sizeof(LSQ_BaseTypeT);
}
/* �������, ������������, ��������� �� ������ �������� �� �������, ��������� �� ��������� � ���������� */
int LSQ_IsIteratorPastRear(LSQ_IteratorT iterator) {
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	int ptrs_dif = interator_header->data - sequence_header->data;
	return ptrs_dif > sequence_header->cur_size * sizeof(LSQ_BaseTypeT);
}
/* �������, ������������, ��������� �� ������ �������� �� �������, �������������� ������� � ���������� */
int LSQ_IsIteratorBeforeFirst(LSQ_IteratorT iterator) {
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	int ptrs_dif = interator_header->data - sequence_header->data;
	return ptrs_dif < 0;
}



/* ������� ���������������� ��������. ���������� ��������� �� �������, �� ������� ��������� ������ �������� */
LSQ_BaseTypeT* LSQ_DereferenceIterator(LSQ_IteratorT iterator) {
	return ((LSQ_Interator_Header*)iterator)->data;
}

/* ��������� ��� ������� ������� �������� � ������ � ���������� ��� ���������� */
/* �������, ������������ ��������, ����������� �� ������� � ��������� �������� */
LSQ_IteratorT LSQ_GetElementByIndex(LSQ_HandleT handle, LSQ_IntegerIndexT index) {
	LSQ_Interator_Header *interator_header = malloc(sizeof(LSQ_Interator_Header));
	interator_header->parent_handler = handle;
	interator_header->data = &((LSQ_Sequence_Header*)handle)->data[index];
	return interator_header;
}
/* �������, ������������ ��������, ����������� �� ������ ������� ���������� */
LSQ_IteratorT LSQ_GetFrontElement(LSQ_HandleT handle) {
	LSQ_Interator_Header *interator_header = malloc(sizeof(LSQ_Interator_Header));
	interator_header->parent_handler = handle;
	interator_header->data = &((LSQ_Sequence_Header*)handle)->data[0];
	return interator_header;
};
/* �������, ������������ ��������, ����������� �� ��������� ������� ���������� */
LSQ_IteratorT LSQ_GetPastRearElement(LSQ_HandleT handle) {
	LSQ_Interator_Header *interator_header = malloc(sizeof(LSQ_Interator_Header));
	interator_header->parent_handler = handle;
	interator_header->data = &((LSQ_Sequence_Header*)handle)->data[((LSQ_Sequence_Header*)handle)->cur_size-1];
	return interator_header;
}

/* �������, ������������ �������� � �������� ������������ � ������������� ������������� ��� ������ */
void LSQ_DestroyIterator(LSQ_IteratorT iterator) {
	free(((LSQ_Interator_Header*)iterator));
}
/* �������, ������������ �������� �� ���� ������� ������ */
void LSQ_AdvanceOneElement(LSQ_IteratorT iterator) {
	LSQ_Interator_Header *interator_header = iterator;
	interator_header->data += sizeof(LSQ_BaseTypeT);
}
/* �������, ������������ �������� �� ���� ������� ����� */
void LSQ_RewindOneElement(LSQ_IteratorT iterator) {
	LSQ_Interator_Header *interator_header = iterator;
	interator_header->data -= sizeof(LSQ_BaseTypeT);
}
/* �������, ������������ �������� �� �������� �������� �� ������ */
void LSQ_ShiftPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT shift) {
	LSQ_Interator_Header *interator_header = iterator;
	interator_header->data += shift*sizeof(LSQ_BaseTypeT);
}
/* �������, ��������������� �������� �� ������� � ��������� ������� */
void LSQ_SetPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT pos) {
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	interator_header->data = sequence_header->data+pos * sizeof(LSQ_BaseTypeT);
}

/* �������, ����������� ������� � ������ ���������� */
void LSQ_InsertFrontElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
	LSQ_Sequence_Header *sequence_header = LSQ_Resize(handle, ((LSQ_Sequence_Header*)handle)->cur_size + 1);
	memmove(sequence_header->data, sequence_header->data + sizeof(LSQ_BaseTypeT), sequence_header->cur_size * sizeof(LSQ_BaseTypeT));
	sequence_header->data[0] = element;
}
/* �������, ����������� ������� � ����� ���������� */
void LSQ_InsertRearElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
	LSQ_Sequence_Header *sequence_header = LSQ_Resize(handle, ((LSQ_Sequence_Header*)handle)->cur_size + 1);
	sequence_header->data[sequence_header->cur_size - 1] = element;
}
/* �������, ����������� ������� � ��������� �� �������, ����������� � ������ ������ ����������. �������, �� �������  *
* ��������� ��������, � ����� ��� �����������, ���������� �� ���� ������� � �����.                                  */
void LSQ_InsertElementBeforeGiven(LSQ_IteratorT iterator, LSQ_BaseTypeT newElement) {
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	sequence_header = LSQ_Resize(sequence_header, sequence_header->cur_size + 1);
	int shift_block_size = sequence_header->data+sequence_header->cur_size * sizeof(LSQ_BaseTypeT)-interator_header->data;
	memmove(interator_header->data, interator_header->data + sizeof(LSQ_BaseTypeT), shift_block_size);
	*(interator_header->data) = newElement;
}

/* �������, ��������� ������ ������� ���������� */
void LSQ_DeleteFrontElement(LSQ_HandleT handle) {
	LSQ_Sequence_Header *sequence_header = handle;
	LSQ_BaseTypeT *new_data = malloc((sequence_header->cur_size - 1) * sizeof(LSQ_BaseTypeT));
	memmove(sequence_header->data+ sizeof(LSQ_BaseTypeT), new_data, (sequence_header->cur_size - 1) * sizeof(LSQ_BaseTypeT));
	free(sequence_header->data);
	sequence_header->data = new_data;
}
/* �������, ��������� ��������� ������� ���������� */
void LSQ_DeleteRearElement(LSQ_HandleT handle) {
	LSQ_Sequence_Header *sequence_header = handle;
	sequence_header->cur_size -= 1;
}
/* �������, ��������� ������� ����������, ����������� �������� ����������. ��� ����������� �������� ��������� ��     *
* ���� ������� � ������� ������.                                                                                    */
void LSQ_DeleteGivenElement(LSQ_IteratorT iterator) {
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	LSQ_BaseTypeT *new_data = malloc((sequence_header->cur_size - 1) * sizeof(LSQ_BaseTypeT));
	memmove(sequence_header->data, new_data, interator_header->data - sequence_header->data - sizeof(LSQ_BaseTypeT));
	memmove(sequence_header->data + sizeof(LSQ_BaseTypeT), new_data, sequence_header->data + sequence_header->cur_size * sizeof(LSQ_BaseTypeT) - interator_header->data - sizeof(LSQ_BaseTypeT));
	free(sequence_header->data);
	sequence_header->data = new_data;
}