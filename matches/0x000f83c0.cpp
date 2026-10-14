class Obj_f83c0 {
  public:
    char pad[0x10];
    int initArg;
    int field14;
    char pad18[8];
    int field20;
};
extern void __stdcall Init(int, int);
Obj_f83c0* __fastcall Copy(Obj_f83c0* self, void*, Obj_f83c0* src) {
    Init(src->initArg, 0);
    self->field14 = src->field14;
    *(int*)self = *(int*)src;
    self->field20 = -1;
    return self;
}