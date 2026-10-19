class Obj_1eecb0 {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    int d;
    float value;
};

void __fastcall BaseInit(void*);

Obj_1eecb0* __fastcall FUN_001eecb0(Obj_1eecb0* self) {
    BaseInit((void*)(self));
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->value = 100.0f;
    return self;
}