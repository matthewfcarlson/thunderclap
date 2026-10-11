extern void* vFCL[];
extern void* vIRef[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Target {
    void* vf;
    char pad[0x14];
    Ref* arr[4];
    void Dtor() throw();
};
void Target::Dtor() throw() {
    vf = vFCL;
    Ref** p = arr;
    for (int i = 4; i; --i) {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        ++p;
    }
    vf = vIRef;
}
