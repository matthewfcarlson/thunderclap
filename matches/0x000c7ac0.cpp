class Target {
    char pad[0x20];

  public:
    unsigned char value;
    void __fastcall set() { value = 1; }
};
void __fastcall FUN_000c7ac0(Target* self) {
    self->value = 1;
}