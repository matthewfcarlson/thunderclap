struct Vec3_1a2020 {
    int x, y, z;
};

class Obj_1a2020 {
  public:
    char pad[0x38];
    int v38, v3c, v40;
    bool Set(Vec3_1a2020* v);
};

bool Obj_1a2020::Set(Vec3_1a2020* v) {
    v38 = v->x;
    v3c = v->y;
    v40 = v->z;
    return true;
}
