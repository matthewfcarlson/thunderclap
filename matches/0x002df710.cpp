// Same code shape as 0x002df6f0 (propagated; names are from that function)
class Helper_2df710 {
  public:
    void go(int, int, int);
};
class PrimGroupSkinnedStreamed {
  public:
    char pad[0x5c];
    int a;
    int b;
    int c;
    void vfunc_12(int);
};
void PrimGroupSkinnedStreamed::vfunc_12(int arg) {
    ((Helper_2df710*)a)->go(arg, b, c);
}