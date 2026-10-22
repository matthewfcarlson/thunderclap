// STATUS: equivalent (tools/equiv.py level 3: 20015 inputs, branch coverage 36/36)
// FUN_00337a30 @ 0x00337a30
extern "C" int memcmp(const void *a, const void *b, unsigned int n);
// MSVC 7.1 expands memcmp against a string literal inline (repe cmpsb); so does this.
static inline int memcmp_lit(const char *a, const char *b, unsigned n)
{
    for (; n != 0; n--, a++, b++)
        if (*a != *b)
            return (unsigned char)*a - (unsigned char)*b;
    return 0;
}
extern "C" long atol(const char *s);

void *__cdecl FUN_0008d690(unsigned int size);

struct BinkCallback_337a30;
struct Item;

struct Listener_337a30 {
    virtual void v0();
    virtual void OnNode(BinkCallback_337a30 *node);
};

struct Registry_337a30 {
    Item *FUN_003373e0(const char *name);
};

class Reader {
public:
    virtual void Destroy(int flag);
    Reader *FUN_003388d0(void *source, int size);
    char FUN_003385f0(int arg);
    void FUN_00338630();
};

class BinkCallback_337a30 {
public:
    virtual void Destroy(int flag);
    char pad04[8];
    int hasOwner;
    BinkCallback_337a30 *FUN_003352a0();
    void FUN_003352c0(const char *text);
    char FUN_00335300(class Parser_337a30 *parser);
    void FUN_00336f30(Item *item, int arg);
};

class Parser_337a30 {
public:
    char pad0[4];
    int state;
    Reader *reader;
    const char *__fastcall FUN_00337980();
    void FUN_003379b0();
    bool FUN_00337a30(void *source, int a1, Registry_337a30 *registry, Listener_337a30 *listener, int a4);
};

bool Parser_337a30::FUN_00337a30(void *source, int a1, Registry_337a30 *registry, Listener_337a30 *listener, int a4)
{
    if (reader)
        reader->Destroy(1);
    Reader *r = (Reader *)FUN_0008d690(0x874);
    if (r)
        r = r->FUN_003388d0(source, 0x2000);
    reader = r;
    if (r->FUN_003385f0(a1)) {
        BinkCallback_337a30 *node = (BinkCallback_337a30 *)FUN_0008d690(0x10);
        if (node)
            node = node->FUN_003352a0();
        const char *tok = FUN_00337980();
        if (tok) {
            do {
                if (memcmp_lit(tok, "version", 8) == 0) {
                    FUN_003379b0();
                    tok = FUN_00337980();
                    if (!tok)
                        break;
                    atol(tok);
                    FUN_003379b0();
                } else if (memcmp_lit(tok, "object", 7) == 0) {
                    if (node->hasOwner)
                        listener->OnNode(node);
                    FUN_003379b0();
                    tok = FUN_00337980();
                    if (!tok)
                        break;
                    Item *item = registry->FUN_003373e0(tok);
                    if (!item) {
                        state = 5;
                        break;
                    }
                    node->FUN_00336f30(item, a4);
                    FUN_003379b0();
                    tok = FUN_00337980();
                    if (!tok)
                        break;
                    node->FUN_003352c0(tok);
                    FUN_003379b0();
                } else if (memcmp_lit(tok, "attr", 5) == 0) {
                    FUN_003379b0();
                    if (!node->FUN_00335300(this))
                        break;
                } else {
                    state = 4;
                    break;
                }
                tok = FUN_00337980();
            } while (tok);
        }
        if (node->hasOwner)
            listener->OnNode(node);
        node->Destroy(1);
        reader->FUN_00338630();
    }
    return state == 0 || state == 1;
}
