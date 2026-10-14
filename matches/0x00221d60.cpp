extern "C" void _ReadWriteBarrier();
class Obj_221d60;
class Elem_221d60 {
  public:
    void Reset(Obj_221d60*);
    void Blend(Elem_221d60*, Elem_221d60*, float);
};
class Obj_221d60 {
  public:
    void Fn(Obj_221d60*, float);
    char pad0[0x30];
    float x, y, z;
    char pad3c[4];
    Elem_221d60 elem;
    char pad44[0xc];
    int state;
};
void Obj_221d60::Fn(Obj_221d60* other, float t) {
    x = (other->x - x) * t + x;
    y = (other->y - y) * t + y;
    z = (other->z - z) * t + z;

    _ReadWriteBarrier();
    int s = *(volatile int*)&state;
    if (s == 2) {
        elem.Reset(this);
        state = 0;
    }
    if (other->state == 2) {
        other->elem.Reset(other);
        other->state = 0;
    }
    elem.Blend(&elem, &other->elem, t);
    state = 1;
}
