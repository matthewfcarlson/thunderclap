extern "C" int __cdecl Check(int, int);
extern "C" void __cdecl StepA(int, int, int);
extern "C" int __cdecl StepB(int, int);
extern "C" void __cdecl StepC(int, int);
extern "C" void __cdecl StepD(int, int);

int __cdecl Target(int a, int b, int c) {
    if (!Check(a, b))
        return 0;
    StepA(a, -1, c);
    if (!StepB(a, -1)) {
        StepC(a, -3);
        return 0;
    }
    StepD(a, -2);
    return 1;
}