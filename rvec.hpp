#ifndef RVEC_HPP
#define RVEC_HPP
#include <ctime>
#include <cstdlib>
#include <iostream>
using std::cout;
/*
Random access vector

this is a psychopathy data structure that want to be a vector
where if you are going to access an item, you must search multiple
times after get it,its because when you access to it, the operator[]
generates a random number to set the index
*/

namespace yassin {
    template <typename T>
    class Rvec{
        private:
            T *ptr;
            unsigned int size;
        public: 
            Rvec(T arr[],unsigned int s);
            ~Rvec();
            void push(T elem);
            T pop();
            void print();
            T operator [] (unsigned int index);
            Rvec<T> operator + (Rvec<T> other); 
    };

    template <typename T>
    T Rvec<T>::operator [] (unsigned int index){
        if (size > 0){
            srand(time(NULL));
            return ptr[(unsigned int)(rand() % size)];
        }
    }
    template <typename T>
    Rvec<T> Rvec<T>::operator + (Rvec<T> other){
        T aux[size];
        ptr = new T[size + other.size];
        for (int i=0;i<size;i++){
            ptr[i] = aux[i];
        }
        for(int i=size;i<size + other.size;i++){
            ptr[i] = other.ptr[i-size];
        }
        size += other.size;
    }

    template <typename T>
    void Rvec<T>::print(){
        cout << "[ ";
        for (int i=0;i<size;i++){
            cout << ptr[i] << " ";   
        }
        cout << "]\n";
    }

    template <typename T>
    Rvec<T>::Rvec(T arr[],unsigned int s){
        ptr = new T[s];
        for (int i=0;i<s;i++){
            ptr[i] = arr[i];
        }
        size = s;
    }
    template <typename T>
    Rvec<T>::~Rvec(){
        delete ptr;
    }
    template <typename T>
    T Rvec<T>::pop(){
        if(size > 0){
            size -= 1;
            return ptr[size];
        }
    }
    template <typename T>
    void Rvec<T>::push(T elem){
        T *aux = new T[size];
        for(int i=0;i<size;i++){
            aux[i] = ptr[i];
        }
        ptr = new T[size+1];
        ptr[0] = elem;
        for(int i=1;i<size+1;i++){
            ptr[i] = aux[i-1];
        }
        size +=1;
    }
}


#endif
