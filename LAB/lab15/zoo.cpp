#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <string.h>
using namespace std;

char nameofzoo[100];

class Animal {
	public :
		Animal(){
			memset(name,0,24);
			weight = 0;
		}
		virtual void speak(){;}
		virtual void info(){;}
	protected :
		char name[24];
		int weight;
};

class Dog : public Animal{
	public :
		Dog(string str,int w){
			strcpy(name,str.c_str());	
			weight = w ;
		}
		virtual void speak(){
			cout << "Wow ~ Wow ~ Wow ~" << endl ;
		}
		virtual void info(){
			cout << "|---------------------|" << endl ;
			cout << "| Animal info         |" << endl;
			cout << "|---------------------|" << endl;
			cout << "  Weight :" << this->weight << endl ;
			cout << "  Name : " << this->name << endl ;
			cout << "|---------------------|" << endl;
		}
};

class Cat : public Animal{
	public :
		Cat(string str,int w){
			strcpy(name,str.c_str());
			weight = w ;
		}
		virtual void speak(){
			cout << "Meow ~ Meow ~ Meow ~" << endl ;			
		}
		virtual void info(){
			cout << "|---------------------|" << endl ;
			cout << "| Animal info         |" << endl;
			cout << "|---------------------|" << endl;
			cout << "  Weight :" << this->weight << endl ;
			cout << "  Name : " << this->name << endl ;
			cout << "|---------------------|" << endl;
		}

};

vector<Animal *> animallist ;

void menu(){
	cout << "*********************************" << endl ;
	cout << " 1. Add a dog                    " << endl ;
	cout << " 2. Add a cat                    " << endl ;
	cout << " 3. Listen a animal              " << endl ;
	cout << " 4. Show a animal info           " << endl ;
	cout << " 5. Remove a animal              " << endl ;
	cout << " 6. Exit                         " << endl ;
	cout << "*********************************" << endl ;
}


void adddog(){
	string name ;
	int weight ;
	cout << "Name : " ;
	cin >> name;
	cout << "Weight : " ;
	cin >> weight ;
	Dog *mydog = new Dog(name,weight);
	animallist.push_back(mydog);

}

void addcat(){
	string name ;
	int weight ;
	cout << "Name : " ;
	cin >> name;
	cout << "Weight : " ;
	cin >> weight ;
	Cat *mycat = new Cat(name,weight);
	animallist.push_back(mycat);

}

void remove(){
	unsigned int idx ;
	if(animallist.size() == 0){
		cout << "no any animal!" << endl ;
		return ;
	}
	cout << "index of animal : ";
	cin >> idx ;
	if(idx >= animallist.size()){
		cout << "out of bound !" << endl;
		return ;
	}
	delete animallist[idx];
	animallist.erase(animallist.begin()+idx);


}

void showinfo(){
	unsigned int idx ;
	if(animallist.size() == 0){
		cout << "no any animal!" << endl ;
		return ;
	}
	cout << "index of animal : ";
	cin >> idx ;
	if(idx >= animallist.size()){
		cout << "out of bound !" << endl;
		return ;
	}
	animallist[idx]->info();

}

void listen(){
	unsigned int idx ;
	if(animallist.size() == 0){
		cout << "no any animal!" << endl ;
		return ;
	}
	cout << "index of animal : ";
	cin >> idx ;
	if(idx >= animallist.size()){
		cout << "out of bound !" << endl;
		return ;
	}
	animallist[idx]->speak();

}
int main(void){
	unsigned int choice ;
	setvbuf(stdout,0,2,0);
	setvbuf(stdin,0,2,0);
	cout << "Name of Your zoo :" ;
	read(0,nameofzoo,100);
	while(1){
		menu();
		cout << "Your choice :";
		cin >> choice ;
		cout << endl ;
		switch(choice){
			case 1 :
				adddog();
				break ;
			case 2 :
				addcat();
				break ;
			case 3 :
				listen();
				break ;
			case 4 : 
				showinfo();
				break ;
			case 5 :
				remove();
				break ;
			case 6 :
				_exit(0);
			default :
				cout << "Invaild choice" << endl;
				break ;
		}
	}	
	return 0 ;
}

