//#include "ZLL.h"

template <typename T> ZLL<T>::ZLL(){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

template <typename T> ZLL<T>::~ZLL(){
    this->empty();
}

template <typename T> Node<T>::Node(){
    next = nullptr;
    prev = nullptr;
}

template <typename T> Node<T>::Node(T input){
    data = input;
    next = nullptr;
    prev = nullptr;
}

template<typename T> bool ZLL<T>::front(const T& item){
    Node<T>* newNode = new Node<T>(item);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        head->next = nullptr;
        head->prev = nullptr;
        listSize++;
        return true;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        listSize++;
        return true;
    }
}

template<typename T> bool ZLL<T>::back(const T& item){
    Node<T>* newNode = new Node<T>(item);

    if(tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        head->next = nullptr;
        head->prev = nullptr;
        listSize++;
        return true;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        listSize++;
        return true;
    }
}

template<typename T> bool ZLL<T>::join(ZLL &other){

    if(isEmpty() && !other.isEmpty())
    {
        //Assign left as right
        head = other.head;
        tail = other.tail;
        listSize = other.listSize;

        //Clear right
        other.head = nullptr;
        other.tail = nullptr;
        other.listSize = 0;

        return true;
    }
    else if(!other.isEmpty())
    {
        //Append other list to this
        tail->next = other.head;
        tail = other.tail;
        listSize += other.listSize;

        //Empty other list
        other.tail = nullptr;
        other.head = nullptr;
        other.listSize = 0;

        return true;
    }
    else if((isEmpty() && other.isEmpty()) || (!isEmpty() && other.isEmpty()))
    {
        return true;
    }

    return false;
}

template<typename T> ZLL<T>& ZLL<T>::operator+=(const ZLL &other){
    if(this == &other)
    {
        //Same object on the right
        return *this;
    }
    else{
        //Append copies of other list to this
        Node<T>* currNode = other.head;
        for(int i = 0; i < other.listSize; i++)
        {
            back(currNode->data);
            currNode = currNode->next;
        }
    }
    return *this;
}
//problem here with line 149------------------------------------------------------------------------------while gdb
template<typename T> ZLL<T>& ZLL<T>::operator-=(const ZLL &other){
    if(this == &other)
    {
        //Same object on the right
        return *this;
    }
    else{
        //Remove copies of other list nodes in this
        Node<T>* currNodeOther = other.head;
        Node<T>* currNodeThis = head;

        Node<T>* currNodePrev;
        Node<T>* currNodeNext;
        for(int i = 0; i < other.listSize; i++)//Iterating through other
        {
            currNodeThis = head;
            for(int index = 0; index < listSize; index++)//Iterating through this
            {
                if(currNodeThis->data == currNodeOther->data)
                {
                    //Assign prev and next
                    currNodePrev = currNodeThis->prev;
                    currNodeNext = currNodeThis->next;

                    //Head case
                    if(currNodeThis == head)
                    {
                        if(listSize != 1)
                        {
                            currNodeNext->prev = nullptr;
                            head = currNodeNext;
                        }
                        else{
                            //If only head
                            head = nullptr;
                            tail = nullptr;
                        }
                        
                        
                    }
                    else if(currNodeThis == tail) //Tail case
                    {
                        currNodePrev->next = nullptr;
                        tail = currNodePrev;
                    }
                    else{
                        //Remove node from list
                        currNodePrev->next = currNodeThis->next;
                        currNodeNext->prev = currNodeThis->prev;
                    }
                    //Clear pointers in abandoned node
                    currNodeThis->next = nullptr;
                    currNodeThis->prev = nullptr;
                    listSize--;

                    //Delete the node
                    delete currNodeThis;
                    break;
                }
                currNodeThis = currNodeThis->next;
            }
            currNodeOther = currNodeOther->next;
        }
    }
    return *this;
}

template<typename T> int ZLL<T>::removeZany(){
    int removeCount = 0;
    Node<T>* currNode = head;

    for(int i = 0; i < listSize; i++)
    {
        if(isZany(currNode->data))
        {
            if(currNode == tail)
            {
                currNode = currNode->prev;
            }
            else{
                currNode = currNode->next;
            }
            removeNode(i);
            listSize--;
            i--; //To account for decreading list size
            removeCount++;
            continue;
        }
        currNode = currNode->next;
    }
    return removeCount;
}

template<typename T> int ZLL<T>::removeNonZany(){

    int removeCount = 0;
    Node<T>* currNode = head;

    for(int i = 0; i < listSize; i++)
    {
        if(!isZany(currNode->data))
        {
            if(currNode == tail)
            {
                currNode = currNode->prev;
            }
            else{
                currNode = currNode->next;
            }
            removeNode(i);
            listSize--;
            i--; //To account for decreading list size
            removeCount++;
            continue;
        }
        currNode = currNode->next;
    }

    return removeCount;
}

template<typename T> bool ZLL<T>::promoteZany(){
    Node<T>* currNode = head;

    for(int i = 0; i < listSize; i++)
    {
        if(isZany(currNode->data))
        {
            front(currNode->data);
            currNode = currNode->next;
            removeNode(i+1);
            listSize--;
            continue;
        }
        currNode = currNode->next;
    }
    return true;
}

template<typename T> bool ZLL<T>::empty(){
    if(isEmpty())
    {
        return false;
    }
    while(head != nullptr)
    {
        //remove front
        Node<T>* temp = head;
        //T data = temp->data;
        if(head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        listSize--;
    }
    return true;
}

template<typename T> bool ZLL<T>::start(){
    if(!isEmpty())
    {
        iterator = head;
        return true;
    }
    return false;
}

template<typename T> bool ZLL<T>::done(){
    //if(iterator == tail && head != tail)
    if(iterator == nullptr)
    {
        return true;
    }
    else if(isEmpty())
    {
        return true;
    }
    else{
        return false;
    }
}

template<typename T> T ZLL<T>::getNext(){
    T tempData;

    if(!done())
    {
        tempData = iterator->data;
        iterator = iterator->next;
    }
    
    return tempData;
}

template<typename T> void ZLL<T>::printList(){
    Node<T>* currNode = head;

    if(listSize != 0)
    {
        cout << currNode->data;
        currNode = currNode->next;
        for(int i = 1; i < listSize; i++)
        {
            cout << ", " << currNode->data;
            currNode = currNode->next;
        }
        cout << endl;
    }
    else{
        cout << "List is empty" << endl;
    }
    
}

template<typename T> bool ZLL<T>::removeNode(int nodeIndex){
    Node<T>* currNode = head;
    Node<T>* currNodePrev;
    Node<T>* currNodeNext;
    if(!isEmpty())
    {
        for(int i = 0; i < nodeIndex; i++)
        {
            currNodePrev = currNode;
            currNode = currNode->next;
        }

        if(currNode == head)
        {
            if(listSize != 1)
            {
                currNodeNext = currNode->next;
            
                head = head->next;
                head->prev = nullptr;
            }
            else{
                head = nullptr;
                tail = nullptr;
            }
        }
        else if (currNode == tail)
        {
            currNodeNext = nullptr;

            tail = tail->prev;
            tail->next = nullptr;
        }
        else{
            currNodeNext = currNode->next;

            currNodePrev->next = currNodeNext;
            currNodeNext->prev = currNodePrev;
        }

        delete currNode;
        return true;
    }
    else{
        return false;
    }
}
template<typename T> bool ZLL<T>::isEmpty(){
    if(head == nullptr)
    {
        return true;
    }
    else{
        return false;
    }
}