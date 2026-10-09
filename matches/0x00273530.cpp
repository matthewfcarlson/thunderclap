extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
extern char gA[];
extern char gB[];
extern const char tag[];
void Target(int a, int b) {
    Init(gA);
    Register(gB, 0x114, a, 0, b, tag, 4);
}
