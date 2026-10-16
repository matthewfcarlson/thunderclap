class Obj {
  public:
    Obj();
    ~Obj();
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup() {
    gObj.~Obj();
}
void FUN_0035f500() {
    gObj.Obj::Obj();
    atexit(cleanup);
}