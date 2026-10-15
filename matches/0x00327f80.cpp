void* __cdecl Alloc(int n);
class O {
  public:
    int M(int a);
};
int __cdecl FUN_00327f80(int a) {
    O* p = (O*)Alloc(0x9c);
    if (p)
        return p->M(a);
    return 0;
}
