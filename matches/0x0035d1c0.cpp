extern "C" long long FUN_0027b020(const char*);
extern int g4dd8f0;
extern int g4dd8f4;
void FUN_0035d1c0() {
    long long r = FUN_0027b020("$MACRO_INSERT");
    *(int*)&r = *(int*)&r;
    g4dd8f0 = *(int*)&r;
    g4dd8f4 = *(int*)((char*)&r + 4);
}
