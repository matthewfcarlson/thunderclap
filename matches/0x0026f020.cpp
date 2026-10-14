void FUN_002705f0();
namespace XAPILIB {
void __stdcall XInitDevices(int, int);
}
class Obj_26f020 {
  public:
    char pad[8];
    unsigned char initialized;
    void Init();
};
void Obj_26f020::Init() {
    FUN_002705f0();
    XAPILIB::XInitDevices(0, 0);
    initialized = 1;
}