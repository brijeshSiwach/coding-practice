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

class MovingCandies {
  public:

  int vis[20][20][401][401];

  bool not_valid (int i, int j, int n, int m){
      return i < 0 || j < 0 || i >= n || j >= m;
  }

  void dfs(int i, int j, int n, int m, int can, int path, vector<string> &t){
  	if(not_valid(i, j, n, m)){
  		return;
  	}
  	path++;
  	can += (t[i][j] == '#');
  	if(path > n*m || vis[i][j][can][path]){
  		return;
  	}
  	vis[i][j][can][path]=1;
  	dfs(i+1,j,n,m,can,path,t);
  	dfs(i-1,j,n,m,can,path,t);
  	dfs(i,j-1,n,m,can,path,t);
  	dfs(i,j+1,n,m,can,path,t);
  	return;
  }

  int minMoved(vector <string> t) {
  	memset(vis, 0, sizeof vis);
    int n = t.size(), m=t[0].size();
    int candies=0;
    for(auto s: t){
      for(auto c: s){
          candies += (c=='#');
      }
    }
    if(candies < n+m-1){
      return -1;
    }
    dfs(0,0,n,m,0,0,t);
    int ans = 100000;
    for(int i = 0; i < n*m; i++){
    	for(int j = 0; j < n*m; j++){
    		if(i >= j && i <= candies){
    			if(vis[n-1][m-1][j][i]){
    				ans = min(ans, i-j);
    			}
    		}
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			string t[]                = {
"#...###",
"#...#.#",
"##..#.#",
".#....#"
};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string t[]                = {
"#...###",
"#...#.#",
"##..###",
".#....#"
};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string t[]                = {
".#..",
"##..",
"..#.",
"..#.",
"..##",
"..##"
};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string t[]                = {
".....",
".###.",
"####.",
"....."
};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string t[]                = {
".#...#.###.#",
"#.#.##......",
".#.#......#.",
"..#.......#.",
"##.........."
};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string t[]                = {
"###.#########..#####",
".#######.###########"
};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string t[]                = {
"..",
".."
};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string t[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string t[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string t[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MovingCandies().minMoved(vector <string>(t, t + (sizeof t / sizeof t[0])));
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
