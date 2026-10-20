class CSoundSystem;
typedef void (CSoundSystem::*SoundMethod)(char*, char*, float, float, float);
class CSoundSystem {
  public:
    void dummy();
};
class Closure5 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, unsigned*, void*);
    char reserved[0x18];
    SoundMethod method;
    CSoundSystem* object;
};
void Closure5::vfunc_2(void*, unsigned* args, void*) {
    char* first = (char*)*args;
    char* second = (char*)*++args;
    float third = *(float*)++args;
    float fourth = *(float*)++args;
    float fifth = *(float*)++args;
    (object->*method)(first, second, third, fourth, fifth);
}