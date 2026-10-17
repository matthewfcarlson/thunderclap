// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure6<CActorManager,bool,const_char_*,const_char_*,const_char_*,const_char_*,bool,const_char_*>::vfunc_2 @ 0x0002eb10
struct CActorManager {
    bool FUN_0002eb10(bool, const char*, const char*, const char*, const char*, bool, const char*);
};

struct Arguments {
    const char* first;
    const char* second;
    const char* third;
    const char* fourth;
    bool fifth;
    char padding[3];
    const char* sixth;
};

struct Closure6 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, const Arguments* arguments, bool* result);
    char reserved[0x18];
    bool (CActorManager::*method)(const char*, const char*, const char*, const char*, bool, const char*);
    CActorManager* object;
};

void Closure6::vfunc_2(int unused, const Arguments* arguments, bool* result) {
    bool value = (object->*method)(arguments->first, arguments->second, arguments->third, arguments->fourth, arguments->fifth, arguments->sixth);
    if (result) *result = value;
}
