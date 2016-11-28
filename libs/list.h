#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>
#include <stdio.h>

typedef struct list_element_s {
    struct list_element_s* next;

	void* start;
	int isFree;
	size_t dataSize;
} list_element_t;

typedef struct list_s {
    list_element_t* head;
    list_element_t* tail;
    uint32_t size;
} list_t;

void
list_ctor(list_t* list);

list_element_t*
get_previous_element(list_t* list, list_element_t* element);

void
list_push_middle(list_t* list, list_element_t* listElement, list_element_t* element);

void
list_push_back(list_t* list, list_element_t* element);

void
list_push_front(list_t* list, list_element_t* element);

void
list_remove_middle(list_t* list, list_element_t* element);

list_element_t*
list_pop_back(list_t* list);

list_element_t*
list_pop_front(list_t* list);

#endif
