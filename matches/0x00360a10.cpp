extern "C" int __cdecl atexit(void (*)(void));
extern void __cdecl FUN_00364550();
struct Obj {
    void Init();
};
extern Obj gObj;
void __cdecl FUN_00360a10() {
    gObj.Init();
    atexit((void (*)(void))FUN_00364550);
}
