extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj;
class Sub {
  public:
    void Fn(Obj*);
};
class Temp {
  public:
    void Fn(Obj*, Obj*);
    char data[0x40];
};
class Obj {
  public:
    char pad[0x40];
    Sub sub;
    char pad2[0x0c];
    int state;
    void Run(Obj*);
};
void Obj::Run(Obj* other) {
    Obj* owner = this;
    if (owner->state == 1) {
        owner->sub.Fn(owner);
        owner->state = 0;
    }
    if (other->state == 1) {
        other->sub.Fn(other);
        other->state = 0;
    }
    Temp t;
    t.Fn(owner, other);
    memcpy(owner, &t, 0x40);
    owner->state = 2;
}