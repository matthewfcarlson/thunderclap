// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<HUDOverlay,int,int,const_char_*>::vfunc_2 @ 0x000cfe20
struct HUDOverlay {
    int FUN_000cfe20(int value, const char *text);
};
struct Arguments {
    int value;
    const char *text;
};
class Closure2_HUDOverlay {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *arguments, int *result);
private:
    char padding[0x18];
    int (HUDOverlay::*method)(int, const char *);
    HUDOverlay *object;
};
void Closure2_HUDOverlay::vfunc_2(void *unused, Arguments *arguments, int *result)
{
    int value = (object->*method)(arguments->value, arguments->text);
    if (result)
        *result = value;
}
