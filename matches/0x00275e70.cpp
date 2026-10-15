namespace core {
class File {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad[8];
    void* context;
    int value;
};
} // namespace core
class Alloc {
  public:
    int Init(core::File*);
};
extern "C" void* __cdecl Allocate(int);
class Context {
  public:
    void Set(int, int, int);
};
void core::File::vfunc_8() {
    Alloc* a = (Alloc*)Allocate(12);
    int x = a ? a->Init(this) : 0;
    ((Context*)context)->Set(x, value, 0);
}