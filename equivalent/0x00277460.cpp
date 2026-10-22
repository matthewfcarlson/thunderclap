// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::CementLibrary::vfunc_7 @ 0x00277460
typedef unsigned int U_277460;
extern "C" int __cdecl sprintf(char*,const char*,...);
namespace core { struct CementLibrary; }
struct Manager_277460 { void FUN_00272b60(void*,U_277460,U_277460); };
struct File_277460 { File_277460* FUN_002764d0(Manager_277460*,const char*,U_277460,U_277460,U_277460,U_277460,U_277460,U_277460,U_277460); };
struct Request { Request* FUN_00274fc0(File_277460*,U_277460,core::CementLibrary*); };
extern File_277460* __cdecl FUN_00275d50(U_277460);
extern Request* __cdecl FUN_00273560(U_277460);
namespace core {
struct CementLibrary {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 virtual void vfunc_7(File_277460**,U_277460,U_277460,U_277460,U_277460,U_277460);
 virtual void vfunc_8();
 char pad[0x14]; Manager_277460* manager;
};
void CementLibrary::vfunc_7(File_277460** output,U_277460 id,U_277460 p4,U_277460 p5,U_277460 p6,U_277460 p7) {
 char name[16]; sprintf(name,"0x%X",id);
 File_277460* storage=FUN_00275d50(0x168);
 File_277460* result=0;
 if(storage) result=storage->FUN_002764d0(manager,name,0,0,p4,p5,p6,p7,0);
 *output=result;
 Request* allocation=FUN_00273560(0x14);
 Request* request=0;
 if(allocation) request=allocation->FUN_00274fc0(result,id,this);
 manager->FUN_00272b60(request,p4,0);
}
}