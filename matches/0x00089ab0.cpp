class Target {
    char pad[0xabf];

  public:
    char field;
};
void __fastcall FUN_00089ab0(Target* self) {
    self->field = 1;
}