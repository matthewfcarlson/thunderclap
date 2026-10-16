void* __cdecl alloc(unsigned int);
class Mesh {
  public:
    Mesh* Init(int) throw();
};
class ShadowMeshBufferLoader {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual Mesh* vfunc_6(int);
};
Mesh* ShadowMeshBufferLoader::vfunc_6(int x) {
    Mesh* p = (Mesh*)alloc(0x58);
    if (p)
        return p->Init(x);
    return 0;
}
