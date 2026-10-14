extern unsigned int gA_35e520;
extern unsigned int gB_35e520;

unsigned long long __cdecl FUN_0027b020(const char*);

void FUN_0035e520() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    gA_35e520 = (unsigned int)h;
    gB_35e520 = (unsigned int)(h >> 32);
}
