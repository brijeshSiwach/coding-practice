#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
 
#define all(x) x.begin(), x.end()
#define nl cout<<"\n"
#define ar  array
#define PRECISION 9
#define fast_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

class DAGConstruction {
  public:
  vector <int> construct(vector <int> x) {
  		int n = x.size();
  		vector<ar<int,2>> edge;
  		for(int i = 0; i < n; i++){
  			edge.push_back({x[i],i});
  		}
  		sort(all(edge));
  		if(edge[0][0] != 1){
  			return {-1};
  		}
  		vector<int> p, ans;
  		int tot = 1;
  		p.push_back(edge[0][1]);
  		for(int i = 1; i < n; i++){
  			int deg = edge[i][0]-1;
  			if(deg > tot){
  				return {-1};
  			}
  			else{
  				for(int j = 0; j < p.size() && deg > 0; j++,deg--){
  					ans.push_back(p[j]);
  					ans.push_back(edge[i][1]);
  				}
  			}
  			p.push_back(edge[i][1]);
  			tot++;
  		}
      return ans;
  }
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x[]                   = {2, 1};
			int expected__[]          = {0, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {1, 1};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {1, 3, 1};
			int expected__[]          = {1, 0, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {5,5,5,5,5};
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1, 2, 3, 2, 5, 6, 7, 6, 7, 5, 10, 7, 10, 11, 15, 15, 13, 15, 18, 15, 20, 18, 22, 21, 22, 26, 25, 25, 26, 26, 26, 32, 30, 32, 32, 35, 34, 37, 39, 35, 37, 39, 39, 40, 45, 43, 45, 44, 47, 50};
			int expected__[]          = {0, 1, 0, 2, 1, 3, 2, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = DAGConstruction().construct(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
