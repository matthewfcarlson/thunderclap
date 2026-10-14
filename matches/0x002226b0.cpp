class Target_2226b0 {
  public:
    char pad[0x64];
    struct Inner {
        char pad[8];
        int value;
    }* member;
};
int __fastcall FUN_002226b0(Target_2226b0* self) {
    return self->member->value;
}