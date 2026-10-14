extern "C" struct Result {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Result Hash(const char*);
extern Result g;

void FUN_0035ed30() {
    g = Hash("golfBall_golfBall");
}