// Same code shape as 0x00221cf0 (propagated; names are from that function)
struct Four {
    int x, y, z, w;
};
class Obj {
  public:
    char pad[0x40];
    Four v;
    int flag;
    void Set(const Four& p);
};
void Obj::Set(const Four& p) {
    v = p;
    flag = 1;
}
