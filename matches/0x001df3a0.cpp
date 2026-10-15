class Obj {
  public:
    char pad[0x70];
    char flag;
    char gap[3];
    Obj* link;
    Obj* get();
};
Obj* __stdcall findObj(int);
char __stdcall target(int id, char value) {
    Obj* a = findObj(id);
    if (!a)
        return 0;
    Obj* b = a->get();
    if (!b)
        return 0;
    Obj* c = b->link;
    if (!c)
        return 0;
    c->flag = value;
    return 1;
}