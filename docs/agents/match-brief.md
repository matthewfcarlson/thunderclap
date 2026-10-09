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
