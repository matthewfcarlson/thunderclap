// Same code shape as 0x002df690 (propagated; names are from that function)
class Obj_2df6b0 {
  public:
    void FUN(int, int, int);
};
class PrimGroupStreamed {
  public:
    char pad[0x5c];
    Obj_2df6b0* mObj;
    void vfunc_12(int a);
};
void PrimGroupStreamed::vfunc_12(int a) {
    mObj->FUN(a, 0, 0);
}