struct V {
    int x, y, z;
};
class Obj {
    char pad[8];
    V value;

  public:
    void Set(const V& v);
};
void Obj::Set(const V& v) {
    value.x = v.x;
    value.y = v.y;
    value.z = v.z;
}