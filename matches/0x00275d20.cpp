extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
extern char g1[];
extern char g2[];
extern const char fileName[];
void __cdecl target(int param_1, int param_2) {
    Init(g1);
    Register(g2, 0x168, param_1, 0, param_2, fileName, 4);
}
