#include <iostream>
#include <cstring>

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
    friend ostream& operator<<(ostream& out, const Member& obj);
    friend istream& operator>>(istream& in, Member& obj);
};

Member::Member(){
    name = new char[4];
    strcpy(name, "N/A");
    age = 0;
    weight = 0.0f;
    active = false;
    noMeasurements = 0;
    weightHistory = nullptr;

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
    this->weightHistory = nullptr;
    for (int i = 0; i < obj.noMeasurements; i++)
        this->weightHistory[i] = obj.weightHistory[i];
}

Member& Member::operator=(const Member &obj){
    if(this == &obj)
        return *this;
    delete[] name;
    delete[] weightHistory;
    this->name = new char[strlen(obj.name)+1];
    strcpy(this->name, obj.name);
    this->age = obj.age;
    this->weight = obj.weight;
    this->active = obj.active;
    this->noMeasurements = obj.noMeasurements;
    this->weightHistory = new float[this->noMeasurements];
    for (int i = 0; i < obj.noMeasurements; i++)
        this->weightHistory[i] = obj.weightHistory[i];
    return *this;
}

Member::~Member(){
    delete[] name;
    delete[] weightHistory;
};

ostream& operator<<(ostream& out, const Member& obj) {
    out << "Member name: " << obj.name << "\n";
    out << "Age: " << obj.age << "\n";
    out << "Weight: " << obj.weight << "\n";
    out << "Active: " << obj.active << "\n";
    out << "Number of measurements: " << obj.noMeasurements << "\n";
    out << "Weight history: ";

    if (obj.noMeasurements > 0 && obj.weightHistory != nullptr) {
        for (int i = 0; i < obj.noMeasurements; i++) {
            out << obj.weightHistory[i] << " ";
        }
    } else {
        out << "No measurements";
    }

    out << "\n";
    return out;
}

istream& operator>>(istream& in, Member& obj) {
    char buffer[100];

    cout << "Enter member name: ";
    in >> buffer;

    delete[] obj.name;
    obj.name = new char[strlen(buffer) + 1];
    strcpy(obj.name, buffer);

    cout << "Enter age: ";
    in >> obj.age;

    cout << "Enter weight: ";
    in >> obj.weight;

    cout << "Is active? (0/1): ";
    in >> obj.active;

    cout << "Enter number of measurements: ";
    in >> obj.noMeasurements;

    delete[] obj.weightHistory;

    if (obj.noMeasurements > 0) {
        obj.weightHistory = new float[obj.noMeasurements];
        for (int i = 0; i < obj.noMeasurements; i++) {
            cout << "Weight history[" << i << "]: ";
            in >> obj.weightHistory[i];
        }
    } else {
        obj.weightHistory = nullptr;
    }

    return in;
}

//Member class (End)

//Subscription class(Start)
class Subscription {
    char type;
    double basePrice;
    int durationMonths;
    bool active;

public:
    Subscription();
    Subscription(char type, double basePrice, int durationMonths, bool active);
    Subscription(const Subscription& obj);
    Subscription& operator=(const Subscription& obj);
    ~Subscription();
};

Subscription::Subscription() {
    type = 'B'; //B -Basic, P- Premium, V - VIP
    basePrice = 0.0;
    durationMonths = 0;
    active = false;
}

Subscription::Subscription(char type, double basePrice, int durationMonths, bool active) {
    this->type = type;
    this->basePrice = basePrice;
    this->durationMonths = durationMonths;
    this->active = active;
}

Subscription::Subscription(const Subscription& obj) {
    this->type = obj.type;
    this->basePrice = obj.basePrice;
    this->durationMonths = obj.durationMonths;
    this->active = obj.active;
}

Subscription& Subscription::operator=(const Subscription& obj) {
    if (this == &obj) {
        return *this;
    }

    this->type = obj.type;
    this->basePrice = obj.basePrice;
    this->durationMonths = obj.durationMonths;
    this->active = obj.active;

    return *this;
}

Subscription::~Subscription() {
}

//Subscription Class (end)

//Trainer Class (Start)

class Trainer {
    char* name;
    int experienceYears;
    float rating;
    bool available;
    static int noTrainers;

public:
    Trainer();
    Trainer(const char* name, int experienceYears, float rating, bool available);
    Trainer(const Trainer& obj);
    Trainer& operator=(const Trainer& obj);
    ~Trainer();
    friend ostream& operator<<(ostream& out, const Trainer& obj);
    friend istream& operator>>(istream& in, Trainer& obj);
};

int Trainer::noTrainers = 0;

Trainer::Trainer() {
    name = new char[4];
    strcpy(name, "N/A");
    experienceYears = 0;
    rating = 0.0f;
    available = false;
    noTrainers++;
}

Trainer::Trainer(const char* name, int experienceYears, float rating, bool available) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->experienceYears = experienceYears;
    this->rating = rating;
    this->available = available;
    noTrainers++;
}

Trainer::Trainer(const Trainer& obj) {
    this->name = new char[strlen(obj.name) + 1];
    strcpy(this->name, obj.name);
    this->experienceYears = obj.experienceYears;
    this->rating = obj.rating;
    this->available = obj.available;
    noTrainers++;
}

Trainer& Trainer::operator=(const Trainer& obj) {
    if (this == &obj) {
        return *this;
    }

    delete[] name;

    this->name = new char[strlen(obj.name) + 1];
    strcpy(this->name, obj.name);
    this->experienceYears = obj.experienceYears;
    this->rating = obj.rating;
    this->available = obj.available;

    return *this;
}

