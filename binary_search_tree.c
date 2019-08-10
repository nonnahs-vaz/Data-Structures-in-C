//C program to implement binary search tree using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *LEFT,*RIGHT;
}*ROOT=0;
typedef struct node node;
node * alloc_mem(int);
void insert_node(node *,node *);
void delete_node();
void find_parent_of_node(node *,node *,int);
void delete_node_1(node *,node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
int count_nodes(node *);
int search_node(node *,int);
node * find_min(node *);
node * find_max(node *);
int find_sum(node *);
int find_depth(node *);
void create_tree();
int main()
{
    int ch;
    node *TEMP;
    while(1)
    {
        printf("\n\n1>Create a BST\n2>In order traversal\n3>Pre-order traversal\n4>Post order traversal\n5>Searching an element");
        printf("\n6>Delete an element\n7>Find the depth\n8>Count number of nodes\n9>Find the minimum element\n10>Find the maximum element\n11>Find the sum of all elements\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create_tree();
                    break;
            case 2: if(ROOT)
                    {
                        printf("\nIn-order traversal is :\n");
                        inorder(ROOT);
                    }
                    else
                        printf("\nTree is empty");
                    break;
            case 3: if(ROOT)
                    {
                        printf("\nPre-order traversal is :\n");
                        preorder(ROOT);
                    }
                    else
                        printf("\nTree is empty");
                    break;
            case 4: if(ROOT)
                    {
                        printf("\nPost-order traversal is :\n");
                        postorder(ROOT);
                    }
                    else
                        printf("\nTree is empty");
                    break;
            case 5: if(!ROOT)
                        printf("\nTree is empty");
                    else
                    {
                        printf("\nEnter the element to search_> ");
                        scanf("%d",&ch);
                        ch=search_node(ROOT,ch);
                        if(!ch)
                            printf("\nElement not found");
                        else
                            printf("\nElement found");
                    }
                    break;
            case 6: delete_node();
                    break;
            case 7: if(!ROOT)
                        printf("\nTree is empty");
                    else
                        printf("\nDepth of tree is %d",find_depth(ROOT));
                    break;
            case 8: if(!ROOT)
                        printf("\nTree is empty");
                    else
                        printf("\nNumber of nodes in tree is %d",count_nodes(ROOT));
                    break;
            case 9: if(!ROOT)
                        printf("\nTree is empty");
                    else
                    {
                        TEMP=find_min(ROOT);
                        printf("\nMinimum element is %d",TEMP->data);
                    }
                    break;
            case 10:if(!ROOT)
                        printf("\nTree is empty");
                    else
                    {
                        TEMP=find_max(ROOT);
                        printf("\nMaximum element is %d",TEMP->data);
                    }
                    break;
            case 11:if(!ROOT)
                        printf("\nTree is empty");
                    else
                        printf("\nSum of all nodes is %d",find_sum(ROOT));
                    break;
            default:return 0;
        }
    }
}
node * alloc_mem(int data)
{
    node *NEW_NODE;
    NEW_NODE=(node *)malloc(sizeof(node));
    NEW_NODE->data=data;
    NEW_NODE->LEFT=NEW_NODE->RIGHT=0;
    return NEW_NODE;
}
void insert_node(node *TMP_ROOT,node *NEW_NODE)
{
    if(NEW_NODE->data <= TMP_ROOT->data)
    {
        if(TMP_ROOT->LEFT)
            insert_node(TMP_ROOT->LEFT,NEW_NODE);
        else
            TMP_ROOT->LEFT=NEW_NODE;
    }
    if(NEW_NODE->data > TMP_ROOT->data)
    {
        if(TMP_ROOT->RIGHT)
            insert_node(TMP_ROOT->RIGHT,NEW_NODE);
        else
            TMP_ROOT->RIGHT=NEW_NODE;
    }
}
void delete_node()
{
    node *TMP;
    int found,lmnt;
    if(!ROOT)
    {
        printf("\nTree is empty");
        return;
    }
    printf("\nEnter element to delete_> ");
    scanf("%d",&lmnt);
    found=search_node(ROOT,lmnt); //checking if element is present in tree
    if(found)
    {
        find_parent_of_node(0,ROOT,lmnt);   //finding parent of node and deleting the node
        if(!ROOT)
            printf("\nTree is empty");
        else
        {
            printf("In-order traversal is:\n");
            inorder(ROOT);
        }
    }
    else
        printf("\nElement not found");
}
void find_parent_of_node(node *PARENT,node *CHILD,int data)
{
    if(CHILD && CHILD->data==data)  //child found
    {
        delete_node_1(PARENT,CHILD);
        return;
    }
    else if(CHILD && (CHILD->LEFT || CHILD->RIGHT))     //child has at least one subtree
    {
        find_parent_of_node(CHILD,CHILD->LEFT,data);    //searching in left subtree
        find_parent_of_node(CHILD,CHILD->RIGHT,data);   //searching in right subtree
    }
}
void delete_node_1(node *PARENT,node *CHILD)
{
    node *TMP;
    int tmp;
    if(!CHILD->LEFT && !CHILD->RIGHT)   //leaf node
    {
        if(!PARENT) //checking if root
            ROOT=0; //resetting root
        else
        {
            if(PARENT->RIGHT==CHILD)  //right child
                PARENT->RIGHT=0;
            else    //left child
                PARENT->LEFT=0;
        }
        printf("\n%d is deleted\n",CHILD->data);
        free(CHILD);
    }
    else if(CHILD->LEFT && CHILD->RIGHT)    //2 children
    {
        TMP=find_max(CHILD->LEFT);  //finding max in left subtree
        tmp=TMP->data;             //swapping
        TMP->data=CHILD->data;
        CHILD->data=tmp;
        find_parent_of_node(0,ROOT,TMP->data);  //finding node again as it is replaced
    }
    else    //one child
    {
        if(PARENT) //not root node
        {
            if(PARENT->LEFT==CHILD) //left child
                PARENT->LEFT=(!CHILD->LEFT ? CHILD->RIGHT:CHILD->LEFT);   //resetting left pointer of parent
            else
                PARENT->RIGHT=(!CHILD->LEFT ? CHILD->RIGHT:CHILD->LEFT);  //resetting right pointer of parent
        }
        else    //root node
            ROOT=(!CHILD->LEFT ? CHILD->RIGHT:CHILD->LEFT);  //resetting root

        printf("\n%d is deleted\n",CHILD->data);
        free(CHILD);
    }
}
void inorder(node *TMP)
{
    if(TMP)
    {
        inorder(TMP->LEFT);
        printf("%d\t",TMP->data);
        inorder(TMP->RIGHT);
    }
}
void preorder(node *TMP)
{
    if(TMP)
    {
        printf("%d\t",TMP->data);
        preorder(TMP->LEFT);
        preorder(TMP->RIGHT);
    }
}
void postorder(node *TMP)
{
    if(TMP)
    {
        postorder(TMP->LEFT);
        postorder(TMP->RIGHT);
        printf("%d\t",TMP->data);
    }
}
int count_nodes(node *T)
{
    if(!T)
        return 0;
    else
        return (1 + count_nodes(T->LEFT) + count_nodes(T->RIGHT));
}
int search_node(node *TMP_ROOT,int data)
{
    if(data==TMP_ROOT->data)
        return 1;
    else if(data < TMP_ROOT->data)  //search in left subtree
    {
        if(TMP_ROOT->LEFT)
            search_node(TMP_ROOT->LEFT,data);
    }
    else if(data > TMP_ROOT->data)  //search in right subtree
    {
        if(TMP_ROOT->RIGHT)
            search_node(TMP_ROOT->RIGHT,data);
    }
    else
        return 0;
}
node * find_min(node *T)
{
    if(!T->LEFT)
        return T;
    else
        find_min(T->LEFT);
}
node * find_max(node *T)
{
    if(!T->RIGHT)
        return T;
    else
        find_max(T->RIGHT);
}
int find_sum(node *T)
{
    if(!T)
        return 0;
    else
        return (T->data + find_sum(T->LEFT) + find_sum(T->RIGHT));
}
int find_depth(node *T)
{
    if(!T)
        return 0;
    else
    {
        int left_depth=find_depth(T->LEFT); //find depth of left subtree
        int right_depth=find_depth(T->RIGHT);   //find depth of right subtree
        return(left_depth > right_depth ? left_depth+1 : right_depth+1);    //compare and return maximum depth
    }
}
void create_tree()
{
    int data;
    node *NODE;
    printf("\nEnter data_> ");
    scanf("%d",&data);
    NODE=alloc_mem(data);
    if(ROOT)    //tree exists
        insert_node(ROOT,NODE);
    else    //creating new tree
        ROOT=NODE;
    printf("\nNode added to tree\nIn-order traversal is:\n");
    inorder(ROOT);
}
