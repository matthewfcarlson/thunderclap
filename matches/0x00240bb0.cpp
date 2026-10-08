extern int __fastcall FUN_00267f80(void*);
extern void __cdecl FUN_0024c060();
extern void __cdecl FUN_00243090(int,float);
extern void __cdecl FUN_00240f50();
extern int DAT_004e5ca8;
extern int DAT_004e5cac;
void __fastcall FUN_00240bb0(void* p) {
    int i = FUN_00267f80(p) - DAT_004e5ca8;
    FUN_0024c060();
    FUN_00243090(DAT_004e5cac, (float)i);
    FUN_00240f50();
}
