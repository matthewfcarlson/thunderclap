struct Pair {
    int a;
    int b;
};
extern Pair __cdecl lookup(const char*);
extern Pair result;
void init() {
    result = lookup("golfBall_golfBall");
}