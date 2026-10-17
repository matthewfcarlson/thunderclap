// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 @ 0x000cfae0
struct HUDOverlay {
    int FUN_000cfae0(const char *, const char *, float);
};
struct Arguments {
    const char *first;
    const char *second;
    float third;
};
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *args, int *result);
    char padding[0x18];
    int (HUDOverlay::*method)(const char *, const char *, float);
    HUDOverlay *object;
};
void Closure3::vfunc_2(void *unused, Arguments *args, int *result) {
    const char *first = args->first;
    const char *second = args->second;
    float third = args->third;
    int value = (object->*method)(first, second, third);
    if (result) *result = value;
}