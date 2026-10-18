struct Target {};
struct Obj {
    Target* p;
};
int __fastcall Do(Target*, int, int, int, int, int);
int __cdecl FUN_0025ac10(Obj* a, int b) {
    Target* p = *(Target* volatile*)&a->p;
    return Do(p, b, b, 4, 1, 1);
}