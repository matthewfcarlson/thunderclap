// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 6/6)
// pure3d::d3dDevice::vfunc_9 @ 0x0031b8a0
void* __cdecl FUN_0008d690(unsigned int);
struct Params { int a,b,c,d,e,f,g,h; unsigned char extended; };
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
struct d3dDevice {
 void* vtable;
 int field4;
 int error;
 void* context;
 d3dTexture_31b8a0* vfunc_9(Params*);
};
d3dTexture_31b8a0* d3dDevice::vfunc_9(Params* p) {
 d3dTexture_31b8a0* s = (d3dTexture_31b8a0*)FUN_0008d690(0xf8);
 if(s) s=s->FUN_00326b40(context);
 bool ok;
 if(p->extended) ok=s->FUN_003265f0(p->a,p->b,p->c,p->d,p->e,p->f,p->g,p->h);
 else ok=s->FUN_00326330(p->a,p->b,p->d,p->e,p->f,p->g,p->h);
 if(!ok) { error=s->slot2(); s->slot3(1); return 0; }
 return s;
}
}