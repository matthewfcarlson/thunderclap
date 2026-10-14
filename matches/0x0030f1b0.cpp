// Same code shape as 0x00221cf0 (propagated; names are from that function)
struct Four_30f1b0 {
    int x, y, z, w;
};
class Obj_30f1b0 {
  public:
    char pad[0x40];
    Four_30f1b0 v;
    int flag;
    void Set(const Four_30f1b0& p);
};
void Obj_30f1b0::Set(const Four_30f1b0& p) {
    v = p;
    flag = 1;
}
