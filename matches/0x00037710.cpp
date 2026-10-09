class Obj {
  public:
    char pad[0x1c];
    int value;
    int a;
    int b;
    void init();
    void set(const float*);
};
extern const float zero;
Obj* __fastcall target(Obj* self) {
    self->init();
    self->value = (int)0xbf800000;
    self->set(&zero);
    self->pad[8] = (char)0xff;
    self->pad[9] = (char)0xff;
    self->a = 0;
    self->b = 0;
    return self;
}