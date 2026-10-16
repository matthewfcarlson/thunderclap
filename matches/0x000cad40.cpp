extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class X {
  public:
    char pad[0x4c4];
    char name[64];
    void SetName(const char*);
};
void X::SetName(const char* s) {
    strncpy(name, s, 64);
}