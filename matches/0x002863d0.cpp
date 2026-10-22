extern void* vFCL[];
extern void* vIRef[];
class Ref_2863d0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct FrameControllerLoader_2863d0 {
    void* vf;
    char pad[0x14];
    Ref_2863d0* arr[4];
    void Dtor() throw();
};
void FrameControllerLoader_2863d0::Dtor() throw() {
    vf = vFCL;
    Ref_2863d0** p = arr;
    for (int i = 4; i; --i) {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        ++p;
    }
    vf = vIRef;
}
