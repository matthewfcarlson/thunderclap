extern "C" struct Result_35c720 {
    int a;
    int b;
};
extern "C" struct Result_35c720 __cdecl FUN_0027b020(const char* name);
extern int gA_35c720;
extern int gB_35c720;
void FUN_0035c720() {
    Result_35c720 r = FUN_0027b020("golfBall_golfBall");
    gA_35c720 = r.a;
    gB_35c720 = r.b;
}
