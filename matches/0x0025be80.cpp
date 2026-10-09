extern "C" int __cdecl FUN_0024c310(int);
extern "C" int __cdecl FUN_0024c2f0(int);
unsigned int __cdecl target(int a, int b) {
    int x = FUN_0024c310(a);
    int y = FUN_0024c2f0(b);
    unsigned int z = FUN_0024c310(b);
    return (unsigned int)(y * x) / z;
}