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
- GPT-6 Luna, 30 large functions, 5 attempts each:

  | Size | Matched | Avg best score | Cost |
  |---|---|---|---|
  | 97–192 B | 1/12 | 0.37 | $0.022 |
  | 193–512 B | 0/10 | 0.32 | $0.027 |
  | 513–1500 B | 0/8 | 0.07 | $0.206 (~$0.026 each) |

- There's a cliff just above ~96 bytes. On the biggest functions Luna barely gets the first instructions right.
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
- Throughput bug: Luna normally answers in seconds, but runs were taking 8–17 minutes with no local load. The cause was stalled streams waiting out the 240 s timeout before retrying. With the timeout at 90 s, functions finish in 13–75 s.
- First real crash-resume test: killed both farms mid-run and restarted them. In-flight conversations reattached and continued from their committed attempts (e.g. one reported att=3 13 s after restart).

### Aligned diffs
- The compare tool paired the target's k-th instruction with our k-th, so one extra or missing instruction early on marked everything after it as wrong. Large functions looked hopeless (scores of 0.0–0.4) partly because the *feedback* was misleading.
- Switched to LCS alignment on normalized instructions (branch/call targets and image addresses ignored), with tags `!!` differs, `--` missing in ours, `++` extra in ours. Score = aligned-equal / target instructions. Exact-match checking is unchanged (byte-identical at identical offsets).
- Re-scoring Luna's large-function attempts: 0.43 → 0.74, 0.58 → 0.79, 0.51 → 0.68, 0.03 → 0.33. The models were much closer than they were told.

### Parallelism and three more correctness fixes
- Concurrency 12 → 32: a compile and compare takes 0.17 s and the box sat at load ~2.5/8, so the model API is the only bottleneck. Seen so far: 10 timeouts and 2 upstream 429s.
- Provider errors used to mark a tier "done" and escalate. Now they're retried on the next run with a fresh `requestId`, in the same conversation, so earlier attempts are kept.
- The aligned score let branches/calls "match" by mnemonic alone, so Haiku reported best=1.00 while not matching. Aligned pairs now need equal bytes (relocs masked), and jumps must land on the aligned instruction. Honest score for that case: 4/9.
- **Truncated function bodies**: `ExportFunctions` recorded only the first address range of each Ghidra function. 1,081 game functions are multi-chunk (mostly switch jump tables MSVC places inline after the code), and 1,089 had jumps leaving their recorded body. Those could *never* match. Sizes now span the whole body (11 that would swallow a neighbour keep the old size). No existing match was affected. The ≤96-byte queue is now 17,829 functions / 6,189 shapes.
- **The big throughput bug**: every Luna/Haiku request inside the farm stalled for exactly the 90 s stream timeout and returned zero tokens, then succeeded on retry. Direct requests took ~1 s, even 20 in parallel. `lsof` showed the cause: Node's built-in fetch (undici) sent all ~32 concurrent streams over **one** HTTP/2 connection to OpenRouter, and long-lived streams stalled there. Fix: a global undici `Agent` with HTTP/1.1 and a 128-connection pool. Result: ~14 → ~400 attempts per minute (~28×), and functions finish in 14–34 s instead of 10–17 minutes. Lesson: when a pipeline is slow, measure where the time goes before tuning timeouts.

### Local Macs (Unsloth Studio)
- Two Macs serve models through Unsloth Studio's OpenAI-compatible API (`farm/endpoints.json`, gitignored, has tokens). Gotchas found while connecting:
  - It accepts **no** auth header, but rejects any token it can't validate, and the OpenAI SDK always sends one. Fix: real per-Mac tokens.
  - It only serves the loaded model unless "Switch model by request" is on. Models can be loaded via `POST /api/inference/load {"model_path": "<hf repo id>"}`.
  - GGUF (llama.cpp) handled 4 parallel requests well (~170 tok/s total on a 2B model). **MLX models hung with 4 parallel requests**, so MLX endpoints run at concurrency 1.
  - **Local reasoning models ignore "low" effort.** Ternary-Bonsai-2-27B (2-bit) thought for ~20k tokens on one function without submitting. `chat_template_kwargs.enable_thinking=false` (or `reasoning_effort: "none"`) is honoured by both servers: 19–34 s down to 3–8 s per reply. The farm now injects it for local endpoints (`"thinking": false` is the default).
  - Gemma-4-12B appears to loop inside tool arguments when allowed 32k output tokens. Local endpoints are now capped at 4k output tokens (`maxTokens`).
