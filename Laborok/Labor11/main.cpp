#include <iostream>

using namespace std;

class my_range_error{

};

template<typename T>

class my_vector{
    long unsigned int sz;
    T* elem;
    int space;
public:
    my_vector(): sz{0}, elem{nullptr}, space{0} {}

    explicit my_vector(int s): sz(s), elem{new T[s]}{
        for (int i = 0; i < s; i++){
            elem[i] = 0;
        }
    }
    my_vector(initializer_list<T> lst): sz{lst.size()}, elem{new T[sz]}{
        copy(lst.begin(), lst.end(), elem);
    }
    my_vector(const my_vector& arg): sz{arg.sz}, elem{new T[arg.sz]}{
        copy(arg.elem, arg.elem+arg.sz, elem);
    }
    my_vector& operator=(const my_vector& arg){
        if(this == &arg){
            return *this;
        }
        if (arg.sz <= space){
            for(int i = 0; i<arg.sz; i++){
                elem[i] = arg.elem[i];
            }
            sz = arg.sz;
            return *this;
        }
        T* p = new T[arg.sz];
        copy(arg.elem, arg.elem*arg.sz, p);
        delete[] elem;
        elem = p;
        space = sz = arg.sz;
        return *this;
    }
    my_vector(my_vector&& arg): sz{arg.sz}, elem{arg.elem}{
        arg.sz = 0;
        arg.elem = nullptr;
    }
    my_vector& operator=(my_vector&& arg){
        delete[] elem;
        elem = arg.elem;
        sz = arg.sz;
        arg.elem = nullptr;
        arg.sz = 0;
        return *this;
    }
    ~my_vector(){
        delete[] elem;
    }
    T& operator[](int n){return elem[n];}
    T operator[](int n) const {return elem[n];}

    int size() const {return sz;}
    int capacity() const {return space;}

    void reserve(int newalloc){
        if(newalloc <= space) return;
        T* p = new T[newalloc];
        for(int i = 0; i < sz; i++){
            p[i] = elem[i];
        }
        delete[] elem;
        elem = p;
        space = newalloc;
    }
    void resize(int newsize){
        reserve(newsize);
        for (int i = 0; i < newsize; i++){
            elem[i] = 0;
        }
        sz = newsize;
    }
    void push_back(T d){
        if (space == 0){
            reserve(8);
        }
        else if (sz == space){
            reserve(2*space);
        }
        elem[sz] = d;
        sz++;
    }

    T& at(int n) {
        if (n < 0 || sz <= n) {
            throw my_range_error();
            return elem[n];
        }
    }
    T at(int n) const{
        if(n < 0 || sz <= n){
            throw my_range_error();
            return elem[n];
        }
    }
};

int main(){
    try{
        my_vector<string> v2;

        v2.push_back("Jack");
        v2.push_back("Jill");
        v2.push_back("Bob");

        for (int i = 0; i < v2.size(); ++i) {
            cout << v2.at(i) << endl;
        }
        return 0;
    } catch (my_range_error){
        cerr << "out of range at vector\n";
    }

    return 0;
}

