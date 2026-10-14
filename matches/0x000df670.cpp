// Same code shape as 0x000df5e0 (propagated; names are from that function)
typedef unsigned int U_df670;
void __cdecl Helper(U_df670);
struct Target_df670 {
    U_df670 a;
    U_df670 b;
    void Run();
};
void Target_df670::Run() {
    Helper(a);
    Helper(b);
}