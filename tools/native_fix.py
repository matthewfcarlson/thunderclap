#!/usr/bin/env python3
"""Source edits for the native (clang) build that no generator rule can make (docs/native-build.md fix 4).

  build/venv/bin/python tools/native_fix.py                    # plan only: what would change
  build/venv/bin/python tools/native_fix.py --apply --verify   # rewrite, each source only if it still verifies
  build/venv/bin/python tools/native_fix.py --apply --verify --rule template-spec --only matches/0x001c7ca0.cpp

Each edit is standard C++ that MSVC 7.1 accepts as well, and `--verify` writes a rewrite only after the rewritten
text passes the verification the source passed (compare.py MATCH for matches/, equiv.py --inputs 3000 EQUIVALENT
for equivalent/; tools/reconcile_stubs.verify_rewrite) and only if the file didn't change since it was read.
Log: build/native-fix.log (one JSON line per source); changed paths: build/native/fix4-sources.txt.

Rules:

  template-spec   A member of an implicitly instantiated class template specialization defined without
                  `template <>` (`int om::MetaTypeAttrib<float>::vfunc_2(...) {`): an MSVC extension, which
                  clang rejects. `template <> ` goes in front. Not when the source explicitly specializes that
                  class (`template <> class X<...> {`), where the member definition must not have it.
  dependent-base  A class template using a typedef of its dependent base unqualified (`Closure0(..., Fn f)` in
                  `template <class T, class R> class Closure0 : public Method0<T, R>`): MSVC looks into the
                  dependent base, clang (two-phase lookup) doesn't, or finds another `Fn`. The use becomes
                  `typename Method0<T, R>::Fn`.
  return-struct   A struct defined in a function declaration's return type (`extern "C" struct Pair {...}
                  __cdecl Hash(const char*);`, `struct W {...} *f();`): the struct is defined first, then the
                  function declared with it (and the same linkage).
  patch           One-off edits listed in PATCHES below (exact text, each with its reason).
  this-note       A thiscall definition (a member: `this` in ecx) that a caller declares as a free __cdecl/__stdcall
                  function with an equiv-conv note `ecx stack...` (native_conv_check check 9): natively the caller
                  pushed `this` and the definition read ecx (and, popping its stack words, unbalanced the stack). The
                  declaration becomes a member of a struct of its own, each call `((ThisNote_X*)(a0))->X(a1, ...)`.
  return-param    A void definition whose original callers use eax (check 6) that the void-return rule can't
                  rewrite (the body doesn't end in a call): candidates `return <pointer parameter>;` (vector ops
                  storing through `out`: the original's eax is still `out`) and `return <the last assigned
                  lvalue>;` (singleton getters: eax holds the stored pointer), with the return type changed and bare
                  `return;` statements returning the same; each candidate is verified in turn (compare.py MATCH /
                  equiv.py EQUIVALENT) and the first that verifies is written. Only with --apply --verify.
  base-ctor       A base-class constructor (a thiscall `??0` definition, check 8) that a constructor calls through a
                  free __stdcall/__cdecl declaration as its first statement (`Base(const char* s) {
                  FUN_001d0480(s, 1); }`, the Lua binding objects): MSVC 7.1 had `this` in ecx by chance, natively
                  nothing sets it. The declaration becomes a base class `Ctor_<addr>` (empty, or with a virtual
                  function when the object's vftable pointer comes first) and the call its mem-initializer;
                  candidates verified in turn (as return-param). Only with --apply --verify.
  this-cand       A thiscall definition (not a constructor; constructors too with HULK_THIS_CAND_CTORS=1) that a
                  caller declares as a free __stdcall/__cdecl function (check 8, behaviour-changing): the call becomes
                  `((ThisCall_<addr>*)X)->f(args)` for X in `this` and the enclosing function's parameters, each
                  candidate verified in turn (MSVC 7.1 must still emit the original's bytes: ecx already held X
                  there). Also: a one-register __fastcall definition called without arguments gets X in ecx; a
                  declaration after an `ecx ...` register note becomes a member of its first argument with the note
                  kept on the member; and this-wrap: when the enclosing function is the source's own free function
                  and its original passes its incoming ecx on (`bool __stdcall FUN_001fc9d0(int x) { return
                  FUN_001fc7f0(x); }`), the wrapper becomes a member itself (its callers are check 8's next level).
                  C-linkage caller symbols (`_FUN_000e7260@4`, no namespace) map to every source declaring the name
                  `extern "C"`. Only with --apply --verify.
  ret-cand        A void definition whose original callers use its eax / st0 result (check 6) after void-return:
                  candidates in turn: the last call returned (callee declaration retyped, a trailing
                  `_ReadWriteBarrier();` kept or dropped, `float` for st0), the last call's result returned past
                  the stores after it, `return <parameter | this | local>;`. Only with --apply --verify.
  arg-shift       A call declared popping more words than its callee's `ret N` (check 7; the callee reads no more
                  stack words than it pops), chained into the next call (`X(a, b)->M()`, `T* v = X(a, b);
                  v->M();`): the extra words are M's - `X(a)->M(b)` (MSVC 7.1 pushes M's arguments before it
                  evaluates the object expression: the original's push order). Several next callees per source are
                  allowed. Only with --apply --verify.
  code-literal    A function passed by its XBE address as an integer literal (`CreateFiber(d, (void*)0x26dc20, p)`):
                  named (`((int)(void (__cdecl*)())&FUN_0026dc20)`, declared extern "C"), see code_literal.
  data-literal    A data item passed by its XBE address as an integer literal (`((T*)0x4e6a68)->Run()`): named
                  `hulk_at_<item>` + offset (data_literal).
  stub-body       An adjustor-thunk source's empty body for the virtual its thunk jumps to: removed (stub_body).
  unique-class    A class several sources of one TU declare alike, each storing another game vftable: renamed per
                  source (HULK_UNIQUE_CLASS; unique_class).
  ctor-virt       A constructor / destructor calling a virtual member of its own class: MSVC 7.1 calls it directly,
                  clang through the (game's) vftable; the member becomes non-virtual, a stand-in virtual keeps its
                  slot (ctor_virt).
  ret-widen       A definition declared bool/char/short whose callers declare a 32-bit result (check 10; HULK_RET_WIDEN
                  names them): the definition's type becomes int (or unsigned int) when that still verifies.
  reg-call        Calls of register-convention functions (native_conv_check check 5), each read from the
                  original's call site: the edit groups in tools/native_calls.py (every occurrence of each old
                  text is replaced; a group applies only if all its texts are present). A matches/ source listed
                  in native_calls.DEMOTE becomes an equivalent/ source (the call can't be written so that MSVC
                  7.1 still emits the original bytes: the argument travels in esi/edi/ebx): it is written to
                  equivalent/ with equiv.py's STATUS header only if equiv.py --inputs 3000 finds it equivalent
                  and promotable, and the match is removed (kept in build/native/fix4-orig/).

equivalent/ sources shadowed by a matches/ source of the same address are skipped (the tree uses the match).
HULK_FIX_SKIP names a file of sources no rule may rewrite (another session's untracked work).
"""
import argparse
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
LOG = os.path.join(ROOT, "build/native-fix.log")
CHANGED = os.path.join(ROOT, "build/native/fix4-sources.txt")
ORIG = os.path.join(ROOT, "build/native/fix4-orig")

