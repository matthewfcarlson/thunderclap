// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// core::DebugConsole::vfunc_0_adj4 @ 0x0026e700
namespace core {
struct DebugConsole {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    void vfunc_0_adj4();
};
void DebugConsole::vfunc_0_adj4() {
    DebugConsole* object = reinterpret_cast<DebugConsole*>(reinterpret_cast<char*>(this) - 4);
    object->DebugConsole::vfunc_2();
}
}