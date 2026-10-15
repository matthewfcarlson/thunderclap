// STATUS: equivalent (tools/equiv.py level 3: 2538 inputs, branch coverage 85/102, incomplete)
// FUN_0023a6b0 @ 0x0023a6b0
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int isalpha(int c);
extern "C" int isalnum(int c);
extern "C" int isdigit(int c);
extern "C" long atol(const char *s);

struct NameKey {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027b040(const char *s);
};

struct Chunk {
    char data[0x100];
    Chunk *next;
};

struct Entry {
    NameKey name;
    int type;
    union {
        int i;
        float f;
        Chunk *s;
    } val;
    float v[2];
};

class CharStream {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual char peek();
    virtual char get();
    virtual char eof();
};

int __cdecl FUN_00238190(int i);
int __cdecl FUN_00266da0(int v);
float __cdecl FUN_003458c1(const char *s);
void *FUN_0008d690(unsigned int size);

class Tokenizer {
public:
    char pad0[8];
    CharStream *stream;
    int line;
    char pad10[0x120 - 0x10];
    NameKey name120;
    int f128;
    int count;
    Entry entries[0x200];

    int FUN_0023a610();
    int FUN_0023a660(const char *name);
    void FUN_0023a6b0();
};

void Tokenizer::FUN_0023a6b0()
{
    unsigned int cookie = DAT_004d9968;
    char buf[256];
    int old = FUN_00266da0(FUN_00238190(1));

    if (!stream->eof()) {
        do {
            int ws = FUN_0023a610();
            char ch = stream->peek();
            if (!isalpha(ch) && ch != '_') {
                if (ch == '\n') {
                    line++;
                    stream->get();
                } else if (stream->peek() != '\n') {
                    while (!stream->eof()) {
                        stream->get();
                        if (stream->peek() == '\n')
                            break;
                    }
                }
            } else {
                int len = 0;
                while (isalnum(ch) || ch == '_') {
                    if (len < 0xff) {
                        buf[len] = stream->get();
                        len++;
                    }
                    ch = stream->peek();
                }
                buf[len] = 0;
                FUN_0023a610();
                ch = stream->peek();

                if (isdigit(ch) || ch == '-' || ch == '+') {
                    int idx = -1;
                    if (count < 0x200) {
                        idx = count;
                        entries[idx].name.FUN_0027b040(buf);
                        entries[idx].type = 0;
                        count++;
                    }
                    char isFloat = 0;
                    len = 0;
                    while (isdigit(ch) || ch == '-' || ch == '+' || ch == '.' || ch == 'e' || ch == 'E') {
                        if (stream->eof())
                            break;
                        if (len < 0xff) {
                            char c = stream->get();
                            if (c == '.')
                                isFloat = 1;
                            buf[len] = c;
                            len++;
                        }
                        ch = stream->peek();
                    }
                    buf[len] = 0;
                    FUN_0023a610();
                    ch = stream->peek();
                    if (isdigit(ch) || ch == '-' || ch == '+') {
                        if (idx >= 0) {
                            entries[idx].type = 8;
                            entries[idx].val.f = FUN_003458c1(buf);
                        }
                        int cnt = 0;
                        do {
                            len = 0;
                            while (isdigit(ch) || ch == '-' || ch == '+' || ch == '.' || ch == 'e' || ch == 'E') {
                                if (stream->eof())
                                    break;
                                if (len < 0xff) {
                                    buf[len] = stream->get();
                                    len++;
                                }
                                ch = stream->peek();
                            }
                            buf[len] = 0;
                            if (idx >= 0)
                                entries[idx].v[cnt] = FUN_003458c1(buf);
                            FUN_0023a610();
                            ch = stream->peek();
                            cnt++;
                        } while (cnt < 2);
                    } else if (idx >= 0) {
                        if (isFloat) {
                            entries[idx].type = 2;
                            entries[idx].val.f = FUN_003458c1(buf);
                        } else {
                            entries[idx].type = 1;
                            entries[idx].val.i = atol(buf);
                        }
                    }
                } else if (ch != '"') {
                    name120.FUN_0027b040(buf);
                    f128 = ws;
                    FUN_00266da0(old);
                    __security_check_cookie(cookie);
                    return;
                } else {
                    int idx = FUN_0023a660(buf);
                    if (idx >= 0) {
                        entries[idx].type = 4;
                        entries[idx].val.s = 0;
                    }
                    stream->get();
                    ch = stream->peek();
                    Chunk *chunk = 0;
                    int pos = 0;
                    while (ch != '"') {
                        if (stream->eof())
                            break;
                        if (ch == '\\') {
                            stream->get();
                            stream->peek();
                        }
                        if (chunk == 0) {
                            chunk = (Chunk *)FUN_0008d690(0x104);
                            chunk->next = 0;
                            entries[idx].val.s = chunk;
                            pos = 0;
                        } else if (pos >= 0xff) {
                            chunk->data[pos] = 0;
                            Chunk *nc = (Chunk *)FUN_0008d690(0x104);
                            chunk->next = nc;
                            chunk = nc;
                            chunk->next = 0;
                            pos = 0;
                        }
                        char c = stream->get();
                        chunk->data[pos] = c;
                        pos++;
                        if (c == '\n')
                            line++;
                        ch = stream->peek();
                    }
                    if (chunk)
                        chunk->data[pos] = 0;
                    if (ch == '"')
                        stream->get();
                }
            }
        } while (!stream->eof());
    }
    FUN_00266da0(old);
    __security_check_cookie(cookie);
}
