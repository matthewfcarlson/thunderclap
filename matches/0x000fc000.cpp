typedef unsigned int U_fc000;
extern void FUN_000fbc00(U_fc000, U_fc000, U_fc000, U_fc000*);
void FUN_000fc000(U_fc000 a, U_fc000 b, U_fc000 c) {
    FUN_000fbc00(a, b, c, (&c) + 1);
}