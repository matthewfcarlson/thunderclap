extern "C" void _ReadWriteBarrier();
class Obj;
class Elem {
  public:
    void Reset(Obj*);
    void Blend(Elem*, Elem*, float);
};
class Obj {
  public:
    void Fn(Obj*, float);
    char pad0[0x30];
    float x, y, z;
    char pad3c[4];
    Elem elem;
    char pad44[0xc];
    int state;
};
void Obj::Fn(Obj* other, float t) {
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
