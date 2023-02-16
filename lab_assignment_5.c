#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* temp = head;
	int count = 0;

	if (head == NULL)
		return 0;

	while (temp->next != NULL) {
		count++;
		temp = temp->next;
	}
	count++;

	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int len = length(head);

	char* stringpointer = (char*)malloc(sizeof(char) * (len + 1));

	node* temp = head;


	for (int i = 0; i <= len; i++) {
		if (i == len){
			stringpointer[i] = '\0';
			return stringpointer;
		}
		stringpointer[i] = temp->letter;
		temp = temp->next;
	}
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = *pHead;
	// Allocate and create node with parameter letter.
	node* newNode = (node*)malloc(sizeof(node));
	newNode->next = NULL;
	newNode->letter = c;

	// Executes when list is initially empty.
	if (*pHead == NULL)
		*pHead = newNode;

	
	// For when list has at least one node.
	else {

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node*subhead = *pHead;

	while (*pHead != NULL)
	{
		*pHead = subhead->next;
		free(subhead);
		subhead = *pHead;

	}

	*pHead = NULL;
	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}