extern "C" int __stdcall FUN_000f8cc0(int a);
extern "C" int __cdecl FUN_00344e74(int a, int b, void** c, void** d, int e);
int __stdcall Target(int a) {
    return FUN_00344e74(FUN_000f8cc0(a), 0, (void**)0x4a17a8, (void**)0x4a17c4, 0);
}
