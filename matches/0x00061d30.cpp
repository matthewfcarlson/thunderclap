struct V3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x4c];
    V3 v;
    bool Set(const V3* p);
};
bool Obj::Set(const V3* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}
