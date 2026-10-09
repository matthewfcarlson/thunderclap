// Same code shape as 0x0033b560 (propagated; names are from that function)
typedef unsigned int u32;
extern void __cdecl FUN_003390d0(u32, const char *, const char *, int);
int __cdecl target(u32 p) {
    FUN_003390d0(p, "table", "$IC", 0);
    return 1;
}