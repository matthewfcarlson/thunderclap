class Obj_1eecb0 {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    int d;
    float value;
};

extern "C" void __fastcall FUN_0027af00(void*);

Obj_1eecb0* __fastcall FUN_001eecb0(Obj_1eecb0* self) {
    FUN_0027af00((void*)(self));
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->value = 100.0f;
    return self;
}