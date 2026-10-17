// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 @ 0x000cec00
struct HUDOverlay {
    int FUN_000cec00(int a, const char *b, const char *c);
};
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(HUDOverlay *object, unsigned int *arguments, int *result);
    char padding[0x1c - 4];
    int (HUDOverlay::*method)(int, const char *, const char *);
};
void Method3::vfunc_2(HUDOverlay *object, unsigned int *arguments, int *result) {
    int value = (object->*method)(arguments[0], (const char *)arguments[1], (const char *)arguments[2]);
    if (result) *result = value;
}
