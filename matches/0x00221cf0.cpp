struct Four_221cf0 {
    int x, y, z, w;
};
class Obj_221cf0 {
  public:
    char pad[0x40];
    Four_221cf0 v;
    int flag;
    void Set(const Four_221cf0& p);
};
void Obj_221cf0::Set(const Four_221cf0& p) {
    v = p;
    flag = 1;
}
