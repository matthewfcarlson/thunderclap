void FUN_00304370(int, int, int);
struct Thing { int *a; int *b; };
void __fastcall FUN_00304500(Thing *p) {
 int *s=p->b;
 int *d=p->a;
 FUN_00304370((int)d,(int)s,(int)(((char*)s-(char*)d)/0x44));
}