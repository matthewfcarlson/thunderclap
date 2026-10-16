struct Pair {
    int a, b;
};
extern Pair __cdecl Lookup(const char*);
extern Pair result;
void __cdecl FUN_0035c9b0() {
    result = Lookup("golfBall_golfBall");
}