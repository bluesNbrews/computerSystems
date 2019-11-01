#include<iostream>
#include<vector>

using namespace std;

int trap(vector<int> &height)
{
	if(height.empty() == true)
		return 0;
    
    int ans = 0;
    int size = height.size();

    vector<int> left_max(size), right_max(size);
    
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) { 
        left_max[i] = max(height[i], left_max[i - 1]);
        cout << "Left max for " << i << " " << left_max[i] << endl;
    }
    
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
        cout << "Right max for " << i << "  " << right_max[i] << endl;
    }
    
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
        cout << "Left max is " << left_max[i] << " and right max is " << right_max[i] << " and height is " << height[i] << endl;
    }
    return ans;
}

int main(){
	
	vector<int> height;

	height.push_back(0);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(1);

	int answer = trap(height);

	cout << answer << endl;

	return 0;
}