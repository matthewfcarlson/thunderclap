struct Vec {
    int x, y, z;
};

class Obj {
  public:
    char pad[0x28];
    int a, b, c;
    char Set(Vec* v);
};

char Obj::Set(Vec* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}
