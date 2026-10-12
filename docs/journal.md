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
- **Ledger double-counting**: once failed runs were retried *in the same conversation*, each ledger row recorded that conversation's cumulative `pi.usage`, so retries re-counted earlier spend. The ledger claimed $30 vs ~$15.6 real (OpenRouter key usage; it includes earlier non-farm use). One row claimed 264k output tokens in 43 s. The sweep stopped on the inflated internal budget. Rows now record per-run deltas (usage after − before). The real guards are OpenRouter's key allowance and the 402 out-of-credits check.

### Pure3D (task 04): verified against real files; textures and Hulk export
- The spec-first `p3d.py` chunk walker was right: all 1,436 `.p3d` files parse with 0 bad chunks. Most chunk *names* were wrong or missing, though. Ground truth came from the XBE: each `*Loader` class's constructor stores its chunk ID next to its vtable pointer, so scanning the functions that reference each vtable gave 29 confirmed IDs (Skeleton is 0x23000, not the 0x4500 I'd guessed; PolySkin 0x10001; Room 0x60000701, …).
- **Textures are plain files**: ImageData is `u32 size` + a complete DDS (DXT1/3/5 only, no Xbox swizzle) or PNG. A ~60-line pure-Python DXT decoder exports all **8,798 textures in ~40 s**. The DDS rows are bottom-up: the controller diagram's "L"/"R" read upside down until flipped.
- **Hulk** (`global_hulk.p3d`): a 38-joint skeleton, a 4-primitive PolySkin (3,426 triangles from strips) and one 256² DXT texture. Two traps on the way to a correct glTF:
  1. The first render had denim on Hulk's head. The UV list has an extra `u32 channel` after the count (8,140 = 16 + 4 + 1015×8), so every pair was off by one float. Scoring all 8 flip/swap variants by "Shorts samples blue, Skin samples green" showed no orientation worked. That pointed to a parsing bug rather than an orientation one.
  2. Bone indices pack the first weight's slot in the top byte. Checked geometrically: the top-byte joint is the nearest joint for 847/1015 vertices, against 10 for the low byte.
- No Blender here, so the `.glb` is checked by reading it back: accessor bounds, joint indices < 38, weights sum to 1, plus a small software rasterizer to render it. Front and back renders look right: face, torso, torn shorts.
- **World geometry** shares shaders across files: a downtown room references shaders and textures that live in `districts.rcf` (`dt_day_district_N.p3d`), mirroring how the game resolves by name across loaded inventory. `p3d.py gltf --lib` handles this; with the district libs, the room's skyscrapers export textured. Rooms also carry baked vertex lighting (D3DCOLOR) and a second UV channel (grime/lightmap); both are exported.
- Gotcha for anyone grepping assets on macOS: `grep -r` silently misses strings in binary files under a UTF-8 locale. Use `LC_ALL=C grep -a`.
- Remaining unknown chunks are dominated by animation channels (0x1211xx, ~800k instances), then collision volumes (0x701xxxx) and state props (0x802xxxx). Those are the next targets (animations → glTF).

### Pure3D animations and whole-city export
- **Animations** decode cleanly: all 14,856 animations / 283,400 channels of the decoded types fill their chunks to the byte. Rotation comes in four encodings: float quaternions, `s16[4]`, `s16[3]` (cutscenes) and `s8[3]` (gameplay, the most common channel in the game: 3 bytes per key, w derived). The quaternion order (x, y, z[, w]) and handedness were settled by scoring every candidate against Hulk's rest pose; the right one matched far better than the rest. Translation keys match the rest pose exactly.
- Joints bind by **group name**, not group id (weapon-joint ids vary between animations). Cutscenes name the root group after the character (`hulk`) instead of `Motion_Root`.
- Many characters share joint names, so a glob picks whose animations to bind: `p3d.py gltf global_hulk.p3d hulk.glb --anims global_nonchar.p3d --anim-match 'hlk_*'` gives Hulk with **178 animations** (4.8 MB, < 1 s). Checked with a skinned software render: the run cycle loops, `hlk_pnch_devastator_slam` crouches and slams, the `5E_5_hulk_roar` cutscene flings his arms out with the jaw open.
- **Cities**: `p3d.py city downtown_day out.glb` merges every room (in world space) with district textures. All 15 locations export in ~30 s, with 4,121/4,126 materials textured. A top-down render of downtown shows the full street grid, park and rooftops.
- Shared checkout hazard: another session committed onto this branch and then aborted a rebase, which discarded my uncommitted edits. Commit early when sharing a working tree.
- Night lane found 24 functions whose Ghidra body stops one instruction short of the final `ret`, e.g. `0x17000` recorded as 3 bytes (`mov eax,[ecx+0x20]`) with the `ret` left out. They could never match, and the model's attempts scored 1.00 aligned but "exhausted". Sizes are patched in `build/functions.csv` (extended by the following `C3`/`C2 nn nn`). A future `ExportFunctions` re-export needs the same post-pass.

