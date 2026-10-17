// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001e1dc0
struct Vector { float x, y, z; };
struct Arguments { const char *name; Vector position; };
struct CSPManager {};
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const Arguments *arguments, bool *result);
    char padding[0x18];
    bool (CSPManager::*method)(const char *, Vector);
    CSPManager *object;
};
void Closure2::vfunc_2(void *unused, const Arguments *arguments, bool *result) {
    bool value = (object->*method)(arguments->name, arguments->position);
    if (result) *result = value;
}