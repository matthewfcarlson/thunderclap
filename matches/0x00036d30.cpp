class Target {
    char pad[0x20f8];
};
Target* __fastcall FUN_00036d30(Target* self) {
    return (Target*)((char*)self + 0x20f8);
}