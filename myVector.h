#include "Includes.h"
template <typename T> class myVector{
    private:
        T* arr;
        int capacity;
        int currentSize;

    public:
    //creates an empty vector with capacity of 1
    myVector(){
        arr = new T[1];
        capacity = 1;
        currentSize = 0;
    }
    //creates a vector and fills it
    myVector(size_t value, T data){
        arr = new T[value];
        for (int i = 0; i < value; i++){
            arr[i] = data;
        }
        capacity = value;
        currentSize = value;
    }
    myVector(T data){
        arr = new T[1];
        arr[0] = data;
        capacity = 1;
        currentSize = 1;
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
    void push_back(T duomenys){
 
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
    void pop_back(){
        currentSize--; 
    }


    T at(size_t index){
        if (index < currentSize){
            return arr[index];
        }
        else{
            throw std::out_of_range("Vector out of range");
        }
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

    // Erase a single element at position
    void erase(T* position) {
        if (position < arr || position >= arr + currentSize) {
            throw std::out_of_range("Position out of range");
        }
        std::copy(position + 1, arr + currentSize, position);
        --currentSize;
    }

    // Erase elements in range
    void erase(T* first, T* last) {
        if (first < arr || last > arr + currentSize || first > last) {
            throw std::out_of_range("Range out of range");
        }
        std::copy(last, arr + currentSize, first);
        currentSize -= (last - first);
    }


    // Swap the contents with another vector
    void swap(myVector& other) {
        std::swap(arr, other.arr);
        std::swap(capacity, other.capacity);
        std::swap(currentSize, other.currentSize);
    }

    // Resize the vector to contain n elements
    void resize(size_t n) {
        if (n > capacity) {
            reserve(n);
        }
        if (n > currentSize) {
            std::fill(arr + currentSize, arr + n, T());
        }
        currentSize = n;
    }
        // Insert a single element at position
    T* insert(T* position, const T& val) {
        size_t index = position - arr;
        if (currentSize == capacity) {
            reserve(capacity == 0 ? 1 : 2 * capacity);
        }
        position = arr + index;
        std::copy_backward(position, arr + currentSize, arr + currentSize + 1);
        *position = val;
        ++currentSize;
        return position;
    }

    // Insert multiple elements at position
    void insert(T* position, size_t n, const T& val) {
        size_t index = position - arr;
        if (currentSize + n > capacity) {
            reserve(currentSize + n);
        }
        position = arr + index;
        std::copy_backward(position, arr + currentSize, arr + currentSize + n);
        std::fill(position, position + n, val);
        currentSize += n;
    }

    // Insert elements from range [first, last) at position
    template <typename InputIterator>
    void insert(T* position, InputIterator first, InputIterator last) {
        size_t index = position - arr;
        size_t n = std::distance(first, last);
        if (currentSize + n > capacity) {
            reserve(currentSize + n);
        }
        position = arr + index;
        std::copy_backward(position, arr + currentSize, arr + currentSize + n);
        std::copy(first, last, position);
        currentSize += n;
    }


    // Comparison operators
    bool operator==(const myVector& other) const {
        if (currentSize != other.currentSize) return false;
        for (size_t i = 0; i < currentSize; ++i) {
            if (arr[i] != other.arr[i]) return false;
        }
        return true;
    }

    bool operator!=(const myVector& other) const {
        return !(*this == other);
    }

    bool operator<(const myVector& other) const {
        return std::lexicographical_compare(arr, arr + currentSize, other.arr, other.arr + other.currentSize);
    }

    bool operator<=(const myVector& other) const {
        return !(other < *this);
    }

    bool operator>(const myVector& other) const {
        return other < *this;
    }

    bool operator>=(const myVector& other) const {
        return !(*this < other);
    }
};