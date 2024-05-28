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
        currentSize = 0;
    }

    ~myVector(){
        delete [] arr;
    }
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T* new_arr = new T[new_capacity];
            for (size_t i = 0; i < currentSize; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity = new_capacity;
        }
    }
    void push(T duomenys){
 
        // if capacity reached, double size
        if (currentSize == capacity) {
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
        arr[currentSize] = duomenys;
        currentSize++;
    }

    // function to delete last element
    void pop(){
        currentSize--; 
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
        if (index < currentSize)
            return arr[index];
        // if index is not within range
        return -1;
    }


    // function to get size of the vector
    int getSize(){ 
        return currentSize; 
    }
    // function to get capacity of the vector
    int getCapacity(){ 
        return capacity; 
    }


    // function to print out all array elements
    void print()
    {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // check if empty
    bool empty(){
        if (currentSize == 0){
            return true;
        }else{
            return false;
        }
    }
    

    // clears vector
    void clear(){
        currentSize = 0;
    }

 // Access the first element
    T& first() {
        if (currentSize == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return arr[0];
    }

    // Access the last element
    T& last() {
        if (currentSize == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return arr[currentSize - 1];
    }

    // Iterator to the beginning
    T* begin() {
        return arr;
    }

    // Iterator to the end
    T* end() {
        return arr + currentSize;
    }



    T& operator[] (size_t index){
        if (index >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    // Assign function to assign multiple copies of a value
    void assign( size_t count, const T& value ){
        clear();
        for (int i = 0; i < count; i++){
            arr[i] = value;
        }
    }

   // Assign function to assign a range of elements
    template <typename InputIterator>
    void assign(InputIterator first, InputIterator last) {
        size_t new_size = std::distance(first, last);
        if (new_size > capacity) {
            reserve(new_size);
        }
        currentSize = new_size;
        std::copy(first, last, arr);
    }
};