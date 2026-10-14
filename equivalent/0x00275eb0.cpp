// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_3 @ 0x00275eb0
void* __cdecl FUN_00273560(unsigned int);
namespace core { struct File; }
struct Request { Request* FUN_00275230(core::File*, unsigned int, unsigned int, unsigned int); };
struct Queue_275eb0 { void FUN_00272b60(Request*, unsigned int, unsigned int); };
namespace core {
struct File {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3(unsigned int, unsigned int, unsigned int);
 char padding[8];
 Queue_275eb0* queue;
 unsigned int context;
};
void File::vfunc_3(unsigned int a, unsigned int b, unsigned int c) {
 Request* memory = static_cast<Request*>(FUN_00273560(0x18));
 Request* request = 0;
 if (memory) request = memory->FUN_00275230(this, a, b, c);
 queue->FUN_00272b60(request, context, 0);
}
}
