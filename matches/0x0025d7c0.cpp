class X_25d7c0;
class Other_25d7c0 {
  public:
    virtual void call(X_25d7c0*);
};
class X_25d7c0 {
  public:
    char pad[0x48];
    int state;
    char pad2[4];
    Other_25d7c0* ptr;
};
void __fastcall target(X_25d7c0* self) {
    unsigned int i = 0;
    do {
        Other_25d7c0* p = self->ptr;
        if (!p)
            return;
        Other_25d7c0* q = (Other_25d7c0*)((char*)p - 4);
        if (!q)
            return;
        if (self->state == 0x1e)
            return;
        q->call(self);
        ++i;
    } while (i < 5);
}