// Same code shape as 0x000fc1a0 (propagated; names are from that function)
struct Obj {
    void Target();
};
extern Obj* g_object;
extern "C" void __cdecl FUN_000fc1a0(void) {
    g_object->Target();
}