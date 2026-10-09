class X;
class Other {
  public:
    virtual void call(X*);
};
class X {
  public:
    char pad[0x48];
    int state;
    char pad2[4];
    Other* ptr;
};
void __fastcall target(X* self) {
    unsigned int i = 0;
    do {
        Other* p = self->ptr;
        if (!p)
            return;
        Other* q = (Other*)((char*)p - 4);
        if (!q)
            return;
        if (self->state == 0x1e)
            return;
        q->call(self);
        ++i;
    } while (i < 5);
}