// Same code shape as 0x000df5e0 (propagated; names are from that function)
typedef unsigned int U_df640;
void __cdecl Helper(U_df640);
struct Target_df640 {
    U_df640 a;
    U_df640 b;
    void Run();
};
void Target_df640::Run() {
    Helper(a);
    Helper(b);
}