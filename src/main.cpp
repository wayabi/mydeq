#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <deque>

#include "mydeq.h"
#include "Util.h"

using namespace std;

void load_test()
{
	int size = 10000;
	vector<int> data;
	data.resize(size);
	deque<int> q0(data.begin(), data.end());
	mydeq<int> q1(size);
	q1.push(&data[0], data.size());

	vector<int> b;
	b.resize(size);
	int times = 100;

	auto c0 = clock();
	for(int i=0;i<times;++i){
		vector<int> a(q0.begin(), q0.end());
	}
	auto c1 = clock();
	for(int i=0;i<times;++i){
		q1.get_array(&b[0]);
	}
	auto c2 = clock();
	printf("std::dequue = %d millisec\n", c1 - c0);
	printf("mydeq = %d millisec\n", c2 - c1);
}

int main(){
	load_test();
	char buf[80];
	int size = 5;
	vector<int> data_get;
	data_get.resize(size);
	mydeq<int> deq(size);
	while(true){
		gets(buf);
		auto ss = Util::split(string(buf), ',');
		vector<int> data;
		for(auto ite = ss.begin();ite != ss.end();++ite){
			int v = atoi(ite->c_str());
			data.push_back(v);
		}
		deq.push(&data[0], data.size());
		int num = deq.get_array(&data_get[0]);
		stringstream ss_out;
		for(int i=0;i<num;++i){
			ss_out << data_get[i] << ",";
		}
		ss_out << "\n";
		printf(ss_out.str().c_str());
	}

	return 0;
}
