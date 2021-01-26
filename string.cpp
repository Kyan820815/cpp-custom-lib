class MyString {

private:
    // s is the char pointer
    // which stores the address of our vector
    char *s;

    // maxsize is the total storage
    // capacity of the string
    int maxsize;

    // size is the number of elements
    // currently present in the string
    int size;

public:
    MyString() {
        maxsize = size = 0;
        s = new char[0];
    }
    
    MyString(const char *input) {
        maxsize = size = strlen(input);
        s = new char[maxsize+1];
        for (int i = 0; i < maxsize; ++i) {
            s[i] = input[i];
        }
        s[maxsize] = '\0';
    }
    
    MyString(const MyString &cpy) {
        maxsize = size = cpy.len();
        s = new char[maxsize+1];
        for (int i = 0; i < maxsize; ++i) {
            s[i] = cpy.s[i];
        }
        s[maxsize] = '\0';
    }
    
    ~MyString() {
        delete[] s;
    }
    
    void change(const char *newStr) {
        delete[] s;
        maxsize = size = strlen(newStr);
        s = new char[maxsize+1];
        for (int i = 0; i < maxsize; ++i) {
            s[i] = newStr[i];
        }
        s[maxsize] = '\0';
    }
    
    int len() const {
        return size;
    }
    
    MyString &operator=(const MyString &input) {
        if (this == &input) {
            return *this;
        }
        delete[] s;
        maxsize = size = input.len();
        s = new char[maxsize+1];
        for (int i = 0; i < maxsize; ++i) {
            s[i] = input.s[i];
        }
        s[maxsize] = '\0';
        return *this;
    }
    
    MyString &operator+=(const MyString &cpy) {
        if (maxsize < size + cpy.len()) {
            char *old = s;
            maxsize = size = size + cpy.len();
            s = new char[maxsize+1];
            for (int i = 0; i < strlen(old); ++i) {
                s[i] = old[i];
            }
            for (int i = strlen(old); i < maxsize; ++i) {
                s[i] = cpy.s[i-strlen(old)];
            }
            s[maxsize] = '\0';
            delete[] old;
        } else {
            for (int i = 0; i < cpy.len(); ++i) {
                s[i+size] = cpy.s[i];
            }
            s[cpy.len()+size] = '\0';
            size += cpy.len();
        }
        return *this;
    }
    
    MyString &operator+(const MyString &cpy) {
        return *this += cpy;
    }

    bool operator==(const MyString &cmp) {
        if (size != cmp.len()) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (s[i] != cmp.s[i]) {
                return false;
            }
        }
        return true;
    }
    
    void resize(int len) {
        maxsize = len;
        char *old = s;
        s = new char[maxsize+1];
        size = min((int)strlen(old), maxsize);
        for (int i = 0; i < size; ++i) {
            s[i] = old[i];
        }
        s[size] = '\0';
        delete[] old;
    }
    
    void print() {
        cout << s << "\n";
    }
};
