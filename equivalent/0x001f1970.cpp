// STATUS: equivalent (tools/equiv.py level 3: 2853 inputs, branch coverage 11/12, incomplete)
// FUN_001f1970 @ 0x001f1970
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" void * __cdecl memset(void *, int, unsigned int);
extern "C" char * __cdecl strcat(char *, const char *);
extern unsigned int DAT_004d9968;

class Mgr {
public:
    void FUN_001ef260(void *p);
};

class Job {
public:
    void *FUN_001f0810(const char *name, int b, int c);
};

extern Mgr *DAT_004e3710;
void *__cdecl FUN_0008d710(int size, int tag);


struct Frame {
    Mgr *mgr;
    char buf[0x40];
    unsigned int cookie;
};

void __stdcall FUN_001f1970(const char *name, int b, int c)
{
    Frame f;
    f.cookie = DAT_004d9968;
    if (name != 0) {
        if (b != 0) {
            f.mgr = DAT_004e3710;
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                Job *j = (Job *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? j->FUN_001f0810(name, b, c) : 0);
            }
        }
    }
    __security_check_cookie(f.cookie);
}
