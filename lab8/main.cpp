#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
//314045

bool debug_printing = false;
int counter = 0;

std::unordered_map<int, std::string> i_to_str;
std::unordered_map<std::string, int> str_to_i;

struct node {
	int id;
	std::string name;
	std::vector<int> friends;
	std::vector<double> distance;
	node() {};
	node(std::string in, std::vector<int>in2, std::vector<double>in3) {
		this->name = in;
		this->friends = in2;
		this->distance = in3;
	};

};
std::vector<node*> nodes;
void bfs(node* start, int target_id) {
	std::queue<node*> q;
	std::unordered_map<int, double> distance;

	q.push(start);
	distance[start->id] = 0.0;

	while (!q.empty()) {
		auto current_pair = q.front();
		node* current = current_pair;
		double current_dist = distance[current->id];
		q.pop();

		if (current->id == target_id) {
			std::cout << "Target node found: " << current->name << " with distance: " << current_dist << std::endl;
			return;
		}

		for (size_t i = 0; i < current->friends.size(); ++i) {
			int friend_id = current->friends[i];

			if (distance.find(friend_id) == distance.end()) {
				distance[friend_id] = current_dist + current->distance[i];
				q.push(nodes[friend_id]);
			}
		}
	}

	std::cout << "Target node not found." << std::endl;
}



double dfs(node* start, int target_id) {
	std::stack<std::pair<node*, double>> s;
	std::unordered_map<int, double> distance;

	s.push({ start, 0.0 });
	distance[start->id] = 0.0;

	while (!s.empty()) {
		auto current_pair = s.top();
		node* current = current_pair.first;
		double current_dist = current_pair.second;
		s.pop();

		if (current->id == target_id) {
			std::cout << "Target node found: " << current->name << " with distance: " << current_dist << "\n";
			return current_dist;
		}

		for (size_t i = 0; i < current->friends.size(); ++i) {
			int friend_id = current->friends[i];
			double edge_weight = current->distance[i];

			if (distance.find(friend_id) == distance.end()) {
				distance[friend_id] = current_dist + edge_weight;
				s.push({ nodes[friend_id], distance[friend_id] });
			}
		}
	}
}


void dijkstra(node* start, int end_id) {
	std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
	std::unordered_map<int, double> dist; // Stores the shortest distance to each node
	std::unordered_map<int, int> prev;

	for (auto& n : nodes) {
		dist[n->id] = std::numeric_limits<double>::infinity();
	}

	dist[start->id] = 0.0;
	pq.push({ 0.0, start->id });

	while (!pq.empty()) {
		int current_id = pq.top().second;
		double current_dist = pq.top().first;
		pq.pop();

		if (current_id == end_id) {
			std::cout << "Shortest distance from " << start->name << " to " << nodes[end_id]->name << " is " << current_dist << std::endl;

			std::vector<int> path;
			for (int at = end_id; at != start->id; at = prev[at]) {
				path.push_back(at);
			}
			path.push_back(start->id);

			std::cout << "Path: ";
			for (auto it = path.rbegin(); it != path.rend(); ++it) {
				std::cout << nodes[*it]->name;
				if (it + 1 != path.rend()) {
					std::cout << " - ";
				}
			}
			std::cout << std::endl;
			return;
		}

		if (current_dist > dist[current_id]) {
			continue;
		}

		node* current = nodes[current_id];


		for (size_t i = 0; i < current->friends.size(); ++i) {
			int friend_id = current->friends[i];
			double edge_weight = current->distance[i];

			if (dist[current_id] + edge_weight < dist[friend_id]) {
				dist[friend_id] = dist[current_id] + edge_weight;
				prev[friend_id] = current_id;
				pq.push({ dist[friend_id], friend_id });
			}
		}
	}

	std::cout << "No path exists from " << start->name << " to " << nodes[end_id]->name << std::endl;
}
node* line_processor(std::string str) {
	node* output = new node();
	std::stringstream ss(str);
	std::string part;
	std::string part2;
	std::string part3;
	std::string part4;
	std::getline(ss, part, ':');
	if (debug_printing)
	{
		std::cout << part << "\n";
	} // Node coordinates
	//std::cout << part << "\n";
	output->name = part;
	if (str_to_i.count(part) == 0) {
		str_to_i[part] = counter;
		counter++;
	}
	output->id = str_to_i[part];

	std::vector<int>* frid = new std::vector<int>;
	std::vector<double>* dist = new std::vector<double>;

	if (str_to_i.count(part) == 1) {
		//if (debug_printing)	
		//{std::cout << str_to_i[part] << " " << "founded" << "\n";} // Node coordinates
		//std::cout << part << "\n";
		node* nd = nodes[str_to_i[part]];
		std::vector<double> dis_get = nd->distance;
		std::vector<int> friends_get = nd->friends;
		(*frid).insert((*frid).end(), friends_get.begin(), friends_get.end());
		(*dist).insert((*dist).end(), dis_get.begin(), dis_get.end());
	}

	while (true) {
		std::getline(ss, part2, ';');
		if (part2 == "") { break; }
		std::stringstream ss2(part2);

		for (int k = 0; k < 3; k++) {
			std::getline(ss2, part3, ',');
			if (part3 == "") { break; }
			//std::cout << part3 << " "; //next node x,y , distance
			if (k == 0) {
				part4 = part3;
			}
			if (k == 1) {
				part4 += "," + part3;
				if (str_to_i.count(part4) == 0) {
					str_to_i[part4] = counter;
					if (debug_printing) {
						std::cout << "f" << part4 << "f\n";
					}
					counter++;
				}
				(*frid).push_back(str_to_i[part4]);

			}
			if (k == 2) {
				(nodes[str_to_i[part4]]->friends).push_back(str_to_i[part]);
				(nodes[str_to_i[part4]]->distance).push_back(std::stod(part3));
				(*dist).push_back(std::stod(part3));
			}

			part3 = "";
		}
		//std::cout << "\n";
		part2 = "";
	}
	output->friends = *frid;
	output->distance = *dist;
	//std::getline(ss,part3);


	return output;
}

int main() {

	int len_nodes = 314045 * 2;
	nodes.resize(len_nodes);
	for (int i = 0; i < len_nodes; i++) {
		nodes[i] = new node;
	}
	std::string str;
	std::ifstream st("C:/tmp/alg/lab8/spb_graph.txt");

	while (true) {
		std::getline(st, str);
		if (str == "") { break; }
		node* nd = line_processor(str);
		nodes[str_to_i[(*nd).name]] = nd;
		//nodes.push_back();
		str = "";
	}
	//std::cout << "\n";
	if (debug_printing or false) {
		for (auto a : nodes) {
			std::cout << "\n";
			std::cout << (*a).id << " " << (*a).name << " ;";
			for (int i = 0; i < (*a).friends.size(); i++) {
				std::cout << (*a).friends[i] << " ";
			}
		}
	}
	int start = str_to_i["30.4145466,59.9470296"];
	int target = str_to_i["30.4144348,59.9476425"];
	start = 7;
	target = 2;
	std::cout << start << " " << target << "\n";
	std::cout << "out" << "\n";
	bfs(nodes[start], target);
	std::cout << "bfs out\n";
	dfs(nodes[start], target);
	std::cout << "dfs out\n";
	dijkstra(nodes[start], target);
	std::cout << "dijkstra out\n";
	//std::cout << str_to_i[(*nodes[0]).name];
	//std::cout << str_to_i["30.4140936,59.9469059"];
	return 0;
}
