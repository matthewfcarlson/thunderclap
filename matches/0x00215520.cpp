// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_00215520 @ 0x00215520
// cl-flags: /GS
struct Context;
struct Packet_215520 {
    int kind;
    char unused04[16];
    int value;
    char unused18[68];
    int index;
};
typedef void (__cdecl *Callback_215520)(Context *, Packet_215520 *);
struct Entry_215520 { int unused; char *end; };
struct Context {
    char unused00[8];
    char *cursor;
    char unused0c[8];
    Entry_215520 *entry;
    char *limit;
    char *base;
    char unused20[8];
    Entry_215520 *entries;
    char unused2c[5];
    unsigned char enabled;
    char unused32[10];
    Callback_215520 callback;
};
void __cdecl FUN_00215460(Context *, int);
void __cdecl FUN_00215520(Context *self, int kind, int value) {
    Callback_215520 callback = self->callback;
    if (callback && self->enabled) {
        int cursorOffset = self->cursor - self->base;
        int endOffset = self->entry->end - self->base;
        Packet_215520 packet;
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
}