struct Handle {
    int lo;
    int hi;
};
extern "C" Handle __cdecl FindHandle(const char* name);
extern Handle gHandle;
void FUN_0035e840() {
    gHandle = FindHandle("golfBall_golfBall");
}
