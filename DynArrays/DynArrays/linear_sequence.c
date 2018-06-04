#include "linear_sequence.h"
const size_t initial_size = 16;
typedef struct {
	LSQ_IntegerIndexT cur_size;
	LSQ_IntegerIndexT allocated_size;
	LSQ_BaseTypeT *data;
}LSQ_Sequence_Header;

LSQ_IntegerIndexT get_new_allocated_size(LSQ_IntegerIndexT allocated_size) {
	//return allocated_size * 1.5;
	return (allocated_size << 1)-(allocated_size >> 1);
}
LSQ_HandleT LSQ_Resize(LSQ_HandleT handle, LSQ_IntegerIndexT new_size) {
	LSQ_Sequence_Header *sequence_header = handle;
	if (new_size > sequence_header->allocated_size) {
		sequence_header->data = realloc(sequence_header->data, get_new_allocated_size(sequence_header->allocated_size));
	}
	sequence_header->cur_size = new_size;
	return sequence_header;
}


/* ‘ункци€, создающа€ пустой контейнер. ¬озвращает назначенный ему дескриптор */
LSQ_HandleT LSQ_CreateSequence(void) {
	LSQ_Sequence_Header *sequence_header = malloc(sizeof(LSQ_Sequence_Header));
	sequence_header->allocated_size = initial_size;
	sequence_header->cur_size = 0;
	sequence_header->data = malloc(initial_size*sizeof(LSQ_BaseTypeT));
	return sequence_header;
}

/* ‘ункци€, уничтожающа€ контейнер с заданным дескриптором. ќсвобождает принадлежащую ему пам€ть */
void LSQ_DestroySequence(LSQ_HandleT handle) {
	LSQ_Sequence_Header *sequence_header = handle;
	free(sequence_header->data);
	free(sequence_header);
}

/* ‘ункци€, возвращающа€ текущее количество элементов в контейнере */
LSQ_IntegerIndexT LSQ_GetSize(LSQ_HandleT handle) {
	return ((LSQ_Sequence_Header*)handle)->cur_size;
}

/* ‘ункци€, добавл€юща€ элемент в начало контейнера */
void LSQ_InsertFrontElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {


}
/* ‘ункци€, добавл€юща€ элемент в конец контейнера */
void LSQ_InsertRearElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {


}
/* ‘ункци€, добавл€юща€ элемент в контейнер на позицию, указываемую в данный момент итератором. Ёлемент, на который  *
* указывает итератор, а также все последующие, сдвигаетс€ на одну позицию в конец.                                  */
void LSQ_InsertElementBeforeGiven(LSQ_IteratorT iterator, LSQ_BaseTypeT newElement) {

}