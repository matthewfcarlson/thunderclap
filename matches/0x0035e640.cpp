struct Obj {
    void Init(int, int, int);
};
extern Obj globalObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl target() {
    globalObj.Init(0xffff, 0xffff, 0xffff);
    atexit(cleanup);
}