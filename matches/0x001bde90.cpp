class Obj_1bde90 {
  public:
    void clean();
};
class Thing_1bde90 {
  public:
    char pad[0x34];
    Obj_1bde90* a;
    Obj_1bde90* b;
    void target();
};
void Thing_1bde90::target() {
    if (a)
        a->clean();
    if (b)
        b->clean();
}
