class CHapticControllerManager {
  public:
    void Action(int, float, float, float);
};
class Function {
  public:
    virtual void F0();
    virtual void F1();
};
class Method4 : public Function {
  public:
    virtual void F0();
    virtual void F1();
    virtual void vfunc_2(CHapticControllerManager*, void*, void*);
    char pad[0x18];
    void (CHapticControllerManager::*method)(int, float, float, float);
};
void Method4::vfunc_2(CHapticControllerManager* obj, void* args, void* unused) {
    char* p = (char*)args;
    int a = *(int*)p;
    p += 4;
    float b = *(float*)p;
    p += 4;
    float c = *(float*)p;
    float d = *(float*)(p + 4);
    (obj->*method)(a, b, c, d);
}