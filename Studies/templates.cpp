#include <iostream>
using namespace std;

template <typename T>

class Container {

private:
    T* data;
    int size;

public:
    Container(int s) : size(s) 
    {
        data = new T[size];
    }

    void setData(int index, T value) 
    {
        if (index >= 0 && index < size) 
        {
            data[index] = value;
        }
    }

    T getData(int index) 
    {
        if (index >= 0 && index < size) 
        {
            return data[index];
        }

        return T();
    }

    void display() 
    {
        for (int i = 0; i < size; i++) 
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~Container()
    {
        delete[] data;
    }
};

template <typename T>
T add(T a, T b) 
{
    return a + b;
}

template <typename T>
T multiply(T a, T b) 
{
    return a * b;
}

int main() {

    Container<int> intContainer(5);
    intContainer.setData(0, 10);
    intContainer.setData(1, 20);
    intContainer.setData(2, 30);
    intContainer.setData(3, 40);
    intContainer.setData(4, 50);
    intContainer.display();

    cout << "Sum of 10 and 20: " << add(10, 20) << endl;
    cout << "Product of 10 and 20: " << multiply(10, 20) << endl;

    Container<float> floatContainer(3);
    
    floatContainer.setData(0, 1.1f);
    floatContainer.setData(1, 2.2f);
    floatContainer.setData(2, 3.3f);
    floatContainer.display();

    cout << "Sum of 1.1 and 2.2: " << add(1.1f, 2.2f) << endl;
    cout << "Product of 1.1 and 2.2: " << multiply(1.1f, 2.2f) << endl;

    return 0;
}
