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
    FUN_000f81b0(e->FUN_000f83f0(owner, this), e->a, arg);
    scale = saved;
}