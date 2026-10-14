extern "C" char DAT_0040eac0[];
extern void* __cdecl Alloc(unsigned int);
class LocatorDistanceCondition {
  public:
    LocatorDistanceCondition(int);
};
class Factory_11b060 {
  public:
    void* vtable;
    char pad[0x10];
    LocatorDistanceCondition* vfunc_5();
};
LocatorDistanceCondition* Factory_11b060::vfunc_5() {
    LocatorDistanceCondition* p = (LocatorDistanceCondition*)Alloc(0x14);
    if (p) {
        p->LocatorDistanceCondition::LocatorDistanceCondition(0);
        *(unsigned int*)p = ((int)DAT_0040eac0);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}