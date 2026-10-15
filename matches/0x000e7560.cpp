extern char g1[], g2[], g3[];
extern "C" int __stdcall helper(int);
extern "C" int __cdecl work(int, int, char*, char*, int);
int __stdcall target(int x) {
    return work(work(helper(x), 0, g1, g2, 0), 0, g2, g3, 0);
}