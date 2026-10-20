// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char vftableD[];
extern char vftableA[];

class RefObj_19100 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Tidier {
    void Tidy();
};

class CDropAction_19100 {
  public:
    char pad[0x1c];
    RefObj_19100* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_19100* volatile mB; // 0x24
    void Shutdown();
};

void CDropAction_19100::Shutdown() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_19100* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_19100* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy();
}
