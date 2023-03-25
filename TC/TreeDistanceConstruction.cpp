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

class TreeDistanceConstruction {
  public:

  void dfs(int u, int p, vector<int> &dp, vector<int> adj[]){
      for(auto v: adj[u]){
          if(v!=p){
              dfs(v,u,dp, adj);
              dp[u] = max(dp[v]+1, dp[u]);
          }
      }
  }

  vector <int> construct(vector <int> d) {
      vector<ar<int,2>> edge;
      unordered_map<int,int> f;
      int n = d.size();
      vector<int> adj[n];
      for(int i = 0; i < n; i++){
          f[d[i]]++;
          edge.push_back({d[i],i});
      }
      sort(all(edge)), reverse(all(edge));
      vector<int> ans;
      vector<ar<int,2>> p1, p2; 
      set<int> al;
      p1.push_back(edge[0]), p2.push_back(edge[1]);
      al.insert(edge[0][1]), al.insert(edge[1][1]);
      for(int i = 2; i < n; i++){
          if(p1.back()[0] - 1 == edge[i][0]){
              p1.push_back(edge[i]);
              al.insert(edge[i][1]);
          }
          else if(p2.back()[0] - 1 == edge[i][0]){
              p2.push_back(edge[i]);
              al.insert(edge[i][1]);
          }
      }
      while(!p2.empty()){
          p1.push_back(p2.back());
          p2.pop_back();
      }
      for(int i = 0; i < (int)p1.size()-1; i++){
          ans.push_back(p1[i][1]);
          ans.push_back(p1[i+1][1]);
      }
      for(int i = 0; i < (int)ans.size(); i+=2){
          adj[ans[i]].push_back(ans[i+1]);
          adj[ans[i+1]].push_back(ans[i]);
      }
      for(int i=0;i<n;i++){
          if(al.find(i)!=al.end()) continue;
          int ok = 0;
          for(int j = 0; j < (int)p1.size(); j++){
              vector<int> dp(n);
              vector<int> nadj[n];
              for(int k = 0; k < n; k++){
                  nadj[k] = adj[k];
              }
              nadj[i].push_back(p1[j][1]);
              nadj[p1[j][1]].push_back(i);
              dfs(i,-1, dp, nadj);
              if(dp[i] == d[i]){
                  ok=1;
                  ans.push_back(i);
                  ans.push_back(p1[j][1]);
                  for(int ii = 0; ii < n; ii++){
                      adj[ii] = nadj[ii];
                  }
                  break;
              }
          }
          if(ok==0){
              return {};
          }
      }
      for(int i = 0; i < n; i++){
          vector<int> dp(n);
          dfs(i, -1, dp, adj);
          if(dp[i] != d[i]){
              return {};
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
			int d[]                   = {3,2,2,3};
			int expected__[]          = {1, 2, 1, 0, 2, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int d[]                   = {1,2,2,2};
			int expected__[]          = {0, 1, 0, 2, 0, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int d[]                   = {1,1,1,1};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int d[]                   = {1,1,1};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int d[]                   = {1,1};
			int expected__[]          = {0, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int d[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int d[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int d[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
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
