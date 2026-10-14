class C_90250 {
  public:
    char pad[0xc80];
    int count;
};
void* __fastcall FUN_00090250(C_90250* self, void* edx, int index) {
    if (index >= 0 && index < self->count)
        return (char*)self + index * 0x40;
    return 0;
}