class Obj {
  public:
    void clean();
};
class Thing {
  public:
    char pad[0x34];
    Obj* a;
    Obj* b;
    void target();
};
void Thing::target() {
    if (a)
        a->clean();
    if (b)
        b->clean();
}
