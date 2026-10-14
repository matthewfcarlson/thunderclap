// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FEThingsBase::vfunc_8 @ 0x000e83a0
class Widget {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int a, int b);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
};

class FEThingsBase {
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
    char pad04[0x175c - 4];
    Widget* header;         // 0x175c
    char pad1760[0x1a5c - 0x1760];
    Widget* arrows[2];      // 0x1a5c
    char pad1a64[0x2074 - 0x1a64];
    char arrowsVisible;     // 0x2074
    char pad2075[0x2080 - 0x2075];
    Widget* items[32];      // 0x2080
    char pad2100[0x2218 - 0x2100];
    Widget* footer;         // 0x2218
};

void FEThingsBase::vfunc_8()
{
    // the item list is terminated by the first empty slot
    for (int i = 0; i < 32 && items[i]; i++)
        items[i]->vfunc_3();
    if (arrowsVisible) {
        for (int i = 0; i < 2; i++) {
            if (arrows[i])
                arrows[i]->vfunc_8(0, 0);
        }
    }
    if (header)
        header->vfunc_11();
    if (footer)
        footer->vfunc_11();
}
