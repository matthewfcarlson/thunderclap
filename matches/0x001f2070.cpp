class CSoundSystem {
  public:
    void Play(char*, char*, char*, float, float, float);
};
class Closure6 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(int, unsigned*, int);
    char pad[24];
    void (CSoundSystem::*method)(char*, char*, char*, float, float, float);
    CSoundSystem* obj;
};
void Closure6::vfunc_2(int, unsigned* x, int) {
    char* a = (char*)*x++;
    char* b = (char*)*x++;
    char* c = (char*)*x++;
    float d = *(float*)x++;
    float e = *(float*)x++;
    float f = *(float*)x++;
    (obj->*method)(a, b, c, d, e, f);
}