class Obj {
  public:
    char pad[0x514];
    void* value;
    void Set(int);
};
extern "C" void* __stdcall FUN_001e9960(int);
void Obj::Set(int x) {
    void* p = FUN_001e9960(x);
    if (p)
        value = p;
}