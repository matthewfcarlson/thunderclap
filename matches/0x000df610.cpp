// Same code shape as 0x000df5e0 (propagated; names are from that function)
typedef unsigned int U_df610;
void __cdecl Helper(U_df610);
struct Target_df610 {
    U_df610 a;
    U_df610 b;
    void Run();
};
void Target_df610::Run() {
    Helper(a);
    Helper(b);
}