//Animal shelter
//https://www.learncpp.com/cpp-tutorial/112-basic-inheritance-in-c/
#include<iostream>
#include<list>
using namespace std;

struct Animal{
  int name;
  char type;
  int timestamp = 0;
};

class animalShelter{
  private:
    list<Animal> dog_shelter; //http://www.cplusplus.com/forum/beginner/3396/
    list<Animal> cat_shelter; 
    int time = 0;
  public:
    void enqueue(Animal x);
    Animal dequeueAny();
    Animal dequeueCat();
    Animal dequeueDog();
};

void animalShelter::enqueue(Animal x){
   time++;
   if(x.type == 'c'){
     cat_shelter.push_back(x);
     x.timestamp = time;
   }
   else{
     dog_shelter.push_back(x);
     x.timestamp = time;
   }
}

Animal animalShelter::dequeueAny(){
   Animal oldest_cat = cat_shelter.front();
   Animal oldest_dog = dog_shelter.front();
   Animal adopt;
   if(oldest_cat.timestamp > oldest_dog.timestamp){
     adopt = cat_shelter.front();
     cat_shelter.pop_front();
   }
   else{
     adopt = dog_shelter.front();
     dog_shelter.pop_front();
   }
   return adopt;
}

Animal animalShelter::dequeueCat(){
   Animal adopt;
   adopt = cat_shelter.front();
   cat_shelter.pop_front();
   return adopt;
}

Animal animalShelter::dequeueDog(){
   Animal adopt;
   adopt = dog_shelter.front();
   dog_shelter.pop_front();
   return adopt;
}

int main(){
  animalShelter s;
  Animal x1,x2,x3,x4,x5;
  x1.name = 1;
  x1.type = 'd';
  x2.name = 2;
  x2.type = 'c';
  x3.name = 3;
  x3.type = 'c';
  x4.name = 4;
  x4.type = 'd';
  x5.name = 5;
  x5.type = 'd';
  s.enqueue(x1);
  s.enqueue(x2);
  s.enqueue(x3);
  s.enqueue(x4);
  s.enqueue(x5);
  Animal adopt;
  adopt = s.dequeueAny();
  adopt = s.dequeueCat();
  //adopt = s.dequeueDog();
  if(adopt.type == 'd'){cout << "Animal " << adopt.name << " is a dog." << endl;}
  else{cout << "Animal " << adopt.name << " is a cat." << endl;}
}
