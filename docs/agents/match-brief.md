# Matching subagent brief

You match decompiled functions for a byte-exact decompilation of an original Xbox game (2005): for each assigned function, write C++ that compiles with MSVC 7.1 (cl 13.10.3077, /O2 /GR /GX, x86-32, x87, frame pointers omitted) to byte-identical machine code.

Work ONLY in REPO. Start every Bash command with `cd REPO && `. Your batch name B and list file `build/farm/agents/B.txt` (8 addresses) are given in your prompt.

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

## Register allocation and operand order

From a study of 113 near-misses (`build/farm/queue-permute-r8.txt`; experiments in `build/farm/agent-work/regalloc/`). Most "register-only" diffs were not allocator quirks. They came from a wrong signature, a callee missing from the declarations, or a hand-written hack. Fix the structure first.

**1. Temp in ecx/edx where you get eax** (`mov ecx,[esi+N]; test ecx,ecx` vs `mov eax,...`):
- A later call whose `ecx` is never loaded is a thiscall on that value. The test result stays in ecx because it becomes `this`. Declare that callee as a member of the tested object (`m38->H(9)`, not `__stdcall H(9)`). Examples: 0x000bc750, 0x00232290.
- Look for eax still holding the return value. If the function returns the result of an earlier call (`return v;`), eax is busy, so the code uses ecx. Ghidra often drops that return. Example: 0x00212d30.
- The vtable is loaded into eax (reused) while you get edx: copy the member pointer into a local first: `Node* q = m18; q->c->v6(..)`. Writing `m18->c->v6()`, or caching `c` in a local, gives edx. Example: 0x001be170.
- Hacks with odd effects (`cur = (Node*)count`, `*(volatile*)`) change register choice. Rewriting the plain natural loop fixed 0x00233160.

**2. Zero held in a register** (`push edi; xor edi,edi; cmp eax,edi`). A zero register appears only when at least one compare against 0/NULL shares the region with the stores. With no `==0` / `!p` test, zero stores after a call stay `mov [m],0`, even 7 of them. With one compare it depends on the number k of later zero stores: k=1 imm, k=2 REG, **k=3 imm**, k>=4 REG. With two compares: k<=3 imm, k=4 REG. To flip it, change how many zero uses fall in that region (move a store into or out of an inline helper, or drop or add a re-test). In 0x0028c240/0x0028c310 (edi zero) the cleanup sits in an inline `Reset()` member. In 0x0028c130 (immediates) it is written out with `if (!p0) {..} else {..}`. Copy matched siblings, e.g. 0x0028beb0, 0x0028c4f0.

**3. Base/index order** (`[eax+ecx+0x10]` vs `[ecx+eax+0x10]`). `p[i]`, `i[p]`, `*(p+i)`, `(int)` arithmetic and casts all give the same encoding. The order follows the order in which the two values were defined, and pure copies don't count (they get propagated away). Fix: put the pointer in a real computed local (`unsigned char* p = a->b;`) and declare it before or after the index. In 0x0008c710, `p` before `int i = 0` gave `[i+p]`.

**4. Strength-reduced pointer** (`mov eax,[x]; lea edi,[eax+8]`, then `add edi,4` per iteration). Cache the struct pointer in a local and index the array (`D* d = data; d->c[i] = 0;`). A hand-written walking pointer gives `mov edi,[x]; add edi,8`. Example: 0x00321280.

**5. strlen/strcpy.** `mov eax,esi; lea edx,[eax+1]; loop; sub eax,edx; inc eax` is the **intrinsic** `strlen(src)+1`. A hand-written `e = s+1` loop gives `lea edx,[esi+1]`. Declare `extern "C" unsigned strlen(const char*); extern "C" char* strcpy(char*, const char*);` and call them. This also fixed an esi/edi this/arg swap in 0x001a4560. Example: 0x000f9ab0.

**6. vptr store order in ctors and dtors.** Over half of the remaining near-misses hand-stored the vptr (`vptr = g_vt` plus barriers or volatiles). Rewrite with real classes (RTTI names come from `build/rtti.json`, see `vt.py` in the work directory) and move stores into member types:
- Ctor zero-inits that the target emits *after* the vptr store go into a member type with an inline ctor: `Vec v; ... : v(0.0f,0.0f,0.0f)`. Plain `a(0),b(0),c(0)` initializers sink the vptr (physics::PhysicsJoint 0x0030ca30 and its three subclasses).
- Dtor body stores go into an inline method of a member struct: `sb.Reset()` with `void Reset(){p=b;}` (0x002579f0, and the hand-vptr `vfunc_2` 0x00257c90).
- Multiple inheritance: a second base with an inline virtual dtor, plus a vector member with `clear()` and an inline dtor, reproduced the two-vptr TextBible dtor (0x002c3a20).
- Base ctor with initializer `: mType(b)`, and the derived body in the target's store order (0x0023b320).
- An immediate store (`m=0.1f`) sinks below a run of register stores. To keep it before them, write the run as a loop (`for (j<8) f[j]=1.0f;`) or as inline `Set()` calls on member structs (0x000ed820).

**Ruled out** (no effect on the cases tested): the `register` keyword, `const`, the signedness or pointer-vs-int type of the temp, `a+b` vs `b+a`, `p[i]`/`i[p]`/`*(p+i)`, `if (a&&b)` vs nested or early-return forms, and statement order inside a run of stores (the scheduler keeps them in order).

**Unsolved:** ebx vs ebp for a local (0x0019b460; only 3 of 16k matches use ebp without ebx), a redundant re-test of a register param kept after a call (0x001b4c40), tail-merge choice of the duplicate return block (0x00299540), and `cmp reg,[param]` vs `cmp [field],reg` operand roles (0x0027d580).
