// Same code shape as 0x001bde90 (propagated; names are from that function)
class Obj_1bdeb0 {
  public:
    void clean();
};
class Thing_1bdeb0 {
  public:
    char pad[0x34];
    Obj_1bdeb0* a;
    Obj_1bdeb0* b;
    void target();
};
void Thing_1bdeb0::target() {
    if (a)
        a->clean();
    if (b)
        b->clean();
}
