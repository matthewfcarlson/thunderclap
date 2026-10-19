// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_001bc710 @ 0x001bc710
class X_1bc710 {
  public:
    void Run(void*);
};
extern X_1bc710* __cdecl Make();
void __stdcall target(void* a) {
    Make()->Run(a);
}