struct Pair {
    int a, b;
};
extern Pair __cdecl lookup(const char*);
extern Pair result;
void target() {
    result = lookup("golfBall_golfBall");
}