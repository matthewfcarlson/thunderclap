// Same code shape as 0x00042930 (propagated; names are from that function)
class C { public: char pad0[0x118]; unsigned char flag; char pad1[0x314-0x119]; float scale; char pad2[0x338-0x318]; int field338; void target(int, float); };
void __stdcall helper(int, float);
void C::target(int a, float b) {
    if (!flag && field338 == 0)
        helper(a, b * scale);
}