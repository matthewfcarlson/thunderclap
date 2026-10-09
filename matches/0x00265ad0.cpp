class Thing {
  public:
    char pad0[8];
    int field8;
    char padc[8];
    unsigned int a, b, c, d;
    void step();
};
void __fastcall target(Thing* self) {
    for (;;) {
        unsigned int x = self->a, y = self->b;
        int n;
        if (x <= y)
            n = (int)(y - x) >> 3;
        else
            n = ((int)(y - self->c) >> 3) + ((int)(self->d - x) >> 3);
        if ((unsigned int)n > 0 || self->field8 != 0)
            self->step();
        else
            break;
    }
}