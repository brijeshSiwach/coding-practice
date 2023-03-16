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
// #define clock() cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"

class MazeConstruct {
public:

	bool check(vector<string> &grid, int k){
		int n = grid.size(), m = grid[0].size();
		int dp[n+1][m+1];
		memset(dp, 0x3f, sizeof dp);
		priority_queue<ar<int,3>, vector<ar<int,3>>, greater<ar<int,3>>> pq;
		pq.push({0,0,0});
		while(!pq.empty()){
			auto u = pq.top();
			pq.pop();
			int d = u[0], i=u[1], j=u[2];
			if(i < 0 || j < 0 || i >= n || j >= m) continue;
			if(grid[i][j] == '#') continue;
			if(dp[i][j] <= u[0]) continue;
			dp[i][j] = u[0];
			pq.push({u[0]+1,i+1,j});
			pq.push({u[0]+1,i,j-1});
			pq.push({u[0]+1,i,j+1});
			pq.push({u[0]+1,i-1,j});
		}
		return dp[n-1][m-1] == k;
	}

  vector <string> construct(int k){
  	vector<string> grid;
  	int n = 50, m = 50;
  	if(k <= 98){
  		for(int i=1; i<=50;i++){
  			for(int j=1;j<=50;j++){
  				if(i+j-2==k){
  					n=i,m=j;
  					break;
  				}
  			}
  		}
  		for(int i=0;i<n;i++){
  			string s(m,'.');
  			grid.push_back(s);
  		}
  		return grid;
  	}
  	if(k&1) n=49;
  	for(int i = 0; i < n; i++){
  		string s(m,'.');
  		grid.push_back(s);
  	}
  	int row = 0, col = 1, d=1;
  	while(true){
  		grid[row][col]='#';
  		if(check(grid, k)){
  			return grid;
  		}
  		row+=d;
  		if(row==n-1){
  			d=-1;
  			col+=2;
  		}
  		if(row == 0){
  			d=1;
  			col+=2;
  		}
  	}
  	return {};
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
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) { 
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
			int k                     = 3;
			string expected__[]       = {"...." };

			std::clock_t start__      = std::clock();
			vector <string> received__ = MazeConstruct().construct(k);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int k                     = 4;
			string expected__[]       = {"...", "...", "..." };

			std::clock_t start__      = std::clock();
			vector <string> received__ = MazeConstruct().construct(k);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int k                     = 10;
			string expected__[]       = {"..#..", "#.#..", "..#..", ".#...", "....." };

			std::clock_t start__      = std::clock();
			vector <string> received__ = MazeConstruct().construct(k);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int k                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = MazeConstruct().construct(k);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			int k                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = MazeConstruct().construct(k);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int k                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = MazeConstruct().construct(k);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
