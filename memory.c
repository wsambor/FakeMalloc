#include "memory.h"
#include "list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void* memoryArea = NULL;
static size_t memorySize = 0;

list_t metaDataList;
static list_element_t memoryBlockDescs[1000];

int
memory_init(void* ptr, size_t mem_size)
{
    memoryArea = ptr;
    memorySize = mem_size;

	list_ctor(&metaDataList);

	printf("Init memory point: %p \n", memoryArea);
	printf("Init memory size: %ld \n", memorySize);
	
	memoryBlockDescs[0].dataSize = memorySize;
	memoryBlockDescs[0].start = memoryArea;
	memoryBlockDescs[0].isFree = 1;

	list_push_back(&metaDataList, &memoryBlockDescs[0]);

    return 0;
}

void
resize_node(list_element_t* node, size_t size)
{
	int descsArrayIndex = node->start - memoryArea;
	
	memoryBlockDescs[descsArrayIndex + size].start = node->start + size;
	memoryBlockDescs[descsArrayIndex + size].isFree = 1;
	memoryBlockDescs[descsArrayIndex + size].dataSize = node->dataSize - size;

	node->dataSize = size;
	node->isFree = 0;
	list_push_middle(&metaDataList, node, &memoryBlockDescs[descsArrayIndex + size]);
}

int
merge_nodes(list_element_t* node)
{
	list_element_t* previous = NULL;

	if (node->next != NULL) {
		if (node->next->isFree == 1) {
			node->dataSize += node->next->dataSize;

			list_remove_middle(&metaDataList, node->next);
		}
	}

	if (node != metaDataList.head) {
		 previous = get_previous_element(&metaDataList, node);

		if (previous->isFree == 1) {
			merge_nodes(previous);
		}
		else {
			return 0;
		}
	}
}

void*
memory_malloc(size_t size)
{
    void* ptr = NULL;
	list_element_t* node = NULL;
	list_element_t* prev_node = NULL;

	if (!metaDataList.head) {
		fprintf(stderr, "Memory not initialized!\nUse memory_init()\n");
		return NULL;
	}

	node = metaDataList.head;

	while (((node->dataSize < size) || (node->isFree == 0)) && (node->next != NULL)) {
		prev_node = node;
		node = node->next;
	}

	if (node->dataSize > size) {
		resize_node(node, size);

		return node->start;
	}
	else if(node->dataSize == size) {
		node->isFree = 0;

		return node->start;
	}
	else {
		fprintf(stderr, "No available memory!\n");
		return NULL;
	}

	return ptr;
}

void
memory_free(void* ptr)
{
	list_element_t* node = metaDataList.head;

	while ((node->next != NULL) && (node->start != ptr)) {
		node = node->next;
	}

	if (node->start == ptr) {
		int i = 0;
		for (i = 0; i < node->dataSize; ++i) {
			((uint8_t* )node->start)[i] = 0x00;
		}
		
		node->isFree = 1;

		merge_nodes(node);
	}
}

void 
memory_print()
{   
    size_t start;
    size_t sub;

    for (start = 0; start < memorySize; start += 16) {

        printf("%04x  ", (uint32_t)start);

        for (sub = 0; sub < 16; ++sub) {
            if (start + sub  < memorySize) {
                uint8_t value = *((uint8_t*)memoryArea + start + sub);
                printf("%02X ", value);
            }
            else {
                printf("   ");
            }

            if (sub == 7) {
                printf(" ");
            }
        }

        printf("    ");

        for (sub = 0; sub < 16; ++sub) {
            if (start + sub  < memorySize) {
                uint8_t value = *((uint8_t*)memoryArea + start + sub); 
                printf("%c", value >= 33 && value <= 127 ? value : '.');
            }
            else {
                printf(" ");
            }

            if (sub == 7) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

