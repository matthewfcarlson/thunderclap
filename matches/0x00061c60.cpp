struct Vec3 {
    int x, y, z;
};

class Thing {
  public:
    char pad[0xb8];
    Vec3 v;
    bool Fn(Vec3* p);
};

bool Thing::Fn(Vec3* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}
