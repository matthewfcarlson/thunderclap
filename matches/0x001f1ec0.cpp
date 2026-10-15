class CSoundSystem {
  public:
    void Play(char*, char*, float, float, float, float);
};
class Closure6 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void**, void*);
    char pad[0x18];
    void (CSoundSystem::*fn)(char*, char*, float, float, float, float);
    CSoundSystem* obj;
};
void Closure6::vfunc_2(void*, void** a, void*) {
    char* x = (char*)*a++;
    char* y = (char*)*a++;
    float z = *(float*)a++;
    float w = *(float*)a++;
    float v = *(float*)a++;
    float u = *(float*)a++;
    (obj->*fn)(x, y, z, w, v, u);
}