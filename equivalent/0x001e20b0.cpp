// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,const_char_*,const_char_*,math::Vector>::vfunc_2 @ 0x001e20b0
struct Vector { float x, y, z; };
struct CSPManager {
    void FUN_001e20b0(const char *, const char *, Vector);
};
struct Arguments {
    const char *first;
    const char *second;
    Vector position;
};
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const Arguments *, void *);
    char pad[0x18];
    void (CSPManager::*method)(const char *, const char *, Vector);
    CSPManager *manager;
};
void Closure3::vfunc_2(void *, const Arguments *arguments, void *) {
    (manager->*method)(arguments->first, arguments->second, arguments->position);
}
