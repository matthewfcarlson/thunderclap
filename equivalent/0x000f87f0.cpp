// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_000f87f0 @ 0x000f87f0
struct Owner;
struct Blender_f87f0;
struct Entry_f87f0 {
    int a;
    int b;
    float scale;
    int FUN_000f83f0(Owner* owner, Blender_f87f0* blender);
};
struct Blender_f87f0 {
    Owner* owner;
    char pad[0x88 - 4];
    int index;
    float scale;
    void FUN_000f81b0(int v, int a, int b);
    void FUN_000f87f0(Entry_f87f0* e, int arg);
};
void Blender_f87f0::FUN_000f87f0(Entry_f87f0* e, int arg) {
    float saved = scale;
    scale = e->scale;
    int a = e->a;
    int v = e->FUN_000f83f0(owner, this);
    FUN_000f81b0(v, a, arg);
    scale = saved;
}
