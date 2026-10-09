typedef unsigned int u32;
struct Owner { u32 count; char pad[20]; u32 *items; char gap[4]; char tail[4]; };
struct Cursor { Owner *owner; u32 index; };
u32 __fastcall FUN_002314c0(Cursor *self) {
    Owner *o = self->owner;
    u32 i;
    u32 *p;
    do {
        i = ++self->index;
        if (i >= o->count) break;
        p = (u32 *)o->items[i];
    } while (p == 0 || (char *)p == o->tail);
    if (i >= o->count) return 0;
    return o->items[i];
}