#include "Includes.h"
template <typename T> class myVector{
    private:
        T* arr;
        int capacity;
        int currentSize;

    public:

    myVector(){
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    ~myVector(){
        delete [] arr;
    }
    void push(T duomenys){
 
        // if capacity reached, double size
        if (current == capacity) {
            T* temp = new T[2 * capacity];
 
            // copy elements
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
 
            // deleting previous array
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
 
        // Adding data
        arr[current] = duomenys;
        current++;
    }

    // function to delete last element
    void pop(){
        current--; 
    }


    void push(T duomenys, int index){
 
        // if index is equal to capacity then do push
        if (index == capacity)
        {
            push(duomenys);
        }
        // if else(index > capacity)
        // {
        //     cout << "error, out of bounds\n";
        //     terminate();
        // }
        else
        {
            arr[index] = duomenys;
        }
    }

    T get(int index){
        // if index is within the range
        if (index < current)
            return arr[index];
        // if index is not within range
        return -1;
    }


    // function to get size of the vector
    int getSize(){ 
        return current; 
    }
    // function to get capacity of the vector
    int getCapacity(){ 
        return capacity; 
    }


    // function to print out all array elements
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};