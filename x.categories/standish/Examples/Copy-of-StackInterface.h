/*  StackInterface.h */

#include "StackTypes.h"

	// Initialize the stack S to be the empty stack
extern void InitializeStack(Stack *S);
extern int Empty(Stack *S);
extern int Full(Stack *S);
extern void Push(ItemType X, Stack *S);
extern void Pop(Stack *S, ItemType *X);
