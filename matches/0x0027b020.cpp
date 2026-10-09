// Same code shape as 0x0027afb0 (propagated; names are from that function)
typedef unsigned int u32;
extern __declspec(noreturn) void __cdecl target(u32, u32, u32);
__declspec(noreturn) void __cdecl wrapper(u32 x) {
    target(x, 0, 0);
}