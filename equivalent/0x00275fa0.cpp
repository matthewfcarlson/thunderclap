// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_6 @ 0x00275fa0
void* __cdecl FUN_00273560(unsigned int size);
namespace core { struct File; }
struct Request {
 Request* FUN_00275430(core::File* file, unsigned int argument);
};
struct Manager {
 int FUN_00272b60(Request* request, unsigned int value, unsigned int zero);
};
namespace core {
struct File {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual int vfunc_6(unsigned int argument);
 char pad[8];
 Manager* manager;
 unsigned int value;
};
int File::vfunc_6(unsigned int argument) {
 Request* request = static_cast<Request*>(FUN_00273560(16));
 if (request) request = request->FUN_00275430(this, argument);
 return manager->FUN_00272b60(request, value, 0);
}
}