### Large-function A/B: similar-function examples (task 08)
- GPT-6 Luna on the 30 large benchmark functions, fresh runs under the current prompt and scoring. **Without** examples: 2/30 matched, avg best 0.53. **With** up to 2 verified similar matches in the packet: 1/30, avg best 0.50. On the 10 functions that actually got examples: 0/10 either way (avg best 0.52 vs 0.47). ~$0.10 per arm.
- Conclusion: the nearest matched functions are small generic idioms (~30-byte dtors/ctors), and they don't carry what large functions need. `packet.py --similar` stays opt-in and off by default.

### Sonnet 5.5 cracks mid-size functions
- On the 12 benchmark functions of 97–192 bytes: **Claude Sonnet 5.5 matched 8/12** (avg best 0.95) at $0.53 total, ~$0.066 per match. GPT-6 Luna matched 2/12 (avg best 0.69) on the same set. Sonnet matches typically took 3–5 attempts and 12–40 s.
- So the cheap-model cliff above ~96 bytes is a capability cliff, not a feedback problem. For functions over 96 bytes the tier should be Sonnet, ~2 KB of game code matched per dollar at these sizes.
- Spent the last OpenRouter credit on Sonnet over the 97–192 B queue (2,100 unique shapes). Result: 5/28 (18%) for $0.95, well below the benchmark's 67%. Smallest-first ordering front-loaded a family of near-identical functions (`0x001a3a00…0x001a4410`) that Sonnet couldn't crack, so the next run should interleave shapes or skip a family after repeated failures. With 8 concurrent Sonnet requests OpenRouter returned 402 while ~$1.60 was still left: it checks each request's maximum possible cost (8k output tokens) against the balance. At low balances, run with fewer concurrent requests.

## 2026-10-09: Overnight

- **mac2 night lane** (Qwen3.8-Flash-Next GGUF, thinking low, 4 parallel, 8 attempts, 23:52–07:02): 78 functions tried, **29 matched (37%)**, median ~19 min per function. Its queue was what the cloud tiers had given up on, closest misses first, so a free local model can finish near-misses that cheap cloud models gave up on. Propagation turned 29 direct matches into +83 committed functions.
- Lessons from the night:
  - Front-of-queue junk wastes local time. Ghidra bodies that don't end in `ret`/`jmp` are unmatchable and are now filtered.
  - The score must penalize *extra* instructions (fixed).
  - Flash-Next started at 1/18, then improved as it reached the closer cloud misses.
- Formatting pass: 13,427 matches reformatted with clang-format, 565 already clean, 0 that failed re-verification. New matches are formatted on save.
- Morning status: **14,089 functions (61.1%), 432 KB of 2.60 MB (16.6%)**. OpenRouter credit is exhausted. Real spend for the whole project so far is ~$18.9 of the $50 budget.

### Claude subagents as matchers (subscription, not OpenRouter)
- 4 Sonnet subagents with 8 mid-size (97–192 B) functions each, spread across the queue, plus the shared tools (packet, compare, verify_relocs, format). **10/32 matched (31%)**, all re-verified. Per batch: 4, 4, 1, 1. These are harder than the benchmark set: the ones the OpenRouter Sonnet lane hadn't reached, with no cherry-picking.
- Same morning, the last $0.22 of OpenRouter credit: GPT-6 Luna on 122 interleaved mid-size functions, **25 matches (20%)**, ~$0.009 per match.
- What the agents found (folded into the prompt):
  - Callees without `add esp` are `__stdcall`; `FUN_0034483c` is `_ftol`.
  - Any destructor, even on a temporary, adds an SEH frame. Use a plain virtual method as a placeholder, or `throw()` dtors.
  - Float sum order matters (try permutations); `inline` helpers change instruction selection; copying a member to a local changes load order.
- **Two structural findings that matter later:**
  1. Three agents independently hit functions taking arguments in registers (`eax`/`ebx`/`edi`, plain `ret`). That points at **link-time code generation (`/GL` + `/LTCG`)**, which invents calling conventions for internal functions. Plain per-file C++ can't reproduce those, so they need a different approach (and it matters for the relink stage).
  2. One function has an `ebp` frame with `leave`, i.e. at least some objects were built *without* frame-pointer omission (`/Oy-`). Per-object compiler flags will be part of the split config.
- Common near-miss causes: register allocation (`this` in ebp vs edi), block layout of early returns, spills, `add ecx,-3` vs `sub ecx,3`. That's the long tail.

## 2026-10-09: Daytime rounds

