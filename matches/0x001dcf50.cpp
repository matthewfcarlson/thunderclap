class CGrabAction {
    char pad[0x1e820];

  public:
    int value;
};
extern "C" int __fastcall FUN_001dcf50(CGrabAction* self) {
    return self->value;
}