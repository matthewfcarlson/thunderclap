# Project journal

A running record of what we tried, what we learned, and what it cost, kept for a later blog write-up.
Newest entries go at the bottom of each day.

## 2026-10-08: Day 1, from ISO to a matching farm

### Target recon
- Disc: Xbox USA/Asia xiso, 2.4 GB. `default.xbe` (5.2 MB, MD5 `5ed84ae5…`) plus 13 `.rcf` archives tagged `ATG CORE CEMENT LIBRARY`, which is Radical's "Cement" format, same family as *Simpsons: Hit & Run*.
- Built 2005-06-15 from `c:\HC3-Link\hulk2\…`. Internal name **hulk2**. The PDB (`hulk2f.pdb`) is referenced but not shipped.
- All XDK libraries are **5849** (the final XDK), so the compiler should be VC 7.1.
- **RTTI is on**: ~4,200 type descriptors with namespaces `pure3d`, `choreo2`, `fight`, `physics`, `audio`, … This confirms the Pure3D/radcore engine. It was the single biggest free win of the day.
- Codegen fingerprint from raw byte counts: almost no `push ebp; mov ebp,esp` (frame pointers omitted), zero SSE (x87 only), and lots of `ret N` (thiscall-heavy C++).

### Prior art
- Closest analogues: **punpckhdq/halo** (matching original-Xbox decomp, csplit + objdiff + wibo) and **dc3-decomp** (Claude-driven Xbox 360 MSVC decomp at ~91%).
- LLM-decomp lessons from others: schedule similar functions together; don't let permuters overfit; hooks against tampering; cap retries.
- The leaked SHAR source shares this engine. Decision: **never use it**; clean-room only.
- One TCRF page returned prompt-injection text (instructions to transfer money, write `key.bin`). Ignored, and noted as an unreliable source.

### Toolchain
- No XDK needed: the XDK 5849 compiler is reported as `cl` **13.10.3077**, the same build decomp.me hosts as `win32/msvc7.1`. Pulled straight from ghcr.io without Docker (`tools/pull_compiler.py`).
- Runs on Apple Silicon via **wibo** (x86_64 build, Rosetta). Gotcha: `cl` parses absolute paths like `/private/...` as switches, so compile from the source's directory.
- Ghidra 12.0.3 + ghidra-xbe. Gotchas:
  - The XbSymbolDatabase binary ships only as `mac_x86_64` and must be copied to `mac_arm_64`.
  - Ghidra's RTTI analyzer is PE-only, so it found nothing on the XBE.
- Wrote our own RTTI walker (`tools/rtti.py`, under 0.5 s) plus a tiny MSVC demangler. `undname.exe` prints nothing under wibo.
  - Recovered **4,244 classes, 4,267 vtables, 13,006 virtual functions**.
  - Applying them in Ghidra created 8,467 functions that auto-analysis had missed: 17,481 → **25,426 functions, 52% named**.

### First matches (by hand)
- 5 of 5 small functions matched byte-for-byte (refcount `Release`, switch dispatcher, x87 getter, two member-fn-pointer templates). This confirmed `cl 13.10.3077 /O2`.
- MSVC 7.1 idioms learned:
  - `bool r=false; switch…break; return r;` instead of early returns;
  - copying a member-fn pointer to a local before calling it.

