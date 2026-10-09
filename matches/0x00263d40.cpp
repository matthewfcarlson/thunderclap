struct Pair {
    int a, b;
};
extern int __cdecl FUN_00263970(void*, Pair*);
extern Pair __cdecl FUN_00263c90();
extern void __cdecl FUN_00263bb0(void*, void*);
extern void __cdecl FUN_002639c0(void*, void*, Pair*);
extern int LOOP;
class Obj {
    char pad[0x18];
    Pair value;

  public:
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    Pair local;
    local.a = a;
    local.b = b;
    Pair result = local;
    if (FUN_00263970(&LOOP, &local))
        result = FUN_00263c90();
    FUN_00263bb0(&LOOP, this);
    value = result;
    FUN_002639c0(&LOOP, this, &value);
}