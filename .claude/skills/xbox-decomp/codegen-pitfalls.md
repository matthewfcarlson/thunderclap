# MSVC 7.1 / x87 / calling-convention recipes

Recipes for XDK-era code (MSVC 7.1, `cl` 13.10.3077, `/O2 /GR /GX`, x86-32, x87, frame pointer omitted). Each was
confirmed on real functions; addresses in parentheses are illustrations from the Hulk project, not data to reuse.

## Reading the target

- `ret N` pops N bytes of stack arguments. Plain `ret` with stack arguments is `__cdecl`; no `add esp` after a call
  to a stack-argument callee means `__stdcall` or a `__thiscall` member. `ecx` loaded right before a call is `this`.
- Count every callee's real `ret N` (follow jmp thunks). Pushes a callee doesn't pop belong to a *later* call: the
  first call was evaluated inside the next call's argument list (MSVC pushes right to left). Don't fake it with
  varargs on a virtual.
- A function whose `eax` is leftover junk returns `void`. One that starts `mov eax,ecx` and returns it is a ctor.
- `ebp` frame (`push ebp; mov ebp,esp ... leave`): built with `/Oy-`. Size-optimized idioms (`push 2; pop eax`,
  `and dword [m],0`): `/O1 /Oy-` (CRT/XAPI region often).
- `and esp,-8` prologue: a `double`/`__int64` local, an `__declspec(align(8))` struct, or a large array.
- `fs:[0]` setup: an EH frame from a destructor on a local; mark callees `throw()` if the target has none.
- Jump tables and byte tables: read them from the executable, don't guess case numbering (off-by-one is common).
- Ghidra truncates functions at calls it thinks don't return and at split `jcc`s; check sizes before trusting
  "missing code". Its casts are noise: rebuild real structs.

## Matching (byte-identical)

- Fix the earliest diff first; change one thing per attempt.
- Register-only diffs: first suspect structure. A later call whose `ecx` is never loaded is a thiscall on the
  tested value (declare it as a member). `eax` busy because the function returns a value Ghidra dropped. A
  hand-written `strlen`/`strcpy` loop should be the intrinsic (declare `extern "C"` and call it).
- vptr store sinking below the first member load: write a real `virtual ~T() throw()` and move cleanup into inline
  member-type dtors; or `extern "C" void _ReadWriteBarrier();` after the store (an intrinsic, emits nothing); or a
  volatile store + volatile first load (both needed).
- Zero kept in a register vs immediate stores depends on how many zero uses share a region with a `== 0` compare;
  change that count (inline helper, extra/fewer re-tests) to flip it.
