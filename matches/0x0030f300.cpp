extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj_30f300;
class Sub_30f300 {
  public:
    void Fn(Obj_30f300*);
};
class Temp_30f300 {
  public:
    void Fn(Obj_30f300*, Obj_30f300*);
    char data[0x40];
};
class Obj_30f300 {
  public:
    char pad[0x40];
    Sub_30f300 sub;
    char pad2[0x0c];
    int state;
    void Run(Obj_30f300*);
};
void Obj_30f300::Run(Obj_30f300* other) {
    Obj_30f300* owner = this;
    if (owner->state == 1) {
        owner->sub.Fn(owner);
        owner->state = 0;
    }
    if (other->state == 1) {
        other->sub.Fn(other);
        other->state = 0;
    }
    Temp_30f300 t;
    t.Fn(owner, other);
    memcpy(owner, &t, 0x40);
    owner->state = 2;
}