struct Vec_1335b0 {
    int x, y, z;
};

class Obj_1335b0 {
  public:
    char pad[0x28];
    int a, b, c;
    char Set(Vec_1335b0* v);
};

char Obj_1335b0::Set(Vec_1335b0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}
