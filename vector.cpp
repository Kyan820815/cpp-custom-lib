template <typename T> class MyVector {

private:
    // arr is the integer pointer
    // which stores the address of our vector
    T* arr;
 
    // capacity is the total storage
    // capacity of the vector
    int capacity;
 
    // current is the number of elements
    // currently present in the vector
    int current;
 
public:
    // Default constructor to initialise
    // an initial capacity of 1 element and
    // allocating storage using dynamic allocation
    MyVector() {
        current = 0;
        arr = new T[1];
        capacity = 1;
    }
    
    ~MyVector() {
        delete[] arr;
    }
    
    MyVector& operator=(const MyVector<T>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        capacity = rhs.getcapacity();
        current = rhs.size();
        arr = new T[capacity];
        for (int i = 0; i < current; ++i) {
            arr[i] = rhs.arr[i];
        }
        return *this;
    }
    
    MyVector(std::size_t count, const T &value) {
        arr = new T[count];
        current = capacity = count;
        for (int i = 0; i < capacity; ++i) {
            arr[i] = value;
        }
    }
    
    void swap(MyVector<T> &rhs) {
        std::swap(rhs.current, current);
        std::swap(rhs.capacity, capacity);
        std::swap(rhs.arr, arr);
    }
    
    MyVector(MyVector<T> &&rhs) {
        capacity = rhs.getcapacity();
        current = rhs.size();
        arr = new T[capacity];
        for (int i = 0; i < current; ++i) {
            arr[i] = rhs.arr[i];
        }
    }
    
    MyVector(MyVector<T> &rhs) {
        capacity = 1;
        current = 0;
        arr = new T[1];
        rhs.swap(*this);
    }
    
    // Function to add an element at the last
    void push(T data) {
        if (current == capacity) {
            T *old = arr;
            arr = new T[capacity*2];
            for (int i = 0; i < current; ++i) {
                arr[i] = old[i];
            }
            delete[] old;
            capacity *= 2;
        }
        arr[current++] = data;
    }
 
    // function to add element at any index
    void push(T data, int index) {
        if (index < current) {
            arr[index] = data;
        } else {
            push(data);
        }
    }
 
    // function to extract element at any index
    T get(int index) {
        if (index < current) {
            return arr[index];
        }
    }
 
    // function to delete last element
    void pop() {
        --current;
    }
 
    // function to get size of the vector
    int size() const {
        return current;
    }
 
    // function to get capacity of the vector
    int getcapacity() const {
        return capacity;
    }
 
    // function to print array elements
    void print() {
        for (int i = 0; i < current; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
