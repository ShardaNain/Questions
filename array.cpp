//QUESTIONS ON ARRAY

//Find largest number in an array

#include <bits/stdc++.h>
using namespace std;


int LargestElement(int arr[], int n) {
 
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
int main() {
  int arr1[] = {2,6,8,5,9};
  int n = 5;
  int max = LargestElement(arr1, n);
  cout  << max << endl;
 
  int arr2[] =  {5,6,7,11,14};
  n = 5;
  max = LargestElement(arr2, n);
  cout << max<<endl;
  return 0;
}

// Finding Second Largest



int SecondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}

int main() {
    int arr[]={1,2,4,7,7,5};  
    int n=sizeof(arr)/sizeof(arr[0]);
    int sL=secondLargest(arr,n);
    cout<<sL<<endl;
    return 0;
}

//Finding the union 


vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; 
  vector < int > Union; 
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) 
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else 
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) 
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) 
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout  << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}

//Finding longest sequence 


int longestSequence(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    
    for (auto it : st) {
        
        if (st.find(it - 1) == st.end()) {
           
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSequence(a);
    cout <<  ans << "\n";
    return 0;
}

//Kadane's Algorithm 


long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; 
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << maxSum << endl;
    return 0;
}





