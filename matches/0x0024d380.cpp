extern "C" char DAT_004e62d8[];
extern int g_vftable;
class EntityLoader {
  public:
    int vptr;
    EntityLoader* vfunc_2(unsigned char);
};
extern void FUN_00247550(void*, EntityLoader*);
EntityLoader* EntityLoader::vfunc_2(unsigned char param) {
    vptr = (int)&g_vftable;
    if (param & 1)
        FUN_00247550((void*)((int)DAT_004e62d8), this);
    return this;
}