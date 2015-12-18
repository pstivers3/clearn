/*  BuildThreeNodes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char AirportCode[4];	// typdef AirportCode is an array of 4 chars

typedef struct NodeTag{
	AirportCode Airport;
	struct NodeTag *Link;   // Link is a pointer to this struct of type NodeType
} NodeType;                 // typedef is NodeType

	// declare functions
void BuildThreeNodes(NodeType *L);
void PrintList(NodeType *L);

	
		
int main(void){
	
	NodeType *L;
	L = (NodeType *)malloc(sizeof(NodeType));  // doesn't work if this line is moved into 
												// BuildThreeNodes(){}
	BuildThreeNodes(L);
	
	PrintList(L);

	return 0;
}
	
void BuildThreeNodes(NodeType *L){
	
			
	L->Link = (NodeType *)malloc(sizeof(NodeType));
	L->Link->Link = (NodeType *)malloc(sizeof(NodeType));
	L->Link->Link->Link = NULL;
	
	strcpy(L->Airport,"DUS");		// assign airport names to Airport at each node
	strcpy(L->Link->Airport,"ORD");
	strcpy(L->Link->Link->Airport,"SAN");
	
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

