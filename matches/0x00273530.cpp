extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
extern char gA_273530[];
extern char gB_273530[];
extern const char tag[];
void Target(int a, int b) {
    Init(gA_273530);
    Register(gB_273530, 0x114, a, 0, b, tag, 4);
}
