extern "C" void __cdecl f339d70(void*, int, int);
extern "C" void __cdecl f33d9e0();
extern "C" int __cdecl f213720(void*, int);
extern "C" void __cdecl f213380(void*, const char*, int);
extern "C" void __cdecl f213600(void*, int);
extern "C" int __cdecl f212f00(void*, int);
extern "C" void __cdecl f338e20(void*, const char*);
extern "C" void __cdecl f212d80(void*, int);
extern "C" void __cdecl f212ed0(void*, int);
extern "C" int __cdecl f212f70(void*, int);
extern "C" float __cdecl f2130e0(void*, int);
extern "C" void __cdecl f212e60(void*, int);
extern "C" int __cdecl f213950(void*, int);
int __cdecl target(void* state, void*) {
    f339d70(state, 2, 5);
    f33d9e0();
    f213720(state, -1);
    f213380(state, "__fenv", 6);
    f213600(state, -2);
    if (f212f00(state, -1))
        f338e20(state, "`setfenv' cannot change a protected environment");
    else
        f212d80(state, -3);
    f212ed0(state, 2);
    if (f212f70(state, 1)) {
        if (f2130e0(state, 1) == 0.0f) {
            f212e60(state, -10001);
            return 0;
        }
    }
    if (!f213950(state, -2))
        f338e20(state, "`setfenv' cannot change environment of given function");
    return 0;
}