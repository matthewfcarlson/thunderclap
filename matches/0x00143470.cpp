struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0x1c];
    int x, y, z;

  public:
    bool Set(Vec* p);
};
bool Obj::Set(Vec* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return true;
}