class Obj {
  public:
    char pad[0x70];
    char flag;
    char gap[3];
    Obj* link;
    Obj* get();
};
struct ThisWrap_001df3a0 {
    Obj* findObj(int);
    char target(int id, char value);
};
char ThisWrap_001df3a0::target(int id, char value) {
    Obj* a = this->findObj(id);
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