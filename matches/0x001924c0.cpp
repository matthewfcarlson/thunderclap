struct Vec3 {
    int x;
    int y;
    int z;
};

class Obj {
  public:
    char pad[0x90];
    int v[3];
    char Set(Vec3* p);
};

char Obj::Set(Vec3* p) {
    v[0] = p->x;
    v[1] = p->y;
    v[2] = p->z;
    return 1;
}
