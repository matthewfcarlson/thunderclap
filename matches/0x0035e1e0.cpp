struct Pair {
    unsigned a, b;
};
extern Pair __cdecl Lookup(const char*);
extern Pair result;
void FUN_0035e1e0() {
    result = Lookup("golfBall_golfBall");
}