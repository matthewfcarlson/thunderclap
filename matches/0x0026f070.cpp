typedef unsigned int uint;
struct Platform {
    virtual ~Platform();
};
extern Platform platformObject;
Platform* gPlatform;
Platform** gPlatformRef;
unsigned char gReady;
extern void InitPlatform();
namespace XAPILIB {
extern void __stdcall XInitDevices(int, int);
}
void Target() {
    gPlatform = &platformObject;
    gPlatformRef = &gPlatform;
    InitPlatform();
    XAPILIB::XInitDevices(0, 0);
    gReady = 1;
}