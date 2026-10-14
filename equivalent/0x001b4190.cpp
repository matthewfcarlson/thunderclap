// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// FUN_001b4190 @ 0x001b4190
extern unsigned int DAT_004c39e8, DAT_004c39ec, DAT_004c39f8, DAT_004c39fc;
extern unsigned int DAT_004c3a18, DAT_004c3a1c, DAT_004c3a20, DAT_004c3a24;
struct Target {
    char pad[0x58];
    unsigned int w58, w5c, w60, w64;
};
struct Source {
    char pad[0x74];
    Target* target;
};
struct Sink {
    void FUN_002ee6b0(Target* t);
};
class Obj {
  public:
    char pad00[8];
    Sink* sink;
    char FUN_001b4190(Source* s);
};
char Obj::FUN_001b4190(Source* s) {
    if (s == 0)
        return 0;
    Target* t = s->target;
    if (t == 0)
        return 0;
    t->w58 = DAT_004c39f8;
    t->w5c = DAT_004c39fc;
    t->w60 = DAT_004c3a20 | (DAT_004c3a18 | DAT_004c39e8);
    t->w64 = DAT_004c3a24 | (DAT_004c3a1c | DAT_004c39ec);
    sink->FUN_002ee6b0(t);
    return 1;
}
