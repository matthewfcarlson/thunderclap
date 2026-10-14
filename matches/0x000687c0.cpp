struct Vec {
    int x;
    int y;
    int z;
};
class Obj {
  public:
    char pad[0x14];
    Vec v;
    char Set(Vec* p);
};
char Obj::Set(Vec* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return 1;
}