# (source, old text, new text, why). Exact, unique occurrences; anything else is reported and skipped.
PATCHES = [
    ("equivalent/0x000c0e40.cpp", "for(int i=0;i<128;++i) { records[i].items[0]", "int i; for(i=0;i<128;++i) { records[i].items[0]",
     "for-scope: `i` is used after its loop (MSVC 7.1 /Zc:forScope-): declared before it"),
    ("equivalent/0x00322cd0.cpp", "for(int j=0;j<count;++j)weights[j]*=scale;", "int j;for(j=0;j<count;++j)weights[j]*=scale;",
     "for-scope: `j` is used after its loop: declared before it"),
    ("matches/0x001ff730.cpp", 'return x ? "Volume" : "Locator";', 'return (char*)(x ? "Volume" : "Locator");',
     "string literals returned as char*: the conditional's type is const char*"),
    ("equivalent/0x000d4b60.cpp", "extern union { float f; unsigned int u; } DAT_004a06b4;",
     "union U_4a06b4 { float f; unsigned int u; };\nextern U_4a06b4 DAT_004a06b4;",
     "an extern variable of an unnamed type (no linkage: clang can't refer to it from another TU)"),
    ("equivalent/0x0033a880.cpp", "hook != FUN_0033a620)", "hook != (Hook_33a880)FUN_0033a620)",
     "comparison with an overloaded function name (the merged TU declares FUN_0033a620 three ways): the cast picks one"),
    ("matches/0x00238190.cpp", 'extern "C" int __cdecl FUN_00238190(int index) {\n    extern int table_238190[1];\n',
     'extern int table_238190[1];\nextern "C" int __cdecl FUN_00238190(int index) {\n',
     "a block-scope extern inside an extern \"C\" function has C linkage, the TU's declaration C++ linkage"),
    ("matches/0x0035c720.cpp", 'extern "C" struct Result_35c720 __cdecl FUN_0027b020(', 'extern "C" Result_35c720 __cdecl FUN_0027b020(',
     "`extern \"C\" struct X f()` is read as a declaration of the struct, so gen_tree can't give f C++ linkage"),
    ("matches/0x000f6ef0.cpp", "    X_f6ef0();\n    int m[0x100];", "    int X_f6ef0();\n    int m[0x100];",
     "a member function declared without a return type (implicit int)"),
    ("matches/0x0031ee00.cpp", "            q->pddiRenderState::pddiRenderState();",
     "            ((pddiRenderState*)q)->pddiRenderState::pddiRenderState();",
     "an explicit constructor call (MSVC extension, which clang accepts too) through a pointer of dependent type "
     "`T*`: clang can't resolve the injected class name there; the cast makes the object expression non-dependent "
     "(placement new would add MSVC 7.1's null check)"),
    ("equivalent/0x0008d480.cpp", "int bounds[4]; FUN_00209f01(bounds);", "int bounds[8]; FUN_00209f01(bounds);",
     "GlobalMemoryStatus fills a 32-byte MEMORYSTATUS (the original reserves 0x20 bytes for it): natively the "
     "16-byte array let it overwrite the saved registers and return address (start-up trace, init 216)"),
    ("matches/0x0008d690.cpp",
     "int __cdecl first(int);\nvoid __cdecl second(int);\nvoid __cdecl FUN_0008d690(int x) {",
     "int __cdecl first();\nvoid* __cdecl second(int, int);\nvoid* __cdecl FUN_0008d690(int x) {",
     "the game's operator new: `push size; call first; push eax; call second` is second(first(), size) (MSVC "
     "pushes the right-hand argument first), not second(first(size)) with the size left on the stack, and it "
     "returns second's pointer: natively the old text passed second a garbage size and returned nothing"),
    ("matches/0x0008d690.cpp", "    second(first(x));\n    _ReadWriteBarrier();\n", "    return second(first(), x);\n",
     "(the same edit, second part)"),
    ("equivalent/0x0026c040.cpp", "// equiv-conv: FUN_0026be70 stack eax\nextern void *FUN_0026be70(unsigned nb, MState *av);",
     "// equiv-conv: FUN_0026be70 eax stack\nextern void *FUN_0026be70(MState *av, unsigned nb);",
     "a register-convention callee declared with its parameters in another order than its own source "
     "(equivalent/0x0026be70.cpp: `eax stack`, (arena, size)): equiv.py maps each side to the original's registers, "
     "natively both are __cdecl and the callee read the size as its arena (start-up trace, init 216)"),
    ("equivalent/0x0026c040.cpp", "            return FUN_0026be70(nb, av);", "            return FUN_0026be70(av, nb);",
     "(the same edit, the call)"),    # start-up round 2 (docs/native-build.md "Start-up, continued")
    ("equivalent/0x00219cc0.cpp", "void __cdecl FUN_00219be0(void*);\nvoid __cdecl FUN_00219c30(void*);\n",
     "// equiv-conv: FUN_00219be0 esi edi stack\nvoid __cdecl FUN_00219be0(Item*, void*, void*);\n"
     "// equiv-conv: FUN_00219c30 ebx esi stack\nvoid __cdecl FUN_00219c30(void*, Item*, void*);\n",
     "two register-convention callees (their own notes: `esi edi stack`, `ebx esi stack`) called with only their "
     "stack word and no note: the original passes (item, the second argument, owner) and (owner, item, arg) in "
     "those registers (native_conv_check check 5, callers without a note; start-up trace, main: luaH_new)"),
    ("equivalent/0x00219cc0.cpp", "    FUN_00219be0(owner);\n    FUN_00219c30(arg);\n",
     "    FUN_00219be0(item, unused, owner);\n    FUN_00219c30(owner, item, arg);\n", "(the same edit, the calls)"),
    ("matches/0x00275110.cpp", "void __stdcall FUN_00274e60(void* p);\n",
     "struct Request_275110 {\n    Request_275110* FUN_00274e60(void* p);\n};\n",
     "a thiscall constructor (0x00274e60: `mov esi, ecx`, `ret 4`) declared as a free __stdcall function: the "
     "original's ecx still held `this` from the caller, natively nothing sets it (native_conv_check check 8; "
     "start-up trace, main: FileCloseRequest)"),
    ("matches/0x00275110.cpp", "    FUN_00274e60(p);\n", "    ((Request_275110*)this)->FUN_00274e60(p);\n",
     "(the same edit, the call)"),
    ("equivalent/0x00277260.cpp", '// equiv-conv: FUN_0026fcf0 stack stack stack\nextern "C" int __cdecl FUN_0026fcf0(unsigned int, const char *, unsigned int);',
     '// equiv-conv: FUN_0026fcf0 stack stack stack stack\nextern "C" int __cdecl FUN_0026fcf0(unsigned int, const char *, unsigned int, unsigned int);',
     "a tail call passing on more arguments than the source declares: the original `jmp 0x0026fcf0` hands it all "
     "four of its own (result, name, options, details); with three, natively 0x0026fcf0 read the drive path from "
     "beyond the arguments (start-up trace, main: XboxDrive::vfunc_21)"),
    ("equivalent/0x00277260.cpp", "int __cdecl FUN_00277260(unsigned int arg1, const char *path, unsigned int arg3)",
     "int __cdecl FUN_00277260(unsigned int arg1, const char *path, unsigned int arg3, unsigned int arg4)", "(the same edit)"),
    ("equivalent/0x00277260.cpp", "return FUN_0026fcf0(arg1, path, arg3);", "return FUN_0026fcf0(arg1, path, arg3, arg4);",
     "(the same edit, the call)"),
    ("equivalent/0x00251b40.cpp", "    // equiv-conv: FUN_0023fc40 ecx stack stack stack stack stack\n"
     "    ChannelValue *FUN_0023fc40(const char *, int, const Int64 *, int, int);",
     "    // equiv-conv: FUN_0023fc40 ecx stack stack\n    ChannelValue *FUN_0023fc40(const char *, int);",
     "the audio type constructors' string init 0x0023fc40 pops two arguments (`ret 8`); the three the original "
     "pushes before them are the base constructor's (as in matches/0x0024ed10, rule split-temp): declared and "
     "called with two (start-up trace, init 349)"),
    ("equivalent/0x00251b40.cpp", 'channel.FUN_0023fc40("ChVol", 0, &value, 32, 4);', 'channel.FUN_0023fc40("ChVol", 0);',
     "(the same edit, the call)"),
    ("matches/0x0024ed10.cpp",
     "    Data(const char*, int, void*, int, int) throw();\n    ~Data() throw();\n};\nclass Base {\n  public:\n    Base(const Data&) throw();",
     "    Data* Init(const char*, int) throw();\n    ~Data() throw();\n};\nclass Base {\n  public:\n    Base(Data*, void*, int, int) throw();",
     "arguments left on the stack by MSVC and read by the next call: the original pushes (4, 0x50, &key, 0, name), "
     "calls 0x0023fc40, which pops only (name, 0) (`ret 8`: String's init, returning this), then pushes its result and "
     "calls the base constructor 0x002605e0 (`ret 0x10`) with (string, &key, 0x50, 4); the five-argument `Data` "
     "constructor byte-matched, natively it unbalanced the stack (start-up trace, init 329)"),
    ("matches/0x0024ed10.cpp",
     '    : Base(Data("ChSendVol", 0, Key(Lookup("SeqEventChannelSendVolumes", 0, 0)), 0x50, 4)) {}',
     '    : Base(Data().Init("ChSendVol", 0), Key(Lookup("SeqEventChannelSendVolumes", 0, 0)), 0x50, 4) {}',
     "(the same edit, the call)"),
    ("equivalent/0x00011000.cpp", "extern float FUN_003441f0();\nfloat __cdecl FUN_00011000(float value)\n{\n"
     "    volatile float result = FUN_003441f0();\n    return result;\n}",
     'extern "C" double __cdecl acos(double);\nfloat __cdecl FUN_00011000(float value)\n{\n'
     "    double result = acos(value);\n    return (float)result;\n}",
     "0x003441f0 is the CRT's _CIacos (argument and result on the x87 stack): `FUN_003441f0()` passed nothing, "
     "natively acos read an empty x87 stack. acos() is MSVC's intrinsic (fld; call __CIacos; now a byte match)"),
    ("equivalent/0x00011010.cpp", "extern float FUN_003442bc();\nfloat __cdecl FUN_00011010(float value) {\n"
     "    float result = FUN_003442bc();\n    volatile float dummy = value;\n    return result;\n}",
     'extern "C" double __cdecl asin(double);\nfloat __cdecl FUN_00011010(float value) {\n'
     "    double result = asin(value);\n    return (float)result;\n}",
     "0x003442bc is _CIasin: as 0x00011000 (now a byte match)"),
    ("equivalent/0x0033b700.cpp", "float __cdecl FUN_003441f0();\n", 'extern "C" double __cdecl acos(double);\n',
     "_CIacos called as `FUN_003441f0()`: its argument is the previous call's x87 result; acos(a) says so"),
    ("equivalent/0x0033b700.cpp", "    float b = FUN_003441f0();\n", "    float b = (float)acos(a);\n",
     "(the same edit, the call)"),
    ("equivalent/0x0008d6d0.cpp", "int __cdecl FUN_00266d90(int);\nvoid __cdecl FUN_00266e00(int, int);\n"
     "void __cdecl FUN_0008d6d0(int value) {",
     "int __cdecl FUN_00266d90();\nvoid* __cdecl FUN_00266e00(int, int);\nvoid* __cdecl FUN_0008d6d0(int value) {",
     "operator new[], the twin of 0x0008d690: second(first(), size) returning second's pointer (its callers use "
     "eax: native_conv_check check 6), not a void function"),
    ("equivalent/0x0008d6d0.cpp", "    int result = FUN_00266d90(value);\n    FUN_00266e00(result, value);\n",
     "    return FUN_00266e00(FUN_00266d90(), value);\n", "(the same edit, the call)"),
    ("matches/0x001d06a0.cpp", "extern void __cdecl FUN_002130e0(void*, int);\nextern int __cdecl FUN_0034483c();\n",
     "extern double __cdecl FUN_002130e0(void*, int);\n",
     "0x0034483c is the CRT's _ftol (argument on the x87 stack): `FUN_002130e0(p, -1); x = FUN_0034483c();` "
     "converted the number 0x002130e0 leaves in st0, which a `void` declaration hides; natively _ftol read an empty "
     "x87 stack (native_conv_check check 6, x87 helpers)"),
    ("matches/0x001d06a0.cpp", "            FUN_002130e0(p, -1);\n            x = FUN_0034483c();\n",
     "            x = (int)FUN_002130e0(p, -1);\n", "(the same edit, the call)"),
    ("equivalent/0x000e8070.cpp", "void FUN_000fad30(); unsigned int FUN_000fad90(); };",
     "float FUN_000fad30(); unsigned int FUN_000fad90(); };",
     "_ftol called as `FUN_0034483c()` on the float FUN_000fad30 leaves in st0: (int)input->FUN_000fad30()"),
    ("equivalent/0x000e8070.cpp", "unsigned int __cdecl FUN_0034483c();\n", "", "(the same edit)"),
    ("equivalent/0x000e8070.cpp", "{ input->FUN_000fad30(); object->stamp=FUN_0034483c(); }",
     "{ object->stamp=(int)input->FUN_000fad30(); }", "(the same edit, the call)"),
    # native9 (docs/native-build.md "native9"): run-time stops
    ("equivalent/0x00277d00.cpp",
     " virtual void slot12(unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);",
     " virtual int slot12(unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);",
     "the archive reader's read 0x00277d00 returns the device read's status (eax untouched after the call; "
     "0x00278010 tail-jumps to it and FileReadRequest::vfunc_1 0x00273f00 tests `== 1`): void natively left garbage, "
     "the request was never disposed and File::vfunc_21 waited forever (check 6 through a tail jump)"),
    ("equivalent/0x00277d00.cpp",
     " void FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);\n};",
     " int FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);\n};",
     "(the same edit, the declaration)"),
    ("equivalent/0x00277d00.cpp",
     "void Object::FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f) {\n target->slot12(a,b,c,base+offset,d,e,result,f);",
     "int Object::FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f) {\n int status = target->slot12(a,b,c,base+offset,d,e,result,f);",
     "(the same edit, the definition)"),
    ("equivalent/0x00277d00.cpp", " state = 0;\n}", " state = 0;\n return status;\n}", "(the same edit, the return)"),
    ("matches/0x002dd690.cpp", "typedef void(__cdecl* ReadFn_2dd690)(void*);",
     "typedef void(__cdecl* ReadFn_2dd690)(void*, void*, unsigned int);",
     "png_read_data 0x002dd690 (`mov [esp+4], ecx; jmp eax`) hands its buffer and length on to the read callback "
     "(the pass-through class through a function pointer); the source called fn(p) alone and the game's callback "
     "0x002ad790 read garbage for both: the stream copied the whole file again and again over the heap"),
    ("matches/0x002dd690.cpp", "void __cdecl Target(Obj_2dd690* p) {", "void __cdecl Target(Obj_2dd690* p, void* data, unsigned int length) {",
     "(the same edit, the parameters)"),
    ("matches/0x002dd690.cpp", "        fn(p);", "        fn(p, data, length);", "(the same edit, the call)"),
    ("matches/0x00266220.cpp", "    U64 FUN_00231530(Node* node);", "    U64 FUN_00231530();",
     "the iterator's current-id getter 0x00231530 takes no argument (plain `ret`): the node pushed before its call is "
     "OnEntry's second argument (check 7, the next call's words): natively the getter's caller popped a word the "
     "callee never took and `this` was read from the wrong slot"),
    ("matches/0x00266220.cpp", "    virtual void OnEntry(U64 id);", "    virtual void OnEntry(U64 id, Node* node);",
     "(the same edit, OnEntry)"),
    ("matches/0x00266220.cpp", "            OnEntry(it.FUN_00231530(n));", "            OnEntry(it.FUN_00231530(), n);",
     "(the same edit, the call)"),
    ("equivalent/0x0025c7c0.cpp", "// equiv-conv: FUN_0025c7c0 ecx stack stack\nint __cdecl FUN_0025c7c0(unsigned int initial, void* source, unsigned int* destination)\n{\n    unsigned int value = initial;",
     "int __cdecl FUN_0025c7c0(void* source, unsigned int* destination)\n{\n    unsigned int value;",
     "the read-four-words helper 0x0025c7c0: its `push ecx` only makes room for the local the first read fills "
     "(the caller's ecx, `this` of SeqEventChannelSends::vfunc_0, is never used); its callers pass (source, "
     "destination) on the stack, so natively the 3-parameter declaration read source from the destination's slot "
     "and the next word as the destination (check 5's register-note class)"),
    ("matches/0x001b46d0.cpp", "    void Other(int a, float b);", "    void Other(int a, float b, float c);",
     "cm_SetGravity's target 0x001b46d0 takes the script's three floats and tail-jumps to 0x002ece90 (`ret 0xc`) "
     "with them (check 7): declared with two, natively it popped 8 of the 12 bytes its Closure3 caller pushed"),
    ("matches/0x001b46d0.cpp", "    void Fn(int a, float b);", "    void Fn(int a, float b, float c);", "(the same edit)"),
    ("matches/0x001b46d0.cpp", "void Target::Fn(int a, float b) {", "void Target::Fn(int a, float b, float c) {", "(the same edit)"),
    ("matches/0x001b46d0.cpp", "    g->Other(a, b);", "    g->Other(a, b, c);", "(the same edit, the call)"),
    # native10, code-table: a switch whose case-index table MSVC 7.1 put in .text after the function, read by the
    # source as `DAT_<addr>[i]` (the XBE's code bytes): natively the name is a zero stub, every input took case 0.
    # The switch is written on the value itself (the table's mapping, read from the XBE once, in the case labels).
    ("equivalent/0x0026f3e0.cpp", "extern unsigned char DAT_0026f498[];\n", "",
     "code-table: the case-index table 0x0026f498 lies in .text (MSVC's switch table, not data): the switch is "
     "written on `code` itself"),
    ("equivalent/0x0026f3e0.cpp",
     "        switch (DAT_0026f498[code]) {\n        case 0: return 0;\n        case 1: return 1;\n        case 2: return 5;\n"
     "        case 3: return 8;\n        case 4: return 3;\n",
     "        switch (code) {\n        case 0: return 0;\n        case 2: case 3: case 15: return 1;\n        case 11: return 5;\n"
     "        case 14: return 8;\n        case 17: return 3;\n", "(the same edit, the switch)"),
    ("equivalent/0x002787c0.cpp", "extern unsigned char DAT_002788a4[];\n", "",
     "code-table: the case-index table 0x002788a4 lies in .text: the switch is written on `value` itself"),
    ("equivalent/0x002787c0.cpp",
     "switch(DAT_002788a4[value]) {case 0:return 0;case 1:return 1;case 2:return 5;case 3:return 7;case 4:return 3;default:return 8;}",
     "switch(value) {case 0:return 0;case 2:case 3:case 15:return 1;case 11:return 5;case 14:return 7;case 17:return 3;default:return 8;}",
     "(the same edit, the switch)"),
    ("equivalent/0x0028ec30.cpp", "extern unsigned char DAT_0028ed74[21];\n", "",
     "code-table: the case-index table 0x0028ed74 lies in .text: the switch is written on the chunk id's index"),
    ("equivalent/0x0028ec30.cpp",
     "switch(DAT_0028ed74[index]) {\ncase 8: return FUN_0028c580(c,a,b);\ncase 0: return FUN_0028c6b0(c,a,b);\n"
     "case 1: return FUN_0028c7e0(c,a,b);\ncase 2: return FUN_0028c910(c,a,b);\ncase 3: return FUN_0028e160(c,a,b);\n"
     "case 4: return FUN_0028cd80(c,a,b);\ncase 5: return FUN_0028ea80(c,a,b);\ncase 6: return FUN_0028ceb0(c,a,b);\n"
     "case 7: return FUN_0028cfd0(c,a,b);\n",
     "switch(index) {\ncase 14: return FUN_0028c580(c,a,b);\ncase 0: return FUN_0028c6b0(c,a,b);\n"
     "case 1: return FUN_0028c7e0(c,a,b);\ncase 2: case 3: case 4: return FUN_0028c910(c,a,b);\n"
     "case 5: case 17: case 18: case 19: case 20: return FUN_0028e160(c,a,b);\n"
     "case 6: return FUN_0028cd80(c,a,b);\ncase 7: return FUN_0028ea80(c,a,b);\ncase 8: return FUN_0028ceb0(c,a,b);\n"
     "case 9: return FUN_0028cfd0(c,a,b);\n", "(the same edit, the switch)"),
    ("equivalent/0x0031c290.cpp", "extern unsigned char DAT_0031c544[39];\n", "",
     "code-table: the case-index table 0x0031c544 lies in .text: the switch is written on the format's index"),
    ("equivalent/0x0031c290.cpp",
     " if(index<=38) switch(DAT_0031c544[index]) {\n case 3: r=0xf800;g=0x7e0;b=0x1f;out->type=1;break;\n"
     " case 0: a=0x8000;r=0x7c00;g=0x3e0;b=0x1f;out->type=2;break;\n case 2: a=0xf000;r=0xf00;g=0xf0;b=0xf;out->type=4;break;\n"
     " case 4: a=0xff000000;r=0xff0000;g=0xff00;b=0xff;out->type=6;break;\n case 5: r=0xff0000;g=0xff00;b=0xff;out->type=6;break;\n"
     " case 1: r=0x7c00;g=0x3e0;b=0x1f;out->type=3;break;\n case 7: out->type=11;break;\n case 8: out->type=13;break;\n"
     " case 9: out->type=15;break;\n case 6: out->type=7;break;\n case 10: out->type=10;break;\n }",
     " if(index<=38) switch(index) {\n case 3: case 15: r=0xf800;g=0x7e0;b=0x1f;out->type=1;break;\n"
     " case 0: case 14: a=0x8000;r=0x7c00;g=0x3e0;b=0x1f;out->type=2;break;\n case 2: case 27: a=0xf000;r=0xf00;g=0xf0;b=0xf;out->type=4;break;\n"
     " case 4: case 28: a=0xff000000;r=0xff0000;g=0xff00;b=0xff;out->type=6;break;\n case 5: case 16: r=0xff0000;g=0xff00;b=0xff;out->type=6;break;\n"
     " case 1: r=0x7c00;g=0x3e0;b=0x1f;out->type=3;break;\n case 10: out->type=11;break;\n case 12: out->type=13;break;\n"
     " case 13: out->type=15;break;\n case 9: out->type=7;break;\n case 38: out->type=10;break;\n }",
     "(the same edit, the switch)"),
    ("equivalent/0x0021db50.cpp", "extern unsigned char DAT_0021dc68[164];\n", "",
     "code-table: the case-index table 0x0021dc68 lies in .text: the branch is computed from the kind itself"),
    ("equivalent/0x0021db50.cpp", " unsigned int branch=k<=0xa3 ? DAT_0021dc68[k] : 7;\n",
     " unsigned int branch=k==0 ? 0 : k==140 ? 1 : k==142 ? 2 : k==146 ? 3 : k==152 ? 4 : k==162 ? 5 : k==163 ? 6 : 7;\n",
     "(the same edit, the branch)"),
    ("equivalent/0x001b0470.cpp", "extern unsigned char DAT_001b0590[10];\n", "",
     "code-table: the case-index table 0x001b0590 and the branch addresses before it lie in .text (the source "
     "compared code addresses): the switch is written on `type` itself"),
    ("equivalent/0x001b0470.cpp",
     "        const DispatchData* dispatch = reinterpret_cast<const DispatchData*>(\n"
     "            DAT_001b0590 - 5 * sizeof(unsigned char*));\n"
     "        unsigned char* branch = dispatch->branches[DAT_001b0590[type]];\n"
     "        const unsigned char* origin = reinterpret_cast<const unsigned char*>(dispatch);\n"
     "        float angle = 90.0f;\n"
     "        if (branch == origin - 0xa5) {\n"
     "            angle = FUN_00044500(self->state->value) ? 10.0f : 90.0f;\n"
     "        } else if (branch == origin - 0x41) {\n"
     "            angle = FUN_00044500(self->state->value) ? 90.0f : 100.0f;\n"
     "        } else if (branch == origin - 0x0a) {\n"
     "            return result;\n"
     "        }\n",
     "        float angle = 90.0f;\n"
     "        switch (type) {\n"
     "        case 0: case 4:\n"
     "            angle = FUN_00044500(self->state->value) ? 10.0f : 90.0f;\n"
     "            break;\n"
     "        case 2: case 9:\n"
     "            angle = FUN_00044500(self->state->value) ? 90.0f : 100.0f;\n"
     "            break;\n"
     "        case 6: case 7:\n"
     "            return result;\n"
     "        }\n",
     "(the same edit, the switch)"),
    ("equivalent/0x0028aea0.cpp",
     " case 0x121100: case 0x121107: case 0x121109: case 0x121111: case 0x121113: a=count*4; b=count*2; *header=0x1c; break;\n"
     " case 0x121101: a=count*8; b=count*2; *header=0x1c; break;\n",
     " case 0x121100: case 0x121107: case 0x121109: case 0x12110e: case 0x121113: a=count*4; b=count*2; *header=0x1c; break;\n"
     " case 0x121101: case 0x121111: a=count*8; b=count*2; *header=0x1c; break;\n",
     "jump-table: DefaultChannelHandler::vfunc_5 0x0028aea0 (a channel's pool sizes) maps 0x12110e like 0x121100 "
     "(count*4, header 0x1c) and 0x121111 like 0x121101 (count*8): the source had 0x121111 in the first group and "
     "no 0x12110e (sizes 0), which the equivalence run never fed (its coverage counts the table's 12 targets, not "
     "its 21 indices). Natively an animation's pool came out 63 headers short and AnimationLoader's group array, "
     "allocated after it, was overwritten (qsort's comparator 0x00289270 then read a null group)"),
    ("matches/0x000fa9c0.cpp", "    virtual void vfunc_2();\n    int a, b, c;",
     "    virtual CScriptToken* vfunc_2();\n    int a, b, c;",
     "check 11: DollyScript::CTokenHashed::vfunc_2 0x000fa9c0 is the token's Clone (slot 2 of CScriptToken: "
     "CTokenString/CTokenFloat/CTokenSectionStart/End return the copy; the original leaves it in eax): declared void, "
     "natively the front end's script parser linked whatever eax held into its token list"),
    ("matches/0x000fa9c0.cpp", "    virtual void vfunc_2();\n    int d, e;", "    virtual CScriptToken* vfunc_2();\n    int d, e;",
     "(the same edit, the override)"),
    ("matches/0x000fa9c0.cpp", "void CTokenHashed::vfunc_2() {\n    CTokenHashed* p = new CTokenHashed(*this);\n    p->a = 0;\n}",
     "CScriptToken* CTokenHashed::vfunc_2() {\n    CTokenHashed* p = new CTokenHashed(*this);\n    p->a = 0;\n    return p;\n}",
     "(the same edit, the definition)"),
    # native10, ret-wide64: definitions that return a 64-bit callee's result (edx:eax) declared 32-bit; their
    # callers read edx:eax (check 10's 64-bit case). Natively clang's int return left edx to chance: FUN_0027b020
    # (the 64-bit name hash, 173 callers) gave the front end's container lookups (FEContainer::vfunc_50) hashes
    # with a garbage high half.
    ("matches/0x0027b020.cpp", "int FUN_002672f0(void* a, int b, int c);\nint FUN_0027b020(void* a) {",
     "unsigned __int64 FUN_002672f0(void* a, int b, int c);\nunsigned __int64 FUN_0027b020(void* a) {",
     "check 10 (64-bit, native10): the 64-bit name hash / microsecond clock returned through a 32-bit definition: FUN_0027b020 0x0027b020 tail-returns FUN_002672f0's edx:eax (the 64-bit name hash)"),
    ("matches/0x00044370.cpp", "int __fastcall FUN_00044370(char* self) {", "unsigned __int64 __fastcall FUN_00044370(char* self) {",
     "check 10 (64-bit, native10): the 64-bit name hash / microsecond clock returned through a 32-bit definition: 0x00044370 returns FUN_0027b020's edx:eax"),
    ("matches/0x000443c0.cpp", "int __cdecl FUN_0027b020(void*);", "unsigned __int64 __cdecl FUN_0027b020(void*);",
     "check 10 (64-bit, native10): the 64-bit name hash / microsecond clock returned through a 32-bit definition: 0x000443c0 returns FUN_0027b020's edx:eax"),
    ("matches/0x000443c0.cpp", "    int Fn();", "    unsigned __int64 Fn();", "(the same edit, the declaration)"),
    ("matches/0x000443c0.cpp", "int Obj::Fn() {", "unsigned __int64 Obj::Fn() {", "(the same edit, the definition)"),
    ("matches/0x00267f40.cpp", "int __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);\nint __cdecl FUN_00267f40(void) {",
     "unsigned __int64 __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);\nunsigned __int64 __cdecl FUN_00267f40(void) {",
     "check 10 (64-bit, native10): the 64-bit name hash / microsecond clock returned through a 32-bit definition: core::GetMicroseconds64 0x00267f40 returns the 64-bit muldiv 0x00267e20's edx:eax (GameClock::Update's time)"),
    ("matches/0x0027afb0.cpp", "int __cdecl Target(int, int, int);\nint __cdecl Wrapper(int a) {",
     "unsigned __int64 __cdecl Target(int, int, int);\nunsigned __int64 __cdecl Wrapper(int a) {",
     "check 10 (64-bit, native10): the 64-bit name hash / microsecond clock returned through a 32-bit definition: 0x0027afb0 tail-returns FUN_002672f0's edx:eax"),
    # native10, shared-static: the token list's `last` item is ONE function-local static in the original (an inline
    # Put of the parser, emitted inline in 0x000faf80 and out of line as 0x000fa870: both use 0x4e09f8 and its
    # guard bit at 0x4e09fc); each source declared its own `static ... last = it;`, natively two statics: the
    # macro expander's Put (0x000fa870) never saw the parser's last token, its first call skipped linking, and
    # every inserted macro token hung off that unlinked one (the front end's screens lost their AddLocators and
    # AddSceneGraph lines: FEContainer::vfunc_50 found no children). Both name the shared item.
    ("matches/0x000fa870.cpp", "struct Item_fa870 {",
     'extern "C" unsigned char DAT_004e09f8[4];\nextern "C" unsigned char DAT_004e09fc[4];\nstruct Item_fa870 {',
     "shared-static: Lst::Put 0x000fa870's `last` is the parser's (0x4e09f8, guard 0x4e09fc bit 0)"),
    ("matches/0x000fa870.cpp", "    static Item_fa870* last = it;\n",
     "    if (!(*(unsigned char*)DAT_004e09fc & 1)) {\n        *(unsigned*)DAT_004e09fc |= 1;\n"
     "        *(Item_fa870**)DAT_004e09f8 = it;\n    }\n    Item_fa870*& last = *(Item_fa870**)DAT_004e09f8;\n",
     "(the same edit, the static)"),
    ("equivalent/0x000faf80.cpp", "struct Item_faf80 {\n",
     'extern "C" unsigned char DAT_004e09f8[4];\nextern "C" unsigned char DAT_004e09fc[4];\nstruct Item_faf80 {\n',
     "(the same edit, the declarations)"),
    ("equivalent/0x000faf80.cpp", "                    static Item_faf80 *last = it;\n",
     "                    if (!(*(unsigned char*)DAT_004e09fc & 1)) {\n                        *(unsigned*)DAT_004e09fc |= 1;\n"
     "                        *(Item_faf80**)DAT_004e09f8 = it;\n                    }\n"
     "                    Item_faf80 *&last = *(Item_faf80**)DAT_004e09f8;\n",
     "shared-static: the parser 0x000faf80's inline Put names the shared `last` (0x4e09f8, guard 0x4e09fc bit 0)"),
    ("matches/0x000f6370.cpp", "    int B(int, int, int, int*);\n    void C(int);\n",
     "    int B(int, int);\n    void C(int, int, int*);\n",
     "check 7 (arg-shift through a variable): 0x000f6370 pushes (&local, 0) before B 0x002843a0 (`ret 8`, pops "
     "c and d) and C 0x002848b0 (`ret 0xc`) takes them after B's result: C(r, 0, &local) is the camera locator's "
     "Run(index, value, out); natively B took four words and C one (the front end's sort comparator 0x000e1e90 "
     "then crashed in Run)"),
    ("matches/0x000f6370.cpp", "    int r = api->B(c, d, 0, (int*)&local);\n    api->C(r);\n",
     "    api->C(api->B(c, d), 0, (int*)&local);\n", "(the same edit, the calls)"),
    ("equivalent/0x000f63c0.cpp", "    int FUN_002843a0(int first, int second, int zero, void *out);\n    void FUN_00284860(int result);\n",
     "    int FUN_002843a0(int first, int second);\n    void FUN_00284860(int result, int zero, void *out);\n",
     "check 7 (the same shape as 0x000f6370): 0x002843a0 pops 8, 0x00284860 (`ret 0xc`) takes (result, 0, values)"),
    ("equivalent/0x000f63c0.cpp", "    int result = device->FUN_002843a0(first, second, 0, values);\n    device->FUN_00284860(result);\n",
     "    device->FUN_00284860(device->FUN_002843a0(first, second), 0, values);\n", "(the same edit, the calls)"),
    ("equivalent/0x002139a0.cpp",
     "void __cdecl FUN_002159e0(Record *record, char *position);\nvoid __cdecl FUN_002139a0(Record *record, int index) {\n"
     "    FUN_002159e0(record, record->end - (index * 8 + 8));\n",
     "void __cdecl FUN_002159e0(Record *record, char *position, int nresults);\n"
     "void __cdecl FUN_002139a0(Record *record, int index, int nresults) {\n"
     "    FUN_002159e0(record, record->end - (index * 8 + 8), nresults);\n",
     "pass-through: lua_call 0x002139a0 rewrites its first two stack words and tail-jumps to luaD_call 0x002159e0, "
     "whose third argument (nresults) is lua_call's own third, passed through; declared with two, natively "
     "luaD_poscall filled `nresults` (stack garbage) nils past the Lua stack (the script call UpdateMoveList)"),
    ("equivalent/0x0021f300.cpp", "    int values[5];\n", "    int values[6];\n",
     "exprstat 0x0021f300: values[0] is the assignment's link and values[1..5] the expdesc (k, info, aux, t, f) "
     "primaryexp 0x0021d830 fills: the array was one word short, natively `item` (ls->fs) lay there and the "
     "expdesc's f (NO_JUMP, -1) overwrote it (the Lua parser crashed in luaK_setcallreturns 0x00220a50)"),
    # native11: a virtual call's argument left on the stack for the next call (check 7 through a vftable slot)
    ("equivalent/0x0028faa0.cpp", "    virtual int v18(int flag, void *location);\n};\nstruct Destination { void FUN_0022ca90(int value); };\n",
     "    virtual int v18(int flag);\n};\nstruct Destination { void FUN_0022ca90(int value, void *location); };\n",
     "check 7 through a vftable slot (native11): 0x0028faa0 pushes &location (+0x4c), then 0, calls slot 18 (`ret 4`: "
     "takes the 0) and passes its result and the location left on the stack to Matrix::Mult 0x0022ca90 (`ret 8`: a, b); "
     "declared as v18(0, location) and Mult(value), natively Mult read its second matrix from stack garbage (the "
     "front end's PolySkin draw 0x0029b750 crashed in 0x0022ca90)"),
    ("equivalent/0x0028faa0.cpp", "    int value = (*source)->v18(0, location);\n    destination.FUN_0022ca90(value);\n",
     "    destination.FUN_0022ca90((*source)->v18(0), location);\n", "(the same edit, the calls)"),
    ("equivalent/0x00296160.cpp", "virtual int vfunc_18(int,int,int);\n", "virtual int vfunc_18(int);\n",
     "check 7 through a vftable slot (native11, the same slot as 0x0028faa0): Scenegraph::vfunc_8 0x00296160 pushes "
     "(b, a, 0) and calls the context's slot 18 (`ret 4`: takes the 0); the root node's vfunc_8 (slot 8, "
     "BranchNode::vfunc_8 `ret 0xc`) takes its result and the a, b left on the stack. Declared as vfunc_18(0, a, b) "
     "and vfunc_8(result): natively the root node's draw read a return address as its second argument (the front "
     "end's PolySkin draw crashed in 0x0029b750)"),
    ("equivalent/0x00296160.cpp", "virtual void vfunc_7(); virtual void vfunc_8(int);\n};\nnamespace",
     "virtual void vfunc_7(); virtual void vfunc_8(int, int, int);\n};\nnamespace", "(the same edit, slot 8)"),
    ("equivalent/0x00296160.cpp",
     "  int result = (*(*(Device***)&DAT_0052c2ac))->vfunc_18(0,a,b);\n  typedef void (Child::*Method)(int);\n"
     "  union { void *address; Method method; } call;\n  call.address = savedTable[8];\n  (child->*call.method)(result);\n",
     "  typedef void (Child::*Method)(int, int, int);\n"
     "  (child->*(*(Method*)&savedTable[8]))((*(*(Device***)&DAT_0052c2ac))->vfunc_18(0), a, b);\n",
     "(the same edit, the calls: a and b are pushed before the slot-18 call, as in the original)"),
    ("equivalent/0x0024d840.cpp", "    virtual audio::ListenerEffectXBox_24d840* vfunc_3(audio::ListenerEffectXBox_24d840*);\n",
     "    virtual audio::ListenerEffectXBox_24d840* vfunc_3();\n", "check 7 through a vftable slot (native11): the listener-effect types' Create (0x0024d840 and its siblings) push the new effect, call the type's slot 3 (`mov eax, <base type>; ret`: takes nothing) and pass the effect left on the stack to the base type's init 0x0025fb00 (`ret 4`); declared as slot3(effect) and/or init(), natively init read its effect from stack garbage (the replay's first level load crashed in 0x0025fb00 at frame ~430)"),
    ("equivalent/0x0024d840.cpp", "    void FUN_0025fb00();\n", "    void FUN_0025fb00(ListenerEffectXBox_24d840*);\n", "(the same edit, the init)"),
    ("equivalent/0x0024d840.cpp",
     "        ListenerEffectXBox_24d840* object = ((EffectRegistry*)DAT_004e6468)->vfunc_3(result);\n        object->FUN_0025fb00();\n",
     "        ((EffectRegistry*)DAT_004e6468)->vfunc_3()->FUN_0025fb00(result);\n", "(the same edit, the calls)"),
    ("equivalent/0x0024da50.cpp", "    virtual ListenerEffectPs2* vfunc_3(ListenerEffectPs2*);\n", "    virtual ListenerEffectPs2* vfunc_3();\n",
     "(the same class as 0x0024d840: slot 3 takes nothing)"),
    ("equivalent/0x0024da50.cpp",
     "    ListenerEffectPs2* result = factory->vfunc_3(effect);\n    ((Returned*)result)->FUN_0025fb00(effect);\n",
     "    ((Returned*)factory->vfunc_3())->FUN_0025fb00(effect);\n", "(the same edit, the calls)"),
    ("equivalent/0x0024db50.cpp", "virtual void* vfunc_3(audio::ListenerEffectWin32*)=0; };", "virtual void* vfunc_3()=0; };",
     "(the same class as 0x0024d840: slot 3 takes nothing)"),
    ("equivalent/0x0024db50.cpp",
     " EffectResult* result = (EffectResult*)((Factory*)&(*(char*)&DAT_004e65b8))->vfunc_3(obj);\n result->FUN_0025fb00(obj);\n",
     " ((EffectResult*)((Factory*)&(*(char*)&DAT_004e65b8))->vfunc_3())->FUN_0025fb00(obj);\n", "(the same edit, the calls)"),
    ("matches/0x000e2a60.cpp", "    virtual int v44(int);\n", "    virtual int v44();\n",
     "check 7 through a vftable slot (native11): 0x000e2a60 pushes 1, calls the provider's slot 44 (takes nothing) and "
     "passes the 1 left on the stack to the text element's Set 0x000f8500 (`ret 0xc`: key, value, 1); declared as "
     "v44(1) and Set(key, value) with the key read as `(&x)[1]` (the word above x at that depth: x itself)"),
    ("matches/0x000e2a60.cpp", "    void Set(int, int);\n", "    void Set(int, int, int);\n", "(the same edit, Set)"),
    ("matches/0x000e2a60.cpp", "    elem.Set((&x)[1], outer->mid->provider->v44(1));\n", "    elem.Set(x, outer->mid->provider->v44(), 1);\n",
     "(the same edit, the calls)"),
    ("matches/0x000e5f70.cpp", "    short* Find(int);\n", "    short* Find(int, int);\n",
     "check 7 through a vftable slot (native11, the shape of 0x000e2a60): 0x000e5f70 pushes 0, calls the manager's "
     "slot 44 (takes nothing) and passes its result and the 0 to the text lookup 0x000f83f0 (`ret 8`: language, flag)"),
    ("matches/0x000e5f70.cpp", "    virtual int get(int);\n", "    virtual int get();\n", "(the same edit, slot 44)"),
    ("matches/0x000e5f70.cpp", "            int x = mgr->get(0);\n            short* q = ((Probe_e5f70*)((char*)p + 0x18))->Find(x);\n",
     "            short* q = ((Probe_e5f70*)((char*)p + 0x18))->Find(mgr->get(), 0);\n", "(the same edit, the calls)"),
    ("equivalent/0x000becd0.cpp", "virtual void* get(int); };", "virtual void* get(); };",
     "check 7 through a vftable slot (native11, the shape of 0x000e2a60): 0x000becd0 pushes the record's value, calls "
     "the service's slot 44 (takes nothing) and the item's key getter 0x000f72c0 (`ret 4`) takes the value"),
    ("equivalent/0x000becd0.cpp", "struct Object { __int64 FUN_000f72c0(); };", "struct Object { __int64 FUN_000f72c0(int); };",
     "(the same edit, the getter)"),
    ("equivalent/0x000becd0.cpp", " Object* obj=(Object*)service->get(record->value);\n __int64 key=obj->FUN_000f72c0();\n",
     " __int64 key=((Object*)service->get())->FUN_000f72c0(record->value);\n", "(the same edit, the calls)"),
    ("equivalent/0x000ef030.cpp", "virtual Brief* f44(const char*);", "virtual Brief* f44();",
     "check 7 through a vftable slot (native11, the shape of 0x000e2a60): the text service's slot 44 takes nothing; "
     "the string 0x000ef030 pushes before it is the argument of 0x000f7d30 (`ret 4`)"),
    ("equivalent/0x000ef030.cpp", "struct Brief { int FUN_000f7d30(); };", "struct Brief { int FUN_000f7d30(const char*); };",
     "(the same edit, the callee)"),
    ("equivalent/0x000ef030.cpp", "->f44(\"TBS_MISSION_BRIEF_C7M2\")->FUN_000f7d30();",
     "->f44()->FUN_000f7d30(\"TBS_MISSION_BRIEF_C7M2\");", "(the same edit, the calls)"),
    ("equivalent/0x000991b0.cpp", "    virtual int v14(int a, float b);\n", "    virtual int v14();\n",
     "check 7 through a vftable slot (native11): 0x000991b0 pushes the node's speed and out1, calls the node's slot 14 "
     "(takes nothing, as 0x000a1930's `v14()`) and 0x000fd8a0 (`ret 0x10`) takes (owner, result, out1, speed)"),
    ("equivalent/0x000991b0.cpp", "    void FUN_000fd8a0(void *owner, int arg);\n", "    void FUN_000fd8a0(void *owner, int arg, int a, float b);\n",
     "(the same edit, the callee)"),
    ("equivalent/0x000991b0.cpp", "                int r = node->v14(out1, f);\n                cur->FUN_000fd8a0(owner, r);\n",
     "                cur->FUN_000fd8a0(owner, node->v14(), out1, f);\n", "(the same edit, the calls)"),
    ("equivalent/0x000e39c0.cpp", "virtual Vec_e39c0* slot8(Vec_e39c0*, unsigned); };", "virtual Vec_e39c0* slot8(Vec_e39c0*); };",
     "check 7 through a vftable slot (native11): 0x000e39c0 pushes the tolerance 0x3727c5ac and &pos, calls the "
     "entry's slot 8 (`ret 4`: takes &pos) and 0x0022d2b0 (`ret 8`) takes (result, tolerance)"),
    ("equivalent/0x000e39c0.cpp", "    bool FUN_0022d2b0(Vec_e39c0*);\n", "    bool FUN_0022d2b0(Vec_e39c0*, unsigned);\n", "(the same edit, the callee)"),
    ("equivalent/0x000e39c0.cpp", "->FUN_0022d2b0(entry->slot8(&pos,0x3727c5ac))", "->FUN_0022d2b0(entry->slot8(&pos),0x3727c5ac)",
     "(the same edit, the calls)"),
    ("equivalent/0x00232cc0.cpp", " virtual int line(char*);\n", " virtual int line();\n",
     "check 7 through a vftable slot (native11): the fight reader's error report 0x00232cc0 pushes &message, calls the "
     "reader's slot 19 (the line number: takes nothing) and formats (name, line, message): the message pointer is the "
     "format's third argument (`add esp, 0x18`). Declared as line(message) and a format with two arguments, natively "
     "the `%s` read stack garbage (the fight script parser's \"Unexpected token.\" report crashed)"),
    ("equivalent/0x00232cc0.cpp", " int line = reader->line(message);\n FUN_00267760(fullMessage, 1024, \"fight::Reader ERROR\\n%s(%d):  %s\\n\", name, line);\n",
     " FUN_00267760(fullMessage, 1024, \"fight::Reader ERROR\\n%s(%d):  %s\\n\", name, reader->line(), message);\n",
     "(the same edit, the calls)"),
    ("equivalent/0x002787c0.cpp", "case 11:return 5;case 14:return 7;case 17:return 3;", "case 11:return 5;case 17:return 3;",
     "jump-table case index (native11, equiv.py round 15): the index byte table at 0x2788a4 sends 14 to the default "
     "target (8), not to 7 (only 0x70 returns 7)"),
    ("matches/0x0023ba20.cpp", "    virtual void vi(int, int, int, int);\n", "    virtual char vi(int, int, int, int);\n",
     "check 6 (native11): fight::BinReader::vfunc_6 0x0023ba20 (an enum value: the binary reader's int read, slot 10, or "
     "the string read, slot 8) returns its callee's bool (`call [eax+0x28]; ret 0x14`); declared void, natively "
     "ParamValueEnum::vfunc_5 0x00234cf0 read garbage as `ok` and the fight parameter reader went off its stream "
     "(the replay's level load: a 2 GB string length, out of memory in 0x0008d320)"),
    ("matches/0x0023ba20.cpp", "    virtual void vk(int, int, int);\n", "    virtual char vk(int, int, int);\n", "(the same edit, slot 10)"),
    ("matches/0x0023ba20.cpp", "    void vfunc_6(int, int, int, int, int);\n", "    char vfunc_6(int, int, int, int, int);\n", "(the same edit)"),
    ("matches/0x0023ba20.cpp", "void BinReader::vfunc_6(int p2, int p3, int p4, int p5, int p6) {\n    if (mode)\n        vk(p2, p3, p4);\n    else\n        vi(p2, p3, p5, p6);\n",
     "char BinReader::vfunc_6(int p2, int p3, int p4, int p5, int p6) {\n    if (mode)\n        return vk(p2, p3, p4);\n    else\n        return vi(p2, p3, p5, p6);\n",
     "(the same edit, the body)"),
    ("matches/0x00232f60.cpp", "    void run();\n", "    void* run();\n",
     "check 6 (native11): fight Node::run 0x00232f60 returns the dynamic_cast 0x00344e74 of the block node it finds "
     "(its caller 0x00233fe0 tests eax); declared void"),
    ("matches/0x00232f60.cpp", "extern void helper(Node*, int, const void*, const void*, int);\n",
     "extern void* helper(Node*, int, const void*, const void*, int);\n", "(the same edit, the cast)"),
    ("matches/0x00232f60.cpp", "void Node::run() {\n    if (type == 3) {\n        helper(this, 0, &desc1_232f60, &desc2_232f60, 0);\n        return;\n    }\n",
     "void* Node::run() {\n    if (type == 3)\n        return helper(this, 0, &desc1_232f60, &desc2_232f60, 0);\n", "(the same edit)"),
    ("matches/0x00232f60.cpp", "        q = q->next;\n    helper(q, 0,", "        q = q->next;\n    return helper(q, 0,", "(the same edit)"),
    ("matches/0x000ad580.cpp", "    void Do(int a, int b);\n", "    int Do(int a, int b);\n", "check 6 (native11): Manager_ad580::Run 0x000ad580 forwards its callee's result in eax on every path (the original caller 0x000d3f10 tests it); declared void"),
    ("matches/0x000ad580.cpp", "void Fallback(int a, int b);\n", "int Fallback(int a, int b);\n", "(the same edit)"),
    ("matches/0x000ad580.cpp", "    void Run(int id, int a, int b);\n", "    int Run(int id, int a, int b);\n", "(the same edit)"),
    ("matches/0x000ad580.cpp", "void Manager_ad580::Run(", "int Manager_ad580::Run(", "(the same edit)"),
    ("matches/0x000ad580.cpp", "                arr[i]->Do(a, b);\n                return;\n", "                return arr[i]->Do(a, b);\n", "(the same edit)"),
    ("matches/0x000ad580.cpp", "    Fallback(a, b);\n}", "    return Fallback(a, b);\n}", "(the same edit)"),
    ("matches/0x000ad7b0.cpp", "    void action(int a, int b);\n", "    int action(int a, int b);\n", "check 6 (native11): Owner_ad7b0::run 0x000ad7b0 forwards its callee's result in eax on every path (the original caller 0x000d3f10 tests it); declared void"),
    ("matches/0x000ad7b0.cpp", "void fallback(int a, int b);\n", "int fallback(int a, int b);\n", "(the same edit)"),
    ("matches/0x000ad7b0.cpp", "    void run(int key, int a, int b);\n", "    int run(int key, int a, int b);\n", "(the same edit)"),
    ("matches/0x000ad7b0.cpp", "void Owner_ad7b0::run(", "int Owner_ad7b0::run(", "(the same edit)"),
    ("matches/0x000ad7b0.cpp", "            items[i]->action(a, b);\n            return;\n", "            return items[i]->action(a, b);\n", "(the same edit)"),
    ("matches/0x000ad7b0.cpp", "    fallback(a, b);\n}", "    return fallback(a, b);\n}", "(the same edit)"),
    ("matches/0x00099d60.cpp", "    void A(U_99d60* p);\n    void B(U_99d60* p);\n", "    int A(U_99d60* p);\n    int B(U_99d60* p);\n", "check 6 (native11): 0x00099d60 forwards its callee's result in eax on every path (the original caller 0x001f9810 tests it); declared void"),
    ("matches/0x00099d60.cpp", "void __stdcall FUN_00099d60(", "int __stdcall FUN_00099d60(", "(the same edit)"),
    ("matches/0x00099d60.cpp", "    if (flag)\n        o->A(&x[3]);\n    else\n        o->B(&x[3]);\n",
     "    if (flag)\n        return o->A(&x[3]);\n    return o->B(&x[3]);\n", "(the same edit)"),
    ("equivalent/0x00241930.cpp",
     "void __cdecl FUN_00241930(Tree *tree, Node *node)\n{\n    Node *end = &tree->sentinel;\n    Node *next = node->parent;\n"
     "    if (next == end) {\n        next = node->right;\n        while (next != end && node == next->parent) {\n"
     "            node = next;\n            next = next->right;\n        }\n    } else {\n        next = next->left;\n"
     "        while (next != end)\n            next = next->left;\n    }\n}",
     "Node * __cdecl FUN_00241930(Tree *tree, Node *node)\n{\n    Node *end = &tree->sentinel;\n    Node *next = node->parent;\n"
     "    if (next == end) {\n        next = node->right;\n        while (next != end && node == next->parent) {\n"
     "            node = next;\n            next = next->right;\n        }\n        return next;\n    }\n"
     "    while (next->left != end)\n        next = next->left;\n    return next;\n}",
     "check 6 (native11): the tree step 0x00241930 returns the node it finds (its caller 0x002424a0 uses eax): the "
     "leftmost node of the parent link's subtree, not the sentinel the declared-void loop stopped at"),
    ("equivalent/0x001b0470.cpp",
     "// The case-selection bytes follow five branch addresses in the dispatch data.\nstruct DispatchData {\n"
     "    unsigned char* branches[5];\n    unsigned char cases[10];\n};\n\n", "", "(the same edit, the table's struct)"),
    # native12: check 6 findings that are real (the callers' sources use the result)
    ("equivalent/0x0033c6e0.cpp", "void FUN_0033c6e0(CaptureState *state, int value, int arg1, int arg2)",
     "int FUN_0033c6e0(CaptureState *state, int value, int arg1, int arg2)",
     "check 6 (native12): Lua's start_capture 0x0033c6e0 returns match()'s result (its caller 0x0033c7e0, do_match, "
     "returns it: string.find/gsub with captures); declared void"),
    ("equivalent/0x0033c6e0.cpp", "    if (!FUN_0033c7e0(state, value, arg1))\n        --state->count;\n}",
     "    int result = FUN_0033c7e0(state, value, arg1);\n    if (!result)\n        --state->count;\n    return result;\n}",
     "(the same edit)"),
    ("matches/0x002b2c30.cpp", "    virtual void doIt(Caster_2b2c30*, U64);", "    virtual void* doIt(Caster_2b2c30*, U64);",
     "check 6 (native12): 0x002b2c30 returns the loader slot's result (its caller 0x002b2ea0 keeps it as the "
     "controller); declared void"),
    ("matches/0x002b2c30.cpp", "void __cdecl target(Obj* obj, void* p) {", "void* __cdecl target(Obj* obj, void* p) {",
     "(the same edit)"),
    ("matches/0x002b2c30.cpp", "    obj->doIt(&caster, v);\n}", "    return obj->doIt(&caster, v);\n}", "(the same edit)"),
    ("matches/0x00219610.cpp", "void FUN_00219610(Owner_219610* self, uint_219610 key) {",
     "Node* FUN_00219610(Owner_219610* self, uint_219610 key) {",
     "check 6 (native12): luaF_findupval 0x00219610 returns the upvalue (found or new; luaV_execute's OP_CLOSURE "
     "stores it): declared void, the native closures got &L->openupval as their upvalue (play3's level scripts: "
     "arithmetic on a nil upvalue)"),
    ("matches/0x00219610.cpp", "        if (current->key == key)\n            return;", "        if (current->key == key)\n            return current;",
     "(the same edit)"),
    ("matches/0x00219610.cpp", "    *link = node;\n}", "    *link = node;\n    return node;\n}", "(the same edit)"),
    ("matches/0x0030bf40.cpp", "void FUN_0030bf40(U32_30bf40* param_1, int param_2, U32_30bf40* param_3) {\n    volatile U32_30bf40* out = param_3;",
     "U32_30bf40* FUN_0030bf40(U32_30bf40* param_1, int param_2, U32_30bf40* param_3) {\n    U32_30bf40* out = param_3;",
     "check 6 (native12): the copy 0x0030bf40 returns the end of the destination (its caller 0x0030c580 stores it); "
     "declared void"),
    ("matches/0x0030bf40.cpp", "        } while (--param_2 != 0);\n    }\n}", "        } while (--param_2 != 0);\n    }\n    return out;\n}",
     "(the same edit)"),
    ("matches/0x00047970.cpp", 'extern "C" int __cdecl _isnan(double);\nvoid FUN_00047970(float param_1) {\n    _isnan((double)param_1);\n}',
     'extern "C" double __cdecl floor(double);\ndouble FUN_00047970(float param_1) {\n    return floor((double)param_1);\n}',
     "check 6 (native12): 0x00047970 is floor's wrapper (0x0034557c is floor; the propagated name said _isnan, bound "
     "ambiguously) and its callers (0x002899e0) use st0"),
    # native13: check 6, real: the script table's lookup returns the script it finds or loads
    ("equivalent/0x000fb240.cpp", "    void FUN_000faf80(int result);\n    void FUN_000fb240(void *item);",
     "    void *FUN_000faf80(int result);\n    void *FUN_000fb240(void *item);",
     "check 6 (native13): 0x000fb240 returns the parsed script 0x000faf80 returns (0 when neither the loader slot nor "
     "0x000fa4b0 has it); its caller 0x000f5fa0 keeps it (`Script_f5fa0 *script = ...FUN_000fb240(name)`); declared void"),
    ("equivalent/0x000fb240.cpp", "void Inventory::FUN_000fb240(void *item) {", "void *Inventory::FUN_000fb240(void *item) {",
     "(the same edit)"),
    ("equivalent/0x000fb240.cpp", "        if (!result) return;\n    }\n    FUN_000faf80(result);\n}",
     "        if (!result) return 0;\n    }\n    return FUN_000faf80(result);\n}", "(the same edit)"),
    # native13: a literal shorter than the original's item (verify_relocs compares a literal up to its first NUL)
    ("matches/0x003388d0.cpp", '    F1(b83a, (const unsigned short*)L"()");', '    F1(b83a, (const unsigned short*)L"()[]{}=;");',
     "literal (native13, stop 34): the tokenizer's one-character token list at 0x00434634 is the wide string "
     "L\"()[]{}=;\" (read as a double-NUL list of 1-char strings by 0x00338640); the source spelled L\"()\", so natively "
     "`[`/`]` were not tokens, the type-schema loader 0x00337700 read `HudMap]` as a type name and stopped, no "
     "Locator type was registered, the level's locators never loaded and SpawnHulk found no `spawn_hulk`"),
    # native13: check 7 through a vftable slot (native11's row 28), spelled with the next call's words twice: the
    # virtual declared with them (natively it "pops" them: the caller's stack is off by their size afterwards)
    ("equivalent/0x002f2fc0.cpp", " virtual CallbackResult* vfunc_4(void*, void*, void*);", " virtual CallbackResult* vfunc_4(void*);",
     "check 7 through a vftable slot (native13, stop 35): CollisionCylinder::vfunc_13 0x002f2fc0 pushes (position, "
     "+0x70, +0x08), calls the owner's callback slot 4 (SimState::vfunc_4 0x002ef300: `ret 4`, takes +0x08) and the "
     "transform 0x0022c3b0 (`ret 8`) takes the two words left; declared vfunc_4(a, b, c) and the transform's (b, c) "
     "again: natively 8 bytes too many came off the stack and vfunc_13 returned to 0 (first level, Hulk's collision setup)"),
    ("equivalent/0x002f2fc0.cpp",
     " CallbackResult* result = owner->callback->vfunc_4(field08, pad70, position);\n result->FUN_0022c3b0(pad70, position);",
     " owner->callback->vfunc_4(field08)->FUN_0022c3b0(pad70, position);", "(the same edit)"),
    ("equivalent/0x0024da50.cpp", "    virtual ListenerEffectPs2_24da50* vfunc_3(ListenerEffectPs2_24da50*);",
     "    virtual ListenerEffectPs2_24da50* vfunc_3();",
     "check 7 through a vftable slot (native13): native11's 0x0024da50 patch no longer applied after a rename; slot 3 "
     "takes nothing, the effect is the init 0x0025fb00's"),
    ("equivalent/0x0024da50.cpp",
     "    ListenerEffectPs2_24da50* result = factory->vfunc_3(effect);\n    ((Returned*)result)->FUN_0025fb00(effect);",
     "    ((Returned*)factory->vfunc_3())->FUN_0025fb00(effect);", "(the same edit)"),
    ("equivalent/0x0024db50.cpp", "virtual void* vfunc_3(audio::ListenerEffectWin32_24db50*)=0; };", "virtual void* vfunc_3()=0; };",
     "check 7 through a vftable slot (native13): as 0x0024da50 (native11's patch text no longer matched)"),
    ("equivalent/0x0024db50.cpp",
     " EffectResult* result = (EffectResult*)((Factory*)&(*(char*)&DAT_004e65b8))->vfunc_3(obj);\n result->FUN_0025fb00(obj);",
     " ((EffectResult*)((Factory*)&(*(char*)&DAT_004e65b8))->vfunc_3())->FUN_0025fb00(obj);", "(the same edit)"),
    # native13: a value the original keeps in edx across a call whose callee never writes edx (whole-program
    # register allocation), spelled as the high half of a 64-bit return: natively the definition's edx is garbage
    ("equivalent/0x00271b70.cpp", "    const unsigned char *p = (const unsigned char *)(hulk_uintptr)(result >> 32);",
     "    const unsigned char *p = text;",
     "callee-preserved edx (native13): the UTF-8 decoder 0x00271b70 reads the text pointer back from edx after the "
     "validator 0x002719a0 (__fastcall, the text in edx, never written); declared as the validator's 64-bit result"),
    # native14: fields of a frame structure the caller passes by pointer, stored by the original and missing in the
    # source (equiv.py doesn't compare the caller's frame bytes a callee reads through an argument)
    ("equivalent/0x0027dca0.cpp", """class Handler_27dca0 {
public:
    virtual void vfunc_0(Id64_27dca0 *id, Chain_27dca0 *chain);
};""", """// the listener event: the prop's state id, the kind (-1: a state change) and a value
struct Event_27dca0 {
    Id64_27dca0 id;
    int type;
    int value;
};

class Handler_27dca0 {
public:
    virtual void vfunc_0(Event_27dca0 *ev, Chain_27dca0 *chain);
};""",
     "frame structure fields (native14, stop 38): the state prop's change notification 0x0027dca0 passes its "
     "listeners {state id, type -1, 0} (`mov [esp+0x1c], -1` after the id's constructor, `mov [esp+0x1c], 0` before "
     "the loop); the source passed only the id, so natively CSPListener::vfunc_0 0x001db230 switched on stack garbage "
     "and no prop's state change (breakage, the ERS event 20, `State_%d`) was ever handled"),
    ("equivalent/0x0027dca0.cpp", """    Id64_27dca0 id;
    Id64_27dca0 empty;

    id.FUN_0027af00();
    empty.FUN_0027b0e0(((char*)&DAT_003f335c));
    id.FUN_0027af70(&empty);
    empty.FUN_0027af50();

    for (int i = 0; i < count; i++)
        handlers[i]->vfunc_0(&id, this);

    id.FUN_0027af50();""", """    Event_27dca0 ev;
    Id64_27dca0 empty;

    ev.id.FUN_0027af00();
    ev.type = -1;
    empty.FUN_0027b0e0(((char*)&DAT_003f335c));
    ev.id.FUN_0027af70(&empty);
    empty.FUN_0027af50();
    ev.value = 0;

    for (int i = 0; i < count; i++)
        handlers[i]->vfunc_0(&ev, this);

    ev.id.FUN_0027af50();""", "(the same edit)"),
    # native14: x87 precision: a float local MSVC 7.1 keeps in an x87 register (53-bit mantissa, the game's control
    # word 0x023f) across statements, which clang -O0 rounds to 24 bits when it stores the local; spelled `double`
    # (the same register value) with the stores to float memory explicit: MSVC compiles the same bytes
    ("matches/0x000350c0.cpp", "        float r = v * 0.5f + p[1];", "        double r = v * 0.5f + (double)p[1];",
     "x87 precision (native14, stop 39): Hulk's position getter 0x000350c0 adds half the collision height to y and "
     "keeps the sum in st0 for the second addition (`fst [edi+4]` ... `fadd st(1)`); the source's `float r` rounded "
     "it natively: y one ULP off at frame 445, the chase camera's y 1-14 ULP off from frame 450 on"),
    ("matches/0x000350c0.cpp", "            p[1] = y->f3c * 0.5f + r;", "            p[1] = (float)(y->f3c * 0.5f + r);",
     "(the same edit)"),
    # native14: check 7 (listed since native12, never applied): the name constructor 0x0027b0e0 (`ret 4`) declared
    # with the next call's six words; natively the entity manager's add 0x001dd330 got one argument
    ("matches/0x000796e0.cpp", "Request* FUN_0027b0e0(const char*, unsigned int, Matrix*, unsigned int, unsigned int, unsigned int, unsigned int);",
     "Request* FUN_0027b0e0(const char*);",
     "check 7 (native14, stop 40): the prop factory 0x000796e0 pushes (0, d, c, b, &m, a), builds the name 0x0027b0e0 "
     "(`ret 4`: takes the text only) and calls the entity manager's add 0x001dd330 (`ret 0x1c`) with the name and the "
     "six words; the source declared the name constructor with all seven and the add with one: natively the add read "
     "garbage for the transform, every ambient cow got a record at (0, 4, ...) and was deleted and re-created each frame"),
    ("matches/0x000796e0.cpp", "struct Manager_796e0 { unsigned int FUN_001dd330(Request*); };",
     "struct Manager_796e0 { unsigned int FUN_001dd330(Request*, unsigned int, Matrix*, unsigned int, unsigned int, unsigned int, unsigned int); };",
     "(the same edit)"),
    ("matches/0x000796e0.cpp", "Request* request=r.FUN_0027b0e0(text,a,&m,b,c,d,0); unsigned int result=manager->FUN_001dd330(request);",
     "unsigned int result=manager->FUN_001dd330(r.FUN_0027b0e0(text),a,&m,b,c,d,0);", "(the same edit)"),
    ("equivalent/0x0012f750.cpp", "struct Obj3_12f750 { char FUN_00092de0(); };", "struct Obj3_12f750 { char FUN_00092de0(int n); };",
     "check 7 (native14): natively clang re-reserves its call frame after a callee-pops call by the bytes the declaration pops, so a callee that pops a different number shifts every later outgoing argument: 0x0012f750 pushes 2 for 0x00092de0 (`ret 4`) before calling the getter 0x00086340 (`ret`)"),
    ("equivalent/0x0012f750.cpp", "Obj3_12f750 *FUN_00086340(int n); };", "Obj3_12f750 *FUN_00086340(); };", "(the same edit)"),
    ("equivalent/0x0012f750.cpp", "DAT_004dd6ec->FUN_00086340(2)->FUN_00092de0() != 0", "DAT_004dd6ec->FUN_00086340()->FUN_00092de0(2) != 0",
     "(the same edit)"),
    ("matches/0x001b3320.cpp", "    void doIt();", "    void doIt(Vec, int, int, int);",
     "check 7 (native14): natively clang re-reserves its call frame after a callee-pops call by the bytes the declaration pops, so a callee that pops a different number shifts every later outgoing argument: 0x001b3320 pushes the explosion's (position, kind, 0, 0) for 0x001b4620 (`ret 0x18`) before the getter 0x001b6580 (`ret`); declared get(Vec, int, int, int) and doIt()"),
    ("matches/0x001b3320.cpp", "Obj* __stdcall get(Vec, int, int, int);", "Obj* get();", "(the same edit)"),
    ("matches/0x001b3320.cpp", "        Obj* p = get(v, n, 0, 0);\n        p->doIt();", "        get()->doIt(v, n, 0, 0);", "(the same edit)"),
    ("matches/0x001c5740.cpp", "    int convert(Arg*);", "    int convert();",
     "check 7 (native14): natively clang re-reserves its call frame after a callee-pops call by the bytes the declaration pops, so a callee that pops a different number shifts every later outgoing argument: 0x001c5740 pushes n for 0x001c7870 (`ret 8`) before n's 0x001c5b70 (`ret`)"),
    ("matches/0x001c5740.cpp", "    void g(int);", "    void g(int, Arg*);", "(the same edit)"),
    ("matches/0x001c5740.cpp", "    g(n->convert(n));", "    g(n->convert(), n);", "(the same edit)"),
]


