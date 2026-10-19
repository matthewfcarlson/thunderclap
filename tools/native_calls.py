"""Register-convention calls for the native build: the edit groups of tools/native_fix.py's `reg-call` rule.

A function the original calls with arguments in registers (`// equiv-conv: FUN_x esi stack` in its own source) is
an ordinary __cdecl function natively, so each caller must pass exactly its parameters, in its own source's order.
tools/native_conv_check.py check 5 lists the callers that don't (no note at all, or a list missing a register the
definition reads). Each group below was read off the original's call site (which value the register holds there)
and is applied by `native_fix.py --apply --verify --rule reg-call`: written only if the rewritten source still
passes equiv.py (equivalent/) - equiv.py maps every argument of an equiv-conv note to the original's register or
stack word at the call, so a wrong value fails. A matches/ source in DEMOTE can't express the call and still
byte-match (MSVC 7.1 has no esi/edi/ebx convention: the original only happened to have the value there), so it
becomes an equivalent/ source.

Each group: (source, why, [(old text, new text), ...]); every occurrence of an old text is replaced.
"""

DEMOTE = {"matches/0x002151e0.cpp", "matches/0x00339270.cpp", "matches/0x0033eb30.cpp"}


def _n(name, locs):
    return "// equiv-conv: %s %s\n" % (name, locs)


ESI_S = "esi stack"

OLD_35AB0 = 'struct Object { char padding[0x11c]; void *item; };\nstruct Item { __int64 FUN_000443c0(); };\n// equiv-conv: FUN_00035ab0 eax ecx\nunsigned int FUN_00035ab0(unsigned int incoming, Object *self) {\n    Item *p = (Item *)self->item;\n    if (!p) return incoming & 0xffffff00;\n    __int64 value = p->FUN_000443c0();\n    return (unsigned int)value == (*(unsigned int*)&DAT_004dc0e0) && (unsigned int)(value >> 32) == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4));\n}'
NEW_35AB0 = 'struct Item { __int64 FUN_000443c0(); };\nstruct Object {\n    char padding[0x11c];\n    void *item;\n    bool FUN_00035ab0();\n};\nbool Object::FUN_00035ab0() {\n    Item *p = (Item *)item;\n    if (!p) return false;\n    __int64 value = p->FUN_000443c0();\n    return (unsigned int)value == (*(unsigned int*)&DAT_004dc0e0) && (unsigned int)(value >> 32) == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4));\n}'

