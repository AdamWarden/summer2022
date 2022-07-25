/*
struct node;
typedef struct node Node;

struct node
{
    Node* next;
    int* data;
};
*/

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* reverse_list(Node* head_ref);

Node* newNode(int data);

void head_insert(Node** head_ref, int new_data);

Node* list_sum(Node* head_ref, Node* head_ref2);

void print_list(Node* node);

void destroy_list(Node* head_ref);