extern "C" int __cdecl Check(void*, int);
extern "C" void* __cdecl Get(void*, int);
typedef int(__cdecl* Fn)(void*, void*);
int __cdecl FUN_001d0d30(void* p) {
    if (!Check(p, 0xffffd8ee))
        return 0;
    Fn f = (Fn)Get(p, 0xffffd8ee);
    if (!Check(p, 0xffffd8ed))
        return 0;
    return f(p, Get(p, 0xffffd8ed));
}