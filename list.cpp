#include <iostream>
using namespace std;

struct ListPair                  //Структура с инфополями и адресным полем
{
    int num;                         //Инфополе. значения из num будут передаваться в список
    ListPair *tail;                 //Адресное поле
};
 
struct List                      
{
    ListPair *head;                 //Указатель на последний активный элемент
};


List new_list(){
    List *p = new List;
    p->head = nullptr;
    return *p;
}

List new_list(List const &lst){ // not finished yet
    List *p = new List;
    ListPair *t = lst.head;
    if (t == nullptr){
        p->head == nullptr;
    } else {

    }
    p->head = lst.head;
    return *p;
}

List push_list(List &lst, int num){
    ListPair *p = new ListPair;           //При каждом вызове выделяется память
    p->num = num;                            //Записываем x в элемент структуры  element (в x структуры element)
    p->tail = lst.head;                      //Указываем, что след. элемент это объект по адресу Head
    lst.head = p;    
    return lst;                        //Указываем, что последний активный элемент это только что введенный
}

int pop_list(List &lst){
    int c = lst.head->num;
    ListPair *p = lst.head;
    lst.head = p->tail;
    delete p;
    return c;
}

int peak_list(List const&lst){
    int c = lst.head->num;
    return c;
}

void delete_list(List &lst){
    ListPair *p;
    while (lst.head!= nullptr){
        p = lst.head;
        lst.head = (lst.head)->tail;
        delete p;
    }
    delete &lst;
}

bool is_empty(List const &lst){
    if (lst.head == nullptr)
    return true;
    else
    return false;
}

List reverse_list(List &lst){

}
/*
int main() {
    chrono::steady_clock();
    chrono::system_clock();
    chrono::high_resolution_clock();

    auto start = chrono::steady_clock::now();

    int sum = 0;
    for (int i=0; i != 1000000; ++i){
        sum += i;
    }

    auto stop = chrono::steady_clock::now();
    cout << sum << endl;
    return 0;
    }
*/

