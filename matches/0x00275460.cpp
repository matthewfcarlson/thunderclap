#include "decls/data/engine/core.h"
// data: g_buf = DAT_0052a1c8, g_holder = DAT_0052a1e4

extern void* g_vfFile[];
extern void* g_vfReq[];
class Sub_275460 {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_275460 {
  public:
    virtual void f0();
    virtual void f1();
    Sub_275460 sub;
    char pad[0x18 - 8];
    int cnt;
};
class Holder_275460 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
void Init(void*);
void Fini(void*);
class FileGetPositionRequest_275460 {
  public:
    void* vptr;
    int pad;
    Obj_275460* file;
    FileGetPositionRequest_275460* f0(unsigned char flags);
};
FileGetPositionRequest_275460* FileGetPositionRequest_275460::f0(unsigned char flags) {
    vptr = g_vfFile;
    file->sub.f0();
    --file->cnt;
    file->sub.f1();
    ((Sub_275460*)file)->f1();
    vptr = g_vfReq;
    if (flags & 1) {
        Init(((char*)&DAT_0052a1c8));
        (*(Holder_275460**)&DAT_0052a1e4)->e(this);
        Fini(((char*)&DAT_0052a1c8));
    }
    return this;
}
