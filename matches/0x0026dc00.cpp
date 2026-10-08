struct Fiber { char pad[0x14]; void* fiber; };
struct Context { char pad[0x2c]; Fiber* value; };
extern Context* FUN_0026dbb0();
namespace XAPILIB { void __stdcall SwitchToFiber(void*); }
void __cdecl FUN_0026dc00(Fiber* param_1) {
    Context* p = FUN_0026dbb0();
    p->value = param_1;
    XAPILIB::SwitchToFiber(param_1->fiber);
}