
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

class Document
{

private:
    char* text;
    char* author;


public:

    Document() : text{ NULL }, author{ NULL } {
    }

    Document(const char* author, const char* text) {
        this->text = new char[strlen(text) + 1];
        strcpy_s(this->text, strlen(text) + 1, text);

        this->author = new char[strlen(author) + 1];
        strcpy_s(this->author, strlen(author) + 1, author);
    }

    Document(const Document& doc) {
        this->text = new char[strlen(doc.text) + 1];
        strcpy_s(this->text, strlen(doc.text) + 1, doc.text);

        this->author = new char[strlen(doc.author) + 1];
        strcpy_s(this->author, strlen(doc.author) + 1, doc.author);
    }

    ~Document() {
        if (text) {
            delete[]text;
            text = NULL;
        }
        if (author) {
            delete[]author;
            author = NULL;
        }
    }

    char* getText() const {
        return text;
    }
    char* getAuthor() const {
        return author;
    }

    void setAuthor(const char* author) {
        if (this->text)
            delete[]this->text;
        this->author = new char[strlen(author) + 1];
        strcpy_s(this->author, strlen(author) + 1, author);
    }
    void setText(const char* text) {
        if (this->author)
            delete[]this->author;
        this->text = new char[strlen(text) + 1];
        strcpy_s(this->text, strlen(text) + 1, text);
    }

    Document& operator=(const Document& doc) {

        if (this == &doc) return *this;

        if (this->author)
            delete[]author;
        if (this->text)
            delete[]text;

        this->text = new char[strlen(doc.text) + 1];
        strcpy_s(this->text, strlen(doc.text) + 1, doc.text);

        this->author = new char[strlen(doc.author) + 1];
        strcpy_s(this->author, strlen(doc.author) + 1, doc.author);

        return *this;

    }



};


class Printer 
{
    
private:
    Queue<Document> docs;

public:
    
    void addDoc(Document doc) {
        docs.enqueue(doc);
    }
    void printDoc() {
        if (isEmpty())
            return;
        Document tmp(docs.dequeue());
        std::cout << "Author: " << tmp.getAuthor() << std::endl;
        std::cout << "Text: " << tmp.getText() << std::endl;
    }

    bool isEmpty() const
    {
        return docs.isEmpty();
    }

    void wievQueue() {

        if (isEmpty())
            return;

        Element<Document>* tmp = docs.getHead();
        int i = 1;

        while (tmp)
        {
            Document tmpDoc = tmp->data;
            std::cout << i++ << " doc in queue from: " << tmpDoc.getAuthor() << std::endl;
            tmp = tmp->next;
        }

    }


};




int main()
{
    
    Printer p;
    p.addDoc(Document("first", "firstText"));
    p.addDoc(Document("second", "secondText"));
    p.addDoc(Document("third", "thirdText"));
    p.addDoc(Document("fourth", "fourthText"));

    p.wievQueue();
    std::cout << std::endl;

    p.printDoc();
    std::cout << std::endl;
    p.printDoc();
    std::cout << std::endl;
    p.printDoc();
    std::cout << std::endl;
    p.printDoc();
    std::cout << std::endl;





}

