class CHapticControllerManager {
  public:
    void Run(int, float, float, float);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, int*, void*);
};
class Closure4 : public Function {
    char pad[24];
    void (CHapticControllerManager::*method)(int, float, float, float);
    CHapticControllerManager* object;

  public:
    virtual void vfunc_2(void*, int*, void*);
};
void Closure4::vfunc_2(void*, int* args, void*) {
    int a = *args;
    float b = *(float*)++args;
    args++;
    float c = *(float*)args;
    float d = *(float*)(args + 1);
    (object->*method)(a, b, c, d);
}