typedef long long LARGE_INTEGER;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(LARGE_INTEGER*);
}
class d3dContext {
  public:
    char pad[0x418];
    void vfunc_106();
};
void d3dContext::vfunc_106() {
    XAPILIB::QueryPerformanceCounter((LARGE_INTEGER*)(pad + 0x418));
}