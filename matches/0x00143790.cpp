// Same code shape as 0x0013a280 (propagated; names are from that function)
typedef unsigned int u32;
extern u32 vtable;
struct Sub { void Init(); };
struct T { char pad[0x28]; void Run(); };
struct Base { void Finish(); };
void T::Run() {
 *(u32*)this=(u32)&vtable;
 ((Sub*)((char*)this+0x28))->Init();
 ((Sub*)((char*)this+0x18))->Init();
 ((Base*)this)->Finish();
}