- **Runaway outputs**: one GPT-6 Luna turn produced a 483 KB "submission" (a repetition loop, 137k output tokens, $0.09, 18 minutes). That's ~50× a normal function's cost. Haiku then matched it in one try for $0.0016. The farm now clamps OpenRouter requests to 8k output tokens (above any thinking budget) and trims the best-attempt code passed to the next tier.
- **Out of credits**: around $6.9 of ledger spend, OpenRouter started answering `402 … exceed your available credits` (the *account balance*, separate from the key's spending limit). The sweep kept cycling through instant failures. The farm now treats a 402 from a paid tier as a budget stop, skipping paid tiers for the rest of the run, and the sweep exits. Failed runs stay retryable once credits are topped up.
- Status when the sweep stopped: **12,398 functions (53.8%), 317 KB of 2.60 MB (12.2%)**, ~$6.9 total cloud spend.

### Reference verification (task 01): codegen match → full match
- `tools/verify_relocs.py` pairs every relocation in our object with the original 4 bytes at the same offset (valid because offsets line up in an exact match), then checks the original target: string literals byte-equal, `__real@` floats bit-equal, vftables are real vftables, calls land on function starts, data refs land in data, and one symbol maps to one target.
- Full run over 12,415 matches (57 min, 8 workers): **12,181 verified (98.1%), 234 flagged**. After softening false positives (XDK sections like `D3D` hold real globals; an `int` global holding a function address; calls to functions Ghidra didn't split out), **225 are genuinely wrong**, 6.1 KB in total:
  - 170 string mismatches, mostly *propagated* matches: same code shape, but the copied source carries the other function's strings;
  - 49 cases of one declared function standing in for two different call targets;
  - 17 references into the middle of code;
  - 6 where the original has a constant `0` but ours has a vftable pointer (the masking hid it);
  - 2 float mismatches.
- The 225 moved to `build/farm/invalid/` and are retried under fresh conversations. From now on the farm's `submit_cpp` and shape propagation both run the reference check before accepting a match, and wrong references go back to the model as feedback.

### RCF archives (task 03): exact names and byte-identical repack
- The first `rcf.py` joined names to directory entries by position, so sizes were wrong (`fe_real.txt` came out as 94 bytes instead of 87,217). The name table has no offsets, and the directory is sorted by hash, so a correct join needs the game's filename hash.
- Found it by scanning `.text` for `imul r, r, 0x1f`: there are only two hits in radcore, `FUN_002673a0` and `FUN_002673d0`. The second is `h = h*31 + c` with `c += 0x20` for every char below `'a'`. That's a cheap case fold that also shifts `\`, `.` and digits. With seed 0 it matches **8,359 / 8,359** names across all 13 archives.
- Name records: `{mtime, 0x800, 0, len, name\0, 3 zero bytes}`. The mtimes are real Unix timestamps from 2005-03-10 to 2005-06-08, a build-date fingerprint (the movies were packed 2005-05-30 and 2005-06-03; sound on 2005-06-07).
- Every layout rule is deterministic (sections and files 0x800-aligned, last file unpadded, zero fill), so `rcf.py repack` rebuilds all 13 archives **byte-for-byte** from extracted files plus a small `_rcf.json` manifest. That unblocks mods. `rcf.py verify` checks all 2.3 GB in ~5 s using mmap.
- Contents (8,359 files):

| Archive | Files | Size | Types | Built | Top dirs |
|---|---|---|---|---|---|
| `art.rcf` | 1188 | 348 MB | .p3d 361, .png 315, .lua 187, .fig 138, .rdl 94, .dh 93 | 2005-03-24 – 06-08 | art |
| `districts.rcf` | 35 | 45 MB | .p3d 35 | 2005-05-15 – 06-07 | art |
| `misc.rcf` | 676 | 13 MB | .txt 508, .lua 107, .fig 38, .p3d 22, .dhd 1 | 2005-03-10 – 06-08 | frontend, scripts |
| `mog_mov1-3.rcf` | 3+2+3 | 629 MB | .rmv | 2005-06-03 | movies |
| `movies1-2.rcf` | 8+12 | 541 MB | .rmv | 2005-05-30 | movies |
| `nis.rcf` | 141 | 15 MB | .p3d 141 | 2005-06-07 | nis, nischars |
| `rooms.rcf` | 784 | 127 MB | .p3d 784 | 2005-05-15 – 06-08 | art |
| `sound.rcf` | 394 | 354 MB | .rsd 394 | 2005-06-07 | sound |
| `sound_en.rcf` | 4732 | 220 MB | .rsd 4732 | 2005-06-07 | sound |
| `sound_misc.rcf` | 381 | 27 MB | .lua 101, .obj 93, .p3d 93, .txt 93, .ods 1 | 2005-05-15 – 06-07 | sound |

- Surprises: `art.rcf`'s 315 `.png` files are plain PNGs for the unlockable bonus gallery (`art\bonus\concept_*`, `comic_images`), and the `.lua` files are compiled bytecode (`\x1bLua`). `sound_en.rcf` isn't in `rcfs.txt`; the game builds its name from `sound_%s.rcf`, and there's also a `sound_uk.rcf` string.

### Compile-error coaching
- `tools/compile_errors.py` mines every `submit_cpp` reply in the farm databases. Baseline over 25,000 submissions: **15.5% failed to compile**.
  - The top code by far was C4234 (`__thiscall` in Ghidra-style casts, 2,449 hits).
  - Next: undeclared members/identifiers (C2039/C2065/C3861), mismatched member declarations (C2761/C2509/C2535/C2556/C2511), ctor/dtor misuse (C2600/C2533/C2577), and bad padding arrays (C2229/C2118).
  - Syntax/brace errors (C2059/C2143/C2447/C1075) had the worst recovery: 34–52% compiled on the next try.
- `farm/src/hints.ts` appends a one-line MSVC 7.1-specific fix for each recognized error code (max 3) to compile-error replies. The system prompt gained the three most common rules: no `__thiscall` casts, pre-C++11 syntax, ctor/dtor declarations and padding. Re-measure with `tools/compile_errors.py` on runs after this change.
- Self-inflicted bug: I reworded the budget-stop log message, and the sweep's stop check (`grep 'budget .* reached'`) no longer matched it. The sweep looped through instant no-op chunks until I killed it (nothing spent; paid tiers were skipped each time). It now keys off the stable suffix `skipping paid tiers`. Lesson: log lines that scripts parse are an interface.
- Cloud sweep paused at the OpenRouter key's $10 limit (account still has ~$4 of credit). Status: **13,802 functions (59.9%), 15.6% of game bytes**; ledger spend ~$13.7 including benchmarks.
