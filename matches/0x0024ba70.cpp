class Obj {
  public:
    char pad0[0xb8];
    unsigned char head;
    unsigned char count;
    unsigned char size;
    char padbb;
    int total;
};
struct Entry {
    int a;
    int b;
    int c;
};
int __cdecl FUN_0024ba70(Obj* self, int value, int amount) {
    int old = self->total;
    int index = ((int)self->head + (int)self->count) % (int)self->size;
    Entry* e = (Entry*)((char*)self + 0x40) + index;
    e->a = value;
    e->c = self->total;
    e->b = amount;
    self->total = self->total + amount;
    self->count = self->count + 1;
    return old;
}