REG_CALLS = [
    # --- Lua 5.x core (0x00212bb0-0x00222000) and its libraries (0x00338d90-) -------------------------------
    ("matches/0x002151e0.cpp", "lua_close: close_state 0x00214f90 takes the state in esi (the original's esi = L)",
     [("void __cdecl FUN_00214f90(void);", _n("FUN_00214f90", "esi") + "void __cdecl FUN_00214f90(int);"),
      ("    FUN_00214f90();", "    FUN_00214f90(esi);")]),
    ("matches/0x00339270.cpp", "0x003391f0 takes the state in esi (the original's esi = the first argument)",
     [("extern void FUN_003391f0();", _n("FUN_003391f0", "esi") + "extern void FUN_003391f0(void*);"),
      ("    FUN_003391f0();", "    FUN_003391f0(a);")]),
    ("matches/0x0033eb30.cpp", "luaopen_base 0x0033ea90 takes the state in esi (the original's esi = the argument); "
     "start-up trace run 20",
     [('extern "C" void __cdecl FUN_0033ea90();', _n("FUN_0033ea90", "esi") + 'extern "C" void __cdecl FUN_0033ea90(void*);'),
      ("FUN_0033ea90();", "FUN_0033ea90(p);")]),
    ("equivalent/0x00214a90.cpp", "luaG_runerror: addinfo 0x00214900 takes (L in ebx, msg on the stack)",
     [("void __cdecl FUN_00214900(int);", _n("FUN_00214900", "ebx stack") + "void __cdecl FUN_00214900(int, int);"),
      ("    FUN_00214900(result);", "    FUN_00214900(first, result);")]),
    ("equivalent/0x00214bd0.cpp", "lua_getinfo: info_tailcall 0x002141d0 takes (ar in esi, L on the stack)",
     [("extern void __cdecl FUN_002141d0(State_214bd0 *);",
       _n("FUN_002141d0", ESI_S) + "extern void __cdecl FUN_002141d0(DebugInfo_214bd0 *, State_214bd0 *);"),
      ("        FUN_002141d0(state);", "        FUN_002141d0(info, state);")]),
    ("equivalent/0x002150e0.cpp", "lua_open: close_state 0x00214f90 takes the new state in esi",
     [("extern void __cdecl FUN_00214f90();", _n("FUN_00214f90", "esi") + "extern void __cdecl FUN_00214f90(Object*);"),
      ("{ FUN_00214f90(); p=0; }", "{ FUN_00214f90(p); p=0; }")]),
    ("equivalent/0x00216ac0.cpp", "propagatemark: traverseclosure 0x002168d0 / traverseproto 0x00216810 take "
     "(the object in esi, the GC state on the stack)",
     [("void __cdecl FUN_002168d0(State_216ac0*);",
       _n("FUN_002168d0", ESI_S) + "void __cdecl FUN_002168d0(Node*, State_216ac0*);"),
      ("void __cdecl FUN_00216810(State_216ac0*);",
       _n("FUN_00216810", ESI_S) + "void __cdecl FUN_00216810(Node*, State_216ac0*);"),
      ("FUN_002168d0(state);", "FUN_002168d0(n,state);"), ("FUN_00216810(state);", "FUN_00216810(n,state);")]),
    ("equivalent/0x00217350.cpp", "singlestep: the sweep 0x00216e10 takes L in ebx after its two stack words; "
     "checkSizes 0x00216e70 takes L in ebx (eax held the sweep cursor by chance)",
     [("int __cdecl FUN_00216e10(int flag, int amount);",
       _n("FUN_00216e10", "stack stack ebx") + "int __cdecl FUN_00216e10(int flag, int amount, Object* object);"),
      ("FUN_00216e10(1,amount)", "FUN_00216e10(1,amount,object)"),
      ("// equiv-conv: FUN_00216e70 eax\nvoid __cdecl FUN_00216e70(Node* cursor);",
       "// equiv-conv: FUN_00216e70 ebx\nvoid __cdecl FUN_00216e70(Object* object);"),
      ("FUN_00216e70(p);", "FUN_00216e70(object);")]),
    ("equivalent/0x00217490.cpp", "luaC_callGCTM-style loop: GCTM 0x00216ed0 takes L in esi (eax held the "
     "pending list by chance)",
     [("// equiv-conv: FUN_00216ed0 eax\nvoid __cdecl FUN_00216ed0(unsigned int);",
       "// equiv-conv: FUN_00216ed0 esi\nvoid __cdecl FUN_00216ed0(Context*);"),
      ("FUN_00216ed0(context->state->pending);", "FUN_00216ed0(context);")]),
    ("equivalent/0x00219e90.cpp", "luaH_get: the generic lookup 0x00219d80 takes (key in edi, table on the stack)",
     [("extern void __cdecl FUN_00219d80(int);",
       _n("FUN_00219d80", "edi stack") + "extern void __cdecl FUN_00219d80(const Value *, int);"),
      ("    FUN_00219d80(context);", "    FUN_00219d80(value, context);")]),
    ("equivalent/0x00219fb0.cpp", "luaH_next's findindex: 0x00219980 takes (key in esi, the float on the stack)",
     [("extern int __cdecl FUN_00219980(float value);",
       _n("FUN_00219980", ESI_S) + "extern int __cdecl FUN_00219980(int* key, float value);"),
      ("FUN_00219980((float)ctx->index)", "FUN_00219980(key, (float)ctx->index)")]),
    ("equivalent/0x0021ad80.cpp", "luaU_dump: the header dump 0x0021acc0 takes the DumpState (the local) in esi",
     [("void FUN_0021acc0();", _n("FUN_0021acc0", "esi") + "void FUN_0021acc0(Values *);"),
      ("    FUN_0021acc0();", "    FUN_0021acc0(&v);")]),
    ("equivalent/0x0021c790.cpp", "singlevaraux: indexupvalue 0x0021c5f0 takes (fs in edi, name, v)",
     [("int __cdecl FUN_0021c5f0(unsigned,Result_21c790*);",
       _n("FUN_0021c5f0", "edi stack stack") + "int __cdecl FUN_0021c5f0(Object*,unsigned,Result_21c790*);"),
      ("FUN_0021c5f0(key,result)", "FUN_0021c5f0(object,key,result)")]),
    ("equivalent/0x0021ccb0.cpp", "str_checkname 0x0021c3d0 takes the LexState in esi",
     [("int __cdecl FUN_0021c3d0();", _n("FUN_0021c3d0", "esi") + "int __cdecl FUN_0021c3d0(LexState_21ccb0* ls);"),
      ("FUN_0021c3d0();", "FUN_0021c3d0(ls);")]),
    ("equivalent/0x0021db50.cpp", "simpleexp: body 0x0021d4b0 takes (ls in ebx, e, needself, line)",
     [("extern void __cdecl FUN_0021d4b0(Output_21db50*, int, unsigned int);",
       _n("FUN_0021d4b0", "ebx stack stack stack") +
       "extern void __cdecl FUN_0021d4b0(Input_21db50*, Output_21db50*, int, unsigned int);"),
      ("FUN_0021d4b0(output,0,input->value)", "FUN_0021d4b0(input,output,0,input->value)")]),
    ("equivalent/0x0021f280.cpp", "funcstat: body 0x0021d4b0 takes (ls in ebx, e, needself, line)",
     [("void __cdecl FUN_0021d4b0(expdesc_21f280* dst, expdesc_21f280* src, int arg);",
       _n("FUN_0021d4b0", "ebx stack stack stack") +
       "void __cdecl FUN_0021d4b0(LexState_21f280* ls, expdesc_21f280* dst, expdesc_21f280* src, int arg);"),
      ("FUN_0021d4b0(&f.second, r, arg)", "FUN_0021d4b0(ls, &f.second, r, arg)")]),
    # lundump's error(S, why, ...) 0x0021f800: the LoadState in esi, the format and its arguments on the stack
    ("equivalent/0x0021f940.cpp", "LoadBlock: error 0x0021f800 takes the LoadState in esi",
     [("extern void __cdecl FUN_0021f800(const char *);",
       _n("FUN_0021f800", ESI_S) + "extern void __cdecl FUN_0021f800(Reader *, const char *);"),
      ('FUN_0021f800("unexpected end of file")', 'FUN_0021f800(reader, "unexpected end of file")')]),
    ("equivalent/0x0021faf0.cpp", "LoadCode: error 0x0021f800 takes the LoadState in esi; LoadBlock 0x0021f940 "
     "takes the vector (the new block, in ecx) between the count and the LoadState",
     [("void __cdecl FUN_0021f800(const char *message);",
       _n("FUN_0021f800", ESI_S) + "void __cdecl FUN_0021f800(Source *source, const char *message);"),
      ('FUN_0021f800("bad integer")', 'FUN_0021f800(source, "bad integer")'),
      ("// equiv-conv: FUN_0021f940 eax edx stack\nvoid FUN_0021f940(int count, Source *source, int kind);",
       "// equiv-conv: FUN_0021f940 eax ecx edx stack\nvoid FUN_0021f940(int count, int data, Source *source, int kind);"),
      ("FUN_0021f940(count, source, 4)", "FUN_0021f940(count, destination->data, source, 4)")]),
    ("equivalent/0x0021fcb0.cpp", "LoadLines-style vector: error 0x0021f800 takes the LoadState in esi",
     [("void __cdecl FUN_0021f800(const char *);",
       _n("FUN_0021f800", ESI_S) + "void __cdecl FUN_0021f800(Source *, const char *);"),
      ('FUN_0021f800("bad integer")', 'FUN_0021f800(source, "bad integer")')]),
    ("equivalent/0x0021fd10.cpp", "LoadUpvalues: error 0x0021f800 takes the LoadState in esi",
     [("void __cdecl FUN_0021f800(const char*, ...);",
       _n("FUN_0021f800", ESI_S) + "void __cdecl FUN_0021f800(Reader*, const char*, ...);"),
      ('FUN_0021f800("', 'FUN_0021f800(reader, "')]),
    ("equivalent/0x0021fe20.cpp", "LoadConstants: error 0x0021f800 takes the LoadState in esi",
     [("void __cdecl FUN_0021f800(const char *fmt, ...);",
       _n("FUN_0021f800", ESI_S) + "void __cdecl FUN_0021f800(LoadState_21fe20 *S, const char *fmt, ...);"),
      ('FUN_0021f800("', 'FUN_0021f800(S, "')]),
    ("equivalent/0x00220220.cpp", "LoadSignature: error 0x0021f800 takes the LoadState in esi",
     [("void __cdecl FUN_0021f800(const char *msg);",
       _n("FUN_0021f800", ESI_S) + "void __cdecl FUN_0021f800(LoadState_220220 *S, const char *msg);"),
      ('FUN_0021f800("', 'FUN_0021f800(S, "')]),
    ("equivalent/0x002202a0.cpp", "TestSize: error 0x0021f800 takes the LoadState in esi",
     [("extern void __cdecl FUN_0021f800(const char *format, ...);",
       _n("FUN_0021f800", ESI_S) + "extern void __cdecl FUN_0021f800(Reader *reader, const char *format, ...);"),
      ('FUN_0021f800("', 'FUN_0021f800(reader, "')]),
    ("equivalent/0x00220310.cpp", "LoadHeader: error 0x0021f800 declared (msg, S): natively the definition's "
     "order (S, msg, ...)",
     [("// equiv-conv: FUN_0021f800 stack esi\nvoid FUN_0021f800(const char *msg, Reader *r, ...);",
       "// equiv-conv: FUN_0021f800 esi stack\nvoid FUN_0021f800(Reader *r, const char *msg, ...);"),
      ('FUN_0021f800("unexpected end of file", S)', 'FUN_0021f800(S, "unexpected end of file")'),
      ('FUN_0021f800("bad version (read %d.%d; expected at %s %d.%d)", S,',
       'FUN_0021f800(S, "bad version (read %d.%d; expected at %s %d.%d)",'),
      ('FUN_0021f800("unknown number format", S)', 'FUN_0021f800(S, "unknown number format")')]),
    ("equivalent/0x003392c0.cpp", "0x003391f0 takes the state in esi (the original's esi = the first argument)",
     [("void __cdecl FUN_003391f0();", _n("FUN_003391f0", "esi") + "void __cdecl FUN_003391f0(State*);"),
      (" FUN_003391f0();", " FUN_003391f0(state);")]),
    ("equivalent/0x0033a7a0.cpp", "db_sethook: gethooktable 0x0033a740 takes the thread in esi",
     [('extern "C" void __cdecl FUN_0033a740();', _n("FUN_0033a740", "esi") + 'extern "C" void __cdecl FUN_0033a740(U_33a7a0);'),
      ("FUN_0033a740();", "FUN_0033a740(context);")]),
    ("equivalent/0x0033a880.cpp", "db_gethook: gethooktable 0x0033a740 takes the thread in esi",
     [("void __cdecl FUN_0033a740();", _n("FUN_0033a740", "esi") + "void __cdecl FUN_0033a740(State*);"),
      ("FUN_0033a740();", "FUN_0033a740(source);")]),
    ("equivalent/0x0033e5e0.cpp", "0x0033e4d0 takes the state in esi",
     [("const char* __cdecl FUN_0033e4d0();", _n("FUN_0033e4d0", "esi") + "const char* __cdecl FUN_0033e4d0(LuaState*);"),
      ("FUN_0033e4d0();", "FUN_0033e4d0(state);")]),
    ("equivalent/0x0033e8f0.cpp", "auxwrap: auxresume 0x0033e7f0 takes (narg = lua_gettop(L) in eax, the coroutine "
     "in esi, L in edi); lua_gettop returns the count",
     [("int __cdecl FUN_00213290(void*, int); void __cdecl FUN_00212d70(void*); int __cdecl FUN_0033e7f0();",
       _n("FUN_0033e7f0", "eax esi edi") +
       "int __cdecl FUN_00213290(void*, int); int __cdecl FUN_00212d70(void*); int __cdecl FUN_0033e7f0(int, void*, void*);"),
      ("FUN_00213290(handle, -10002); FUN_00212d70(handle); int result = FUN_0033e7f0();",
       "int co = FUN_00213290(handle, -10002); int n = FUN_00212d70(handle); "
       "int result = FUN_0033e7f0(n, (void*)co, handle);")]),
    ("equivalent/0x00214e80.cpp", "f_luaopen: preinit_state 0x00214dd0 takes (L in edi, L1 in esi): both the state",
     [("// equiv-conv: FUN_00214dd0 edi\nextern void FUN_00214dd0(State_214e80*);",
       "// equiv-conv: FUN_00214dd0 edi esi\nextern void FUN_00214dd0(State_214e80*, State_214e80*);"),
      (" FUN_00214dd0(s);", " FUN_00214dd0(s, s);")]),
    ("equivalent/0x00215de0.cpp", "luaD_pcall: seterrorobj 0x00215240 takes L in edi after (status eax, oldtop ecx)",
     [('// equiv-conv: FUN_00215240 eax ecx\nextern "C" void __cdecl FUN_00215240(unsigned int, char*);',
       '// equiv-conv: FUN_00215240 eax ecx edi\nextern "C" void __cdecl FUN_00215240(unsigned int, char*, State_215de0*);'),
      ("FUN_00215240(result,position);", "FUN_00215240(result,position,s);")]),
    ("equivalent/0x00215d10.cpp", "lua_resume: resume_error 0x00215b00 takes (L in esi, msg in edx)",
     [("// equiv-conv: FUN_00215b00 edx\nextern int FUN_00215b00(const char*);",
       "// equiv-conv: FUN_00215b00 esi edx\nextern int FUN_00215b00(State_215d10*, const char*);"),
      ('FUN_00215b00("', 'FUN_00215b00(s, "')]),
    ("equivalent/0x0021a020.cpp", "luaH_next: findindex 0x00219fb0 takes (key eax, table edi, L on the stack)",
     [("// equiv-conv: FUN_00219fb0 eax stack\nint FUN_00219fb0(Value_21a020* output, void* context);",
       "// equiv-conv: FUN_00219fb0 eax edi stack\nint FUN_00219fb0(Value_21a020* output, Table_21a020* table, void* context);"),
      ("FUN_00219fb0(output, context)", "FUN_00219fb0(output, table, context)")]),
    ("equivalent/0x0021bbc0.cpp", "llex: read_long_string 0x0021b520 takes (ls ecx, sep eax = skip_sep's result, "
     "seminfo on the stack)",
     [("// equiv-conv: FUN_0021b520 ecx stack\n", "// equiv-conv: FUN_0021b520 ecx eax stack\n"),
      ("void FUN_0021b520(LexState_21bbc0 *ls, SemInfo_21bbc0 *seminfo);",
       "void FUN_0021b520(LexState_21bbc0 *ls, int sep, SemInfo_21bbc0 *seminfo);"),
      ("FUN_0021b520(ls, 0);", "FUN_0021b520(ls, sep, 0);"), ("FUN_0021b520(ls, seminfo);", "FUN_0021b520(ls, sep, seminfo);")]),
    ("equivalent/0x0021cd30.cpp", "checknext 0x0021c2e0 takes (ls esi, token eax)",
     [("// equiv-conv: FUN_0021c2e0 eax\nvoid FUN_0021c2e0(int);",
       "// equiv-conv: FUN_0021c2e0 esi eax\nvoid FUN_0021c2e0(State *, int);"),
      ("FUN_0021c2e0(0x5d);", "FUN_0021c2e0(state, 0x5d);")]),
    ("equivalent/0x0021cd90.cpp", "errorlimit 0x0021c240 takes (fs esi, what ecx, limit edx = 0x7ffffffd)",
     [("// equiv-conv: FUN_0021c240 ecx esi\nvoid FUN_0021c240(const char*, Context*);",
       "// equiv-conv: FUN_0021c240 esi ecx edx\nvoid FUN_0021c240(Context*, const char*, int);"),
      ('FUN_0021c240("items in a constructor", context)', 'FUN_0021c240(context, "items in a constructor", 0x7ffffffd)')]),
    ("equivalent/0x0021d4b0.cpp", "body: errorlimit 0x0021c240 takes fs (ls->fs) in esi; check_match 0x0021c340 "
     "takes ls in esi after the line (eax)",
     [("// equiv-conv: FUN_0021c240 ecx edx\nvoid FUN_0021c240(const char*, int);",
       "// equiv-conv: FUN_0021c240 esi ecx edx\nvoid FUN_0021c240(State_21d4b0*, const char*, int);"),
      ('FUN_0021c240("local variables", 200)', 'FUN_0021c240(state, "local variables", 200)'),
      ("// equiv-conv: FUN_0021c340 eax edi stack\nvoid __cdecl FUN_0021c340(int, int, int);",
       "// equiv-conv: FUN_0021c340 eax esi edi stack\nvoid __cdecl FUN_0021c340(int, Context*, int, int);"),
      ("FUN_0021c340(arg3, 0x106, 0x109)", "FUN_0021c340(arg3, ctx, 0x106, 0x109)")]),
    ("equivalent/0x0021ef60.cpp", "localfunc: errorlimit 0x0021c240 takes fs (ls->fs) in esi",
     [("// equiv-conv: FUN_0021c240 ecx edx\nvoid FUN_0021c240(const char *what, int limit);",
       "// equiv-conv: FUN_0021c240 esi ecx edx\nvoid FUN_0021c240(FuncState_21ef60 *fs, const char *what, int limit);"),
      ('FUN_0021c240("local variables", 200)', 'FUN_0021c240(cur, "local variables", 200)')]),
    ("equivalent/0x0021e5b0.cpp", "check_match 0x0021c340 takes ls in esi after the line (eax)",
     [("// equiv-conv: FUN_0021c340 eax edi stack\nvoid FUN_0021c340(int, int, int);",
       "// equiv-conv: FUN_0021c340 eax esi edi stack\nvoid FUN_0021c340(int, Parser_21e5b0*, int, int);"),
      ("FUN_0021c340(argument, 0x114, 0x110)", "FUN_0021c340(argument, parser, 0x114, 0x110)")]),
    ("equivalent/0x0021ecd0.cpp", "check_match 0x0021c340 takes ls in esi after the line (eax)",
     [("// equiv-conv: FUN_0021c340 eax edi stack\nextern void FUN_0021c340(int, int, int);",
       "// equiv-conv: FUN_0021c340 eax esi edi stack\nextern void FUN_0021c340(int, Parser_21ecd0*, int, int);"),
      ("FUN_0021c340(arg,0x106,0x108)", "FUN_0021c340(arg,p,0x106,0x108)")]),
    ("equivalent/0x0021ee70.cpp", "check_match 0x0021c340 takes ls in esi after the line (eax)",
     [("// equiv-conv: FUN_0021c340 eax edi stack\nint FUN_0021c340(int argument, int token, int mode);",
       "// equiv-conv: FUN_0021c340 eax esi edi stack\nint FUN_0021c340(int argument, State_21ee70* state, int token, int mode);"),
      ("FUN_0021c340(argument, 0x106, 0x10a)", "FUN_0021c340(argument, state, 0x106, 0x10a)")]),
    ("equivalent/0x0021f220.cpp", "funcname: str_checkname 0x0021c3d0 reads only ls (esi); field 0x0021ccb0 takes "
     "(ls eax, v ebx)",
     [("// equiv-conv: FUN_0021c3d0 ecx eax\nint FUN_0021c3d0(Parser *parser, int input);",
       "// equiv-conv: FUN_0021c3d0 esi\nint FUN_0021c3d0(Parser *parser);"),
      ("FUN_0021c3d0(parser, input)", "FUN_0021c3d0(parser)"),
      ("// equiv-conv: FUN_0021ccb0 eax\nvoid FUN_0021ccb0(Parser *parser);",
       "// equiv-conv: FUN_0021ccb0 eax ebx\nvoid FUN_0021ccb0(Parser *parser, int input);"),
      ("FUN_0021ccb0(parser);", "FUN_0021ccb0(parser, input);")]),
    ("equivalent/0x0021f300.cpp", "0x0021d830 takes (v eax, ls esi)",
     [("// equiv-conv: FUN_0021d830 eax\nvoid FUN_0021d830(int *value);",
       "// equiv-conv: FUN_0021d830 eax esi\nvoid FUN_0021d830(int *value, Object *object);"),
      ("FUN_0021d830(&values[1]);", "FUN_0021d830(&values[1], object);")]),
    ("equivalent/0x002207c0.cpp", "luaK_concat: fixjump 0x002204e0 takes (l2 eax, list ecx, fs ebx)",
     [("// equiv-conv: FUN_002204e0 eax\nvoid FUN_002204e0(int item);",
       "// equiv-conv: FUN_002204e0 eax ecx ebx\nvoid FUN_002204e0(int item, int index, NodeList **list);"),
      ("FUN_002204e0(item);", "FUN_002204e0(item, index, list);")]),
    ("equivalent/0x00220790.cpp", "dischargejpc: patchlistaux 0x00220650 takes fs in ebx after jpc (edx)",
     [("// equiv-conv: FUN_00220650 edx stack stack stack stack stack\nvoid FUN_00220650(int, int, int, int, int, int);",
       "// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack\n"
       "void FUN_00220650(int, Object*, int, int, int, int, int);"),
      ("FUN_00220650(state, value, 0xff, value, 0xff, value);", "FUN_00220650(state, object, value, 0xff, value, 0xff, value);")]),
    ("equivalent/0x00220b20.cpp", "luaK_code: patchlistaux 0x00220650 takes fs in ebx after jpc (edx)",
     [("// equiv-conv: FUN_00220650 edx stack stack stack stack stack\nvoid FUN_00220650(int marker, int a, int b, int c, int d, int e);",
       "// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack\n"
       "void FUN_00220650(int marker, Context* context, int a, int b, int c, int d, int e);"),
      ("FUN_00220650(context->marker, count, 255, count, 255, count);",
       "FUN_00220650(context->marker, context, count, 255, count, 255, count);")]),
    ("equivalent/0x00221430.cpp", "jumponcond: condjump 0x00220d10 takes fs in esi after A (eax)",
     [("// equiv-conv: FUN_00220d10 eax stack stack stack\nint FUN_00220d10(int a, int op, int b, int c);",
       "// equiv-conv: FUN_00220d10 eax esi stack stack stack\nint FUN_00220d10(int a, FuncState_221430* fs, int op, int b, int c);"),
      ("FUN_00220d10(0xff, 0x18,", "FUN_00220d10(0xff, fs, 0x18,")]),
    ("equivalent/0x00221860.cpp", "codebinop: condjump 0x00220d10 takes (A = cond in eax, fs in esi, op, B, C)",
     [("// equiv-conv: FUN_00220d10 stack stack stack eax\nint FUN_00220d10(int op, int b, int c, int cond);",
       "// equiv-conv: FUN_00220d10 eax esi stack stack stack\nint FUN_00220d10(int cond, FuncState_221860* fs, int op, int b, int c);"),
      ("FUN_00220d10(((int*)((char*)&DAT_004271d4 + 32))[op], o2, o1, cond)",
       "FUN_00220d10(cond, fs, ((int*)((char*)&DAT_004271d4 + 32))[op], o2, o1)")]),
    ("equivalent/0x00220f80.cpp", "luaK_exp2nextreg: discharge2reg 0x00220e90 takes (e ebx, reg esi, fs edi)",
     [("// equiv-conv: FUN_00220e90 eax ebx esi\nvoid FUN_00220e90(int newCount, int *expression, int previousCount);",
       "// equiv-conv: FUN_00220e90 ebx esi edi\nvoid FUN_00220e90(int *expression, int reg, Context *context);"),
      ("FUN_00220e90(context->count, expression, context->count - 1);",
       "FUN_00220e90(expression, context->count - 1, context);")]),
    ("equivalent/0x00220fe0.cpp", "luaK_exp2reg: discharge2reg 0x00220e90 takes (e ebx, reg esi, fs edi)",
     [("// equiv-conv: FUN_00220e90 eax ebx esi\nvoid __cdecl FUN_00220e90(Context*, Record_220fe0*, int);",
       "// equiv-conv: FUN_00220e90 ebx esi edi\nvoid __cdecl FUN_00220e90(Record_220fe0*, int, Context*);"),
      (" FUN_00220e90(ctx, rec, flag);", " FUN_00220e90(rec, flag, ctx);")]),
    ("equivalent/0x002218d0.cpp", "luaK_posfix: codebinop 0x00221860 takes (rk(e2) eax, rk(e1) ecx, op edx, "
     "e1 edi, fs on the stack)",
     [("// equiv-conv: FUN_00221860 ecx edx stack eax\nvoid FUN_00221860(void* self, int sel, Ctx_2218d0* c, void* extra);",
       "// equiv-conv: FUN_00221860 eax ecx edx edi stack\n"
       "void FUN_00221860(void* extra, void* self, int sel, Operand_2218d0* a, Ctx_2218d0* c);"),
      ("FUN_00221860(self, sel, c, extra);", "FUN_00221860(extra, self, sel, a, c);")]),
    ("equivalent/0x00339ba0.cpp", "0x00339ad0 takes the state in esi after the status (eax)",
     [("// equiv-conv: FUN_00339ad0 eax\nvoid FUN_00339ad0(int);", "// equiv-conv: FUN_00339ad0 eax esi\nvoid FUN_00339ad0(int, int);"),
      ("FUN_00339ad0(result);", "FUN_00339ad0(result, source);")]),
    ("equivalent/0x0033c4d0.cpp", "singlematch: matchbracketclass 0x0033c430 takes (c ebx, p eax, ec on the stack)",
     [("// equiv-conv: FUN_0033c430 eax stack\nunsigned int FUN_0033c430(const char *text, int remaining);",
       "// equiv-conv: FUN_0033c430 ebx eax stack\nunsigned int FUN_0033c430(unsigned int c, const char *text, int remaining);"),
      ("FUN_0033c430(text, remaining - 1)", "FUN_0033c430(character, text, remaining - 1)")]),
    ("equivalent/0x0033cec0.cpp", "add_value: push_captures 0x0033cb70 takes (ms esi, s ecx, e eax)",
     [("// equiv-conv: FUN_0033cb70 ecx eax\nextern void* FUN_0033cb70(int, int);",
       "// equiv-conv: FUN_0033cb70 esi ecx eax\nextern void* FUN_0033cb70(Context*, int, int);"),
      ("FUN_0033cb70(a,b)", "FUN_0033cb70(context,a,b)")]),
    ("equivalent/0x00218170.cpp", "luaV_arith-style: call_binTM's helpers in their definitions' orders "
     "(0x00217750: ecx stack eax edx, 0x00217790: ecx eax, 0x00217af0: esi ebx edi stack stack; native6's "
     "build/native6/try version)",
     [("// equiv-conv: FUN_00217750 eax ecx edx stack\nvoid FUN_00217750(TV *lhs, Ctx_218170 *ctx, TV *rhs, TV *fn);",
       "// equiv-conv: FUN_00217750 ecx stack eax edx\nvoid FUN_00217750(Ctx_218170 *ctx, TV *fn, TV *lhs, TV *rhs);"),
      ("// equiv-conv: FUN_00217790 eax ecx\nvoid FUN_00217790(TV *res, ...);",
       "// equiv-conv: FUN_00217790 ecx eax\nvoid FUN_00217790(Ctx_218170 *ctx, TV *res);"),
      ("// equiv-conv: FUN_00217af0 stack stack ebx esi edi\nint FUN_00217af0(TV *res, int op, TV *lhs, Ctx_218170 *ctx, TV *rhs);",
       "// equiv-conv: FUN_00217af0 esi ebx edi stack stack\nint FUN_00217af0(Ctx_218170 *ctx, TV *lhs, TV *rhs, TV *res, int op);"),
      ("FUN_00217750(b, ctx, a, h);", "FUN_00217750(ctx, h, b, a);"), ("FUN_00217790(res, ctx);", "FUN_00217790(ctx, res);"),
      ("FUN_00217af0(res, op, lhs, ctx, rhs)", "FUN_00217af0(ctx, lhs, rhs, res, op)")]),
    # --- game code -----------------------------------------------------------------------------------------
    ("equivalent/0x00035ab0.cpp", "0x00035ab0 is a thiscall member returning bool (al): `this` in ecx, eax only "
     "carried the caller's leftover upper bytes into `xor al, al`; the definition becomes `bool Object::f()`, which "
     "is how its 15 callers already call it (with no note)",
     [(OLD_35AB0, NEW_35AB0)]),
    ("equivalent/0x002e7560.cpp", "png_get_uint_16: the result is ax (`movzx ax`); the definition modelled eax's "
     "upper half from the caller's eax as a parameter, which its callers (unsigned short, no note) don't pass",
     [("// equiv-conv: FUN_002e7560 eax stack\nunsigned int __cdecl FUN_002e7560(unsigned int incomingEax, const byte *data)\n{\n"
       "    unsigned int upper = (incomingEax & 0xffff0000u) << 8;\n"
       "    return upper + ((unsigned int)data & 0xffff0000u) + ((unsigned int)data[0] << 8) + data[1];\n}",
       "// png_get_uint_16: the result is ax (the original's `movzx ax, ...` leaves eax's upper half as it was)\n"
       "unsigned short __cdecl FUN_002e7560(const byte *data)\n{\n"
       "    return (unsigned short)((data[0] << 8) + data[1]);\n}")]),
    ("equivalent/0x0024b920.cpp", "the `ebx` parameter is a register save: the original's `push ebx` before the "
     "0-argument timer 0x00267f80 is popped at the end (0x00267f80 reads no argument)",
     [("int FUN_00267f80(unsigned int live);", "int FUN_00267f80();"),
      ("// equiv-conv: FUN_0024b920 esi ebx\nvoid FUN_0024b920(Player_24b920 *p, unsigned int live)",
       "// equiv-conv: FUN_0024b920 esi\nvoid FUN_0024b920(Player_24b920 *p)"),
      ("FUN_00267f80(live)", "FUN_00267f80()")]),
    ("equivalent/0x0024bc70.cpp", "the `ebx` parameter only fed 0x0024b920's register save (see 0x0024b920): "
     "its 5 callers pass the player alone",
     [("// equiv-conv: FUN_0024b920 esi ebx\nvoid FUN_0024b920(Player_24bc70 *p, unsigned int live);",
       "// equiv-conv: FUN_0024b920 esi\nvoid FUN_0024b920(Player_24bc70 *p);"),
      ("// equiv-conv: FUN_0024bc70 eax ebx\nvoid FUN_0024bc70(Player_24bc70 *p, unsigned int live)",
       "// equiv-conv: FUN_0024bc70 eax\nvoid FUN_0024bc70(Player_24bc70 *p)"),
      ("FUN_0024b920(p, live);", "FUN_0024b920(p);")]),
    ("equivalent/0x000e0850.cpp", "debug quad: the line helper 0x000e07c0 takes the vertex handle in esi",
     [("void __cdecl FUN_000e07c0(Vec3_e0850 a, Vec3_e0850 b, int color);",
       _n("FUN_000e07c0", "esi stack stack stack") + "void __cdecl FUN_000e07c0(int handle, Vec3_e0850 a, Vec3_e0850 b, int color);"),
      ("        FUN_000e07c0(", "        FUN_000e07c0(handle, ")]),
    ("equivalent/0x000e0e50.cpp", "debug box: the line helper 0x000e07c0 takes the vertex handle in esi",
     [("void __cdecl FUN_000e07c0(Vec3_e0e50 a, Vec3_e0e50 b, int color);",
       _n("FUN_000e07c0", "esi stack stack stack") + "void __cdecl FUN_000e07c0(int handle, Vec3_e0e50 a, Vec3_e0e50 b, int color);"),
      ("        FUN_000e07c0(", "        FUN_000e07c0(handle, ")]),
    ("equivalent/0x0019e430.cpp", "0x001947a0 takes the target position (f.tmp) in esi before (fighter, step)",
     [("void __cdecl FUN_001947a0(Stats_19e430 *fighter, float x);",
       _n("FUN_001947a0", "esi stack stack") + "void __cdecl FUN_001947a0(V3_19e430 *pos, Stats_19e430 *fighter, float x);"),
      ("FUN_001947a0(f.fighter, f.s14.f);", "FUN_001947a0(&f.tmp, f.fighter, f.s14.f);")]),
    ("equivalent/0x001b0470.cpp", "0x001b0310 takes (attacker esi = self, victim edi = item); the member call "
     "passed only ecx",
     [("extern bool __cdecl FUN_00044500(int);",
       _n("FUN_001b0310", "esi edi") + "float FUN_001b0310(Actor_1b0470 *self, Item_1b0470 *item);\n"
       "extern bool __cdecl FUN_00044500(int);"),
      ("self->FUN_001b0310();", "FUN_001b0310(self, item);")]),
    ("equivalent/0x001bc5b0.cpp", "0x001bc5b0 itself takes the bounds rect in eax (`mov esi, eax`) and hands it to "
     "0x001bc530 (rect esi, point on the stack)",
     [("void FUN_001bc530(Vec3_1bc5b0 *v);",
       "struct Rect_1bc5b0;\n" + _n("FUN_001bc530", ESI_S) + "void FUN_001bc530(Rect_1bc5b0 *rect, Vec3_1bc5b0 *v);"),
      ("// equiv-conv: FUN_001bc5b0 edi stack\nvoid FUN_001bc5b0(Vec3_1bc5b0 *pos, float a)",
       "// equiv-conv: FUN_001bc5b0 eax edi stack\nvoid FUN_001bc5b0(Rect_1bc5b0 *rect, Vec3_1bc5b0 *pos, float a)"),
      ("FUN_001bc530(&v);", "FUN_001bc530(rect, &v);")]),
    ("equivalent/0x001bc8a0.cpp", "0x001bc5b0 takes the bounds rect (q, in eax) before (pos edi, a)",
     [("// equiv-conv: FUN_001bc5b0 edi stack\nvoid FUN_001bc5b0(V3_1bc8a0 *pos, float a);",
       "// equiv-conv: FUN_001bc5b0 eax edi stack\nvoid FUN_001bc5b0(V4_1bc8a0 *q, V3_1bc8a0 *pos, float a);"),
      ("FUN_001bc5b0(&p, obj->c.f54);", "FUN_001bc5b0(q, &p, obj->c.f54);"), ("FUN_001bc5b0(pos, a);", "FUN_001bc5b0(q, pos, a);")]),
    ("equivalent/0x002497e0.cpp", "0x00249750 takes the item in esi (the member call passed the owner's flags in ecx)",
     [("unsigned short __cdecl FUN_002497e0(Item* item) {",
       "\n" + _n("FUN_00249750", "esi") + "int FUN_00249750(Item*);\nunsigned short __cdecl FUN_002497e0(Item* item) {"),
      ("unsigned short result = flags->FUN_00249750();", "unsigned short result = (unsigned short)FUN_00249750(item);")]),
    ("equivalent/0x0024a3c0.cpp", "the state handlers take the object in esi (0x00249810, 0x00248780: then a stack "
     "word) and 0x00248670 (x in edi, the object in esi, a)",
     [("void __cdecl FUN_00249810(int x);", _n("FUN_00249810", ESI_S) + "void __cdecl FUN_00249810(Obj_24a3c0 *o, int x);"),
      ("void __cdecl FUN_00248670(int a);", _n("FUN_00248670", "edi esi stack") + "void __cdecl FUN_00248670(int x, Obj_24a3c0 *o, int a);"),
      ("void __cdecl FUN_00248780(int a);", _n("FUN_00248780", ESI_S) + "void __cdecl FUN_00248780(Obj_24a3c0 *o, int a);"),
      ("FUN_00249810(x);", "FUN_00249810(o, x);"), ("FUN_00248670(a);", "FUN_00248670(x, o, a);"),
      ("FUN_00248780(a);", "FUN_00248780(o, a);")]),
    ("equivalent/0x0025e290.cpp", "0x0025e230 takes the object in edi",
     [("}; void __cdecl FUN_0025e230();", "};\n" + _n("FUN_0025e230", "edi") + "void __cdecl FUN_0025e230(Object*);"),
      ("FUN_0025e230();", "FUN_0025e230(obj);")]),
    ("equivalent/0x0025e550.cpp", "0x0025e230 takes the object in edi",
     [("}; void __cdecl FUN_0025e230();", "};\n" + _n("FUN_0025e230", "edi") + "void __cdecl FUN_0025e230(Object*);"),
      ("FUN_0025e230();", "FUN_0025e230(obj);")]),
    ("equivalent/0x002931c0.cpp", "0x00292f60 takes the TRAN and LOOK channels in esi/edi before the time",
     [("void __cdecl FUN_00292f60(float *t);",
       _n("FUN_00292f60", "esi edi stack") + "void __cdecl FUN_00292f60(Channel *tran, Channel *look, float *t);"),
      ("FUN_00292f60(&fr.t);", "FUN_00292f60(tran, look, &fr.t);")]),
    ("equivalent/0x00293450.cpp", "0x00292f60 takes the TRAN and LOOK channels in esi/edi before the time",
     [("void __cdecl FUN_00292f60(float *t);",
       _n("FUN_00292f60", "esi edi stack") + "void __cdecl FUN_00292f60(Channel *tran, Channel *look, float *t);"),
      ("FUN_00292f60(&fr.A);", "FUN_00292f60(tran, look, &fr.A);")]),
    ("equivalent/0x00335010.cpp", "0x00334b00 (a member reading `this` from esi) is called on req, which the "
     "original has in esi: the note makes equiv.py check it (natively both sides are thiscall)",
     [("    unsigned int startTime;\n    void FUN_00334b00();",
       "    unsigned int startTime;\n    " + _n("FUN_00334b00", "esi") + "    void FUN_00334b00();")]),
    ("equivalent/0x000cf4b0.cpp", "0x000cb7d0 moves *ecx toward *edx (= &f480) by the stack limit",
     [("// equiv-conv: FUN_000cb7d0 ecx stack\nvoid __cdecl FUN_000cb7d0(float *obj, float v);",
       "// equiv-conv: FUN_000cb7d0 ecx edx stack\nvoid __cdecl FUN_000cb7d0(float *obj, float *target, float v);"),
      ("FUN_000cb7d0(&f484, dt * f48c);", "FUN_000cb7d0(&f484, &f480, dt * f48c);")]),
    ("equivalent/0x00148730.cpp", "0x00148580 takes the track (this, in edi) after (builder ecx, local esi)",
     [("// equiv-conv: FUN_00148580 ecx esi\nvoid FUN_00148580(Builder_148730*, Local_148730*);",
       "// equiv-conv: FUN_00148580 ecx esi edi\nvoid FUN_00148580(Builder_148730*, Local_148730*, void*);"),
      ("FUN_00148580(FUN_0005a470(actor), &local);", "FUN_00148580(FUN_0005a470(actor), &local, this);")]),
    ("equivalent/0x0014f110.cpp", "0x0014efd0 takes (owner ebx, the track esi, settings edi)",
     [("// equiv-conv: FUN_0014efd0 esi edi\nextern void FUN_0014efd0(hulkfight::motion::HitReactionTrack*, Settings_14f110*);",
       "// equiv-conv: FUN_0014efd0 ebx esi edi\n"
       "extern void FUN_0014efd0(Owner_14f110*, hulkfight::motion::HitReactionTrack*, Settings_14f110*);"),
      ("FUN_0014efd0(this,&settings);", "FUN_0014efd0(owner,this,&settings);")]),
    ("equivalent/0x0014f470.cpp", "0x0014f2f0 takes (context eax, the track esi, temporary edi)",
     [("// equiv-conv: FUN_0014f2f0 eax edi\nextern void FUN_0014f2f0(Context_14f470*, Temporary_14f470*);",
       "// equiv-conv: FUN_0014f2f0 eax esi edi\nextern void FUN_0014f2f0(Context_14f470*, void*, Temporary_14f470*);"),
      ("FUN_0014f2f0(context, &temporary);", "FUN_0014f2f0(context, (void*)this, &temporary);")]),
    ("equivalent/0x00199060.cpp", "0x00195560 takes a3 in ebx after (ecx, eax)",
     [("// equiv-conv: FUN_00195560 ecx eax stack", "// equiv-conv: FUN_00195560 ecx eax ebx stack"),
      ("char FUN_00195560(V3_199060 *pn, void *own, int f1c,", "char FUN_00195560(V3_199060 *pn, void *own, V3_199060 *b, int f1c,"),
      ("FUN_00195560(&fr.Q, ((Carried *)carriedObj)->f12c, f1c,", "FUN_00195560(&fr.Q, ((Carried *)carriedObj)->f12c, a3, f1c,")]),
    ("equivalent/0x002d0a50.cpp", "the four draw paths take (object, flag e, c) in their own registers: "
     "0x002cec10 ecx edx esi, 0x002cd130 eax edx esi, 0x002c7e40 eax ecx esi, 0x002c8130 (flag ecx, object eax, c esi)",
     [("// equiv-conv: FUN_002cec10 ecx esi\nvoid FUN_002cec10(Object*,unsigned,bool);",
       "// equiv-conv: FUN_002cec10 ecx edx esi\nvoid FUN_002cec10(Object*,bool,unsigned);"),
      ("// equiv-conv: FUN_002cd130 eax esi\nvoid FUN_002cd130(Object*,unsigned,bool);",
       "// equiv-conv: FUN_002cd130 eax edx esi\nvoid FUN_002cd130(Object*,bool,unsigned);"),
      ("// equiv-conv: FUN_002c7e40 eax esi\nvoid FUN_002c7e40(Object*,unsigned,bool);",
       "// equiv-conv: FUN_002c7e40 eax ecx esi\nvoid FUN_002c7e40(Object*,bool,unsigned);"),
      ("// equiv-conv: FUN_002c8130 eax esi\nvoid FUN_002c8130(Object*,unsigned,bool);",
       "// equiv-conv: FUN_002c8130 ecx eax esi\nvoid FUN_002c8130(bool,Object*,unsigned);"),
      ("FUN_002cd130(this,c,e)", "FUN_002cd130(this,e,c)"), ("FUN_002cec10(this,c,e)", "FUN_002cec10(this,e,c)"),
      ("FUN_002c7e40(this,c,e)", "FUN_002c7e40(this,e,c)"), ("FUN_002c8130(this,c,e)", "FUN_002c8130(e,this,c)")]),
    ("equivalent/0x002ddb40.cpp", "the true-colour reader 0x002dd9e0 takes (out ebx, stream edi, header on the stack)",
     [("// equiv-conv: FUN_002dd9e0 stack ebx\n", "// equiv-conv: FUN_002dd9e0 ebx edi stack\n"),
      ("void FUN_002dd9e0(TgaHeader *hdr, void *out);", "void FUN_002dd9e0(void *out, Stream_2ddb40 *stream, TgaHeader *hdr);"),
      ("FUN_002dd9e0(&hdr, out);", "FUN_002dd9e0(out, stream, &hdr);")]),
    ("equivalent/0x002de990.cpp", "0x002de600 takes (value eax, data ecx, context esi); 0x002de6c0 (value eax, "
     "context esi, item on the stack)",
     [("// equiv-conv: FUN_002de600 ecx eax\nvoid FUN_002de600(void *data, void *value);",
       "struct Context;\n// equiv-conv: FUN_002de600 eax ecx esi\nvoid FUN_002de600(void *value, void *data, Context *context);"),
      ("// equiv-conv: FUN_002de6c0 ecx eax stack\nvoid FUN_002de6c0(Item *regItem, void *value, Item *item);",
       "// equiv-conv: FUN_002de6c0 eax esi stack\nvoid FUN_002de6c0(void *value, Context *context, Item *item);"),
      ("FUN_002de600(item->data, context->value);", "FUN_002de600(context->value, item->data, context);"),
      ("FUN_002de6c0(item, context->value, item);", "FUN_002de6c0(context->value, context, item);")]),
    ("equivalent/0x002de9c0.cpp", "0x002de8b0 takes (value eax, context esi, item on the stack)",
     [("// equiv-conv: FUN_002de8b0 eax stack\nvoid FUN_002de8b0(void* value, Item* item);",
       "// equiv-conv: FUN_002de8b0 eax esi stack\nvoid FUN_002de8b0(void* value, Context* context, Item* item);"),
      ("FUN_002de8b0(context->value, item);", "FUN_002de8b0(context->value, context, item);")]),
    ("equivalent/0x003068a0.cpp", "0x00306790 takes the other volume in ebx after this (eax)",
     [("// equiv-conv: FUN_00306790 eax stack\nvoid __cdecl FUN_00306790(physics::CollisionVolume*, void*);",
       "// equiv-conv: FUN_00306790 eax ebx stack\n"
       "void __cdecl FUN_00306790(physics::CollisionVolume*, physics::CollisionVolume*, void*);"),
      ("FUN_00306790(this, arg);", "FUN_00306790(this, other, arg);")]),
]

