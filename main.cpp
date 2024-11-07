#include "iostream"
#include "vector"
#include "cmath"
#include "cassert"



float best_val = 2147483647;
std::vector<std::vector<double>> best_vec;

void print_vec(std::vector<double> b){
	for(int i = 0; i < b.size(); i++){
		std::cout << b[i];
	}
	std::cout << " ";
}

double sum(std::vector<double> &b){
	double output = 0; 
	for(int i = 0; i < b.size(); i++){
		output += b[i];
	}
	return output;
}

double real_test(std::vector<std::vector<double>> &scomb){
	std::vector<double> means = {0.0, 0.0, 0.0, 0.0, 0.0};
	std::vector<double> sums  = {0.0, 0.0, 0.0, 0.0, 0.0};
	for(int i = 0; i < scomb.size(); i++){
		if(scomb[i].size() > 0){
			means[i] = (double)sum(scomb[i]) / scomb[i].size();
		}
		else{
			means[i] = 0;
		}
	}
	//std::cout << "m:";
	//for(int i = 0; i < means.size();i++){
	//	std::cout << means[i] << " ";
	//}

	for(int i = 0; i < scomb.size(); i++){
		double summ = 0.0; 
		if(scomb[i].size() > 0){
			for(int ii = 0; ii < scomb[i].size(); ii++){
				summ += std::abs(scomb[i][ii] - means[i]);
			}	
		}
		sums[i] = summ;
	}
	double big_sum = 0.0;
	for(int i = 0; i < sums.size(); i++){
		big_sum += sums[i];
	}
	return big_sum;

}

void test(std::string combination, std::vector<double> &vec){
	bool logging = false;
	std::vector<double> s1 = {};
	std::vector<double> s2 = {};
	std::vector<double> s3 = {};
	std::vector<double> s4 = {};
	std::vector<double> s5 = {};
	for(int ii = 0; ii<vec.size(); ii++){
		if (combination[ii] == '0'){s1.push_back(vec[ii]);}
		if (combination[ii] == '1'){s2.push_back(vec[ii]);}
		if (combination[ii] == '2'){s3.push_back(vec[ii]);}
		if (combination[ii] == '3'){s4.push_back(vec[ii]);}
		if (combination[ii] == '4'){s5.push_back(vec[ii]);}
	}
	

	std::vector<std::vector<double>> vec_of_vec;
	
	vec_of_vec.push_back(s1);
	vec_of_vec.push_back(s2);
	vec_of_vec.push_back(s3);
	vec_of_vec.push_back(s4);
	vec_of_vec.push_back(s5);
	if(s1.size() == 0 or s2.size() == 0 or s3.size() == 0 or s4.size() == 0 or s5.size() == 0){
		return;
	}	
	double value = real_test(vec_of_vec);

	//std::cout << " " << value;
	//std::cout << "\n";
	
	if (value < best_val){
		best_val = value;
		best_vec = vec_of_vec;

		if (logging){
		std::cout << "new_best " << value << "  "; 
		print_vec(s1);
		print_vec(s2);
		print_vec(s3);
		print_vec(s4);
		print_vec(s5);
		std::cout << "\n";
		}

	}
	//std::cout << value;
	//std::cout << "\n";
}

std::vector<std::vector<double>> method(std::vector<double> inp){//, std::vector<std::string> &output){
	best_val = 2147483647;
	best_vec = {};
	
	for(long i = 0; i < std::pow(5, (int)inp.size()); i++){
		std::string s;
		long x = i;
		for(int ii = 0; ii < inp.size(); ii++){
			s = std::to_string(x % 5) + s;
			x = x / 5;
		}
		//output.push_back(s);
		
		//std::cout << s << "\n";
		test(s, inp);
	}
	return best_vec;
}


int main(){
	std::vector<double> arr;
	std::vector<std::vector<double>> test_vec;
	//arr = {1,1,1,2,3,4,5,6,6,6};
	//method(arr);	
	//for(int i = 0; i < best_vec.size();i++){
	//	print_vec(best_vec[i]);}
	//std::cout << " best score: " << best_val << "\n";

	arr = {1,2,3,4,5};
	test_vec = {{1}, {2}, {3}, {4}, {5}};
	assert(test_vec == method(arr));

	arr = {1,2,3,4,5,6};
	test_vec = {{1,2}, {3}, {4}, {5}, {6}};
	assert(test_vec == method(arr));
	
	arr = {};
	test_vec = {};
	assert(test_vec == method(arr));

	arr = {1,1,1,2,3,4,5,6,6,6};
	test_vec = {{1,1,1},{2,3},{4},{5},{6,6,6}};
	return 0;
}
