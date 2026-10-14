// Same code shape as 0x000fc000 (propagated; names are from that function)
typedef unsigned int U_fc020;
extern void FUN_000fbc00(U_fc020, U_fc020, U_fc020, U_fc020*);
void FUN_000fc000(U_fc020 a, U_fc020 b, U_fc020 c) {
    FUN_000fbc00(a, b, c, (&c) + 1);
}