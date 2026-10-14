class SurfAction {
  public:
    char pad[0x20];
    void* mFirst;
    void* mSecond;
    void vfunc_4();
};
class A_172650 {
  public:
    A_172650* step();
};
class B_172650 {
  public:
    B_172650* next();
    void finish(void*, int);
};
void SurfAction::vfunc_4() {
    A_172650* a = (A_172650*)mFirst;
    if (a) {
        B_172650* b = (B_172650*)a->step();
        b = b->next();
        if (b)
            b->finish(mSecond, 0);
    }
}