#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq = {10, 20, 30};

	dq.push_front(5);
	dq.push_back(50);

	for(auto x: dq)
		cout << x << " ";
    cout<<endl;
	cout << dq.front() << " " << dq.back();

    auto it = dq.begin();

	it++;

	dq.insert(it, 20);

	dq.pop_front();
	dq.pop_back();

	cout<<dq.size();

    auto it1 = dq.begin();

	it1 = dq.insert(it, 7);

	it1 = dq.insert(it, 2, 3);

	it1 = dq.erase(it + 1);

	cout << (*it1) << endl;


	for(int i = 0; i < dq.size(); i++)
		cout<<dq[i]<<" ";
	cout<<endl;
	return 0;
}