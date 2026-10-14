extern int __cdecl MakeThing(int, int);
class Thing_1e8910 {
  public:
    char pad[0x19c];
    int items[200];
    int count;
};
int __fastcall Target(Thing_1e8910* self) {
    if (self->count >= 200)
        return 0;
    int value = MakeThing(0x14, 6);
    self->items[self->count] = value;
    value = self->items[self->count];
    ++self->count;
    return value;
}