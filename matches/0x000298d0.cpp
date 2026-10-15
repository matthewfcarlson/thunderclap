struct Obj {
    char pad[0x1ca0];
    struct Sub* sub;
};
struct Sub {
    char pad[0x128];
    char flag;
};
struct Host {
    Obj* lookup(unsigned a, unsigned b);
    void set(char const* name, char flag);
};
extern "C" unsigned __int64 __cdecl hash(char const*, unsigned, unsigned);
void Host::set(char const* name, char flag) {
    unsigned __int64 a = hash(name, 0, 0);
    Obj* o = lookup((unsigned)a, (unsigned)(a >> 32));
    if (o && o->sub)
        o->sub->flag = flag;
}