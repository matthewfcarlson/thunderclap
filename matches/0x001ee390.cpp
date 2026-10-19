struct CSoundRealTimeManager {};
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(char*, char* volatile*, char*);
    char padding[0x18];
    void (CSoundRealTimeManager::*method)(char*, char*, char*);
    CSoundRealTimeManager* object;
};
void Closure3::vfunc_2(char*, char* volatile* args, char*) {
    char* a = args[0];
    (object->*method)(a, args[1], args[2]);
}