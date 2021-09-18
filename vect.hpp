#include <iostream>
#ifndef VECT_HPP
#define VECT_HPP
#include <iostream>
using namespace std;

// creacion de un namespace 
namespace yassin{
    // los template siempre van antes de la funcion o clase que los usa
    // puede ser typename o class en el caso de ser una clase y no una primitiva
    template <typename T>
    class Vec{
        private:
            T *ptr; // vector que acogera el array dinamico
            unsigned int size; // tamano del array en cuestion para saber acceder
        public:
            Vec(T arr[],unsigned int s); // constructor con los valores iniciales
            ~Vec(); // destructor que se encarga de hacer delete a ptr
            /*Vec(unsigned int s);
            Vec();*/
            void print(); // mostrar el array en forma
            T pop();
            void push(T elem);
            T operator[](unsigned index);
    };

    template <typename T>
    Vec<T>::Vec(T arr[],unsigned int s){
        ptr = new T[s];
        size = s;
        for (unsigned int i=0;i<size;i++){
            ptr[i] = arr[i];
        }
    }
    /*template <typename T>
    Vec<T>::Vec(unsigned int s){
        ptr = new T[s];
        size = s;
        for (unsigned int i=0;i<size;i++){
            ptr[i] = 0;
        }
    }
    template <typename T>
    Vec<T>::Vec(){
        size = 0;
    }*/
    template <typename T>
    Vec<T>::~Vec(){
        delete ptr;
    }

    template <typename T>
    void Vec<T>::print(){
        cout << "[ ";
        for(unsigned int i=0;i<size;i++){
            cout << ptr[i] << " ";
        }
        cout <<"]\n";
    }
    template <typename T>
    T Vec<T>::pop(){
        if (size >0){
            size-=1;
            return ptr[size];
        }
    }
    template <typename T>
    void Vec<T>::push(T elem){
        if (size == 0){
            ptr = new T[0];
        }
        T *aux = new T[size];
        for(int i=0;i<size;i++){
            aux[i] = ptr[i];
        }
        ptr = new T[size+1];
        ptr[0] = elem;
        size+=1;
        for (int i=1;i<size;i++){
            ptr[i] = aux[i-1];
        }
    }

    template <typename T>
    T Vec<T>::operator[](unsigned int index){
        
        return ptr[index%size];
    }

}
#endif
