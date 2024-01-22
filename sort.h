#ifndef SORT_H
#define SORT_H


#include <stdio.h>
#include <stdlib.h>


/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/* Utility function prototypes */
void swap_integers(int *a, int *b);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap(listint_t **ptr1, listint_t **ptr2, int n);



/* Helper function prototypes for */
int getMax(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
void sort_hoare(int *array, size_t size, int high, int low);
void sift_down(int *array, size_t size, size_t start, size_t end);
int partition_hoare(int *array, size_t size, int high, int low);
int lomuto_partition(int *array, int low, int high, size_t size);
void bitonic_seq(int *array, size_t start, size_t seq, char dir);
void merge_bitonic(int *array, size_t start, size_t seq, char dir);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void listend_sort(listint_t **ptr, listint_t **end, listint_t **list);
void liststart_sort(listint_t **ptr, listint_t **start, listint_t **list);
void merge_sort_recursive(int *sub_array, int *buff, size_t front,
		size_t back);
void merge_sub_array(int *sub_array, int *buff, size_t front,
		size_t middle, size_t back);



/* Function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);



#endif
