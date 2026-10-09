extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
extern char gA, gB;
extern "C" void __cdecl Target(int a, int b) {
    Init(&gA);
    Register(&gB, 0x24, a, 0, b, "InstanceDrive", 4);
}