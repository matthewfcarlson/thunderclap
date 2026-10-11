// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::ControllerBuffer::vfunc_2 @ 0x00270840
void __cdecl FUN_00266f00(void*, void*);
extern void* DAT_004cdbb0;
extern void* DAT_0042b688[];
extern void* DAT_0042b680[];
extern void* DAT_0042af64[];
extern void* DAT_003f6098[];
namespace core {
struct ControllerBuffer {
 void** vtable;
 void** baseVtable;
 void* owner;
 char unusedC[4];
 void* first;
 char unused14[16];
 void* second;
 void* context;
 ControllerBuffer* vfunc_2(unsigned char flags);
};
ControllerBuffer* ControllerBuffer::vfunc_2(unsigned char flags) {
 void* firstValue = first;
 void* contextValue = context;
 vtable = DAT_0042b688;
 baseVtable = DAT_0042b680;
 FUN_00266f00(contextValue, firstValue);
 FUN_00266f00(context, second);
 DAT_004cdbb0 = owner;
 baseVtable = DAT_0042af64;
 vtable = DAT_003f6098;
 if (flags & 1) FUN_00266f00(DAT_004cdbb0, this);
 return this;
}
}
