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
	//if not exist subset, setting subset_num =0;
	if (sum % 2 == 1) {
		return 0;
	}
	//default setting
	arr[0] = 1;

	//setting value at arr
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
void cal2(vector<int> &v, vector<int> &v2, int sum, int big_num, int index) {
	vector<int>::iterator v_it;
	v_it = v.begin() + index;
	int temp = big_num;
	sum -= big_num;
	v.erase(v_it);
	v2.push_back(temp);
	//if sum == 0 subset_num -> 1 setting
	if (sum == 0) {
		subset_num += 1;
		return;
	}

	for (index; index < (int)v.size(); index++) {
		temp = v.at(index);
		//if find already subset, end cycle
		if (subset_num == 1) {
			return;
		}
		else if (sum >= temp) {
			cal2(v, v2, sum, temp, index);
			//if target num not include subset
			if (subset_num != 1) {
				v.insert(v_it, big_num);
				v.pop_back();
			}
		}
	}
	return ;
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

		//setting input number
		if (number == 0) return 0;
		for (int i = 0; i < number; i++) {
			cin >> att;
			v.push_back(att);
			sum += att;
		}

		//setting 'zero' all array
		arr = (unsigned long*)calloc(500 * 1100, sizeof(unsigned long));

		//vector sort down
		sort(v.begin(), v.end());

		//calculate subset's number
		subset_num = (cal(v, sum, arr))/2;
		cout << "subset Count : " << subset_num << endl;

		//settiing default value
		subset_num = 0;

		//sort down
		sort(v.begin(), v.end(), greater<int>());
		sum /= 2;
		cal2(v, v2, sum, v.at(0), index);

		//printf one subset start
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
		//printf one subset end

		//set default value
		v.clear();
		v2.clear();
		sum = 0;
		index = 0;
		subset_num = 0;
		delete[] arr;
	}
	return 0;
}