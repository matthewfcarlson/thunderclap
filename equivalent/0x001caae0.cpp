// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001caae0 @ 0x001caae0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
// 0x001caae0: fill a 0x38-byte request record from two names and several values
extern "C" void* __cdecl memset(void*, int, unsigned int) throw();
unsigned __int64 __cdecl FUN_0027b020(const char* s) throw();

struct Name {
    int lo;
    int hi;
    ~Name() throw();
};

class Request {
public:
    int size;
    int kind;
    int field_08;
    int pad0c;
    int field_10;
    int pad14;
    Name first;
    Name second;
    int field_28;
    int field_2c;
    unsigned __int64 key;
    Request* Init(Name a, int v28, Name b, int v2c, const char* text, int v10, int v08) throw();
};

Request* Request::Init(Name a, int v28, Name b, int v2c, const char* text, int v10, int v08) throw()
{
    memset(this, 0, 0x38);
    first = a;
    second = b;
    size = 0x38;
    kind = 0x17;
    field_28 = v28;
    field_2c = v2c;
    key = FUN_0027b020(text);
    field_10 = v10;
    field_08 = v08;
    return this;
}
