class Obj {
  public:
    char pad[0x10];
    int initArg;
    int field14;
    char pad18[8];
    int field20;
};
extern void __stdcall Init(int, int);
Obj* __fastcall Copy(Obj* self, void*, Obj* src) {
    Init(src->initArg, 0);
    self->field14 = src->field14;
    *(int*)self = *(int*)src;
    self->field20 = -1;
    return self;
}