// Same code shape as 0x00048520 (propagated; names are from that function)
extern int g_vft_48790;
class CButtonValueCondition {
  public:
    int vf;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
};
extern void __stdcall FUN_00234590(int);
CButtonValueCondition* __fastcall FUN_00048520(CButtonValueCondition* self) {
    FUN_00234590(0);
    self->x4 = 4;
    self->x6 = 4;
    self->x3 = 0;
    self->x5 = 0;
    self->vf = (int)&g_vft_48790;
    self->x7 = 0;
    return self;
}