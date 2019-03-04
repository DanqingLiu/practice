//Animal shelter
#include<iostream>
#include<list>
using namespace std;

struct Animal{
  int name;
  char type;
};

class animalShelter{
  private:
    list<Animal> shelter; //http://www.cplusplus.com/forum/beginner/3396/
  public:
    void enqueue(Animal x);
    Animal dequeueAny();
    Animal dequeueCat();
    Animal dequeueDog();
};

void animalShelter::enqueue(Animal x){
   shelter.push_back(x);
}

Animal animalShelter::dequeueAny(){
   Animal adopt = shelter.front();
   shelter.pop_front();
   return adopt;
}

Animal animalShelter::dequeueCat(){
   Animal oldest;
   oldest = shelter.front();
   Animal adopt;
   list<Animal> temp;
   if(oldest.type == 'c'){
     adopt = oldest;
     shelter.pop_front();     
   }
   else{
     while(oldest.type != 'c'){
       temp.push_back(shelter.front());
       shelter.pop_front();
       oldest = shelter.front();
     }
     adopt = shelter.front();
     shelter.pop_front();
     temp.splice(temp.end(), shelter);//https://stackoverflow.com/questions/1449703/how-to-append-a-listt-object-to-another
     shelter = temp;
   }
   return adopt;
}

Animal animalShelter::dequeueDog(){
   Animal oldest;
   oldest = shelter.front();
   Animal adopt;
   list<Animal> temp;
   if(oldest.type == 'd'){
     adopt = oldest;
     shelter.pop_front();     
   }
   else{
     while(oldest.type != 'd'){
       temp.push_back(oldest);
       shelter.pop_front();
       oldest = shelter.front();
     }
     adopt = shelter.front();
     shelter.pop_front();
     temp.splice(temp.end(), shelter);//https://stackoverflow.com/questions/1449703/how-to-append-a-listt-object-to-another
     shelter = temp;
   }
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
  //adopt = s.dequeueAny();
  //adopt = s.dequeueCat();
  adopt = s.dequeueDog();
  if(adopt.type == 'd'){cout << "Animal " << adopt.name << " is a dog." << endl;}
  else{cout << "Animal " << adopt.name << " is a cat." << endl;}
}
