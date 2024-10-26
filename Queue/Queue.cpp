


#include <iostream>


template<typename structType>
struct Element {

    structType data;
    Element<structType>* next;
    Element(structType data) {
        this->data = data;
        next = NULL;
    }
};

template <typename classType>
class Queue
{

private:
    Element<classType>* head;
    Element<classType>* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    //add element to queue
    void enqueue(classType value)
    {

        Element<classType>* newElement = new Element<classType>(value);
        if (tail == NULL) {
            head = tail = newElement;
            return;
        }

        tail->next = newElement;
        tail = newElement;

    }

    //delete from queue
    classType dequeue()
    {
        Element<classType>* tmp = head;
        head = head->next;
        if (!head)
            tail = nullptr;

        classType res = tmp->data;
        delete tmp;
        tmp = NULL;
        return res;

    }

    bool isEmpty() const
    {
        return !head;
    }
    
    Element<classType>* getHead() const
    {
        return head;
    }

    int peek()
    {
        return head->data;
    }

    ~Queue() {
        while (!isEmpty())
            dequeue();
        head = tail = nullptr;
    }

};

template <typename reverse>
void printReverse(Element<reverse>* element) {
    if (!element)
        return;

    printReverse(element->next);

    std::cout << element->data << std::endl;

}

template <typename Qreverse>
void QueuePrintReverse(const Queue<Qreverse>& q) {

    Element<Qreverse>* head = q.getHead();

    printReverse(head);

}





int main()
{
    
    Queue < char > q;
    q.enqueue('c');
    q.enqueue('b');
    q.enqueue('a');
    
    //while (!q.isEmpty())
    //{
    //    std::cout << q.dequeue() << std::endl;
    //}

    QueuePrintReverse(q);




}

