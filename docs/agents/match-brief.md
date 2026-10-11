# Matching subagent brief

You match decompiled functions for a byte-exact decompilation of an original Xbox game (2005): for each assigned function, write C++ that compiles with MSVC 7.1 (cl 13.10.3077, /O2 /GR /GX, x86-32, x87, frame pointers omitted) to byte-identical machine code.

Work ONLY in /Users/matthewcarlson/git/hulk-main. Start every Bash command with `cd /Users/matthewcarlson/git/hulk-main && `. Your batch name B and list file `build/farm/agents/B.txt` (8 addresses) are given in your prompt.

Read first: `farm/src/prompt.ts` (SYSTEM_PROMPT: MSVC 7.1 rules, how to read the diff, a symptom-to-source table, idioms and a worked example) and `farm/src/hints.ts` (compile-error fixes).

For each address A (skip it if `matches/A.cpp` already exists):
1. **Context:** `cat build/farm/packets/A.txt`. Earlier close attempts by other models may be in `build/farm/work/lane-*/A/`; reuse what they learned.
2. **Write** a complete, self-contained .cpp to `build/farm/agent-work/B/A_N.cpp` (N = attempt):
   - no #include; declare everything you need, minimally;
   - exactly ONE function body (the target); declare, but don't define, the functions it calls;
   - match class layout and offsets; a virtual call `[eax+N]` is slot N/4;
   - forbidden: inline asm, `_emit`, `naked`, `#pragma`;
   - ebp frame (`push ebp / mov ebp,esp ... leave`): make the first line `// cl-flags: /Oy-`. Size-optimized code: `// cl-flags: /Oy- /O1`.
3. **Compare:** `build/venv/bin/python tools/compare.py build/farm/agent-work/B/A_N.cpp A`. It prints MATCH or an aligned diff (`!!` differs, `--` missing in ours, `++` extra in ours). Fix the earliest difference first. If compare picks the wrong function from your object, pass the mangled symbol as a third argument.
4. **Verify references** on MATCH: `build/venv/bin/python tools/verify_relocs.py build/farm/agent-work/B/A_N.cpp --addr A --json` must report status "ok". Otherwise fix the string literals, constants, or which function or global each reference names.
5. **Install** on MATCH + ok: `cp build/farm/agent-work/B/A_N.cpp matches/A.cpp && build/venv/bin/python tools/format_matches.py matches/A.cpp`.
6. **Budget:** at most 8 attempts per function; move on when the score stops improving. Skip immediately if arguments arrive in registers other than ecx (eax/ebx/edi with a plain ret), if it uses the CRT `__SEH_prolog` helper, or if it's an SEH funclet. If only a this/argument register swap remains after ~4 attempts, move on.
7. **Log** one JSON line per function to `build/farm/agents/B.jsonl`: `{"addr": A, "status": "match"|"miss"|"skip", "attempts": n, "best_score": x}`.

Hard rules: no git commands. Modify only `build/farm/agent-work/B/`, `build/farm/agents/B.jsonl`, and `matches/A.cpp` for verified matches. Don't touch `tools/`, `farm/`, `docs/`, or other matches. No long-running processes.

Reply briefly: status and attempt count per address, plus any NEW MSVC 7.1 pitfall that isn't already in prompt.ts (max 2 bullets).

## vptr store order

Symptom: the target starts `mov esi,ecx; mov dword ptr [esi], <vftable>; mov r,[esi+N]; test ...`, but our build sinks the vptr store below the first member load/test (`++ mov dword ptr [esi], 0` a few lines down). Everything else matches. `/O1`, `/Os`, `/Ob1`, `/Ox` do not change it. Fixes, in order of preference:

1. **Real dtor whose tail is member dtors.** If the body is empty or starts with a loop and the later cleanup looks like `if (p) Free(p)` / release-and-null per member (in reverse offset order), write a real `virtual ~Derived() throw()` and move that cleanup into inline dtors of small member types (`template<class T> struct Vec { T* b; T* e; ~Vec() throw() { if (b) Free(b); } };`, `struct Ref { T* p; ~Ref() throw() { if (p) p->Release(); p = 0; } };`). Callees must be `throw()` or MSVC adds an EH frame. The compiler then puts the vptr store first, and the base vptr reset or `jmp ~Base` follows. Examples: matches/0x002d0f10, 0x002b0100, 0x00299fa0, 0x002b1400, 0x002a4ff0. This did not help when the body starts with an `if (member)` (0x00105060, 0x001d3410).
2. **Compiler barrier.** Declare `extern "C" void _ReadWriteBarrier();` (MSVC 7.1 treats it as an intrinsic, so it emits no code) and call it right after the vptr store (`vptr = X_vftable; _ReadWriteBarrier();`). This works for scalar-deleting-dtor bodies (`vfunc_2(unsigned char)`) and plain dtors alike: 0x001d3410, 0x001a8f80, 0x0017b560, 0x00145da0, 0x00283870, 0x0023a360, 0x002bfa70.
3. **Volatile pair.** Make both the store `*(void* volatile*)&vptr = X;` and the first member load `*(T* volatile*)&m` volatile. A volatile store alone, or a volatile load alone, does not work. This changes register allocation less than the barrier did in 0x00105060 (the barrier moved `push edi` above the store).
