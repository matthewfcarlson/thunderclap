extern "C" void* __cdecl FUN_0008d690(unsigned int);
class A {
  public:
    void* Fn(void* a);
};
void* __cdecl FUN_003280d0(void* a) {
    A* p = (A*)FUN_0008d690(0x90);
    if (p)
        return p->Fn(a);
    return 0;
}