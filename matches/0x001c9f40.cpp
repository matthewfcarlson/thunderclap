extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl Fmt(char*, unsigned int, const char*, const char*);
class Obj {
  public:
    int v;
    int a;
    char pad[12];
    char s1[32];
    char s2[32];
    Obj* Init(int, const char*, const char*);
};
Obj* Obj::Init(int a, const char* b, const char* c) {
    memset(this, 0, 0x54);
    this->a = a;
    this->v = 0x54;
    this->s1[0] = 0;
    this->s2[0] = 0;
    if (b)
        Fmt(this->s1, 0x20, "%s", b);
    if (c)
        Fmt(this->s2, 0x20, "%s", c);
    return this;
}
