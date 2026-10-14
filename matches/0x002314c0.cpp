typedef unsigned int u32_2314c0;
struct Owner_2314c0 {
    u32_2314c0 count;
    char pad[20];
    u32_2314c0* items;
    char gap[4];
    char tail[4];
};
struct Cursor_2314c0 {
    Owner_2314c0* owner;
    u32_2314c0 index;
};
u32_2314c0 __fastcall FUN_002314c0(Cursor_2314c0* self) {
    Owner_2314c0* o = self->owner;
    u32_2314c0 i;
    u32_2314c0* p;
    do {
        i = ++self->index;
        if (i >= o->count)
            break;
        p = (u32_2314c0*)o->items[i];
    } while (p == 0 || (char*)p == o->tail);
    if (i >= o->count)
        return 0;
    return o->items[i];
}