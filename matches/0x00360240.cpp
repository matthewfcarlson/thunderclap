struct Obj {
    Obj();
    ~Obj();
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void target() {
    gObj.Obj::Obj();
    atexit(cleanup);
}