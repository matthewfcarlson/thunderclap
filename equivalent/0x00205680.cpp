// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_2 @ 0x00205680
struct CWorldStreamManager {};
struct Arguments { const char* name; int number; unsigned char flag; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_2(CWorldStreamManager* object, Arguments* arguments, void* unused);
    char padding[24];
    void (CWorldStreamManager::*method)(const char*, int, int);
};
void Method3::vfunc_2(CWorldStreamManager* object, Arguments* arguments, void* unused) {
    (object->*method)(arguments->name, arguments->number, arguments->flag);
}