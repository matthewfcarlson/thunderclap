class T {
  public:
    T(const char*, int);
    ~T();
};
extern T g;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void f() {
    g.T::T("sound/rsd", 0);
    atexit(cleanup);
}