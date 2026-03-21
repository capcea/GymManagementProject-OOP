#include <iostream>
#include <string>

using namespace std;

//Member class (Start)

class Member{
    char* name;
    int age;
    float weight;
    bool active;
    int noMeasurements;
    float* weightHistory;
public:
    Member();
    Member(const char* name, int age, float weight, bool active, int noMeasurements,const float* weightHistory);
    Member(const Member &obj);
    Member& operator=(const Member &obj);
    ~Member();
}

Member::Member(){
    name = new char[4];
    strcpy(name, "N/A");
    age = 0;
    weight = 0.0f;
    active = false;
    noMeasurements = 0;
    weightHistory = nullptr

}

Member::Member(const char* name, int age, float weight, bool active, int noMeasurements,const float* weightHistory){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->age = age;
    this->weight = weight;
    this->active = active;
    this->noMeasurements = noMeasurements;
    this->weightHistory = new float[this->noMeasurements];
    for (int i = 0; i < noMeasurements; i++)
        this->weightHistory[i] = weightHistory[i];
}

Member::Member(const Member &obj){
    this->name = new char[strlen(obj.name)+1];
    strcpy(this->name, obj.name);
    this->age = obj.age;
    this->weight = obj.weight;
    this->active = obj.active;
    this->noMeasurements = obj.noMeasurements;
    this->weightHistory = nullptr
    for (int i = 0; i < obj.noMeasurements; i++)
        this->weightHistory[i] = obj.weightHistory[i];
}

Member& Member::operator=(const Member &obj){
    if(this == &obj)
        return *this;
    delete[] name;
    delete[] weightHistory
    this->name = new char[strlen(obj.name)+1];
    strcpy(this->name, obj.name);
    this->age = obj.age;
    this->weight = obj.weight;
    this->active = obj.active;
    this->noMeasurements = obj.noMeasurements;
    this->weightHistory = new float[this->noMeasurements];
    for (int i = 0; i < obj.noMeasurements; i++)
        this->weightHistory[i] = obj.weightHistory[i];
    return *this
}

Member::~Member(){
    delete[] name;
    delete[] weightHistory;
};