- **Subagent round 4: 46/64 matched (72%)**, the best round yet. One batch went 8/8, and several functions matched on the first attempt. The difference from round 1's 38% is the accumulated prompt tips plus one-function-per-family batches.
- OpenRouter Luna→Sonnet lane on mid-size functions: 51 matches for $2.74 (~$0.054/match). Then the key hit a **weekly** budget cap, which OpenRouter reports as `403 Budget limit exceeded (weekly limit)`, not `402`. The lane looped on instant failures (no cost) until stopped. The guard now treats a budget-flavored 403 like a 402.
- **Subagent round 5: 38/64 (59%).** Confirmed that part of the binary, mostly the CRT/XAPI region around 0x34xxxx–0x35xxxx, was built with **/O1 /Oy-** (size-optimized with frame pointers). Exact matches came with `// cl-flags: /Oy- /O1`. So at least three code-generation regimes exist: game code /O2 with frame-pointer omission, some objects /Oy-, and library code /O1 /Oy-. All of them will need to be recorded per object in the split config.

### 2026-10-09: Batch API and the permuter
- **OpenRouter Batch API** (`tools/batch_run.py`): `:batch` models are half price but only go through `POST /api/v1/batches`; the chat endpoint rejects them. With no live tool loop, attempts run in rounds, and each miss gets its best code plus diff in the next round. Sonnet 5.5 on 200 random untried mid-size functions (97–192 B), 4 rounds: matches per round 18/200, 23/182, 19/159, 7/140, so **67/200 (34%) for $5.14 = $0.077/match**. That's *worse* than the live Luna→Sonnet lane (~$0.054). Each request is half price, but one attempt per round with only the best attempt and last diff converges more slowly than the live multi-turn loop, and round 4 returned little ($0.17/match). Batch per-request results carry no cost; it's in the batch-level `usage.cost`.
- Haiku 5.5's batch sat queued (0/100) for over an hour while Sonnet's rounds took ~10 min each.
- **Permuter** (`tools/permute.py`): random source rewrites (statement swaps, commuted operands, flipped compares, int/unsigned, if/else flip, split init, flag sets), compiled at ~34 variants/s on 5 cores, hill-climbing with plateau walks. Only byte-identical plus reference-verified results count, so mutations needn't preserve meaning. First test: 0.44 → 0.59 on a register-allocation near-miss in 3 minutes. Wired into batch_run between rounds for misses ≥0.75.
- **Workbench** (`tools/workbench/`): a godbolt-style local page for matching by hand. A function list is sorted by best score. The editor is preloaded with the best earlier attempt (scored on open), next to a side-by-side aligned asm diff, a C++ diff against the starting attempt, the packet context (Ghidra decompilation, data refs) and a list of earlier attempts. Auto-compile while typing, plus a Permute button. Verified matches are installed, formatted, committed (that file only) and pushed.
- Restarted the paid lane as **Luna only** (no Sonnet escalation) over 3,945 functions of up to 192 B that Luna had never tried. OpenRouter blocked twice more on caps, a weekly key budget and then a **workspace monthly budget** (`403 Workspace monthly budget of $20.00 exceeded`); both were raised.

## 2026-10-10: Shared class headers from RTTI (task 02)

