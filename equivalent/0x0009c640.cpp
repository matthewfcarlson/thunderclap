// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,bool,bool,bool,float>::vfunc_2 @ 0x0009c640
struct CCameraManager { void FUN_0009c640(unsigned int, unsigned int, unsigned int, float); };
struct Arguments { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; char pad2[3]; float fourth; };
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, Arguments *arguments, int unused2);
    char reserved[0x18];
    void (CCameraManager::*method)(unsigned int, unsigned int, unsigned int, float);
    CCameraManager *manager;
};
void Closure4::vfunc_2(int unused, Arguments *arguments, int unused2) {
    unsigned int first = (reinterpret_cast<unsigned int>(this) & 0xffffff00u) | arguments->first;
    unsigned int second = (reinterpret_cast<unsigned int>(arguments) & 0xffffff00u) | arguments->second;
    (manager->*method)(first, second, arguments->third, arguments->fourth);
}