#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

#include "mydeq.h"
#include "Util.h"

using namespace std;

int main(){
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
