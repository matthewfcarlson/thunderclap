extern void* vtController;
extern void* vtDolly;
void __cdecl Release(void*);
class ControllerState_dd7a0 {
  public:
    void* vt;
    char pad[8];
    void* a;
    void* b;
    void Clear();
};
void ControllerState_dd7a0::Clear() {
    vt = &vtController;
    if (a) {
        Release(a);
        a = 0;
    }
    if (b) {
        Release(b);
        b = 0;
    }
    vt = &vtDolly;
}