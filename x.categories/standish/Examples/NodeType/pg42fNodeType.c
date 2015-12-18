/*  Pg 42, NodeTag */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char AirportCode[4];	// typdef AirportCode is an array of 4 chars

typedef struct NodeTag{
	AirportCode Airport;
	struct NodeTag *Link;   // Link is a pointer to this struct of type NodeType
} NodeType;                 // typedef is NodeType

	// declare functions
void InsertNewSecondNode(NodeType *L);		// passed void in text book
NodeType *ListSearch(char *A, NodeType *L);	// must declare after struct
void DeleteLastNode(NodeType **L);
void InsertNewLastNode(char *A, NodeType **L);
void PrintList(NodeType *L);

int main(void){

	NodeType *L;		// L is a pointer to type NodeType, like Link,
					    // except Link is a member of the structure it points to.
						// Can declare in main because L is passed in every function.

		// First, construct the list L == (DUS,ORD,SAN) and print it
		// To start things off, let L be the empty list
	L = NULL;

		// Insert a new last node in L with airport code "DUS"
	InsertNewLastNode("DUS",&L);

		// Insert a new last node in L with airport code "ORD" */
	InsertNewLastNode("ORD",&L);

		// Insert a new last node in L with airport code "SAN" */
	InsertNewLastNode("SAN",&L);

			// Now, print the list, to show what it looks like before changing it */
	PrintList(L);

		// Then, insert a new second node with the airport code "BRU" */
	InsertNewSecondNode(L);

		// Print the modified list */
	PrintList(L);

		// Delete the last node of the list */
	DeleteLastNode(&L);

		// Finally, print the shortened list */
	PrintList(L);

	return 0;
}

void InsertNewSecondNode(NodeType *L){
	NodeType *N;		// create new node
	N = (NodeType *)malloc(sizeof(NodeType));
	strcpy(N->Airport,"BRU");
	N->Link = L->Link;	// let N link to the second node of list L
	L->Link = N;        // let L's fist node link to N
	return;
}

NodeType *ListSearch(char *A, NodeType *L){
	NodeType *N;	// N points to successive nodes on the list L
	N = L;   // initialize N by pointing to the first node of the list L

	while (N != NULL) {		// While N points to a non-null node on list L
		if (strcmp(N->Airport,A) == 0) {          // if N's Airport == A
			return N;
		} else {
			N = N->Link;		//advance N to the next node on the list
		}
	}
	return N;	// if no node's Airport == A, return last Link which is NULL */
}

void DeleteLastNode(NodeType **L){	// **L is the address of the variable L,
									// whose value points to the first node
									// of list L
	NodeType *PreviousNode, *CurrentNode;

	if (*L != NULL) {               // do nothing if *L was the empty list
		if ((*L)->Link == NULL) {	// if *L has exactly one node, then
			free(*L);				// free the node's storage, and
            *L = NULL;				// set L to be the empty list, and terminate
		} else {				// otherwise, list L must have two or more nodes
				// initialize a pair of pointers, (PreviousNode,CurrentNode)
				// to point to the first and second nodes
			PreviousNode = *L;
			CurrentNode =(*L)->Link;
				// Advance the pointer pair along L until CurrentNode
				// points to the last node
			while (CurrentNode->Link != NULL) {
				PreviousNode = CurrentNode ;
				CurrentNode = CurrentNode->Link;
			}
				// Now PreviousNode points to the next-to-last node on the list
                // and CurrentNode points to the last node on the list.
			PreviousNode->Link= NULL;	// last node gets NULL link
			free(CurrentNode);			//recycle storage for discarded node
		}
	}
	return;
}

void InsertNewLastNode(char *A, NodeType **L){	// Again, expect **L to be the
										// address of a variable L containing a
										// pointer to the first node of the list
	NodeType *N, *P;
		// Allocate a new node N with Airport == A and Link == NULL
	N = (NodeType *)malloc(sizeof(NodeType));
	strcpy(N->Airport, A);
	N->Link = NULL;

	if ( *L == NULL ) {		// If list *L is empty,
		*L = N;				// let N become the new value for *L
	} else {
		// Locate the last node of list L, using pointer variable P
		P = *L;
		while (P->Link != NULL){
			P = P->Link;
		}
			// Finally, link node N onto the end of the list
		P->Link = N;
	}
	return;
}

void PrintList(NodeType *L){
	NodeType *N;			// N points to successive nodes on list L

	printf( "(" );

		// Let N start by pointing to the first node on the list L
	N = L;

		// Provided N doesn't point to an empty node, print N's Airport
		// and advance N to point to the next node on the list
	while (N != NULL) {
		printf("%s",N->Airport);
		N = N->Link;			// make N point to next node on list
		if (N != NULL){
			printf(", ");
		}
	}
	printf(")\n");
	return;
}