def reg_call(rel, text):
    """(new text, [why]) for the reg-call rule (groups in tools/native_calls.py)."""
    import native_calls
    out, names = text, []
    for g_rel, why, edits in native_calls.REG_CALLS:
        if g_rel != rel:
            continue
        if any(old not in out for old, _new in edits):
            if any(old in out for old, _new in edits):
                names.append("SKIP (not every text present): %s" % why)
            continue
        for old, new in edits:
            out = out.replace(old, new)
        names.append(why)
    return out, names


def demote_verify(rel, addr, text):
    """(verdict, equivalent/ text with equiv.py's STATUS header) for a matches/ source rewritten for reg-call."""
    import subprocess
    import tempfile
    d = tempfile.mkdtemp(prefix="demote-", dir=os.path.join(ROOT, "build"))
    p = os.path.join(d, os.path.basename(rel))
    with open(p, "w", encoding="latin1", newline="") as f:
        f.write(text)
    try:
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/equiv.py"), p, "0x%08x" % addr, "--inputs", "3000",
                            "--json"], capture_output=True, text=True, errors="replace", cwd=ROOT)
        try:
            rep = json.loads(r.stdout.strip().splitlines()[-1])
        except (ValueError, IndexError):
            return "equiv.py: no result", None
    finally:
        import shutil
        shutil.rmtree(d, ignore_errors=True)
    if rep.get("status") != "equivalent" or not rep.get("promotable"):
        return "equiv.py: %s%s" % (rep.get("status"), "" if rep.get("promotable") else " (not promotable)"), None
    l3 = rep["level3"]
    c = l3["coverage"]
    head = ("// STATUS: equivalent (tools/equiv.py level 3: %d inputs, branch coverage %d/%d%s)\n"
            "// %s @ 0x%08x\n" % (l3["inputs_run"], c["edges_covered"], c["edges_total"],
                                  "" if c["complete"] else ", incomplete", rep.get("target") or "FUN_%08x" % addr, addr))
    return "EQUIVALENT", head + text


