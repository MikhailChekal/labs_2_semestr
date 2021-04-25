#include <iostream>
#include <random>

#include <chrono>


struct Node{

int num;
public:
    Node *parent, *left, *right;
    int height;

    Node (int number, Node *parent_node){
        num = number;
        parent = parent_node;
        left = nullptr; right = nullptr;
        height = 1;
    }

    int bfactor(){return ((right->height) - (left->height));}

    bool find_node(int key) const{
        if (key == num) return true;
        else if ((key < num) and (left != nullptr)) return left->find_node(key);
        else if ((key > num) and (right != nullptr)) return right->find_node(key);
        else return false;
    }

    void list_node() const{
        if (left != nullptr) left->list_node();

        std::cout << num << " ";

        if (right != nullptr) right->list_node();
    }

    bool rotate_left(){
        if (right == nullptr) { std::cout << "impossible rotation"; return false;}
        else{
            right->parent = parent;
            parent = right;
            right = parent->left; if (parent->left != nullptr)  parent->left->parent = this;
            parent->left = this;
            int l_height, r_height;
            if (this->left != nullptr) l_height= (this->left)->height;
            else l_height=0;
            if (this->right!= nullptr) r_height= this->right->height;
            else r_height=0;
            this->height = std::max(l_height, r_height)+1;
            if (parent->left != nullptr) l_height= (parent->left)->height;
            else l_height=0;
            if (parent->right!= nullptr) r_height= parent->right->height;
            else r_height=0;
            parent->height = std::max(l_height, r_height)+1;


            if (parent->parent != nullptr){
                if (parent->parent->num >parent->num) parent->parent->left = parent;
                else parent->parent->right=parent;return false;
            }
            else return true;
        }
    }

    bool rotate_right(){
        if (left == nullptr) { std::cout << "impossible rotation"; return false; }
        else{
            left->parent = parent;
            parent = left;
            left = parent->right; if (parent->right != nullptr) parent->right->parent = this;

            parent->right = this;

            int l_height, r_height;
            if (this->left != nullptr) l_height= (this->left)->height;
            else l_height=0;
            if (this->right!= nullptr) r_height= this->right->height;
            else r_height=0;
            this->height = std::max(l_height, r_height)+1;
            if (parent->left != nullptr) l_height= (parent->left)->height;
            else l_height=0;
            if (parent->right!= nullptr) r_height= parent->right->height;
            else r_height=0;
            parent->height = std::max(l_height, r_height)+1;

            if (parent->parent != nullptr){
                if (parent->parent->num >parent->num) parent->parent->left = parent;
                else parent->parent->right=parent;
                return false;
            }
            else return true;

        }
    }

    bool balance(){
        int l, r;
        if (bfactor == 2){

            if (right->left != nullptr) l=(right->left)->height;
            else l=0;
            if (right->right!= nullptr) r=(right->right)->height;
            else r=0;
            if (l<=r){

                return this->rotate_left();

            }
            else{
                right->rotate_right();
                bool e = this->rotate_left();

                return e;
            }
        }
        if (l-r ==2){

            if (left->left != nullptr) l=(left->left)->height;
            else l=0;
            if (left->right!= nullptr) r=(left->right)->height;
            else r=0;
            if (r<=l){
                return this->rotate_right();
            }
            else{
                left->rotate_left();
                bool e = this->rotate_right();

               return e;
            }
        }
        return false;
    }


};

class IntTree{


public:
    unsigned size_of_tree;
    Node *root;


public:

    IntTree(){
        size_of_tree = 0;
        root = nullptr;
    }


    void insert(int key){
        Node *t = root;

        if (root == nullptr){
            Node *k = new Node(key, nullptr);
            size_of_tree++;
            root = k;
            return;
        }

        while (t->height > 1){

            if (t->num == key) return;
            else if (key < t->num) { if (t->left == nullptr) break; else t = t->left; }
            else {if (t->right == nullptr) break; else t = t->right; }
        }


        if (key == t->num) return;
        else{
            Node *k = new Node(key, t);
            size_of_tree++;
            if (key > t->num) t->right = k;
            if (key < t->num) t->left = k;

            while (t->parent != nullptr){

                int l_height, r_height;
                if (t->left != nullptr) l_height=t->left->height;
                else l_height=0;
                if (t->right!= nullptr) r_height=t->right->height;
                else r_height=0;
                t->height = std::max(l_height, r_height)+1;
                t = t->parent;
            }
            int l_height, r_height;
            if (t->left != nullptr) l_height=t->left->height;
            else l_height=0;
            if (t->right!= nullptr) r_height=t->right->height;
            else r_height=0;
            t->height = std::max(l_height, r_height)+1;




            while (k->parent != nullptr){

                if (k->balance()) root = k->parent;
                k = k->parent;
            }

            if (k->balance()) root = k->parent;
        }

    }


    bool find(int key){
        if (size_of_tree == 0) return false;
        else{
            return (*root).find_node(key);
        }
    }


    unsigned size(){
        return size_of_tree;
    }


    void list(){
        if (root == nullptr) std::cout << "Empty";
        else{
            (*root).list_node();
            std::cout << std::endl;
        }
    }

};

class NaiveIntTree{

public:
    unsigned size_of_tree;
    Node *root;


public:

    NaiveIntTree(){
        size_of_tree = 0;
        root = nullptr;
    }


    void insert(int key){
        Node *t = root;

        if (root == nullptr){
            Node *k = new Node(key, nullptr);
            size_of_tree++;
            root = k;
            return;
        }

        while ((t->left!= nullptr) or (t->right!= nullptr)){
            if (t->num == key) return;
            else if (key < t->num) { if (t->left == nullptr) break; else t = t->left; }
            else {if (t->right == nullptr) break; else t = t->right; }
        }


        if (key == t->num) return;
        else{
            Node *k = new Node(key, t);
            size_of_tree++;
            if (key > t->num) t->right = k;
            if (key < t->num) t->left = k;
        }

    }


    bool find(int key){
        if (size_of_tree == 0) return false;
        else{
            return (*root).find_node(key);
        }
    }


    unsigned size(){
        return size_of_tree;
    }


    void list(){
        if (root == nullptr) std::cout << "Empty";
        else{
            (*root).list_node();
            std::cout << std::endl;
        }
    }




};


int main(){
    auto start = std::chrono::steady_clock:: now();
    float sum = 0.f;
    const int64_t y = 10000000;

    IntTree tree = IntTree();

    //NaiveIntTree tree = NaiveIntTree();

    for (long long counter =1; counter != y; ++counter){
        tree.insert(rand()*10238457/74383);
    }


    auto stop = std::chrono::steady_clock::now();
    auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    std::cout << sum << "  "<< duration << std::endl;
}
