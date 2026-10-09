class Obj {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    int d;
    float value;
};

void BaseInit();

Obj* __fastcall FUN_001eecb0(Obj* self) {
    BaseInit();
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->value = 100.0f;
    return self;
}