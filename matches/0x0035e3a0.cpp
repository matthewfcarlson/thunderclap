extern "C" int __cdecl atexit(void (*f)());
extern void __cdecl FUN_00363f50();
struct Device {
    void Open(const char*, int);
};
extern Device gDevice;
void __cdecl FUN_0035e3a0() {
    gDevice.Open("sound/rsd", 0);
    atexit(FUN_00363f50);
}