- Base/index order in `[a+b+N]` follows definition order of the two values (copies don't count).
- `rep stosd` = `memset`; `rep movsd` = `memcpy` (declare and call; /O2 inlines). `repe cmpsb` = `memcmp` with a
  literal. `sbb eax,eax; sbb eax,-1` = `strcmp` intrinsic. `fpatan` = `atan2`; call with st0/st1 args = `fmod`.
- Function-local static with runtime init shows as a guard bit test.
- Placement new adds a null test; call `p->T::T()` to avoid it. `x/W` becomes `x*(1/W)` under MSVC.
- `/GS`: compile with `// cl-flags: /GS` and plain `char buf[N]` locals so MSVC emits the cookie itself. The cookie
  helper is `__fastcall` (cookie in ecx).
- Ruled out as levers (no effect): `register`, `const`, signedness of temps, `a+b` vs `b+a`, `p[i]`/`i[p]`.

## Equivalence (behaviour)

- Name callees and globals after their address so the checker can bind them; wrong address names are errors.
- If the original calls a function, ours must call it too (declare, don't define). Only CRT routines are exempt.
- Inline helper functions you define become symbols in the clang object; mark them `__forceinline` or the checker
  may pick the wrong target.
- A free-function declaration of a thiscall callee fails reference checks: declare it as a member.
- Locals passed by pointer: the checker compares neighbouring words, so place them in a frame struct in the
  original's slot order, sized as large as the callee writes.
- Re-read heap fields after every call where the original re-reads them (callees may change memory); load once
  where the original loads once (a float store may alias a pointer; cache `&p->m[12]` if the original does).
- One-expression virtual calls (`g->Set(g->Get() == 0)`) load the vptr once; splitting into statements reloads it.
- Loop counters the checker patches must live in memory at the original's offsets in loop-repair-heavy functions.
- NaN polarity: `fcom`/`fnstsw`/`test ah,MASK` + `jp`/`jne` encodes both the comparison and what an unordered (NaN)
  operand does. `if (a >= b)` and `!(a < b)` compile to different masks (e.g. `test ah,1` vs `test ah,5; jp`) and
  differ for NaN. Derive the condition from C0/C2/C3 and the operand order of the `fcom`, then write the form whose
  mask matches. Earlier notes got this wrong several times.
- `-(a-b)` and `0-(a-b)` differ in signed zero; `a*b + -(c*d)` keeps `fchs; faddp`.
- A bool stored as a byte then pushed as a dword carries stale upper bytes: model with a union. Return the raw byte
  (char), not bool, when the original returns a stored flag byte.
- `__int64` locals force an aligned ebp frame and `__allshr` etc.; use two `unsigned` halves or a union.
- Copy-paste bugs in the original are behaviour: keep them.
- Writable globals: never replace a global the game writes (scripts, setters) with its initial value.
- Struct-return callees (`call F; fld [eax]`) return their out pointer; keep that shape.

## x87 floats

- The original runs the FPU at 53-bit precision (control word 0x027F) set by the CRT; no game code changes it.
- MSVC /O2 keeps values in x87 registers across statements and rounds only when storing to a `float` slot. clang -O0
  rounds every named `float` local at each assignment. So:
  - a local the original never stores: use a register-float type (`typedef double regfloat` under clang, `float`
    under MSVC) so neither compiler rounds it;
  - a value the original stores and reloads: plain `float` (or `volatile float` under MSVC if it optimises the
    store away);
  - a product used twice and kept on the stack: write it inline each time.
- MSVC reassociates sums and products. Write every chain fully parenthesised in the original's order
  (`((z*nz + y*ny) + x*nx)`); a symbolic x87 order checker that compares expression trees is worth building.
- `(float)` around a math call or a double expression: MSVC drops it (value stays in the register), clang rounds.
  Drop the cast, or cast to the register-float type.
- `(int)f` / `(short)f` compile to `__ftol`/`__ftol2`: truncation to a 64-bit integer, low word used. clang's
  `fistp`/`cvttss2si` saturates. Spell it `(int)(__int64)f` where the MSVC object stays identical.
- `sqrt`, `sin`, `cos` may be inline instructions under MSVC; declare `double f(double)` to keep it so.
- Extended exponent range (x87 80-bit) vs double can't be reproduced with double: rare overflows differ.
- Float constants bit-exact: `0.0174533f` is not pi/180's float; write 9 significant digits from the executable's
  bits. A static linter that flags literals within 1e-3 of an original constant but not bit-equal pays off.
- Emulator transcendental results (xemu's fsin etc.) are not real hardware's; a port needs correctly rounded soft
  versions following real hardware.

## Calling conventions MSVC can't express

- Link-time-generated register conventions (args in eax/edx/esi, thiscall with caller pop) exist in engine and
  graphics code. Write ordinary C++ and annotate where each parameter really travels so the checker and the linker's
  adapter thunks agree. Many old "unsupported" notes were just a missing annotation.
- A callee declared with the wrong pop count can pass at -O0 (ebp frame absorbs it) and crash at -O1 (esp frame).
  Lint callee declarations against the definitions' real `ret N` across the whole tree.
- char/bool parameters forwarded to a callee are pushed as the whole stack word.
- Variadic callers and by-value struct arguments (`ret 0x2c0`) need the full stack word count.

## Evaluation order (MSVC vs clang)

- MSVC evaluates call arguments (and a binary operator's right operand) before the object expression: `G()->f(h())`
  calls `h` first; clang calls `G` first. Hoist into typed locals in the original's order.
- MSVC loads an object's vptr before evaluating arguments that contain calls; clang after. Only observable if the
  call changes the vptr; a checker that havocs memory around stubs will report it.
- Overlapping `memcpy` where the original used forward `rep movsd`: write the forward loop (undefined for memcpy).
- `new` null checks: MSVC 7.1 checks; clang with a `throw()` operator new doesn't unless `-fcheck-new`.
- Uninitialised locals the original reuses from an earlier statement's slot: make the dependency explicit.

## When to stop

- Byte-match attempts plateau around attempt 4-8; equivalence around 10 runs. Log the best attempt and the first
  mismatch, move on, and let a recipe from a later investigation unblock the group.
- Diff the call traces of one failing input before calling something a checker limit.
