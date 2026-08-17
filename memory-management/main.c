/*
 ============================================================================
 Name        : main.c
 Author      : Muhammed Salih Yılmaz
 Version     : 0.0.1
 Copyright   : Your copyright notice
 Description : Memory Management Project
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define kb 1

struct Node
{
	int start;
	int end;
	struct Node *next;
};
typedef struct Node Node;

int isEmpty(Node *root)
{
	return root == NULL;
}

void initializeMemory(Node **root, int startAddr, int size)
{
	*root = (Node *)malloc(sizeof(Node));
	(*root)->start = startAddr;
	(*root)->end = startAddr + size;
	(*root)->next = NULL;
}

void printMemoryLayoutThousands(Node *root)
{
	// printf("Memory Layout:\n");
	if (isEmpty(root))
	{
		printf("No memory to allocate!\n");
	}
	printf("--------------------------------------------------------------------------------\n");
	while (root != NULL)
	{

		printf("%dK-%dK     ", root->start / kb, (root->end) / kb);
		root = root->next;
	}
	printf("\n");
	printf("\n");
}

void bellekAlAdresli(Node **root, int startAddr, int size)
{

	Node *current = *root;
	Node *prev = NULL;

	if (isEmpty(*root))
	{
		return;
	}

	while (current != NULL && current->end <= startAddr)
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
	{
		// DO NOTHING
		printf("bellekAlAdresli(root,%d*kb,%d*kb)\n", startAddr / kb, size / kb);
		printMemoryLayoutThousands(*root);
		return;
	}

	// case 1: Girilen adres boş alanın başından önce; bitişik değil ya da bitişik
	if (startAddr < current->start && startAddr + size <= current->end)
	{
		// sol tarafta ve sağda başka node yoksa, yani tek node ise
		if (prev == NULL && current->next == NULL)
		{
			// printf("case 1.1\n");
			// printf("DO NOTHING.\n");
		}

		// sol taraf boş ama sağ taraf dolu, yani ilk node
		else if (prev == NULL && current->next != NULL)
		{
			// printf("case 1.2\n");
			// printf("DO NOTHING.\n");
		}

		// sağ tarafta başka node yoksa, yani son node'da isek
		else if (prev != NULL && current->next == NULL)
		{
			// printf("case 1.3\n");
			// printf("DO NOTHING.\n");
		}

		// ortada bir yerde isek
		else
		{
			// printf("case 1.4\n");
			// printf("DO NOTHING.\n");
		}
	}

	// case 3: Girilen adres ile boş alan birebir aynı
	else if (startAddr == current->start && current->end == startAddr + size)
	{

		// sol tarafta ve sağda başka node yoksa, yani tek node ise
		if (prev == NULL && current->next == NULL)
		{
			// printf("case 3.1\n");
			current = NULL;
			(*root) = current;
		}

		// sol taraf boş ama sağ taraf dolu, yani ilk node
		else if (prev == NULL && current->next != NULL)
		{
			// printf("case 3.2\n");
			current = current->next;
			(*root) = current;
		}
		// sağ tarafta başka node yoksa, yani son node'da isek
		else if (prev != NULL && current->next == NULL)
		{
			// printf("case 3.3\n");
			prev->next = NULL;
		}
		// ortada bir yerde isek
		else
		{
			// printf("case 3.4\n");
			prev->next = current->next;
		}
	}

	// case 4: Girilen adres boş alanın içinde; baştan bitişik
	else if (startAddr == current->start && startAddr + size < current->end)
	{
		// sol tarafta ve sağda başka node yoksa, yani tek node ise
		if (prev == NULL && current->next == NULL)
		{
			// printf("case 4.1 BURAYA ASLA GİRMEMELİ \n");
		}

		// sol taraf boş ama sağ taraf dolu, yani ilk node
		else if (prev == NULL && current->next != NULL)
		{
			// printf("case 4.2\n");
			current->start = startAddr + size;
		}
		// sağ tarafta başka node yoksa, yani son node'da isek
		else if (prev != NULL && current->next == NULL)
		{
			// printf("case 4.3\n");
			current->start = startAddr + size;
			prev->next = current;
		}
		// ortada bir yerde isek
		else
		{
			// printf("case 4.3\n");
			current->start = startAddr + size;
			prev->next = current;
			current = current->next;
		}
	}

	// case 5: Girilen adres boş alanın içinde; başa ve sona değmiyor
	else if (startAddr > current->start && startAddr + size < current->end)
	{

		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->end = current->end;
		newNode->start = startAddr + size;
		current->end = startAddr;

		// sol tarafta ve sağda başka node yoksa, yani tek node ise
		if (prev == NULL && current->next == NULL)
		{
			// printf("case 5.1 BURAYA ASLA GİRMEMELİ \n");
		}

		// sol taraf boş ama sağ taraf dolu, yani ilk node
		else if (prev == NULL && current->next != NULL)
		{
			// printf("case 5.2\n");
			newNode->next = current->next;
			current->next = newNode;
		}

		// sağ tarafta başka node yoksa, yani son node'da isek
		else if (prev != NULL && current->next == NULL)
		{
			// printf("case 5.3\n");

			newNode->next = current->next;
			current->next = newNode;
		}

		// ortada bir yerde isek
		else
		{
			// printf("case 5.4\n");

			newNode->next = current->next;
			current->next = newNode;
		}
	}

	// case 6: Girilen adres boş alanın içinde; sonundan bitişik
	else if (startAddr > current->start && startAddr + size == current->end)
	{
		// sol tarafta ve sağda başka node yoksa, yani tek node ise
		if (prev == NULL && current->next == NULL)
		{
			// printf("case 6.1 BURAYA ASLA GİRMEMELİ \n");
		}

		// sol taraf boş ama sağ taraf dolu, yani ilk node
		else if (prev == NULL && current->next != NULL)
		{
			// printf("case 6.2\n");
			current->end = startAddr;
		}
		// sağ tarafta başka node yoksa, yani son node'da isek
		else if (prev != NULL && current->next == NULL)
		{
			// printf("case 6.3\n");
			current->end = startAddr;
			current->next = NULL;
		}
		// ortada bir yerde isek
		else
		{
			// printf("case 6.4\n");
			current->end = startAddr;
		}
	}

	// case 7: Girilen adres boş alanın sonundan sonra; bitişik veya bitişik değil
	else if (startAddr >= current->end && startAddr + size > current->end)
	{
		// sol tarafta ve sağda başka node yoksa, yani tek node ise
		if (prev == NULL && current->next == NULL)
		{
			// printf("case 7.1 BURAYA ASLA GİRMEMELİ \n");
		}

		// sol taraf boş ama sağ taraf dolu, yani ilk node
		else if (prev == NULL && current->next != NULL)
		{
			// printf("case 7.2\n");
			// printf("DO NOTHING.\n");
		}

		// sağ tarafta başka node yoksa, yani son node'da isek
		else if (prev != NULL && current->next == NULL)
		{
			// printf("case 7.3\n");
			// printf("DO NOTHING.\n");
		}

		// ortada bir yerde isek
		else
		{
			// printf("case 7.4\n");
			// printf("DO NOTHING.\n");
		}
	}

	// case 11: Everything else
	else
	{
		// printf("case 11.1 BURAYA ASLA GİRMEMELİ\n");
		// printf("DO NOTHING.\n");
	}

	printf("bellekAlAdresli(root,%d*kb,%d*kb)\n", startAddr / kb, size / kb);
	printMemoryLayoutThousands(*root);
}

void bellekIadeEt(Node **root, int startAddr, int size)
{
	if (isEmpty(*root))
	{
		initializeMemory(root, startAddr, size);
		printf("bellekIadeEt(&pList,%d*kb,%d*kb)\n", startAddr / kb, size / kb);
		printMemoryLayoutThousands(*root);
		return;
	}

	Node *current = *root;
	Node *prev = NULL;

	while (current != NULL && current->end <= startAddr)
	{
		prev = current;
		current = current->next;
	}

	// Case 1: Memory to be deallocated starts exactly where the current node ends
	// If root is (900-905) this case --> (897-900)
	if (current != NULL && current->start == startAddr + size)
	{
		if (prev != NULL && current->next == NULL && current->start == startAddr + size && prev->end == startAddr)
		{
			current->start = prev->start;
			prev->end = current->end;
			prev->next = NULL;
			// free(current);
		}
		else
		{
			// Extend the current node to cover the deallocated memory
			current->start = startAddr;
			// Check if current node's end can be merged with the next node's start
			if (current->next != NULL && prev != NULL && prev->end == current->start)
			{
				prev->end = current->end;
				prev->next = current->next;
			}
		}
	}

	// Case 2: Memory to be deallocated starts exactly where the previous node ends
	// If root is (900-905) this case --> (905-910)
	else if (prev != NULL && prev->end == startAddr)
	{
		if (current == NULL)
		{
			prev->end = startAddr + size;
		}
		else if (startAddr + size > current->start)
		{
			// DO NOTHING
		}
		else
		{
			// Extend the previous node to cover the deallocated memory
			prev->end = startAddr + size;
		}
	}

	// Case 3: Memory to be deallocated fits between two nodes or at the end of the list
	else
	{
		if (current != NULL && (current->start == startAddr ||
								(startAddr > current->start && (startAddr + size < current->end || startAddr + size > current->end)) ||
								(current->start > startAddr && current->start < startAddr + size) ||
								(current->start > startAddr && current->end < startAddr + size)))
		{
			// printf("EXCLUDING.\n");
			// DO NOTHING.
		}

		else
		{
			// Create a new node for the deallocated memory
			Node *newNode = (Node *)malloc(sizeof(Node));
			newNode->start = startAddr;
			newNode->end = startAddr + size;

			if (prev == NULL)
			{
				// Memory to be deallocated comes before the first node
				newNode->next = *root;
				*root = newNode;
			}
			else
			{
				newNode->next = prev->next;
				prev->next = newNode;
			}

			// Merge nodes if the deallocated memory can be merged with the next node
			if (current != NULL && newNode->end == current->start)
			{
				// Extend the new node to cover the merged memory range
				newNode->end = current->end;
				newNode->next = current->next;
				// Free the merged node
				free(current);
			}
			// Check if the new node's end can be merged with the next node's start
			if (newNode->next != NULL && newNode->end == newNode->next->start)
			{
				newNode->end = newNode->next->end;
				Node *temp = newNode->next;
				newNode->next = temp->next;
				free(temp);
			}
		}

		// Print the updated memory layout
	}
	printf("bellekIadeEt(&pList,%d*kb,%d*kb)\n", startAddr / kb, size / kb);
	printMemoryLayoutThousands(*root);
}

void bellekAlAdressiz(Node **root, int size)
{
	// Check if the memory list is empty or allocation size is invalid
	if (isEmpty(*root) || size <= 0)
	{
		// printf("Memory is not available for allocation.\n");
		return;
	}

	// Initialize variables to track the best fit node and its remaining space
	Node *bestFitNode = NULL;
	// Initialize with a large value
	int bestFitDiff = INT_MAX;

	// Initialize pointers to traverse the linked list
	Node *current = *root;
	Node *prev = NULL;

	// Traverse the linked list to find the best fit node
	while (current != NULL)
	{
		// Calculate the size of the current memory block
		int blockSize = current->end - current->start;

		// Calculate the remaining space after allocation
		int remainingSpace = blockSize - size;

		// Check if the current memory block can fit the allocation size
		// and has better fit than the previous best fit
		if (remainingSpace >= 0 && remainingSpace < bestFitDiff)
		{
			bestFitNode = current;
			bestFitDiff = remainingSpace;

			// If an exact fit is found, no need to continue searching
			if (remainingSpace == 0)
			{
				break;
			}
		}

		// Move the current and previous pointers
		prev = current;
		current = current->next;
	}

	// Allocate memory if a best fit node is found
	if (bestFitNode != NULL)
	{
		if (bestFitDiff == 0)
		{
			// If the allocated size matches the best fit node size, delete the node
			if (prev == NULL)
			{
				// Update root node
				*root = bestFitNode->next;
			}
			else
			{
				// Update previous node's next pointer
				prev->next = bestFitNode->next;
			}
			// Deallocate the best fit node
			free(bestFitNode);
		}
		else
		{
			// Otherwise, update the start address of the best fit node
			bestFitNode->start += size;
		}
	}
	
	// No suitable memory block found for allocation
	else
	{
		
		// printf("Memory is not available for allocation.\n");
	}

	// Print the updated memory layout
	printf("bellekAlAdressiz(root,%d*kb)\n", size / kb);
	printMemoryLayoutThousands(*root);
}

int main(void)
{

	// Test cases performed
	Node *root = NULL;
	printf("\n");

	bellekIadeEt(&root, 900 * kb, 5 * kb);
	bellekIadeEt(&root, 26 * kb, 3 * kb);
	bellekAlAdresli(&root, 26 * kb, 3 * kb);
	bellekIadeEt(&root, 3 * kb, 1 * kb);
	bellekIadeEt(&root, 17 * kb, 1 * kb);
	bellekIadeEt(&root, 920 * kb, 10 * kb);
	bellekIadeEt(&root, 16 * kb, 1 * kb);
	bellekIadeEt(&root, 9 * kb, 1 * kb);
	bellekIadeEt(&root, 8 * kb, 1 * kb);
	bellekIadeEt(&root, 19 * kb, 1 * kb);
	bellekIadeEt(&root, 18 * kb, 1 * kb);
	bellekIadeEt(&root, 24 * kb, 2 * kb);
	bellekIadeEt(&root, 1 * kb, 2 * kb);
	bellekIadeEt(&root, 29 * kb, 1 * kb);
	bellekAlAdresli(&root, 2 * kb, 1 * kb);
	bellekAlAdresli(&root, 24 * kb, 2 * kb);
	bellekAlAdresli(&root, 18 * kb, 1 * kb);
	bellekAlAdresli(&root, 19 * kb, 1 * kb);
	bellekAlAdresli(&root, 8 * kb, 1 * kb);
	bellekAlAdresli(&root, 9 * kb, 1 * kb);
	bellekAlAdresli(&root, 16 * kb, 1 * kb);
	bellekAlAdresli(&root, 17 * kb, 1 * kb);
	bellekIadeEt(&root, 28 * kb, 1 * kb);
	bellekIadeEt(&root, 17 * kb, 1 * kb);
	bellekIadeEt(&root, 16 * kb, 1 * kb);
	bellekIadeEt(&root, 899 * kb, 1 * kb);
	bellekIadeEt(&root, 27 * kb, 1 * kb);
	bellekIadeEt(&root, 18 * kb, 9 * kb);
	bellekAlAdresli(&root, 15 * kb, 5 * kb);
	bellekIadeEt(&root, 30 * kb, 50 * kb);
	bellekIadeEt(&root, 17 * kb, 1 * kb);
	bellekAlAdresli(&root, 19 * kb, 2 * kb);
	bellekAlAdressiz(&root, 1 * kb);
	bellekIadeEt(&root, 90 * kb, 17 * kb);
	bellekIadeEt(&root, 18 * kb, 2 * kb);
	bellekAlAdressiz(&root, 6 * kb);
	bellekIadeEt(&root, 180 * kb, 20 * kb);
	bellekIadeEt(&root, 250 * kb, 20 * kb);
	bellekIadeEt(&root, 300 * kb, 20 * kb);
	bellekAlAdresli(&root, 29 * kb, 3 * kb);
	bellekAlAdressiz(&root, 8 * kb);
	bellekAlAdresli(&root, 303 * kb, 17 * kb);
	bellekAlAdressiz(&root, 2 * kb);
	bellekAlAdresli(&root, 92 * kb, 15 * kb);
	bellekIadeEt(&root, 303 * kb, 20 * kb);
	bellekAlAdressiz(&root, 1 * kb);
	bellekIadeEt(&root, 92 * kb, 20 * kb);
	bellekAlAdressiz(&root, 25 * kb);
	bellekAlAdressiz(&root, 15 * kb);
	bellekAlAdressiz(&root, 22 * kb);
	bellekAlAdressiz(&root, 22 * kb);
	bellekAlAdressiz(&root, 22 * kb);
	bellekIadeEt(&root, 25 * kb, 7 * kb);
	bellekAlAdresli(&root, 195 * kb, 5 * kb);
	bellekAlAdressiz(&root, 1 * kb);
	bellekAlAdressiz(&root, 1 * kb);
	bellekIadeEt(&root, 300 * kb, 20 * kb);
	bellekAlAdressiz(&root, 7 * kb);
	bellekAlAdressiz(&root, 20 * kb);
	bellekAlAdressiz(&root, 20 * kb);
	bellekAlAdressiz(&root, 6 * kb);
	bellekAlAdressiz(&root, 2 * kb);
	bellekAlAdressiz(&root, 2 * kb);
	bellekIadeEt(&root, 400 * kb, 40 * kb);
	bellekIadeEt(&root, 40 * kb, 40 * kb);
	bellekIadeEt(&root, 100 * kb, 40 * kb);
	bellekAlAdresli(&root, 100 * kb, 5 * kb);
	bellekAlAdresli(&root, 430 * kb, 10 * kb);
	bellekAlAdresli(&root, 70 * kb, 10 * kb);
	bellekIadeEt(&root, 430 * kb, 40 * kb);
	bellekIadeEt(&root, 70 * kb, 20 * kb);
	bellekIadeEt(&root, 950 * kb, 40 * kb);
	bellekAlAdresli(&root, 420 * kb, 5 * kb);
	bellekAlAdresli(&root, 950 * kb, 5 * kb);
	bellekIadeEt(&root, 95 * kb, 5 * kb);
	bellekIadeEt(&root, 330 * kb, 40 * kb);
	bellekIadeEt(&root, 480 * kb, 40 * kb);
	bellekIadeEt(&root, 90 * kb, 4 * kb);
	bellekIadeEt(&root, 140 * kb, 40 * kb);
	bellekIadeEt(&root, 990 * kb, 40 * kb);
	bellekIadeEt(&root, 94 * kb, 1 * kb);
	bellekIadeEt(&root, 370 * kb, 30 * kb);
	bellekIadeEt(&root, 520 * kb, 435 * kb);
	bellekAlAdresli(&root, 40 * kb, 10 * kb);
	bellekAlAdresli(&root, 322 * kb, 10 * kb);
	bellekAlAdresli(&root, 480 * kb, 10 * kb);
	bellekAlAdresli(&root, 490 * kb, 540 * kb);
	bellekAlAdresli(&root, 50 * kb, 50 * kb);
	bellekAlAdresli(&root, 110 * kb, 20 * kb);
	bellekAlAdresli(&root, 330 * kb, 10 * kb);
	bellekAlAdresli(&root, 350 * kb, 10 * kb);
	bellekAlAdresli(&root, 430 * kb, 10 * kb);

	return EXIT_SUCCESS;
}
