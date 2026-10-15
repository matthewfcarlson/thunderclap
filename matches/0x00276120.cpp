namespace core {
class File {
  public:
    virtual void vfunc_17();
    char pad[8];
    void* ptr;
    int size;
};
} // namespace core
extern "C" void* __cdecl alloc(int);
class Obj {
  public:
    int init(core::File*);
};
class Manager {
  public:
    void finish(int, int, int);
};
void core::File::vfunc_17() {
    Obj* p = (Obj*)alloc(12);
    int v = p ? p->init(this) : 0;
    ((Manager*)ptr)->finish(v, size, 1);
}