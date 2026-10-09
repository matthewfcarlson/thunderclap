class Thing {
  public:
    char pad[0x14];
    int a;
    char pad2[8];
    int b;
};
void __fastcall FUN_000f7110(Thing* self) {
    self->a = 0;
    self->b = 0;
}