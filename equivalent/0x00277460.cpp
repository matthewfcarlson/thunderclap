// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::CementLibrary::vfunc_7 @ 0x00277460
typedef unsigned int U;
extern "C" int __cdecl sprintf(char*,const char*,...);
namespace core { struct CementLibrary; }
struct Manager { void FUN_00272b60(void*,U,U); };
struct Resource { Resource* FUN_002764d0(Manager*,const char*,U,U,U,U,U,U,U); };
struct Request { Request* FUN_00274fc0(Resource*,U,core::CementLibrary*); };
extern Resource* __cdecl FUN_00275d50(U);
extern Request* __cdecl FUN_00273560(U);
namespace core {
struct CementLibrary {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 virtual void vfunc_7(Resource**,U,U,U,U,U);
 virtual void vfunc_8();
 char pad[0x14]; Manager* manager;
};
void CementLibrary::vfunc_7(Resource** output,U id,U p4,U p5,U p6,U p7) {
 char name[16]; sprintf(name,"0x%X",id);
 Resource* storage=FUN_00275d50(0x168);
 Resource* result=0;
 if(storage) result=storage->FUN_002764d0(manager,name,0,0,p4,p5,p6,p7,0);
 *output=result;
 Request* allocation=FUN_00273560(0x14);
 Request* request=0;
 if(allocation) request=allocation->FUN_00274fc0(result,id,this);
 manager->FUN_00272b60(request,p4,0);
}
}