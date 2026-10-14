struct Handle_35e840 {
    int lo;
    int hi;
};
extern "C" Handle_35e840 __cdecl FindHandle(const char* name);
extern Handle_35e840 gHandle;
void FUN_0035e840() {
    gHandle = FindHandle("golfBall_golfBall");
}
