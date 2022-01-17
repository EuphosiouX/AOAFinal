#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#define MIN 50000
#define MED 60000
#define MAX 70000
using namespace std;
using namespace std::chrono;

/*
This algorithm finds the maximum height from left to right, and right to left within each loop 
and store the result in a vector. Then we find the water trapped by finding the units that has a contact point with 
each other. 
*/

int rainwater(vector<int> water, int size){
	// Declaring variables
	int ans, leftMax, rightMax;
	ans = leftMax = rightMax = 0;
	vector <int> lMax, rMax;
	
	// Store all the maximum units value when iterating from left to right in a vector
	for (int i = 0; i < size; i++) {
		leftMax = max(leftMax, water[i]);
		lMax.push_back(leftMax); // Add to the vector
	}
	
	// Store all the maximum units value when iterating from right to left in a vector
	for (int i = size - 1; i >= 0; i--) {
		rightMax = max(rightMax, water[i]);
		rMax.push_back(rightMax);
	}
	
	// Iterate from the beginning and find the contact points between left and right max, and subtract the container
	for(auto i = 0; i < size; i++) {
		// Make sure the direction of rMax is from left to right (that is why it is size-i-1)
		ans += min(lMax[i], rMax[size-i-1]) - water[i];
	}
	return ans;
}

// Function to insert ascending value into the vector
vector<int> pushAsc(vector<int> vector, int size) {
	for(auto i = 0; i < size; i++){
		vector.push_back(i+1);	
	}
	
	return vector;
}

// Function to insert descending value into the vector
vector<int> pushDesc(vector<int> vector, int size) {
	for(auto i = size-1; i >= 0; i--){
		vector.push_back(i+1);
	}
	return vector;
}

// Function to insert ascending descending value into the vector
vector<int> pushAscDesc(vector<int> vector, int size){
	for(auto i = 1; i < size/2; i++){
		vector.push_back(i);
	}
	vector.push_back(size/2);
	for(auto i = size/2-1; i >= 1; i--){
		vector.push_back(i);
	}
	return vector;
}

// Function to insert descending ascending value into the vector
vector<int> pushDescAsc(vector<int> vector, int size){
	for(auto i = size/2-1; i >= 0; i--){
		vector.push_back(i+1);
	}
	vector.push_back(0);
	for(auto i = 0; i < size/2; i++){
		vector.push_back(i+1);
	}
	return vector;
}

// Function to insert random value into the vector
vector<int> pushRand(vector<int> vector, int size) {
	for(auto i = 0; i < size; i++){
		vector.push_back(rand() % size + 1);
	}
	return vector;
}

int main (void) {
	// Declare vectors
	vector<int> ascMin;
	vector<int> ascMed;
	vector<int> ascMax;
	
	vector<int> descMin;
	vector<int> descMed;
	vector<int> descMax;
	
	vector<int> randMin;
	vector<int> randMed;
	vector<int> randMax;

	vector<int> daMin;
	vector<int> daMed;
	vector<int> daMax;
	
	vector<int> adMin;
	vector<int> adMed;
	vector<int> adMax;
	
	// Insert value
	ascMin = pushAsc(ascMin, MIN);
	ascMed = pushAsc(ascMed, MED);
	ascMax = pushAsc(ascMax, MAX);
	
	descMin = pushDesc(descMin, MIN);
	descMed = pushDesc(descMed, MED);
	descMax = pushDesc(descMax, MAX);
	
	randMin = pushRand(randMin, MIN);
	randMed = pushRand(randMed, MED);
	randMax = pushRand(randMax, MAX);
	
	daMin = pushDescAsc(daMin, MIN);
	daMed = pushDescAsc(daMed, MED);
	daMax = pushDescAsc(daMax, MAX);
	
	adMin = pushAscDesc(adMin, MIN);
	adMed = pushAscDesc(adMed, MED);
	adMax = pushAscDesc(adMax, MAX);
	
	// Print result
	cout << "ALGO 1" << endl;
	cout << "Small is " << MIN << " DATA" << endl;
	cout << "Medium is " << MED << " DATA" << endl;
	cout << "Big is " << MAX << " DATA" << endl << endl;
	
	auto start = high_resolution_clock::now();
	int ans = rainwater(ascMin, ascMin.size());
	auto end = high_resolution_clock::now();
	cout << "Time taken for small ascending: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;	
	
	start = high_resolution_clock::now();
	ans = rainwater(ascMed, ascMed.size());
	end = high_resolution_clock::now();
	cout << "Time taken for medium ascending: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(ascMax, ascMax.size());
	end = high_resolution_clock::now();
	cout << "Time taken for big ascending: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	cout << "--------------------------------------------------------------" << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(descMin, descMin.size());
	end = high_resolution_clock::now();
	cout << "Time taken for small descending: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(descMed, descMed.size());
	end = high_resolution_clock::now();
	cout << "Time taken for medium descending: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(descMax, descMax.size());
	end = high_resolution_clock::now();
	cout << "Time taken for big descending: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	cout << "--------------------------------------------------------------" << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(randMin, randMin.size());
	end = high_resolution_clock::now();
	cout << "Time taken for small random: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(randMed, randMed.size());
	end = high_resolution_clock::now();
	cout << "Time taken for medium random: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(randMax, randMax.size());
	end = high_resolution_clock::now();
	cout << "Time taken for big random: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	cout << "--------------------------------------------------------------" << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(daMin, daMin.size());
	end = high_resolution_clock::now();
	cout << "Time taken for small desc asc: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(daMed, daMed.size());
	end = high_resolution_clock::now();
	cout << "Time taken for medium desc asc: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(daMax, daMax.size());
	end = high_resolution_clock::now();
	cout << "Time taken for big desc asc: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	cout << "--------------------------------------------------------------" << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(adMin, adMin.size());
	end = high_resolution_clock::now();
	cout << "Time taken for small asc desc: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(adMed, adMed.size());
	end = high_resolution_clock::now();
	cout << "Time taken for medium asc desc: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
	
	start = high_resolution_clock::now();
	ans = rainwater(adMax, adMax.size());
	end = high_resolution_clock::now();
	cout << "Time taken for big asc desc: " << duration_cast<nanoseconds>(end-start).count() << " nanoseconds / " << duration_cast<milliseconds>(end-start).count() << " milliseconds" << endl;
	cout << "The max number of water that can be trapped is " << ans << " units" << endl << endl;
}
