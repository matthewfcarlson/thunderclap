// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_33 @ 0x00276df0
struct Child_276df0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual unsigned char v6(); };
struct Created_276df0 { Created_276df0* FUN_002764d0(Child_276df0*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, int); };
extern void __cdecl FUN_002697c0(unsigned, char*, unsigned*, unsigned*, unsigned*);
extern Created_276df0* __cdecl FUN_00275d50(unsigned);
namespace core { struct InstanceDrive { void* vtable; void* refTable; unsigned field8; Child_276df0* child; Created_276df0* vfunc_33(Created_276df0**,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned); }; }
Created_276df0* core::InstanceDrive::vfunc_33(Created_276df0** out,unsigned path,unsigned a3,unsigned a4,unsigned a5,unsigned a6,unsigned a7,unsigned a8) {
 unsigned first=0,second=0,other; char buffer[260];
 FUN_002697c0(path,buffer,&other,&second,&first);
 unsigned selected=second;
 if ((signed char)child->v6()<0) selected=first;
 Created_276df0* p=FUN_00275d50(0x168);
 Created_276df0* result=0;
 if(p) result=p->FUN_002764d0(child,selected,a3,a4,a5,a6,a7,a8,1);
 *out=result;
 return result;
}