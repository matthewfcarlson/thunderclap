// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00214160 @ 0x00214160
struct TString_214160 { char pad[0x10]; char data[1]; };
struct Proto_214160 { char pad0[0x20]; TString_214160 *source; char pad1[0x3c - 0x24]; int linedefined; };
struct Closure_214160 { char pad0[6]; char isC; char pad1[5]; Proto_214160 *p; };
struct CallInfo_214160 { int pad; Closure_214160 *cl; };
struct DebugInfo_214160 {
    char pad0[0xc];
    const char *what;
    const char *source;
    char pad1[0x1c - 0x14];
    int linedefined;
    char short_src[0x3c];
};
void __cdecl FUN_00216340(char *out, const char *source, unsigned int len);

// equiv-conv: FUN_00214160 ecx eax
void FUN_00214160(DebugInfo_214160 *ar, CallInfo_214160 *ci)
{
    Closure_214160 *cl = ci->cl;
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
