struct Vec3_18ecf0 {
    int x;
    int y;
    int z;
};

class Obj_18ecf0 {
  public:
    char pad[0x18];
    Vec3_18ecf0 v;
    bool Set(Vec3_18ecf0* p);
};

bool Obj_18ecf0::Set(Vec3_18ecf0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}
