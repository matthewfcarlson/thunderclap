struct Obj;
struct Sub {
    Sub* Get();
    void* Make();
};
struct Mgr {
    char pad[0x54];
    Sub* s;
};
extern Mgr* gManager;
struct Obj {
    char pad[0x4c];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad2[1];
    int x;
    int y;
    void Init(void* v);
};
void __fastcall FUN_001f6c50(Obj* self, void*, int unused) {
    Sub* a = gManager->s;
    Sub* b = a->Get();
    void* v = b->Make();
    self->Init(v);
    self->a = 0;
    self->x = 0;
    self->b = 0;
    self->y = 0;
    self->c = 0;
}
