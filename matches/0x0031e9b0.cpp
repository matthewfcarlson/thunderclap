struct Stack_31e9b0 {
    int pad0;
    int pad1;
    int top;
    char* data;
};

struct StateBase {
    virtual void Restore(void* ctx);
};

class Ctx_31e9b0 {
  public:
    virtual void f0();
    char pad[0x30];
    Stack_31e9b0* s34;
    Stack_31e9b0* s38;
    Stack_31e9b0* s3c;
    Stack_31e9b0* s40;
    Stack_31e9b0* s44;
    StateBase* cur48;
    StateBase* cur4c;
    StateBase* cur50;
    StateBase* cur54;
    StateBase* cur58;
    virtual void vfunc_88(unsigned char mask);
};

void Ctx_31e9b0::vfunc_88(unsigned char mask) {
    if (mask & 1) {
        s38->top--;
        cur4c = (StateBase*)(s38->data + s38->top * 0x1c);
        cur4c->Restore(this);
    }
    if (mask & 2) {
        s34->top--;
        cur48 = (StateBase*)(s34->data + s34->top * 0x34);
        cur48->Restore(this);
    }
    if (mask & 4) {
        s3c->top--;
        cur50 = (StateBase*)(s3c->data + s3c->top * 0x3ec);
        cur50->Restore(this);
    }
    if (mask & 8) {
        s40->top--;
        cur54 = (StateBase*)(s40->data + s40->top * 20);
        cur54->Restore(this);
    }
    if (mask & 0x10) {
        s44->top--;
        cur58 = (StateBase*)(s44->data + s44->top * 36);
        cur58->Restore(this);
    }
}
