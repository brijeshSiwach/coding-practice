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

class BalancedStrings {
public:
  vector <string> findAny(int n) {
    // cout<<1<<"\n";
      vector<string> ans(n);
      if(n <= 26){
        for(int i = 0; i < n; i++){
            string s;
            s+=('a' + i);
            ans[i]=s;
        }
        return ans;
      }
      else{
          int c = 0;
          while(n>3){
              if(c>=20) c%=20;
              string s;
              s+= ('a' + c);
              ans[n-1]=s;
              n--;
              c++;
          }
          int sim = 0;
          for(int i = 3; i<(int)ans.size(); i++){
              for(int j=i+1; j<(int)ans.size(); j++){
                  if(ans[i] == ans[j]){
                      sim++;
                  }
              }
          }
          c=20;
          int i=0;
          while(sim>=0){
            if(ans[i].length()<100){
                char ch='a'+c;
                ans[i].push_back(ch);
                if(c%2) c--;
                else c++;
                if(ans[i].size()<100) sim--;
            }
            else{
                // dbg(sim);
                i++;
                c+=2;
            }
          }
          if(ans[1].empty()) ans[1].push_back('a'+22);
          if(ans[2].empty()) ans[2].push_back('a'+24);
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
			int N                     = 3;
			string expected__[]       = {"eertree", "topcoder", "arena" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 4;
			string expected__[]       = {"hello", "little", "polar", "bear" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 5;
			string expected__[]       = {"abbbbbbbbbbbbczaaaaaao", "c", "zz", "c", "xxxyyyzvvv" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 1;
			string expected__[]       = {"kkkkkkkkkkkkkkkkkkk" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int N                     = 10;
			string expected__[]       = {"asdflkjhsdfsfffkdhjfdlshlfds", "pudelek", "xo", "xo", "mnbvmnmbbr", "plox", "qqwwrrttyyy", "you", "are", "awesome" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = BalancedStrings().findAny(N);
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
