struct V3_61d30 {
    int x, y, z;
};
class Obj_61d30 {
  public:
    char pad[0x4c];
    V3_61d30 v;
    bool Set(const V3_61d30* p);
};
bool Obj_61d30::Set(const V3_61d30* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}
