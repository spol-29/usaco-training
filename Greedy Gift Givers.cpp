/*
ID: polineni1
LANG: C++
TASK: gift1
*/

#include<bits/stdc++.h>
using namespace std;

int np;
map<string,int> names;
int money[20];

int main(){
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");

	fin >> np;
	vector <string> namesList;
	for(int i = 0; i < np; i++){
		string name; fin >> name;
		names[name] = i;
		money[i] = 0;
		namesList.push_back(name);
	
	} 
	for(int i = 0; i < np; i++){
		string sender; fin >> sender;
		int amount; fin >> amount;
		int num_people; fin >> num_people;
		vector <string> people;
			for(int i = 0; i < num_people; i++){
				string person; fin >> person;
				people.push_back(person);
			}
			if(num_people == 0){
				continue;
			}
			int moneyGot = amount / num_people; 
			money[names[sender]]  -= moneyGot *  num_people;
			for(int j = 0; j < num_people; j++){
				money [names[people[j]]] += moneyGot;
			}
		}
 	for(int p = 0; p <np; p++){
		 fout << namesList[p] << " " << money[p]<< endl;
 	}
}
/*Explanation:
First we take in the input of how many people are there
Let's say there are 5 people
we loop through the number of people (np)
and we take in the [5] names 
We then assign the "name" variable which contains the (5) names 
to the hashmap which assigns the name / passes it to i which is the loop iterator
and then gets assined to the numbers 1-5
we initialize all the variabes in the money array to 0
the money array contains the amount of money that each person has
then we push back the list of names that we collected from "name" and then we assign this to namesList

Second part of the input:
the amount and the num_people
num_people is the amount of people giving to
then based on the number of people giving to we collect these names and put it in a vector
if num_people is equivalent to 0 it will skip the next function
if we didn't do this then we would get an error message because dividing anything by 0 is undefined
then we map money to the sender with the names hashmap this gave us the money and storage/mapping for 
the senders now the mone the people are giving is being deducted fr0om the senders balance and being mapped 
to the persons name

So, now we have to actually GIVE the people the money we have only deducted the money from the sender

that is, money [names[people[j]]] += moneyGot;
so in this we are mapping people the names of the people
("the input of the num_people")

:-not the np names-:
so this maps the moneyGot to people of names j number of times
so money got is being mapped to people j number of times.

the rest is the output
*/