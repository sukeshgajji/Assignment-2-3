#include<iostream>
using namespace std;
 
class Node
{
    public:
    int row;
    int col;
    int data;
    Node *next;
};
 
void create_new_node(Node **p, int row_index,
                     int col_index, int x)
{
    Node *temp = *p;
    Node *r;
    if (temp == NULL)
    {
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
     
    else
    {
        while (temp->next != NULL)  
            temp = temp->next;
             
        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}
void printList(Node *start)
{
    Node *ptr = start;
    cout << "row_position:";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "column_position:";
 
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:";
    ptr = start;
     
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{

    int sparseMatrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
                               { 0 , 0 , 5 , 7 , 0 },
                               { 4 , 0 , 0 , 2 , 1 },
                               { 0 , 2 , 6 , 0 , 0 } };
     
    Node *first = NULL;
    int nonzeros = 0, size = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            size++;
            if (sparseMatrix[i][j] != 0)
                {nonzeros++;
                create_new_node(&first, i, j,
                                sparseMatrix[i][j]);}
        }
    }
    cout << "The matrix is:\n";
    for (int i = 0; i < 4; i++)
    {
    for (int j = 0; j < 5; j++)
    {
        cout << sparseMatrix[i][j] << " ";
    }
    cout << endl;
    }
    if(nonzeros < size/2){
        cout << "Its a sparse matrix.\n";
        printList(first);    
    }
    else{
        cout << "Its not a sparse matrix.";
    }
 
    return 0;
}