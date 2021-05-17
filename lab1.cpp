#include <iostream>

struct Node{
    int data;
    Node *pnext;
};

struct List{
    Node *head;
    int size;
};

List new_list(){
    List *q = new List;
    q->size = 0;
    q->head = nullptr;
    return *q;
}

List new_list(List const &lst){ // создаем лист-копию
    Node *t = lst.head; // голова копируемого
    if (t == nullptr){
        new_list();
    }
    else{
        List *q = new List; // новый лист
        Node *n = new Node, *p; // 2 новых узла
        q->head = n; // n - голова листа q (пока n пустой)
        while (t != nullptr){ // пока не дошли до конца
            if (t->pnext != nullptr){ // если текущий - не последний
                p = new Node; // новый узел
                n->pnext = p; // записываем его как следующий
                n->data = t->data; // записываем в предыдущий данные из исходника
                n = p; // n теперь не пустой
                t = t->pnext; // переходит на следующий
            }
            else{ // если текущий - последний
                n->data = t->data; 
                n->pnext = nullptr;
                t = t->pnext;
            }
        }
        return *q;
    }
}

List push_list(List &lst, int number){
    Node *q = new Node;
    q->data = number;
    q->pnext = lst.head;
    lst.head = q;
    lst.size ++;
    return lst;
}

int pop_list(List &lst){
    int t = (lst.head)->data;
    Node *temp = lst.head;
    lst.head = temp->pnext;
    lst.size --;
    delete temp;
    return t;
}

int peak_list(List const &lst){
    return (lst.head)->data;
}

void delete_list(List &lst){
    Node *temp = lst.head;
    while (lst.size){
        pop_list;
    }
    delete &lst;
}

bool is_empty(List const &lst){
    return (lst.head == nullptr);
}

List reverse_list(List &lst){
    Node *t = lst.head, *p = nullptr, *v;
    while (t != nullptr){
        v = new Node;
        v->pnext = p;
        v->data = t->data;
        p = v;
        t =t->pnext;
    }

    t = lst.head;
    lst.head = p;
    while (t!= nullptr){
        v = t;
        t = t->pnext;
        delete v;
    }

    return lst;
}

int getsize(List &lst){
    return lst.size;
}