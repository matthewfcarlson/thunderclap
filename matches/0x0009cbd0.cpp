class CCameraManager {
  public:
    void Action(int, float, float, float);
};
class Closure4 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, int*, int);
    char pad[0x18];
    void (CCameraManager::*fn)(int, float, float, float);
    CCameraManager* obj;
};
void Closure4::vfunc_2(int, int* p, int) {
    int a = *p++;
    float b = *(float*)p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    (obj->*fn)(a, b, c, d);
}