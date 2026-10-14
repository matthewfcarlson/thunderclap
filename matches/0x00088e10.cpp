extern "C" char* __cdecl strncpy(char*, const char*, unsigned);
class X {
  public:
    void Set(const char* s);
    char pad0[0x5c];
    char buf[0x40];
    char flag;
};
void X::Set(const char* s) {
    strncpy(buf, s, 0x40);
    flag = 1;
}
