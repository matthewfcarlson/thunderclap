struct Obj {
    char pad[0x1b91];
    unsigned char flag;
};
struct Owner {
    Obj* get(unsigned long long);

  public:
    unsigned char Set(const char*, unsigned char);
};
extern "C" unsigned long long __cdecl Parse(const char*, int, int);
unsigned char Owner::Set(const char* s, unsigned char v) {
    unsigned long long id = Parse(s, 0, 0);
    Obj* p = get(id);
    if (!p)
        return 0;
    p->flag = v;
    return 1;
}