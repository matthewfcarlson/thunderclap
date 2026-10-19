struct ThisWrap_000f8d40 {
    int FUN_000f8cc0(int a);
    int Target(int a);
};
extern "C" int __cdecl FUN_00344e74(int a, int b, void** c, void** d, int e);
int ThisWrap_000f8d40::Target(int a) {
    return FUN_00344e74(this->FUN_000f8cc0(a), 0, (void**)0x4a17a8, (void**)0x4a17c4, 0);
}