# the text-encoding dispatchers 0x0026b380-0x0026b740 tail-jump (`jmp`) to their converters with the converter's
# three stack words rewritten from their own registers (edi, esi, edx): the sources passed only the first
_DISPATCH = {
    "0026b380": ["00269a80", "00269b10", "00269ba0", "00269c40", "00269ce0", "00269d70"],
    "0026b440": ["00269e90", "00269f20", "00269fb0", "0026a050", "0026a0f0", "0026a180"],
    "0026b500": ["0026a2a0", "0026a350", "0026a400", "0026a4a0", "0026a550", "0026a600"],
    "0026b5c0": ["0026a750", "0026a800", "0026a8b0", "0026a960", "0026aa00", "0026aab0"],
    "0026b680": ["0026abf0", "0026ac80", "0026ad10", "0026adb0", "0026ae50", "0026aee0"],
    "0026b740": ["0026b000", "0026b090", "0026b120", "0026b1c0", "0026b260", "0026b2f0"],
}
for _d, _cs in sorted(_DISPATCH.items()):
    _edits = []
    for _c in _cs:
        _edits.append(("// equiv-conv: FUN_%s eax ecx stack\nextern \"C\" int __cdecl FUN_%s(int c, int a, int p2);" % (_c, _c),
                       "// equiv-conv: FUN_%s eax ecx stack stack stack\n"
                       "extern \"C\" int __cdecl FUN_%s(int c, int a, int p2, int p3, int p4);" % (_c, _c)))
        _edits.append(("return FUN_%s(c, a, ediArg);" % _c, "return FUN_%s(c, a, ediArg, esiArg, edxArg);" % _c))
    REG_CALLS.append(("equivalent/0x%s.cpp" % _d, "tail calls pass all three stack words the converter reads "
                      "(edi, esi, edx: the original rewrites its own argument slots before the jmp)", _edits))

