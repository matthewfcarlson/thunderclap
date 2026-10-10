// cl-flags: /Oy- /O1
extern "C" void* __stdcall FUN_0020a2b5(unsigned int, unsigned int);
namespace XAPILIB {
void __stdcall SetLastError(unsigned int);
}
namespace xboxkrnl {
void __stdcall XcSHAInit(void*);
}
struct Context {
    unsigned int kind;
    unsigned int state;
    unsigned char data[0x74];
};
extern "C" void* __cdecl FUN_00212005() {
    Context* p = (Context*)FUN_0020a2b5(0x7c, 0x24830000);
    if (!p) {
        XAPILIB::SetLastError(8);
        return (void*)-1;
    }
    p->state = 0 & p->state;
    p->kind = 2;
    xboxkrnl::XcSHAInit(&p->data[0]);
    return p;
}
