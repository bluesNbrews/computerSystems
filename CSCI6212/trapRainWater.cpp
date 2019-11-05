/* Author: Steven Williams
** Given an elevation map (with non-negative integers), compute how much water the terrain map will trap
** The map is shown below (x marks the elvation and - marks the trapped water)
** |
** |       x
** |   x---xx-x
** | x-xx-xxxxxx
** --------------
*/

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
    
    //Find the maximum height of a column from the left side of the elevation map
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) { 
        left_max[i] = max(height[i], left_max[i - 1]);
        cout << "Left max for " << i << " " << left_max[i] << endl;
    }
    
    //Find the maximum height of a column from the right side of the elevation map
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
        cout << "Right max for " << i << "  " << right_max[i] << endl;
    }
    
    //Iterate through the elevation map and calculate the trapped water
    //The calculation is the minimum of both max heights (left and right) minus the height of the current column
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
        cout << "Left max is " << left_max[i] << " and right max is " << right_max[i] << " and height is " << height[i] << endl;
    }
    return ans;
}

int main(){
	
	vector<int> height;

	//Create the elevation map using a vector (dynamically sized array)
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

	//Find and print the trapped water
	int answer = trap(height);	
	cout << answer << endl;

	return 0;
}