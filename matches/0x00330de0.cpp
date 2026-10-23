#include "compat/ptr.h"
#include "gen/pure3d.h"
struct Desc_330de0 {
    int format;
    char pad[24];
};
extern "C" int __stdcall GetBackBuffer2(int);
extern "C" void __stdcall GetDesc(int, Desc_330de0*);
extern "C" void __stdcall Release(int);
extern "C" int __stdcall CreateTexture2(int, int, int, int, int, int, int);
extern "C" hulk_intptr Alloc(hulk_intptr);
struct Obj_330de0 {
    virtual void Fn();
};
struct d3dTexture_nv_330de0 {
    Obj_330de0* Build(int, int);
};
class d3dToonVertexShader_330de0 {
    char pad[0x10];

  public:
    int m;
    char pad2[0x80];
    Obj_330de0* texture;
    void Update();
    void Tail();
};
void d3dToonVertexShader_330de0::Update() {
    if (texture == 0) {
        int s = GetBackBuffer2(0);
        Desc_330de0 d;
        GetDesc(s, &d);
        Release(s);
        int t = CreateTexture2(0x40, 1, 1, 1, 0, d.format, 3);
        Obj_330de0* o = (Obj_330de0*)Alloc(0xf8);
        if (o)
            o = ((d3dTexture_nv_330de0*)(((pure3d::d3dTexture*)(((pure3d::d3dTexture*)o)))))->Build(m, t);
        else
            o = (Obj_330de0*)0;
        texture = o;
        o->Fn();
        Tail();
    }
}