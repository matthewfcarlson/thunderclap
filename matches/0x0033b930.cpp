extern "C" double __cdecl calc(void*, int);
extern "C" void __cdecl sink(void*, float);
extern "C" double __cdecl exp(double);
extern "C" int __cdecl FUN_0033b930(void* p) {
    sink(p, (float)exp(calc(p, 1)));
    return 1;
}