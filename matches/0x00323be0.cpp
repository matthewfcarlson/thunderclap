#include "gen/pure3d.h"

class Obj_323be0 {
  public:
    virtual void Init();
    Obj_323be0* Create(void*, int);
    void Attach(unsigned int*);
};
void* __cdecl Allocate(unsigned int);
unsigned int* __stdcall GetBackBuffer(int);

void* pure3d::d3dExtFrameBufferTexture::vfunc_1(int param) {
    if (!(*(Obj_323be0 * *)&this->f_08)) {
        Obj_323be0* p = (Obj_323be0*)Allocate(0xf8);
        Obj_323be0* r;
        if (p)
            r = p->Create((*(void * *)&this->f_04), 0);
        else
            r = 0;
        (*(Obj_323be0 * *)&this->f_08) = r;
        r->Init();
        unsigned int* b = GetBackBuffer(param ? 0 : -1);
        (*(unsigned int * *)&this->f_0c) = b;
        unsigned int o = *b;
        this->f_10 = o;
        *b = (o & 0xfffcffff) | 0x40000;
        (*(Obj_323be0 * *)&this->f_08)->Attach((*(unsigned int * *)&this->f_0c));
    }
    return (void*)((*(Obj_323be0 * *)&this->f_08));
}
