struct pure3d_d3dDisplay { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void vfunc_14(); char pad[0x430]; char flag; };
namespace D3D8 { void D3D_KickOffAndWaitForIdle(); void D3DDevice_BlockUntilVerticalBlank(); void __stdcall D3DDevice_Swap(int); }
extern unsigned char g5554a0; extern int g55549c;
void pure3d_d3dDisplay::vfunc_14() {
 D3D8::D3D_KickOffAndWaitForIdle();
 unsigned char c = g5554a0;
 int n = g55549c;
 if (c == 0) { if (n == 0) D3D8::D3DDevice_BlockUntilVerticalBlank(); else if (n != 1) goto done; }
 D3D8::D3DDevice_BlockUntilVerticalBlank();
 done: g55549c = 0; flag = 0; D3D8::D3DDevice_Swap(0); D3D8::D3D_KickOffAndWaitForIdle();
}
