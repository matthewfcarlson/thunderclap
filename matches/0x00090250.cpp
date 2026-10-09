class C {
  public:
    char pad[0xc80];
    int count;
};
void* __fastcall FUN_00090250(C* self, void* edx, int index) {
    if (index >= 0 && index < self->count)
        return (char*)self + index * 0x40;
    return 0;
}