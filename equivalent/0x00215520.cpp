// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_00215520 @ 0x00215520
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Context;
struct Packet {
    int kind;
    char unused04[16];
    int value;
    char unused18[68];
    int index;
};
typedef void (__cdecl *Callback)(Context *, Packet *);
struct Entry { int unused; char *end; };
struct Context {
    char unused00[8];
    char *cursor;
    char unused0c[8];
    Entry *entry;
    char *limit;
    char *base;
    char unused20[8];
    Entry *entries;
    char unused2c[5];
    unsigned char enabled;
    char unused32[10];
    Callback callback;
};
void __cdecl FUN_00215460(Context *, int);
void __cdecl FUN_00215520(Context *self, int kind, int value) {
    unsigned int cookie = DAT_004d9968;
    Callback callback = self->callback;
    if (callback && self->enabled) {
        int cursorOffset = self->cursor - self->base;
        int endOffset = self->entry->end - self->base;
        Packet packet;
        packet.kind = kind;
        packet.value = value;
        packet.index = kind == 4 ? 0 : ((char *)self->entry - (char *)self->entries) >> 4;
        if (self->limit - self->cursor <= 160)
            FUN_00215460(self, 20);
        self->entry->end = self->cursor + 160;
        self->enabled = 0;
        callback(self, &packet);
        self->enabled = 1;
        self->entry->end = self->base + endOffset;
        self->cursor = self->base + cursorOffset;
    }
    __security_check_cookie(cookie);
}