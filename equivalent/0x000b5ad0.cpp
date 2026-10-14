// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000b5ad0 @ 0x000b5ad0
extern "C" char DAT_0049dba4[];
extern "C" char DAT_0049dbbc[];
extern char DAT_004dd83a;
extern char DAT_004dd83b;
extern void* __cdecl FUN_000fc260(const char* name);
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

class Selector_b5ad0 {
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int selected);
};

// Syncs the two camera-invert selectors with the stored flags.
void FUN_000b5ad0()
{
    Selector_b5ad0* x = (Selector_b5ad0*)FUN_00344e74(FUN_000fc260("camera_invert_x_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (x)
        x->vfunc_25(DAT_004dd83a == 0);
    Selector_b5ad0* y = (Selector_b5ad0*)FUN_00344e74(FUN_000fc260("camera_invert_y_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (y)
        y->vfunc_25(DAT_004dd83b == 0);
}
