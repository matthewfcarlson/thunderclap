class CSPManager {
  public:
    void Fn(int, float, float, float, float, int);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int, void*, int);
};
class Closure6 : public Function {
  public:
    char pad[0x18];
    void (CSPManager::*fn)(int, float, float, float, float, int);
    CSPManager* obj;
    virtual void v2(int, void*, int);
};
void Closure6::v2(int x, void* arg, int y) {
    int* p = (int*)arg;
    int a = *p++;
    float b = *(float*)p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    float e = *(float*)p++;
    int f = *p++;
    (obj->*fn)(a, b, c, d, e, f);
}