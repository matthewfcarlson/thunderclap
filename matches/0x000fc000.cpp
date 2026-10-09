typedef unsigned int U;
extern void FUN_000fbc00(U,U,U,U*);
void FUN_000fc000(U a, U b, U c) {
    FUN_000fbc00(a,b,c,(&c)+1);
}