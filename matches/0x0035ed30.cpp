extern "C" struct Result_35ed30 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Result_35ed30 Hash(const char*);
extern Result_35ed30 g_35ed30;

void FUN_0035ed30() {
    g_35ed30 = Hash("golfBall_golfBall");
}