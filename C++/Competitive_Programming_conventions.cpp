using ll = long long;
using ld = long double;

typedef pair <int,int> P;

#define rep(i, n) for(int  i = 0; i < (n); i++)

#define All(x) x.begin(), x.end()

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
inline bool chmax(T &a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}

template <class T>
inline bool chmin(T &a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}

const int inf = (int)1e9 + 7;
const long long INF = 1ll << 60;

std::cin.tie(nullptr);
std::ios::sync_with_stdio(false);
