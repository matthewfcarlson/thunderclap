extern "C" char DAT_004e62d8[];
extern int g_vftable_24d380;
namespace om { class EntityLoader {
  public:
    int vptr;
    EntityLoader* vfunc_2(unsigned char);
}; }
extern void FUN_00247550(void*, om::EntityLoader*);
om::EntityLoader* om::EntityLoader::vfunc_2(unsigned char param) {
    vptr = (int)&g_vftable_24d380;
    if (param & 1)
        FUN_00247550((void*)((int)DAT_004e62d8), this);
    return this;
}