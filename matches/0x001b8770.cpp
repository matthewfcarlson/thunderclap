extern "C" void* __cdecl FUN_001c3d90();
class A_1b8770 {
  public:
    void Fn(int);
};
struct R_1b8770 {
    A_1b8770* p;
};
void __stdcall FUN_001b8770(int a) {
    R_1b8770* r = (R_1b8770*)FUN_001c3d90();
    r->p->Fn(a);
}
