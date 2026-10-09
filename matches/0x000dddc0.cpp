struct Helper {
    void run(int, const float*);
};
class Obj {
  public:
    char pad[0x2230];
    Helper* helper;
    void* stored;
    void f(void* a, void* b);
};
void Obj::f(void* a, void* b) {
    helper->run(0x8fc, (const float*)0x27290);
    stored = b;
}