// Same code shape as 0x00172650 (propagated; names are from that function)
class SurfAction {
  public:
    char pad[0x20];
    void* mFirst;
    void* mSecond;
    void vfunc_4();
};
class A_172760 {
  public:
    A_172760* step();
};
class B_172760 {
  public:
    B_172760* next();
    void finish(void*, int);
};
void SurfAction::vfunc_4() {
    A_172760* a = (A_172760*)mFirst;
    if (a) {
        B_172760* b = (B_172760*)a->step();
        b = b->next();
        if (b)
            b->finish(mSecond, 0);
    }
}