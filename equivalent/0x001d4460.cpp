// STATUS: equivalent (tools/equiv.py level 3: 10265 inputs, branch coverage 0/0)
// FUN_001d4460 @ 0x001d4460
// cl-flags: /GS
struct Request {
    int kind;
    char first[64];
    char second[64];
    char third[64];
    char remaining[0x2b8 - 4 - 192];
    void FUN_001d1630();
};
extern "C" int __cdecl FUN_000964a0(char*, int, const char*, ...);
struct Owner_1d4460 {
    char reserved[8];
    int context;
    void FUN_001d2190(int, Request, int);
    void target(int id, const char* a, const char* b, const char* c);
};
void Owner_1d4460::target(int id, const char* a, const char* b, const char* c) {
    Request request;
    request.FUN_001d1630();
    request.kind = 3;
    FUN_000964a0(request.first, 64, "%s", a);
    FUN_000964a0(request.second, 64, "%s", b);
    FUN_000964a0(request.third, 64, "%s", c);
    FUN_001d2190(id, request, context);
}
