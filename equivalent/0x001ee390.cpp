// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSoundRealTimeManager,void,char_*,char_*,char_*>::vfunc_2 @ 0x001ee390
struct CSoundRealTimeManager { };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(char*, char**, char*);
    char padding[0x18];
    void (CSoundRealTimeManager::*method)(char*, char*, char*);
    CSoundRealTimeManager* object;
};
void Closure3::vfunc_2(char*, char** args, char*) {
    (object->*method)(args[0], args[1], args[2]);
}