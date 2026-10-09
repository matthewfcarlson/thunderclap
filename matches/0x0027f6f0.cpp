class Buffer { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(void *); };
class Conv { public: void Run(void *, void *); };
struct Obj { char p0[4]; void *a; unsigned int index; char p1[4]; Buffer *buffer; char p2[0x14]; };
void __stdcall Target(Obj *self) {
    char local[12];
    if (self->index != 0xffff) {
        Conv *c = (Conv *)((char *)*((void **)((char *)self->a + 0x1c)) + (self->index << 6));
        c->Run((char *)self + 0x14, local);
        self->buffer->f8(local);
    } else {
        self->buffer->f8((char *)self + 0x14);
    }
}