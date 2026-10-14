class Obj_2df690 {
  public:
    void FUN(int, int, int);
};
class PrimGroupStreamed {
  public:
    char pad[0x5c];
    Obj_2df690* mObj;
    void vfunc_12(int a);
};
void PrimGroupStreamed::vfunc_12(int a) {
    mObj->FUN(a, 0, 0);
}