void __cdecl freebuf(void*);
void* __cdecl allocbuf(unsigned);
extern "C" unsigned __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class X {
    char pad[24];
    char* str;

  public:
    void Set(const char* s);
};
void X::Set(const char* s) {
    if (str) {
        freebuf(str);
        str = 0;
    }
    if (s) {
        str = (char*)allocbuf(strlen(s) + 1);
        strcpy(str, s);
    }
}