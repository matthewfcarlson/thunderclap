struct Pair_263d40 {
    int a, b;
};
extern int __cdecl FUN_00263970(void*, Pair_263d40*);
extern Pair_263d40 __cdecl FUN_00263c90();
extern void __cdecl FUN_00263bb0(void*, void*);
extern void __cdecl FUN_002639c0(void*, void*, Pair_263d40*);
extern int LOOP;
class Obj_263d40 {
    char pad[0x18];
    Pair_263d40 value;

  public:
    void Fn(int a, int b);
};
void Obj_263d40::Fn(int a, int b) {
    Pair_263d40 local;
    local.a = a;
    local.b = b;
    Pair_263d40 result = local;
    if (FUN_00263970(&LOOP, &local))
        result = FUN_00263c90();
    FUN_00263bb0(&LOOP, this);
    value = result;
    FUN_002639c0(&LOOP, this, &value);
}