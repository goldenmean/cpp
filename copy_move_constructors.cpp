class MyResource {
public:
    // Constructors and destructor
    MyResource() : data(new int[100]) {}
    ~MyResource() { delete[] data; }

    // Copy constructor
    MyResource(const MyResource& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Copy assignment operator
    MyResource& operator=(const MyResource& other) {
        if (&other == this) { return *this; }
        std::copy(other.data, other.data + 100, data);
        return *this;
    }

    // Move constructor
    // MyResource(MyResource&& other) noexcept : data(std::move(other.data)) {
    MyResource(MyResource&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    MyResource& operator=(MyResource&& other) noexcept {
        if (&other == this) { return *this; }
        delete[] data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }

private:
    int* data;
};



