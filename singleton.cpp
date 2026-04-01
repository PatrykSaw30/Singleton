#include <iostream>
#include <functional>

class Singleton {
private:
    int n;
    double a = 0.0;
    double b = 0.0;

    std::function<double(int)> func;

    static Singleton* instance_ptr;
    Singleton() = default;
    ~Singleton() { instance_ptr = nullptr; }


public:
    static Singleton* getInstance()
    {
        if(!instance_ptr)
        {
            instance_ptr = new Singleton();
        }
        return instance_ptr;
    }

    void setN(int value) { n = value; }
    void setA(double value) { a = value; }
    void setB(double value) { b = value; }
    void setFunction(std::function<double(int)> f) { func = f; }

    int getN() const { return n; }
    double getA() const { return a; }
    double getB() const { return b; }
    std::function<double(int)> getFunction() const { return func; }

    double integrateRectangle() 
    {
        if(!func || n <= 0) return 0.0;

        double h = (b - a) / n;
        double sum = 0.0;

        for(int i = 0; i < n; ++i)
        {
            double x = a + (i + 1) * h;
            sum += func(x);
        }

        return sum * h;
    }
    

};

Singleton* Singleton::instance_ptr = nullptr;

int main()
{
    auto* ptr = Singleton::getInstance();

    ptr->setN(1);
    ptr->setA(1.0);
    ptr->setB(2.0);

    ptr->setFunction([](double x) {
        return x * x;
    });

    std::cout << "Result calculation of the inregral: " << ptr->integrateRectangle() << std::endl;
}
