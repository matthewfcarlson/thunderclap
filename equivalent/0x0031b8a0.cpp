// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 6/6)
// pure3d::d3dDevice::vfunc_9 @ 0x0031b8a0
#include "gen/pure3d.h"

void* __cdecl FUN_0008d690(unsigned int);
struct Params_31b8a0 { int a,b,c,d,e,f,g,h; unsigned char extended; };
struct d3dTexture_31b8a0 {
 virtual void slot0();
 virtual void slot1();
 virtual int slot2();
 virtual void slot3(int);
 d3dTexture_31b8a0* FUN_00326b40(void*);
 bool FUN_003265f0(int,int,int,int,int,int,int,int);
 bool FUN_00326330(int,int,int,int,int,int,int);
};
namespace pure3d {

}
void* pure3d::d3dDevice::vfunc_9(int __p0) { Params_31b8a0 * p = (Params_31b8a0 *)__p0;

 d3dTexture_31b8a0* s = (d3dTexture_31b8a0*)FUN_0008d690(0xf8);
 if(s) s=s->FUN_00326b40((*(void * *)&this->f_0c));
 bool ok;
 if(p->extended) ok=s->FUN_003265f0(p->a,p->b,p->c,p->d,p->e,p->f,p->g,p->h);
 else ok=s->FUN_00326330(p->a,p->b,p->d,p->e,p->f,p->g,p->h);
 if(!ok) { this->f_08=s->slot2(); s->slot3(1); return (void*)(0); }
 return (void*)(s);
}
