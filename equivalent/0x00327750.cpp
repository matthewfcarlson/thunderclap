// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::d3dPrimBufferStream::vfunc_12 @ 0x00327750
namespace pure3d {
struct Triple_327750 { unsigned x,y,z; };
struct Pair_327750 { unsigned x,y; };
class d3dPrimBufferStream {
public:
 virtual void vfunc_0();
 virtual void vfunc_1(unsigned x,unsigned y,unsigned z);
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual void vfunc_7();
 virtual void vfunc_8();
 virtual void vfunc_9();
 virtual void vfunc_10();
 virtual void vfunc_11();
 virtual void vfunc_12(const Triple_327750*,const Triple_327750*,const Pair_327750*);
 char pad04[0x20];
 Triple_327750* position;
 char pad28[0x10];
 Pair_327750* texture;
 void FUN_00326f90();
};
void d3dPrimBufferStream::vfunc_12(const Triple_327750* p,const Triple_327750* n,const Pair_327750* uv) {
 Triple_327750* out=position;
 out->x=p->x;
 out->y=p->y;
 out->z=p->z;
 vfunc_1(n->x,n->y,n->z);
 Pair_327750* dest=texture;
 dest->x=uv->x;
 dest->y=uv->y;
 FUN_00326f90();
}
}
