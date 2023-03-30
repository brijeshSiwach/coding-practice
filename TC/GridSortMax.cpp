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

class GridSortMax {
  public:
  string findMax(int n, int m, vector <int> grid) {
      string ans;
      vector<int> pos(n * m + 10);
      vector<int> br(n+1, -1);
      vector<int> cr(n+1, -1);
      vector<int> bc(m+1, -1);
      vector<int> cc(m+1, -1);
      for(int i = 0; i < n*m; i++){
      	pos[grid[i]] = i;
      }
      for(int i = 0; i < n*m; i++){
      	int x = i / m, y = i % m;
      	int p = pos[i+1] / m, q = pos[i + 1] % m;
      	if((br[x]==-1 || br[x]==p) && (cr[p] == -1 || cr[p] == x) && (cc[y] == -1 || cc[y] == q) && (bc[q] == -1 || bc[q] == y)) {
      		ans += '1';
      		br[x]=p;
      		cr[p]=x;
      		cc[y]=q;
      		bc[q]=y;
      	}
    		else {
    			ans += '0';
    		}
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int n                     = 2;
			int m                     = 2;
			int grid[]                = { 1,2, 3,4 };
			string expected__         = "1111";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int m                     = 2;
			int grid[]                = { 2,1, 3,4 };
			string expected__         = "1100";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 2;
			int m                     = 2;
			int grid[]                = { 4,2, 3,1 };
			string expected__         = "1001";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 1;
			int m                     = 10;
			int grid[]                = {10,6,2,3,5,7,1,9,4,8};
			string expected__         = "1111111111";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 3;
			int m                     = 5;
			int grid[]                = { 5,2,10,7,9, 3,4,14,11,1, 15,12,6,8,13 };
			string expected__         = "101100100100000";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 6;
			int m                     = 2;
			int grid[]                = { 3,9, 5,1, 10,6, 2,7, 8,11, 12,4 };
			string expected__         = "100000101010";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int n                     = ;
			int m                     = ;
			int grid[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int m                     = ;
			int grid[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int m                     = ;
			int grid[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
