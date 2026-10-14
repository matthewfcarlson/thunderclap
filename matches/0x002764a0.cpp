extern void* file_vft;
extern void* file_vft4;
extern void* ref_vft;

class Sub_2764a0 {
  public:
    void fin();
};
class Ref_2764a0 {
  public:
    virtual void x();
    virtual void y();
};

class File {
  public:
    void* vp;
    void* vp4;
    int f8;
    Ref_2764a0* r;
    char pad[0x11c];
    Sub_2764a0 sub;
    void vfunc_21();
    void shutdown();
};

void File::shutdown() {
    *(void**)this = &file_vft;
    *((void**)this + 1) = &file_vft4;
    vfunc_21();
    r->y();
    sub.fin();
    *(void**)this = &ref_vft;
}