### Matching farm
- Built on **pi-durable** (Earendil's new durable agent runtime, SQLite-backed, crash-resumable):
  - one `submit_cpp` tool;
  - a precomputed context "packet" per function (symbolized asm, RTTI class and vtable, Ghidra C hint);
  - a static system prompt;
  - tiered escalation;
  - a per-run ledger.
- Token discipline: workers get no file or shell tools, so there's nothing to explore. Diffs are compact (mismatches ±1 line). A match ends the run via `control: terminate`.
- Anti-cheat: reject `__asm`, `_emit`, `naked` and `#pragma`. No model tried it so far, but it's cheap insurance.
- **Shape dedup was a huge win.** Masking call targets and absolute addresses, 18,270 queued functions collapse to **6,407 shapes**. One match propagates to every identical shape with zero LLM calls: ~80 model matches → **2,212 verified functions**. Caveat: most are tiny, so by bytes this is only ~2% of game code. Count progress in bytes, not functions.

### Model benchmark (20 mid-size functions, 32–96 bytes, 5 attempts, low thinking)

| Model | Match | $/match | tok/run | median |
|---|---|---|---|---|
| **GPT-6 Luna** | **65%** | **$0.0019** | **1.5k** | **73 s** |
| Claude Haiku 5.5 | 45% | $0.0064 | 4.2k | 109 s |
| GLM-5.3-flash | 50% | $0.011 | 16k | 488 s |
| DeepSeek-v4.1-flash | 65% | $0.027 | 22k | 272 s |
| Qwen 3.8 Flash (10/20 runs) | 70% | $0.0089 | 18k | 838 s |
| MiMo v2.6 Flash (stopped) | 44% | $0.017 | 33k | 974 s |

- GPT-6 Luna dominates on cost, speed and match rate. The thinking-heavy models spend 10–30× the tokens for similar results.
- On tiny functions (1–8 bytes) even GLM-5.3-flash went 42/42 at $0.0005 each.
- 17/20 were matched by *some* model, so different model families rescue each other's misses.
- Early GLM pilots had many "failed" runs: 15–30-minute stalls from long thinking and stream timeouts. Lowering thinking and logging failure reasons helped.

### Large functions (>96 bytes): first signal
- GPT-6 Luna on 97–192-byte functions: **0/8 so far**, all exhausted after 5 attempts. Best scores range from 0.00 to 0.82, at ~$0.002 each. The step from 96 to ~100+ bytes looks like a cliff for one-shot-ish cheap models. Bigger functions are still running.
- Implication: the cheap farm alone won't cover large functions. They need stronger models (e.g. GPT-6 Astra at $10/$50 per M, ~100× Luna), more attempts with better feedback, similar-function examples, or the free local Macs.

### Difficulty routing (dropped)
- Tried TypeSafe **Jev** as a complexity classifier ($0.005 for 48 functions).
  - On 19 labeled outcomes its AUC was 0.65–0.68, no better than function size (0.65) and worse than a free static asm score (0.74).
  - More to the point, Luna attempts are so cheap (~$0.001–0.003) that skipping them never saves money. Routing only matters for gating expensive tiers.
- Decision: no Jev. Luna goes first for everything.

### Spend
- OpenRouter key usage today: **$0.74**. Our ledger said $0.82, so it slightly over-counts (it uses catalog prices).
- Most of it went to benchmarking thinking-heavy models. Luna's whole 20-function benchmark cost $0.025.
- Budget is $50. The farm enforces `--budget` and stops paid tiers near the OpenRouter key limit.

### Mistakes worth remembering
- Extrapolated a ~$1.1k (likely) / $3.2k (high) whole-game cost from the slowest, most expensive pilot model. Real per-match costs with the right model are 5–14× lower. Benchmark models before forecasting.
- Shipped a farm change that typechecked but crashed under Node's type stripping (TS parameter properties). Now typecheck with `--erasableSyntaxOnly`.
- Measured "100% match" on a sample that turned out to be 1–8-byte functions (the queue was sorted by size). Always sample across sizes.

### Escalation handoff (evening)
- Escalation used to pass only the previous tier's best code and diff. Now every earlier attempt is summarized in one line (score, length, first mismatching instruction), plus the best code and diff across all tiers. Example of what a higher tier now sees:
  `tier 0 attempt 1: score 0.62; target=102 ours=102, instructions matched 28/45; first mismatch 0010 push ebp | push ebx`
- Each tier's exact prompt is saved as `build/farm/work/<tag>/<addr>/t<N>_prompt.txt` for debugging (and blog material).
- Bug found while testing: pi-durable conversation IDs are **numbers**. We stored them as strings in our index, so `harness.conversation("2")` quietly returned nothing. Restart/resume would have created fresh conversations instead of reattaching. Fixed (stored as numbers; old string entries are converted on read).
