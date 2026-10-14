// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002340b0 @ 0x002340b0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

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
    unsigned int cookie = DAT_004d9968;
    char buf[0x400] = "";
    reader->Read(a, b, buf, sizeof(buf));
    FUN_00233f20(buf);
    if (reader->HasMore()) {
        state = -1;
        reader->Finish(a, b, &state);
    }
    __security_check_cookie(cookie);
    return true;
}
