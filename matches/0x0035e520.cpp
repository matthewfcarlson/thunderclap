extern unsigned int gA;
extern unsigned int gB;

unsigned long long __cdecl FUN_0027b020(const char*);

void FUN_0035e520() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    gA = (unsigned int)h;
    gB = (unsigned int)(h >> 32);
}
