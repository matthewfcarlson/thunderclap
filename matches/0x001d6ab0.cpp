class Target {
    char pad[0x111];

  public:
    unsigned char value;
};
unsigned char __fastcall FUN_001d6ab0(Target* self) {
    return self->value;
}