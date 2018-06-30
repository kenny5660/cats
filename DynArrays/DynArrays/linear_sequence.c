#include "linear_sequence.h"
#include <string.h>
const size_t initial_size = 0;

typedef struct {
	LSQ_IntegerIndexT cur_size;
	LSQ_IntegerIndexT allocated_size;
	LSQ_BaseTypeT *data;
}LSQ_Sequence_Header;

typedef struct {
	LSQ_HandleT parent_handler;
	//LSQ_IntegerIndexT offset;
	LSQ_BaseTypeT *data;
}LSQ_Interator_Header;


LSQ_IntegerIndexT get_new_allocated_size(LSQ_IntegerIndexT allocated_size) {
//return allocated_size * 2;
	if (allocated_size == 0) {
		return 1;
	}
	return (allocated_size << 1)-(allocated_size >> 1);
}
LSQ_HandleT LSQ_Resize(LSQ_HandleT handle, LSQ_IntegerIndexT new_size) {
	LSQ_Sequence_Header *sequence_header = handle;
	if (new_size >= sequence_header->allocated_size)
	{
		sequence_header->allocated_size = get_new_allocated_size(sequence_header->allocated_size);
		sequence_header->data = realloc(sequence_header->data, sequence_header->allocated_size *sizeof(LSQ_BaseTypeT));
	}
	if (new_size < (int)(sequence_header->allocated_size/1.5)) {
		sequence_header->allocated_size = (int)(sequence_header->allocated_size / 1.5);
		sequence_header->data = realloc(sequence_header->data, sequence_header->allocated_size * sizeof(LSQ_BaseTypeT));
	}
	sequence_header->cur_size = new_size;
	return sequence_header;
}

/* Функция, создающая пустой контейнер. Возвращает назначенный ему дескриптор */
LSQ_HandleT LSQ_CreateSequence(void) {
	LSQ_Sequence_Header *sequence_header = malloc(sizeof(LSQ_Sequence_Header));
	sequence_header->allocated_size = initial_size;
	sequence_header->cur_size = 0;
	sequence_header->data = malloc(initial_size*sizeof(LSQ_BaseTypeT));
	return sequence_header;
}
/* Функция, уничтожающая контейнер с заданным дескриптором. Освобождает принадлежащую ему память */
void LSQ_DestroySequence(LSQ_HandleT handle) {\
	if (handle == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Sequence_Header *sequence_header = handle;
	if (sequence_header->allocated_size == 0) {
		free(sequence_header->data);
	}
	free(sequence_header);
}
/* Функция, возвращающая текущее количество элементов в контейнере */
LSQ_IntegerIndexT LSQ_GetSize(LSQ_HandleT handle) {
	if (handle == LSQ_HandleInvalid) {
		return;
	}
	return ((LSQ_Sequence_Header*)handle)->cur_size;
}

/* Функция, определяющая, может ли данный итератор быть разыменован */
int LSQ_IsIteratorDereferencable(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	int ptrs_dif = interator_header->data - sequence_header->data;
	return ptrs_dif >= 0 && ptrs_dif < sequence_header->cur_size;
}
/* Функция, определяющая, указывает ли данный итератор на элемент, следующий за последним в контейнере */
int LSQ_IsIteratorPastRear(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	int ptrs_dif = interator_header->data - sequence_header->data;
	return ptrs_dif >= sequence_header->cur_size;
}
/* Функция, определяющая, указывает ли данный итератор на элемент, предшествующий первому в контейнере */
int LSQ_IsIteratorBeforeFirst(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	int ptrs_dif = interator_header->data - sequence_header->data;
	return ptrs_dif < 0;
}



/* Функция разыменовывающая итератор. Возвращает указатель на элемент, на который ссылается данный итератор */
LSQ_BaseTypeT* LSQ_DereferenceIterator(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	return ((LSQ_Interator_Header*)iterator)->data;
}

/* Следующие три функции создают итератор в памяти и возвращают его дескриптор */
/* Функция, возвращающая итератор, ссылающийся на элемент с указанным индексом */
LSQ_IteratorT LSQ_GetElementByIndex(LSQ_HandleT handle, LSQ_IntegerIndexT index) {
	if (handle == LSQ_HandleInvalid) {
		return LSQ_HandleInvalid;
	}
	if (index >= ((LSQ_Sequence_Header*)handle)->cur_size || index < 0) {
		return LSQ_HandleInvalid;
	}

	LSQ_Interator_Header *interator_header = malloc(sizeof(LSQ_Interator_Header));
	interator_header->parent_handler = handle;
	interator_header->data = ((LSQ_Sequence_Header*)handle)->data+index;
	return interator_header;
}
/* Функция, возвращающая итератор, ссылающийся на первый элемент контейнера */
LSQ_IteratorT LSQ_GetFrontElement(LSQ_HandleT handle) {
	if (handle == LSQ_HandleInvalid) {
		return LSQ_HandleInvalid;
	}
	if (0 == ((LSQ_Sequence_Header*)handle)->cur_size) {
		return LSQ_HandleInvalid;
	}
	LSQ_Interator_Header *interator_header = malloc(sizeof(LSQ_Interator_Header));
	interator_header->parent_handler = handle;
	interator_header->data = &((LSQ_Sequence_Header*)handle)->data[0];
	return interator_header;
};
/* Функция, возвращающая итератор, ссылающийся на последний элемент контейнера */
LSQ_IteratorT LSQ_GetPastRearElement(LSQ_HandleT handle) {
	if (handle == LSQ_HandleInvalid) {
		return LSQ_HandleInvalid;
	}
	if (0 == ((LSQ_Sequence_Header*)handle)->cur_size) {
		return LSQ_HandleInvalid;
	}
	LSQ_Interator_Header *interator_header = malloc(sizeof(LSQ_Interator_Header));
	interator_header->parent_handler = handle;
	//interator_header->data = &((LSQ_Sequence_Header*)handle)->data[((LSQ_Sequence_Header*)handle)->cur_size-1];
	interator_header->data = &((LSQ_Sequence_Header*)handle)->data[((LSQ_Sequence_Header*)handle)->cur_size];
	return interator_header;
}

/* Функция, уничтожающая итератор с заданным дескриптором и освобождающая принадлежащую ему память */
void LSQ_DestroyIterator(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	free(((LSQ_Interator_Header*)iterator));
}
/* Функция, перемещающая итератор на один элемент вперед */
void LSQ_AdvanceOneElement(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	interator_header->data ++;
}
/* Функция, перемещающая итератор на один элемент назад */
void LSQ_RewindOneElement(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	interator_header->data--;
}
/* Функция, перемещающая итератор на заданное смещение со знаком */
void LSQ_ShiftPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT shift) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	interator_header->data += shift;
}
/* Функция, устанавливающая итератор на элемент с указанным номером */
void LSQ_SetPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT pos) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	interator_header->data = sequence_header->data+pos;
}

