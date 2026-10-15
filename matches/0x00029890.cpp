struct Sub {
    char pad[0x9e];
    char flag;
};
struct Obj {
    char pad[0x1ca0];
    Sub* sub;
};
unsigned __int64 __cdecl make(unsigned, unsigned, unsigned);
class Handler {
  public:
    Obj* find(unsigned, unsigned);
    void func(unsigned x);
};
void Handler::func(unsigned x) {
    unsigned __int64 p = make(x, 0, 0);
    Obj* o = find((unsigned)p, (unsigned)(p >> 32));
    if (o && o->sub)
        o->sub->flag = 0;
}