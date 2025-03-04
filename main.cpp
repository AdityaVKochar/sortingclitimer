#include<bits/stdc++.h>
#include<chrono>
#include "sorts.cpp"
using namespace std;


int main() {

    vector<int> arr;
    int n;

    cout << "Welcome to Sorting Visualizer\n";

    char cont='y';

    while(cont=='y') {

        arr.clear();

        cout << "Enter size of array: ";
        cin >> n;
        cout << "Enter elements:\n";
        input(arr, n); 

        bool to_break = true;

        while(to_break) {
            cout << "\nEnter respective number to visualize particular sort\n";
            cout << "1: Bubble Sort\n"; 
            cout << "2: Selection Sort\n"; 
            cout << "3: Insertion Sort\n"; 
            cout << "4: Quick Sort\n"; 
            cout << "5: Merge Sort\n";
            cout << "6: Counting Sort\n";
            cout << "Press any other number to exit\n\n";

            int ch;
            cin >> ch;

            chrono::time_point<chrono::system_clock> start, end;
            start = chrono::system_clock::now();

            switch(ch) {

                case 1:
                    bubble_sort(arr);
                    cout << "Time Complexity: O(n^2)\n";
                    break;
                case 2:
                    selection_sort(arr);
                    cout << "Time Complexity: O(n^2)\n";
                    break;
                case 3:
                    insertion_sort(arr);
                    cout << "Time Complexity: O(n^2)\n";
                    break;
                case 4:
                    quick_sort(arr);
                    cout << "Time Complexity: O(nlogn)\n";
                    break;
                case 5:
                    merge_sort(arr);
                    cout << "Time Complexity: O(nlogn)\n";
                    break;
                case 6:
                    counting_sort(arr);
                    cout << "Time Complexity: O(n+m)\n";
                    break;
                default:
                    to_break = false;

            } 

            if(!to_break)
                continue;

            end = chrono::system_clock::now();
            chrono::duration<double, milli> elapsed_ms = end - start;
            cout << "Time Taken: " << elapsed_ms.count() << " ms" << endl;
        
        }

        
        cout << "\nEnter y to continue:\n";

        cin >> cont;


    }



    

}