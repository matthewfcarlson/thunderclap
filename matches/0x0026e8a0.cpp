extern "C" char* __cdecl _strncpy(char*, const char*, unsigned int);
struct ConsoleImpl {
    void FUN_0026e140(void*, int);
};
namespace core {
struct DebugConsole {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9(const char*);
    virtual void vfunc_10();
    virtual void vfunc_11();
    char pad[0xa0];
    ConsoleImpl* impl;
};
} // namespace core
void core::DebugConsole::vfunc_9(const char* text) {
    ConsoleImpl* destination = impl;
    struct Message {
        int type;
        core::DebugConsole* owner;
        char text[84];
    } message;
    message.type = 7;
    message.owner = this;
    _strncpy(message.text, text, 84);
    message.text[83] = 0;
    destination->FUN_0026e140(&message, 92);
}