struct Obj_1f6c50;
struct Sub_1f6c50 {
    Sub_1f6c50* Get();
    void* Make();
};
struct Mgr_1f6c50 {
    char pad[0x54];
    Sub_1f6c50* s;
};
extern Mgr_1f6c50* gManager_1f6c50;
struct Obj_1f6c50 {
    char pad[0x4c];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad2[1];
    int x;
    int y;
    void Init(void* v);
};
void __fastcall FUN_001f6c50(Obj_1f6c50* self, void*, int unused) {
    Sub_1f6c50* a = gManager_1f6c50->s;
    Sub_1f6c50* b = a->Get();
    void* v = b->Make();
    self->Init(v);
    self->a = 0;
    self->x = 0;
    self->b = 0;
    self->y = 0;
    self->c = 0;
}
