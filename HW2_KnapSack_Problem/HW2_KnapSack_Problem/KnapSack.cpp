#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
unsigned long subset_num = 0;	//How many subset

//Vector, current sum, pick num(big_num), current index
unsigned long cal(vector<int> v, int sum, unsigned long* arr) {
	vector<int>::iterator v_it;
	int temp = 0;

	arr[0] = 1;
	for (int i = 0; i < (int)v.size(); i++) {
		int add_num = v.at(i);
		temp += add_num;
		for (int j = temp; j >= 0; j--) {
			arr[j + add_num] += arr[j];
		}
	}
	return arr[sum / 2];
}

//Vector, current sum, pick num(big_num), current index
unsigned long cal(vector<int> v, int sum, unsigned long* arr) {
	vector<int>::iterator v_it;
	int temp = 0;

	arr[0] = 1;
	for (int i = 0; i < (int)v.size(); i++) {
		int add_num = v.at(i);
		temp += add_num;
		for (int j = temp; j >= 0; j--) {
			arr[j + add_num] += arr[j];
		}
	}
	return arr[sum / 2];
}

int main() {
	vector<int> v;	//vector
	vector<int> v2;	//vector2
	int number;		//How many count
	int att;		//set of attribute
	int sum = 0;
	int index = 0;
	unsigned long* arr;


	while (1) {
		cout << "How many count number : ";
		cin >> number;
		if (number == 0) return 0;
		for (int i = 0; i < number; i++) {
			cin >> att;
			v.push_back(att);
			sum += att;
		}
		arr = (unsigned long*)calloc(500 * 1100, sizeof(unsigned long));

		//vector sort
		sort(v.begin(), v.end());

		subset_num = (cal(v, sum, arr))/2;

		cout << "subset Count : " << subset_num << endl;
		subset_num = 0;
		//cal2(v, sum, arr);
		cout << "{";

		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
			if (i != v.size() - 1) cout << ", ";
		}
		cout << "} / ";

		cout << "{";

		for (int i = 0; i < v2.size(); i++) {
			cout << v2[i];
			if (i != v2.size() - 1) cout << ", ";
		}
		cout << "}" << endl;
		v.clear();
		v2.clear();
		sum = 0;
		subset_num = 0;
		delete[] arr;
	}
	return 0;
}