struct Helper_dddc0 {
    void run(int, const float*);
};
class Obj_dddc0 {
  public:
    char pad[0x2230];
    Helper_dddc0* helper;
    void* stored;
    void f(void* a, void* b);
};
void Obj_dddc0::f(void* a, void* b) {
    helper->run(0x8fc, (const float*)0x27290);
    stored = b;
}