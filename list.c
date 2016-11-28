#include "list.h"

#include <stdlib.h>
#include <stdio.h>

void
list_ctor(list_t* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

list_element_t*
get_previous_element(list_t* list, list_element_t* element)
{
	list_element_t* previous = list->head;

	if (!list->head) {
		return NULL;
	}
	else if (element == list->head) {
		return list->head;
	}
	else {
		while (previous->next != element) {
			previous = previous->next;
		}

		return previous;
	}
}

void
list_push_middle(list_t* list, list_element_t* listElement, list_element_t* element)
{
	list_element_t* nextListElement = listElement->next;

	if (listElement == list->tail) {
		listElement->next = element;
		list->tail = element;
	}
	else {
		element->next = nextListElement;
		listElement->next = element;
	}
	list->size++;
}

void
list_push_back(list_t* list, list_element_t* element)
{
    element->next = NULL;
    if (list->tail == NULL) {
        list->head = element;
    }
    else {
        list->tail->next = element;
    }
    list->tail = element;
    list->size++;
}

void
list_push_front(list_t* list, list_element_t* element)
{
    if (list->head == NULL) {
        element->next = NULL;
        list->tail = element;
    }
    else {
        element->next = list->head;
    }
    list->head = element;
    list->size++;
}

void
list_remove_middle(list_t* list, list_element_t* element)
{
	list_element_t* previous = list->head;

	while (previous->next != element) {
		previous = previous->next;
	}

	if (element == list->tail) {
		previous->next = NULL;
		list->tail = previous;
	}
	else {
		previous->next = element->next;
	}
	list->size--;
}

list_element_t*
list_pop_back(list_t* list)
{
    list_element_t* element = NULL;

    if (list->head != NULL) {
        element = list->head;
        if (list->head == list->tail) {
            list->head = NULL;
            list->tail = NULL;
        }
        else {
            while (element->next != list->tail) {
                element = element->next;
            }
            list->tail = element;
            element = element->next;
            list->tail->next = NULL;
        }

        list->size--;
    }

    return element;
}

list_element_t*
list_pop_front(list_t* list)
{
    list_element_t* element = NULL;

    if (list->head != NULL) {
        element = list->head;
        list->head = element->next;
 
        if (element == list->tail) {
            list->tail = NULL;
        }

        list->size--;
    }

    return element;
}
