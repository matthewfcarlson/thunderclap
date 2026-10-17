// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure6<CCameraManager,void,int,int,float,int,int,float>::vfunc_2 @ 0x0009c960
struct CCameraManager { void FUN_0009c960(int, int, float, int, int, float); };
struct Arguments { int first; int second; float third; int fourth; int fifth; float sixth; };
class Closure6 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, Arguments *arguments, int unused2);
    char padding[24];
    void (CCameraManager::*method)(int, int, float, int, int, float);
    CCameraManager *object;
};
void Closure6::vfunc_2(int unused, Arguments *arguments, int unused2) {
    (object->*method)(arguments->first, arguments->second, arguments->third, arguments->fourth, arguments->fifth, arguments->sixth);
}