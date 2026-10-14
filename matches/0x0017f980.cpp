struct Vec3_17f980 {
    int x, y, z;
};

class Obj_17f980 {
  public:
    char pad[0x1c];
    int a;
    int b;
    int c;
    bool Set(Vec3_17f980* v);
};

bool Obj_17f980::Set(Vec3_17f980* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
