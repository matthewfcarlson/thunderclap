// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::d3dPrimBufferStream::vfunc_12 @ 0x00327750
namespace pure3d {
struct Triple { unsigned x,y,z; };
struct Pair { unsigned x,y; };
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
 virtual void vfunc_12(const Triple*,const Triple*,const Pair*);
 char pad04[0x20];
 Triple* position;
 char pad28[0x10];
 Pair* texture;
 void FUN_00326f90();
};
void d3dPrimBufferStream::vfunc_12(const Triple* p,const Triple* n,const Pair* uv) {
 Triple* out=position;
 out->x=p->x;
 out->y=p->y;
 out->z=p->z;
 vfunc_1(n->x,n->y,n->z);
 Pair* dest=texture;
 dest->x=uv->x;
 dest->y=uv->y;
 FUN_00326f90();
}
}
