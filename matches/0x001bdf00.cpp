// Same code shape as 0x001bde90 (propagated; names are from that function)
class Obj_1bdf00 {
  public:
    void clean();
};
class Thing_1bdf00 {
  public:
    char pad[0x34];
    Obj_1bdf00* a;
    Obj_1bdf00* b;
    void target();
};
void Thing_1bdf00::target() {
    if (a)
        a->clean();
    if (b)
        b->clean();
}
