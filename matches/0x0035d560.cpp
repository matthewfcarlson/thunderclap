extern "C" unsigned __int64 __cdecl hash(const char*);
extern "C" unsigned __int64 value;
void init() {
    value = hash("golfBall_golfBall");
}