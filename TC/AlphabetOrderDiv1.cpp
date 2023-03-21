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

class AlphabetOrderDiv1 {
  public:
  int b_edge = 0;
  void dfs(int u, set<int> adj[], vector<int> &vis){
      vis[u] = 2;
      for(auto v: adj[u]){
          if(vis[v]==2){
              b_edge = 1;
          }
          else if (vis[v] == 1){
          }
          else{
              dfs(v, adj, vis);
          }
      }
      vis[u]=1;
  }


  string isOrdered(vector <string> words) {
    int order[26][26];
    memset(order, 0, sizeof order);
    int pos = 1;
    set<int> adj[26];
    vector<int> indeg(26), outdeg(26);
    for(int i = 0; i < (int)words.size(); i++){
      for(int j = 0; j < (int)words[i].length()-1; j++){
          int x = words[i][j]-'a';
          int y = words[i][j+1]-'a';

          if(x != y) adj[x].insert(y), indeg[y]++;
          outdeg[x]++;
      }
    }
    vector<int> vis(26);
    int ok = 0;
    for(int i = 0; i < 26; i++){
      if(!vis[i] && indeg[i] == 0){
          if(outdeg[i]) ok = 1;
          b_edge = 0;
          dfs(i, adj, vis);
          // dbg(b_edge);
          if(b_edge) pos = 0;
      }
    }

    return (pos&ok? "Possible":"Impossible");
  }
};
// _any hypothetical undefs I will talk about in a minute_
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
			string words[]            = {"single","round","match"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"topcoder","topcoder"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"algorithm", "contest"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"pink","floyd"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string words[]            = {"gimnasia","y","esgrima","la","plata"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetOrderDiv1().isOrdered(vector <string>(words, words + (sizeof words / sizeof words[0])));
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
