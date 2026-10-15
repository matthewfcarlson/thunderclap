extern "C" unsigned __int64 __cdecl resolve(int, int, int);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
  public:
    char* get(unsigned int, unsigned int);
    void fn(int, const char*);
};
void Obj::fn(int a, const char* s) {
    unsigned __int64 id = resolve(a, 0, 0);
    char* p = get((unsigned int)id, (unsigned int)(id >> 32));
    if (p)
        strcpy(p + 0x20f8, s);
}
