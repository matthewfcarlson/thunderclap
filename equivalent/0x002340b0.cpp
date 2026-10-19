// STATUS: equivalent (tools/equiv.py level 3: 8461 inputs, branch coverage 2/2)
// FUN_002340b0 @ 0x002340b0
// cl-flags: /GS
extern "C" void *__cdecl memset(void *, int, unsigned int);

class Reader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool HasMore();                                                  // slot 3
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void Read(int a, int b, char *buf, int size);                    // slot 8
    virtual void v9();
    virtual void Finish(int a, int b, int *state);                           // slot 10
};

class Parser_2340b0 {
public:
    char pad0[8];
    int state;              // 0x8

    void FUN_00233f20(char *text);
    bool FUN_002340b0(int a, int b, Reader *reader);
};

bool Parser_2340b0::FUN_002340b0(int a, int b, Reader *reader)
{
    struct Frame {
        char buf[0x400];
        int pad;                // (the original leaves a word between the buffer and the cookie)
    } f;
    f.buf[0] = 0;
    memset(f.buf + 1, 0, sizeof(f.buf) - 1);
    reader->Read(a, b, f.buf, sizeof(f.buf));
    FUN_00233f20(f.buf);
    if (reader->HasMore()) {
        state = -1;
        reader->Finish(a, b, &state);
    }
    return true;
}
