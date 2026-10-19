extern char g1[], g2[], g3[];
struct ThisWrap_000e7560 {
    int helper(int);
    int target(int x);
};
extern "C" int __cdecl work(int, int, char*, char*, int);
int ThisWrap_000e7560::target(int x) {
    return work(work(this->helper(x), 0, g1, g2, 0), 0, g2, g3, 0);
}