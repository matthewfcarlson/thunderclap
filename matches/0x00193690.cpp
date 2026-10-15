struct Vec3 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

class Obj {
  public:
    char pad[0x118];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool Set(Vec3* v);
};

bool Obj::Set(Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
