#include <iostream>
#include<bits/stdc++.h>
using namespace std;
template <class t>
struct node
{
    t data;
    node *next;
};
template <class t>
class List{
private:
    node<t> *first;
    node<t> *last;
public:
    List(){
        first=NULL;
        last=NULL;
    }
    List(t value, int size){
        node<t> *tmp=new node<t>;
        tmp->data = value;
        tmp->next = NULL;
        first = tmp;
        last = tmp;
       tmp = NULL;
        for(int i=0;i<size-1;++i){
            node<t> *tmp = new node<t>;
            tmp->data = value;
            tmp->next = NULL;
            last->next = tmp;
            last = tmp;

        }
    }

class iterator {
public:
    node<t> *nodeit ;
    node<t> *headit ;
public:
    iterator () {
       nodeit = nullptr;
        headit = nullptr;
    }
    iterator (node<t> *Ptrn,node<t> *ptrh){
        nodeit = Ptrn;
        headit = ptrh;
    }

    void operator ++ () {
        if ( nodeit->next == NULL ){
            cout<<"it is Out \n";
            return;
        }
        nodeit = nodeit->next;
    }

    void operator -- (){
        List <t> :: iterator it;
        it.nodeit = this->headit;
        it.headit=this->headit;
        if (this->headit == this->nodeit ){
            cout<<"it is Out \n";
        }
        else {
            while (it.nodeit->next != NULL ){
                if(it.nodeit->next == this->nodeit){
                    this->nodeit = it.nodeit;
                    return;
                }
                ++it;
            }
        }
    }

    t& operator*() const {
        return nodeit->data;
    }

    bool operator == (const iterator& it)const{

        return nodeit == it.nodeit;
    }
//const b3d it
    bool operator != (const iterator & it)const{

        return nodeit != it.nodeit;
    }

};
List<t> & operator = (list <t> another_list)
{
    if( this == &another_list )
        return *this;

    iterator it =another_list.begin( );
    this -> push_back (*it);
    for(int it=1;it < another_list.end();it++)
    {
        this-> push_back(it);
    }
    return *this;
}

    void push_back(t value)
    {
        node <t> *tmp = new node<t>;
        tmp ->data = value;
        tmp->next = NULL;
        if(first == NULL)
        {
            first=tmp;
            last=tmp;
            tmp=NULL;
        }
        else
        {
            last->next=tmp;
            last=tmp;
        }
    }
    iterator erase(iterator pos) {
        node <t> *Delete = pos.nodeit->next;
        pos.nodeit->next = pos.nodeit->next->next;
        if (Delete == last) last = pos.nodeit;
        delete Delete;
        return pos;
    }


    void insert(t value, int pos) {
        node<t> *n = new node<t>;
        n->data = value;
        n->next = NULL;

        if (this->first == NULL) {
            if (pos != 0) {
                return;
            } else {
                this->first = n;
            }
        }
        if ( first != NULL && pos == 0) {
            n->next= this->first;
            this->first = n;
            return;
        }
        node<t> *cur = this->first;
        node<t>* pre = NULL;

          int i = 0;
        while (i < pos) {
            pre = cur;
            cur = cur->next;
            if (cur == NULL) {
                break;
            }
            i++;
        }
        n->next = cur;
        pre->next = n;
    }
    void display()
    {   node<t> *tmp = new node<t>;
        tmp=first;
        while(tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
           cout<<"\n";
    }
    int size(){
        int c = 0;
        node <t> *tmp = new node<t>;
        tmp = first;
        while (tmp != NULL)
        {
            ++c;
            tmp=tmp->next;
        }
        return c;
    }

    iterator begin() {
        return iterator(first,first);
    }

    iterator end() {
        return iterator(last,first);
    }
    void pop_back()
    {
        node <t> *cur = new node<t>;
        node<t> *pre = new node<t>;
        cur = first;
        while(cur->next!=NULL)
        {
            pre = cur;
            cur = cur ->next;
        }
        last = pre;
        pre -> next = NULL;
        delete cur;
    }
    
};
int main(){

List<int>l(5,5);
l.display();
l.push_back(2);
l.insert(1,0);
l.display();
cout<<l.size()<<"\n";
List<int>:: iterator it = l.begin();
    cout<<"it----\n"<<*it<<"\n";
    ++it;
    cout<<*it<<"\n";
     l.erase(it);

cout<<"after erase= "<<*it;
List<int> l2;
l2=l;
cout<<"\nlist2=list1\n";
l2.display();

    return 0;}
