extern "C" char DAT_0042ec20[];
class Texture {
  public:
    int v;
    char pad[12];
    int field10;
};
void Init();
Texture* __fastcall FUN_002c1c30(Texture* self) {
    Init();
    self->v = ((int)DAT_0042ec20);
    self->field10 = 0;
    return self;
}