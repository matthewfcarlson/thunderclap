extern "C" struct Result {
    int a;
    int b;
};
extern "C" struct Result __cdecl FUN_0027b020(const char* name);
extern int gA;
extern int gB;
void FUN_0035c720() {
    Result r = FUN_0027b020("golfBall_golfBall");
    gA = r.a;
    gB = r.b;
}
