class Obj_1d7300 {
  public:
    char pad[0xa0];
    void* a;
};
int __fastcall FUN_001d7300(Obj_1d7300* self) {
    void* p = self->a;
    if (p && *(void**)((char*)p + 0x10) && *(void**)((char*)*(void**)((char*)p + 0x10) + 0x70))
        return 1;
    return 0;
}