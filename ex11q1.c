#include "ex11q1.h"

// ############################################################################
// Vector
// ############################################################################
Vec* vec_create(void)
{
    Vec* vec=(Vec*)malloc(sizeof(Vec));
    vec->length=0;
    vec->capacity=128;
    vec->storage=(int*)malloc(vec->capacity*sizeof(int));
    return vec;
}

void vec_insert_at(Vec* vec, int at, int item)
{
    if(at<0 || at>vec->length)
    {
        exit(5);
    }
    if(vec->length==vec->capacity)
    {
        vec->capacity=vec->capacity*2;
        vec->storage=(int*)realloc(vec->storage,vec->capacity*sizeof(int));

    }
    int i=vec->length;
    while(i>at)
    {
        vec->storage[i]=vec->storage[i-1];
        i--;

    }
    vec->storage[at]=item;
    vec->length++;
}
void vec_print(Vec* vec)
{
    printf("[");
    for(int i=0; i<vec->length-1; i++)
    {
        printf("%d, ",vec->storage[i]);
    }
    if(vec->length>0)
    {
        printf("%d",vec->storage[vec->length-1]);
    }
    printf("]");
}
void vec_free(Vec* vec)
{
    free(vec->storage);
    free(vec);
}



// ############################################################################
// Linked List
// ############################################################################

LinkedListNode* list_node_create(int item)
{
    LinkedListNode* node=(LinkedListNode*)malloc(sizeof(LinkedListNode));
    if(node==NULL)
    {
        exit(6);
    }
    node->item=item;
    node->next=NULL;
    return node;

}


LinkedList* list_create(void)
{
    LinkedList* list=(Linkedlist*)malloc(sizeof(Linkedlist));
    list->length=0;
    list->start=NULL;

    return list;
}

void list_insert_at(LinkedList* list, int at, int item)
{
    if (at<0 || at>list->length)
    {
        exit(5);
    }
    LinkedListNode* newNode=list_node_create(item);
    if (at==0)
    {
        newNode->next=list->start;
        list->start=newNode;
    }
    LinkedListNode* currentNode=list->start;
    int i=0;
    while(i<at-1)
    {
        currentNode=currentNode->next;
        i++;
    }
    LinkedListNode* temp=currentNode->next;
    currentNode->next=newNode;
    newNode->next=temp;


}

void list_print(LinkedList* list)
{
    printf("[");
    LinkedListNode* currentNode=list->start;
    while (currentNode!=NULL)
    {
        printf("%d", currentNode->item);
        currentNode=currentNode->next;
        if (currentNode!=NULL)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
void list_free(LinkedList* list)
{
    LinkedListNode* currentNode=list->start;
    while (currentNode!=NULL)
    {
        LinkedListNode* temp=currentNode;
        currentNode=currentNode->next;
        free(temp);
    }

    free(list);
}



// ############################################################################
// Doubly Linked List
// ############################################################################

DoublyLinkedListNode* dlist_node_create(int item)
{
    DoublyLinkedListNode* node=(DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    if(node==NULL)
    {
        exit(6);
    }
    node->item=item;
    node->next=NULL;
    return node;

}


DoublyLinkedList* dlist_create(void)
{
    DoublyLinkedList* list=(DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->length=0;
    list->start=NULL;
    list->end=NULL;
    return list;

}

void dlist_insert_at(DoublyLinkedList* l, int at, int item)
{
    if (at<0 || at>l->length)
    {
        exit(5);
    }
    DoublyLinkedListNode* newNode=dlist_node_create(item);
    if (at==0)
    {
        newNode->next=l->start;
        if (l->start!=NULL) {
            l->start->prev=newNode;
        }
        l->start=newNode;
        if (l->end==NULL) {
            l->end=newNode;
        }
    }
    DoublyLinkedListNode* currentNode=l->start;
    int i=0;
    while(i<at-1)
    {
        currentNode=currentNode->next;
        i++;
    }
    DoublyLinkedListNode* temp=currentNode->next;
    currentNode->next=newNode;
    newNode->prev=currentNode;
    newNode->next=temp;
    if(temp==NULL){
        temp->prev=newNode;
    }
}

void dlist_print(DoublyLinkedList* l)
{
    DoublyLinkedListNode* currentNode=l->start;
    while (currentNode!=NULL)
    {
        printf("%d",currentNode->item);
        currentNode=currentNode->next;
        if (currentNode!=NULL)
        {
            printf(", ");
        }
    }
    printf("]");
}
void dlist_free(DoublyLinkedList* l)
{
    DoublyLinkedListNode* currentNode=l->start;
    while (currentNode!=NULL)
    {
        DoublyLinkedListNode* temp=currentNode;
        currentNode=currentNode->next;
        free(temp);
    }

    free(l);
}
//
//// ############################################################################
//// Main
//// ############################################################################
int main(void)
{
    char line[1000];
    // Uncomment each for loop as you implement that part

    clock_t begin_vec = clock();
    Vec* v = vec_create();

    for (int i = 0; i < 100000; i++)
    {
        int a, b;
        if (getchar() == 'i')
        {
            scanf("%s %d %s %d\n", line, &a, line, &b);
            vec_insert_at(v, b, a);
        }
        else
        {
            scanf("%s\n", line);
            vec_print(v);
        }
    }

    vec_free(v);
    clock_t end_vec = clock();

    clock_t begin_list = clock();
    //LinkedList* l = list_create();

    //for (int i = 0; i < 100000; i++) {
    //    int a, b;
    //    if (getchar() == 'i') {
    //        scanf("%s %d %s %d\n", line, &a, line, &b);
    //        list_insert_at(l, b, a);
    //    } else {
    //        scanf("%s\n", line);
    //        list_print(l);
    //    }
    //}

    //list_free(l);
    clock_t end_list = clock();

    clock_t begin_dlist = clock();
    //DoublyLinkedList* dlist = dlist_create();

    //for (int i = 0; i < 100000; i++) {
    //    int a, b;
    //    if (getchar() == 'i') {
    //        scanf("%s %d %s %d\n", line, &a, line, &b);
    //        dlist_insert_at(dlist, b, a);
    //    } else {
    //        scanf("%s\n", line);
    //        dlist_print(dlist);
    //    }
    //}

    //dlist_free(dlist);
    clock_t end_dlist = clock();

    fprintf(stderr, "Vector: %gs\n", (double)(end_vec - begin_vec) / CLOCKS_PER_SEC);
    fprintf(stderr, "Linked List: %gs\n", (double)(end_list - begin_list) / CLOCKS_PER_SEC);
    fprintf(stderr, "Doubly Linked List: %gs\n", (double)(end_dlist - begin_dlist) / CLOCKS_PER_SEC);
}
