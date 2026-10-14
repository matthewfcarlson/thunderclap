struct Vec3_5a1b0 {
    int x;
    int y;
    int z;
};

class Obj_5a1b0 {
  public:
    char pad[0x48];
    int m48;
    int m4c;
    int m50;
    bool Set(const Vec3_5a1b0* v);
};

bool Obj_5a1b0::Set(const Vec3_5a1b0* v) {
    m48 = v->x;
    m4c = v->y;
    m50 = v->z;
    return true;
}
