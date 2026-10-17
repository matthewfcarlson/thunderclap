// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,int>::vfunc_2 @ 0x001e1560
struct CSPManager {};
struct Arguments { const char* text; int number; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, Arguments* args, bool* result);
    char padding[24];
    bool (CSPManager::*method)(const char*, int);
    CSPManager* object;
};
void Closure2::vfunc_2(void* unused, Arguments* args, bool* result) {
    bool value = (object->*method)(args->text, args->number);
    if (result) *result = value;
}
