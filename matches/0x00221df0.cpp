extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj;
class Sub {
  public:
    void Fn(Obj*);
};
class Obj {
  public:
    char pad[0x40];
    Sub sub;
    char pad44[0x0c];
    int state;
    char pad54[0x2c];
    void Run(Obj*);
};
class Tmp {
  public:
    char data[0x40];
    void Make(Obj*, Obj*);
};
void Obj::Run(Obj* other) {
    Obj* self = this;
    if (self->state == 1) {
        self->sub.Fn(self);
        self->state = 0;
    }
    if (other->state == 1) {
        other->sub.Fn(other);
        other->state = 0;
    }
    Tmp tmp;
    tmp.Make(self, other);
    memcpy(self, &tmp, 0x40);
    self->state = 2;
}