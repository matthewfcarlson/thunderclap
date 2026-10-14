struct Vec3_60450 {
    int x, y, z;
};

class Obj_60450 {
  public:
    char pad[0x38];
    int a;
    int b;
    int c;
    bool Set(const Vec3_60450* v);
};

bool Obj_60450::Set(const Vec3_60450* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}