# index2adr 0x00212bb0 is a __fastcall match (idx in ecx, L in edx): its callers declared it __cdecl with an
# equiv-conv note, so natively they pushed both words and the definition read ecx/edx (start-up trace: lua_type
# inside luaL_openlib). Declared __fastcall (parameters in ecx, edx order), no note.
_BB0 = [
    ('equivalent/0x00212e60.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('TObject_212e60* FUN_00212bb0(lua_State_212e60* L, int idx);', 'TObject_212e60* __fastcall FUN_00212bb0(int idx, lua_State_212e60* L);'), ('FUN_00212bb0(L, idx)', 'FUN_00212bb0(idx, L)')]),
    ('equivalent/0x00212f00.cpp', [('// equiv-conv: FUN_00212bb0 ecx edx\n', ''), ('int* FUN_00212bb0(int second, int first);', 'int* __fastcall FUN_00212bb0(int second, int first);')]),
    ('equivalent/0x00212f70.cpp', [('// equiv-conv: FUN_00212bb0 ecx edx\n', ''), ('Result* FUN_00212bb0(void* first, void* second);', 'Result* __fastcall FUN_00212bb0(void* first, void* second);')]),
    ('equivalent/0x00212fb0.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('int *FUN_00212bb0(void *first, void *second);', 'int *__fastcall FUN_00212bb0(void *second, void *first);'), ('FUN_00212bb0(first, second)', 'FUN_00212bb0(second, first)')]),
    ('equivalent/0x00212fe0.cpp', [('// equiv-conv: FUN_00212bb0 ecx edx\n', ''), ('int* FUN_00212bb0(int first, int second);', 'int* __fastcall FUN_00212bb0(int first, int second);')]),
    ('equivalent/0x002130e0.cpp', [('// equiv-conv: FUN_00212bb0 ecx edx\n', ''), ('Entry* FUN_00212bb0(void* second, void* first);', 'Entry* __fastcall FUN_00212bb0(void* second, void* first);')]),
    ('equivalent/0x00213120.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('const TObject* FUN_00212bb0(lua_State* L, int idx);', 'const TObject* __fastcall FUN_00212bb0(int idx, lua_State* L);'), ('FUN_00212bb0(L, idx)', 'FUN_00212bb0(idx, L)')]),
    ('equivalent/0x00213160.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('int* FUN_00212bb0(int first, int second);', 'int* __fastcall FUN_00212bb0(int second, int first);'), ('FUN_00212bb0(first, second)', 'FUN_00212bb0(second, first)')]),
    ('equivalent/0x00213260.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('Result* FUN_00212bb0(int first, int second);', 'Result* __fastcall FUN_00212bb0(int second, int first);'), ('FUN_00212bb0(first, second)', 'FUN_00212bb0(second, first)')]),
    ('equivalent/0x002132b0.cpp', [('// equiv-conv: FUN_00212bb0 ecx edx\n', ''), ('Entry *FUN_00212bb0(int second, int first);', 'Entry *__fastcall FUN_00212bb0(int second, int first);')]),
    ('equivalent/0x00213870.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('TObject_213870 *FUN_00212bb0(lua_State_213870 *L, int idx);', 'TObject_213870 *__fastcall FUN_00212bb0(int idx, lua_State_213870 *L);'), ('FUN_00212bb0(L, idx)', 'FUN_00212bb0(idx, L)')]),
    ('equivalent/0x002138e0.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('TObject_2138e0* FUN_00212bb0(lua_State_2138e0* L, int idx);', 'TObject_2138e0* __fastcall FUN_00212bb0(int idx, lua_State_2138e0* L);'), ('FUN_00212bb0(L, objindex)', 'FUN_00212bb0(objindex, L)')]),
    ('equivalent/0x00213e50.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx\n', ''), ('TObject_213e50 *FUN_00212bb0(lua_State_213e50 *L, int idx);', 'TObject_213e50 *__fastcall FUN_00212bb0(int idx, lua_State_213e50 *L);'), ('FUN_00212bb0(L, funcindex)', 'FUN_00212bb0(funcindex, L)')]),
    ('equivalent/0x00213570.cpp', [('// equiv-conv: FUN_00212bb0 edx ecx stack stack\nint __cdecl FUN_00212bb0(Item* item, int other, int size1, int size2);', 'int __fastcall FUN_00212bb0(int other, Item* item);'), ('FUN_00212bb0(item, other, size, size)', 'FUN_00212bb0(other, item)')]),
]
for _f, _e in _BB0:
    REG_CALLS.append((_f, "index2adr 0x00212bb0 is __fastcall (idx ecx, L edx): declared so, not __cdecl with a note", _e))

# --- check 5 after `target`/`run` notes count as the definition's own (native7) ---------------------------------
REG_CALLS += [
    ("equivalent/0x002209b0.cpp", "luaK_numberK: addk 0x002208e0 takes (fs ebx, k ecx, v on the stack): fs is the "
     "first argument, k and v the same local",
     [("int __cdecl FUN_002208e0(Args *);", _n("FUN_002208e0", "ebx ecx stack") + "int __cdecl FUN_002208e0(int fs, Args *k, Args *v);"),
      ("return FUN_002208e0(&args);", "return FUN_002208e0(unused, &args, &args);")]),
    ("equivalent/0x002209e0.cpp", "luaK_stringK-style: addk 0x002208e0 takes (fs ebx, k ecx, v on the stack)",
     [("int __cdecl FUN_002208e0(Args *); int __cdecl FUN_002209e0(",
       "\n" + _n("FUN_002208e0", "ebx ecx stack") + "int __cdecl FUN_002208e0(int fs, Args *k, Args *v); int __cdecl FUN_002209e0("),
      ("return FUN_002208e0(&args);", "return FUN_002208e0(unused, &args, &args);")]),
    ("equivalent/0x00220a10.cpp", "nil constant: addk 0x002208e0 takes fs in ebx before (k ecx, v)",
     [("// equiv-conv: FUN_002208e0 ecx stack\nint FUN_002208e0(Request*, int*);",
       "// equiv-conv: FUN_002208e0 ebx ecx stack\nint FUN_002208e0(Source*, Request*, int*);"),
      ("return FUN_002208e0(&request, &request.result);", "return FUN_002208e0(source, &request, &request.result);")]),
    ("equivalent/0x00168900.cpp", "0x001687a0 takes field_c in esi after the target (ecx)",
     [("// equiv-conv: FUN_001687a0 ecx stack stack\nvoid __cdecl FUN_001687a0(GrappleTarget*, int, int);",
       "// equiv-conv: FUN_001687a0 ecx esi stack stack\nvoid __cdecl FUN_001687a0(GrappleTarget*, int, int, int);"),
      ("FUN_001687a0(target, field_14, field_10);", "FUN_001687a0(target, field_c, field_14, field_10);")]),
    ("equivalent/0x00221700.cpp", "0x00221610 takes (the expression esi, fs edi); eax held the flag by chance",
     [("// equiv-conv: FUN_00221610 edi eax esi\nvoid FUN_00221610(Context*,int,Node*);",
       "// equiv-conv: FUN_00221610 esi edi\nvoid FUN_00221610(Node*,Context*);"),
      ("FUN_00221610(context,flag,node);", "FUN_00221610(node,context);")]),
    ("equivalent/0x0024a800.cpp", "0x00249630 takes (scene edi, ctx on the stack) in that order",
     [("// equiv-conv: FUN_00249630 stack edi\nvoid __cdecl FUN_00249630(Context *ctx, Scene *scene);",
       "// equiv-conv: FUN_00249630 edi stack\nvoid __cdecl FUN_00249630(Scene *scene, Context *ctx);"),
      ("FUN_00249630(ctx, scene);", "FUN_00249630(scene, ctx);")]),
]

# --- check 9: callers' notes for definitions without one (their real convention decides) ----------------------
REG_CALLS += [
    ("equivalent/0x00214ac0.cpp", "currentline 0x00213f20 is a __fastcall match reading only edx (its ecx "
     "parameter is unused): declared so, ecx passed as 0",
     [("// equiv-conv: FUN_00213f20 edx\nint FUN_00213f20(CallInfo *ci);", "int __fastcall FUN_00213f20(int unused, CallInfo *ci);"),
      ("FUN_00213f20(ci)", "FUN_00213f20(0, ci)")]),
    ("equivalent/0x00326330.cpp", "0x00325fb0 is a __fastcall match (ecx ignored, the mask in edx)",
     [("// equiv-conv: FUN_00325fb0 edx\nint __cdecl FUN_00325fb0(int field);", "int __fastcall FUN_00325fb0(int ignored, int field);"),
      ("FUN_00325fb0(field0b4)", "FUN_00325fb0(0, field0b4)")]),
    ("equivalent/0x003265f0.cpp", "0x00325fb0 is a __fastcall match (ecx ignored, the mask in edx)",
     [("// equiv-conv: FUN_00325fb0 edx\nint FUN_00325fb0(int mask);", "int __fastcall FUN_00325fb0(int ignored, int mask);"),
      ("FUN_00325fb0(layout.mask)", "FUN_00325fb0(0, layout.mask)")]),
    ("equivalent/0x0012f930.cpp", "0x000862e0 is a one-argument __fastcall getter; the three words pushed before it "
     "are the next call's (0x001eb5e0)",
     [("// equiv-conv: FUN_000862e0 ecx stack stack stack\nSoundHandle *__cdecl FUN_000862e0(SoundSystem *, SoundValue *, unsigned int, unsigned int);",
       "SoundHandle *__fastcall FUN_000862e0(SoundSystem *);"),
      ("FUN_000862e0(DAT_004dd6ec, &value, sound, extra)", "FUN_000862e0(DAT_004dd6ec)")]),
    ("equivalent/0x002632c0.cpp", "0x0023fb00 is a one-argument __fastcall; the seven words pushed before it are "
     "the next call's (its result is stored into the first)",
     [("// equiv-conv: FUN_0023fb00 ecx stack stack stack stack stack stack stack\n"
       "void* __cdecl FUN_0023fb00(audio::StreamHelper*, void*, int, int, int, int, int, int);",
       "void* __fastcall FUN_0023fb00(audio::StreamHelper*);"),
      ("FUN_0023fb00(helper, this, 0, 0, saved, 0, 1, 1)", "FUN_0023fb00(helper)")]),
    ("equivalent/0x002fd730.cpp", "0x0030edf0 is a one-argument __fastcall; the three words pushed before it are "
     "the later call's (0x002ef760)",
     [("// equiv-conv: FUN_0030edf0 ecx stack stack stack\nTemp* FUN_0030edf0(void* context, float scale, unsigned int value, void* data);",
       "Temp* __fastcall FUN_0030edf0(void* context);"),
      ("FUN_0030edf0(context, 1.0f, originalValue, originalData)", "FUN_0030edf0(context)")]),
    ("equivalent/0x00025a90.cpp", "CActorManager::Register 0x00031310 is a thiscall member without arguments "
     "(eax and edi held loop leftovers)",
     [("// equiv-conv: FUN_00031310 ecx eax edi\nvoid FUN_00031310(Thing_25a90 *t, int n, void *p);",
       "struct ThisNote_00031310 {\n    void FUN_00031310();\n};"),
      ("FUN_00031310(this, 0x40, f94);", "((ThisNote_00031310*)this)->FUN_00031310();")]),
    ("equivalent/0x002e69a0.cpp", "png_error: png_default_error 0x002e6930 is __cdecl (png_ptr): the original's "
     "eax is no argument (its `push eax` reserves a stack slot; fprintf gets two words)",
     [("// equiv-conv: FUN_002e6930 eax stack\nvoid FUN_002e6930(void *context, Item *item);", "void FUN_002e6930(Item *item);"),
      ("FUN_002e6930(context, item);", "FUN_002e6930(item);")]),
    ("equivalent/0x003397c0.cpp", "lua_tostring 0x00213190 is a __cdecl match of (L, idx): the original pushes "
     "edi and ebx, this function's own two register inputs",
     [("// equiv-conv: FUN_00213190 edi\nextern \"C\" int __cdecl FUN_00213190(void*);", "extern \"C\" int __cdecl FUN_00213190(void*, void*);"),
      ("FUN_00213190(stream) + 1", "FUN_00213190(stream, context) + 1")]),
    ("equivalent/0x0033cec0.cpp", "luaL_addvalue 0x00339590 is __cdecl (B): eax held the value by chance",
     [("// equiv-conv: FUN_00339590 eax stack\nextern void FUN_00339590(void*, Buffer_33cec0*);", "extern void FUN_00339590(Buffer_33cec0*);"),
      ("FUN_00339590(value,buffer);", "FUN_00339590(buffer); (void)value;"),
      ("FUN_00339590((void*)result,buffer);", "FUN_00339590(buffer);")]),
    ("equivalent/0x00220fe0.cpp", "0x00220cd0 is a __cdecl match of (fs): eax held the type by chance",
     [("// equiv-conv: FUN_00220cd0 eax stack\nint __cdecl FUN_00220cd0(int, Context*);", "int __cdecl FUN_00220cd0(Context*);"),
      ("FUN_00220cd0(rec->type,ctx)", "FUN_00220cd0(ctx)")]),
    ("equivalent/0x000fb240.cpp", "0x0027b020 is a __cdecl match of one argument: ecx held this by chance",
     [("// equiv-conv: FUN_0027b020 ecx stack\nextern __int64 __cdecl FUN_0027b020(Inventory *self, void *item);",
       "extern __int64 __cdecl FUN_0027b020(void *item);"),
      ("FUN_0027b020(this, item)", "FUN_0027b020(item)")]),
    ("equivalent/0x000fd0f0.cpp", "0x000fce60 reads no edi (its `push edi` is a register save): seven stack words",
     [("// equiv-conv: FUN_000fce60 edi stack stack stack stack stack stack stack\n"
       "void FUN_000fce60(unsigned a_edi, unsigned s1, unsigned s2, unsigned s3, unsigned s4, unsigned s5, unsigned s6, unsigned s7);",
       "void FUN_000fce60(unsigned s1, unsigned s2, unsigned s3, unsigned s4, unsigned s5, unsigned s6, unsigned s7);"),
      ("FUN_000fce60(infov, ", "FUN_000fce60("), ("FUN_000fce60(ediv, ", "FUN_000fce60(")]),
    ("equivalent/0x001fc030.cpp", "0x00224d70 is __cdecl (angle, v): ecx held the vector by chance",
     [("// equiv-conv: FUN_00224d70 ecx stack stack\nvoid FUN_00224d70(Vec_1fc030* self, float angle, Vec_1fc030* output);",
       "void FUN_00224d70(float angle, Vec_1fc030* output);"),
      ("FUN_00224d70(&p, -angle, &p);", "FUN_00224d70(-angle, &p);")]),
]

# --- void definitions whose original callers use the result (native_conv_check check 6), by hand ---------------
REG_CALLS += [
    ("equivalent/0x00219e90.cpp", "luaH_get returns the value slot from each of its three lookups (luaH_set and "
     "luaH_next use it; start-up trace: luaV_settable wrote through garbage)",
     [('extern void __cdecl FUN_00219dc0(int, int);\nextern void __cdecl FUN_00219e50(int, int);\n// equiv-conv: FUN_00219d80 edi stack\nextern void __cdecl FUN_00219d80(const Value *, int);\nvoid __cdecl FUN_00219e90(int context, const Value *value)\n{\n    if (value->type == 3) {\n        int integer = (int)value->data.real;\n        if (value->data.real == (float)integer) {\n            FUN_00219dc0(context, integer);\n            return;\n        }\n    } else if (value->type == 4) {\n        FUN_00219e50(context, value->data.integer);\n        return;\n    }\n    FUN_00219d80(value, context);\n}', 'extern int* __cdecl FUN_00219dc0(int, int);\nextern int* __cdecl FUN_00219e50(int, int);\n// equiv-conv: FUN_00219d80 edi stack\nextern int* __cdecl FUN_00219d80(const Value *, int);\nint* __cdecl FUN_00219e90(int context, const Value *value)\n{\n    if (value->type == 3) {\n        int integer = (int)value->data.real;\n        if (value->data.real == (float)integer) {\n            return FUN_00219dc0(context, integer);\n        }\n    } else if (value->type == 4) {\n        return FUN_00219e50(context, value->data.integer);\n    }\n    return FUN_00219d80(value, context);\n}')]),
    ("matches/0x00219ef0.cpp", "luaH_set returns the slot: luaH_get's when found, newkey's otherwise",
     [('extern int Find(void*, void*);\nextern void Error(void*, const char*);\nextern void Finish(void*, void*, void*);\nextern const float Zero_219ef0;\n\nvoid Target(void* a, void* b, int* c) {\n    int r = Find(b, c);\n    ((char*)b)[6] = 0;\n    if (r == ((int)((char*)&DAT_00426824))) {\n        if (*c == 0) {\n            Error(a, "table index is nil");\n        } else if (*c == 3) {\n            float x = *(float*)((char*)c + 4);\n            if (x != x)\n                Error(a, "table index is NaN");\n        }\n        Finish(a, b, c);\n    }\n}', 'extern int Find(void*, void*);\nextern void Error(void*, const char*);\nextern void* Finish(void*, void*, void*);\nextern const float Zero_219ef0;\n\nvoid* Target(void* a, void* b, int* c) {\n    int r = Find(b, c);\n    ((char*)b)[6] = 0;\n    if (r == ((int)((char*)&DAT_00426824))) {\n        if (*c == 0) {\n            Error(a, "table index is nil");\n        } else if (*c == 3) {\n            float x = *(float*)((char*)c + 4);\n            if (x != x)\n                Error(a, "table index is NaN");\n        }\n        return Finish(a, b, c);\n    }\n    return (void*)r;\n}')]),
]

# base-ctor's polymorphic variant renamed CtorV_<addr> (an empty Ctor_<addr> of another source may share the TU)
_CTORV = [
    ('matches/0x0002c790.cpp', '001d0480'),
    ('matches/0x0007e120.cpp', '001d0480'),
    ('matches/0x0007e2d0.cpp', '001d0480'),
    ('matches/0x00090fe0.cpp', '001d0480'),
    ('matches/0x000910f0.cpp', '001d0480'),
    ('matches/0x0009c440.cpp', '001d0480'),
    ('matches/0x0009ca30.cpp', '001d0480'),
    ('matches/0x000b0350.cpp', '001d0480'),
    ('matches/0x000cfcf0.cpp', '001d0480'),
    ('matches/0x000cfef0.cpp', '001d0480'),
    ('matches/0x000d0080.cpp', '001d0480'),
    ('matches/0x001bfea0.cpp', '001d0480'),
    ('matches/0x001ce730.cpp', '001d0480'),
    ('matches/0x001d4170.cpp', '001d0480'),
    ('matches/0x001e19d0.cpp', '001d0480'),
    ('matches/0x001ee2b0.cpp', '001d0480'),
    ('matches/0x001ee3b0.cpp', '001d0480'),
    ('matches/0x001f20b0.cpp', '001d0480'),
    ('matches/0x001ffd00.cpp', '001d0480'),
    ('matches/0x002030c0.cpp', '001d0480'),
    ('matches/0x00205c00.cpp', '001d0480'),
    ('matches/0x00205ff0.cpp', '001d0480'),
]
for _f, _a in _CTORV:
    REG_CALLS.append((_f, "base-ctor: the polymorphic base is CtorV_%s" % _a, [("Ctor_%s" % _a, "CtorV_%s" % _a)]))

# --- data tables written as string literals: compare.py matched the literal by the bytes at the address (the table's
# first pointer reads as a short string), natively the literal is a 4-byte string, not the table -------------------
REG_CALLS += [
    ("matches/0x0033b560.cpp", "luaopen_table: the luaL_reg table at 0x004348a0 (whose first pointer reads \"$IC\"), "
     "not a string literal (start-up trace: luaL_openlib read the literal as the table)",
     [("typedef unsigned int u32_33b560;", '#include "decls/data/engine/unknown.h"\ntypedef unsigned int u32_33b560;'),
      ('FUN_003390d0(p, "table", "$IC", 0);', 'FUN_003390d0(p, "table", (const char*)DAT_004348a0, 0);')]),
    ("matches/0x001d3c90.cpp", "the game's luaL_reg table at 0x00422458 (whose first pointer reads \"h$B\"), not a "
     "string literal",
     [("struct State;\ntypedef int(__cdecl* Callback_1d3c90)(State*);",
       '#include "decls/data/game/global.h"\nstruct State;\ntypedef int(__cdecl* Callback_1d3c90)(State*);'),
      ('FUN_003390d0(*state, 0, "h$B", 0);', 'FUN_003390d0(*state, 0, (const char*)DAT_00422458, 0);')]),
]

REG_CALLS += [
    ("equivalent/0x001d4c90.cpp", "the script Registry's singleton getter returns the instance (119 callers use eax; "
     "start-up trace: Registry::Add on garbage)",
     [("void FUN_001d4c90() { if (!(*(Object**)&DAT_004e23cc)) {", "Object* FUN_001d4c90() { if (!(*(Object**)&DAT_004e23cc)) {"),
      ("else (*(Object**)&DAT_004e23cc) = 0; } }", "else (*(Object**)&DAT_004e23cc) = 0; } return (*(Object**)&DAT_004e23cc); }")]),
]

# definitions with a register note declared __fastcall: natively clang passes their second argument in edx (the
# note says eax / a third register), while every caller is __cdecl with the note: the definition becomes __cdecl
REG_CALLS += [
    ("equivalent/0x00214280.cpp", "note ecx edx eax: a __cdecl definition natively (its callers are)",
     [("int __fastcall FUN_00214280(int value, Data *data, int mode) {", "int FUN_00214280(int value, Data *data, int mode) {")]),
    ("equivalent/0x00217790.cpp", "note ecx eax: a __cdecl definition natively (its five callers are)",
     [("void __fastcall FUN_00217790(Buffer* self, char* dest) {", "void FUN_00217790(Buffer* self, char* dest) {")]),
    ("equivalent/0x0021e110.cpp", "note ecx eax edi: a __cdecl definition natively (its caller is)",
     [("void __fastcall FUN_0021e110(Owner* owner, Entry* entry, Source* source)", "void FUN_0021e110(Owner* owner, Entry* entry, Source* source)")]),
    ("equivalent/0x0031bc30.cpp", "note eax ecx: a __cdecl definition natively (its caller is)",
     [("int __fastcall FUN_0031bc30(int mode, int value) {", "int FUN_0031bc30(int mode, int value) {")]),
    ("equivalent/0x00271b70.cpp", "0x002719a0 is a __fastcall definition (length ecx, text edx)",
     [("// equiv-conv: FUN_002719a0 ecx edx\n", ""),
      ("extern unsigned __int64 FUN_002719a0(int length, const unsigned char *text);",
       "extern unsigned __int64 __fastcall FUN_002719a0(int length, const unsigned char *text);")]),
]
