extern "C" char* strncpy(char*, const char*, unsigned);
class X_626c0 {
  public:
    char f(const char* s);
    char pad[0x10];
    char buf[0x80];
};
char X_626c0::f(const char* s) {
    strncpy(buf, s, 0x80);
    return 1;
}
