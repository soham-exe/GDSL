//////////////////////////////////////
// Generalised Data Structure Library
//////////////////////////////////////

/*
-------------------------------------------------------------------------------------
Type               |   Name of class for node | Name of class for Functionality  
--------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode                           SinglyLLL      Done 
Singly Circular          SinglyCLLnode                           SinglyCLL      Done
Doubly Linear            DoublyLLLnode                           DoublyLLL      Done 
Doubly Circular          DoublyCLLnode                           DoublyCLL      Done
Stack                    Stacknode                               Stack          Done
Queue                    Queuenode                               Queue          Done     
--------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////
// Singly Linear LinkedList using generic approach
////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:              
        SinglyLLLnode<T> * first;
        int iCount;
    
    public:
        SinglyLLL();
     
        void InsertFirst(T );

        void InsertLast(T );
      
        void DeleteFirst();
        
        void DeleteLast();
        
        void Display();
        
        int Count();
      
        void InsertAtPos(T,int);
        
        void DeleteAtPos(int);
     
};
template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"object of SinglyLLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Used to insert node at First position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn ->next = this->first;                  
    this->first = newn;                         
    
    this->iCount++;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Used to insert node at Last position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T>* newn = NULL;
    SinglyLLLnode<T>* temp = NULL;

    newn = new SinglyLLLnode<T>(no);


    if(iCount == 0)                 
    {
        this->first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Used to Delete node at First position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if(first == NULL)
    {
        return;                              
    }
    else if(this->first->next == NULL)           
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        first = first->next;
        delete temp;
    }
    this->iCount--;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Used to Delete node at last position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: DeleteLast()
{   
    SinglyLLLnode<T>* temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp ->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Used to Display nodes of linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T>* temp = NULL;
    int iCnt = 0;

    temp = this->first;
    
    for(iCnt = 1;iCnt <= this->iCount;iCnt++)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";

}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Used to Count number of nodes in linked list
//  Input         : Data of Node
//  Output        : Integer count of nodes
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Used to Insert node at specific position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: InsertAtPos(T no,int pos)
{
    SinglyLLLnode<T>* temp;
    SinglyLLLnode<T>* newn;
    int iCnt = 0;
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid input\n";
        return;
    }
    if(iCount == 0)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {   
        temp = this->first;
        newn = new SinglyLLLnode<T>(no);

        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp->next; 
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }


}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Used to Delete node at specific position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T>* temp;
    SinglyLLLnode<T>* target = NULL;
    int iCnt = 0;
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid input\n";
        return;
    }
    if(iCount == 0)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {   
        temp = this->first;

        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp->next; 
        }
        target = temp->next;

        temp->next = target->next;

        delete target;

        this->iCount--;
    }
}


////////////////////////////////////////////////////////////////
// Singly Circular LinkedList using generic approach
////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : SinglyCLL
//  Description   : Constructor to initialize Singly circular linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : To insert a new node at the beginning of Singly circular linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL) 
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : To insert a new node at the end of Singly circular linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : To delete the first node of Singly circular linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : To delete the last node of Singly circular linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : To display the elements of Singly circular linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"head\n";
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : To count the number of nodes in Singly circular linked list
//  Input         : Nothing
//  Output        : Integer count of nodes
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : To delete the node at given position in Singly circular linked list
//  Input         : Position of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : To insert a new node at given position in Singly circular linked list
//  Input         : Data of Node, Position of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}



////////////////////////////////////////////////////////////////
// Doubly Linear LinkedList using generic approach
////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;
    
    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DoublyLLL
//  Description   : Constructor to initialize Doubly linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    
    this->iCount = 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Used to Insert node at First position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;                               

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    iCount++;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Used to Insert node at First position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{   
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Used to Insert node at specific position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T>*newn = NULL;
    DoublyLLLnode<T>*temp = NULL;
    int iCnt = 0;
    if((pos < 1)||(pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;
        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        this->iCount++;
    }
    
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Used to Delete node at First position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                   
    {
        cout<<"Linked list is empty";
        return;
    }
    else if(this->first->next == NULL)              
    {
        delete this->first;
        this->first = NULL;
    }
    else                                            
    {
        this->first = this->first->next;
        delete this ->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Used to Delete node at Last position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;
    if(this->first == NULL)                        
    {
        cout<<"Linked list is empty";
        return;
    }
    else if(this->first->next == NULL)             
    {
        delete this->first;
        this->first = NULL;
    }
    else                                            
    {
        temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Used to Delete node at specific position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{   
    DoublyLLLnode<T>*temp = NULL;
    int iCnt = 0;
    if((pos < 1)||(pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
        
        this->iCount--;
    }
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Used to Display all nodes
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;
    temp = this->first;
    cout<<"\n NULL";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Used to Count all nodes
//  Input         : Data of Node
//  Output        : Integer count of nodes
//  Author        : Soham Sachin Sonar
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}




////////////////////////////////////////////////////////////////
// Doubly circular Linked List using generic approach
////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;
};


template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DoublyCLL
//  Description   : Constructor to initialize Doubly circular linked list
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Used to Insert node at First position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Used to Insert node at Last position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> * newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Used to Delete node at First position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL) return;

    if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Used to Delete node at Last position
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL) return;

    if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next; 

        last->next = first;
        first->prev = last;
    }
    iCount--;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Used to Display all nodes
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL && last == NULL) return;

    DoublyCLLnode<T> * temp = first;
    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "(Head)\n";
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns the count of nodes in the doubly circular linked list
//  Input         : None
//  Output        : Integer count of nodes
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at the specified position
//  Input         : Data of Node , Position
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1) return;

    if(pos == 1) InsertFirst(no);
    else if(pos == iCount + 1) InsertLast(no);
    else
    {
        DoublyCLLnode<T> * newn = new DoublyCLLnode<T>;
        newn->data = no;

        DoublyCLLnode<T> * temp = first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node at the specified position
//  Input         : Position of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount) return;

    if(pos == 1) DeleteFirst();
    else if(pos == iCount) DeleteLast();
    else
    {
        DoublyCLLnode<T> * temp = first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}



////////////////////////////////////////////////////////////////
// Stack using generic approach
////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;
        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};
template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();
        void Push(T);                        
        T Pop();                          
        T Peep();
        void Display();
        int Count();
};
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Stack
//  Description   : contructor to initialize stack
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created successfully.\n";
    this->first = NULL;
    this->iCount = 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Push
//  Description   : Pushes an element onto the stack
//  Input         : Data of Node
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> ::  Push(T no)
{
    Stacknode<T> *newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
} 
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Pop
//  Description   : Pops an element from the stack
//  Input         : Nothing
//  Output        : Popped element
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>                          
T Stack<T> :: Pop()
{
    int Value = 0;
    Stacknode<T> *temp = this->first;
    if(this->first == NULL)
    {
        throw "Stack is empty. Cannot Pop.";
    }
    Value = this->first->data;
    this->first = this->first->next;
    delete temp;
    this->iCount--;

    return Value;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Peep
//  Description   : Peeks at the top element of the stack
//  Input         : Nothing
//  Output        : Top element of the stack
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>                                     
T Stack<T> :: Peep()
{    
    T Value;
    if(this->first == NULL)
    {
        throw "Stack is empty. Cannot Peep.";
    }
    Value = this->first->data;
    
    return Value;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements in the stack
//  Input         : Nothing
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }
    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
    cout<<"|_______________|\n";
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns the number of elements in the stack
//  Input         : Nothing
//  Output        : Number of elements in the stack
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////
// Queue using generic approach
////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};
template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();
        void enqueue(T);                                 
        T dequeue();                                    
        void Display();
        int Count();
};
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Queue
//  Description   : Creates a new queue
//  Input         : Nothing
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully.\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : enqueue
//  Description   : Adds an element to the rear of the queue
//  Input         : Element to be added
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
void Queue<T> ::  enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    newn = new Queuenode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    
    else
    {   
        this->last->next = newn;
        this->last = newn;
    }
    this->iCount++;
}  
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : dequeue
//  Description   : Removes an element from the front of the queue
//  Input         : Nothing
//  Output        : Element removed from the front of the queue
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>                         
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;
    if((this->first == NULL) && (this->last == NULL))
    {
        throw "Queue is empty. Cannot Dequeue.";
    }

    Value = this->first->data;
    this->first = this->first->next;
    delete temp;
    this->iCount--;

    return Value;
}                     
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements in the queue
//  Input         : Nothing
//  Output        : Nothing
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////                
template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = this->first;
    if((this->first == NULL) && (this->last == NULL))
    {
        cout<<"Queue is empty\n";
        return;
    }
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns the number of elements in the queue
//  Input         : Nothing
//  Output        : Number of elements in the queue
//  Author        : Soham Sachin Sonar
//  Date          : 21/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}



////////////////////////////////////END OF LIBRARY//////////////////////////////////////////


int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of SinglyLLLnodes are : "<<iRet<<"\n";
    
    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of SinglyLLLnodes are : "<<iRet<<"\n";

    obj->DeleteFirst();
    obj->DeleteLast();
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of SinglyLLLnodes are : "<<iRet<<"\n";
    
    obj->InsertAtPos(100,5);
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of SinglyLLLnodes are : "<<iRet<<"\n";

    obj->DeleteAtPos(4);
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of SinglyLLLnodes are : "<<iRet<<"\n";

    delete obj;
///////////////////////////////////////////////////////////////////////
    SinglyCLL<int> *scobj = new SinglyCLL<int>();
    iRet = 0;

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);
    
    scobj->InsertLast(101);
    scobj->InsertLast(111);
    scobj->InsertLast(121);
    
    scobj->InsertAtPos(105,5);

    scobj->Display();
    
    iRet = scobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    scobj->DeleteAtPos(5);
    scobj->Display();
    
    iRet = scobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    scobj->DeleteFirst();
    scobj->Display();
    
    iRet = scobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    scobj->DeleteLast();
    scobj->Display();
    
    iRet = scobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
///////////////////////////////////////////////////////////////////////
    DoublyLLL<char> *dobj = new DoublyLLL<char>();
    
    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    
    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    
    delete dobj;
/////////////////////////////////////////////////////////////////////////////
    DoublyCLL<int> *dcobj = new DoublyCLL<int>();
    iRet = 0;

    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->InsertLast(101);
    dcobj->InsertLast(111);
    dcobj->InsertLast(121);
    
    dcobj->InsertAtPos(105,5);

    dcobj->Display();
    
    iRet = dcobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dcobj->DeleteAtPos(5);
    dcobj->Display();
    
    iRet = dcobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dcobj->DeleteFirst();
    dcobj->Display();
    
    iRet = dcobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dcobj->DeleteLast();
    dcobj->Display();
    
    iRet = dcobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
/////////////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->Push('a');
    sobj->Push('b');
    sobj->Push('c');
    sobj->Push('d');

    sobj->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n\n";

    cout<<"Return value of peep is : "<<sobj->Peep()<<"\n";
    sobj->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n\n";

    cout<<"Poped element is : "<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n\n";
    cout<<"Poped element is : "<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n\n";
    
    sobj->Push('e');
    sobj->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n\n";

    delete sobj;
/////////////////////////////////////////////////////////////////////////////////
    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";
    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";
    
    qobj->enqueue(121.56789);
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}