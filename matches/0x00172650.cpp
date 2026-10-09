class SurfAction {
  public:
    char pad[0x20];
    void* mFirst;
    void* mSecond;
    void vfunc_4();
};
class A {
  public:
    A* step();
};
class B {
  public:
    B* next();
    void finish(void*, int);
};
void SurfAction::vfunc_4() {
    A* a = (A*)mFirst;
    if (a) {
        B* b = (B*)a->step();
        b = b->next();
        if (b)
            b->finish(mSecond, 0);
    }
}