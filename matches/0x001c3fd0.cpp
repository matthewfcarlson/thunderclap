struct Core_1c3fd0 {
    void Init(void*, int, int, int, int);
    void Finish();
};
class Obj_1c3fd0 {
  public:
    Core_1c3fd0* core;
    char pad[0x18];
    int field1;
    char pad2[0x3c];
    int field5c;
    int field60;
    int field64;
    int field68;
    unsigned char flag6c;
};
void __fastcall Target(Obj_1c3fd0* self) {
    if (!self->flag6c) {
        self->core->Init(&self->field1, self->field5c, self->field60, self->field64, self->field68);
        self->flag6c = 1;
    }
    self->core->Finish();
}