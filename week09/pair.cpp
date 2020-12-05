/*
1. Abstract Class를 정의하고 각 클래스에 필요한 기능들을 디자인한다.

• Abstract class Animal 클래스와 이를 상속받는 Abstract class Dog, Bird 구현
• 각 클래스마다 pure virtual function 2개를 정의
• 조원하마 Dog, Bird 중 하나씩 선택해서 구현

2. 정의한 Abstract Class 마다 그것을 상속 받는 3개의 클래스를 작성
*/

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    virtual string Sound() = 0; //동물의 소리

    virtual string Look() = 0; //동물의 외형
};

class Dog : public Animal {
public:
    virtual string Sound() = 0;

    virtual string Look() = 0;
};

class Pome : public Dog {
public:
    virtual string Sound()
    {
        return "PomePome!";
    }

    virtual string Look()
    {
        return "So~~~Cute!";
    }
};

class Samo : public Dog {
public:
    virtual string Sound()
    {
        return "SamoSamo!";
    }

    virtual string Look()
    {
        return "So~~~Big!";
    }
};

class Jindo : public Dog {
public:
    virtual string Sound()
    {
        return "JindoJindo!";
    }

    virtual string Look()
    {
        return "Loyalty!";
    }
};

class Bird : public Animal {
public:
    virtual string Sound() = 0;

    virtual string Look() = 0;
};

class Eagle : public Bird {
public:
    virtual string Sound()
    {
        return "EHHHA!";
    }

    virtual string Look()
    {
        return "charismatic!";
    }
};

class Pelican : public Bird {
public:
    virtual string Sound()
    {
        return "Boook!";
    }

    virtual string Look()
    {
        return "well eaten!";
    }
};

class Wild_goose : public Bird {
public:
    virtual string Sound()
    {
        return "Ki-look!";
    }

    virtual string Look()
    {
        return "thin!";
    }
};

int main() {
    Pome pome;
    Samo samo;
    Jindo jindo;

    Eagle eagle;
    Pelican pelican;
    Wild_goose wild_goose;

    cout << "Pome : " << pome.Sound() << ", " << pome.Look() << endl;
    cout << "Samo : " << samo.Sound() << ", " << samo.Look() << endl;
    cout << "Jindo : " << jindo.Sound() << ", " << jindo.Look() << endl;

    cout << "Eagle : " << eagle.Sound() << ", " << eagle.Look() << endl;
    cout << "Pelican : " << pelican.Sound() << ", " << pelican.Look() << endl;
    cout << "Wild goose : " << wild_goose.Sound() << ", " << wild_goose.Look() << endl;
    return 0;
}