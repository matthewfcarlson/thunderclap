extern "C" void __cdecl FUN_00267760(void* p, int n, const char* fmt, int x);

class C_5dad0 {
  public:
    char Fn(int x);
};

char C_5dad0::Fn(int x) {
    char r = 1;
    void* q = (char*)this + 0x78;
    FUN_00267760(q, 0x40, "%s", x);
    return r;
}
