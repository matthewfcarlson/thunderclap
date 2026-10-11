// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_7 @ 0x002768f0
struct Drive { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual signed char s6(); int FUN_00272b60(void*,void*,int); };
extern void __cdecl FUN_002697c0(const char*,char*,void*,unsigned*,unsigned*);
extern void* __cdecl FUN_00273560(unsigned);
namespace core { struct InstanceDrive; }
struct Object { void* FUN_00275930(core::InstanceDrive*,unsigned); };
namespace core { struct InstanceDrive { char pad[12]; Drive* drive; void* context; int vfunc_7(const char*); }; }
int core::InstanceDrive::vfunc_7(const char* path) {
 unsigned first=0, second=0; char extra[16]; char buffer[260];
 FUN_002697c0(path,buffer,extra,&second,&first);
 unsigned selected=second;
 if (drive->s6()<0) selected=first;
 Object* object=(Object*)FUN_00273560(32);
 void* result=object ? object->FUN_00275930(this,selected) : 0;
 return drive->FUN_00272b60(result,context,0);
}