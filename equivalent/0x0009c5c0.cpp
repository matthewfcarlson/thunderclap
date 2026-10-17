// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CCameraManager,void,bool,bool,bool>::vfunc_2 @ 0x0009c5c0
struct CCameraManager { void invoke(unsigned int, unsigned int, unsigned int); };
struct BoolArgs { unsigned char first; char pad1[3]; unsigned char second; char pad2[3]; unsigned char third; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, BoolArgs *args, int unused2);
    char padding[0x18];
    void (CCameraManager::*method)(unsigned int, unsigned int, unsigned int);
    CCameraManager *object;
};
void Closure3::vfunc_2(int unused, BoolArgs *args, int unused2)
{
    unsigned int first = (reinterpret_cast<unsigned int>(args) & ~255u) | args->first;
    (object->*method)(first, args->second, args->third);
}
