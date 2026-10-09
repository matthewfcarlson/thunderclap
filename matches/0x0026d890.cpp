typedef unsigned int u32;
extern void __stdcall Helper(u32, int);
void __cdecl Target(u32* p) {
    Helper(*p, -1);
}