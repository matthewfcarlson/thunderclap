struct Obj {
    char pad[0x1d28];
    unsigned char flag;
};
class C {
  public:
    Obj* lookup(unsigned int lo, unsigned int hi);
    void set(char* name, unsigned char v);
};
extern "C" unsigned __int64 __cdecl hash(char*, int, int);
void C::set(char* name, unsigned char v) {
    unsigned __int64 id = hash(name, 0, 0);
    Obj* p = lookup((unsigned int)id, (unsigned int)(id >> 32));
    if (p)
        p->flag = v;
}