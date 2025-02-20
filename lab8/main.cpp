#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct node{
	std::string name;
	std::vector<float> friends;
	
	node(){};
	node(std::string in, std::vector<float>in2){
		this -> name = in;
		this -> friends = in2;

	};

};

node* line_processor(std::string str){
	node *output = new node();
	std::stringstream ss(str);
	std::string part;
	std::string part2;
	std::string part3;
	std::getline(ss,part,':');	
	std::cout << part << "\n"; // Node coordinates
	output -> name = part;
	std::vector<float> *a = new std::vector<float>;
	while (true){
		std::getline(ss,part2,';');
		if (part2 == ""){break;}
		std::stringstream ss2(part2);

		while (true){
			std::getline(ss2, part3, ',');
			if (part3 == ""){break;}
			//std::cout << part3 << " "; //next node x,y , distance
			(*a).push_back(std::stof(part3));
			part3 = "";
		}
		//std::cout << "\n";
		part2 = "";
	}
	output -> friends = *a;
	//std::getline(ss,part3);
	

	return output;
}

int main(){
	std::string str;
	std::ifstream st("simple.txt");
	std::vector<node*> nodes;
	while (true){
		std::getline(st,str);
		if (str == ""){break;}
		nodes.push_back(line_processor(str));
		str = "";
	}
	std::cout << "\n";
	for (auto a: nodes){
		std::cout << "\n";
		std::cout << (*a).name;
		for (float f : (*a).friends){
			std::cout << f << " ";
		}
	}
	return 0;
}
