#include <iostream>
using namespace std;

class Dog
{
public:
    void setAge(int a);
    void setWeight(float w);
    int getAge();
    float getWeight();
private:
    int age;
    float weight;
};

void Dog::setAge(int a)
{
    age = a;
}

void Dog::setWeight(float w)
{
    weight = w;
}

int Dog::getAge()
{
    return age;
}

float Dog::getWeight()
{
    return weight;
}

int main()
{
    Dog dog; 
    dog.setAge(5);
    dog.setWeight(20.5);
    cout << dog.getAge() << dog.getWeight() << endl;
    return 0;
}
