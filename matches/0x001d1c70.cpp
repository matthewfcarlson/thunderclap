class Obj {
  public:
    char pad0[8];
    int value;
    char pad1[0x5470 - 12];
    int items[8];
    int index;
};
int __cdecl Get(int);
void __cdecl Set(int, int);
void __fastcall Target(Obj* self) {
    if (self->index >= 0) {
        int v = Get(self->value);
        int x = self->items[self->index];
        if (v != x)
            Set(self->value, x);
        --self->index;
    }
}