def skipped_sources():
    """Sources no rule may rewrite: the paths listed in the file HULK_FIX_SKIP names (one per line; another
    session's untracked work)."""
    p = os.environ.get("HULK_FIX_SKIP")
    if not p or not os.path.exists(p):
        return set()
    return {l.strip() for l in open(p) if l.strip() and not l.startswith("#")}


def load_sources():
    out = []
    skip = skipped_sources()
    for d in ("matches", "equivalent"):
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if re.fullmatch(r"0x[0-9a-fA-F]{8}\.cpp", fn):
                rel = "%s/%s" % (d, fn)
                if rel in skip:
                    continue
                out.append((rel, int(fn[2:10], 16), open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()))
    return out


SPEC_CLASS = re.compile(r"\btemplate\s*<\s*>\s*(?:class|struct|union)\s+([\w:]+)\s*<")


def template_spec(text):
    """(new text, [names]) for the template-spec rule."""
    if "<" not in text:
        return text, []
    try:
        items = cxx_items.parse(text)
    except ValueError:
        return text, []
    explicit = {m.group(1).split("::")[-1] for m in SPEC_CLASS.finditer(text)}
    edits, names = [], []
    for it in items:
        if it.kind != "funcdef" or not it.key or it.key[0].startswith("template"):
            continue
        vs = [t.v for t in it.toks]
        if "template" in vs[:vs.index("(")] if "(" in vs else True:
            continue
        q = it.key[1]
        if "::" not in q:
            continue
        cls = q.rsplit("::", 1)[0]
        if "<" not in cls:
            continue
        # the class template-ids in the qualifier: X<...>::  (the last one before the member name)
        heads = re.findall(r"(\w+)\s*<", cls)
        if not heads or any(h in explicit for h in heads):
            continue
        edits.append(it.toks[0].s)
        names.append(q)
    for s in sorted(edits, reverse=True):
        text = text[:s] + "template <> " + text[s:]
    return text, names


TEMPLATE_CLASS = re.compile(r"\btemplate\s*<([^<>]*)>\s*(?:class|struct)\s+(\w+)\s*:\s*(?:public\s+)?(\w+)\s*<([^<>{};]*)>\s*\{")


def _body(text, i):
    """End index (exclusive) of the brace block opening at text[i] == '{'."""
    depth = 0
    for j in range(i, len(text)):
        c = text[j]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return j + 1
    return -1


def base_typedefs(text, base):
    """Typedef names declared in the body of `template <...> class base`."""
    m = re.search(r"\btemplate\s*<[^<>]*>\s*(?:class|struct)\s+%s\b[^;{]*\{" % re.escape(base), text)
    if not m:
        return set()
    e = _body(text, m.end() - 1)
    body = text[m.end():e]
    out = set()
    for d in re.finditer(r"\btypedef\b([^;]*);", body):
        decl = d.group(1)
        f = re.search(r"\(\s*[\w:]*::\*\s*(\w+)\s*\)", decl) or re.search(r"\(\s*\*\s*(\w+)\s*\)", decl) \
            or re.search(r"(\w+)\s*$", decl)
        if f:
            out.add(f.group(1))
    return out


def dependent_base(text):
    """(new text, [names]) for the dependent-base rule."""
    edits, names = [], []
    for m in TEMPLATE_CLASS.finditer(text):
        params = [p.split()[-1] for p in m.group(1).split(",") if p.split()]
        args = [a.strip() for a in m.group(4).split(",")]
        if not params or not all(a in params for a in args):
            continue                      # the base is dependent only on the derived class's own parameters
        derived, base = m.group(2), m.group(3)
        tds = base_typedefs(text, base)
        if not tds:
            continue
        e = _body(text, m.end() - 1)
        body = text[m.end():e]
        own = set(re.findall(r"\btypedef\b[^;]*?(\w+)\s*\)?\s*(?:\([^;]*\))?\s*;", body))
        for td in sorted(tds - own):
            for u in re.finditer(r"(?<![\w:])%s\b" % re.escape(td), body):
                edits.append((m.end() + u.start(), m.end() + u.end(),
                              "typename %s<%s>::%s" % (base, m.group(4).strip(), td)))
                names.append("%s: %s" % (derived, td))
    for s, e, rep in sorted(edits, reverse=True):
        text = text[:s] + rep + text[e:]
    return text, sorted(set(names))


RETURN_STRUCT = re.compile(r'(^[ \t]*)(extern "C" )?struct (\w+) (\{[^{}]*\})[ \t]*(\*?[ \t]*(?:__cdecl[ \t]+)?\w+[ \t]*\()', re.M)


def return_struct(text):
    """(new text, [names]) for the return-struct rule: `[extern "C"] struct P {...} f(...);` -> `struct P {...};`
    then `[extern "C"] P f(...);` (a type defined in a return type: an MSVC extension)."""
    names = []

    def rep(m):
        names.append(m.group(3))
        return "%sstruct %s %s;\n%s%s%s %s" % (m.group(1), m.group(3), m.group(4), m.group(1), m.group(2) or "",
                                                m.group(3), m.group(5))
    return RETURN_STRUCT.sub(rep, text), names


def patch(rel, text):
    out, names = text, []
    for p_rel, old, new, why in PATCHES:
        if p_rel != rel:
            continue
        if out.count(old) != 1:
            names.append("SKIP (%d occurrences): %s" % (out.count(old), why))
            continue
        out = out.replace(old, new)
        names.append(why)
    return out, names


# ---------------------------------------------------------------------------------------------
# register-order: a caller's declaration of a register-convention callee in its definition's parameter order
_REG_ORDERS = {}


def register_findings():
    """{caller file: [(callee name, caller locations, definition locations)]} from tools/native_conv_check.py
    check 5 (cached per run)."""
    if "f" not in _REG_ORDERS:
        import native_conv_check
        _n, bad = native_conv_check.check_register_orders()
        out = {}
        for b in bad:
            out.setdefault(b["file"], []).append((int(b["addr"], 16), tuple(b["conv"].split()),
                                                   tuple(b["definition_conv"].split())))
        _REG_ORDERS["f"] = out
    return _REG_ORDERS["f"]


def blank_comments(text):
    """text with comments and string/char literals' contents replaced by spaces (offsets kept)."""
    out = list(text)
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out[i:j] = " " * (j - i)
            i = j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out[i:j] = [ch if ch == "\n" else " " for ch in text[i:j]]
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            out[i + 1:j] = " " * (j - i - 1)
            i = j + 1
        else:
            i += 1
    return "".join(out)


def split_args(text, start, end, angle=False):
    """[(s, e)] spans of the top-level comma-separated items of text[start:end]."""
    spans, depth, s = [], 0, start
    opens, closes = "([{" + ("<" if angle else ""), ")]}" + (">" if angle else "")
    for i in range(start, end):
        ch = text[i]
        if ch in opens:
            depth += 1
        elif ch in closes:
            depth -= 1
        elif ch == "," and depth == 0:
            spans.append((s, i))
            s = i + 1
    if text[start:end].strip():
        spans.append((s, end))
    return spans


def order_plan(locs, def_locs):
    """[index into the caller's parameters] for each of the definition's, or None when the caller lacks one of the
    definition's locations (it would have to pass a value it doesn't have). Stack slots keep their order."""
    used, plan = set(), []
    for l in def_locs:
        j = next((k for k, x in enumerate(locs) if x == l and k not in used), None)
        if j is None:
            return None
        used.add(j)
        plan.append(j)
    return plan


def register_order(rel, text):
    """The register-order rule for one source: reorder (and drop the caller's extra) parameters of every
    declaration and argument of every call of a callee whose `// equiv-conv` note lists its parameters in another
    order than the callee's own note, and the note itself. Callees whose definition reads a location the caller
    doesn't pass are left alone (reported)."""
    finds = register_findings().get(rel)
    if not finds:
        return text, []
    names = []
    for addr, locs, def_locs in finds:
        plan = order_plan(locs, def_locs)
        if plan is None:
            names.append("SKIP 0x%08x: the definition reads %s, the caller passes %s" % (addr, " ".join(def_locs), " ".join(locs)))
            continue
        nm = re.search(r"//\s*equiv-conv:\s*(\S*%06x)\s+%s\s*$" % (addr & 0xFFFFFF, r"\s+".join(locs)), text, re.M | re.I)
        if not nm:
            names.append("SKIP 0x%08x: note not found" % addr)
            continue
        name = nm.group(1)
        blank = blank_comments(text)
        edits = []
        ok = True
        for m in re.finditer(r"\b%s\s*\(" % re.escape(name), blank):
            i, depth = m.end(), 1
            while i < len(blank) and depth:
                depth += {"(": 1, ")": -1}.get(blank[i], 0)
                i += 1
            a0, a1 = m.end(), i - 1
            after = blank[i:i + 40].lstrip()
            k = max(blank.rfind(";", 0, m.start()), blank.rfind("{", 0, m.start()), blank.rfind("}", 0, m.start()))
            prefix = blank[k + 1:m.start()].strip()
            is_decl = after.startswith((";", "{", "throw")) and prefix and not re.search(r"[=(,!&|+\-/<>?:\[]$|\breturn$", prefix) \
                and not re.search(r"\breturn\b|=", prefix)
            spans = split_args(blank, a0, a1, angle=is_decl)
            if len(spans) != len(locs):
                ok = False
                break
            items = [text[s:e].strip() for s, e in spans]
            new = ", ".join(items[j] for j in plan)
            edits.append((a0, a1, new))
        if not ok or not edits:
            names.append("SKIP 0x%08x: %s" % (addr, "argument count differs from the note" if not ok else "no uses"))
            continue
        out = text
        for a0, a1, new in sorted(edits, reverse=True):
            out = out[:a0] + new + out[a1:]
        out = re.sub(r"(//\s*equiv-conv:\s*%s\s+)%s(\s*)$" % (re.escape(name), r"\s+".join(locs)),
                     lambda mm: mm.group(1) + " ".join(def_locs) + mm.group(2), out, count=1, flags=re.M)
        text = out
        names.append("0x%08x %s: %s -> %s (%d sites)" % (addr, name, " ".join(locs), " ".join(def_locs), len(edits)))
    return text, names


# ---------------------------------------------------------------------------------------------
# void-return: a `void` definition whose original callers use the result it leaves in eax
_VOID_RET = {}
TREE_REPORT = os.environ.get("HULK_TREE_REPORT") or os.path.join(ROOT, "build/tree/report.json")


def void_return_findings():
    """{definition file: {symbol}} of tools/native_conv_check.py check 6 (eax uses only; cached per run)."""
    if "f" not in _VOID_RET:
        import native_conv_check
        _n, bad, _h = native_conv_check.check_returns(tree_report=TREE_REPORT)
        out = {}
        for b in bad:
            if b["declared"] == "void" and "eax" in b["why"]:
                out.setdefault(b["file"], set()).add(b["symbol"])
        _VOID_RET["f"] = out
    return _VOID_RET["f"]


def _plain_name(sym):
    if sym.startswith("?"):
        m = re.match(r"\?([\w$]+)@", sym)
        return m.group(1) if m else None
    m = re.fullmatch(r"[_@]?(\w+?)(?:@\d+)?", sym)
    return m.group(1) if m else None


DECL_WORDS = r"(?:virtual\s+|static\s+|extern\s+|inline\s+|__inline\s+|__forceinline\s+)*"
CONV_WORD = r"(?:__cdecl\s+|__stdcall\s+|__thiscall\s+|__fastcall\s+)?"


def void_return(rel, text):
    """The void-return rule for one source: its definition returns `void` but the original's callers use eax after
    calling it (check 6), and its body ends in a call (`...; g(x);`, the original `call g; ret` or `jmp g`): the
    definition returns that call's value. The callee's declaration in this source gets the return type `int` if it
    was `void` too (a pointer- or int-returning callee keeps its own type, which the definition takes over)."""
    syms = void_return_findings().get(rel)
    if not syms:
        return text, []
    names = []
    for sym in sorted(syms):
        name = _plain_name(sym)
        if not name:
            continue
        blank = blank_comments(text)
        defs = []
        for m in re.finditer(r"\bvoid\s+" + CONV_WORD + r"((?:\w+::)*)" + re.escape(name) + r"\s*\(", blank):
            i, depth = m.end(), 1
            while i < len(blank) and depth:
                depth += {"(": 1, ")": -1}.get(blank[i], 0)
                i += 1
            rest = re.match(r"\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?\{", blank[i:])
            if rest:
                defs.append((m, i + rest.end() - 1))
        if len(defs) != 1:
            names.append("SKIP %s: %d definitions" % (name, len(defs)))
            continue
        m, b0 = defs[0]
        depth, j = 0, b0
        while j < len(blank):
            depth += {"{": 1, "}": -1}.get(blank[j], 0)
            if depth == 0:
                break
            j += 1
        body = blank[b0 + 1:j]
        tail = body.rstrip()
        if not tail.endswith(";"):
            names.append("SKIP %s: the body does not end in a statement" % name)
            continue
        k = max(tail.rfind(";", 0, len(tail) - 1), tail.rfind("{", 0, len(tail) - 1), tail.rfind("}", 0, len(tail) - 1))
        stmt = tail[k + 1:-1]
        st = stmt.strip()
        if not st.endswith(")") or re.match(r"(return|if|while|for|switch|do|else|delete)\b", st) or re.search(r"(?<![=!<>])=(?!=)", st):
            names.append("SKIP %s: the last statement is not a call (%s)" % (name, " ".join(st.split())[:60]))
            continue
        # the callee: the identifier before the last top-level argument list
        q, depth = len(st) - 1, 0
        while q >= 0:
            depth += {")": 1, "(": -1}.get(st[q], 0)
            if depth == 0:
                break
            q -= 1
        cm = re.search(r"(\w+)\s*$", st[:q])
        if not cm:
            names.append("SKIP %s: no callee name" % name)
            continue
        callee = cm.group(1)
        if callee in ("_ReadWriteBarrier",):
            names.append("SKIP %s: the last call is a compiler barrier" % name)
            continue
        ret_type = "int"
        new = text
        cdecls = list(re.finditer(r"(?m)(^|[;{}(,]|\b(?:virtual|static|inline)\b|\bextern\b(?!\s+\"))\s*" + r"(?:extern\s+\"[^\"]*\"\s+)?" + DECL_WORDS +
                                  r"([\w:<>\s\*&]+?)\s+" + CONV_WORD + r"(?:\w+::)*" + re.escape(callee) + r"\s*\(",
                                  blank_comments(new)))
        def ctype(c):
            return " ".join(re.sub(r"^(?:public|private|protected)\s*:\s*", "", c.group(2).strip()).split())
        types = {ctype(c) for c in cdecls if c.group(2).strip() not in ("return", "else", "new", "delete")}
        types.discard("")
        if types == {"void"}:
            new2 = new
            for c in sorted(cdecls, key=lambda c: -c.start(2)):
                if ctype(c) == "void":
                    new2 = new2[:c.start(2)] + re.sub(r"\bvoid\b", "int", new2[c.start(2):c.end(2)]) + new2[c.end(2):]
            new = new2
        elif len(types) == 1 and not re.search(r"\b(float|double|void)\b", next(iter(types))):
            ret_type = next(iter(types))
        elif not types and callee in ("_isnan",):
            ret_type = "int"
        elif not types and len(re.findall(r"\bvoid\s*\(\s*(?:__cdecl\s*|__stdcall\s*)?\*\s*%s\s*\)" % re.escape(callee),
                                          blank_comments(new))) == 1:
            # a call through a function-pointer member (`void (__cdecl* write)(Writer*, const char*, int)`): the
            # pointer's type returns int
            fp = re.search(r"\bvoid(\s*\(\s*(?:__cdecl\s*|__stdcall\s*)?\*\s*%s\s*\))" % re.escape(callee), blank_comments(new))
            new = new[:fp.start()] + "int" + new[fp.start() + 4:]
        elif not types:
            names.append("SKIP %s: no declaration of %s in the source" % (name, callee))
            continue
        else:
            names.append("SKIP %s: %s declared as %s" % (name, callee, sorted(types)))
            continue
        # (offsets: the callee declarations come before the definition in these sources, so recompute)
        blank2 = blank_comments(new)
        m2 = re.search(r"\bvoid(\s+" + CONV_WORD + r"(?:\w+::)*" + re.escape(name) + r"\s*\()", blank2)
        dm = [x for x in re.finditer(r"\bvoid\s+" + CONV_WORD + r"((?:\w+::)*)" + re.escape(name) + r"\s*\(", blank2)]
        defm = None
        for x in dm:
            i, depth = x.end(), 1
            while i < len(blank2) and depth:
                depth += {"(": 1, ")": -1}.get(blank2[i], 0)
                i += 1
            if re.match(r"\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?\{", blank2[i:]):
                defm = x
        if defm is None or m2 is None:
            names.append("SKIP %s: definition moved" % name)
            continue
        # the statement position in the new text: the last `stmt;` before the definition's closing brace
        b1 = blank2.index("{", defm.end())
        depth, j = 0, b1
        while j < len(blank2):
            depth += {"{": 1, "}": -1}.get(blank2[j], 0)
            if depth == 0:
                break
            j += 1
        tail_end = blank2.rstrip()[:0]
        body_end = len(blank2[:j].rstrip()) - 1          # the statement's `;`
        stmt_start = body_end - len(stmt)
        if blank2[stmt_start:body_end] != stmt:
            names.append("SKIP %s: statement moved" % name)
            continue
        lead = len(stmt) - len(stmt.lstrip())
        new = new[:stmt_start + lead] + "return " + new[stmt_start + lead:]
        new = new[:defm.start()] + ret_type + new[defm.start() + 4:]
        # its other declarations: the member's in its class body, or a free function's forward declarations
        qual = defm.group(1).rstrip(":").split("::")[-1] if defm.group(1) else None
        decl_rx = re.compile(r"\bvoid(\s+" + CONV_WORD + re.escape(name) + r"\s*\([^;{]*\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?;)")
        if qual:
            bl = blank_comments(new)
            cm2 = re.search(r"\b(?:struct|class)\s+%s\b[^;{]*\{" % re.escape(qual), bl)
            if cm2:
                depth, e = 0, cm2.end() - 1
                while e < len(bl):
                    depth += {"{": 1, "}": -1}.get(bl[e], 0)
                    if depth == 0:
                        break
                    e += 1
                body_txt = new[cm2.end():e]
                body_txt = decl_rx.sub(lambda mm: ret_type + mm.group(1), body_txt)
                new = new[:cm2.end()] + body_txt + new[e:]
        else:
            head, rest_ = new[:defm.start()], new[defm.start():]
            new = decl_rx.sub(lambda mm: ret_type + mm.group(1), head) + rest_
        text = new
        names.append("%s returns %s (%s)" % (name, ret_type, callee))
    return text, names


