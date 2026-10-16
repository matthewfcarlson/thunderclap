// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CRenderManager::vfunc_1 @ 0x001b8ee0
#include "gen/global.h"

struct Vec3_1b8ee0 { float x,y,z; };
struct Reader_1b8ee0 { const char* FUN_003365b0(const char*); void FUN_00336600(const char*,float*,float*,float*); };
struct CRenderManager_nv_1b8ee0 {
    void FUN_001b8dc0(const char*,Vec3_1b8ee0,Vec3_1b8ee0,float);
};

bool CRenderManager::vfunc_1(void* __p0) { Reader_1b8ee0 * reader = (Reader_1b8ee0 *)__p0;

 Reader_1b8ee0* source=reader;
 const char* name=source->FUN_003365b0("Name");
 struct Scratch {float tz,rx,ry,tx,ty,sx,sz,sy;} s;
 source->FUN_00336600("translate",&s.tx,&s.ty,&s.tz);
 source->FUN_00336600("rotate",&s.rx,&s.ry,reinterpret_cast<float*>(&reader));
 source->FUN_00336600("scale",&s.sx,&s.sy,&s.sz);
 Vec3_1b8ee0 t,r;
 t.x=s.tx; t.y=s.ty; t.z=-s.tz;
 r.x=s.rx*-0.01745329238474369f;
 r.y=s.ry*-0.01745329238474369f;
 r.z=*reinterpret_cast<float*>(&reader)*0.01745329238474369f;
 ((CRenderManager_nv_1b8ee0*)this)->FUN_001b8dc0(name,t,r,s.sx);
 return true;
}
