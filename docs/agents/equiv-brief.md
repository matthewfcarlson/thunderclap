# Brief: equivalent decomp of large functions

Write C++ for each function in your batch file that **behaves** exactly like the original, proven by
`tools/equiv.py`. A byte-match is not required. This source is for a native PC port, so it must be correct
and readable.

Repo: /Users/matthewcarlson/git/hulk-ultimate-destruction-decomp (run everything from the repo root).

## Per function
1. `build/venv/bin/python tools/packet.py show 0xADDR`: the assembly, the Ghidra hint and the referenced data.
2. Write `build/farm/bench/claude-equiv/work/0xADDR.cpp`, a self-contained translation unit (rules below).
3. `build/venv/bin/python tools/equiv.py build/farm/bench/claude-equiv/work/0xADDR.cpp 0xADDR --json`
   - Iterate until `"status": "equivalent"` and `level2.conflicts` is empty.
   - Fix the earliest differing call or write first.
   - `docs/equivalence.md` explains the report.
   - Optionally, check `tools/compare.py SRC 0xADDR` for a free byte-match, but don't chase one.
4. Cap: **10 equiv.py runs per function**. Then move on and record it as failed, with your best attempt left in `work/`.
5. When the function passes, copy it to `build/farm/bench/claude-equiv/pass/0xADDR.cpp`.
6. Log every function as one JSON line appended to `build/farm/bench/claude-equiv/log.jsonl`:
   `{"addr": "0x...", "agent": "<your batch letter>", "status": "equivalent|fail|unsupported", "runs": N, "coverage": "covered/total", "note": "<short: what was hard>"}`

## Translation unit rules
They're in `build/farm/bench/claude-equiv/rules.txt` (the farm's equivalent-mode system prompt); read it
first. The essentials:
- No `#include`.
- Declare every class, global and callee yourself. Define exactly one function body, the target.
- Name callees and globals after their address (`FUN_0022b980`, `DAT_004dd6e4`), and keep member functions inside their class.
- The target's calling convention, parameter count and return type must match the original.
- MSVC 7.1 is pre-C++11.
- No asm or `#pragma`. Never hard-code image addresses as integers.
- Use real structs with named fields, and loops instead of gotos.
- **Register-argument callees** (eax, or other registers C++ can't express): declare them normally and add `// equiv-conv: FUN_x eax ecx stack`. See "Register conventions" in `docs/equivalence.md`.
- **Hand-written stack cookie:** for a /GS cookie, see matches/0x001fc460.cpp, or just omit the cookie; the checker skips the cookie call.
- `matches/*.cpp` has ~15k matched functions. Grep it for the same class or callee names to reuse layouts.

## Hard rules
- Don't commit, push, or edit anything outside `build/farm/bench/claude-equiv/`. Don't touch `tools/`, `farm/`, `matches/` or `equivalent/`. Other sessions and lanes are running in this checkout.
- Never use or look at any leaked source code from other Radical games (e.g. The Simpsons: Hit & Run).
- Don't spawn subagents.
- If `equiv.py` itself seems wrong (it claims a difference that you are sure is a false failure), note it in the log line and move on. Don't work around the checker.

## Final report
Under 300 words:
- counts (equivalent / fail / unsupported) and total equiv.py runs;
- which kinds of failures were hard;
- any suspected checker bugs, with the addr and the exact report line.