# ---------------------------------------------------------------------------------------------
# split-temp: the audio type constructors' five-argument temporary (arguments left on the stack)
def split_temp(text):
    """`Base(Temp(name, 0, key, n, m))` with `Temp(const char*, int, K, int, int)` and `Base(const Temp&)` (or
    `Base(Temp*)` with `&Temp(...)`): the original pushes all five, calls 0x0023fc40, which pops only (name, 0)
    (`ret 8`: a string init returning this), and the base constructor 0x002605e0 (`ret 0x10`) takes the string and
    the three words left on the stack. MSVC compiles the five-argument spelling to the same bytes; natively the
    callee pops 8 where the caller expects 20 (native_conv_check check 7). Rewritten as what the machine code does:
    `Base(Temp().Init(name, 0), key, n, m)` with `Temp* Init(const char*, int)` and `Base(Temp*, K, int, int)`."""
    m = re.search(r"(\n\s*)(\w+)\(const char\*, int, ([^,()]+), int, int\) throw\(\);", text)
    if not m:
        return text, []
    T, K = m.group(2), m.group(3).strip()
    b = re.search(r"(\w+)\((?:const %s&|%s\*)\) throw\(\);" % (re.escape(T), re.escape(T)), text)
    c = re.search(r"\b(\w+)\(&?%s\(" % re.escape(T), text)
    if not b or not c or c.group(1) != b.group(1):
        return text, []
    B = b.group(1)
    i, depth = c.end(), 1
    while i < len(text) and depth:
        depth += {"(": 1, ")": -1}.get(text[i], 0)
        i += 1
    inner = text[c.end():i - 1]
    parts, d, s0 = [], 0, 0
    for j, ch in enumerate(inner):
        if ch == "(":
            d += 1
        elif ch == ")":
            d -= 1
        elif ch == "," and d == 0:
            parts.append(inner[s0:j].strip())
            s0 = j + 1
    parts.append(inner[s0:].strip())
    if len(parts) != 5 or i >= len(text) or text[i] != ")":
        return text, []
    call = "%s(%s().Init(%s, %s), %s, %s, %s)" % (B, T, parts[0], parts[1], parts[2], parts[3], parts[4])
    out = text[:c.start()] + call + text[i + 1:]
    out = out.replace(b.group(0), "%s(%s*, %s, int, int) throw();" % (B, T, K), 1)
    out = out.replace(m.group(0), m.group(1) + "%s* Init(const char*, int) throw();" % T, 1)
    return out, ["%s(%s(5 arguments)) -> %s(%s().Init(2), 3 more)" % (B, T, B, T)]


# ---------------------------------------------------------------------------------------------
# code-literal: a function passed by its XBE address as an integer literal
CODE_LITERAL = re.compile(r"\b0x([0-9a-fA-F]{5,8})\b")
# literals that are function addresses by coincidence (read at each site, native9): P3D chunk ids (0x11000 the
# first code address, 0x13000, 0x120100), flag words (0x200000: UTF-8 lengths, png transformations), pad sizes
CODE_LITERAL_NOT = {0x11000, 0x13000, 0x120100, 0x200000, 0x1ed60, 0x1e820}
_FUNCS = {}


def _function_starts():
    if not _FUNCS:
        import csv
        for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))):
            _FUNCS[int(r["address"], 16)] = r["name"]
    return _FUNCS


def code_literal(text):
    """A function named by its XBE address as an integer literal: `CreateFiber(d, (void*)0x26dc20, p)` (the fiber
    procedure), `atexit((void (*)())0x364490)` (an initializer's `$E` cleanup), `p->value = 0x11bd30;` (a functor's
    function), `FUN_00013420(p, 8, n, (void*)0xb0ff0)` (the element constructor of an array helper). MSVC emits the
    same `push imm32` / `mov [m], imm32` for the literal as for the name (a relocation the byte match masks;
    equiv.py binds it by address), natively the image passes 0x0026dc20, which is no code of the image. Each
    literal that is a function start in build/functions.csv (outside comments and strings, CODE_LITERAL_NOT
    excepted: read at every site) becomes `((int)(void (__cdecl*)())&FUN_<addr>)` (the cast picks this declaration
    among the TU's overloads of the name), declared `extern "C" void __cdecl FUN_<addr>();`
    unless the source already declares the name (bound by address)."""
    funcs = _function_starts()
    blank = blank_comments(text)
    # (the first native9 form, `((int)&FUN_x)`, is ambiguous where the tree's TU declares other overloads of the
    # name: the cast to the declared type picks the extern "C" one)
    first = re.compile(r"\(\(int\)&(FUN_[0-9a-f]{8})\)")
    olds = [m.group(1) for m in first.finditer(blank) if 'extern "C" void __cdecl %s();' % m.group(1) in text]
    if olds:
        text = first.sub(lambda m: "((int)(void (__cdecl*)())&%s)" % m.group(1) if m.group(1) in olds else m.group(0),
                         text)
        blank = blank_comments(text)
    hits = []
    for m in CODE_LITERAL.finditer(blank):
        v = int(m.group(1), 16)
        if v in funcs and v >= 0x11000 and v not in CODE_LITERAL_NOT:
            if re.match(r"\s*\]", blank[m.end():]) or re.search(r"\[\s*$", blank[:m.start()]):
                continue            # an array size or index
            hits.append((m.start(), m.end(), v))
    if not hits:
        return text, ["%s: the cast picks the extern \"C\" declaration" % n for n in sorted(set(olds))]
    out = text
    for a, b, v in reversed(hits):
        out = out[:a] + "((int)(void (__cdecl*)())&FUN_%08x)" % v + out[b:]
    names = sorted({"FUN_%08x" % v for _a, _b, v in hits})
    decls = "".join('extern "C" void __cdecl %s();\n' % n for n in names if not re.search(r"\b%s\b" % n, blank))
    if decls:
        # after the leading comment block and #include lines (the STATUS header stays first)
        k = 0
        for line in out.splitlines(True):
            if line.startswith(("//", "#")) or not line.strip():
                k += len(line)
                continue
            break
        out = out[:k] + decls + out[k:]
    return out, ["%s by name, not by address" % n for n in names]


# ---------------------------------------------------------------------------------------------
# data-literal (native9): a data item named by its XBE address as an integer literal
DATA_LITERAL_KINDS = {"bss", "string", "vtable", "struct", "float", "scalar", "double", "pointer", "wstring",
                      "array", "char[]", "data"}
_ITEMS = {}


def _data_items():
    if "range" not in _ITEMS:
        from xbe import Xbe
        x = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        sec = {s_.name: s_ for s_ in x.sections}
        _ITEMS["range"] = (sec[".rdata"].va, sec[".data"].va + sec[".data"].vsize)
        its = sorted((int(i["addr"], 16), max(i["size"], 1), i["kind"]) for i in
                     json.load(open(os.path.join(ROOT, "config/data.json")))["items"])
        _ITEMS["items"] = its
        _ITEMS["starts"] = [i[0] for i in its]
    return _ITEMS


def data_literal(text):
    """`((Helper_360170*)0x4e6a68)->Run();` (the initializer constructing the audio type registry), `(const
    char*)0x400488`, `vptr = (void*)0x3f9a90`: a game data item named by its XBE address. MSVC emits the same
    immediate as for the item's name (a relocation the byte match masks); natively the literal is the XBE window's
    copy of the item (src/platform/sdl/xdk/startup.cpp maps the XBE there), not the image's (data.s, vtables.s), so
    the initializer constructed one object and the getters returned the other. Each such literal in .rdata/.data
    (an item of config/data.json of a data kind; FourCC constants in `case` labels and comparisons excepted) becomes
    `((int)(hulk_at_<item> + off))`, declared `extern "C" char hulk_at_<item>[];` (native_link.py binds `hulk_at_`
    names by address, like `DAT_`)."""
    import bisect
    d = _data_items()
    lo, hi = d["range"]
    blank = blank_comments(text)
    hits = []
    for m in CODE_LITERAL.finditer(blank):
        v = int(m.group(1), 16)
        if not lo <= v < hi or 0x500000 <= v < 0x500100:
            continue            # (0x5000xx: pddi extension ids, `GetExtension(0x500002)`)
        before = blank[max(0, m.start() - 12):m.start()]
        if re.search(r"(\bcase\s*|[=!<>]=\s*|[<>]\s*)$", before) or re.match(r"\s*(?:==|!=|:)", blank[m.end():]):
            continue
        if re.search(r"\[\s*$", blank[:m.start()]) or re.match(r"\s*\]", blank[m.end():]):
            continue
        tag = all(chr((v >> sh) & 0xFF) in "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_ " for sh in (0, 8, 16))
        if tag and not re.search(r"\*\s*\)\s*$", before):
            continue            # (a P3D chunk / attribute FourCC: 0x544f52 'ROT', 0x54494c 'LIT')
        k = bisect.bisect_right(d["starts"], v) - 1
        if k < 0:
            continue
        a, n, kind = d["items"][k]
        if not a <= v < a + n or kind not in DATA_LITERAL_KINDS:
            continue
        hits.append((m.start(), m.end(), a, v - a))
    if not hits:
        return text, []
    out = text
    for s_, e_, a, off in reversed(hits):
        out = out[:s_] + ("((int)(hulk_at_%08x + 0x%x))" % (a, off) if off else "((int)hulk_at_%08x)" % a) + out[e_:]
    names = sorted({"hulk_at_%08x" % a for _s, _e, a, _o in hits})
    decls = "".join('extern "C" char %s[];\n' % n for n in names if not re.search(r"\b%s\b" % n, blank))
    k = 0
    for line in out.splitlines(True):
        if line.startswith(("//", "#")) or not line.strip():
            k += len(line)
            continue
        break
    out = out[:k] + decls + out[k:]
    return out, ["%s by name, not by address" % n for n in names]


# ---------------------------------------------------------------------------------------------
# fourcc (native11): a FourCC constant spelled as a data address
_FOURCC_CH = set(b"ABCDEFGHIJKLMNOPQRSTUVWXYZ")
_FOURCC = {}


def _is_fourcc(v):
    """Three capital letters and a zero byte, and not the start of a data item config/data.json types (an RTTI
    descriptor 0x494b44 'DKI', a struct 0x434250 'PBC' are addresses; a `table` item starting at an odd address was
    cut at the constant)."""
    import bisect
    b = v.to_bytes(4, "little")
    if b[3] != 0 or not all(c in _FOURCC_CH for c in b[:3]):
        return False
    d = _data_items()
    k = bisect.bisect_right(d["starts"], v) - 1
    if k >= 0 and d["items"][k][2] == "vtable" and v - d["items"][k][0] == 4:
        return False            # (a vptr: the vftable after its complete-object-locator word, 0x414150 'PAA')
    return not (k >= 0 and d["items"][k][0] == v and d["items"][k][2] != "table")


