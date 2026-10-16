struct Target {};
struct Obj {
    Target* p;
};
void __fastcall Do(Target*, int, int, int, int, int);
void __cdecl FUN_0025ac10(Obj* a, int b) {
    Target* p = *(Target* volatile*)&a->p;
    Do(p, b, b, 4, 1, 1);
}