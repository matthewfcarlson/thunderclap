struct Vec {
    int x, y, z;
};
class Obj {
    char pad[32];
    int x, y, z;

  public:
    char Set(const Vec* p);
};
char Obj::Set(const Vec* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return 1;
}