#include "list.h"

int main(void) {
	int occurrence;//The occurrence of deleted number
	Node *head = (Node *)malloc(sizeof(Node));
	/*Test of Delete Node*/
	printf("/*Test of Delete Node*/");
	//Test Linked List 2->6->5->6
	printf("\n#####Test Linked List 2->6->5->6#####\n");
	double arr1[] = { 2, 6, 5, 6 };
	ListFromArr(head, arr1, 4);
	printf("The origin list is: ");
	PrintList(head);//Print the origin list
	occurrence = DeleteNodes(&head, 6);
	printf("The occurrence of 6 is %d\nThe updated list is: ", occurrence);
	PrintList(head);//Print the changed list
	DestroyList(head);

	//Test Linked List NULL
	printf("\n#####Test Linked List NULL#####\n");
	head = NULL;
	printf("The origin list is: ");
	PrintList(head);//Print the origin list
	occurrence = DeleteNodes(&head, 6);
	printf("The occurrence of 6 is %d\nThe updated list is: ", occurrence);
	PrintList(head);//Print the changed list

	//Test Linked List 6->6->6
	printf("\n#####Test Linked List 6->6->6#####\n");
	head = (Node *)malloc(sizeof(Node));
	double arr2[] = { 6, 6, 6 };
	ListFromArr(head, arr2, 3);
	printf("The origin list is: ");
	PrintList(head);//Print the origin list
	occurrence = DeleteNodes(&head, 6);
	printf("The occurrence of 6 is %d\nThe updated list is: ", occurrence);
	PrintList(head);//Print the changed list
	DestroyList(head);

	/*Test of Remove Duplicates*/
	printf("\n\n/*Test of Remove Duplicates*/");
	//Test Linked List 1->2->2->4->6->6
	printf("\n#####Test Linked List 1->2->2->4->6->6#####\n");
	head = (Node *)malloc(sizeof(Node));
	double arr3[] = { 1, 2, 2, 4, 6, 6 };
	ListFromArr(head, arr3, 6);
	printf("The origin list is: ");
	PrintList(head);
	RemoveDuplicants(&head);
	printf("The updated list is: ");
	PrintList(head);
	DestroyList(head);

	//Test Linked List NULL
	printf("\n#####Test Linked List NULL#####\n");
	head = NULL;
	printf("The origin list is: ");
	PrintList(head);
	RemoveDuplicants(&head);
	printf("The updated list is: ");
	PrintList(head);
	DestroyList(head);

	//Test Linked List 6->6->6->7->7
	printf("\n#####Test Linked List 6->6->6->7->7#####\n");
	head = (Node *)malloc(sizeof(Node));
	double arr4[] = { 6, 6, 6, 7, 7 };
	ListFromArr(head, arr4, 5);
	printf("The origin list is: ");
	PrintList(head);
	RemoveDuplicants(&head);
	printf("The updated list is: ");
	PrintList(head);
	DestroyList(head);
	return 0;
}