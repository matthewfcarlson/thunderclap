class Name {
  public:
    Name(const char*, int);
    ~Name();
};
extern Name gName;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void init() {
    gName.Name::Name("?Name?", 0);
    atexit(cleanup);
}