Trainer::~Trainer() {
    delete[] name;
    noTrainers--;
}
ostream& operator<<(ostream& out, const Trainer& obj) {
    out << "Trainer name: " << obj.name << "\n";
    out << "Experience years: " << obj.experienceYears << "\n";
    out << "Rating: " << obj.rating << "\n";
    out << "Available: " << obj.available << "\n";
    out << "Total trainers: " << Trainer::noTrainers << "\n";

    return out;
}
istream& operator>>(istream& in, Trainer& obj) {
    char buffer[100];

    cout << "Enter trainer name: ";
    in >> buffer;

    delete[] obj.name;
    obj.name = new char[strlen(buffer) + 1];
    strcpy(obj.name, buffer);

    cout << "Enter experience years: ";
    in >> obj.experienceYears;

    cout << "Enter rating: ";
    in >> obj.rating;

    cout << "Is available? (0/1): ";
    in >> obj.available;

    return in;
}

//Trainer class (end)

//Workout class (start)

class Workout {
    char* type;
    int durationMinutes;
    float estimatedCalories;
    bool intense;
    int noExercises;
    int* repetitions;

public:
    Workout();
    Workout(const char* type, int durationMinutes, float estimatedCalories, bool intense, int noExercises, const int* repetitions);
    Workout(const Workout& obj);
    Workout& operator=(const Workout& obj);
    ~Workout();
    friend ostream& operator<<(ostream& out, const Workout& obj);
    friend istream& operator>>(istream& in, Workout& obj);
};

Workout::Workout() {
    type = new char[4];
    strcpy(type, "N/A");
    durationMinutes = 0;
    estimatedCalories = 0.0f;
    intense = false;
    noExercises = 0;
    repetitions = nullptr;
}

Workout::Workout(const char* type, int durationMinutes, float estimatedCalories, bool intense, int noExercises, const int* repetitions) {
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
    this->durationMinutes = durationMinutes;
    this->estimatedCalories = estimatedCalories;
    this->intense = intense;
    this->noExercises = noExercises;

    if (this->noExercises > 0) {
        this->repetitions = new int[this->noExercises];
        for (int i = 0; i < this->noExercises; i++) {
            this->repetitions[i] = repetitions[i];
        }
    } else {
        this->repetitions = nullptr;
    }
}

Workout::Workout(const Workout& obj) {
    this->type = new char[strlen(obj.type) + 1];
    strcpy(this->type, obj.type);
    this->durationMinutes = obj.durationMinutes;
    this->estimatedCalories = obj.estimatedCalories;
    this->intense = obj.intense;
    this->noExercises = obj.noExercises;

    if (this->noExercises > 0) {
        this->repetitions = new int[this->noExercises];
        for (int i = 0; i < this->noExercises; i++) {
            this->repetitions[i] = obj.repetitions[i];
        }
    } else {
        this->repetitions = nullptr;
    }
}

Workout& Workout::operator=(const Workout& obj) {
    if (this == &obj) {
        return *this;
    }

    delete[] type;
    delete[] repetitions;

    this->type = new char[strlen(obj.type) + 1];
    strcpy(this->type, obj.type);
    this->durationMinutes = obj.durationMinutes;
    this->estimatedCalories = obj.estimatedCalories;
    this->intense = obj.intense;
    this->noExercises = obj.noExercises;

    if (this->noExercises > 0) {
        this->repetitions = new int[this->noExercises];
        for (int i = 0; i < this->noExercises; i++) {
            this->repetitions[i] = obj.repetitions[i];
        }
    } else {
        this->repetitions = nullptr;
    }

    return *this;
}

Workout::~Workout() {
    delete[] type;
    delete[] repetitions;
}
ostream& operator<<(ostream& out, const Workout& obj) {
    out << "Workout type: " << obj.type << "\n";
    out << "Duration (minutes): " << obj.durationMinutes << "\n";
    out << "Estimated calories: " << obj.estimatedCalories << "\n";
    out << "Intense: " << obj.intense << "\n";
    out << "Number of exercises: " << obj.noExercises << "\n";
    out << "Repetitions: ";

    if (obj.noExercises > 0 && obj.repetitions != nullptr) {
        for (int i = 0; i < obj.noExercises; i++) {
            out << obj.repetitions[i] << " ";
        }
    } else {
        out << "No exercises";
    }

    out << "\n";
    return out;
}
istream& operator>>(istream& in, Workout& obj) {
    char buffer[100];

    cout << "Enter workout type: ";
    in >> buffer;

    delete[] obj.type;
    obj.type = new char[strlen(buffer) + 1];
    strcpy(obj.type, buffer);

    cout << "Enter duration in minutes: ";
    in >> obj.durationMinutes;

    cout << "Enter estimated calories: ";
    in >> obj.estimatedCalories;

    cout << "Is it intense? (0/1): ";
    in >> obj.intense;

    cout << "Enter number of exercises: ";
    in >> obj.noExercises;

    delete[] obj.repetitions;

    if (obj.noExercises > 0) {
        obj.repetitions = new int[obj.noExercises];
        for (int i = 0; i < obj.noExercises; i++) {
            cout << "Repetitions for exercise " << i + 1 << ": ";
            in >> obj.repetitions[i];
        }
    } else {
        obj.repetitions = nullptr;
    }

    return in;
}
//Workout class (end)

//MAIN
int main(){

    Trainer m,n;
    cin >> m>>n;
    cout << m<< n;

    return 0;

}