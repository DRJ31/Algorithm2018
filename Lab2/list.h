typedef struct node{
	double data;
	struct node* next; 
} Node;
Node* head;

bool IsEmpty(Node* head);
Node* InsertNode(Node** phead, int index, double x);
int FindNode(Node* head, double x);	
int DeleteNode(Node** phead, double x);
void DisplayList(Node* head);
void DestroyList(Node* head);