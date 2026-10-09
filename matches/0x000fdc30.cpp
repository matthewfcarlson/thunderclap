class Thing {
  public:
    char pad0[0x0c];
    int values[17];
    int index;
};
int __fastcall target(Thing* self) {
    int i = self->index;
    if (i == -1)
        return 0;
    return self->values[i];
}