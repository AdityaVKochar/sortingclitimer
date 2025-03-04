#include<bits/stdc++.h>
using namespace std;

template <typename T> void input(vector<T>& arr, int n) {

    T temp;
    
    while(n--) {
        cin >> temp;
        arr.push_back(temp);
    }

}

template <typename T> void display(vector<T>& arr) {

    for(auto it: arr) {
        cout << it << ' ';
    }

    cout << endl;

}

template <typename T> void bubble_sort(vector<T> arr) {
    
    int n = arr.size(), it=0;
    bool not_swapped;

    for(int i=0; i<n-1; i++) {

        not_swapped = true;

        for(int j=0; j<n-i-1; j++) {

            cout << "Iteration " << it++ << ':' << endl;
            display(arr);

            if(arr[j] > arr[j+1]) {
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
                not_swapped = false;
            }
        }

        if(not_swapped) {
            break;
        }
    }

    cout << "Finally - " << endl;
    display(arr);
}

template <typename T> void selection_sort(vector<T> arr) {

    int n = arr.size(), min_ind = 0, it=0;


    for(int i=0; i<n-1; i++) {

        cout << "Iteration " << it++ << ':' << endl;
        display(arr);

        min_ind = i;

        for(int j=i; j<n; j++) {
            min_ind = arr[min_ind]>arr[j]?j:min_ind;
        }

        swap(arr[min_ind], arr[i]); 
    }

    cout << "Finally - " << endl;
    display(arr);
}

template <typename T> void insertion_sort(vector<T> arr) {

    int n = arr.size(), it=0;

    for(int i=1; i<n; i++) {

        cout << "Iteration " << it++ << ':' << endl;
        display(arr);

        for(int j=0; j<i; j++) {
            if(arr[j]>arr[i]) {
                T temp = arr[i];
                for(int k=i; k>j; k--) {
                    arr[k] = arr[k-1];
                }
                arr[j] = temp;
                break;
            }
        }
    }

    cout << "Finally - " << endl;
    display(arr);
}

template <typename T> vector<T> quick_sort(vector<T> arr) {

    int n=arr.size();
    if(n<2)
        return arr;

    cout << "Quick Sorting" << endl;
    display(arr);

    T pivot = arr[n/2];

    vector<T> low, high;

    for(int i=0; i<n/2; i++)
        if(arr[i]<pivot)
            low.push_back(arr[i]);
        else
            high.push_back(arr[i]);
    for(int i=n/2+1; i<n; i++)
        if(arr[i]<pivot)
            low.push_back(arr[i]);
        else
            high.push_back(arr[i]);

    low = quick_sort(low);
    high = quick_sort(high);

    vector<T> ans;

    for(int val: low)
        ans.push_back(val);
    ans.push_back(pivot);
    for(int val: high)
        ans.push_back(val);

    cout << "Finally" << endl;
    display(ans);

    return ans;

}

template <typename T> vector<T> merge_sort(vector<T> arr) {

    int n=arr.size();
    if(n<2)
        return arr;

    cout << "Merge Sorting" << endl;
    display(arr);

    vector<T> half1, half2, ans;

    half1.insert(half1.begin(), arr.begin(), arr.begin()+(n/2));
    half2.insert(half2.begin(), arr.begin()+(n/2), arr.end());

    half1 = merge_sort(half1);
    half2 = merge_sort(half2);

    auto it1 = half1.begin(), it2 = half2.begin();

    while(it1!=half1.end() && it2!=half2.end()) {
        if(*it1<*it2) {
            ans.push_back(*it1);
            it1++;
        }
        else {
            ans.push_back(*it2);
            it2++;
        }
    }

    if(it1!=half1.end()) {
        ans.insert(ans.end(), it1, half1.end());
    }
    else {
        ans.insert(ans.end(), it2, half2.end());
    }


    cout << "Finally" << endl;
    display(ans);

    return ans;

}

template <typename T> void counting_sort(vector<T> arr) {
    
    map<T, int> count;

    for(int val: arr) {
        count[val]++;
    }

    vector<T> ans;

    cout << "Counting Sorting\n";

    for(auto it: count) {
        ans.insert(ans.end(), it.second, it.first);
    }
    
    cout << "Finally" << endl;
    display(ans);

}