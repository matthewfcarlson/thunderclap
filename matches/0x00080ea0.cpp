struct Vec3_80ea0 {
    int a, b, c;
};
class Obj_80ea0 {
  public:
    char pad0[0x28];
    unsigned int flags;
    char pad2[0xd0 - 0x2c];
    int x[6];
    void Set(Vec3_80ea0* p, Vec3_80ea0* q);
};
void Obj_80ea0::Set(Vec3_80ea0* p, Vec3_80ea0* q) {
    x[0] = p->a;
    x[1] = p->b;
    x[2] = p->c;
    x[3] = q->a;
    x[4] = q->b;
    x[5] = q->c;
    flags |= 0x20;
}