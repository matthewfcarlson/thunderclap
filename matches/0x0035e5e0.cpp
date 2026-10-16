struct Pair {
    unsigned a, b;
};
extern Pair __cdecl Find(const char*);
extern Pair result;
void __cdecl FUN_0035e5e0() {
    result = Find("golfBall_golfBall");
}