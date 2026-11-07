extern "C" int* FUN_002705f0();
// XAPILIB's XInitDevices through its thunk 0x003eba7c (the XDK table's row 0x003eac33)
extern "C" void __stdcall thunk_FUN_003eac33(int, void*);
class Obj_26f020 {
  public:
    char pad[8];
    unsigned char initialized;
    void Init();
};
void Obj_26f020::Init() {
    FUN_002705f0();
    thunk_FUN_003eac33(0, 0);
    initialized = 1;
}
