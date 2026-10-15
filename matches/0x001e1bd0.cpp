class CSPManager {
  public:
    void Fn(int, float, float, float, const char*);
};
class Closure {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, int*, int);
    char pad[24];
    void (CSPManager::*method)(int, float, float, float, const char*);
    CSPManager* obj;
};
void Closure::vfunc_2(int unused, int* args, int other) {
    int a = *args++;
    float b = *(float*)args++;
    float c = *(float*)args++;
    float d = *(float*)args++;
    const char* e = (const char*)*args++;
    (obj->*method)(a, b, c, d, e);
}