extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj_221df0;
class Sub_221df0 {
  public:
    void Fn(Obj_221df0*);
};
class Obj_221df0 {
  public:
    char pad[0x40];
    Sub_221df0 sub;
    char pad44[0x0c];
    int state;
    char pad54[0x2c];
    void Run(Obj_221df0*);
};
class Tmp_221df0 {
  public:
    char data[0x40];
    void Make(Obj_221df0*, Obj_221df0*);
};
void Obj_221df0::Run(Obj_221df0* other) {
    Obj_221df0* self = this;
    if (self->state == 1) {
        self->sub.Fn(self);
        self->state = 0;
    }
    if (other->state == 1) {
        other->sub.Fn(other);
        other->state = 0;
    }
    Tmp_221df0 tmp;
    tmp.Make(self, other);
    memcpy(self, &tmp, 0x40);
    self->state = 2;
}