void FUN_00304370(int, int, int);
struct Thing_304500 {
    int* a;
    int* b;
};
void __fastcall FUN_00304500(Thing_304500* p) {
    int* s = p->b;
    int* d = p->a;
    FUN_00304370((int)d, (int)s, (int)(((char*)s - (char*)d) / 0x44));
}