/* Функция, добавляющая элемент в начало контейнера */
void LSQ_InsertFrontElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
	if (handle == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Sequence_Header *sequence_header = LSQ_Resize(handle, ((LSQ_Sequence_Header*)handle)->cur_size + 1);
		memmove(sequence_header->data + 1, sequence_header->data, (sequence_header->cur_size-1) * sizeof(LSQ_BaseTypeT));
	
	sequence_header->data[0] = element;
}
/* Функция, добавляющая элемент в конец контейнера */
void LSQ_InsertRearElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
	if (handle == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Sequence_Header *sequence_header = LSQ_Resize(handle, ((LSQ_Sequence_Header*)handle)->cur_size + 1);
	sequence_header->data[sequence_header->cur_size - 1] = element;
}
/* Функция, добавляющая элемент в контейнер на позицию, указываемую в данный момент итератором. Элемент, на который  *
* указывает итератор, а также все последующие, сдвигается на одну позицию в конец.                                  */
void LSQ_InsertElementBeforeGiven(LSQ_IteratorT iterator, LSQ_BaseTypeT newElement) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;
	sequence_header = LSQ_Resize(sequence_header, sequence_header->cur_size + 1);
	int shift_block_size = (sequence_header->data   - interator_header->data) + sequence_header->cur_size;
	memmove(interator_header->data + 1,interator_header->data, (shift_block_size-1) * sizeof(LSQ_BaseTypeT));
	*(interator_header->data) = newElement;
}

/* Функция, удаляющая первый элемент контейнера */
void LSQ_DeleteFrontElement(LSQ_HandleT handle) {
	if (handle == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Sequence_Header *sequence_header = handle;
	if (sequence_header->cur_size == 0) {
		return;
	}
	
	memmove(sequence_header->data, sequence_header->data+1,(sequence_header->cur_size-1) * sizeof(LSQ_BaseTypeT));
	sequence_header = LSQ_Resize(sequence_header, sequence_header->cur_size - 1);
}
/* Функция, удаляющая последний элемент контейнера */
void LSQ_DeleteRearElement(LSQ_HandleT handle) {
	if (handle == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Sequence_Header *sequence_header = handle;
	if (sequence_header->cur_size == 0) {
		return;
	}
	sequence_header = LSQ_Resize(sequence_header, sequence_header->cur_size - 1);
}
/* Функция, удаляющая элемент контейнера, указываемый заданным итератором. Все последующие элементы смещаются на     *
* одну позицию в сторону начала.                                                                                    */
void LSQ_DeleteGivenElement(LSQ_IteratorT iterator) {
	if (iterator == LSQ_HandleInvalid) {
		return;
	}
	LSQ_Interator_Header *interator_header = iterator;
	LSQ_Sequence_Header *sequence_header = interator_header->parent_handler;

	int shift_block_size = sequence_header->data + (sequence_header->cur_size-1)  - interator_header->data;
	memmove(interator_header->data, interator_header->data + 1, shift_block_size * sizeof(LSQ_BaseTypeT));
	sequence_header = LSQ_Resize(sequence_header, sequence_header->cur_size - 1);
}