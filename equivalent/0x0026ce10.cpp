// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_6 @ 0x0026ce10
namespace core { struct MemoryDlAllocator { char pad0[12]; unsigned int fieldC,field10,field14,field18,field1c; char pad20[0x490-0x20]; unsigned int count,total,peak; void vfunc_6(unsigned int a,unsigned int b); }; }
extern unsigned int DAT_005283a0,DAT_005283a4,DAT_005283a8;
extern void* DAT_0052839c;
extern void* DAT_005283ac;
extern void* __cdecl FUN_0026c6a0(unsigned int,unsigned int);
void core::MemoryDlAllocator::vfunc_6(unsigned int a,unsigned int b) {
 DAT_005283a0=fieldC; DAT_005283a8=field10; DAT_0052839c=&field1c; DAT_005283ac=&field18; DAT_005283a4=field14;
 void* p=FUN_0026c6a0(b,a);
 if(p) { total+=*((unsigned int*)p-1)&~3u; if(total>peak) peak=total; ++count; }
}