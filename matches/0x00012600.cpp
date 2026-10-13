class Target {
  public:
    char pad[0xb4];
    int value;
};

int __fastcall FUN_00012600(Target* self) {
    return self->value;
}
