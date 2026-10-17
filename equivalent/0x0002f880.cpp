// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure5<CActorManager,void,const_char_*,const_char_*,float,float,float>::vfunc_2 @ 0x0002f880
struct CActorManager {};
struct Arguments { const char* first; const char* second; float third; float fourth; float fifth; };
struct Closure5 {
    char pad[0x1c];
    void (CActorManager::*method)(const char*, const char*, float, float, float);
    CActorManager* actor;
    void vfunc_2(int unused, const Arguments* args, int unused2);
};
void Closure5::vfunc_2(int, const Arguments* args, int) {
    (actor->*method)(args->first, args->second, args->third, args->fourth, args->fifth);
}
