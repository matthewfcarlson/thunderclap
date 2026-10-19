class X_1bc710 {
  public:
    void Run(void*);
};
extern X_1bc710* __cdecl Make();
void __stdcall target(void* a) {
    X_1bc710* x = Make();
    x->Run(a);
}