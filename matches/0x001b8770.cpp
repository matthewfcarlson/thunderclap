extern "C" void* __cdecl FUN_001c3d90();
class A_1b8770 {
  public:
    void Fn();
};
struct R_1b8770 {
    A_1b8770* p;
};
void FUN_001b8770() {
    R_1b8770* r = (R_1b8770*)FUN_001c3d90();
    r->p->Fn();
}
