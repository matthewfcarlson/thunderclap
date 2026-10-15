extern "C" void __cdecl qsort(void*, unsigned int, unsigned int, int(__cdecl*)(const void*, const void*));
int __cdecl compare(const void*, const void*);
class Item {
  public:
    virtual void fn();
};
class FEContainer {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    char pad[0x4c - 4];
    Item* items[128];
    Item* sorted[128];
};
void FEContainer::vfunc_9() {
    int i = 0;
    do {
        if (!items[i])
            break;
        items[i]->fn();
        ++i;
    } while (i < 128);
    for (int j = 0; j < 128; ++j)
        sorted[j] = items[j];
    qsort(sorted, 128, 4, compare);
}