def _orig_immediates(addr):
    """The immediates of the original function at `addr` outside memory operands (push/mov/cmp imm32)."""
    import capstone
    from xbe import Xbe
    if "xbe" not in _FOURCC:
        _FOURCC["xbe"] = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        _FOURCC["sizes"] = {}
        import csv
        for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))):
            _FOURCC["sizes"][int(r["address"], 16)] = int(r["size"])
    x, n = _FOURCC["xbe"], _FOURCC["sizes"].get(addr)
    if not n:
        return set(), []
    o = x.offset(addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    ins = list(md.disasm(x.data[o:o + n], addr))
    out = set()
    for i in ins:
        for m in re.finditer(r"0x([0-9a-f]{5,8})\b", re.sub(r"\[[^\]]*\]", "", i.op_str)):
            out.add(int(m.group(1), 16))
    return out, ins


FOURCC_EXPR = [
    # ((char*)((char*)&DAT_x + N)) / ((char*)&DAT_x + N): data-literal's form of an address inside an item
    (re.compile(r"\(\(char\*\)\(\(char\*\)&(?:DAT|hulk_at)_00([0-9a-f]{6}) \+ (\d+)\)\)"), "((char*)0x%x)"),
    (re.compile(r"\(\(char\*\)&(?:DAT|hulk_at)_00([0-9a-f]{6}) \+ (\d+)\)"), "((char*)0x%x)"),
    # ((int)DAT_x) of a `char DAT_x[]`
    (re.compile(r"\(\(int\)(?:DAT|hulk_at)_00([0-9a-f]{6})\)"), "((int)0x%x)"),
    # (unsigned)&DAT_x / &DAT_x of an `int DAT_x`
    (re.compile(r"\(unsigned\)&DAT_00([0-9a-f]{6})\b"), "((unsigned)0x%x)"),
    (re.compile(r"&DAT_00([0-9a-f]{6})\b(?!\s*\+)"), "((int*)0x%x)"),
    # a `char DAT_x[]` used as a pointer value (`labelPointer = DAT_x;`)
    (re.compile(r"(?<=[=(,]) ?DAT_00([0-9a-f]{6})(?=\s*[;,)])"), " ((char*)0x%x)"),
]


def fourcc(rel, text):
    """`Find(((int)((char*)((char*)&DAT_0052cbb0 + 97692))), 0x31544c46)`: a P3D attribute or channel FourCC ('LIT'
    0x54494c) that falls in the XBE's data range, written as an address inside a data item (or `((int)DAT_00544457)`,
    or a getter propagated from another function's `return &DAT_004dd780;` that the link rebinds to the original's
    immediate, the channel type ids 'ROT' 'INT' 'STR' 'ENT' 'CLR'). MSVC emits the same immediate (the byte match and
    equiv.py bind it by address); natively the name is an address of the image's data, so the lookup never found its
    channel (the front end's particle emitters got no rotation channel: a null reader in 0x002d53d0). Every such
    expression whose value is a FourCC (three capital letters, top byte 0, not a data item's start) that the original function has as an
    immediate becomes the literal; a getter `return &DAT_x;` whose original is `mov eax, <FourCC>; ret` returns
    the FourCC."""
    try:
        addr = int(os.path.basename(rel)[2:10], 16)
    except ValueError:
        return text, []
    imms, ins = _orig_immediates(addr)
    tags = {v for v in imms if _is_fourcc(v)}
    if not tags:
        return text, []
    blank = blank_comments(text)
    out, why = text, []
    if (len(ins) == 2 and ins[0].mnemonic == "mov" and ins[0].op_str.startswith("eax, ") and ins[1].mnemonic == "ret"):
        v = int(ins[0].op_str.split(", ")[1], 16)
        m = re.search(r"return &DAT_00([0-9a-f]{6});", blank)
        if v in tags and m and int(m.group(1), 16) != v:
            out = out[:m.start()] + "return (int*)0x%x;" % v + out[m.end():]
            return out, ["fourcc: the getter returns %r (0x%x), not &DAT_00%s" % (v.to_bytes(4, "little")[:3].decode(), v, m.group(1))]
    for rx, fmt in FOURCC_EXPR:
        blank = blank_comments(out)
        hits = []
        for m in rx.finditer(blank):
            line_start = blank.rfind("\n", 0, m.start()) + 1
            if re.match(r"\s*extern\b", blank[line_start:m.start()]):
                continue
            v = int(m.group(1), 16) + (int(m.group(2)) if m.lastindex and m.lastindex >= 2 else 0)
            if v in tags:
                hits.append((m.start(), m.end(), v))
        for s_, e_, v in reversed(hits):
            out = out[:s_] + fmt % v + out[e_:]
            why.append("fourcc: %r 0x%x is a constant, not a data address" % (v.to_bytes(4, "little")[:3].decode(), v))
    return out, sorted(set(why))


# ---------------------------------------------------------------------------------------------
# addr-const (native10): a constant or a function spelled as the address of a data name in the code range
ADDR_CONST_DECL = re.compile(r'(?:^|(?<=[;}]))[ \t]*extern(?:[ \t]+"[^"\n]*")?[ \t]+(?:unsigned[ \t]+|signed[ \t]+)?char[ \t]+(DAT_00([0-9a-f]{6}))[ \t]*;[ \t]*\n?',
                             re.M)


def addr_const(text):
    """`id == &DAT_00121401` (a P3D chunk id compared with the reader's id), `SetRenderState_Simple(&DAT_0004037c,
    v)` (a push-buffer method), `FUN_00011520(p, 12, n, &DAT_00011090)` (the element constructor): an address in
    the XBE's code range named as a `char` data item. MSVC emits the same immediate as for a literal (a relocation
    the byte match masks); natively the name is a stub of the image's data, so the comparison never held (the
    animation loader read no channel groups: the native stop in the particle loader, 0x002d5640). A scalar
    `extern char DAT_<addr>;` in .text whose every use is `&DAT_<addr>` becomes the literal `((char*)0x<addr>)`,
    or `((char*)(void (__cdecl*)())&FUN_<addr>)` when the address is a function start (code-literal's form)."""
    if "text" not in _ITEMS:
        from xbe import Xbe
        t_ = next(s_ for s_ in Xbe(os.path.join(ROOT, "isos/extracted/default.xbe")).sections if s_.name == ".text")
        _ITEMS["text"] = (t_.va, t_.va + t_.vsize)
    lo, hi = _ITEMS["text"]
    funcs = _function_starts()
    blank = blank_comments(text)
    out, why = text, []
    for m in ADDR_CONST_DECL.finditer(blank):
        name, a = m.group(1), int(m.group(2), 16)
        if not lo <= a < hi:
            continue            # (the library sections' data, XPP's device types: the shim knows those addresses)
        uses = [u.start() for u in re.finditer(r"\b%s\b" % name, blank)]
        amp = [u.start() for u in re.finditer(r"&\s*%s\b" % name, blank)]
        if len(uses) != len(amp) + 1:
            continue            # used other than by its address: not this rule's
        if a in funcs:
            lit = "((char*)(void (__cdecl*)())&FUN_%08x)" % a
            decl = 'extern "C" void __cdecl FUN_%08x();' % a if not re.search(r"\bFUN_%08x\b" % a, blank) else ""
        else:
            lit, decl = "((char*)0x%08x)" % a, ""
        decl_text = text[m.start():m.end()]
        out = re.sub(r"&\s*%s\b" % name, lambda _m: lit, out)
        if decl_text.strip() and decl_text in out:
            out = out.replace(decl_text, decl + ("\n" if decl and decl_text.endswith("\n") else ""), 1)
        why.append("%s: %s" % (name, "the function by name" if a in funcs else "the constant 0x%x" % a))
    return out, why


# stub-body (native9): an adjustor-thunk source defining an empty body for the virtual its thunk jumps to
_THUNK_ADDRS = {}


def _is_adjustor_thunk(addr):
    if addr not in _THUNK_ADDRS:
        from xbe import Xbe
        if "x" not in _THUNK_ADDRS:
            _THUNK_ADDRS["x"] = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        x = _THUNK_ADDRS["x"]
        o = x.offset(addr)
        b = bytes(x.data[o:o + 16]) if o is not None else b""
        n = 3 if b[:1] == b"\x83" else 6 if b[:1] == b"\x81" else 0
        _THUNK_ADDRS[addr] = bool(n) and b[1:2] in (b"\xe9", b"\xc1") and b[n:n + 1] == b"\xe9"
    return _THUNK_ADDRS[addr]


def stub_body(rel, text):
    """matches/0x002777c0.cpp: `void CementLibrary::vfunc_0() {}` next to the adjustor thunk the source exists for
    (`sub ecx, 4; jmp 0x00277790`): the byte match masks the thunk's jump, and natively it jumped to the source's
    empty stand-in instead of the game's 0x00277790 (the CementLibrary's AddRef was lost). The empty out-of-line
    definitions of virtual members (not constructors or destructors) are removed, leaving the declaration: MSVC
    still emits the thunk (the vftable is emitted where the class is constructed), and the jump is an unresolved
    reference the link binds to the game's function. Only for sources whose original is an adjustor thunk."""
    m = re.search(r"0x([0-9a-f]{8})\.cpp$", rel)
    if not m or not _is_adjustor_thunk(int(m.group(1), 16)):
        return text, []
    blank = blank_comments(text)
    virt = set(re.findall(r"\bvirtual\b[^;(]*?\b(\w+)\s*\(", blank))
    out, why = text, []
    for d in reversed(list(re.finditer(r"(?m)^[ \t]*(?:void|int|bool|unsigned\s+int)\s+(?:\w+::)*(\w+)::(\w+)\s*\(\s*\)\s*\{\s*\}[ \t]*\n",
                                       blank))):
        cls, name = d.group(1), d.group(2)
        if name in (cls, "~" + cls) or name not in virt:
            continue
        out = out[:d.start()] + out[d.end():]
        why.append("%s::%s: the stand-in body removed (the thunk's jump goes to the game's)" % (cls, name))
    return out, why


# unique-class (native9): one class name, several sources of a TU, several vftables
def unique_class(rel, text):
    """`class Caster { virtual void _m_vf0(); };` in each of the fight factories' cast helpers (0x0023d420,
    0x0023d710, ...): every source stores another game vftable in its local `Caster`, the tree build merges the
    identical declarations into one class of the TU, and natively its one constructor stored one (stub) vftable for
    all of them (bindings.json lists `??_7Caster@fn_...@@6B@` as ambiguous). The class gets the source's address
    as a suffix, so each source keeps its own class and vftable (names don't reach the bytes: compare.py MATCH).
    Sources and names from HULK_UNIQUE_CLASS (JSON {rel: [class]}: the ambiguous `??_7` symbols of a TU namespace
    whose class two or more of its sources declare)."""
    p = os.environ.get("HULK_UNIQUE_CLASS")
    names = (json.load(open(p)) if p and os.path.exists(p) else {}).get(rel)
    m = re.search(r"0x00([0-9a-f]{6})\.cpp$", rel)
    if not names or not m:
        return text, []
    out, why = text, []
    for cls in names:
        new = "%s_%s" % (cls, m.group(1))
        if re.search(r"\b%s\b" % re.escape(new), out):
            continue
        out = re.sub(r"(?<![\w:])%s\b" % re.escape(cls), new, out)
        # native12: the class's own constructor / destructor names (`Derived_06c740::Derived(`)
        out = re.sub(r"\b%s::(~?)%s\b" % (re.escape(new), re.escape(cls)), lambda m_: "%s::%s%s" % (new, m_.group(1), new), out)
        why.append("%s -> %s" % (cls, new))
    return out, why


# ctor-virt: a constructor or destructor calling a virtual member of its own class
def _brace_end(t, i):
    d = 0
    for j in range(i, len(t)):
        if t[j] == "{":
            d += 1
        elif t[j] == "}":
            d -= 1
            if d == 0:
                return j
    return len(t)


def ctor_virt(text):
    """`LoadStream::LoadStream(int a, int b) { field04 = 0; FUN_00263f50(); ... }` with `virtual void FUN_00263f50();`
    (the class's only virtual function, declared so that the constructor stores the vftable): inside a constructor or
    destructor MSVC 7.1 knows the dynamic type and calls the member directly (`call 0x263f50`, the byte match), clang
    -O0 calls through the vftable the constructor has just stored, which natively is the game's (native_link points
    the stub vftable there): slot 0 of 0x0042ae9c is 0x00038290, not the member. The member becomes non-virtual and a
    stand-in virtual `hulk_slot_<name>` takes its place in the declaration (the class keeps its vftable and every other
    slot its index): MSVC still calls directly, and so does clang. Calls unqualified or through `this->`, members of
    the class or of a base declared in the same source; overloaded names are left alone."""
    blank = blank_comments(text)
    classes = {}
    for m in re.finditer(r"\b(?:class|struct)\s+(\w+)\s*(?::\s*([^{;]*))?\{", blank):
        e = _brace_end(blank, m.end() - 1)
        b = re.sub(r"\{[^{}]*\}", lambda x: " " * len(x.group(0)), blank[m.end():e])
        decls = [(d.start() + m.end(), d.group(1)) for d in re.finditer(r"\bvirtual\b[^;(]*?\b(\w+)\s*\(", b)]
        bases = re.findall(r"(\w+)\s*(?:,|$)", (m.group(2) or "").strip())
        classes.setdefault(m.group(1), []).append((decls, bases, b))

    def owner(cls, name, seen=()):
        for decls, bases, b in classes.get(cls, []):
            ds = [d for d in decls if d[1] == name]
            if ds:
                n_all = len(re.findall(r"\b%s\s*\(" % re.escape(name), b))
                return (ds[0][0], cls) if len(ds) == 1 and n_all == 1 and len(classes[cls]) == 1 else None
            for base in bases:
                if base not in seen:
                    r = owner(base, name, seen + (cls,))
                    if r:
                        return r
        return None
    edits, why = {}, []
    for m in re.finditer(r"(~?)(\w+)\s*::\s*(~?)(\w+)\s*\(([^)]*)\)\s*(?::[^{;]*)?\{", blank):
        cls, name = m.group(2), m.group(4)
        if name != cls or cls not in classes:
            continue
        e = _brace_end(blank, m.end() - 1)
        body = blank[m.end():e]
        for c in re.finditer(r"(?<![\w.>:~])(?:this\s*->\s*)?(\w+)\s*\(", body):
            r = owner(cls, c.group(1))
            if r and c.group(1) != cls:
                edits[r[0]] = (c.group(1), r[1])
    if not edits:
        return text, []
    out = text
    for pos in sorted(edits, reverse=True):
        name, cls = edits[pos]
        # `virtual <ret> NAME(<params>)<cv> [= 0];` -> `virtual <ret> hulk_slot_NAME(<params>)<cv> [= 0]; <ret> NAME(<params>)<cv>;`
        semi = blank.index(";", pos)
        decl = out[pos:semi]
        dm = re.match(r"virtual\s+(.*?)\b%s(\s*\(.*)$" % re.escape(name), decl, re.S)
        if not dm:
            continue
        rest = re.sub(r"\s*=\s*0\s*$", "", dm.group(2))
        out = out[:pos] + "virtual %shulk_slot_%s%s; %s%s%s" % (dm.group(1), name, dm.group(2), dm.group(1), name, rest) + out[semi:]
        why.append("%s::%s called directly (a stand-in virtual keeps its slot)" % (cls, name))
    return out, why


# ---------------------------------------------------------------------------------------------
# pass-through: a wrapper that tail-jumps to a callee-popping function, passing its own stack arguments on
_PT = {}


def _xbe_tools():
    if "x" not in _PT:
        import capstone
        from xbe import Xbe
        import native_conv_check
        _PT["x"] = Xbe(native_conv_check.XBE)
        _PT["md"] = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        _PT["ncc"] = native_conv_check
    return _PT["x"], _PT["md"], _PT["ncc"]


def pass_through(rel, addr, text):
    """`int A::run() { return p->f(); }` whose original is `mov ecx, [ecx+0xb8]; jmp f` with f popping 12 bytes
    (`ret 0xc`): the wrapper's callers push three arguments and the jump hands them on. MSVC compiles the
    argument-less spelling to the same bytes; natively f reads three words that aren't there and pops them anyway
    (native_conv_check check 7). The wrapper and the callee's declaration get N/4 `int` parameters, passed on in
    order. Only for a wrapper without parameters whose body is that one call."""
    x, md, ncc = _xbe_tools()
    o = x.offset(addr)
    if o is None:
        return text, []
    ins = []
    for i in md.disasm(x.data[o:o + 64], addr):
        ins.append(i)
        if i.mnemonic in ("jmp", "ret", "int3"):
            break
    if not ins or ins[-1].mnemonic != "jmp" or not ins[-1].op_str.startswith("0x") or \
            any(i.mnemonic in ("push", "call", "sub") or ("esp" in i.op_str) for i in ins[:-1]):
        return text, []
    rets, _t = ncc.xbe_rets(x, md, int(ins[-1].op_str, 16))
    if not rets or len(rets) != 1 or max(rets) == 0 or max(rets) % 4:
        return text, []
    n = max(rets) // 4
    blank = blank_comments(text)
    defs = list(re.finditer(r"(?m)^([\w:<>\*& ]+?\s(?:\w+::)*(\w+))\s*\(\s*(?:void)?\s*\)\s*(const\s*)?\{", blank))
    if len(defs) != 1:
        return text, []
    d = defs[0]
    i, depth = d.end() - 1, 0
    for j in range(i, len(blank)):
        depth += {"{": 1, "}": -1}.get(blank[j], 0)
        if depth == 0:
            break
    body = blank[i + 1:j].strip()
    m = re.fullmatch(r"(return\s+)?(.*?)(\w+)\s*\(\s*\)\s*;", body, re.S)
    if not m:
        return text, []
    callee = m.group(3)
    names = ["a%d" % k for k in range(n)]
    out = text
    # the callee's declarations without parameters: `T callee();` -> `T callee(int, ...)`
    decl_rx = re.compile(r"(\b%s\s*\()\s*(?:void)?\s*(\)\s*(?:const\s*)?;)" % re.escape(callee))
    if not decl_rx.search(blank[:d.start()]):
        return text, []
    head = decl_rx.sub(lambda mm: mm.group(1) + ", ".join(["int"] * n) + mm.group(2), out[:d.start()])
    # the wrapper's own declaration in its class (same name, no parameters)
    head = re.sub(r"(\b%s\s*\()\s*(?:void)?\s*(\)\s*(?:const\s*)?;)" % re.escape(d.group(2)),
                  lambda mm: mm.group(1) + ", ".join(["int"] * n) + mm.group(2), head)
    rest = out[d.start():]
    rest = re.sub(r"(\b%s\s*\()\s*(?:void)?\s*(\))" % re.escape(d.group(2)),
                  lambda mm: mm.group(1) + ", ".join("int " + a for a in names) + mm.group(2), rest, count=1)
    rest = re.sub(r"(\b%s\s*\()\s*(\)\s*;)" % re.escape(callee), lambda mm: mm.group(1) + ", ".join(names) + mm.group(2),
                  rest, count=1)
    return head + rest, ["%s passes its %d stack argument(s) on to %s" % (d.group(2), n, callee)]


# ---------------------------------------------------------------------------------------------
# this-call: a free-function declaration of a thiscall definition, called while ecx holds `this`
_TC = {}


def this_call_findings():
    """{source file: {plain name}} from native_conv_check check 8 (cdecl/stdcall callers of a thiscall
    definition), mapped to the sources of the caller symbol's TU (HULK_TREE_MANIFEST, default build/tree)."""
    if "f" not in _TC:
        import native_conv_check
        man = json.load(open(os.environ.get("HULK_TREE_MANIFEST") or os.path.join(ROOT, "build/tree/manifest.json")))
        by_ns = {}
        for t in man["tus"]:
            srcs = [b["src"] for b in t["blocks"] if b.get("src")]
            if t.get("tu_ns"):
                by_ns.setdefault(t["tu_ns"], []).extend(srcs)
            for b in t["blocks"]:
                if b.get("ns") and b.get("src"):
                    by_ns.setdefault(b["ns"], []).append(b["src"])
        _p, bad = native_conv_check.check_definition_convs(
            os.environ.get("HULK_BINDINGS") or os.path.join(ROOT, "build/native/bindings.json"))
        out = {}
        for b in bad:
            sym = b["symbol"]
            name = _plain_name(sym)
            m = re.search(r"@(fn_[0-9a-f]{8})@@", sym)
            for src in by_ns.get(m.group(1), []) if m else []:
                out.setdefault(src, set()).add(name)
        _TC["f"] = out
    return _TC["f"]


def this_call(rel, text):
    """`void __stdcall FUN_00274e60(void* p);` called as `FUN_00274e60(p);` inside a member function whose original
    calls the thiscall definition with ecx still holding `this` (matches/0x00275110): MSVC compiles the free call to
    the original's bytes, natively nothing sets ecx (native_conv_check check 8). The declaration becomes a member
    of a struct of its own and the call `((X_this*)this)->FUN_00274e60(p)`; the byte match decides whether ecx
    really was `this` (otherwise MSVC adds the `mov ecx` and the rewrite is refused)."""
    names = this_call_findings().get(rel)
    if not names or not rel.startswith("matches/"):
        return text, []
    done = []
    for name in sorted(n for n in names if n):
        blank = blank_comments(text)
        decls = list(re.finditer(r"(?m)^(?:extern\s+(?:\"C\"\s+)?)?([\w:\*& ]+?)\s+(?:__stdcall\s+|__cdecl\s+)?%s\s*\(([^()]*)\)\s*(?:throw\s*\(\s*\))?\s*;[ \t]*\n" % re.escape(name), blank))
        if len(decls) != 1 or in_class(blank, decls[0].start()):
            continue
        d = decls[0]
        calls = [m for m in re.finditer(r"(?<![\w:>.])%s\s*\(" % re.escape(name), blank) if m.start() > d.end()]
        if not calls:
            continue
        struct = "This_%s" % name
        new = text
        for m in sorted(calls, key=lambda m: -m.start()):
            new = new[:m.start()] + "((%s*)this)->%s(" % (struct, name) + new[m.end():]
        ret = d.group(1).strip()
        new = new[:d.start()] + "struct %s {\n    %s %s(%s);\n};\n" % (struct, ret, name, d.group(2)) + new[d.end():]
        text = new
        done.append("%s called as a member through this" % name)
    return text, done


# this-note: a free declaration with an `ecx stack...` note of a thiscall definition (check 9)
_TN = {}


def this_note_findings():
    """{caller file: {address}} of check 9's thiscall-definition findings whose note is `ecx` + stack words."""
    if "f" not in _TN:
        import native_conv_check
        _n, bad = native_conv_check.check_note_conventions(tree_report=TREE_REPORT)
        out = {}
        for b in bad:
            locs = b["conv"].split()
            if b["definition_conv"] == "thiscall" and locs and locs[0] == "ecx" and all(l == "stack" for l in locs[1:]):
                out.setdefault(b["file"], set()).add(int(b["addr"], 16))
        _TN["f"] = out
    return _TN["f"]


def this_note(rel, text):
    addrs = this_note_findings().get(rel)
    if not addrs:
        return text, []
    done = []
    for a in sorted(addrs):
        name = "FUN_%08x" % a
        blank = blank_comments(text)
        dm = list(re.finditer(r"(?m)^[ \t]*//[ \t]*equiv-conv:[ \t]*%s[ \t]+ecx(?:[ \t]+stack)*[ \t]*\n"
                              r"[ \t]*(?:extern\s+(?:\"C\"\s+)?)?([\w:\*& ]+?)\s*(?:__stdcall\s+|__cdecl\s+)?%s\s*\(([^()]*)\)\s*;[ \t]*\n"
                              % (name, name), text))
        if len(dm) != 1 or in_class(blank, dm[0].start()):
            continue
        d = dm[0]
        params = [text[s0:e0].strip() for s0, e0 in split_args(text, d.start(2), d.end(2), angle=True)]
        if not params or "..." in params:
            continue        # (a varargs member is __cdecl under MSVC: those stay for a hand-written fix)
        struct = "ThisNote_%08x" % a
        calls = [m for m in re.finditer(r"(?<![\w:>.])%s\s*\(" % name, blank) if m.start() > d.end()]
        if not calls:
            continue
        new, ok = text, True
        for m in sorted(calls, key=lambda m: -m.start()):
            depth, j = 1, m.end()
            while j < len(blank) and depth:
                depth += {"(": 1, ")": -1}.get(blank[j], 0)
                j += 1
            args = split_args(blank, m.end(), j - 1, angle=False)
            if not args:
                ok = False
                break
            a0 = new[args[0][0]:args[0][1]].strip()
            rest = new[args[1][0]:j - 1].strip() if len(args) > 1 else ""
            new = new[:m.start()] + "((%s*)(%s))->%s(%s)" % (struct, a0, name, rest) + new[j:]
        if not ok:
            continue
        ret = d.group(1).strip()
        new = new[:d.start()] + "struct %s {\n    %s %s(%s);\n};\n" % (struct, ret, name, ", ".join(params[1:])) + new[d.end():]
        text = new
        done.append("%s (thiscall) called as a member of its first argument" % name)
    return text, done


def return_param_candidates(rel, text):
    """[(new text, why)] candidates for the return-param rule (see the module doc)."""
    syms = void_return_findings().get(rel)
    if not syms:
        return []
    out = []
    for sym in sorted(syms):
        name = _plain_name(sym)
        if not name:
            continue
        blank = blank_comments(text)
        defs = []
        for m in re.finditer(r"\bvoid\s+" + CONV_WORD + r"((?:\w+::)*)" + re.escape(name) + r"\s*\(", blank):
            i, depth = m.end(), 1
            while i < len(blank) and depth:
                depth += {"(": 1, ")": -1}.get(blank[i], 0)
                i += 1
            rest = re.match(r"\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?\{", blank[i:])
            if rest:
                defs.append((m, m.end(), i - 1, i + rest.end() - 1))
        if len(defs) != 1:
            continue
        m, p0, p1, b0 = defs[0]
        depth, j = 0, b0
        while j < len(blank):
            depth += {"{": 1, "}": -1}.get(blank[j], 0)
            if depth == 0:
                break
            j += 1
        params = [text[a:b].strip() for a, b in split_args(text, p0, p1, angle=True)]
        exprs = []
        for prm in params:
            pm = re.match(r"(.*?[\*&])\s*(\w+)$", prm.replace("volatile ", ""))
            if pm and "(" not in prm:
                exprs.append((pm.group(1).strip(), pm.group(2)))
        body = blank[b0 + 1:j]
        lm = None
        for lm in re.finditer(r"([^;{}]*?)(?<![=!<>+\-*/&|^])=(?!=)[^;{}]*;", body):
            pass
        if lm:
            lv = " ".join(text[b0 + 1 + lm.start(1):b0 + 1 + lm.end(1)].split())
            lv = re.sub(r"^(?:(?:unsigned|signed|const|volatile|struct|class)\s+)*[\w:]+\s*\**\s*(?=\w+$)", "", lv) \
                if re.match(r"^[\w:]+(?:\s+[\w:]+)*\s*\**\s*\w+$", lv) and not re.match(r"^\w+$", lv) else lv
            if lv and not re.search(r"[;{}]|\breturn\b", lv):
                exprs.append(("int", "(int)(%s)" % lv))
        for rtype, expr in exprs:
            new = text[:b0 + 1] + re.sub(r"\breturn\s*;", "return %s;" % expr, text[b0 + 1:j]) + \
                "    return %s;\n" % expr + text[j:]
            new = new[:m.start()] + rtype + new[m.start() + 4:]
            # a member's declaration in its class body / a free function's forward declarations
            decl_rx = re.compile(r"\bvoid(\s+" + CONV_WORD + re.escape(name) + r"\s*\([^;{]*\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?;)")
            head = new[:m.start()]
            new = decl_rx.sub(lambda mm: rtype + mm.group(1), head) + new[m.start():]
            out.append((new, "%s returns %s" % (name, expr)))
    return out


_RC = {}


def ret_findings():
    """{definition file: {symbol: 'int' | 'float'}} of check 6's void definitions: 'int' when an original caller
    reads eax after the call, 'float' when one consumes st0 (and none reads eax)."""
    if "f" not in _RC:
        import native_conv_check
        _n, bad, _h = native_conv_check.check_returns(tree_report=TREE_REPORT)
        # native10: check 11, void overrides of virtual slots their family returns a value from
        _n, bad11 = native_conv_check.check_virtual_returns(tree_report=TREE_REPORT)
        bad = bad + bad11
        out = {}
        for b in bad:
            if b["declared"] != "void":
                continue
            k = "float" if b["why"].endswith("uses st0 after the call") else "int"
            d = out.setdefault(b["file"], {})
            d[b["symbol"]] = "int" if k == "int" or d.get(b["symbol"]) == "int" else "float"
        _RC["f"] = out
    return _RC["f"]


SCALAR_T = re.compile(r"^(?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+|class\s+)*[\w:]+(?:\s+(?:int|long|char|short))?\s*\**$")


def ret_cand_candidates(rel, text):
    """[(new text, why)] for the ret-cand rule: a void definition whose original callers use its eax (or st0) result
    (check 6) after the void-return / return-param rules: candidates in turn, each verified (compare.py MATCH /
    equiv.py EQUIVALENT; a byte match proves the returned expression is the original's eax there, equiv.py compares
    the result):
      - the body's last call returned (with the callee's declaration in this source given that return type when it
        was void), also when a `_ReadWriteBarrier();` follows it (`T r = call; _ReadWriteBarrier(); return r;`);
        `float` for an st0 result (the callee returns on the x87 stack: atan2-style helpers, wrap-angle);
      - `return <parameter>;`, `return this;`, `return <local>;` for each pointer/int parameter and local,
        and the last assigned lvalue.
    Bare `return;` statements return the same expression."""
    finds = ret_findings().get(rel)
    if not finds:
        return []
    out = []
    for sym, kind in sorted(finds.items()):
        name = _plain_name(sym)
        if not name:
            continue
        blank = blank_comments(text)
        defs = []
        for m in re.finditer(r"\bvoid\s+" + CONV_WORD + r"((?:\w+::)*)" + re.escape(name) + r"\s*\(", blank):
            i, depth = m.end(), 1
            while i < len(blank) and depth:
                depth += {"(": 1, ")": -1}.get(blank[i], 0)
                i += 1
            rest = re.match(r"\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?\{", blank[i:])
            if rest:
                defs.append((m, m.end(), i - 1, i + rest.end() - 1))
        if len(defs) != 1:
            continue
        m, p0, p1, b0 = defs[0]
        depth, j = 0, b0
        while j < len(blank):
            depth += {"{": 1, "}": -1}.get(blank[j], 0)
            if depth == 0:
                break
            j += 1
        qual = m.group(1).rstrip(":").split("::")[-1] if m.group(1) else None
        member = bool(qual) or in_class(blank, m.start())
        cls = qual
        if not cls and member:
            # an inline member: the innermost class head before the definition
            for hm in re.finditer(r"\b(?:class|struct)\s+(\w+)\b[^;{()]*\{", blank[:m.start()]):
                d_, e_ = 0, hm.end() - 1
                while e_ < len(blank):
                    d_ += {"{": 1, "}": -1}.get(blank[e_], 0)
                    if d_ == 0:
                        break
                    e_ += 1
                if e_ > m.start():
                    cls = hm.group(1)
        body = blank[b0 + 1:j]
        cands = []                       # (return type, expression, body edit or None)

        def retype_decls(new, rtype):
            """the definition's other declarations (class body / forward declarations) get the return type"""
            decl_rx = re.compile(r"\bvoid(\s+" + CONV_WORD + re.escape(name) + r"\s*\([^;{]*\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?;)")
            bl = blank_comments(new)
            dm = re.search(r"\bvoid\s+" + CONV_WORD + r"(?:\w+::)*" + re.escape(name) + r"\s*\([^;{]*\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?\{", bl)
            if not dm:
                return None
            new = new[:dm.start()] + rtype + new[dm.start() + 4:]
            head = new[:dm.start()]
            return decl_rx.sub(lambda mm: rtype + mm.group(1), head) + new[dm.start():]

        # 1. the last call statement (optionally before a barrier)
        tail = body.rstrip()
        stmts = []
        t = tail
        for _ in range(2):
            if not t.endswith(";"):
                break
            k = max(t.rfind(";", 0, len(t) - 1), t.rfind("{", 0, len(t) - 1), t.rfind("}", 0, len(t) - 1))
            stmts.append((k + 1, len(t) - 1))
            t = t[:k + 1]
        call_stmt, barrier = None, False
        if stmts:
            s0, s1 = stmts[0]
            st = tail[s0:s1].strip()
            if re.fullmatch(r"_ReadWriteBarrier\s*\(\s*\)", st) and len(stmts) > 1:
                barrier = True
                s0, s1 = stmts[1]
                st = tail[s0:s1].strip()
            if st.endswith(")") and not re.match(r"(return|if|while|for|switch|do|else|delete)\b", st) and \
                    not re.search(r"(?<![=!<>])=(?!=)", st):
                call_stmt = (s0, s1, st)
        if call_stmt:
            s0, s1, st = call_stmt
            q, depth = len(st) - 1, 0
            while q >= 0:
                depth += {")": 1, "(": -1}.get(st[q], 0)
                if depth == 0:
                    break
                q -= 1
            cm = re.search(r"(\w+)\s*$", st[:q])
            callee = cm.group(1) if cm else None
            if callee and callee != "_ReadWriteBarrier":
                cdecls = list(re.finditer(r"(?m)(^|[;{}(,]|\b(?:virtual|static|inline)\b|\bextern\b(?!\s+\"))\s*" +
                                          r"(?:extern\s+\"[^\"]*\"\s+)?" + DECL_WORDS + r"([\w:<>\s\*&]+?)\s+" + CONV_WORD +
                                          r"(?:\w+::)*" + re.escape(callee) + r"\s*\(", blank))
                types = {" ".join(re.sub(r"^(?:public|private|protected)\s*:\s*", "", c.group(2).strip()).split())
                         for c in cdecls if c.group(2).strip() not in ("return", "else", "new", "delete")}
                types.discard("")
                want = "float" if kind == "float" else "int"
                rtype = None
                if types == {"void"}:
                    rtype = want
                elif len(types) == 1:
                    t0 = next(iter(types))
                    isf = bool(re.search(r"\b(float|double)\b", t0)) and "*" not in t0
                    if isf == (kind == "float") and "void" != t0:
                        rtype = t0
                if rtype:
                    cands.append((rtype, None, (s0, s1, callee, types == {"void"}, barrier)))
        # 1b. the last call statement followed only by stores (`void* r = Move(...); *cnt = n; return r;`: luaM_growaux
        # returns the realloc'd block, the stores after it don't touch eax)
        inner = None
        for im in re.finditer(r"(?:^|(?<=[;{}]))(\s*)((?:[\w\[\]]+\s*(?:->|\.)\s*)*(\w+)\s*\([^;{}]*\))\s*;", body):
            d_ = sum({"{": 1, "}": -1}.get(ch, 0) for ch in body[:im.start(2)])
            if d_ == 0:
                inner = im
        if inner and inner.group(3) != "_ReadWriteBarrier":
            rest = body[inner.end():]
            if "(" not in rest and not re.search(r"\breturn\b", rest) and rest.strip():
                callee = inner.group(3)
                cdecls = list(re.finditer(r"(?m)(^|[;{}(,]|\b(?:virtual|static|inline)\b|\bextern\b(?!\s+\"))\s*" +
                                          r"(?:extern\s+\"[^\"]*\"\s+)?" + DECL_WORDS + r"([\w:<>\s\*&]+?)\s+" + CONV_WORD +
                                          r"(?:\w+::)*" + re.escape(callee) + r"\s*\(", blank))
                types = {" ".join(re.sub(r"^(?:public|private|protected)\s*:\s*", "", c.group(2).strip()).split())
                         for c in cdecls if c.group(2).strip() not in ("return", "else", "new", "delete")}
                types.discard("")
                rt = None
                if types == {"void"}:
                    rt = "float" if kind == "float" else "void*"
                elif len(types) == 1 and next(iter(types)) != "void":
                    rt = next(iter(types))
                if rt:
                    a0, a1 = b0 + 1 + inner.start(2), b0 + 1 + inner.end(2)
                    new = text[:a0] + "%s r_ret = %s" % (rt, text[a0:a1]) + text[a1:j] + "    return r_ret;\n" + text[j:]
                    if types == {"void"}:
                        bl = blank_comments(new)
                        cds = list(re.finditer(r"(?m)(^|[;{}(,]|\b(?:virtual|static|inline)\b|\bextern\b(?!\s+\"))\s*" +
                                               r"(?:extern\s+\"[^\"]*\"\s+)?" + DECL_WORDS + r"([\w:<>\s\*&]+?)\s+" + CONV_WORD +
                                               r"(?:\w+::)*" + re.escape(callee) + r"\s*\(", bl))
                        for c in sorted(cds, key=lambda c: -c.start(2)):
                            seg = new[c.start(2):c.end(2)]
                            if re.search(r"\bvoid\b", seg):
                                new = new[:c.start(2)] + re.sub(r"\bvoid\b", rt, seg) + new[c.end(2):]
                    new = retype_decls(new, rt)
                    if new:
                        out.append((new, "%s returns %s's %s result (stores after it)" % (name, callee, rt)))
        # 2. parameters, this, locals, the last assigned lvalue
        params = [text[a:b].strip() for a, b in split_args(text, p0, p1, angle=True)]
        for prm in params:
            pm = re.match(r"(.*?[\w\*&])\s*\b(\w+)$", prm.replace("volatile ", ""))
            if not pm or "(" in prm or "[" in prm:
                continue
            ty = pm.group(1).strip()
            isf = re.search(r"\b(float|double)\b", ty) and "*" not in ty
            if bool(isf) != (kind == "float") or "&" in ty or not SCALAR_T.match(ty):
                continue
            cands.append((ty, pm.group(2), None))
        if member and cls and kind == "int":
            cands.append(("%s*" % cls, "this", None))
        for lm in re.finditer(r"(?:^|(?<=[;{}]))\s*((?:const\s+|unsigned\s+|signed\s+|struct\s+|class\s+)*[A-Za-z_][\w:]*(?:\s+(?:int|long|char|short))?(?:\s*\*+\s*|\s+))([A-Za-z_]\w*)\s*(?:=[^;]*)?;", body):
            ty, nm = " ".join(lm.group(1).split()), lm.group(2)
            if re.sub(r"\W.*", "", ty) in ("return", "delete", "goto", "else", "case", "break", "continue", "do") or nm in ("return",):
                continue
            isf = re.search(r"\b(float|double)\b", ty) and "*" not in ty
            if bool(isf) != (kind == "float") or ty == "void" or not SCALAR_T.match(ty):
                continue
            cands.append((ty, nm, "local"))
        seen = set()
        for rtype, expr, how in cands:
            key = (rtype, expr, how if not isinstance(how, tuple) else "call")
            if key in seen:
                continue
            seen.add(key)
            if isinstance(how, tuple):
                s0, s1, callee, retype_callee, barrier = how
                a0, a1 = b0 + 1 + s0, b0 + 1 + s1
                st_txt = text[a0:a1]
                lead = st_txt[:len(st_txt) - len(st_txt.lstrip())]
                call_txt = st_txt.strip()
                variants = []
                if barrier:
                    variants.append(lead + "%s r_ret = %s;\n    _ReadWriteBarrier();\n    return r_ret" % (rtype, call_txt))
                    # drop the barrier too (the tail call then is the original's call; ret)
                    variants.append(lead + "return " + call_txt)
                else:
                    variants.append(lead + "return " + call_txt)
                for vi, v in enumerate(variants):
                    if barrier:
                        # replace the call statement and the barrier statement after it
                        bm = re.search(r"_ReadWriteBarrier\s*\(\s*\)\s*;", text[a1:b0 + 1 + len(tail) + 1])
                        if not bm:
                            continue
                        end = a1 + bm.end()
                        new = text[:a0] + v + ";" + text[end:]
                    else:
                        new = text[:a0] + v + text[a1:]
                    if retype_callee:
                        bl = blank_comments(new)
                        cds = list(re.finditer(r"(?m)(^|[;{}(,]|\b(?:virtual|static|inline)\b|\bextern\b(?!\s+\"))\s*" +
                                               r"(?:extern\s+\"[^\"]*\"\s+)?" + DECL_WORDS + r"([\w:<>\s\*&]+?)\s+" + CONV_WORD +
                                               r"(?:\w+::)*" + re.escape(callee) + r"\s*\(", bl))
                        for c in sorted(cds, key=lambda c: -c.start(2)):
                            seg = new[c.start(2):c.end(2)]
                            if re.search(r"\bvoid\b", seg):
                                new = new[:c.start(2)] + re.sub(r"\bvoid\b", rtype, seg) + new[c.end(2):]
                    new = retype_decls(new, rtype)
                    if new:
                        out.append((new, "%s returns %s's %s result%s" % (name, callee, rtype,
                                                                          " (barrier kept)" if barrier and vi == 0 else " (barrier dropped)" if barrier else "")))
                continue
            new = text[:b0 + 1] + re.sub(r"\breturn\s*;", "return %s;" % expr, text[b0 + 1:j]) + \
                "    return %s;\n" % expr + text[j:]
            new = retype_decls(new, rtype)
            if new:
                out.append((new, "%s returns %s (%s)" % (name, expr, rtype)))
    return out


_AS = {}


def arg_shift_pairs():
    """{source: {(plain name, address, declared pops, callee pops)}} of check 7's symbols declared popping more
    than the callee's single `ret N` (callee-pops conventions), mapped to their TU's sources."""
    if "p" not in _AS:
        import native_conv_check
        _n, bad = native_conv_check.check_pops(os.environ.get("HULK_BINDINGS") or os.path.join(ROOT, "build/native/bindings.json"))
        out = {}
        native_conv_check._def_reads(0)          # loads equiv.Program
        prog = native_conv_check._PROG.get("p")
        for b in bad:
            if len(b["callee"]) != 1 or b["declared"] <= b["callee"][0]:
                continue
            # the callee must read no more stack words than it pops (a cdecl-style member reading its arguments
            # without popping them is another shape)
            try:
                nread = prog.callee_stack_args(int(b["addr"], 16)) if prog else None
            except Exception:  # noqa: BLE001
                nread = None
            if nread is None or nread * 4 > b["callee"][0]:
                continue
            name = _plain_name(b["symbol"])
            for src in _symbol_sources(b["symbol"]):
                out.setdefault(src, set()).add((name, int(b["addr"], 16), b["declared"], b["callee"][0]))
        _AS["p"] = out
    return _AS["p"]


def _close_paren(blank, i):
    """index of the `)` matching the `(` at blank[i - 1]"""
    depth = 1
    while i < len(blank) and depth:
        depth += {"(": 1, ")": -1}.get(blank[i], 0)
        i += 1
    return i - 1


def _is_decl_prefix(blank, pos):
    """Is the name at pos declared (a type or calling convention before it), not called?"""
    k = max(blank.rfind(";", 0, pos), blank.rfind("{", 0, pos), blank.rfind("}", 0, pos))
    pre = blank[k + 1:pos].strip()
    pre = re.sub(r"^(?:public|private|protected)\s*:", "", pre).strip()
    if not pre or re.search(r"[=(,!?:]$|\breturn$|\belse$", pre) or "=" in pre or "(" in pre:
        return False
    return bool(re.search(r"[\w*&]$", pre))


def arg_shift_candidates(rel, text):
    """[(new text, why)] for the arg-shift rule: a call `X(a1, ..., an)` declared popping more words than X's callee
    pops (check 7: `Get(int)` over a getter that reads only ecx, `Make(1, 0.5f, 0, 0)` over the singleton getter
    0x001c3d90 that takes nothing), chained into the next call `->M(b...)` that the original's leftover words feed:
    MSVC 7.1 pushes M's arguments before it evaluates the object expression, so `X(a1..ak)->M(b..., ak+1..an)` is
    the original's push order. X's declaration keeps its first k parameters, M's gets the moved ones appended. Only
    when every call of X in the source is chained the same way; verified (compare.py / equiv.py)."""
    pairs = arg_shift_pairs().get(rel)
    if not pairs:
        return []
    out = []
    for name, a, decl_b, ret_b in sorted(pairs):
        if not name or decl_b % 4 or ret_b % 4:
            continue
        keep = ret_b // 4
        blank = blank_comments(text)
        dm = [x for x in re.finditer(r"(?<![\w:.>])%s\s*\(([^()]*)\)\s*(?:const\s*)?;" % re.escape(name), blank)
              if _is_decl_prefix(blank, x.start())]
        if len(dm) != 1:
            continue
        d = dm[0]
        pspans = split_args(text, d.start(1), d.end(1), angle=True)
        params = [text[s0:e0].strip() for s0, e0 in pspans]
        if any("..." in p or re.search(r"\b(double|__int64)\b", p) and "*" not in p for p in params) or \
                len(params) * 4 != decl_b or keep >= len(params):
            continue
        calls = [m for m in re.finditer(r"(?<![\w:])%s\s*\(" % re.escape(name), blank) if m.start() != d.start()]
        if not calls:
            continue
        plan, ok, mname = [], True, None
        for m in calls:
            e = _close_paren(blank, m.end())
            cm = re.match(r"\s*->\s*(\w+)\s*\(", blank[e + 1:])
            base, var = e + 1, None
            if not cm:
                # `T* v = X(...); v->M(...);` (the next statement calls through the result)
                vm = re.search(r"(\w+)\s*=\s*(?:\(\s*[\w:]+\s*\*\s*\)\s*)?((?:[\w\[\]]+\s*(?:->|\.)\s*)*)$", blank[:m.start()])
                if vm:
                    cm = re.match(r"\s*;\s*%s\s*->\s*(\w+)\s*\(" % re.escape(vm.group(1)), blank[e + 1:])
                    if cm:
                        st0 = max(blank.rfind(";", 0, m.start()), blank.rfind("{", 0, m.start()), blank.rfind("}", 0, m.start())) + 1
                        var = (vm.group(1), st0, vm.start(2))
            if not cm:
                ok = False
                break
            mname = cm.group(1)
            ms = base + cm.end()
            me = _close_paren(blank, ms)
            args = split_args(blank, m.end(), e)
            if len(args) != len(params):
                ok = False
                break
            plan.append((m.end(), e, args, ms, me, var, mname))
        if not ok or not plan:
            continue
        mdecls = {}
        for mn in sorted({p_[6] for p_ in plan}):
            mdm = [x for x in re.finditer(r"(?<![\w:.>])%s\s*\(([^()]*)\)\s*(?:const\s*)?;" % re.escape(mn), blank)
                   if _is_decl_prefix(blank, x.start())]
            if len(mdm) != 1 or "..." in text[mdm[0].start(1):mdm[0].end(1)]:
                ok = False
                break
            mdecls[mn] = mdm[0]
        if not ok:
            continue
        mname = "/".join(sorted(mdecls))
        moved = params[keep:]
        for chain in (False, True):
            if chain and not all(p_[5] and len(re.findall(r"\b%s\b" % re.escape(p_[5][0]), blank)) == 2 for p_ in plan):
                continue        # (`v = X(); v->M();` written as `X()->M();` when v has no other use)
            new = text
            # edits from the end backwards (the declarations come before the calls)
            edits = []
            for c0, c1, args, ms, me, var, mn in plan:
                kept = ", ".join(text[s0:e0].strip() for s0, e0 in args[:keep])
                mv = [text[s0:e0].strip() for s0, e0 in args[keep:]]
                margs = ", ".join(([text[ms:me].strip()] if text[ms:me].strip() else []) + mv)
                if chain:
                    lead = text[var[1]:]
                    lead = var[1] + len(lead) - len(lead.lstrip())
                    edits.append((lead, me, "%s%s(%s)->%s(%s" % (text[var[2]:text.rfind(name, 0, c0)], name, kept, mn, margs)))
                else:
                    edits.append((ms, me, margs))
                    edits.append((c0, c1, kept))
            for mn, md_ in mdecls.items():
                mparams = text[md_.start(1):md_.end(1)].strip()
                mp = mparams if mparams not in ("", "void") else ""
                edits.append((md_.start(1), md_.end(1), ", ".join(([mp] if mp else []) + moved)))
            edits.append((d.start(1), d.end(1), ", ".join(params[:keep])))
            for s0, e0, rep in sorted(edits, key=lambda t: -t[0]):
                new = new[:s0] + rep + new[e0:]
            out.append((new, "%s pops %d of its %d words: the rest are %s's (%s)" % (
                name, keep, len(params), mname, "chained" if chain else "next call")))
    return out


def arg_unshift_pairs():
    """{source: {(plain name, address, declared pops, callee pops)}} of check 7's symbols declared popping fewer
    words than the callee's single `ret N`: the missing words are the previous call's (arg-unshift)."""
    if "u" not in _AS:
        import native_conv_check
        _n, bad = native_conv_check.check_pops(os.environ.get("HULK_BINDINGS") or os.path.join(ROOT, "build/native/bindings.json"))
        out = {}
        for b in bad:
            if len(b["callee"]) != 1 or b["declared"] >= b["callee"][0] or (b["callee"][0] - b["declared"]) % 4:
                continue
            name = _plain_name(b["symbol"])
            for src in _symbol_sources(b["symbol"]):
                out.setdefault(src, set()).add((name, int(b["addr"], 16), b["declared"], b["callee"][0]))
        _AS["u"] = out
    return _AS["u"]


def arg_unshift_candidates(rel, text):
    """[(new text, why)] for the arg-unshift rule (native10): the reverse of arg-shift. A call `X(a1..an)->M(b...)`
    where M is declared popping fewer words than its callee's `ret N` (check 7: `v44(t)->FUN_000f8970()`, the font
    setter 0x000f8970 takes the font's name; v44, the dolly script node's getter, takes nothing and leaves `t` on
    the stack): X pops its first n-k arguments and M finds the last k on top, then its own. The call becomes
    `X(a1..a(n-k))->M(a(n-k+1)..an, b...)` (MSVC 7.1 pushes M's arguments before it evaluates the object
    expression: the same push order), X's declaration loses its last k parameters, M's gains them in front. Only
    when every call of M in the source is chained that way to calls of one X, and M's declaration there has the
    words check 7 saw. Verified (compare.py / equiv.py), but the verification can't tell which of two consecutive
    calls an argument word belongs to (both see the same stack): the split comes from the callee's `ret N` alone.
    Run once per check 7 report (a second pass over the same report would move another word)."""
    pairs = arg_unshift_pairs().get(rel)
    if not pairs:
        return []
    out = []
    for name, a, decl_b, ret_b in sorted(pairs):
        if not name:
            continue
        k = (ret_b - decl_b) // 4
        blank = blank_comments(text)
        dm = [x for x in re.finditer(r"(?<![\w:.>])%s\s*\(([^()]*)\)\s*(?:const\s*)?;" % re.escape(name), blank)
              if _is_decl_prefix(blank, x.start())]
        if len(dm) != 1:
            continue
        md = dm[0]
        mparams = text[md.start(1):md.end(1)].strip()
        mparams = "" if mparams in ("", "void") else mparams
        if len(split_args(text, md.start(1), md.end(1)) if mparams else []) * 4 != decl_b:
            continue        # (another source of the TU declares M; this one's declaration already has the words)
        calls = [m for m in re.finditer(r"(?<![\w:])%s\s*\(" % re.escape(name), blank) if m.start() != md.start()]
        if not calls:
            continue
        plan, xname, ok = [], None, True
        for m in calls:
            pm = re.search(r"(\w+)\s*\(([^()]*)\)\s*->\s*$", blank[:m.start()])
            if not pm or (xname and pm.group(1) != xname):
                ok = False
                break
            xname = pm.group(1)
            xargs = split_args(text, pm.start(2), pm.end(2)) if text[pm.start(2):pm.end(2)].strip() else []
            if len(xargs) < k:
                ok = False
                break
            me = _close_paren(blank, m.end())
            plan.append((pm.start(2), pm.end(2), xargs, m.end(), me))
        if not ok or not plan:
            continue
        xd = [x for x in re.finditer(r"(?<![\w:.>])%s\s*\(([^()]*)\)\s*(?:const\s*)?(?:=\s*0\s*)?;" % re.escape(xname), blank)
              if _is_decl_prefix(blank, x.start())]
        if len(xd) != 1:
            continue
        xd = xd[0]
        xps = split_args(text, xd.start(1), xd.end(1)) if text[xd.start(1):xd.end(1)].strip() not in ("", "void") else []
        if len(xps) < k:
            continue
        xparams = [text[s0:e0].strip() for s0, e0 in xps]
        moved = xparams[len(xparams) - k:]
        edits = []
        for x0, x1, xargs, m0, m1 in plan:
            kept = ", ".join(text[s0:e0].strip() for s0, e0 in xargs[:len(xargs) - k])
            mv = [text[s0:e0].strip() for s0, e0 in xargs[len(xargs) - k:]]
            margs = text[m0:m1].strip()
            edits.append((m0, m1, ", ".join(mv + ([margs] if margs else []))))
            edits.append((x0, x1, kept))
        edits.append((md.start(1), md.end(1), ", ".join(moved + ([mparams] if mparams else []))))
        edits.append((xd.start(1), xd.end(1), ", ".join(xparams[:len(xparams) - k])))
        new = text
        for s0, e0, rep in sorted(edits, key=lambda t: -t[0]):
            new = new[:s0] + rep + new[e0:]
        out.append((new, "%s takes %d more word(s) than declared: %s's last %d argument(s), which %s leaves on the "
                         "stack" % (name, k, xname, k, xname)))
    return out


_BC = {}


def _symbol_sources(sym):
    """The sources a caller symbol can come from: its TU / block namespace's sources (`fn_...`), or, for a C-linkage
    symbol (`_FUN_000e7260@4`, no namespace), every source that declares its name `extern "C"`."""
    m = re.search(r"@(fn_[0-9a-f]{8})@@", sym)
    if m:
        return _ns_sources().get(m.group(1), [])
    if sym.startswith("?"):
        return []
    name = _plain_name(sym)
    if not name:
        return []
    if "cnames" not in _BC:
        idx = {}
        for d in ("matches", "equivalent"):
            for fn in os.listdir(os.path.join(ROOT, d)):
                if not fn.endswith(".cpp"):
                    continue
                t = open(os.path.join(ROOT, d, fn), encoding="latin1").read()
                if 'extern "C"' not in t:
                    continue
                for nm in set(re.findall(r'extern\s+"C"[^;{(]*?\b(\w+)\s*\(', t)):
                    idx.setdefault(nm, []).append("%s/%s" % (d, fn))
        _BC["cnames"] = idx
    return _BC["cnames"].get(name, [])


def _ns_sources():
    """{TU or block namespace (`fn_...`): [sources]} of the tree build (HULK_TREE_MANIFEST, default build/tree)."""
    if "ns" not in _BC:
        man = json.load(open(os.environ.get("HULK_TREE_MANIFEST") or os.path.join(ROOT, "build/tree/manifest.json")))
        by_ns = {}
        for t in man["tus"]:
            srcs = [b["src"] for b in t["blocks"] if b.get("src")]
            if t.get("tu_ns"):
                by_ns.setdefault(t["tu_ns"], []).extend(srcs)
            for b in t["blocks"]:
                if b.get("ns") and b.get("src"):
                    by_ns.setdefault(b["ns"], []).append(b["src"])
        _BC["ns"] = by_ns
    return _BC["ns"]


def base_ctor_addrs():
    """{source: {(plain name, definition address)}} of check 8's behaviour-changing cdecl/stdcall callers of a
    thiscall constructor (the caller symbol's TU namespace gives its sources; FUN_<addr> names everywhere)."""
    if "a" not in _BC:
        import native_conv_check
        _c, _p, bad = native_conv_check.classify_definition_convs(
            os.environ.get("HULK_BINDINGS") or os.path.join(ROOT, "build/native/bindings.json"))
        out = {}
        for b in bad:
            if not b["definition"].startswith("??0") or \
                    native_conv_check.symbol_conv(b["symbol"]) not in ("cdecl", "stdcall"):
                continue
            a = int(b["addr"], 16)
            name = _plain_name(b["symbol"])
            for src in _symbol_sources(b["symbol"]):
                out.setdefault(src, set()).add((name, a))
            out.setdefault("*", set()).add(("FUN_%08x" % a, a))
        _BC["a"] = out
    return _BC["a"]


def base_ctor_candidates(rel, text):
    out = []
    pairs = base_ctor_addrs()
    for name, a in sorted(pairs.get(rel, set()) | pairs.get("*", set())):
        if not name or name not in text:
            continue
        blank = blank_comments(text)
        dm = list(re.finditer(r"(?m)^[ \t]*(?:extern\s+(?:\"[^\"]*\"\s+)?)?void\s+(?:__stdcall\s+|__cdecl\s+)?%s\s*\(([^()]*)\)\s*;[ \t]*\n" % name, blank))
        if len(dm) != 1 or in_class(blank, dm[0].start()):
            continue
        d = dm[0]
        params = text[d.start(1):d.end(1)]
        base = "Ctor_%08x" % a
        # the constructor whose first statement is the call: inline `C(...) { FUN(...); ...}` or `C::C(...) {`
        cm = list(re.finditer(r"\b((?:(\w+)::)?(\w+))\s*\(([^()]*)\)\s*\{\s*%s\s*\(([^;]*)\)\s*;" % name, blank))
        if len(cm) != 1:
            continue
        c = cm[0]
        cls = c.group(3)
        if c.group(2) and c.group(2) != cls:
            continue
        args = text[c.start(5):c.end(5)]
        # the class head
        hm = list(re.finditer(r"\b(class|struct)\s+%s\b\s*(:[^{;]*)?\{" % re.escape(cls), blank))
        if len(hm) != 1:
            continue
        h = hm[0]
        for poly in (False, True):
            # (the polymorphic variant has a name of its own: two sources merged into one TU must not define one
            # struct two ways)
            base = "%s_%08x" % ("CtorV" if poly else "Ctor", a)
            body = "struct %s {\n    %s(%s);%s\n};\n" % (base, base, params, "\n    virtual void v_%08x();" % a if poly else "")
            new = text
            # (edits from the end backwards: the call, the class head, the declaration)
            cs, ce = c.start(), c.end()
            ctor_head = text[c.start(1):c.end(4) + 1]
            rest_after_call = text[ce:]
            new = text[:c.start(1)] + ctor_head + " : %s(%s) {" % (base, args) + rest_after_call
            if h.group(2):
                bases = text[h.start(2) + 1:h.end(2)].strip()
                head = "%s %s : public %s, %s {" % (h.group(1), cls, base, bases)
            else:
                head = "%s %s : public %s {" % (h.group(1), cls, base)
            new = new[:h.start()] + head + new[h.end():]
            new = new[:d.start()] + body + new[d.end():]
            out.append((new, "%s called as the base constructor %s of %s%s" % (name, base, cls, " (polymorphic)" if poly else "")))
    return out


def this_cand_pairs():
    """{source: {(plain name, definition address)}} of check 8's behaviour-changing cdecl/stdcall callers of a
    thiscall definition that is no constructor."""
    if "t" not in _BC:
        import native_conv_check
        _c, _p, bad = native_conv_check.classify_definition_convs(
            os.environ.get("HULK_BINDINGS") or os.path.join(ROOT, "build/native/bindings.json"))
        out = {}
        ctors = os.environ.get("HULK_THIS_CAND_CTORS") == "1"
        for b in bad:
            dconv = native_conv_check.symbol_conv(b["definition"])
            if native_conv_check.symbol_conv(b["symbol"]) not in ("cdecl", "stdcall"):
                continue
            if dconv == "thiscall" and (ctors or not b["definition"].startswith("??0")):
                kind = "thiscall"
            elif dconv == "fastcall" and b.get("definition_shape") and list(b["definition_shape"][1:]) == [1, 0] and \
                    b.get("caller") and list(b["caller"][1:]) == [0, 0]:
                kind = "fastcall"          # a one-register fastcall definition called without arguments
            else:
                continue
            a = int(b["addr"], 16)
            name = _plain_name(b["symbol"])
            srcs = _symbol_sources(b["symbol"])
            if b.get("callers") and not any(c.startswith("tu:") for c in b["callers"]):
                # native14: a name the link binds per calling function: only those functions' sources
                own = {"%s/0x%s.cpp" % (d, c[2:].rjust(8, "0")) for c in b["callers"] for d in ("matches", "equivalent")}
                srcs = [x for x in srcs if x in own]
            for src in srcs:
                out.setdefault(src, set()).add((name, a, kind))
        _BC["t"] = out
    return _BC["t"]


def this_cand_candidates(rel, text):
    out = []
    for name, a, kind in sorted(this_cand_pairs().get(rel, set())):
        if not name:
            continue
        blank = blank_comments(text)
        dm = list(re.finditer(r"(?m)^[ \t]*(?:extern\s+(?:\"[^\"]*\"\s+)?)?(?!return\b|else\b)([\w:][\w:\*& ]*?)\s*(?:__stdcall\s+|__cdecl\s+)?%s\s*\(([^()]*)\)\s*;[ \t]*\n" % re.escape(name), blank))
        if len(dm) != 1 or in_class(blank, dm[0].start()):
            continue
        d = dm[0]
        calls = [m for m in re.finditer(r"(?<![\w:>.])%s\s*\(" % re.escape(name), blank) if m.start() > d.end()]
        if not calls:
            continue
        # the enclosing function of the first call: its parameter names, and whether it is a member
        k = calls[0].start()
        fm = None
        for fm_ in re.finditer(r"((?:\w+::)*)(~?\w+)\s*\(([^()]*)\)\s*(?:const\s*)?(?::[^{;]*)?\{", blank[:k]):
            fm = fm_
        if fm is None:
            continue
        pnames = [p.split()[-1].strip("*&") for p in fm.group(3).split(",") if p.strip() and p.strip() != "void"]
        member = bool(fm.group(1)) or in_class(blank, fm.start())
        xs = (["this"] if member else []) + [p for p in pnames if re.fullmatch(r"\w+", p)]
        ret = text[d.start(1):d.end(1)].strip()
        ret = re.sub(r"^(?:extern\s+)", "", ret)
        params = text[d.start(2):d.end(2)]
        struct = "ThisCall_%08x" % a
        # a register-convention note `ecx ...` right before the declaration (the definition is a thiscall member
        # with its own note, `this` in ecx and the rest where the note says): the member of the first argument,
        # the note kept on the member declaration for equiv.py
        nm_ = re.search(r"(?m)^[ \t]*//[ \t]*equiv-conv:[ \t]*%s[ \t]+ecx((?:[ \t]+\w+)*)[ \t]*\n\Z" % re.escape(name), text[:d.start()])
        if kind == "thiscall" and nm_:
            prm = [text[s0:e0].strip() for s0, e0 in split_args(text, d.start(2), d.end(2), angle=True)]
            if prm and "..." not in prm:
                new, ok = text, True
                for m in sorted(calls, key=lambda m: -m.start()):
                    e = _close_paren(blank, m.end())
                    args = split_args(blank, m.end(), e)
                    if not args:
                        ok = False
                        break
                    a0 = new[args[0][0]:args[0][1]].strip()
                    rest = new[args[1][0]:e].strip() if len(args) > 1 else ""
                    new = new[:m.start()] + "((%s*)(%s))->%s(%s)" % ("ThisNote_%08x" % a, a0, name, rest) + new[e + 1:]
                if ok:
                    note = text[nm_.start():nm_.end()].strip()
                    new = new[:nm_.start()] + "struct ThisNote_%08x {\n    %s\n    %s %s(%s);\n};\n" % (
                        a, note, ret, name, ", ".join(prm[1:])) + new[d.end():]
                    out.append((new, "%s (thiscall 0x%08x, note ecx%s) called as a member of its first argument" % (
                        name, a, nm_.group(1))))
            continue
        if re.search(r"(?m)^[ \t]*//[ \t]*equiv-conv:[ \t]*%s\b[^\n]*\n\Z" % re.escape(name), text[:d.start()]):
            continue        # a register note of another shape: read by hand
        if kind == "fastcall":
            # `void FUN(void);` called `FUN();` -> `void __fastcall FUN(void*);` called `FUN((void*)(x));`
            if params.strip() not in ("", "void"):
                continue
            if any(not re.match(r"\s*\)", blank[m.end():m.end() + 8]) for m in calls):
                continue
            for x in xs:
                new = text
                for m in sorted(calls, key=lambda m: -m.start()):
                    new = new[:m.end()] + "(void*)(%s)" % x + new[m.end():]
                new = new[:d.start()] + text[d.start():d.end()].replace(
                    text[d.start(2) - 1:d.end(2) + 1], "(void*)").replace(name, "__fastcall " + name, 1) + new[d.end():]
                new = re.sub(r"__cdecl\s+__fastcall|__stdcall\s+__fastcall", "__fastcall", new)
                out.append((new, "%s (fastcall 0x%08x) passed %s in ecx" % (name, a, x)))
            continue
        for x in xs:
            new = text
            for m in sorted(calls, key=lambda m: -m.start()):
                new = new[:m.start()] + "((%s*)(%s))->%s(" % (struct, x, name) + new[m.end():]
            new = new[:d.start()] + "struct %s {\n    %s %s(%s);\n};\n" % (struct, ret, name, params) + new[d.end():]
            out.append((new, "%s (thiscall 0x%08x) called on %s" % (name, a, x)))
        # this-wrap: the enclosing function is the source's own free function and its original passes its incoming
        # ecx on to the call (`bool __stdcall FUN_001fc9d0(int x) { return FUN_001fc7f0(x); }`, ecx untouched):
        # the wrapper is itself a thiscall member; it becomes one (its own callers are then check 8's next level)
        if kind == "thiscall" and not member and not fm.group(1):
            w = _wrap_member(rel, text, blank, fm, name, a, ret, params, d, calls)
            if w:
                out.append(w)
    return out


def _wrap_member(rel, text, blank, fm, name, a, ret, params, d, calls):
    import native_conv_check
    own = int(re.search(r"0x([0-9a-fA-F]{8})", rel).group(1), 16)
    reads = native_conv_check._def_reads(own)
    if not reads or "ecx" not in reads:
        return None
    wname = fm.group(2)
    # the definition's head: `[extern "C"] RET [conv] wname(params) {` on its own line(s)
    hm = None
    for h in re.finditer(r"(?m)^[ \t]*(extern\s+\"[^\"]*\"\s+)?([\w:<>\*& ]+?)\s*(__stdcall\s+|__cdecl\s+)?%s\s*\(" % re.escape(wname), blank):
        if h.end() - 1 <= fm.start(3) <= h.end():
            hm = h
    if hm is None or in_class(blank, hm.start()):
        return None
    if re.search(r"(?<![\w:>.])%s\s*\(" % re.escape(wname), blank[:hm.start()] + blank[fm.end():]):
        return None          # declared or called elsewhere in the source: by hand
    wret = text[hm.start(2):hm.end(2)].strip()
    wparams = text[fm.start(3):fm.end(3)]
    ws = "ThisWrap_%08x" % own
    new = text
    for m in sorted(calls, key=lambda m: -m.start()):
        new = new[:m.start()] + "this->%s(" % name + new[m.end():]
    head_end = fm.end()          # the `{` of the definition
    new = new[:hm.start()] + "%s %s::%s(%s) {" % (wret, ws, wname, wparams) + new[head_end:]
    new = new[:d.start()] + new[d.end():]
    decl = "struct %s {\n    %s %s(%s);\n    %s %s(%s);\n};\n" % (ws, ret, name, params, wret, wname, wparams)
    new = new[:d.start()] + decl + new[d.start():]
    return new, "%s is a thiscall wrapper (its original passes ecx on to %s): a member of %s" % (wname, name, ws)


def in_class(blank, pos):
    depth = 0
    for ch in blank[:pos]:
        depth += {"{": 1, "}": -1}.get(ch, 0)
    return depth > 0


# ret-widen (native9): a definition declared bool / char / short whose callers declare a 32-bit result
NARROW = r"(?:bool|char|signed\s+char|unsigned\s+char|short|unsigned\s+short)"


def ret_widen_findings():
    """{rel: [plain names]} from HULK_RET_WIDEN (a JSON file of that shape: native_conv_check check 10's findings
    mapped to their sources, plus the virtual ones read off a run)."""
    p = os.environ.get("HULK_RET_WIDEN")
    return json.load(open(p)) if p and os.path.exists(p) else {}


def ret_widen_candidates(rel, text):
    """[(new text, why)] for ret-widen: XboxSaveDrive::vfunc_7 0x00279160 is `bool` (`xor eax, eax; sete al` in the
    original), DriveOpenRequest::vfunc_1 calls it through the vftable as `int a = d->s7(); ... return a;`: clang's
    bool definition sets al only, the caller returns the whole eax and the drive thread saw a garbage status (check
    10). The definition and its declarations in this source get `int`, then `unsigned int`: a byte match (or
    equiv.py) proves MSVC 7.1 sets eax the same way for the wider type, i.e. the original returns the whole
    register."""
    names = ret_widen_findings().get(rel)
    if not names:
        return []
    blank = blank_comments(text)
    spans = []
    for name in names:
        d = [m for m in re.finditer(r"(?<![\w:])(" + NARROW + r")(\s+" + CONV_WORD + r"(?:\w+::)+" + re.escape(name)
                                    + r"\s*\()", blank)]
        d += [m for m in re.finditer(r"(?<![\w:])(" + NARROW + r")(\s+" + CONV_WORD + re.escape(name) + r"\s*\()", blank)]
        if not d:
            return []
        spans += [(m.start(1), m.end(1)) for m in d]
    out = []
    for t in ("int", "unsigned int"):
        new = text
        for a_, b_ in sorted(set(spans), reverse=True):
            new = new[:a_] + t + new[b_:]
        out.append((new, "%s returns %s (callers read eax)" % ("/".join(names), t)))
    return out


RULES = {"template-spec": lambda rel, t: template_spec(t), "dependent-base": lambda rel, t: dependent_base(t),
         "return-struct": lambda rel, t: return_struct(t), "patch": patch, "register-order": register_order,
         "void-return": void_return, "split-temp": lambda rel, t: split_temp(t),
         "code-literal": lambda rel, t: code_literal(t), "addr-const": lambda rel, t: addr_const(t), "fourcc": fourcc, "ctor-virt": lambda rel, t: ctor_virt(t), "data-literal": lambda rel, t: data_literal(t), "stub-body": stub_body, "unique-class": unique_class, "pass-through": None,
         "this-call": this_call, "reg-call": reg_call, "this-note": this_note, "return-param": None, "base-ctor": None, "this-cand": None,
         "ret-cand": None, "arg-shift": None, "ret-widen": None, "arg-unshift": None}


CANDIDATE_RULES = ("return-param", "base-ctor", "this-cand", "ret-cand", "arg-shift", "ret-widen", "arg-unshift")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--verify", action="store_true")
    ap.add_argument("--rule", action="append", choices=sorted(RULES))
    ap.add_argument("--only", nargs="*")
    ap.add_argument("--jobs", type=int, default=3, help="verifications at once (default 3)")
    a = ap.parse_args(argv)
    # (the candidate rules, return-param / base-ctor / this-cand, run alone: --rule NAME)
    rules = a.rule or sorted(r for r in RULES if r not in CANDIDATE_RULES)
    if rules == ["return-param"]:
        return return_param_main(a)
    if rules == ["base-ctor"]:
        return return_param_main(a, base_ctor_candidates, "base-ctor")
    if rules == ["this-cand"]:
        return return_param_main(a, this_cand_candidates, "this-cand")
    if rules == ["ret-cand"]:
        return return_param_main(a, ret_cand_candidates, "ret-cand")
    if rules == ["arg-shift"]:
        return return_param_main(a, arg_shift_candidates, "arg-shift")
    if rules == ["ret-widen"]:
        return return_param_main(a, ret_widen_candidates, "ret-widen")
    if rules == ["arg-unshift"]:
        return return_param_main(a, arg_unshift_candidates, "arg-unshift")
    srcs = load_sources()
    in_matches = {addr for rel, addr, _ in srcs if rel.startswith("matches/")}
    planned = []
    for rel, addr, text in srcs:
        if a.only and rel not in a.only:
            continue
        if rel.startswith("equivalent/") and addr in in_matches:
            continue
        new, why = text, []
        for r in rules:
            new, w = pass_through(rel, addr, new) if r == "pass-through" else RULES[r](rel, new)
            why += ["%s: %s" % (r, x) for x in w]
        if new != text:
            planned.append((rel, addr, text, new, why))
    print("planned: %d sources (%d matches, %d equivalent)" % (
        len(planned), sum(p[0].startswith("matches/") for p in planned), sum(p[0].startswith("equivalent/") for p in planned)))
    if not a.apply:
        for rel, addr, text, new, why in planned:
            print("  %s  %s" % (rel, "; ".join(why)[:200]))
        return 0
    if a.verify:
        import reconcile_stubs
    os.makedirs(os.path.dirname(CHANGED), exist_ok=True)
    verdicts = {}
    if a.verify:
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(a.jobs) as ex:
            import native_calls
            futs = {p[0]: ex.submit(demote_verify, p[0], p[1], p[3]) if p[0] in native_calls.DEMOTE
                    else ex.submit(reconcile_stubs.verify_rewrite, p[0], p[1], p[3]) for p in planned}
            verdicts = {rel: f.result() for rel, f in futs.items()}
            demoted = {rel: v[1] for rel, v in verdicts.items() if isinstance(v, tuple)}
            verdicts = {rel: v[0] if isinstance(v, tuple) else v for rel, v in verdicts.items()}
    written = 0
    if not a.verify:
        import native_calls
        if any(p[0] in native_calls.DEMOTE for p in planned):
            print("a demote (matches/ -> equivalent/) needs --verify")
            return 1
        demoted = {}
    with open(LOG, "a") as log, open(CHANGED, "a") as ch:
        for rel, addr, text, new, why in planned:
            v = None
            if a.verify:
                v = verdicts[rel]
                cur = open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()
                if cur != text:
                    v = "changed meanwhile"
                print("  %-26s %-11s %s" % (rel, v, "; ".join(why)[:150]), flush=True)
                if v not in ("MATCH", "EQUIVALENT"):
                    log.write(json.dumps({"file": rel, "edits": why, "skipped": v}) + "\n")
                    continue
            keep = os.path.join(ORIG, rel)
            if not os.path.exists(keep):
                os.makedirs(os.path.dirname(keep), exist_ok=True)
                with open(keep, "w", encoding="latin1", newline="") as f:
                    f.write(text)
            if rel in demoted:
                eq = "equivalent/" + os.path.basename(rel)
                if os.path.exists(os.path.join(ROOT, eq)):
                    log.write(json.dumps({"file": rel, "edits": why, "skipped": eq + " exists"}) + "\n")
                    continue
                with open(os.path.join(ROOT, eq), "w", encoding="latin1", newline="") as f:
                    f.write(demoted[rel])
                os.remove(os.path.join(ROOT, rel))
                log.write(json.dumps({"file": eq, "demoted_from": rel, "edits": why, "verified": v}) + "\n")
                ch.write(rel + "\n" + eq + "\n")
                written += 1
                continue
            with open(os.path.join(ROOT, rel), "w", encoding="latin1", newline="") as f:
                f.write(new)
            log.write(json.dumps(dict({"file": rel, "edits": why}, **({"verified": v} if v else {}))) + "\n")
            ch.write(rel + "\n")
            written += 1
    print("rewrote %d of %d planned sources (log: %s)" % (written, len(planned), os.path.relpath(LOG, ROOT)))
    return 0


def return_param_main(a, candidates=None, tag="return-param"):
    """--rule return-param (base-ctor): each source's candidates verified in turn; the first that verifies is
    written."""
    candidates = candidates or return_param_candidates
    import reconcile_stubs
    from concurrent.futures import ThreadPoolExecutor
    srcs = load_sources()
    in_matches = {rel_addr for rel, rel_addr, _ in srcs if rel.startswith("matches/")}
    jobs = []
    for rel, addr, text in srcs:
        if a.only and rel not in a.only:
            continue
        if rel.startswith("equivalent/") and addr in in_matches:
            continue
        c = candidates(rel, text)
        if c:
            jobs.append((rel, addr, text, c))
    print("planned: %d sources, %d candidates" % (len(jobs), sum(len(j[3]) for j in jobs)))
    if not (a.apply and a.verify):
        for rel, addr, text, c in jobs:
            print("  %s  %s" % (rel, " | ".join(w for _n, w in c)[:200]))
        return 0

    def first(job):
        rel, addr, text, c = job
        tried = []
        for new, why in c:
            v = reconcile_stubs.verify_rewrite(rel, addr, new)
            tried.append("%s: %s" % (why, v))
            if v in ("MATCH", "EQUIVALENT"):
                return new, why, v, tried
        return None, None, None, tried
    with ThreadPoolExecutor(a.jobs) as ex:
        res = list(ex.map(first, jobs))
    written = 0
    with open(LOG, "a") as log, open(CHANGED, "a") as ch:
        for (rel, addr, text, c), (new, why, v, tried) in zip(jobs, res):
            cur = open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()
            if new is None or cur != text:
                log.write(json.dumps({"file": rel, "edits": [tag + ": " + t for t in tried],
                                      "skipped": "changed meanwhile" if new is not None else "no candidate verified"}) + "\n")
                print("  %-26s %-11s %s" % (rel, "skipped", " | ".join(tried)[:150]), flush=True)
                continue
            keep = os.path.join(ORIG, rel)
            if not os.path.exists(keep):
                os.makedirs(os.path.dirname(keep), exist_ok=True)
                with open(keep, "w", encoding="latin1", newline="") as f:
                    f.write(text)
            with open(os.path.join(ROOT, rel), "w", encoding="latin1", newline="") as f:
                f.write(new)
            log.write(json.dumps({"file": rel, "edits": [tag + ": " + why], "verified": v}) + "\n")
            ch.write(rel + "\n")
            written += 1
            print("  %-26s %-11s %s" % (rel, v, why), flush=True)
    print("rewrote %d of %d planned sources (log: %s)" % (written, len(jobs), os.path.relpath(LOG, ROOT)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
