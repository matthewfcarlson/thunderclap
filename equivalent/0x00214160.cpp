// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00214160 @ 0x00214160
struct TString { char pad[0x10]; char data[1]; };
struct Proto { char pad0[0x20]; TString *source; char pad1[0x3c - 0x24]; int linedefined; };
struct Closure { char pad0[6]; char isC; char pad1[5]; Proto *p; };
struct CallInfo { int pad; Closure *cl; };
struct DebugInfo {
    char pad0[0xc];
    const char *what;
    const char *source;
    char pad1[0x1c - 0x14];
    int linedefined;
    char short_src[0x3c];
};
void __cdecl FUN_00216340(char *out, const char *source, unsigned int len);

// equiv-conv: FUN_00214160 ecx eax
void FUN_00214160(DebugInfo *ar, CallInfo *ci)
{
    Closure *cl = ci->cl;
    if (cl->isC) {
        ar->source = "=[C]";
        ar->linedefined = -1;
        ar->what = "C";
        FUN_00216340(ar->short_src, ar->source, 0x3c);
        return;
    }
    ar->source = cl->p->source->data;
    int line = cl->p->linedefined;
    ar->linedefined = line;
    ar->what = (line != 0) ? "Lua" : "main";
    FUN_00216340(ar->short_src, ar->source, 0x3c);
}
