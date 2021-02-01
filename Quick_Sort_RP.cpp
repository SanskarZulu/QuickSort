//By Sanskar Sharma
//DAA Practical 2

#include<iostream>
#include<cstdlib>
#include <bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace std::chrono;

class MenuDrivenCode
{
	public:
		void For_given_input();
		void Large_arrays(long long int a[], long long int n);
		void Find_Median(long long int a[], long long int n);
		void Operation(long long int a[], long long int n);
	
};
 
// Swapping two values.
void swap(long long int *a, long long int *b)
{
	long long int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// Partitioning the array on the basis of values at high as pivot value.
long long int Partition(long long int a[], long long int low, long long int high)
{
	long long int pivot, index;
	index = low;
	pivot = high;
 
	// Getting index of pivot.
	for(long long int i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[pivot], &a[index]);
 
	return index;
}
 
// Random selection of pivot.
long long int RandomPivotPartition(long long int a[], long long int low, long long int high)
{
	long long int pvt, n;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
// Implementing QuickSort algorithm.
int QuickSort(long long int a[],long long int low,long long int high)
{
	long long int pindex;
	if(low < high)
	{
		// Partitioning array using randomized pivot.
		pindex = RandomPivotPartition(a, low, high);
		// Recursively implementing QuickSort.
		QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	return 0;
}

void MenuDrivenCode::For_given_input()
{
	long long int a[]= {5,3,1,9,8,2,4,7};
	long long int n=8;
	
	// Get starting timepoint 
    auto start = high_resolution_clock::now(); 
 
	QuickSort(a, 0, n-1);
	
	 // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\n\t\tTime taken by Quick sort: "
         << duration.count() << " microseconds" << endl;
         
    cout<<"\n\tSorted array: ";
	for (long long int i = 0; i < 8; i++)
	{
		cout<<" "<<a[i];
	}
	
	
}

void MenuDrivenCode::Large_arrays(long long int a[], long long int n)
{
	// Get starting timepoint 
    auto start = high_resolution_clock::now(); 
 
	QuickSort(a, 0, n-1);
	
	 // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\n\t\tTime taken by Quick sort: "
         << duration.count() << " microseconds" << endl;
 
	// Printing the sorted data.
	cout<<"\n\tFirst 100 elements of Sorted array: ";
	for (long long int i = 0; i < 100; i++)
	{
		cout<<" "<<a[i];
	}
	
	cout<<"\n\n\tLast 100 elements of Sorted array: ";
	for (long long int i = n-101; i < n; i++)
	{
		cout<<" "<<a[i];
	}
}


// Utility function to find median
void MedianUtil(long long int arr[],long long int l,long long int r,
				long long int k, long long int& a, long long int& b)
{

	// if l < r
	if (l <= r) {

		// Find the partition index
		long long int partitionIndex
			= RandomPivotPartition(arr, l, r);

		// If partion index = k, then
		// we found the median of odd
		// number element in arr[]
		if (partitionIndex == k) {
			b = arr[partitionIndex];
			if (a != -1)
				return;
		}

		// If index = k - 1, then we get
		// a & b as middle element of
		// arr[]
		else if (partitionIndex == k - 1) {
			a = arr[partitionIndex];
			if (b != -1)
				return;
		}

		// If partitionIndex >= k then
		// find the index in first half
		// of the arr[]
		if (partitionIndex >= k)
			return MedianUtil(arr, l,
							partitionIndex - 1,
							k, a, b);

		// If partitionIndex <= k then
		// find the index in second half
		// of the arr[]
		else
			return MedianUtil(arr,
							partitionIndex + 1,
							r, k, a, b);
	}

	return;
}

// Function to find Median
void findMedian(long long int arr[],long long int n)
{
	long long int ans, a = -1, b = -1;

	// If n is odd
	if (n % 2 == 1) {
		MedianUtil(arr, 0, n - 1,
				n / 2, a, b);
		ans = b;
	}

	// If n is even
	else {
		MedianUtil(arr, 0, n - 1,
				n / 2, a, b);
		ans = (a + b) / 2;
	}

	// Print the Median of arr[]
	cout << "\n\t\t\tMedian = " << ans;
}


void MenuDrivenCode::Find_Median(long long int a[], long long int n)
{
	// Get starting timepoint 
    auto start = high_resolution_clock::now();
	
	findMedian(a, n);
	
		 // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\n\t\tTime taken by Medians of Median Algo to find median: "
         << duration.count() << " microseconds" << endl;
	
	
}

void MenuDrivenCode::Operation(long long int a[], long long int n)
{
	cout<<"\n\tChoose one of the following: ";
	cout<<"\n\t\t1. Sort the given input using Quick sort algorithm with time (in ms).";
	cout<<"\n\t\t   Given input: 5 3 1 2 8 4 2 7";
	cout<<"\n\t\t2. Sort Large Array using Quick Sort Partition Algo.";
	cout<<"\n\t\t3. Find median of the array using Median of Median algorithm.";
	cout<<"\n\t\t4. Exit.";
	int choice;
	cout<<"\n\t\tEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			For_given_input();
			Operation(a,n);
			break;
		
		case 2:
			Large_arrays(a,n);
			Operation(a,n);
			break;
		
		case 3:
			Find_Median(a,n);
			Operation(a,n);
			break;
		
		case 4:
			//succesfully executed
			exit(0);
			break;
			
		default:
			//unsuccesful exit
			exit(0);
	}
}
 
int main()
{
	long long int n;
	cout<<"\n\tEnter the number of element in the array: ";
	cin>>n;
	
	/*
    //enter the array manually 
	long long int arr[n];
	for(long long int i = 0; i < n; i++)
	{
		cout<<"\n\t\tEnter element "<<i+1<<": ";
		cin>>arr[i];
	}*/
	
	//get a random large array
	long long int arr[n];
	for(long long int i=0;i<n;++i)
	{
		//cout<<"\n\t\tEnter "<<i<<" element: ";
		//cin>>arr[i];
		arr[i]=rand()%100000000;
	}
	
	MenuDrivenCode M;
	M.Operation(arr,n);     	
 
	return 0;
}

/*
Output:
                                                                                                                                                
        Enter the number of element in the array: 1000000                                                                                       
                                                                                                                                                
        Choose one of the following:                                                                                                            
                1. Sort the given input using Quick sort algorithm with time (in ms).                                                           
                   Given input: 5 3 1 2 8 4 2 7                                                                                                 
                2. Sort Large Array using Quick Sort Partition Algo.                                                                            
                3. Find median of the array using Median of Median algorithm.                                                                   
                4. Exit.                                                                                                                        
                Enter your choice: 1                                                                                                            
                                                                                                                                                
                Time taken by Quick sort: 2 microseconds                                                                                        
                                                                                                                                                
        Sorted array:  1 2 3 4 5 7 8 9      
		                                                                                                    
        Choose one of the following:                                                                                                            
                1. Sort the given input using Quick sort algorithm with time (in ms).                                                           
                   Given input: 5 3 1 2 8 4 2 7                                                                                                 
                2. Sort Large Array using Quick Sort Partition Algo.                                                                            
                3. Find median of the array using Median of Median algorithm.                                                                   
                4. Exit.                                                                                                                        
                Enter your choice: 2                                                                                                            
                                                                                                                                                
                Time taken by Quick sort: 1470073 microseconds                                                                                  
                                                                                                                                                
        First 100 elements of Sorted array:  58 150 197 250 478 501 569 580 580 703 746 793 803 844 1065 1210 1848 1933 1989 2167 2274 2304 2348
 2426 2481 2557 2567 2579 2603 2658 2675 2883 3062 3126 3202 3286 3310 3611 3624 3722 3739 3774 3835 4112 4182 4310 4336 4686 4799 5214 5272 528
4 5344 5381 5387 5478 5504 5638 5646 5687 5704 5712 5731 5848 5884 5952 5963 6087 6115 6126 6153 6233 6382 6633 6700 6881 7124 7216 7437 7628 78
53 7959 8002 8079 8186 8204 8274 8369 8404 8415 8652 8707 8785 9079 9301 9382 9580 9704 9868 9913                                               
                                                                                                                                
        Last 100 elements of Sorted array:  99988242 99988325 99988442 99988502 99988511 99988533 99988544 99988665 99988739 99988758 99988848 9
9989042 99989220 99989252 99989431 99989632 99989719 99989737 99989744 99989959 99990244 99990282 99990407 99990639 99990740 99990753 99990811 9
9990911 99990931 99990931 99991137 99991361 99991452 99991634 99991657 99992049 99992220 99992399 99992479 99992531 99992612 99992784 99992825 9
9992973 99993754 99993894 99994375 99994413 99994468 99994560 99994675 99994733 99994738 99994966 99995109 99995264 99995277 99995582 99995851 9
9995862 99995913 99996014 99996097 99996168 99996185 99996459 99996544 99996594 99996595 99996680 99996720 99996804 99996850 99996924 99997064 9
9997258 99997280 99997311 99997360 99997574 99997597 99997635 99997639 99997665 99997728 99997933 99998367 99998454 99998475 99998563 99998717 9
9998724 99998986 99999166 99999358 99999612 99999792 99999926 99999939 99999977 99999981            
                                            
        Choose one of the following:                                                                                                            
                1. Sort the given input using Quick sort algorithm with time (in ms).                                                           
                   Given input: 5 3 1 2 8 4 2 7                                                                                                 
                2. Sort Large Array using Quick Sort Partition Algo.                                                                            
                3. Find median of the array using Median of Median algorithm.                                                                   
                4. Exit.                                                                                                                        
                Enter your choice: 3                                                                                                            
                                                                                                                                                
                        Median = 48905231                                                                                                       
                Time taken by Medians of Median Algo to find median: 25860 microseconds                                                         
                                                                                                                                                
        Choose one of the following:                                                                                                            
                1. Sort the given input using Quick sort algorithm with time (in ms).                                                           
                   Given input: 5 3 1 2 8 4 2 7                                                                                                 
                2. Sort Large Array using Quick Sort Partition Algo.                                                                            
                3. Find median of the array using Median of Median algorithm.                                                                   
                4. Exit.                                                                                                                        
                Enter your choice: 4                                                                                                            
                                                                                                                                                
                                                                                                                                                
...Program finished with exit code 0                                                                                                            
Press ENTER to exit console.
*/


