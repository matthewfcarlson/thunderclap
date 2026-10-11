// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000f87f0 @ 0x000f87f0
struct Owner;
struct Blender;
struct Entry {
    int a;
    int b;
    float scale;
    int FUN_000f83f0(Owner* owner, Blender* blender);
};
struct Blender {
    Owner* owner;
    char pad[0x88 - 4];
    int index;
    float scale;
    void FUN_000f81b0(int v, int a, int b);
    void FUN_000f87f0(Entry* e, int arg);
};
void Blender::FUN_000f87f0(Entry* e, int arg) {
    float saved = scale;
    scale = e->scale;
    int a = e->a;
    int v = e->FUN_000f83f0(owner, this);
    FUN_000f81b0(v, a, arg);
    scale = saved;
}
