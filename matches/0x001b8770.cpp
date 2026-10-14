extern "C" void* __cdecl FUN_001c3d90();
class A {
  public:
    void Fn();
};
struct R {
    A* p;
};
void FUN_001b8770() {
    R* r = (R*)FUN_001c3d90();
    r->p->Fn();
}