- **`tools/gen_headers.py` → `include/gen/`**: 17 namespace headers generated from `build/rtti.json` (4,244 classes, 1,611 emitted units, since the 2,688 template instantiations fold into 55 families). Bases come in RTTI order, virtuals in vtable order as `vfunc_N` with overrides redeclared and `_purecall` slots as `= 0`, and destructors are detected from slot bodies (`test byte ptr [esp+N],1` and `ret 4`; 85 slot families). Each slot's parameter count comes from its `ret N`.
- **The layout probe is the proof.** Every header compiles with `cl` 13.10 `/O2 /GR /GX`. A second TU constructs every class so MSVC emits its vftables and RTTI. Parsing that COFF, **all 4,238 polymorphic classes** agree with the XBE: vftable slot counts, all 27,439 slot implementers, `??_R1` base offsets, and `sizeof` against the generator's layout. MSVC rebuilding the game's own RTTI from our headers is a strong check.
- Things the probe caught:
  - Interfaces like `core::IRefCount` have `_purecall` in their destructor slot, so they declare **pure virtual destructors**, and every interface down the chain redeclares one.
  - Multiple inheritance (21 classes, all `core`/`movie` interface + `core::Object` mixes, no virtual inheritance) needs base sizes. These are proven by the next base's offset: `sizeof(core::Object) == 8`.
  - Placeholder names collide under multiple inheritance (one `vfunc_3` overrides both bases' `vfunc_3`), so 11 secondary-interface slots are renamed `vfunc_N_<Interface>`.
  - `Method1<T,...>` keeps a 4-byte member-function pointer, but for a forward-declared `T` MSVC picks the 16-byte general form. Forward declarations now carry `__single_inheritance`.
  - `rtti.py` over-counted `om::DynBehaviour`'s vftable by one slot. The bogus slot `0xa5d0a` is also a bogus 1,449-byte function in `functions.csv`.
- The 5 original hand matches (`experiments/first-matches/*_gen.cpp`) were rewritten on the headers and **all still MATCH**, including `Method0/1<CActorManager,…>::vfunc_2` as explicit specializations of the generated templates.
- **Mining `matches/`** (clang, MS-ABI layouts) gives 1,795 proven fields in 781 classes and signatures for 1,012 of 1,535 slot families. Votes split (123 slots, 150 fields) only between stub guesses (`int`/`void*`/`unsigned`), never on offsets that matter.
- **Swap-in test:** 400 random vfunc matches were mechanically rewritten to use the headers instead of their stubs. **220 of the 270 non-destructor ones still MATCH and none DIFF.** Whenever the rewrite compiles, the bytes are identical. Failures are scalar-deleting-destructor matches (a third of all vfunc matches, which need real `~X()` definitions), voted signatures that disagree with a call site, and stubs with several bases. Details: `docs/headers.md`.

## 2026-10-10: Platform boundary and QoL subsystem map (roadmap step 1, task 07)

- **The shim surface is small and the seams hold.** `tools/platform_map.py` (on a new Ghidra reference export, `ExportRefs.java`) resolves every call out of game code through thunks and the kernel thunk table: **182 distinct platform functions** (86 D3D8/XGraphics, 24 DirectSound/soundtrack, 12 Bink, 7 XInput, 10 file, 12 save/MU, 16 thread/sync, 3 timing, 5 memory, 6 system, 1 debug) plus 69 portable CRT/C++ runtime functions. All of it is called from four engine seams: the Pure3D `d3d*` backend (149 functions call D3D), radcore's Xbox layer (71), the radsound HAL (15) and `movie::PlayerBink` (10). Only **8 game functions** outside them touch the platform, all trivial (a DVD check, launch info, language, memory status, a Pure3D timer). Details: `docs/platform-boundary.md`.
- No NV2A/APU MMIO, no port I/O, no `rdtsc`, no Xbox Live. But game code does contain **NV2A push-buffer method numbers**: the XDK's inline `SetRenderState` writes `D3D__RenderState`/`D3D__DirtyFlags` directly and passes methods like `0x40300` to `D3DDevice_SetRenderState_Simple` (56 sites, all in the render seam).
- `QueryPerformanceFrequency` is a constant: `mov [eax], 0x2bb5c755` = 733,333,333 Hz.
- `.text` isn't all game code: XAPILIB sits at `0x208b9c`–`0x212bb0` and LIBCMT+XAPI at `0x3440e0`–`0x35be88` (minus a Radical math library at `0x356bf0`–`0x35a7b0`). 753 functions / 106 KB there are in the farm queue as "game"; 47 are already matched.
- Unnamed CRT code needs care: the 758-call function I first took for `operator new` is `__RTDynamicCast` (5 args, two type descriptors), and Ghidra's function-ID `_strncpy` is a memcpy-shaped copy. XbSymbolDatabase put `D3D_SetPushBufferSize` on `0x244c0`, which is game code; the real one is `0x37d8e0`.
- **QoL map** (`docs/subsystems.md`): the game already supports **16:9 and 480p/720p/1080i** (mode table at `0x4d3508`, request 1280×720, filtered by the dashboard's video flags), cameras are **Hor+** (nominal FOV = horizontal FOV at 4:3), and the HUD overlay width scales with aspect. Timing is variable-step with dt clamped at 66.7 ms, but `d3dDisplay::SwapBuffers` waits for **two vblanks per frame in gameplay (30 fps)** and one in menus and movies; the switch is one flag (`0x5554a0`). Modes wider than 720 px drop to a 16-bit back buffer. Intro sequence: copyright 3 s + 5 s, then dolby/marvel/radical/sierra/attract, stepped by one counter at `0x49fb40`.
- Self-inflicted bug, caught before it spread: the first label script created Ghidra labels at function entries, and a label on a `FUN_` function *becomes its name*. That would have renamed 140 game functions on the next `ExportFunctions` and silently dropped them from the farm (`packet.py` decides "game code" by the `FUN_`/`vfunc_` prefix). `ApplyPortLabels.java` now writes `[port]` plate comments on functions, labels only data, and repaired the project; a fresh export matches `functions.csv` exactly.
- Priority list: `docs/port-priority.txt` (= `build/farm/priority.txt`), 2,011 functions / 228 KB: seams first, then the QoL functions, then their direct callees. 1,339 are already matched, but only 20% of the bytes.

## 2026-10-10: Equivalence verifier (task 09, levels 1–3)

- **`tools/equiv.py SRC 0xADDR`** checks behaviour instead of bytes ([docs/equivalence.md](equivalence.md)). It compiles with MSVC 7.1, binds every symbol to an original address and checks the references (level 2). Then it runs the original bytes and our linked object side by side in **Unicorn** (level 3). Every call is stubbed and recorded. Memory is a pure function of (seed, epoch, address), mapped lazily, so both runs read identical bytes anywhere and nothing faults. After each stub call, all data pages are remapped with a new epoch's contents, to model "the callee may change anything". It compares call targets and arguments, `this`, locals passed by pointer, memory writes per call segment, the return value, callee-saved registers and stack balance. It also reports branch coverage of the original.
- **Ground truth, 300 matches (size-stratified; 110 over 128 B):**
  - all 300 pass against themselves;
  - the same sources recompiled with `/O1` (268 of them byte-different) pass 300/300;
  - recompiled with `/Oy-` (236 byte-different), they pass 300/300.
  - Median 2.3 s per function including the compile, p90 3.8 s; one long loop hit the 120 s budget. Branch coverage is complete on 285/300, with 97.6% of edges covered overall.
- **Mutation suite, 120 functions:**
  - 334 mutants caught: 58 at level 2, 276 at level 3.
  - The 4 false passes all had full branch coverage, and each needs a particular combination of data:
    - a magic return value combined with a flag;
    - a byte copy whose bytes happen to be equal;
    - a boundary on a pointer difference (`n > 40` → `41`);
    - a first loop iteration behind a three-pointer chain.
  - 6 mutants are semantically equivalent with different bytes (hand-checked): dead stores, a callee that is an empty function, an argument the callee never reads, a local array resized. They are listed in `EQUIVALENT_MUTANTS`.
  - All 9 commutative rewrites pass (no false failures). 81 mutants were excluded (67 identical bytes, 14 don't compile).
- The `/O1` recompiles were the real test, because they make the code differ the way a decompiled candidate would. They drove most of the design (78/300 failed at first):
  - **Argument counts can't come from the caller alone.** `/O1` cleans with `pop ecx; pop ecx`, defers one `add esp` over several calls, and interleaves an outer call's pushes with an inner call. Arity now comes from the callee: its `ret N`, and a stack-depth scan of which argument slots it reads, so dead arguments don't count. Indirect calls reuse the original's count call by call.
  - **CRT calls vs inline code.** `/O1` calls `memcpy`/`strcmp`/`sin` where `/O2` inlines them. The XBE's own CRT routines are found by **behaviour**: every function in the CRT region is run against memcpy/strcmp/floor test vectors. memcpy is at `0x345130`, strcmp at `0x346e5a`, strlen at `0x344fcd`, stricmp at `0x346fc5`, strncmp at `0x345840`, floor at `0x34557c` and ceil at `0x3481ba`. They run for real on both sides. Ones the XBE never has out of line (memset) run as Python semantics.
  - **Inline helpers.** `/O1` didn't inline an inline base constructor. Functions defined in our own object now execute in place instead of being "paired" to an unrelated original function.
  - **Locals passed by pointer** are part of a call: their contents are compared, over `sizeof(*param)`. The size comes from our callee declaration, via a `sizeof` probe compile for classes, and grows over words the function itself wrote (an array passed as `T*`). Only written bytes count. MSVC reuses dead parameter slots as locals, so uninitialised out-parameters differ between compiles.
  - Smaller items:
    - MSVC function-argument back-references count top-level argument types only. `msvc_demangle._Parser` also counts nested ones, which turned `RefObj*` arguments into `RefObj` by value.
    - `lea ecx, [ecx]` and `mov edi, edi` are padding, not register reads.
    - A function-pointer field call is not a virtual call: `ecx` is only a receiver when the target came from `[ecx]`'s vtable.
- **Unicorn gotchas:**
  - Loading a GDT for `fs:` (SEH frames) breaks plain `ret` unless SS/DS/ES also get flat descriptors.
  - After a lazy page map, an instruction re-executes, and the memory-write hook can miss the retried write. Writes are therefore found by diffing pages against their known initial contents, which also gives final-state rather than write-log semantics.
  - Writing EIP from a code hook works for redirecting calls to stub trampolines (`[fld qword [slot]]; ret N`).
- **Coverage needs help beyond random inputs.**
  - The fuzzer rotates memory modes: structured, small-number, pointer-graph (fields point back at the input objects), narrow (all pointers within 512 bytes), and random bytes.
  - It adds **input-to-state** directed inputs. Every `cmp`/`test` records where its operand was loaded from: memory, a stack argument, or a stub's return value. An uncovered branch side is then re-run with that source patched to the other operand's value. Coverage counts only inputs that ran to completion.
- Side finding: **23 of the 300 sampled matches carry address-encoded names that contradict the code** (`FUN_00019420` where the call goes to `0x1d04a0`; `thunk_FUN_002709b0` is the thunk at `0x269680`, not `0x2709b0`). These are propagated shapes, and `verify_relocs` accepts them because names are treated as invented. For a port they would link to the wrong function. `equiv.py` reports them as `level2.conflicts`.
- Not done yet: `submit_equiv` in the farm, captured xemu snapshots as inputs, and the A/B.

## 2026-10-10: Hybrid build in xemu (task 06, start of task 10)

- **Pipeline.** `tools/patch_xbe.py` links our objects into a new `.hybrid` section with equiv.py's own binding and linker, writes `jmp ours` at each original entry, and rebuilds the header: one section header is inserted (the header grows from `0xda4` to `0xde8` bytes, still below the first section at `0x1000`), and the digests become `SHA1(u32 size ‖ bytes)`. The disc image is packed once with a padded `default.xbe` (6 s, hard links), and later builds rewrite those 16 MB in place.
- **Driving xemu.** It takes `-config_path`/`-dvd_path` plus QEMU's `-qmp`, `-gdb`, `-S`, `-snapshot`. There is no `screendump`, so screenshots are `pmemsave` of the scan-out buffer at `NV_PCRTC_START` (`0xfd600800`); xemu writes rendered frames back to guest RAM. GDB breakpoints give coverage (a 14k-breakpoint build crawls, so use it on small sets). About 1 launch in 10 crashes xemu itself, and the monitor sometimes wedges; the harness retries and times out.
- **Determinism hooks** in `hybrid/hooks.cpp`: a frame counter and a virtual clock in `GameClock::Update`, input replay and record at `XInputGetState`, and checkpoints of the RNG, the boot step and GameClock. Gameplay randomness is one Marsaglia multiply-with-carry generator (`0x4e5ad0`), seeded from the clock only when a new game starts (`0x8669b`); that call becomes `mov eax, 0x1234`. Movies and loading screens don't tick the game loop, so a frame-keyed replay needs `no-fmv`, and START is tapped while the loop is stalled (a button held from the menu blocks the loading screen). The unmodified game is checkpoint-identical across runs through boot → title → menu → difficulty → load (frames 0–450). Past the load, the loop sometimes ticks thousands of times per second, which is the next thing to pin.
- **Result:** 14,614 functions patched (every byte-identical match, the 6 matches with local helpers, and about 170 equivalents) boot into the opening cutscene with checkpoints identical to the original's.
- **The bisect earned its keep:** 8 culprits in about 100 runs. Two were harness or data bugs: a hook bypassed by our copy of the function containing it, and a functions.csv extent 4 bytes short, which a noreturn-truncated "match" had copied. Six were equivalents that pass `equiv.py`. They fall into three classes the verifier can't see because callees are stubbed:
  - a `__security_check_cookie` declared `__cdecl` (equiv.py ignores the call on both sides);
  - **stack locals smaller than what the real callee writes** (a 32-byte object whose ctor writes 64; a `DWORD` handed to QueryPerformanceFrequency);
  - a vfunc declared void whose original returns a pointer (callers only reach it through the vtable, so nothing showed eax being used).
  
  Suggested equiv.py checks: compare a callee's known write extent with the size of our local; for functions only reached through vtables, compare eax whenever the original leaves a value there; check the cookie call's convention.

## 2026-10-11: Overnight burn-down, and the "research once, apply many" pattern

- **The pattern that paid off most: one deep investigation, then cheap application.** Per-function grinding on hard near-misses hits a wall where every attempt fails the same way. Thirteen near-misses all failed on one symptom (the vtable store sinking below the first member load, "vptr-sink"), and Sonnet batches had tried volatile stores, real destructors and forceinline helpers without success. One **Opus investigation** given the 13 cases together found three source recipes (a real `virtual ~T() throw()` with the cleanup in member destructors; `_ReadWriteBarrier()` right after the store, an intrinsic that emits no code under `/O2`; a volatile store paired with a volatile first load), matched all 13, wrote the recipes into the matching brief, and counted ~670 unmatched functions with the same opening. Then:
  - **Sonnet batches** of 30 with the recipe in their brief matched 39/40, 90/90, then 20–29/30 as the easy template families ran out: ~575 functions.
  - **Scripts** applied it without any model: `tools/fix_vptr.py` (insert the barrier into saved farm attempts) found 44; `tools/clone_matches.py` (compile a matched function's source against unmatched functions with the same code shape, renaming moved symbols) found 78.
  - Lesson: when misses cluster on one symptom, spend one strong-model investigation on the cluster, not more attempts per function. Write the result into the brief and the farm prompt, then scale with cheaper models and scripts.
- **Same shape, smaller:** a batch noticed most "0.99" farm attempts were byte-exact but failed `verify_relocs` because packets label both `operator delete` (0x8d330) and `operator delete[]` (0x8d340) as `thunk_FUN_00267090`; `tools/fix_relocs.py` splits such names per target.
- **Overnight numbers (Claude Max, Sonnet subagents ~5 in parallel, plus scripts):** verified source went from 24.8% to ~30% of game-code bytes. Byte-matched +~750 functions; proven equivalent from 263 to ~600, mostly from the port-priority list, ~18/20 per equivalence batch.
- **Portability cleanup:** 909 older matches wrote data addresses as integers (`p->vt = 0x413fb0`). The bytes match, so neither check noticed, but the code can't be relocated for a port. `tools/fix_literals.py` rewrote 860 of them as `(int)DAT_xxxxxxxx` with extern declarations, keeping a rewrite only if compare and `verify_relocs` still pass with each symbol at the same address.
- **Checker round 2** (`tools/equiv.py`): it now catches undersized locals handed to callees (static scan of how far each callee writes through a pointer), void declarations where the original returns in eax, a `__cdecl` stack-cookie check, wrong callee pop counts and dropped arguments; self-recursion is stubbed on both sides. It rejected 23 of 463 equivalents on real bugs, including all five the hybrid-build bisect had found, and 2 more on the full re-check. The hybrid build had found what the unit checker couldn't, and the checker now catches that class.
- **Dead ends worth knowing:** register-choice-only diffs (MSVC keeping zero in a register, eax vs ecx for a temporary), the operand order inside an address (`[esi+eax]` vs `[eax+esi]`), caller-cleaned `this` calls, and noreturn tails ending in `int3`. About 113 such near-misses are queued for the permuter, and the next Opus investigation targets the register-choice cluster.
- **ulk-1 (our fine-tuned Qwen3.6-35B-A3B on mac2):** 0 matches in 37 functions on the rescue pile (functions the cloud models had given up on), best scores 0.94 and 0.78. Moved to small untried functions instead; also 0 of its first few, at about 2.5–3 min per function on the loaded machine. Too early to judge.
- **The function list was missing code (2026-10-11 afternoon).** About 20 byte-exact matches failed `verify_relocs` with `data_in_code`: they store a pointer to code (an element constructor passed to the vector-constructor helper, script callbacks) that `functions.csv` didn't list. Measuring coverage showed 14% of game `.text` (about 490 KB of non-padding bytes) sat outside every listed function. `CreateMissingFunctions.java` created about 17k functions at the starts of uncovered runs. Only **4,879 (164 KB) are referenced** (by a vtable or data pointer, an immediate, or a direct call). Those were added to the list, which unblocked all 8 parked matches with no change to the reference check. The other **12,447 have no reference anywhere**: dead code the linker kept (out-of-line inline functions). They're listed in `build/farm/dead-code.txt` and left out of the denominator, since the port doesn't need them. Game code is now 27,450 functions / 2.69 MB.

## 2026-10-12: The equivalence hard pile, "research once, apply many" again

- **The pile:** about 105 functions (127 log lines) that Sonnet equivalence batches had failed, skipped or seen demoted. One Opus pass re-ran every best attempt under checker round 3 at `--inputs 3000` and clustered the failures by root cause.
- **Most "checker bug" notes were source bugs.** Round 3 fixed the limits they blamed, and the failures that remained were ordinary mistakes:
  - calls evaluated inside another call's argument list (a 0-arg getter or virtual whose "extra" pushes belong to the next call; 6 functions);
  - swapped parameters, switch cases mapped off by one, NaN polarity;
  - a `__cdecl` cookie check, a byte loop where the original inlines `memcpy`, struct fields at the wrong offset.

  Fourteen now pass, including three that had been demoted from `equivalent/` (0x00277810, 0x00332310, 0x002699f0: real bugs a port would have shipped). The recipes are in the batch brief.
- **Payoff estimates** (unproven non-library functions with the same shape): about 65 with the args-around-a-call push pattern, 211 with a `/GS` cookie, 172 with `rep movs` copies, 184 with jump tables.
- **What's left is checker work**, ranked in [docs/tasks/equiv-round4.md](tasks/equiv-round4.md):
  - plant literal strings for `repe cmpsb`/`strcmp` compares (thin coverage; about 50 functions outside the pile);
  - keep fuzzed pointers off code (7 functions that each fail on 1 input in 3000);
  - treat both-sides-fault wild control flow as inconclusive (about 10);
  - well-formed rb-trees and two-load loop bounds (7);
  - float steering through math on stub results (7);
  - two precise fill bugs for by-value temporaries built at `esp` by stubbed copy constructors (5; 47 outside);
  - trace replay as a coverage source for teardown loops and thin coverage.

  28 entries are CRT, XAPI or caller-frame fragments: out of scope. x87 80-bit intermediates (3) stay hand work.

## 2026-10-11/12: How far to trust "equivalent"

- **Checker round 3 raised the yield.** Loop-bound repair, inputs steered through switch tables and float compares, caller-cleaned and pending-push calls, noreturn callees and per-call-site varargs took Sonnet equivalence batches from about 12–14 to 17–20 passes per 20. Re-running old attempts under the new checker promoted 85 more without any model work (30 from the low-coverage pile, 55 from failed batch attempts).
- **The default input count is not enough.** A full re-check of `equivalent/` at `--inputs 3000` (run on mac1) found **36 of 1,451 wrong** (2.5%): sign-flipped float arguments, missing writes, wrong returns. Every one reproduced locally. Promotion now re-runs each pass at 3,000 inputs and requires ≥75% branch coverage and ≥50 completed inputs. That independent re-check keeps rejecting about one agent pass per batch, either a mismatch the agent's run missed or coverage that only a lucky run reached (one agent reported 95/106 edges; the re-check got 33/106). Fix batches recovered 25 of the 36, plus 3 more from the hard pile.
- **Cloning spreads bugs as well as proofs.** `tools/clone_equivalent.py` lines up same-shaped functions instruction by instruction, renames the moved addresses and re-proves the copy; generators in `tools/equiv_gen/` produce template families (48 script-binding registrations in one pass). But 12 of the 36 wrong equivalents were clones of one source whose byte-copy loop differed from the original's `rep movs` when source and destination overlap. A clone is only as good as its template, which is one more reason for the 3,000-input bar.
- **Fuzzing can't see real game state, and trace replay does.** Stubbed callees return made-up values, coverage only has to reach 75%, and random inputs never look like real data (well-formed trees, real strings, plausible floats). Trace replay records function-entry state while the original game runs in xemu (gdbstub) and replays it through the original and our code. Each callee returns what it really returned. The first session (8.5 minutes of game time, 5,906 snapshots, 293 MB) replayed 172 equivalents: **168 agreed and 4 mismatched**, all of which had passed at 3,000 fuzzed inputs (a wrong float argument, a missing argument word, a wrong out-parameter write, a float off by one unit in the last place). So roughly 2% of fuzz-proven functions are still wrong. Equivalents are provisional until replayed. The plan is confidence tiers that decide what the hybrid build includes.
  - QEMU slows down roughly linearly with armed breakpoints (800 never-hit breakpoints made it 6× slower), so capture arms a rotating window of at most 96 functions.
  - xemu itself isn't deterministic, but capture doesn't need it: each snapshot is real state. Re-capturing from recorded input does need it, and the game only replays identically through the new-game load (frames 0–450); the loop runs away after that.
- **The permuter found nothing on what was left.** mac1 (10-core M1 Max) ran it at about 2,000 tries a minute (about 20× this loaded machine) over 70 near-misses the agents had given up on: 0 matches. Those near-misses are register-choice and operand-order differences, which a source permuter rarely fixes. mac1 is more useful running the 3,000-input promotion checks (`tools/equiv_batch.py`: a 20-function batch in about a minute) and full re-checks.
- **The ChatGPT lane ran dry.** It proved 276 equivalents and 40 matches in its first night on mid-size functions (median 147 bytes), at no cost on the subscription. It then produced nothing for a day: the ChatGPT usage window was exhausted (645 of 757 jobs never ran), and the ~110 that did run were the hard tail of the large-function queue. It now works the 100–300-byte slice from the top down while ulk-2 takes the small end. Its commits had been staging all of `matches/` and `equivalent/`, so they claimed other agents' files; lanes now stage only their own results. (One lane commit, feff2ce6, also swept every uncommitted file in the tree into history, including other sessions' work in progress; the cause is still unknown.)
- **Claude usage is now the constraint, not CPU.** With five agents running, both the 5-hour window and the weekly budget became binding, and the remaining functions are bigger (1 KB+, x87-heavy): batches now prove about 12–13 of 20, not 18, at more tokens each. Equivalence batches now run one at a time. Checker work that unblocks families (the round-4 proposals) and replay pay more per token than more batches.
- **Housekeeping lessons.** Don't delete untracked files without knowing where they came from. Kill only your own processes, by PID (an agent's broad `pkill -f equiv.py` may have killed another session's run). Agents that finished can wake up again when leftover background work completes, so stop them explicitly.
