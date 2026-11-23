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

## 2026-10-12: Trace-driven equivalence ("record once, replay every build")

Fuzzed equivalence let 36 of 1,451 functions through, which a 3000-input recheck later caught. Five more
broke the hybrid build outright. So equivalence now also runs against real game states.

- `tools/trace_capture.py` boots the original game in xemu over the GDB stub and drives it with a
  poll-keyed pad script into the junkyard tutorial. Each target function is co-simulated: its original
  bytes run in Unicorn, every page they touch is read from the paused game, and the game itself runs
  each callee. Its results, and its writes into the caller's frame, are recorded and fed back. Each
  capture ends with a self-check against the game's real return.
- `tools/equiv_replay.py` replays those calls on the original and on our object, using equiv.py's own
  `Run` and `compare_runs` (a new `level3_fn` hook in `verify`).
- `tools/equiv_confidence.py` turns the results into tiers. `patch_xbe.py`/`bisect_hybrid.py` filter
  and order by tier.

Lessons:
- **QEMU slows down linearly with breakpoints.** 800 armed but never hit made it 6x slower; 1,600 made it
  15x. Arming every function stalled the boot. A rotating window of 96 fixed it: a 30-minute session
  now captures 7,675 calls from 429 functions.
- **xemu's `g` packet** carries 9 extra control registers (fs_base … efer) before the x87 registers. It
  sends ST(i) relative to TOP, not the physical registers. Getting this wrong gave plausible but wrong
  float results that the end-of-call self-check could not see. A replay mismatch in 0x42680 exposed it,
  and the s1 capture was thrown away.
- **Frames differ.** The original side has to replay the game's exact frame, but ours has a different
  layout. Callee writes are therefore placed relative to the pointer argument they lie behind, and the
  original decides each placement for both sides. Our first replays produced several false failures
  (STACK_FILL against real bytes, a game return address landing in our argument slot) until this was
  symmetric.
- **Stack alignment.** Functions with `and esp, -8` lay out their frames by the entry esp, so Unicorn's
  entry esp takes the game's low 12 bits.

Results:
- The `exclude.txt` versions are caught for 4 of 5, each with the bisect's cause. That includes
  0x259610, never explained before: a local passed to 0x3c9ea7 differs.
- 0 false failures on 49 byte-identical controls.
- 360 equivalents are now replay-verified (tier 3).
- Three bugs the fuzzer passed: undersized locals in 0x2a9920 and 0x2b8b30, and a pop mismatch in
  0x293ef0.
- 1,233 equivalents were never reached by this script and stay fuzz-only.

## 2026-10-12/13: Determinism after the new-game load

- **The runaway was the opening movie.** After Normal is picked, the game enters `GS_FMV` and plays the
  opening Bink movie while the level loads. `no-fmv` only stubbed `QueueMovie`, and this movie starts another
  way. The FMV render presents nothing, so the vblank pacing in `SwapBuffers` never ran. The loop spun at
  ~1,000 updates a second until the movie ended in real time: 5,000–12,000 updates of a fixed 33 ms each, so
  every later frame number depended on the host. `no-fmv` now also reports a playing movie as finished, and
  `GS_FMV` lasts one frame. GDB breakpoints on the state change (`0x86400`) found the path. Watchpoints were
  unusable: xemu crawled.
- **Every other timer is virtual too (`vclock`).** Eight call sites of `QueryPerformanceCounter` (`rdtsc`) in
  core::/Pure3D timers now read the virtual clock. It stands still between game-loop updates: the loading
  screen loop runs a host-dependent number of times, and a clock that advanced per read there differed by
  ~30 reads between runs. Before the first update it advances 4 ms per main-thread read, so the copyright
  screen's 3 s wait still ends. Then it snaps to a fixed 300 s. The pad poll's rate limit had to go, since
  frozen time kept the press-START loop from ever reading the pad.
- **Halted dumps find leaks fast.** `g_hybrid.halt_frame` stops the game loop at an exact frame, so two runs
  can dump `.data`/`.bss` at the same frames and be diffed word by word. The first gameplay difference was
  the sound voice manager's per-category counters. Voice availability follows the emulated audio hardware in
  real time, and voice selection draws from the gameplay RNG (`0x964d0` from three sound functions), so the
  RNG drifted next. `sound-rng` gives the sound code its own MWC state and its own `rand()`.
- **Wide hashes can't be a pass/fail check.** `.data` holds heap and thread-stack pointers, and the layout
  differs between runs of different builds (and of the same build sometimes). Recordings therefore check the
  RNG, the camera position (the first useful player-position proxy: `*0x4e231c + 0x4c`), `GameClock` and the
  boot step.
- **Record mode:** `tools/hybrid_test.py record NAME` plays the unmodified game with only these hooks and saves
  pad changes keyed by pad poll, plus checkpoints. `replay` reproduces them, feeding recordings longer than
  the 8,192-entry ring over the GDB stub. The ring is safe to refill mid-run because game time is virtual. A
  script-driven recording replayed checkpoint-identical through all 15,182 frames.
- **Result:** the runs went from identical through frame 450 to identical through 7,700–19,900 frames
  (4–11 minutes of gameplay). One leak remains: a fully pinned pair parted at frame 8,760.

## 2026-10-09/13: Fine-tuning a local matcher (ulk-1, ulk-2)

- **Setup.** `ulk-N` is Qwen3.6-35B-A3B (35B parameters, 3B active per token) with a LoRA trained on our
  own verified farm output, using Unsloth's MLX backend on mac2 (M3 Max, 128 GB). `tools/export_dataset.py`
  turns farm transcripts and `matches/`/`equivalent/` into chat examples, `tools/train_sft_unsloth.py`
  trains, `tools/export_merged.py` merges and quantizes to 4-bit MLX (19 GB) for Unsloth Studio. The LoRA
  is rank 32 on attention, the linear-attention projections and the shared expert: 38M trainable parameters,
  0.11% of the model. Wrapping the 256 routed experts as well gives 2.5B parameters, 114 GB peak and 3×
  slower steps, so they stay frozen.
- **ulk-1** trained on every assistant turn of 4,238 farm transcripts (10,152 rows, one pass, 20 h). Training
  loss 0.34, validation loss 0.39 → 0.33. Test set (93 held-out functions, 8 attempts): **48**, against 42 for
  the base model. The gain was all in small functions: 64–127 bytes stayed at 1 of 14, the same as the base.
  On the rescue pile (functions cloud models had given up on) it matched 0 of 37.
- **ulk-2** changed the data, not the recipe:
  - train on the **final turn only** (the winning submission, with the earlier failed turns as context)
    instead of every turn, which had taught the early wrong guesses too;
  - read **every lane's transcript database**, not just the Oct 8 snapshot (+770 match transcripts);
  - add one-turn examples (packet in, code out) from `matches/` without a transcript. 16,253 files hold only
    6,082 distinct bodies (cloned and propagated matches), so they are deduped by normalized source;
  - add **equivalence** work (transcripts and `equivalent/` files) under the farm's equivalence system prompt,
    so the model sees 128–1023-byte functions at all and learns the two tasks as separate modes;
  - import an external MSVC 7.1 decomp (halo): 516 of ~2,000 functions survived. Each needed its
    declarations (a closure over types, prototypes and macros) to compile standalone and match, and static
    functions are unmatchable outside their file because MSVC gives them custom register conventions.

  7,045 rows, 2.27M answer tokens, two passes, 40 h (longer rows: 2.7 min/step against 1.9). Test set:
  **60/93** (ulk-1 48, base 42). It gained 13 functions and lost 1, 34 of the 60 matched on the first
  attempt, and its median output fell from 1,390 tokens to 790. 128–255-byte functions did not move
  (1 of 21, the same as ulk-1).
- **What worked:**
  - **Only verified data.** Every example is a byte-exact match or a proven equivalent, so the compiler is
    the data filter and nothing wrong gets in.
  - **More, different data beat more of the same.** ulk-2's +12 came from changing the data, not the recipe.
  - **Restarts over long chains.** ulk-1's matches level off after about 5 attempts (cumulative 21, 31, 40, 42,
    47, 47, 48, 48 over attempts 1–8). Two independent 4-attempt runs matched 50/93 together against 48 for
    one 8-attempt run, with only 29 in common. The easy-pile lane now uses 4 attempts.
  - **Fast and free.** Studio's MLX server batches: 105 tok/s for one stream, 221 total for 4, flat at 8.
    ulk-2 clears about **50 matches an hour** on small functions, and it matched 422 in its first day on
    the small-function lane. Those are in the training set for ulk-3.
- **What didn't:**
  - **Large functions are a capacity limit, not a data gap.** On 50 random unmatched 128–255-byte functions
    ulk-1 matched 1, with a median best score of 0.24. 3B active parameters doesn't seem to be enough, and
    ulk-2's extra data didn't change it.
  - **"Thinking effort" does nothing.** Qwen3.6's chat template only has thinking on/off, so the farm's
    low/high setting is ignored and the length of reasoning is learned from the data. 3,900 of 6,269
    transcripts (mostly GPT-6 Luna, which hides its reasoning) have no reasoning at all.
  - **The 8,192-token cap** (training rows and the endpoint's `maxTokens`) drops long conversations (145
    in ulk-2, mostly equivalence work), and the base model probably thought past it on the 12 test functions where it never submitted.
  - **ulk-2 never ran validation** (no eval lines in the log), so there is no validation curve and no way to
    pick a better checkpoint without benchmarking each one.
  - **Training loss isn't comparable between runs.** ulk-2's 0.24 against ulk-1's 0.34 mostly reflects
    easier rows (code-only answers, final turn only), not a better model. Only the fixed test set counts.
  - **Ops:** an expert-routing profile of Qwen3-Coder-Next ran for hours and saved nothing when interrupted
    (it now saves every 250 conversations). Studio binds its LAN address at launch, so mac2 changing IP
    (.33 → .209) silently broke the endpoint until Studio was restarted.
- **DeepSeek V4 Flash as the teacher.** On OpenRouter (284B parameters, 13B active) it matched **77/86** on
  the test set (ulk-2 53, ulk-1 41 on the same 86) and 4 of 12 128–255-byte functions (ulk-1 0), at about
  $0.01 per small function and $0.06 per mid-size one. antirez's ds4 engine runs a 2-bit build (81 GB) on
  mac2. It matched all 7 test functions it reached (cloud also 7/7), but at ~5–6 tok/s per session with 4
  sessions it takes about 5 minutes an attempt: roughly 14 matches an hour against ulk-2's 50. A mixed
  2-/4-bit build (98 GB, needs `iogpu.wired_limit_mb` raised) is downloaded but untested.
- **Plan:** ulk-2 burns down the small-function pile, local DeepSeek works what it leaves, and DeepSeek's
  verified matches (with its reasoning, which it doesn't hide) become ulk-3's main new data. ulk-3: rank 64,
  extra weight on 64–255-byte and multi-attempt examples, a 12k token cap, working validation. The goal is
  DeepSeek-level matching in a model that runs in 32–64 GB.

## 2026-10-14: Fixing the function list (fragments and truncated sizes)

`build/functions.csv` (Ghidra, plus `tools/fix_truncated_sizes.py`) still had two kinds of bad entry that could
never be matched or proven: **truncated** functions (the recorded size stops at an early `ret`, after a `cmp` whose
`jcc` Ghidra split off, or at a `call` it thought never returns) and the **fragments** that the lost tails turned
into (no callers, running in the parent's frame; some "vtable slots" that were really the dword after a vtable, i.e.
starts in the middle of an instruction).

`tools/fix_function_list.py` is the deterministic, re-runnable fix. For every listed function it walks the real
control-flow graph from the entry (fall-through, conditional jumps, in-function jumps, jump tables; calls are not
followed) and takes the furthest reached instruction as the end. An edge that leaves the recorded range is followed
unless it lands on a function start that something else calls or points at, or that two other functions jump to
(a shared tail). Entries that start inside the corrected extent are folded into the parent; an entry that is
independently referenced is folded only when it starts mid-instruction or the parent executes straight into it from
a non-16-aligned start, otherwise the change is reported as a conflict and not applied. It repeats to a fixed point.
The log (`build/function-list-fixes.json`, not committed) has each change with evidence; `--sources NEW.csv` re-runs
`tools/compare.py` (matches) and a quick local `tools/equiv.py` (equivalent) at the new sizes for every affected
address.

Result: 34 functions extended, 17 fragments removed (30,305 -> 30,288 entries), 8 conflicts left alone (all libc/XAPI
hand-written assembly with a real helper in the middle). Game-code functions 27,450 -> 27,435 (+760 bytes of body
that were previously unaccounted for, 2,745,084 -> 2,745,844 B), unverified 3,604 -> 3,590. One matched source fell
out: `matches/0x00288df0.cpp` matched the 101-byte tail of 0x00288de0 (a 117-byte function), not a function of its
own. All of the listed known fragments and truncated functions were found except `_memmove` 0x00345130, whose CFG
ends exactly at its recorded size (its linear decode only fails because of an inline jump table). The tool also
found the same "call to a function that does return, then the rest of the body" truncation in
`ShadowMeshLoader::vfunc_5` 0x002b6170, 0x002b6930, 0x002c2ab0 (28 bytes each, all with equivalents) and size-1
entries at 0x00050c00, 0x00110100, 0x00327860, plus a few XGRPH/DSOUND functions outside game code. Eight
`equivalent/` sources are for extended parents (0x00027fc0, 0x00028050, 0x000a6400, 0x002343e0, 0x00236ac0,
0x002b6170, 0x002b6930, 0x002c2ab0): locally they still pass at the new size, but they were proven against the
truncated size, so they need the 3000-input re-check on the checker box.

### 2026-10-14 (later): second function-list pass, unlisted code between functions

`tools/fix_function_list.py --pass2` classifies every gap between listed functions that holds more than 0xCC padding
(6,949 gaps, 720 KB): it cuts each gap into units by walking the control flow from the first real byte, recognises jump
tables, index tables and alignment NOPs (`mov edi,edi`, `lea ecx,[ecx]`, `nop` runs), and sorts the code units by who
refers to them (call/jmp from listed code or from a referenced unit, data-section dword pointers such as vtables and
unwind maps, pushed or loaded code addresses). Result: class a (a parent's own flow reaches the bytes) is empty, so no
parent needed extending; class b (separate code with its own entry) is 550 new functions (30,288 -> 30,838 entries);
class c is the rest, recorded in the log. Of the 550, 42 are game code (3,229 bytes: 16 audio `Seq*` vtable slots
named from RTTI, 13 tail-jump targets, 7 callback addresses), 204 are EH frame-handler thunks and unwind funclets
(named `__ehhandler_*` / `__unwindfunclet_*`, so progress counts leave them out, like the 650 existing ones in
`.text$x`), and 304 are library code (BINK, D3D, XGRPH, DSOUND, XPP, LIBCMT/XAPILIB). The bulk of class c is 13,995
well-formed code bodies (342 KB) that nothing in the XBE refers to: dead COMDAT copies of small inline methods such as
vector dot and cross products. They are not listed because there is no evidence they are functions anyone calls; if
they should be matched anyway the log has their addresses. The rest of class c is 340 jump tables, 82 index tables,
556 NOP runs and 61 blobs (BINK data, SEH tails). 21 SEH `__finally` tails that fall into a listed function with its
own entry are logged as conflicts and left alone. No `matches/` or `equivalent/` file is affected (no sizes changed, no
source exists at a new address); the eight pass-1 equivalents still pass locally at 400 inputs. Game functions
27,435 -> 27,477, unverified 3,526 -> 3,568 (279,038 -> 282,267 bytes); the new game functions are queued
smallest-first in `build/farm/new-functions.txt`.

## cl12: declaration-arity check (checker round 23) and the Wine promotion gate (2026-10-23)

MSVC mode passed sources whose call declarations give a callee the wrong number of stack words when the pushed bytes
coincide (cl11's six). `equiv.py` now reports `decl_arity` at level 2 in MSVC mode: the callee's real arity from the XBE
(`ret N`; a cdecl callee's highest argument read and the fewest words pending at the original's call sites; a function
pointer some site calls with nothing pending) against the words our declaration passes (decoration, sizeof probe, clang's
call sites for C names). Report only; `--strict-decl` fails it. `tools/decl_lint.py` ran it over all 27,480 sources: 31
flagged (10 `equivalent/`, 21 `matches/`), all correct by hand; 11 of them are adjustor thunks to deleting destructors
whose flags word the class leaves undeclared (harmless), 3 are tail calls that clang -O0 turns into real calls, the rest
getters handed a later call's word or callees reading more than we pass (`build/cl12/flagged.jsonl`). Promotion into
`equivalent/` now also needs `equiv.py --wine` at 600 inputs (`tools/wine_gate.py`; `--no-wine-gate` without LLVM).
A `--wine` sweep at 60 inputs over all of `equivalent/` and the float-using `matches/` (7,466 sources): 6,934 equivalent,
532 not, 154 of them already on nf3's list; 218 of the new ones are one checker artefact (clang emits no scalar deleting
destructor for a source that defines only the destructor). Categories in `build/cl12/wine-sweep-summary.md`, for nf4.

## data2: the source offsets refreshed, drift1's 15 review items decided (2026-11-12)

config/data-source-offsets.json now comes from the merged tree (446 offsets). Most of what it changes is right: 8-byte
.bss pairs that code reads as one 64-bit value become one item. But an offset records how *our* source spells an
address, so some merges are artefacts of the source: a loop's end pointer (`DAT_00528388 + 16` swallowed a separate
global), one struct overlaid on separate noise tables (`DAT_0056b7c0 + 14392`), neighbouring arrays written as offsets
of the first. Those are pinned in config/data-items.json with their reasons. A word that gets folded into its
neighbour loses its header declaration, so the 9 TUs that named one now spell it `(*(T*)((char*)&DAT_x + 4))`. That
changed the code hash of 8 equivalents. All 8 were re-proved (MSVC at 3,000 inputs, `--wine`); `--x64` passes for 6, fails for 0x00043ae0 exactly as at HEAD, and cannot run 0x00088020 (the main loop: no 32-bit input completes). The matches still match. PathAction's 0x0011e4a0
declares six such words itself (C++ linkage). It still compiles and the Wine link retargets the names, but natively
they become interior names (unbound) until it is rewritten. The inventory's code operands skip base+displacement
(`byte [eax + 0x426830]`), so luaO_log2's table had no reference. The type votes feed back through config/data.json:
always regenerate from the committed file. Details in docs/data.md "Reproducing".

## pure3d::NonCopyable's word at 4 is the reference count; MS-ABI base padding (x64t7, 2026-11-12)

NonCopyable's AddRef 0x00018b30 is `inc dword [ecx+4]` and Release 0x00018b40 decrements it and deletes below 1;
constructors store 0 there. gen's `hulk_intptr f_04` came from one false "pointer pun": CSPListener 0x001db1c0, where
NonCopyable is the second base (at 4) and the store is that base's vftable pointer. Natively the type alone doesn't
move anything: the MS ABI (the native front end's) never reuses a base's tail padding, so `{vftable; int}` is 16
bytes and a descendant's first word sits at 0x10, against 0x0c in the hand-written flat views. The tree now packs
NonCopyable (and local stand-ins) to 4 natively (HULK_REFCOUNT_PACK) so descendants follow the count as in the
original. content::LoadObject (687 classes) has the same shape and is still unpacked.

MSVC 7.1 codegen of 0x001a9b10 and 0x000b86b0 changes (two loads swap) when any extern declaration is added to
include/decls/data/records.h: every records.h addition re-proves them on MSVC.

## data3: the inventory reads base-register operands; one spelling of a type (2026-11-12)

`movzx eax, byte [eax + 0x426830]` is how MSVC indexes a byte table, and the inventory used to skip every memory
operand with a base register, so such tables had no code reference unless a source named them. Taking them adds 390
operands, but three kinds of them must not carve on their own. The D3D library writes NV2A's PGRAPH registers through
a register holding the MMIO base (`mov [esi + 0x400750], eax` is 0xfd400750): 110 operands that land on game strings
in .rdata's first 8 KB; they are dropped (library code, 0x400000-0x401fff only). A base register often selects a
field, not an element: `[eax + 0x4399a0]` .. `[eax + 0x4399a7]` are the 8 bytes of one element of a Bink table, and
taken as starts they cut it into 8 one-byte items; a displacement under 16 bytes after another of the same function
is now a field (it counts for the item, it doesn't start one). And the access width through a base register is a
field's width, so it no longer replaces a type or size the sources declare (`Entry_32a260[]` stays, not
`unsigned char[128]`). What remains is good evidence: three struct tables get their real extent (TblEntry 68 x 20 B,
Lookup_d3f10 31 x 8 B, ModeEntry 112 B), 16 items get the owner whose code reads them, and two regions that guesses
gave to lua/lbaselib.cpp and pure3d/Image32.cpp are Bink's (its error strings, its byte tables). The TblEntry table is
read only by unk_0bc1e0 but sits in unk_0b4cf0's mission-table run and shares its strings: pinned to unk_0b4cf0, and
a pinned owner now takes the items only it references along.

The `unsigned int char` spelling was fixed in decl_type a day earlier but lived on: the type votes read
config/data.json, so the old spelling voted for itself (26 items, plus 49 spelled `unsigned int __int64`,
`unsigned int short`, `unsigned int long long`). One function now spells every type, on the way in from the sources
and from config/data.json. data_gen then sees primitive types it didn't before: 33 eight-byte .bss keys become
`unsigned __int64` (were `unsigned char[8]`). The header change moves MSVC 7.1's scheduling of 0x001a9b10 (two loads
swap, as x64t7 saw for records.h additions): re-proved on MSVC; its clang code is unchanged.

## and1 (2026-11-12): the Android image runs to macOS's stop

`libmain.so` with static SDL3 (NDK) and FFmpeg (NDK, plain sonames) runs in the emulator, both under adb and as a
debug APK through SDLActivity (`tools/android_apk.py`). It stops where macOS stops: ParticleAllocator, 0x002ac4a0.

Three Android-only findings:
- SDL's Android core needs its video driver linked, even headless.
- A plain process that marks SDL's main ready crashes in `SDL_GetAndroidPackageName` (no JavaVM) unless `SDL_APP_ID`
  is set.
- Files adb's shell writes into `Android/data/<pkg>` are unreadable to the app. The scripted install copies the disc
  into the app's internal storage with `run-as`.

Details: docs/native-android.md section 16.

## x64eq (2026-11-13): the whole tree through --x64

Every block's x86-64 object against its own 32-bit clang object, once (27,438 blocks, 200 inputs each, ~3 hours of
queue time at low priority): 23,240 equivalent, 2,393 differ, 1,665 unsupported, 132 inconclusive
(docs/native-build.md "The tree-wide 64-bit equivalence sweep").

- The commonest real 64-bit bug is a byte offset of the 32-bit layout, `(char*)P + N`. Where N is a named field's
  start the rewrite is mechanical and byte-identical on MSVC (`(char*)&P->field`): 297 sites, 129 blocks newly
  equivalent. Five times as many sites point into pads or past the end of stub classes; those need records.
- Several "differs" were the checker: a deleting destructor the native build instantiates was defined twice; an int
  whose untouched bytes happened to look like a 32-bit heap address read as a truncated pointer; adjustor thunks were
  never paired; `_chkstk` had no signature.
- 0x001a9b10's `--wine` failure was a stale frame slot: the callee only writes the out-parameter, but callee_reads
  let a `ret 8` callee's escape window (16 words behind an argument whose address it takes) speak for the caller's
  own arguments. With that fixed the run reached a real difference behind it: the original rounds a span to float.
- Pointer arithmetic that wraps at 2^32 shows up wherever the fuzzer picks a huge count; `wild64` now names it.

## unb4: header-less TUs and HULK_PTR64; common.h moves MSVC code (2026-11-13)

`HULK_PTR64` is defined only by compat/ptr.h. A TU that includes no tree header (many `.iso_` TUs: "tree_prelude.h:
not needed") never saw it, so its `#if defined(HULK_PTR64)` branches compiled the 32-bit way on the native targets,
silently. x64t5's game-item constructions for 0x0035fb20 / 0x00360870 were dead (and would not have compiled). The new
native-link gate on local data stand-ins (tools/native_local_data.py) found it: the stand-ins were still defined under
their 32-bit names. compat/native.h, force-included by every clang build, now includes ptr.h. A scan of the 343 TUs
that test the macro found only those two.

MSVC 7.1's code for some functions depends on how many names a shared header declares, not only on what they use.
Adding five free-function declarations to include/common.h changed the code of two equivalents in
src/engine/physics/unk_2e6780.cpp (0x002e9c60, 0x002ea3c0, zlib / libpng), which use none of them. Adding two members
to an existing struct there changed nothing. x64t7 saw the same for records.h (0x001a9b10, 0x000b86b0). A change to a
header every TU includes needs the whole tree's verification (a Wine proof build's materialize stage does it), not
only the edited TUs'. Declarations a batch needs in a few TUs are safer TU-local.

## 2026-11-13 linux1: the x86-64 Linux image runs (Rosetta VM); a 2-byte item read as 3

- `hulk-linux` runs in a Lima / vz arm64 Debian 12 VM through Rosetta for Linux (docs/native-linux.md,
  tests/linux/vm_run.sh). After one fix it stops where Android and macOS stop (same snapshot).
- The fix: FUN_00277190 read `"D:"`'s terminator as `DAT_0042b50c + 2`, a cross-item read. The XBE's byte there is
  the next item (`s_empty_0042b50e`), but native links place items independently: Linux's link put `'X'` there and
  the drive check took another path. Cross-item reads written as `ITEM + k` past an item's inventory size are latent
  on every native target (verify_relocs passes them: the address is right); a scan for reads past an item's
  inventory size would find any others.
- x86-64 specific: the Windows x64 front end omits frame pointers (the arm64 one keeps them), so the native reports
  had no backtrace; native_elf now asks for them on linux-x64. Rosetta's `ROSETTA_DEBUGSERVER_PORT` segfaults in the
  guest; qemu-user's gdb stub works.

## 2026-11-13 gate1: 64-bit equivalence as a regression gate

- `tools/x64_gate.py` (hooked as `tree_tu.py verify ... --x64`): `equiv.py --x64` on the blocks whose code changed,
  failing on a block newly in layout / ptrtrunc / crash64; config/x64-baseline.json (address -> class) holds the known
  ones and only shrinks unless `accept --why`. Change detection by a per-block key over both clang objects' code hashes
  is precise: a header commit that keys all 2,675 TUs finds only the blocks whose code moved (0 for data3's, 64 for
  typ1's audio records, 229 for x64t8's loader records).
- Replayed over the 16 commits since x64eq's sweep: one would have failed, x64t8's d6321f64d (0x002656b0's
  `bufferEnd`, possibly the checker typing two allocations of one allocator alike; 0x0023a550, equivalent again later).
  typ1's ea6ce3693 made 35 baseline blocks equivalent; 1,166 -> 1,128.
- A baseline block that changes to another failure class is usually the same bug seen first elsewhere (a crash through
  a garbage pointer becomes a garbage `float` return or `wild64`): only `equivalent` takes a block out.
- rev1's argpop follow-ups: `argbound` (a `ret N` callee addressing past its arguments is unknown), a `_wrong` case for
  0x001a9b10, rawint's heap spans enforced.

## unb5: stub classes derived from include/gen's classes (2026-11-13)

A TU's stub class can derive from the include/gen class it stands for with no change to MSVC 7.1's code: the
implicit constructor of the include/gen class inlines and its vptr store is dead (MSVC drops it), so the derived
stub's constructor still calls the out-of-line base constructor and stores one vptr. Two costs: where the stub has
member objects with destructors, the base's virtual destructor adds an EH frame (17 TUs left for this), and natively the
include/gen classes' destructors become names of their own (the game inlines them into the scalar deleting
destructors). Track batch: 68 TUs, macOS -52 net (79 constructors and 52 placeholder virtuals gone; 78 destructors
and 12 shared slot names new). A field that include/gen types `void*` where the stub dereferences a typed pointer
blocks fight::Action's whole family: the records come first there.

## 2026-11-13 typ1: byte offsets on records (audio, core, unlockables, FE actions)

- A local stub's field is checked against the stub's own layout, so a cast to the record at the site leaves `--x64`
  differing: the stub itself must carry the record's words (members past the vftable, or a non-polymorphic "words"
  base, which both compilers place right after the vftable).
- MSVC 7.1 moves a polymorphic class's first member to +8 when any member is 8-aligned. A `static_cast` / reference
  cast of `this` to a second base still tests for null; a constant base offset (`static_cast<B*>((D*)0x1000) - 0x1000`)
  does not.
- 0x001a9b10 (EffectAction.new_throw.cpp): with a gen/core.h change, the Wine build's tree check (materialize) gives
  it another MSVC hash than `tree_tu verify` does over the same files. Open (docs/native-build.md, typ1).
- 654 blocks: 60 became equivalent (layout 57 -> 6); 1,529 byte-offset sites in 389 classes remain catalogued in
  build/typ1/cls.jsonl.
- **gen1 (2026-11-13): include/gen/ is hand-maintained source.** The loss check (regenerating from 9bbef387f's inputs) found nothing in the generator's inputs missing from the committed headers; all 219 differing lines were later hand edits. Evidence files deleted, `gen_headers.py --probe` kept as the checker with a size ratchet (config/gen-sizes.json). Details: docs/native-build.md "gen1", docs/headers.md.

## 2026-11-13 hash3: the 0x001a9b10 "hash disagreement" (verify vs materialize)

- Not two checkers disagreeing. typ1's 28 `tree_tu.py verify` queue jobs (76770-77953) shipped only `job/tus.txt`, so
  they checked `git archive HEAD`, not the parked gen/core.h change; the Wine build's materialize had the files and was
  right. Reproduced uncached: the parked core.h gives 76aee2ab8faa in both the checkout layout and materialize's
  build/tree layout; a whole-tree verify with the parked files shipped (78111-78118) fails on exactly that block.
- MSVC 7.1's code for a few functions follows the number of symbols declared before them in the TU: three `extern int`
  lines before 0x001a9b10 swap two spill reloads (N = 3 and 19..48 flip, 4..18 don't). Names, name lengths, macros,
  comments, paths, the environment and declarations after the function change nothing: deterministic per text, so the
  code hashes and caches are sound. Its hash has alternated edf80f70a210 <-> 76aee2ab8faa four times (d6b934876,
  6d0429829, 717b73606, f22370845), each re-proved.
- Sweep (N dummy declarations at the top of every TU): six equivalent blocks move, 0x001a9b10, 0x000b86b0, 0x000ba040,
  0x00027930, 0x002e9c60, 0x002ea3c0; no matches block.
- `verify` now prints `inputs` digests (TU texts, reachable headers); `tree_tu.py inputs` gives them locally.

## 2026-11-13 scan1: accesses past the end of a data item

- `tools/data_overreach.py` reads constant offsets from the MSVC objects' relocation addends and widths from the
  instructions; an access must end inside its config/data.json item. First run: 25 reported, all real (1 read of the
  next item, 5 mis-sized items), 15 benign (loop bounds at a field of one past the end, negative index constants).
- A data2 pin that keeps an item small while the source overlays a bigger structure on it (0x0056b7c0, 0x004e3768,
  0x004cc254) is a native bug, not a spelling choice: the scan reports every such pin's users.
- Words whose bytes read as text hide pointer tables (0x0048f6d0 was a 4-byte "string"); its neighbours 0x0048f6a4
  (last word), 0x0048f6b4 (`int[6]`), 0x0048f6cc and 0x0048f6e0 hold string addresses as integers too (left: data_ptrs).

## 2026-11-13 x64t9: evaluation order in `p->f(g(x))`, memcmp, per-site casts
- MSVC 7.1 evaluates a member call's arguments before loading the object expression; clang (C++17) loads the object
  first. `e0->FUN_001fc8c0(FUN_0027b020(pt))` (PathAction 0x0011e4a0) therefore read `this->e0` on the other side of an
  opaque call: the --wine failure at input 474. Where the object is a member load and an argument is a call, write the
  argument into a local first (the original's order).
- equiv.py: `memcmp` runs as an intrinsic (MSVC inlines it; clang calls it). equiv64: one allocator cast to two types in
  one body types each allocation by its own call site (0x002656b0's false layout entry).

## unb6 (2026-11-13): implicit destructors, Track's and Condition's +8 words

- include/gen declared `virtual ~C();` for 461 fight classes whose destructor no source defines; the game inlines
  them into the scalar deleting destructors, so the declarations made 78+ unbindable `~C` names natively. Dropped:
  the destructors are implicit (8e982dfec). fight::Track / Condition / Param's destructors are defined at
  0x00236d60 / 0x002345b0 / 0x00234210 under their gen names (`throw()` on Track's and Condition's: the game has no
  unwind there).
- MSVC 7.1 drops the derived vftable store in a `??_G` built from `~C() {}` (empty, inline, implicit or
  out-of-line) when the base destructor is called right after; the game's 36-byte Track `??_G`s keep it. The tree
  keeps those blocks as stubs.
- fight::Track's +8 word in the base, packed natively (HULK_REFCOUNT_PACK); Condition's +8 is its owner pointer
  (constructor argument). Dropping ParamValue's undeclared destructors changes 970 blocks' MSVC code: not done.

## 2026-11-13 tool2: verify checks the header probe, unshipped edits and data overreach

- A queue job's workspace has no git. Before this, `verify --changed-since REF` there found no TUs and passed. The x64
  gate could not run in a job at all. Both now take the job's base commit as the only REF.
- `jobq.py submit --dirty` skips files over 8 MB, and config/data.json (8.75 MB) is one of them: a dirty inventory
  never travelled with `--dirty`. The submit guard names it.
- The auto-mode permission classifier refused an agent's `gen_headers.py --probe` in the shared checkout because the
  agent had read the tool's pre-gen1 docstring (it regenerated include/gen/). The probe only ever wrote to a temp
  dir; now that dir is under build/tmp/ and the docstring says so.

## 2026-11-13 x64t10-eq: two fills in one directed input (strterm), overruns past the return address (smasharg)
- `n = len byte; read(name, n); name[n] = 0`: the terminator store replaced the stub fill of a word of the name, so
  equiv.py's string plant (the literal as the stub's fill) no longer saw a filled buffer and never queued the compare
  (0x002f4eb0's unit names: 22/30). `strterm` keeps the replaced word's fill and the store index's source, and the
  plant sets both: the literal and the length that puts the terminator right after it. 0x002f4eb0: 30/30.
- With the compares reached, `--wine` at 3,000 inputs met input 907: `tag[n] = 0` with n = 0xf6 writes past the
  original's return address into an argument word, and into clang's saved ebp. `smasharg` extends round 8's smash rule
  (an indexed store from a frame local landing in the incoming arguments is an overrun: inconclusive when the sides
  differ).

## 2026-11-13 del1: matches/ and equivalent/ removed (merge-once (d)), farm/ archived
- The Wine build's binding map read the per-function sources for every equivalent function (equiv.py level 2 on
  `equivalent/0xADDR.cpp` with the tree object) and for native9's same-symbol check: deleting them unretargeted would
  have unbound the equivalents' callees (the first control, run with the new SRC_DIRS, hung at frame 0). Retargeted to
  the unit text (TU shared part + block) in equiv.py's standalone mode: 5,099 / 5,099 maps identical. equiv.py's tree
  mode is not a substitute there: it drops `how: name` bindings of the TU's neighbours by design (39 of 508 differed).
- `wine_build_job.py submit` ships the checkout's tools/wine_build_run.py: a control of an older commit needs that
  commit's build tools at submit.
- docs/merge-once.md "Step (d)", docs/msvc71-pitfalls.md.

## 2026-11-13 dtor1: the game was built without C++ exceptions (/GX-)

- No game function has an exception frame (`mov eax, fs:[0]`): 0 of 18,768; the six in the XBE are LIBCMT's. The tree
  compiles with /GX, and that is what the `throw()` / `__declspec(nothrow)` spellings, the stub `??_G` blocks and the
  base-less stub classes were working around.
- MSVC 7.1 /GX never inlines a destructor that calls a base destructor into `??_G`; /GX- does, with the vftable store,
  so `C::~C() { delete[] f_10; }` is the game's 50-byte `??_G`. /GX- also lets a stub constructor `X() : C(0)` on a
  class with a virtual destructor inline into its factory again (unb6's 9 Condition TUs).
- Whole tree with /GX-: 1,886 of 27,438 blocks differ, 1,873 of them scalar deleting destructors written for /GX
  (mostly the fight parameter templates' `template <> ParamX<T>::~ParamX() {}`; the game's are implicit). Per-TU
  `// cl-flags: /GX-` is used where a TU's blocks all match with it; the tree-wide default needs those destructors
  migrated first.

## x64t10 (2026-11-13): InstanceDrive's record, member-object locks, the drive wait

- clang calls a virtual of a member object (`p->sub.A()`, `guard.enter()`) directly, MSVC 7.1 through the vftable:
  natively the call reaches the view class's undefined stub. Hold such a lock as its vftable word (`void* sub`) and
  call `((T*)&p->sub)->A()`; the MSVC bytes do not change.
- A local polymorphic view that constructs a game object (0x00277110) emits its own vftables natively: store the
  game's by address after the members' own stores (the code still MATCHes).
- InstanceDrive::vfunc_21 read the request count through a 12-byte pad: natively the drive pointer's upper half, so
  vfunc_22's wait never ended (a hang with no crash: lldb on our binary with a breakpoint on the sleep's Nth hit gave
  the caller).
- Wine proofs at an older base (1c5f08c59) hung at frame 0 on studio after del1's commits whether changed or not
  (79145, 79236, the unchanged control 79239): rebase the control on the current HEAD.

## 2026-11-13 gx1: /GX- is the tree's default; native builds without exceptions
- compare.py DEFAULT_FLAGS /GX-; `// cl-flags: /GX` on the 454 TUs whose scalar deleting destructors are written for
  /GX (their true form is the constructing code: D18), on the two dynamic_initializers TUs (unwind funclets of
  library code built with exceptions) and on 0x00148f40's iso TU. Native compiles and equiv64 use -fno-exceptions.
- MSVC 7.1 emits a vftable, and so an implicit `??_G`, only where a constructor is compiled: not for an explicit
  instantiation, not for a constructor used only in an unused function (build/gx1/exp/).
- The Wine build keeps -fexceptions: 72 equivalents' clang code changes without it, and 10 of them do not re-prove
  `--wine` under the current checker (they fail the same way on HEAD). The throw()/nothrow clean-up waits with it.
- D19: Condition's five shared slots now defined on include/gen's classes and bound natively.

## 2026-11-13 x64t11: macOS start-up through the platform set-up; a data item too small natively

- A 28-byte .bss item (DAT_004e2210, CStaticAllocator) whose class is 0x30 bytes natively: its start-up constructor
  wrote past it into the pddi device slot the linker placed next, and the crash came minutes later in 0x002c3230 as a
  zeroed device. Overruns of data items by native class sizes do not show in the 32-bit overreach scan: a records.h
  type is the fix (natively sized item).
- The controller subsystem was 32-bit throughout (pads at a 0x4a0 stride in a dozen local views, names and callbacks
  as ints, gen's classes with byte pads): records (decls/controller_xbox.h) held by gen's classes, every view checked
  against them (`HULK_CTL_SAME`). The replay pin 0x00269170 needed only its shared view's pad sized by the record.
- Declaration-count flips follow the header state, not the change: of the six known blocks, 0x00027930 took a new MSVC
  hash with the final headers while 0x002e9c60 / 0x002ea3c0 / 0x000b86b0 / 0x001a9b10 flipped and flipped back on the
  way (record a hash only from a run on the final headers).
- macOS start-up now stops at the language file: its open fails and the drive's error callback (0x00272df0) calls a
  null slot.

## 2026-11-14 chk1: a masked difference must be one the undefined behaviour explains (rev2 follow-through)
- rev2 showed `smasharg` (and round 8's smash, and `bool_ub`) set aside ANY difference on a flagged input: mutants of
  0x002f4eb0 with a different call sequence (M1/M2) or a wrong constant (M3) passed `--wine` at 3,000. f4a5e5df8,
  bba347f96, 8e8c9f921: smash explains only registers restored from overwritten slots, ours going wild, and differences
  after a side reads back a word its overrun replaced (`xlocal`, `smash_read`); `bool_ub` reruns ours with the bytes
  read as true (normalised / raw) and false; `x87_range`/`ro_write`/`frame_escape`/`copy_overlap` never explain a call
  made before the event; inconclusive inputs no longer count for coverage (`maskedges`). `level3.unexplained`.
- Pitfalls met: writing EFLAGS from a Unicorn code hook does not reach its lazily computed flags (set the operand
  before the instruction instead); clang's `!b` (`xor al, 0xff; and al, 1`) looked like a non-bool read on every input.
- Audit (all 5,099 equivalent blocks, 3,000 inputs, MSVC and --wine, then the non-passing ones re-run with the pre-chk1
  checker on the same HEAD): most non-passing blocks fail with the old checker too (51 MSVC, 226 --wine on HEAD of
  2026-11-14). Due to chk1: coverage once only inconclusive inputs reached (often `code_write` inputs: a fuzzed
  pointer storing into .text), 9 MSVC / 10 --wine; differences the detected bool sites don't explain, 15 --wine
  (0x00224540: a float difference, the store of `*result` keeps its old value where the original writes -inf);
  6 new differing inputs found by the changed exploration; 2 refused frame_escape/smash masks; a few time-budget
  shortfalls. Lists in the chk1 hand-back.

## 2026-11-14 gx2: the Wine build without exceptions (D22, D23); the parameter templates constructed for real (D18)
- D22: clang_probe COMMON is -fno-exceptions for every build; 585 `__declspec(nothrow)` and 1,091 `throw()` removed
  from 280 /GX- TUs (no MSVC code change). 72 equivalents' clang code changed: 60 re-prove `--wine` at 3,000, 12 do not
  and fail the same way with exceptions on (chk1's masks; 4 of them newly since gx1's runs). Recording no hash for them
  left `materialize` failing (`code_changed`), so their 12 TUs keep exceptions in the Wine build through a new
  `// clang-flags: -fexceptions -fcxx-exceptions` line (native builds ignore it), as gx1's `/GX` kept 0x00148f40's TU.
- The ddtor regress cases broke with the /GX- default because their source is a /GX source (an empty user destructor
  the /GX- MSVC object inlines into the `??_G`): they say `// cl-flags: /GX`, like the tree TUs they mirror.
- D18's form: `new ParamX<T>(name, &T::Setter)` through the global operator new, out-of-line `ParamValueX(const char*)`
  (each the inlined `ParamValue(name)`: two vftable stores around the name id's constructor) and an inline template
  constructor storing the setter word reproduce the registrations byte for byte (10 equivalents became matches), and
  the `??_G` blocks need no text: the registration emits them. Pitfall: typing the setter word as a member function
  pointer of T0 changes the code of `vfunc_2` (`f_10 == 0`) wherever T0 is incomplete (general representation).
- Of the 434 registrations in the game, 65 sit in the TU of their classes' `??_G` blocks, 128 in a `.iso_` /
  `.new_*` sibling of it, and 241 in another object (the `??_G` blocks are in `_params` / `_reg` TUs of low-confidence
  splits, e.g. CButtonCondition_params.cpp holds CNameFlagConditionBase's): those need the object boundaries settled
  (config/splits.json) before the registration can emit them. Non-template `??_G`s (OpportunityAction, ...) keep
  their TUs on /GX until their constructors are real.

## 2026-11-14 x64t12: the archives mount natively; pointers parked in ints along the drive path

- macOS start-up never opened rcfs.txt's archives: 0x00271560 kept FUN_002697c0's two result *pointers* in int words
  of its work area, so the 8-byte stores ran over the drive name it then looked up. The same parser feeds InstanceDrive's
  slots and the archive's name went through 0x00277b70 as an `unsigned int`. With the drive path, core::CementLibrary
  (on records.h CoreCementLibrary, its constructor storing the game's vftables), the entry readers (CoreFileView's
  buffer pointer, 0x00278010 calling the readers by name) and the file requests (CoreFile, the lock through a cast)
  fixed, all twelve archives mount and the language probe finds frontend/lang/str_en.txt in one.
- data_gen wrote a pointer into a vftable record as `vtbl_<record> + 4`: natively the record's words are 8 bytes and
  `vtbl_` has no native name, so DAT_0049ca0c (the static MyDriveErrorCallback) had a null slot 0. Such pointers are
  now the slot's own `DAT_<address>`, which both links bind (ten items).
- Adjustor-thunk blocks of invented classes (0x002777c0..0x00277800) have no usable native form: their thunks call
  undefined local methods. The explicit `HULK_PTR64` thunk (0x002786f0's pattern) must call its target by the
  target's own C++ name: a 64-bit-only `FUN_<addr>` name is never in the Wine binding map, so the native link cannot
  verify it (0x002786f0's own `FUN_00278a80` is unbound for that reason).
- Removing two unused member declarations from include/gen/owners.h flipped 0x002ea3c0's MSVC code (one of the six
  declaration-count blocks); keeping the declarations restores it.

## 2026-11-14 tri2: the 226 `--wine` blocks that never held as tree TUs
- chk1's 226 pre-existing `--wine` failures were never proven as tree TUs: their `@w` came from hash1's bulk recording
  (6a71f9a03's code), and at that commit, with its own checker, 215 of 226 already failed. The flip had checked `--wine`
  on a 200-block sample at 64 inputs only. The standalone sources mostly failed too (at F, 115 within the gate's 600).
- Causes: tree-mode checker gaps only clang's single `.text`/namespaces meet (fastcall neighbour as local label,
  fuzzed fn-pointer facts, block-scope extern, local-static back-references, double NaN quieting: ec867cc4f); tri1's
  queue-host probe and unit_text bugs; time budget on loaded hosts; x87 precision in sources (13 fixed, 07071bd58).
  70 of 226 pass after this; 156 open, listed in build/tri2/still_failing.json with docs/native-build.md "tri2".
- D31: four of the exception-flag TUs clean without exceptions (cefff8a80); five of tri2's fail with and without.
- Pitfalls: clang with -fms-compatibility defines `_MSC_VER` (guard clang-only spellings with `__clang__`); the
  "hulk_freg everywhere" autofixes were wrong where the original stores a value (a halved denormal, an fst-stored
  fraction read back); `fst [v]; fmul [v]` multiplies the unrounded value by the rounded one.

## 2026-11-14 tri1: why 51 "proven" equivalent blocks failed their own proof (chk1's pre-existing MSVC failures)
- Two checker inputs the code hash does not cover broke proofs silently: (1) unb4's `namespace fn_X {` / decl / `}`
  groups made `tree_tu.unit_text` unparseable in 95 TUs (510 blocks), so every C-linkage block there lost its declared
  return and parameter kinds (8 of the 51); (2) on the queue hosts the sizeof probe's `/I ../../include` resolved
  through the build/ symlink into the host checkout's stale headers, so every tree-TU run on mac1/mac2/studio compared
  pointer arguments without their pointee sizes (4 of the 51 and chk1's 0x001759c0; the laptop passed). Both fixed in
  tools/tree_tu.py; docs/merge-once.md "What the hash does not cover" proposes a third hash of the checker's view.
- 9 blocks were never valid in the tree or at today's bar: merge-time overload capture (0x00297680: an int literal picks
  the TU's other `extern "C"` thunk declaration), the merged `extern "C"` declaration of a varargs function with a
  register convention (0x0021f800: a checker gap, `cvarargs`), xlocal's word granularity (`char buf[N] = {0}`: 3 blocks
  with every input set aside), 0x002142d0 (46/120 coverage even at 20,000 inputs).
- 10 started failing at a checker round that exposed a real difference nobody fixed (round 17 exact floats 0x000d3170,
  0x002d2c40; round 19 0x000a4450; round 21 `wglobals` 0x000d50f0, 0x00079990, 0x001c0360) or that misfires (round 21
  `vptrkeep` on 0x00106290 / 0x0007f690 / 0x001e3020, which make no stubbed call to keep a vptr across:
  EQUIV_OFF=vptrkeep passes them); several were listed as known failures in docs/equivalence.md and kept their label,
  and hash1 then recorded hashes over them. A hash should be recorded only from a passing run.
- The rest pass with a bigger budget or at the input count they were proven with (20,000), not at the audit's 3,000/120 s.
- Pitfall: an unsigned literal decides which of two same-named declarations a call binds (`f(0x28)` vs `f(0x28u)` with
  `extern "C" f(int)` and `f(unsigned)` both in scope).

## 2026-11-15 gx3: registration objects (D32); 156 more registrations construct the real parameter templates

- A fight registration that is the only storer of a `ParamX<T>` vftable fixes the object of that vftable's `??_G`
  (COMDATs come from the first object in link order that emits them, and only a constructing object emits them). That
  rule alone merges 198 inferred objects into 15 (tools/infer_splits.py step 8); the merged ones are whole files of
  condition / track classes (up to 50 inferred objects, 0x0006e840..0x00075ce0), so the `_params` / `_reg` cuts of the
  registration runs were within-file COMDAT order, not object boundaries.
- MSVC 7.1's stack slot assignment depends on the declarations the TU has seen: three equivalent blocks (0x000b86b0, 0x00027930, 0x001a9b10) changed
  code when only their TU's data declaration header gained or lost unrelated `extern` lines. A header-only data change
  can need re-proofs.
- clang rejects two `extern "C"` declarations of one function with different parameter types (MSVC accepts them):
  merging registration TUs must drop the siblings' own declarations of the list set-up 0x002347b0.
- An `operator=` setter (`O_47fa0::operator=(int)`) needs its member pointer type spelled out: `&C::operator=` names
  the implicit copy assignment too, and template argument deduction fails on the overload set.
- Shared-checkout hazard: a commit made from the shared index right after another agent's temporary-index commit can
  carry that index's stale entries and revert the other commit wholesale (bc332e523 reverted gx3 2's 128 paths;
  restored by 3d5e44c3c). After a temporary-index commit, sync the shared index entries of the committed paths at once
  (build/gx3/scripts/commitpatch.py does, but only where the entry still equals HEAD~1, which a concurrent commit
  breaks); check `git show --stat HEAD` of the next commits.

## 2026-11-15 integ1: proof integrity (D43, D38, D42, D37, D39, D44, D45)

- vptrkeep's own tracker changed runs: `_read_u32` maps an unmapped page outside the 1000-page limit, so in a call-free
  loop over a pointer array the original (tracked) mapped past the limit and returned where ours hit too_many_pages.
  A checker hook must read without side effects (`vptrread`, 3d44040ee). Other `_read_u32` callers are not audited yet.
- Code hashes now have a third companion: `@v`, the checker's view (signature, bindings, pointee sizes, ...), and a
  proof ledger (config/proof-ledger.jsonl, written only by `hash --proven`). Views computed on the laptop and on mac2 agree
  (ChannelSendVolumeFadeBehaviour.cpp, 12 views). The ledger is held back until the re-audit finishes: once the file
  exists every block without a line is `unproven`.
- nanpayload (D39): rev3 found the first form set aside integer differences (-1 vs -2 are qNaN-shaped). Restricted to
  words both sides last stored as 4-byte floats, it rescues none of the four blocks that motivated it (struct copies
  as integer words, or the original's `mov` copy). Recommendation: drop it. Runs with EQUIV_ON / EQUIV_OFF switches now
  prove nothing (proves, wine_gate.judge).
- Shared-checkout hazard seen again: `regress.py --jobq` ships every dirty file, so other agents' WIP (equiv64.py,
  include/decls) fails unrelated cases; read failures by their cause before blaming a checker change.
- Coverage-threshold regress cases (0x003037f0_iterator_range, 0x002cb2b0_loop_exit_order) fail on a loaded laptop
  with HEAD's checker as well: time budget, not code.

## 2026-11-15 tri3: failing equivalent proofs fixed in source; strlazy and memub

- In the Wine build a `float op float` expression is already evaluated at double: casting an operand to `hulk_freg`
  leaves the clang object unchanged (0x0009faa0, 0x00356fa0 checked). What rounds is a `float` local, member or
  argument that is stored. Fix the declaration of the value the original keeps in st (`hulk_freg`), not the expression;
  and the other way round, a value the original spills with `fstp dword` must stay `float` (0x0013d410's span).
- `(int)x` / `(unsigned char)(int)x` of a float that can leave int range: the original's `_ftol` returns a 64-bit
  result whose low word the code keeps; clang's cvttss2si gives 0x80000000. Spell `(int)(__int64)x` (MSVC's code is
  unchanged). Six more blocks had it.
- clang makes a struct copy above a few words a `memcpy` call; MSVC 7.1 a forward `rep movsd`. Fuzzed overlapping
  pointers made the two differ in 13 blocks; memcpy on overlapping ranges is undefined, so the checker now sets such
  inputs aside (`memub`), and where the original's word order matters for real (in-place edge removal) the source
  copies word by word.
- clang evaluates the object of a call (and of `(obj->*m)(args)`) before its arguments; MSVC 7.1 the arguments first.
  When an argument is a call that the stub lets write memory, the object the original reads after the call differs:
  hoist the argument into a local (0x00117480, 0x00297ba0, 0x002d50c0). The converse pattern, the vptr read before an
  argument call and `this` re-read after it (0x000e14b0, 0x00264050, 0x00297680), has no C++ spelling clang follows:
  a checker model question, not a source fix.
- clang does not reset the vptr in a destructor whose body is empty (`~Base() {}`), even at -O0; the original does.
  `{ ; }` keeps the store with identical MSVC code (0x0026e650).
- `*p++` in clang -O0 stores p + 1 before it reads the byte; the original reads first. Where p can point at itself
  (fuzzed), spell the read first (llex 0x0021b1c0).
- Process: a temporary-index commit must read-tree the HEAD it will commit on and build every file from that HEAD:
  building files from an older HEAD reverts whatever landed in between (caught before the push here).

## 2026-11-15 gx4: Name / int-word parameter families constructed for real (D18)

- MSVC 7.1 /O2 inlines a base class's out-of-line constructor into a derived constructor defined in the same TU and
  drops the base's (dead) vftable store: 0x00234a90 ParamValueName(const char*) = ParamValue's vftable, the name, its
  own vftable. Never across objects, so 0x00234a90 / 0x00234ba0 belong to ParamValueString's / ParamValueStringList's
  objects; config/splits.json had each one object too late (moved, data.json regenerated).
- ParamBoolPtr / ParamFloatPtrConstRange's +0x10 word is a data member offset (vfunc_6 stores `p[f_10] = v`), written
  as `&T::f_xx` (a pointer to the include/gen field). The other families' word is a member function's address; some
  setters are pinned as fastcall / stdcall C functions (getters `return this + k`), named by address in the
  registrations.
- gx3's gen19 read the shared working copy for files outside its overlay: a batch could carry another agent's
  uncommitted edit (gx4 caught tri3's 0x0015ebc0 in its overlay through a changed `--wine` hash). gen20 reads a
  `git archive HEAD` snapshot.
- After the 11-15 reboot, local wibo (MSVC) runs hung at 0 CPU on the laptop; the queue hosts were unaffected.
- `delete[]` of a char* in MSVC 7.1 calls `operator delete` (??3) unless `void operator delete[](void*);` is declared;
  the game's destructors call 0x0008d340 for the strings and 0x0008d330 for `delete this`, so the declaration is
  needed (verify_relocs: "inconsistent ??3").
- A setter pinned on a virtual stand-in method (`?Get@Obj_12960@fn_ff0a839e@@UAEPAXXZ`) can't be named from a
  registration as its address without a non-virtual declaration, which gives another native name: such stand-ins
  should not be virtual.

## 2026-11-15 x64t13: macOS start-up into the loader fiber; D34's gate entries fixed; D35 thunks
- A thunk call "passing 2 arguments" can push 5: MSVC interleaves the pushes of nested zero-argument thiscalls, so
  0x00272df0's `cb->run(error, drive->slot4(), req->kind(), req->name(), arg)` and the old source's nested
  one-argument calls compile to the same bytes. Only the callees' `ret` sizes tell them apart (bare `ret` for the
  slots, `ret 0x14` for MyDriveErrorCallback::vfunc_0); both were equivalent at 32-bit, only one is right natively.
- equiv64 input annotations (docs/equivalence.md): `HULK_RANGE(lo, hi)` on an integer field and `HULK_INTO(field)` on
  a pointer parameter, seen only by the checker's libclang parse; they model a domain fact (a list index, a pool
  block) instead of accepting the block into the x64 baseline. D34's 0x002775b0 and 0x0008ff00 left the baseline.
- native_unbound.Defs lacked native_mac.TreeDefs's own-address rule, so a call to a function that only a 64-bit branch
  defines (named `FUN_<addr>`) never bound; with it 0x00266890's native constructor binds.
- Local wibo (MSVC) processes hung in state U after the 09:30 reboot (unkillable); every MSVC check after that ran
  on the queue.
- 32abd96a2 (tri3) committed x64t13's three regress entries from the shared index before their case files and the
  equiv64 change existed; this batch adds them.

## 2026-11-16 integ1 (2): what a proof ran
- "--inputs 3000" had meant 3,000 drawn, and the random phase stops at 32 inconclusive inputs: recorded proofs had
  compared as few as 56. D62: a proof is 3,000 compared inputs per mode; proof runs now draw until they get there.
  Drawing more already found a real --wine difference (0x00330ba0) and one in a regress case (0x002155f0_diff_bound).
- Equivalence rules that set inputs aside hide differences on those inputs (rev4's memub_hidden): prefer modelling the
  original (memfwd) or repairing the input to the contract (preconditions) over excluding it.
- x64_gate's cache was keyed on all of equiv.py: every 32-bit checker edit re-ran every --x64 result.

## 2026-11-16 tri4: the failing equivalent blocks, fixed in source (D55)
- A byte the original tests whole (`test al, al` after a call: a virtual, a function pointer, a stub) is a `char`
  return in source: clang tests bit 0 of a `bool`, so a callee returning 2 takes the other branch (boolexpl, D28).
  Fixed 0x000e2c90, 0x000ebf40, 0x000e9af0, 0x000ea7c0, 0x00239f10, 0x00245390 (0x00237050 in batch 2); 0x001bea80 passes the
  whole byte of a `bool` getter back to its setter.
- clang -O0 lays out locals in declaration order, the first at the highest address. Where a stub's write through a
  pointer argument or the checker's comparison of a local reaches the next local (the original's frame), declaring
  the neighbour first reproduces it (0x002a9f60, 0x00310bc0, 0x001e2ed0, 0x002a8450 by case order, 0x000ed990 one
  local for two calls).
- `a[f()]` and `obj->m(x)` read the array base / object before the call in clang; the original calls first
  (0x001ed0b0 `bones[FUN()]`, 0x000c1b50 the arguments before `FUN_000fc1b0()->`).
- x87 keeps what it does not store: 0x00323ee0's tan product, 0x00324660's dot, 0x00326330's unsigned-to-float count,
  0x0029d880's cosine difference and its `Reach()` helper, 0x002d31e0's floor argument, 0x003078a0's dx. Read the
  `fst`/`fstp` pairs: an `fst` value is stored rounded and kept unrounded.
- A static helper ending in a callee-popped virtual call right before its epilogue loses the checker's `sub esp` cue
  (clang_pop_after): `__forceinline` it (0x002801b0).
- NaN preconditions (D54) on 0x0022ca90, 0x0022cc10, 0x0022cdb0 (the floats read) and 0x00308ba0 (periodScale,
  dampingScale) prove in both modes with @msvc unchanged, but the Wine build traps at play3 frame 37080 with them
  (deterministic, 85859 / 86188): game data, or one of our differences upstream, does hand one of them a NaN.
  0x00229360's NaN comes through `this->blends[i].weight` and callee returns: no LOC expresses it.
- D62 leaves blocks whose loops run over fuzzed counts unprovable from the source side: 0x0024a280 (430 of 11,171
  compared), 0x002155f0 (582 of 10,000), 0x002b07d0 (1,250), 0x002ee9a0 (2,327), 0x00300080 (2,446).

## 2026-11-15 gx5: fight::Action real; HULK_REFCOUNT_INLINE_DTOR; D48 not needed
- MSVC 7.1 schedules a destructor's vftable store after the load of the word it releases when the release is written
  in place (`if (f_08) { f_08->Release(); f_08 = 0; }`), but before it when the same statements are an inline function
  taking the word by reference (`core::ReleaseRef(f_08)`), as the game's destructors do (0x002326a0, 0x00237530,
  0x00239870, ...). The stand-ins pinned the order with `*(void* volatile*)this = ...; _ReadWriteBarrier();`.
- The game inlines core::IRefCount's and pure3d::NonCopyable's (empty) destructors everywhere; the tree can only do so
  in TUs without user-written empty `??_G` destructors (`pure3d::View::~View() {}` under /GX): once ~NonCopyable is
  inline, such a destructor is trivial and MSVC inlines it into the `??_G` (20 blocks changed). Gated per TU with
  HULK_REFCOUNT_INLINE_DTOR until those TUs construct their classes for real.
- gen_headers.py --probe defines a class's out-of-line constructors in its layout TU only when the declaration is on
  one line (`X(P...);`, defaults stripped); a constructor declared over two lines leaves the vftable unemitted ("vftable
  +0x0 not emitted"). A constructor that takes arguments needs defaults for the probe's `new X`.
- fight::Action's +0x08 word is the next action of the list a fight::ActionList (10 words, no RTTI: ExecuteAction +0x38,
  GrappleHitReactionAction +0x24, CCharacter, CEventManager) runs; 0x002325f0, listed as a thunk "not yet verified", is
  ActionList's destructor `{ Reset(); }`, which MSVC 7.1 compiles to `jmp Reset`.
- D48's premise (a 16-byte Itanium member function pointer on Linux / Android) does not hold: every native target's
  front end is MS-ABI (tools/native_elf.py TARGETS), where `bool (C::*)(int)` is 8 bytes for a complete
  single-inheritance class; all 1,374 ParamX vfunc_6 blocks cast to their own ParamX<T>.
- config/proof-ledger.jsonl does not exist in HEAD: `hash --proven` creates it in the job tree, and committing it would
  switch the ledger checks on for every block (all unproven). The two ledger lines of 0x00147db0 are kept in
  build/gx5/ledger-lines.jsonl for when the ledger is started.

## 2026-11-16 tri4 (2): the NaN precondition trap
- play3 frame 37080: slot 24 of FUN_0027f2a0's render table hands FUN_0022ca90 a transform whose rotation is the
  default NaN 0xffc00000 (translation valid): the game itself computes it (HEAD traps too). The notnan contract does
  not hold for the matrix product; a NaN that is the default NaN on both sides is not a payload difference.
- A frame address stored into memory (0x00265cd0's &f.reader) cannot be placed by clang -O0 where the original's
  frame-pointer-less layout puts it (ebp, saved registers and the this spill sit above every local).

## 2026-11-15 x64t14: content stream / chunk reader records; the device slot overrun; FUN_000964a0
- A 16-byte data item holding a counter and a 12-byte string (DAT_004e3748) overran natively by the string's 64-bit
  growth into the next item, the pddi device slot: the first symptom was a crash on "device 9" (the string's length)
  far from either. Check the neighbour of a slot that holds garbage before debugging its writer.
- A polymorphic view with a pad after its vptr (`virtual f(); char pad[8]; char ok;`) keeps 32-bit distances, so
  natively its fields miss the record's pointer-aligned words; HULK_CONTENT_LOADSTREAM_WORDS lays a record's words
  after a view's own vptr.
- Fixes on a block whose proof can't currently be redone (0x00265cd0, --wine fails at HEAD under D62) can keep its
  32-bit objects byte-identical with pointer-sized integer types (`hulk_intptr`) or a 64-bit-only typedef (a result
  type the 64-bit call needs to bind): check then reports its code hashes ok.
- A call by a name the Wine map doesn't know yet (a renamed member) is unbound in a local native link until the next
  Wine build: name such callees by address (`FUN_<addr>` members) so the own-address rule binds them.
- `until ! pgrep -f "it.sh i5"` matches its own shell's command line and never ends; wait on a log line instead.
- A helper script that imported tree_tu and did its work at module level ran recursively (thousands of copies) and
  exhausted the laptop's processes; scripts that import the tools keep their work under `if __name__ == "__main__"`.

## 2026-11-15 x64t15: the start-up hang was a size of 0; declarations that bind only natively
- The macOS start-up "hang in the drive" was a stream of size 0 copying 0 bytes forever: a 12-byte pad in front of a
  cement library entry's size (owners::C_277cd0) read the neighbouring word natively. When a wait never ends, check
  that the work it waits for was ever asked for (breakpoints on the queue's push and pop showed every request ran).
- The native link binds a call by address only when the caller's IR signature is the definition's: `char`, `bool` and
  `int` results are three different types there (i8 / i1 / i32), `int` and `unsigned` are one (i32), a pointer and a
  pointer-sized integer are one (64-bit). Making a loader's declaration say the definition's `bool` changed 44 Wine-build
  objects (clang tests the byte differently) though MSVC's were unchanged; `HULK_TYPE64(char, bool)` keeps both 32-bit
  objects and binds natively. Changing a result's signedness (`int` -> `unsigned`) is not free under `--x64` either:
  it flips a comparison.

## 2026-11-16 x64t16: libpng / zlib on records; four things the batch showed

- **A header's size can move MSVC 7.1's code.** Adding the libpng records (about 270 lines of types) to
  include/decls/data/records.h, which most TUs reach, changed 0x002ea3c0's object (two loads swapped) although its TU
  used none of the new types; the same text in a header only three TUs include changed nothing elsewhere. Large
  additions to widely included headers need a whole-tree check before anything else is built on them.
- **A caller's declaration must not become the definition in the same TU.** The views' distinct parameter types kept
  every libpng caller's declaration a different overload from the definition; unifying them on one record would make
  them the same function, which MSVC then inlines (the tree's "a call became inline code" wraps). The conversion kept
  them distinct (a `void *` / `hulk_intptr` parameter), which natively binds like the pointer.
- **TreeDefs and `hulk_intptr` first parameters.** Three `target` definitions (png_set_cHRM / oFFs / pHYs) whose first
  parameter is `hulk_intptr` were "definition without a unique 64-bit symbol" natively (their demangled forms collapse
  once int / __int64 are loosened); named by their addresses they bind by their own address.
- **The game's global operator delete** (0x00267090, as the Wine map binds `??3@YAXPAX@Z` / `??_V@YAXPAX@Z`) had no
  MS-mangled definition natively: every deleting destructor ran into a stub. Defined for the 64-bit builds only.

## 2026-11-16 tri5: what kept the last float blocks from proving
- **A copy the original makes with `mov` keeps a signalling NaN; one through st does not.** 0x002d6790 copies
  `cols[0]` into the vertex with integer moves; the source's `hulk_freg u0` (double in the Wine build) quieted a fuzzed
  sNaN (0x7f8b... became 0x7fcb...). A value the listing only moves is `float`, never `hulk_freg`.
- **`fst` then compare: the comparison sees the unrounded value.** MSVC 7.1 compares the value it has just stored
  without reloading it (`fst [m]; fcomp`), so `x = a + b; if (x < 0)` tests the unrounded sum. Four blocks hinged on it
  (0x00318910's `sq > 0`, 0x0019e910's `fuel < 0` and `age > fd8`); a denormal that rounds to 0 is where it shows. In
  the Wine build the spelling is a `hulk_freg` local stored to the member and compared itself; where MSVC 7.1 would then
  spill and reload the local (0x00318910), the two spellings sit under `#if defined(__clang__)`.
- **Under SSE a float product is rounded before it is added.** `x * 0.06f + s` is one rounding in the original (the
  product stays in st at 53 bits; a product of two floats is exact there) and two in the Wine build's SSE code, so
  every product feeding a sum the original keeps in st needs `(hulk_freg)x * c` (0x000d3170's 14 HUD constants,
  0x002d2c40's `w.x * v + ax`). Products alone round the same either way.
- **`x * -0.5f` is not exact for a denormal x in float.** 0x000d3170 and 0x000c8850 keep `DAT_004de600 * -0.5` in st
  (exact in the extended format) and add it to `0.5 * x`: `+0` in the original, `-0` (or a denormal off by one) with
  the product rounded first.
- **`memfwd` misses an overlap that wraps around address 0** (`memcpy(dst=0, src=0xffffffe6, n=0x66)`: the source's
  end wraps to 0x4c, inside the destination): the original's forward `rep movsd` reads what it has just written, ours
  copies as if disjoint. 0x00277d60 and 0x0027e920 fail only on such inputs; a checker case for integ2.
- **A callee's out pointer into the function's own parameter slot** (0x000c9720: `FUN_000c9460(&input, input)`, the
  original passes `&input` = its incoming argument slot): the stub fill writes only word 0 there ("never into the
  caller's argument slots"), while clang's copy of the expanded struct is a frame local and gets every word. Checker.
- **Overlapping unaligned writes defeat `nanquiet`.** 0x002d6790's fuzzed vertex pointers (9, a, b, c) made the uv,
  colour and position stores overlap; the compared word mixed bytes of several stores, so the quieted NaN no longer
  looked like one and the input failed instead of being set aside. The source fix (no conversion of a moved value) was
  the right one anyway.
- **MSVC 7.1 keeps a float local in st where the original stored it.** 0x00079990's MSVC-only 1-ulp failures were three
  locals the original spills and reloads (`p`, `x1`, `x2`) that our MSVC build kept unrounded; `volatile float` gives
  the store/reload in both builds.
- **A stub's return model depends on how soon eax is used.** 0x000a4450: after `FUN_0009fef0` the original stores a
  constant and jumps to a shared copy tail before dereferencing eax; the checker gives its stub a scalar return (0x42)
  and ours (dereferencing at once) the first argument. A checker case.

## 2026-11-16 integ2: the ledger landed; defnan; proof draws past 10,000; selfnarrow

- **Ledger (D51)**: 238edce66, 8,611 lines from 23,496 harvested reports of committed checkers, decided by
  `hash --proven` at eb6ff7e53. Whole tree: 509 blocks unproven in some mode (373 msvc, 486 wine), now failing verify
  wherever a change touches them. Reports of five uncommitted checker digests (139 reports) and 733 without a digest
  were not offered.
- **defnan (D65)**: the default NaN 0xffc00000 is the only NaN the four matrix blocks accept; with it x87 and SSE hand
  on the same bits. The checker plants it (one input in four) and checks per contract word that another NaN traps and
  that the default NaN computes as the original. The play3 replay is the test that the game's NaNs are all default.
- **D69**: past 10,000 draws compare much less often than before (the first 10,000 include the directed and
  small-count inputs): the extension must be staged on the marginal rate, not the average. Three parked blocks compare
  nothing new past 10,000: their inputs need a model, not draws.
- **selfnarrow**: natnarrow skipped the function's own recursive calls (the self-call is not among our relocations'
  callees); 0x0030a9d0 now passes --wine at 3,000.

## 2026-11-17 integ2: defnan of either sign; proofs past 10,000 with small counts
- arm64 makes 0x7fc00000 where x87/SSE make 0xffc00000; the contract allows both, and a NaN's sign is not behaviour.
  A fixed sample of bad NaNs let a macro blind to even payloads pass (rev5's _oddpay): sample by the seed too.
- Proofs that draw past --inputs starved because small counts had used their time share; giving them rounds while
  drawing proves 0x002a2200 / 0x002155f0 / 0x002b07d0 in ~3,000 draws instead of failing at 30,000.
- A view must not depend on a host's local files (D91: build/xbsymbols.txt is laptop-only); rev5 showed that dropping
  the file loses a real check (0x00320d30 calling the wrong D3D export passes): the fix is the user's call (D101).

## 2026-11-16 x64t17: TextureBuilder and d3dTexture on records (D76)

- **A source-local polymorphic stand-in for a game object the code constructs gets clang's vftable natively, sized
  by the stand-in's declared virtuals.** The image factories' five TextureBuilder stand-ins each had 1 to 11 slots; the
  PNG reader called slot 10 and jumped into whatever followed the short table. Constructing the object as a
  non-polymorphic record with the game's vftable stored by address (`init()`) makes every caller, whatever its view,
  reach the game's slots, which the native link binds to the tree's definitions; the definitions then must not be
  virtual members of yet another local class (they are record-derived structs' plain members, named as before but `Q`).
- **A local stand-in base whose constructor is only declared** (`d3dBase();`, `pddiObject() throw();`) is an unbound
  name natively: the Wine build binds it by relocation position, the native link has no address in the name. The fix
  is the record plus the base constructor by its address name (`HulkD3dTexture* FUN_0031bac0();`), as x64t5 did for
  d3dDisplay.
- **An overload set split by `int` / `unsigned int` (FUN_0008d690 in d3dDevice.cpp) is ambiguous natively for a
  `sizeof` argument** (size_t is unsigned long): cast the argument to the overload the 32-bit object called.
- **A changed gen layout changes the checker view of blocks that never touch the class** (0x00320d30's view moved with
  gen d3dTexture's fields although its code did not): budget re-proofs for every view a gen edit reaches (the
  whole-tree check lists them).
- 0x003821c0 is the next missing XDK function (the game's Get2DSurfaceDesc, D3DTexture_GetLevelDesc); the native D3D
  shim creates no textures (CreateTexture2 returns 0), so the native image's textures are empty until it does.

## 2026-11-17 x64t18: the D3D shim's textures, ImageBuilder on a record (D89, D90)

- **The native image runs the game's own pddi D3D layer, so the XDK D3D shim is its graphics device for now.** The
  Wine build swaps pure3d's d3d layer for the pddi/bgfx backend at d3dCreateDevice; the native link has no bgfx, so
  the tree's d3dTexture / d3dDisplay call the shim's D3D8 functions. Textures, surfaces, palettes and the device's
  back and depth buffers are now real host-memory objects there (linear levels, the game's own format tables for
  their sizes); nothing draws them until the native image gets a renderer.
- **A game name that is another row's name** (Get2DSurfaceDesc: the game's name for 0x003821c0, the shim row's name at
  0x0038abf0) binds natively only through an explicit table (native_bind.GAME_NAME_ROWS), as the Wine map binds it.
- **Pads over the image registry hide 64-bit bugs in seven places.** Its handler array is 32 pointers, so every word
  behind it moves by 0x88 natively; views that reached +0x8c / +0x94 through a pad read and wrote the handler
  pointers (texture parameters made of pointer halves, DXT parameters written over handlers).
- **pure3d::Entity is 0x14 bytes natively** (vftable, count, the two name words): `char pad[0x10]; T* p;` puts `p` 8
  bytes off (natively +0x18), `char pad[8]; name` 4 bytes off. `void* vftable; int words[3];` is right on both builds.
- **A placement-new into a 4-byte word of a frame** (`new (&f.r6) DynamicCaster<...>`) writes 8 bytes natively: the
  following pointer is overwritten. A union with a `void*` keeps the 32-bit frame and gives the object room natively.
- **The x64 gate's cache is keyed by the code**: moving a member function from an owners:: view to a record-derived
  class leaves the code (and the cached `layout` result, which sized `this` by the old class) unchanged; the cached
  result has to be dropped to re-run (the result's type fingerprints cover the classes it used, not the method's
  class change).
- **The equivalence checker sizes an object returned through a stub by the declared pointee**, so a view that moves a
  field to its native offset (0x002aecb0: Entity's name at +0xc) can read as a new `layout` difference although the
  native code is the one that matches the tree's own Entity constructor (D93).

## 2026-11-17 x64t19: pure3d::Sprite, the drawable container and the content loader on records (D94, D96)

- **A native hang can be a view writing a state word 4 bytes short.** The copyright p3d loaded, yet the game waited
  for its request forever: the request's state setter (0x00266950) was a pad view that put the state at +0x14, where
  the getters (on records.h ContentLoadRequest) read +0x18 natively. A hang sample (HULK_HANG) only shows the wait
  loop; attaching lldb (`lldb -p PID --batch -s FILE`) and breaking in the loop's callees shows the words.
- **A frame struct sized by a 32-bit pad is a stack overrun natively**: LoadInventory's lookup reserved 0x18 bytes for
  the hash probe, which natively writes 0x20; the probe's last word landed on the caller's saved matcher pointer.
  Spell such frames with the probe's own words (or `sizeof(record)`), never `char data[0x18]`.
- **Ring and vector arithmetic on byte counts** (`(end - begin) >> 3`, `>> 4`, `count * 16`) is the 32-bit element
  size: natively each count is doubled or halved. Pointer subtraction of the element type compiles to the same MSVC
  bytes (sub / sar), so the views keep matching.
- **A queue entry's "value" can be a pointer**: the content registry's ring entries {request, value} carry a task the
  queue later calls (0x00265190 pushes one, 0x002655b0 pops and calls it); an `unsigned int` value truncated it.
- **Local polymorphic stand-ins in constructors** (Sprite, DrawableHierarchy, DrawableContainer's copy, SpriteObject)
  give the object clang's vftable natively, whose slots are the stand-ins' undefined declarations; the fix is the
  same each time: a non-polymorphic record, the base constructor by its address name, the game's vftable by address,
  and calls through a slots-only view that is never constructed.
- **A callee declared with another signature than its definition does not bind natively** (IR signatures must agree:
  int vs pointer, void vs a returned pointer, hulk_uintptr vs unsigned): `missing` at run time names the caller's
  spelling; declare it as defined.

## 2026-11-18 tri6: 0x001bc0c0, the copyright content lookup (D108)

- **A `--wine` failure whose numbers look like float bits was a bool byte.** SetFlag's argument differed only in its
  low byte (0x3aaec201 vs 0x3aaec294): the original stores GetFlag's `al` as returned into the low byte of the float
  slot it later passes whole; `bool GetFlag()` let clang normalise the byte to 0/1, which the `bool_ub` counterfactual
  does not explain (it reads the original's byte as a value, not a bool test). Declaring the slot `unsigned char`
  proves both modes; x87_order reports no x87 at all here. Read a diff's byte positions before assuming rounding.
- x64t19's caster patch (the game's vftable 0x003f6330 by address in a pointer-sized frame word) landed with it;
  `--x64` stays `unsupported:no32` (no 32-bit input completes: a fuzzed virtual call fetches at 0), as at HEAD.

## 2026-11-18 x64t20: the content tables' cursor (D106), DrawablePrimitive's word (D105), the copyright's release

- **A cursor initialiser declared with an unsigned parameter cuts the table pointer in every caller.** Ten iterators
  of fight's hash table (LoadInventory, LoadStream, fight::Context, ParamValueInventoryEntity, unk_28fbc0,
  CSoundRealTimeManager, EffectAction) kept the cursor as an 8-byte pad or `unsigned` words and the inventory's pool
  as `unsigned f0c` behind a 0xc pad (+0x10 natively). One record (decls/table_cursor.h HulkTableCursor) and the
  inventory's record (decls/load_inventory.h) for the owner views; MSVC bytes unchanged everywhere.
- **A shared base's word size decides where every descendant's box lands.** DrawablePrimitive's +0x10 word is an int,
  DrawableHierarchy's a pointer: natively their boxes were 4 bytes apart and 0x002a4570 can read only one offset.
  Making the primitive's word pointer-sized moves every descendant view (gen f_10, HULK_SPE, HulkSprite) by the same
  8 bytes; a raw `(char*)this + HULK_SPE(k)` inside a pad is what the x64 gate then reads as `layout`: give the view
  a field at that offset.
- **`pure3d::X::~X() {}` standing for a scalar deleting destructor defines nothing natively.** The pinned `??_G`
  symbol is MSVC's; clang emits only the destructor variants, so the game vftable's slot binds to `hulk_x_<addr>`.
  An explicit `X_addr* vfunc_N(unsigned char flags) { body(); if (flags & 1) free(this); return this; }` matches the
  same bytes. 809 blocks of the tree have this shape.
- **Free and release helpers named without an address** (`Free`, `Release`, `BaseDestroy`, `run`,
  `SweepTrack_DeleteThis`, `thunk`) are unbound natively: call them by their address names or as defined (the XDK's
  `D3DResource_Release`). A new `thunk_FUN_00267090` spelling needs a local map entry for the call's target thunk
  (the Wine map binds such names by position).

## 2026-11-18 integ2: data annotations on globals, the last two data-driven crash64 accepts (D103)
- Both baseline accepts took their bad index from a **word of game data**, not from a parameter, so D102's
  parameter HULK_RANGE could not fix them:
  - 0x00356fa0 (Perlin noise): the permutation table DAT_0056bfc8 is writable .data. Its only writer is NoiseInit
    0x003572b0, which stores a permutation of 0..255 and a copy of it.
  - 0x001fe380: DAT_00425260 is the const .rdata table {2, 3, 4, 5}, read only by this function.
- **Dead code:** an XBE scan of every reference into the Perlin table also found 0x00356de0, a 1-D noise function
  that nothing calls. It is linked but missing from the function list.
- **The fix**, applied on `--x64` runs only:
  - `HULK_RANGE` on a TU's redeclaration of a global, with a mandatory reference census. The citation must name
    every function in the XBE that references the table.
  - `HULK_RDATA` on a const table in a read-only data section: both runs start from the XBE's bytes.
- **rev5's three rounds** found the gaps fixed here:
  - an MSVC C2872: a redeclaration inside a namespace brought in with `using` is ambiguous with the global one;
  - pointer tables that data.json types as int;
  - the census window and the citation rule for dead code;
  - stale digests: a global read through a helper, an edited comment, a changed data.json.
- **Lesson:** a table's data.json type says nothing about its words. 37 ".rdata int" items hold image addresses
  (SEH scope tables, {id, string} pairs). Read the image before trusting a scalar type.

## 2026-11-18 data4: image addresses under scalar kinds in config/data.json (D119); Perlin's 1-D noise stays dead code (D120)

- **42 of the 55 `.rdata` items of a scalar kind whose words fall in the image are pointers** (docs/data.md "Image
  addresses under a scalar kind"). Three causes: typed records were always placed as `table` (an initialized
  records.h item is now typed by its declaration and a `struct` when it holds a pointer: 0x0040cc74's {id, string}
  pairs, plus 54 `.data` records), the carve takes a code word as a pointer only at a function start (the library's
  SEH scope tables and C++ unwind maps: 39 `struct` pins), and pointer bytes that read as text (two XAPI
  OBJECT_STRINGs: config/data-pointers.json). The data TUs change in comment lines only: data_gen already emitted
  the records from records.h, and library data is not emitted.
- **Still open, not of a scalar kind:** `unknown` runs of string pointers the text rule dropped (mission and
  condition name lists next to `pointer_table` pieces) and three `.data` items the sources declare `int` that hold
  string pointers (0x0048f6b4, 0x0049f3bc, 0x004c6028). Natively those are 4-byte integers where the code reads
  8-byte pointers.
- **0x00356de0 is already where the project keeps dead code.** The 2026-10-11 function-list pass put the 12,447
  functions nothing references in `build/farm/dead-code.txt` (local) and left them out of `build/functions.csv` and
  the progress denominator; 0x00356de0 is one of them, with 13 more in unk_356bf0's range. A fresh scan (rel32
  E8/E9/0F 8x, short jumps and absolute words over every section) finds no reference. "Every game function has
  verified source" counts the listed functions, so it needs no block. Listing it would change build/functions.csv,
  a local input each queue host keeps its own copy of. integ2's census needs nothing either: the comment on
  DAT_0056bfc8 cites the loads 0x00356dfe and 0x00356e0b and also 0x00356de0, so it holds whether or not the function
  is listed.

## 2026-11-18 clean2: dataset lane and retired-workflow docs removed (D122-D125)

- **Removed:** the fine-tuning lane (export_dataset, train_sft_unsloth, import_external_trainingdata, export_merged,
  profile_experts, docs/dataset-plan.md; last state b365e7087), docs/farm.md, docs/hybrid-build.md,
  docs/port-priority.txt, docs/agents/ and tools/equiv_next.py, plus the untracked junk clean1 listed (backed up under
  build/lead/discarded/clean2-2026-11-18/).
- **Kept:** the live half of docs/hybrid-build.md (the hook-only recording build: what you need, image surgery,
  tweaks, hooks and flags, determinism pins, recording, drawlog, driving xemu) is now the first part of
  docs/tasks/record-replay.md. match-brief.md's register-allocation and vptr studies are in docs/msvc71-pitfalls.md.
  `tools/platform_map.py --priority` writes only build/farm/priority.txt.
- **A stale shared index undid a commit.** 961047f97 (data4) was committed while the shared index still held the six
  files af1790d44 had just removed (that commit was made through a temporary index; the shared entries were synced a
  moment later), so it restored them and the old skill lines; a05fae211 reapplied the removal. Sync the shared
  index entries of committed paths right after the commit, and check `git show --stat` of your own commit for paths
  that aren't yours before pushing.


## 2026-11-18 x64t21: the game's operator delete by its name (D115), the scalar deleting destructors as functions (D114)

- **Almost every "free" in the tree is the game's `operator delete`.** The game's free 0x00267090 has four one-`jmp`
  forwarders: the global `operator delete` 0x0008d330 (3,038 calls; 1,819 of the 1,891 compiler-generated `??_G`
  call it), `operator delete[]` 0x0008d340 (708), `content::LoadObject::operator delete` 0x00263f30 (689: every
  class whose `??_G` calls it derives from content::LoadObject, by RTTI 62/62, and none of the 145 that call
  0x0008d330 does; 0x00263ea0, a `jmp` to the game's operator new, is the class's `operator new`) and 0x00263f40 (2).
  Only 45 calls reach 0x00267090 directly. The tree spelled these ~2,000 calls with ~1,300 different names
  (`thunk_FUN_00267090` overloads, `X_0008d330` suffixes, `thunk`, `SweepTrack_DeleteThis`, `Free`, `opdel`, ...),
  each in its TU's namespace; natively the ones without an address bound to nothing.
- **MSVC 7.1 predeclares only the scalar `operator delete`.** `::operator delete[](p)` needs a declaration at global
  scope (C2039 otherwise); the scalar one needs none. Both forwarders compile to the original's 5-byte `jmp` when
  defined as `void __cdecl operator delete(void* p) { FUN_00267090(p); }` at global scope (inside a TU namespace
  MSVC mangles a namespace-scope `??3fn_x@@`).
- **The native tree's operator delete can't meet the host's.** The native front end is MS-ABI: the tree's
  `??3@YAXPEAX@Z` and the host runtime's Itanium `_ZdlPv` are different names. A missing tree definition is an
  unbound name, never the host's free. (The tree's global `operator new` natively is an `inline` definition in
  CActorManager.cpp, weak, that the linker happens to keep; it should become a strong one.)
- **A `??_G` pin can be shared.** 144 empty-destructor `??_G` blocks pin a symbol another block of the TU also pins
  (identical template instances: Closure/Method pairs); removing the destructor that emits it leaves the other
  block's pin missing. The D114 generator rewrites such a group only when every block of it is rewritable.
- **Dropping /GX after the rewrite.** In the TUs left with no empty-destructor `??_G` block after the rewrite, every matches
  block still matched under /GX-, and two equivalent blocks' code changed (0x00285f50, 0x00254760): those two TUs keep
  `// cl-flags: /GX`; 126 TUs lose it (304 -> 178).

## 2026-11-18 sweep-allocsize: allocation sizes by record (landed)

- Allocation sizes written as the 32-bit literal are now `sizeof` of the record the code constructs, in about 375
  blocks (start-up census group "32-bit-literal allocation sizes"). Details and leftovers are in
  docs/native-build.md "sweep-allocsize (2026-11-18)".
- Natively `size_t` is neither `unsigned int` nor `int`. A TU that declares an allocator under both spellings (here
  `FUN_0008d690(unsigned int)` and `FUN_0008d690(int)`) makes `FUN_0008d690(sizeof(X))` ambiguous under clang for
  arm64 and x86-64, while MSVC 7.1 picks the `unsigned int` overload. Write `(unsigned int)sizeof(X)`. verify --x64 did
  not catch this. A clang -fsyntax-only pass with native_mac's front-end flags (for both Windows triples) did.
- In a TU that has its own stub of a gen class, `sizeof(::Gen)` gives the gen class's size, but a local stub with
  the same name gives the stub's. Check which one a site resolves to.
- A local `char data[N]` stand-in keeps its 32-bit size natively. Writing `n*sizeof(Stub)` changes nothing unless the
  stub is the real record, so derive it from gen's class instead (0x001ff580's CEncounterGenerator).

## 2026-11-18 decl1: callers declare extern "C" callees as defined (batch 1)

- **Callee by the original's target, not by spelling.** build/decl1/scripts/relmap.py records, per tree TU, every
  matched block's referenced symbols with the address the original's bytes reach (verify_relocs.check_object); joined
  with the tree's definitions by address, 3,209 call sites in 725 TUs name an extern "C" definition with a C++ spelling
  (2,327 names: `Alloc_0008d690`, `operator_new`, `?FUN_0008d750@fn_f3919bbe@@...`) and 260 with another C name
  (`_malloc`, `_alloc`, `_snprintf` for the game's 0x0008d690 / 0x000964a0).
- **C linkage makes one function of all a TU's declarations.** Declarations of the same C name in different block
  namespaces of one TU must agree (C2733 "second C linkage of overloaded function"); the existing `extern "C++"`
  declarations were there to dodge that. The generator writes one canonical `extern "C"` declaration per TU and
  callee; when an include/ header already declares the C name, the header's prototype is the canonical one (clang
  rejects a TU declaration that differs from a header's natively even where MSVC 7.1, seeing `int` both times, does not).
- **Natively most C++ spellings were already bound by the address in the name** (plan_link, verified by the Wine map):
  batch 1's 95 callees in 79 TUs took 53 references off "bound by the address in the name" and 16 names off unbound. The
  bindings that changed silently are the invented C names with no address (`malloc`, `snprintf`, `operator_new`,
  `alloc`): natively they bound to the host's libc or to nothing.
- **A binding exposes literal sizes to the x64 gate.** Three `operator_new(0x14)` sites (0x000592c0, 0x0016e070,
  0x0017e910) became `layout` once the allocator bound: they now allocate `sizeof` of the record they construct (0x14
  on 32-bit). 0x00159cb0's record view is shorter than its 0x18 allocation, so its TU stays out (deferred).

## 2026-11-18 script1: the script binding family on records (include/game/script_bind.h)

- MSVC 7.1 compiles the Method<N> / Closure<N> family to the game's own code from plain records: an empty base whose
  constructor is Function's 0x001d0480, the vftable word, ScriptFunctionFields, the member-function pointer and the
  object, with the game's vftables stored by address. A registration helper that had been equivalent (0x000b0440)
  byte-matches on them, as do 36 more after a generator rewrote them, and 91 out-of-line constructors regenerated from
  the listing. So the stand-in classes were never needed for the bytes.
- In a TU that keeps /GX (D24), `new` of a record whose constructor may throw gets an unwind frame that the game's
  code does not have. Declare the constructors throw(). The game was built without /GX, so this only undoes the
  tree's /GX.
- A second extern "C" declaration of a C name with another type is an error under clang and accepted by MSVC.
  Several TUs declare `FUN_001d04d0` with their own types. A shared header therefore declares the callees under
  C++ address names in its own namespace. The links bind them by address, and verify_relocs / equiv resolve
  `DAT_` / `FUN_` names by name. `hulk_at_` data names in a namespace are only paired by position in equiv.
- A local native estimate with an older Wine map counts new spellings as unbound. That covers renamed definitions
  (the map's `def` is the old symbol) and special members such as `??0FUN_001d0480@hulk_script@@`. The proof's own
  map is the measure.
- The bound callbacks bind by IR shape only: a stdcall free definition `void (const char*)` binds to a caller's
  `void ()` member declaration, and then reads the Lua argument from the `this` register (the FE's `fe_SetupSM*`).

## drive1 (D139, 2026-11-18): blocker B1, the U: save drive's wild request node

- **Root cause.** The save drive's own views of itself were 32-bit pad views (`char pad[0x60]; unsigned result, size,
  count, sector; ...`, `pad[0xb4]`, `pad[0xcc]`). 0x00278b50 (the media query the mount runs) writes `sector = 512` at
  +0x6c and `count = 0` at +0x68. Natively those 8 bytes are core::Drive's request list head (records.h
  CoreDrive.requests is at +0x68 on arm64), so the head became 0x200_00000000 and core::Drive::vfunc_3 0x00272df0
  read `node->next` at +8, the wild 0x200_00000008. The gate's three baseline blocks of the cluster (0x00270c80,
  0x00270f10, 0x00270f90) were not the cause: as census1 noted, the gate does not see a cross-block view mismatch.
- Every view in XboxSaveDrive.cpp is now records.h CoreXboxSaveDrive (or CoreDriveThread). The save block cache
  DAT_0052c270 is read by its fields; as +4/+8/+0xc byte offsets the 64-bit builds hit the buffer pointer's upper half.
  Find handles are pointer-sized. FUN_0026fd50 has one C declaration, the definition's; the C++ overloads bound
  nothing, so vfunc_5's rounding was lost.
- The memory-card manager's U: slot (0x0008c470: `FUN_0008d6d0(0xc8)`) is a record now. Its two 0x54-byte blocks are
  copies of core::Drive's media block (+0x60: result, size, count, sector size, label), which
  core::DriveMediaRequest::vfunc_1 copies in 21 words. decls/drive_media.h holds CoreDriveMedia (nested in CoreDrive,
  so one copy is right on every target), GameMemoryCardSlot and GameMemoryCardManager. Ten memory-card blocks indexed
  the slots with 0xc8-byte pad strides. The media request stored its target as an int over the drive pointer, and
  InstanceDrive's slots 4 and 11 took that pointer as an int.
- Lesson: a struct view `char pad[N]; T field;` of an object that has pointers before N is wrong natively even when
  every sibling block uses the record. It writes into the record's fields at shifted offsets. The crash shows up later,
  in another TU's walk of the field it hit (here the request list). Look for the writer through the field's 32-bit
  offset.

## 2026-11-18 script1 2: five more manager constructors on records; find1 F3 / F5

- When the stand-in templates are kept, a per-instantiation trait (`template <class X> struct VftOf;` specialized per
  Method/Closure instantiation, returning `DAT_<addr>`) gives each template constructor its game vftable without
  touching the call sites. MSVC inlines it to the same immediate store.
- find1's F3 (snd_MapInstance, called by map.lua during registration) and F5 (subtitles' default shader) are fixed at
  the root: game vftables by address, HulkShader's size and its constructor by address.

## 2026-11-18 sweep-caster: the game's casters by vftable address (landed)

- Local polymorphic stand-ins for the game's casters (DynamicCaster, Track/ConditionFactoryCasterTemplate) got
  clang's own vftable natively, with an undefined slot and an 8-byte object in a 4-byte frame word. They are now
  records that store the game's vftable by address (`DAT_<vtable item + 4>`), in about 500 sites in 102 TUs. Details
  and leftovers: docs/native-build.md "sweep-caster (2026-11-18)".
- The census that finds caster sites by class name misses local spellings such as `Caster_17ca00` or `Caster`. Using
  config/data.json's vtable xrefs (each caster vftable's referencing functions) found 47 more in two TUs. A sweep
  should start from the xrefs, not from names.
- A gate failure that only appears because a fix changed a block's code can already exist at HEAD. Run the same
  `equiv.py --x64` on HEAD's source before blaming headers or other agents. Three of the four were allocation sizes,
  and `sizeof` of the record fixes them without touching the 32-bit code (the code hashes stay the same, so no
  re-proof).

## drive1 follow-up (D139, 2026-11-18): the 64-bit gate on aaa0a1573

- The gate on aaa0a1573 found three NEW blocks. 0x002728d0 and 0x002783d0 took `this` as an owners.h stub (a 0x60-byte
  and a 0xd5-byte pad) and cast it to the record, so the checker allocated the stub and the native offsets read past it
  (layout). 0x00278de0 read the cache DAT_0052c270 while the checker still modelled it as untyped words (crash64).
  Fixes: the two functions are defined on the record (Drive_2728d0 : CoreDrive, XboxSaveDrive_2783d0 :
  CoreXboxSaveDrive), and their callers keep the owners spelling, bound by the address in the name. The cache is now
  a typed record, records.h CoreSaveBlockCache, regenerated with data_gen. All three are `equivalent` under --x64.
- Lesson: when a block casts `this` to a record, declare the class as the record. The 64-bit check builds `this` from
  the declared class, not from the cast.
- aaa0a1573 was pushed by another agent's push before its message was final: its "PROOFLINE" line is a placeholder.
  The proof for it and this follow-up is in this commit's message.
- aaa0a1573 broke the Wine build's materialize on HEAD: its records.h edit moved MSVC 7.1's code in four equivalent
  blocks of TUs that do not use the records (0x00027930, 0x000b86b0, 0x002e9c60, 0x002ea3c0; the records.h effect
  noted for 0x000b86b0 under data3). With this commit's records.h, 0x002e9c60 is back at its proven code; the other
  three are re-proven on MSVC at 3,000 (their clang code is unchanged). A records.h edit needs the whole-tree verify
  before landing.

## 2026-11-18 decl1: int parameters the definition passes as pointers (batch 2)

- **Native signatures per call site.** build/decl1/scripts/sigcmp.py compares, for each matched block's call (callee
  by the original's target), the native IR signature of the caller's reference with the definition's (the native
  compile's `.sig.json` sidecars). At HEAD e28b9f41b: 11,826 sites agree, 1,744 differ only by an ignored result, and
  the rest differ: int / int64 (pointer) arguments 1,217, argument count 272, result i32 / i64 169, float / int 113,
  i32 / i8 99, bool / int and bool / char ~170.
- **The int / pointer case is MSVC-neutral.** Where the caller passes a 32-bit int and the definition a pointer or
  pointer-sized integer, the caller's type becomes the pointer-sized integer of the same 32-bit type (`int` ->
  `hulk_intptr`, `unsigned` -> `hulk_uintptr`, `long` -> `hulk_longptr`): MSVC's code and mangled names stay the same,
  and natively the declaration passes 64 bits as the definition does. Call sites that cast a pointer to `(int)` still
  truncate it natively (the native compile's `64bit-pointer-int-cast` diagnostics list them).
- **Only rewrite when the whole signature then agrees.** A first pass also retyped references whose signatures differ
  elsewhere too (a definition that takes an int where the caller passes a pointer, a bool / char result): their names
  changed spelling and stayed unbound (52 "new" unbound names that were old ones respelled). gen_sig now rewrites a
  reference only when, after the fix, it passes exactly as the definition does.
- Names that carry no address (`Init`, `BaseCtor`, `vfunc_24` of a local stand-in) don't bind natively either way; the
  pass respells 10 of them (old spelling unbound, new spelling unbound).

## 2026-11-18 decl1: batches 2b and 3 (pointer-sized int declarations; extern "C" spellings)

- Batch 2b continues 2a's int -> `hulk_intptr` retyping: 164 references in 116 TUs. Batch 3 is gen_decl's
  extern "C" spellings in the TUs other lanes had dirty during batch 1: 35 callees in 29 TUs.
- **The allocator binding exposes the layouts of local stand-ins.** In three more TUs (SemaphoreWaitTrack_4,
  fight/WaitTrack, fight/StopTrack), calling the allocator by its C name makes the x64 gate see a 32-bit local stand-in
  inside a larger native allocation (`layout`). Those TUs stay out until their stand-ins are records.

## 2026-11-18 audio1: the audio om::Type registry on records (D140, census1's B2 and S12-S17)
- The ~25 static audio om types that 0x002407a0 initializes were built by constructors on local polymorphic
  stand-ins: natively each stored clang's own vftable (slot 0 had no definition), one copied only 4 bytes of it
  (null upper half: census1's "15th type"), one memcpy'd it, and two initializers constructed into `gObj`, one
  namespace-scope name the TU used for six different objects (verify_relocs checks each block alone, so each use
  verified against its own address). Now every constructor in the chain (om::Type 0x002584d0, om::EntityType
  0x00243310, om::MetaEntityType 0x0025e6c0, audio::SeqEventType 0x002605e0 and 29 leaf types) works on the
  records.h record and stores the game's vftable by address.
- Slots 0 / 1 of the 22 audio::SeqEvent*Type classes were 5-byte `jmp om::Type::vfunc_0/1` thunks listed "not yet
  verified": with no definition the native game vftable held `hulk_x_` stubs. They are 44 matched blocks now
  (`void X::vfunc_0() { ((om::Type*)(void*)this)->om::Type::vfunc_0(); }`, MSVC 7.1 emits the jump).
- om::EntityType's 32-bit `reserved48[8]` is two tree nodes (by key, by flags) whose keys the tree code read by
  32-bit distances from the node (n - 0x18, node + 0x10); the views take the key from the record by container-of.
- A static .data tree whose words point at its own sentinel (0x004cd1a8, the om types by key) was two items
  natively, so `&tree->nil` was not where the links pointed and the first insert never ended. It is a records.h
  record now, and data_gen points an initializer word into a typed record at the field (`&DAT_x[0].nilLeft`), not at
  a 32-bit byte offset. Same for the om::Allocator objects (0x004cc200, 0x004e36c8: 12 bytes, 24 natively) and two
  "sound/rsd" Strings.
- The declaration-count blocks moved again with these headers (records.h, gen/om.h, the generated data headers):
  0x002ea3c0, 0x000b86b0, 0x00027930 and 0x001a9b10 re-proved at 3,000 MSVC + `--wine` (jobs 91794-91801) and recorded
  by `hash --proven` run on a queue host. A local `hash` in a private workspace once recorded the other code than the
  queue's verify compiled: record these from a queue job with the final files.

## 2026-11-18 decl1: C++-named data globals as the data's C name (find1 F15)

- 620 unbound native names are data variables declared in a TU namespace (`extern Obj_87990* gObj_87990;`,
  `extern void* pvtable;`, `extern int gTypeA_23d070;`). Natively they bind to nothing; most are the game's vftables
  stored by address and RTTI type descriptors passed to the dynamic cast. relmap gives each name's original
  address, so build/decl1/scripts/gen_data.py declares the data's C name instead (`extern "C" char DAT_<addr>[];`)
  and writes each use as `(*(T*)&DAT_<addr>)`. MSVC compiles that to the same access. Natively the name binds to the
  data item, or to the vftable / RTTI label the link emits.
- Not converted: 302 names whose declaration isn't a one-line scalar or pointer declaration in the TU (arrays, multi-line
  `extern "C++" {}` blocks, declarations in headers). Also 36 names declared several times in one TU, 15 names that
  reach several addresses (a stand-in reused for two vftables), and names an equivalent block references.

## 2026-11-19 script2: D24 retired; the invoke blocks' pad views on Function's fields

- **D24 is done: no Method / Closure / Function `??_G` is an empty user destructor any more.** The 288 script-binding
  scalar deleting destructors of 146 TUs (x64t21's D114 generator had skipped them: template instantiations with a
  `template class` line, and 144 blocks pinning a `??_G` symbol another block also pins) are explicit functions in
  D114's form, `void* vfunc_N(unsigned int flags)`: Function's destructor 0x001d04a0, then `operator delete(this)` when
  flags & 1 (every one of them calls 0x0008d330, D115). Each block now pins its own symbol, so the shared-pin groups
  disappear. The template destructor specializations (`template <> Closure1<...>::~Closure1() {}`) and the native-only
  `template class` lines stay: other TUs' native code references `??1`. All 146 TUs compile with /GX- and every
  block MATCHes with relocations ok, except one equivalent block whose MSVC code changed with the flag (0x00040550,
  CCharacter.cpp), re-proven at 3,000 inputs. Generator: build/script2/scripts/gen_mc.py (reads a HEAD snapshot).
- **/GX left: 32 TUs** (178 before): the 8 parameter-registration TUs (100 `??_G` blocks, D18), 19 TUs with one
  non-template `??_G` each, 4 with no `??_G` block whose equivalent code changes without /GX, dynamic_initializers.cpp
  and GrappleThrowAction.iso_00148f40.cpp (docs/tech-debt.md).
- **Invoke blocks' pad views (script1's Q2).** 89 `Closure<N>` / `Method<N>` / `Function<N>` `vfunc_2` blocks in 21 TUs
  read the member-function pointer after a `char pad[0x18]` (or `[0x1c]`, `[0x1c - sizeof(Function)]`, `[0x1c - 4]`):
  natively that put the pointer at +0x20 instead of after Function's 0x28 bytes. They now say `ScriptFunctionFields
  fields;` (after the vftable) or `void* vftable; ScriptFunctionFields fields;` (a view without virtuals). The 32-bit
  code is unchanged in all 89 (the 29 equivalent blocks keep their code and view hashes: no re-proof). Two small pads
  (0x0007ced0, 0x0009ac30) are not Function views and stay.
- **Bound callbacks defined as free functions are members now (script1's Q1, first TUs).** A Lua closure calls its
  member-function pointer with `this` in ecx. A callback written `void __stdcall F(int)` matches the same bytes when
  `this` is unused, but natively (x64 / arm64, where thiscall and stdcall are one convention) the member call puts
  `this` in the first register and the argument in the second, so the free definition read `this` as its argument.
  The 29 definitions in CRenderManager, CWorldStreamManager, unk_2036c0, ScriptHandler, CSoundResourceManager and
  CEventManager are `R CB_<addr>::FUN_<addr>(the RTTI instantiation's types)` (a block-local record), and their binding
  sites declare the same signatures (Vector getters return `math::Vector` by value: MSVC's thiscall hidden-return code
  is the stdcall `V f()` code). Every one still MATCHes. Its other callers in the tree already call them as members,
  with their own (often wrong) parameter types: 0x00204200 has 9 such callers in 9 TUs, 0x001b8780 / 0x001b8900 are
  called from the replay pin 0x00086630 with `int` for `bool`. Those callers are decl1's list.
- **A helper whose name starts with `DAT_<addr>` is read as that data address by the checker.** An inline function
  `DAT_004c55f0_1cfb20()` that clang did not inline became a call to 0x004c55f0 in the `--wine` run. Never give a
  function a `DAT_` / `FUN_` prefix that is not its own address.
- **Manager constructors on records (script1's list).** HUD 0x000d1720 (44 closures, incl. a Method5 now in
  include/game/script_bind.h), scenario 0x001cfb20 (Closure1s) and 0x001cf690 (stack Closure2s), trigger volumes
  0x00200c10 (Closure1s): records with the game's vftables by address. HUDOverlay's and CScenarioManager's own vftable
  words are stored by address too (they were placement-new stand-ins with clang's vftable natively).
- **159 more out-of-line Method/Closure constructors on records (find2's start-up stops).** script1's genctor skipped
  blocks that were merged into their TU's namespace, and wrapped blocks in TUs that were dirty at the time. Their
  base constructors were local names (`Function_1f0c00(const char*, int)`, `Base`, `CheckString_001d04d0`,
  `Lookup` / `GetValue`), which bind to nothing natively. build/script2/scripts/genctor2.py reuses genctor's
  gen_block for those blocks; all 159 MATCH with relocations ok (28 TUs, including CSoundSystem's Method3/4/6,
  CFEManager's Method6/7 and CUnlockablesManager's Method6). 0x001f30e0 (CSoundVoiceManager), which the Closure4
  invoke calls as a member, is a member too.

## 2026-11-19 recs1: records for find1's start-up stops

- pure3d::View is 0x140 bytes (gen had 0xc0: the constructor 0x00294880 writes two matrices at 0xc0 / 0x100); its
  words are the viewport, camera, ambient, clear colour / depth / stencil / mask, fog colour / start / end, 32 light
  slots and the fog flag (0x00293ef0 reads them all). With the record the constructor is a byte match storing the
  vftable by address. A TU that both calls a View's slots and writes its words gets the words through
  `HULK_VIEW_WORDS` after its own vptr: a non-polymorphic record plus a cast for the slot call made the 64-bit checker
  lose the object (a field cast to two records is `view_ambiguous`; a HulkView-typed result whose vftable word is
  fuzz crashes every input).
- CGame (0x54 bytes) holds the triple and 18 managers as pointers; its 15 getters read pointer-sized words now
  (find1 F6). 0x00086350 (named CJumpTrack::vfunc_26 by a propagated shape) is CGame's pair getter.
- The listener effects' attribute offsets 0x28 .. 0x54 are offsets into audio::ListenerEffectXBox (OmEntity, then
  the twelve I3DL2 listener settings 0x00241280 copies to the device); natively they are offsetof() on the record.
  OmMetaType +0x30 is the base meta type (0x0025fb00 recurses into it, 0x0025fad0 searches it next), not flags.
- 0x002407a0's x64 `int` class comes from DAT_00527c58 (the content registry) being an incomplete DataLayout to the
  checker, not from the String: typing that global (records.h HulkContentRegistry) is data5's.

## 2026-11-19 fix126 (D126): the triage's real source bugs, re-proven

- integ2's D126 triage found 15 blocks whose source was wrong, not the checker. They are fixed and re-proven at
  3,000 inputs (MSVC and --wine, plus --x64), and recorded by `hash --proven` from queue jobs:
  - luaK_concat 0x002207c0 passed -1 instead of the last list entry.
  - 0x00107760 missed the store to f.z.z.
  - 0x002eea80 tested the link count as signed.
  - lua_pushcclosure 0x002134a0 read L->top once.
  - LoadBlock / LoadConstants 0x0021f8c0 / 0x0021fe20 read the byte before storing p+1.
  - 0x00281fd0 loaded before it stored.
  - 0x001c82c0 and 0x002d5a70: `(int)(__int64)`, the low word of `__ftol`'s 64-bit result (clang's `(int)` of an
    out-of-range float is 0x80000000).
  - 0x002d5a70 also copies pos word by word.
  - 0x000e8cf0 (w4) and 0x002d21c0 (v14): D112 `unsigned char` returns.
  - 0x00201e00: a dword out-parameter declared `short`.
  - 0x00148f40: Hit is 0x98 bytes, not 0x90; the TU's gx1 `/GX` line is dropped.
  - 0x002b2040: slot 19 takes no argument, and FUN_002899e0 gets its 8th argument and its definition's return. This
    needed integ3's prepushed-argument checker fix, de44977ea. Its `(char*)this + 0x40` became a field, which fixes
    the --x64 `layout` result.
  - The unproven baseline loses 18 modes.
- 0x002d21c0's 1-ulp q.y came from dx/dy, not from the products: the original keeps `to - from` in st. The products'
  `(hulk_freg)` changes nothing under `-ffp-eval-method=double`. tools/x87_order.py found it; the triage's sketch
  didn't.
- The code hash follows a block's references. 0x00283e10's hash changed with an uncommitted caster edit (sweep2's)
  in the same TU, so stage only your own hunks when proving a block in a TU with others' edits.

## 2026-11-19 integ3: proof-integrity findings (allocty, arity, RTTI gate, D126 REF hole, input_guard)

- 0x0008c470's crash64 was the harness, not the source, and not the stubs drive1 suspected (they write nothing). The
  slot comes from FUN_0008d6d0 (an allocator stub): its region was raw bytes, the same byte for byte on both sides,
  and the code reads `slot->drive` before writing it (the stubbed initializer would). The 32-bit run read a 4-byte 0,
  the 64-bit run an 8-byte garbage pointer. equiv64's fix ("allocty", rev5-adopted, not landed yet) draws the
  record's leaves over a fresh allocation the allocator returns as a record; more than element 0 only at
  `n * sizeof(T)` sites; a header's payload stays raw, counted from the header's end. 46 -> 400/400 completed.
- Arity attribution (de44977ea): MSVC hoists a call's own argument push above a conditional jump (0x00081b20); clang
  functions without a reserved argument area open one per call, so "the next `sub esp`" is the next call's; a
  virtual called with `this` in ecx is __thiscall and pops its own words, so a word released after a later direct
  call is that call's (0x002b2040). The brute-force pop solver hit its cap at 622,080 combinations; the exact
  solver agrees with it on all 30,559 functions it resolved.
- RTTI exact names (46518a83a, D147): a TU-local polymorphic stand-in shows up twice, at its casts and in its
  vftable's complete object locator (??_R4 -> R3 -> R2 -> R1 -> R0). The COL rows were 4,545 of 4,695 seed entries;
  ScriptFunctionFields appeared in 512 TUs only as the base of local `virtual` Closure/Function stand-ins (script2
  removed 848 entries in c7ef3a154). Exactness follows the runtime's unwrap (`(?<=@)fn_<8 hex>@`), not a looser regex.
- D126's growth check failed open in queue jobs (19ddec138): with no git in the workspace, `git show REF:` failed and
  read as "REF had no list", so seed stamps vouched for themselves. Any check that compares against REF's copy of a
  config file must tell "absent at REF" from "unreadable".
- input_guard (260c93696): a stale refusal now names the commit the input was built from (stamp files.json
  built_from) and the job's commit; a workspace below the checkout is not the checkout's HEAD.
- R5 (faac4ce73): 17 of 45 re-proofs promotable; unproven baseline 150/192 -> 146/183.

## 2026-11-18 decl1 batch 4: the three generators over the TUs left out before

- gen_decl, gen_sig and gen_data, run in that order on one snapshot, over every TU without another agent's uncommitted
  edits. That includes the script-binding and audio TUs script1 and audio1 have since landed. 194 extern "C"
  callees, 47 pointer-sized int references and 1 data global, in 122 TUs.
- Two generator bugs found here and fixed: a global C++ function (`?FUN_001d04d0@@YADPBX@Z`, no namespace) was taken
  for a member, and a TU with no `#include "tree_prelude.h"` line made gen_decl stop before the rest of the batch.
- 5 TUs whose equivalent blocks' checker view changed (CScenarioManager.GS, CWorldStreamManager, CSoundResourceManager,
  HUDOverlay_2, CRenderManager) wait for the equivalent re-proof batch.
- **U: 64-bit keys the slot definition takes as two words (find2 G4 family).** In 18 TUs, the inventory find slot
  (content::LoadInventory::vfunc_3 0x00266280, `(Matcher*, int, int)`) is now called through views that pass the key as
  two `unsigned int` words natively. The 32-bit side keeps the original u64 parameter in `#if defined(HULK_PTR64)` /
  `#else`, so MSVC's bytes and the Wine build don't change. Natively a u64 is one register, so the definition read
  a garbage high word.

## 2026-11-19 script2 2: the invoke functions without stand-in vftables (RTTI)

- **The script-binding invoke functions (`Closure<N>/Method<N>/Function<N>::vfunc_2`) are plain members now.** 536 of
  them were written as `template <> void Method2<C, R, A, B>::vfunc_2(...)`, a member of include/gen/global.h's
  polymorphic template. Each specialization made clang emit the template's vftable and RTTI natively: the D147 gate
  counted about 2,000 such entries. They are now members of a block-local record on
  `hulk_script::FunctionGenView`: gen Function's fields by their gen names, after a plain vftable word. f_1c is typed
  as gen's (`R (::C::*)(A...)`, with the gen class qualified with `::`), and f_20 keeps gen's type. Generator:
  build/script2/scripts/geninv.py. The blocks' native-only `template class X<...>;` lines go: the D114 functions
  already bind the game vftables' slots. 75 more were written on block-local polymorphic stand-ins (`struct Function { virtual ...; }`): they lose `virtual`, and each
  root class gets a leading `void* vftable;` (build/script2/scripts/genlv.py). All 481 converted matches blocks still MATCH. The
  130 converted equivalent blocks keep their MSVC code; their checker views changed (the `this` class), and they are re-proven
  at 3,000 inputs, MSVC and --wine.
- **f_1c must carry gen's member-function-pointer type.** With `ScriptMemberFn` (one word, 4 bytes) every block still
  MATCHed, but `equiv.py --x64` no longer recognised the field as the bound function: the harness gives a
  member-function-pointer leaf a stub only when its pointee prototype is the call's. Of 659 changed blocks, 426 became
  `unsupported:no32`, because the 32-bit side called a random word, and 5 became NEW layout failures. With gen's type
  qualified as `::C`, all blocks MATCH and --x64 runs. The same type written without `::` resolved to a block-local
  class and changed MSVC's code.
- **Manager constructors on records:** camera 0x0009dd20 and ambients 0x0007f950 (the `G<N>` macro family:
  build/script2/scripts/genmgr.py, vftables from the XBE listing in call order) and sound resource 0x001ea8b0.
- **Natively a gen template's vftable outlives its specializations.** D114 keeps `template <> X<...>::~X() {}`, and
  that destructor emits gen's vftable for X natively. Its slot 2 (`X::vfunc_2`) then has to be defined: the converted
  invokes keep a native-only specialization that forwards to the record's function.

## drive1 (D141, 2026-11-19): the native save round trip

- The save path from CMemoryCardManager down to the SDL shim now runs on arm64 macOS. A 0xbe8-byte save goes through
  the game's 0x0008cbe0 and the InstanceDrive's open, core::File's write and commit, and XboxSaveDrive's signed 8 KiB
  blocks. It is then read back through the same open and core::File's read, with the signature check, and the data
  comes back identical. The new host test tests/native_host/save_roundtrip_test.py drives this through
  src/platform/sdl/host/save_selftest.cpp, an entry hook on 0x0008c470 that only acts under HULK_SAVE_SELFTEST=1.
- Each break had the same shape: a value the 32-bit code passed as an int and natively had to be a pointer, a 32-bit
  view of a record, or a callee declared with a different IR signature from its definition. Examples:
  - the save's name, data, image and buffer were `unsigned` in vfunc_9 / 12 / 13 and in 0x0027a370 / 0x0027a460;
  - the request's file (SaveGameOpenRequest, the save File constructor 0x002763a0, InstanceDrive slot 35 / 36);
  - XDK calls declared with int handles (now decls/save_xdk.h, one declaration each);
  - `bool` against `unsigned char` returns and an `int` against `unsigned char` parameter.
  The native link refuses the last kind at the IR level, even where native_unbound's register-class check calls them
  compatible.
- Lessons:
  - a constructor called through a class named by its address (`struct FUN_<addr> : Record`) does not bind by the
    address in its name natively ("special member of a class named by address"); the Wine map binds it by name;
  - unifying a callee's declaration with a definition in the same TU lets MSVC 7.1 inline it (0x00278ef0 lost its
    call to 0x00278180); keep the caller's overload distinct;
  - an equivalent block whose --wine run faults on an unterminated buffer may just have its locals in another order
    than the original: vfunc_9's path ran into the return address until the title / path / drive and share / access /
    byte-count locals were declared in the original's frame order (clang -O0 places them in declaration order, the
    first one highest); its unproven-baseline entry is gone;
  - a local native run after symbol changes needs the snapshot's report.json refreshed (build/drive1/scripts/fixreport.py)
    and the binding map extended (augmap3 plus the class-named constructors by hand).

## 2026-11-19 fix126 (D126): float group, first seven (D80)

- 0x000396a0: u, v, dot and the new angle stay in st, and the angle is compared before its store. atan2's differences
  come from the unrounded result.
- 0x000a0330: the wrap loops run on a hulk_freg.
- 0x000a4b90: speed, and the stored-then-compared angle, are hulk_freg.
- 0x0011ce20: the dot is compared from st.
- 0x002a5570: the inlined Smooth returns a hulk_freg (a TU-local helper names no external symbol).
- 0x002b4710: nx/ny/nz are float. The original rounds them through the frame, and the second vertex adds the offsets
  to the rounded values: the opposite of the triage's guess.
- 0x0030aef0: `!(|v| >= |newVel|)`, so an unordered (NaN) compare subtracts, as the original's C0 test does.
- tools/x87_order.py misses roundings inside TU-local helpers (a call leaf); check inlined helpers' return types by
  hand.

## 2026-11-19 script2 3: the Lua dispatcher's native argument cells (find3's start-up stop 6)

- **The dispatcher 0x001d22a0 packs each argument into a 4-byte cell; natively the invokes read pointers as 8 bytes.**
  Closure4<CSoundVoiceManager,...>::vfunc_2 read its three `char*` from `VoiceArgs { char* first, second, third;
  int fourth; }`: at 0/8/16 natively, but the dispatcher wrote them at 0/4/8, so CB_001f30e0 received
  name = 0x100000001.
- **Fix (natural layout, native only):** under `#if HULK_PTR64` the dispatcher gives a pointer argument a
  pointer-aligned, pointer-sized cell, so the buffer has exactly the natural native layout of the argument list (a C
  struct of the argument types). The 32-bit code is unchanged, so its proofs stand.
  - Hand-laid argument structs and all-pointer arrays already read that layout.
  - 22 invokes read the second argument at `(char*)p + 4` after a pointer. They now read `+ sizeof(void*)`: the same
    32-bit code, and they still MATCH.
  - 8 invokes index int arrays to get pointers or pointer arrays to get floats, or call the bound function with the
    32-bit cells punned (0x001b16b0, 0x0002d8c0, 0x0003f010, 0x000bfef0, 0x001bf5f0, 0x00094b10, 0x000ceb30,
    0x000cec00). They get a native-only body that
    reads a struct of the instantiation's types (`#if HULK_PTR64` ... `#else` the 32-bit body).
- **Buffer size:** the largest native argument list is 56 bytes (0x0002cc10 / 0x0002ebc0 `pVsppsp`, 0x000be8f0
  7 x `char*`, 0x001dfb80 `ppspVV`). It is within the 0x40-byte buffer, including the Vector writer 0x001d1f30's
  this-relative bound.
- **(script2) hack_IsFieldGoal: a `bool` declaration of a `char` definition does not bind natively.** CGame's
  constructor 0x00087e80 declared 0x00096f40 as returning bool, but the definition returns char. MSVC 7.1 compiles
  either the same, while natively i1 and i8 are different signatures, so it stayed unbound. Declared as defined, it binds.

## 2026-11-19 integ3: D152 range contracts, D153 split pins, the queue's base commit

- D152 (8b982fc60): a range contract (`HULK_PRE_GE(dt, 0.0f)` + `// pre: ge(arg4, 0)` + `// pre-callers:`) is enforced
  natively (a trap) and repaired into in the checker. Expected follow-on: the callers of a contracted block pass it
  values from their own fuzzed inputs; 0x000a75d0 (the caller of 0x9fb20) comes out `pre_violation_in_original` as soon
  as 0x9fb20 is contracted (tau is the fuzzed global DAT_0049ec84). Each such caller needs its own contract, or a model
  of the global (HULK_RANGE / HULK_RDATA with its census), before it can be proven.
- D153 (345179548): a split of pushed words that only our own code makes is no evidence; a per-input set-aside of the
  unpinned inputs made a real bug (0x00264050_msplit_noword) promotable, so the rule fails closed at the block.
- A repair of a contract word must be applied after any directed patch of the same word (a dict update keeps the old
  key's position): before D152 a patched input could undo the repair (a false failure only).
- Coverage-ratio regress cases fail deterministically on mac1 with every checker (0x000ffef0_compare_chain,
  0x002cb2b0_loop_exit_order, 0x003037f0_iterator_range; control 100463): a host difference, not load.

## 2026-11-18 data5: string-pointer lists the text rule cut (D128); bss records typed by records.h (D129)

- **The text rule hid 689 pointer words in 45 items** (docs/data.md "String-pointer lists the text rule cut"). Name
  lists whose string addresses read as text (`30 5c 3f 00` = "None" at 0x003f5c30) were cut into `unknown`, 1-byte
  `string`, `table` and `pointer_table` pieces, or kept as integers inside `struct`s: natively 4-byte words where the
  code reads 8-byte pointers, or a list that runs from one item into the next. data_inventory now takes such a word
  when it points at a string start and sits in a run of pointers (`string_pointer_runs`). Besides the lists the lead
  named, it finds the unlockables (0x0049ceb0, 766 names, 188 hidden pointers), the mission objectives (0x004061e8,
  213), the credits (0x004c3c18, 661 lines: an `unknown`/pointer patchwork before), om::String's operator list and
  zlib's messages.
- **Two original overruns, kept and made safe.** SmartPropGrabbableCondition passes its objectClass list (22 names;
  csmConsole is missing) with a count of 23, so the game reads the first weaponType name after it; CSPManager's weapon
  loop ends at the next item's address and the credits loop 0x001baab0 at the address after its table. The overlapping lists
  are one item (0x004c5fd0 `const char*[29]`, 0x0048f6cc `const char*[4]`) and the sources name the inner lists and
  ends by index (`&DAT_004c5fd0[22]`, `DAT_004c3c18 + 661`): the MSVC bytes are the same, natively the reads stay
  inside one array.
- **The movies' track mixes are records.** CRadMovieRenderLoop's tables (0x004341a4..0x0043423c and the French /
  Italian ones) are {count, entries} / {track, count, bins} records that movie::PlayerBink 0x00333ab0 copies through
  pointer-holding records: records.h `MovieTrackMix` / `MovieTrackMixEntry`, one item per referenced start.
- **The cow's animation keys (sweep2):** 0x004dd270 is `Entry_835a0[6]` (one `.bss` item; 0x000835a0 indexes 0..5),
  not six 16-byte items; 0x0035cec0 initializes them by index.
- **D129:** 104 `.bss` records.h items carry their declaration's type in config/data.json instead of stale source
  votes; data_gen's output is unchanged.

## 2026-11-19 script2 4: gen's script-binding templates no longer instantiated natively

- **Native `template class X<...>;` lines were what kept D114's destructor specializations alive.** The 245 native-only
  explicit instantiations of include/gen/global.h's Closure/Method/Function templates instantiated each class's
  declared, undefined `virtual ~X()`. With the 664 `template <> X<...>::~X() {}` specializations dropped, those lines
  made 367 `??1` unbound. With the lines dropped too, nothing natively instantiates gen's polymorphic templates any
  more:
  - the game vftables are emitted by native_mac;
  - the D114 explicit functions bind slot 0;
  - the record invokes bind slot 2.
  So the 536 native-only forwarders (a84e0c824) go as well.
- In a native mac link of the stop-6 snapshot with the 185 TUs overlaid, unbound went from 10265 to 10150, with no new
  names. The 32-bit code is unchanged: the destructor specializations defined only unpinned COMDATs.

## 2026-11-20 integ3: equiv budgets by work, not time (workclock); per-host selftest (hostcheck)
- Three regress coverage cases failed on mac1 and passed elsewhere. Host probes (jobs 100640-100642) found the same
  unicorn, capstone, clang, XBE and symbols on every host: the cause is speed. The run loop's budget was CPU time and
  mac1 (M1 Max, Python 3.12.3) does about a quarter of mac2's work per second, so in 120 s it reached 51 inputs of
  0x002cb2b0 where mac2 reached 532.
- equiv.py and equiv64.py now count work: per emulator run, a fixed cost plus one per instruction and one per stubbed
  call (equiv64: per hook call), fitted to CPU time on mac2/studio (128 and 64 tree blocks). The verdict, inputs and
  coverage are identical on all three hosts (100855-100857); mac1 takes ~3.5x as long. CPU time is a safety cap only
  (8x); a run it cuts is unsupported / time_cut_wall, and equiv64 decides hangs by steps alone. The budget knobs count as
  switches (a run with one set proves nothing).
- `equiv.py --selftest` and tools/host_selftest.py: six fixed cases must reproduce the recorded summary exactly
  (including the uncovered-edge set and an ordered digest of the inputs); a host that differs loses the queue's
  `equiv` cap until it passes again.
- The budget had hidden a real difference: at 3,000 compared inputs 0x000ffef0's MSVC object stores this+0xc8 one ulp
  off from input 839 on (0x44797bef vs 0x44797bee; job 100932, --wine is equivalent). The regress case passed only
  because the 120 s budget ran out first (mac2 stopped at input 859, studio at 752). The block's msvc mode was already
  in the unproven baseline; fix126's source fix (fbc read through volatile) passes at 3,000 compared (94008).
- The seven regress failures that predated this were fixture rot and one objkeep bug: three cases followed tree changes
  (a data declaration's header, `void* dst`, data.json's GameLanguageName typing), sitecasts was retyped as the tree has
  it (equivalent, with a new must-fail _wrong variant), and objkeep's kept object pointer now ends at the virtual call
  (it pinned the word for every later epoch).

## 2026-11-20 sweep3: gen records completed from their allocations
- gen's 32-bit size can be wrong in both directions. Below the allocation, most gaps are the last word that no
  constructor writes, or tUIDs (0x0027af00) and helper objects the constructor builds in place. Above it, the RTTI
  merge attributed fields to the wrong class: physics::CollisionSphere is 0x78 in gen, but its constructor 0x002efe50
  writes 0x48 bytes and every allocation is 0x48. Before writing `sizeof(::Gen)`, compare gen's size with the literal.
- Hand-written constructor views that pad fight::Track's words (`char pad[8]` after the vftable) put the derived
  fields 4 bytes early natively, because Track's f_04 is a pointer. The 32-bit code is the same, so only a native
  size probe (xtu alloc rows) shows it.
- `tree_tu.py pin` with no records resolves an unpinned block by its name. When the block's function moves into a
  local record, that lookup can pick an inline constructor of another class in the TU. Pass `--records` with the
  definition's own symbol.

## 2026-11-20 integ4: stubexit (loops a stub ends)
- 0x00088020's 7,656 timeouts were not its load loop: they were the anti-piracy check, `if (FUN_00209a8e("D:\\") !=
  0x800) for (;;) FUN_001bb0b0("TBS_STOP_PIRATING");`. A stubbed disc check returns 0x800 almost never, so almost every
  input spun in a loop with no exit. The rule treats a guard in front of a loop nothing leaves as a loop condition and
  sends it to its returning side (0 rounds); inputs that take that path are reported as `stubexit_sealed`.
- A drain loop (`while (registry->Pending())`) gets n continuing results then one that ends it, decided at the
  original's call site and replayed by call index into ours. The old loop repair already ends such loops at their
  first round on small functions, so the rule mostly matters where many inputs time out (0x00088020).
- 0x002731d0 (DriveThread) is not this case: its loop exits on `s->stopped`, which another thread writes. That needs
  a model of the flag's writer (a separate item).

## 2026-11-20 sweep3: settling a record's words from the original's code
- A Track's words: its fight::Param registrations list each member's setter and Param kind. The setter's store
  offset places the word, and the Param kind types it (float, int, vector, Name tUID, script string + length).
  HeliLocomotionTrack's 0xd8 bytes come from 37 setters plus its constructor.
- An object's size: an array stride is evidence too. CLocator's only constructor runs over arrays with a 0x40
  stride, so the record is 0x40 even though nothing touches 0x24..0x3c.
- Pointer or float: look at the instructions. CAvoidBehaviour's "pointer" words at 0x2c/0x30 are loaded with fld.

## 2026-11-20 integ4: allocty lands (typed allocations, regions, region tails)
- 0x0008c470's crash64 was a raw allocation read 4 bytes on i386 and 8 on x86-64 at the same place: a pointer field
  the stubbed initializer would have set. Allocations now take the record the code casts them to. Across 1,388 blocks
  six went from fail to equivalent (a constructor stub run on a member of the fresh object, an int field of element 1,
  0x8c470's slot->drive), and none newly fails.
- The first regress run caught a region bug: past a one-record region (a literal-size request, `count * 100 + 4`)
  offsets were divided by the region size as if the allocation were an array of regions. The raw-tail rule now
  covers offsets as well as bytes.
- Left to triage: 0x0016d860 (layout -> wild64: element 3 in a region's raw tail) and 0x0030f870 (layout -> untyped).

## 2026-11-20 recs1: FEThings views, CEncounterGenerator

- A pad view of a 32-bit object needs its native offset from gen's members, not a native-only formula. The first
  HULK_FE_SPAN doubled the pointer segments on every clang build, which broke the 32-bit clang (Wine) build's views
  (0x000e4a40 wrote FEObject +0x40 at the wrong place under --wine). With the pointer segments scaled by
  sizeof(void*) / 4, the 32-bit clang code is identical and no block needs a re-proof.
- FEThings' remaining views disagree with gen in about 20 places: Target_f42c0 has a pointer at 0x1d98 inside what gen
  calls the name buffers at 0x1c74, and Runner_f5fa0 / X_e65b0 have words where gen has pointers. These are evidence
  that gen's 0x1c74 .. 0x2074 block is not two plain name buffers. They are left as 32-bit pads.
- 0x001fa7d0's x64 `layout` comes from the checker: FUN_001f87e0's stub returns true with an unwritten out-index.
  integ4 is adding a `// post:` contract for it.
## 2026-11-20 data5: the prim buffer's static streams on gen's words; record pointers in the generated headers

- DAT_004d3ed0 (find3's stop 10) is four records.h `PrimBufferStreamStatic` records (gen d3dPrimBufferStream's
  words; clang static_asserts: same offsets on i686-msvc, x86_64, arm64). Landed 9804d55a2.
- data_gen: a config/data-items.json type `struct NAME *` makes the item a pointer to the forward-declared record in
  the generated header (record_ptr_type); DAT_00527c58 is `struct HulkContentRegistry*` (recs1: 0x002407a0's
  x64 `int` class). Opt-in by that spelling only, so source votes (`LoaderRegistry *`) never turn an item into one.

## 2026-11-19 fix126 (D126/D146): four more float blocks; a preloaded virtual slot (include/compat/hulk_vslot.h)

- Float blocks:
  - 0x000ffef0: the length comes from the stored, rounded fbc words. MSVC 7.1 had reused the unrounded x still in
    st; volatile reads stop that.
  - 0x00225300: cur.y goes through its rounded slot.
  - 0x0010a040: the third length, d3, is compared from st.
  - 0x002a5fd0: the inlined Clamp01 takes and returns hulk_freg. v3 is float: the original spills it like v0-v2.
- D146, 0x000bd1b0: the original loads the device's vftable before the viewport's slot 16 (impure in some
  implementations). It then re-reads the device and calls slot 28 of the table it loaded: old table, new object.
  - `hulk_slot<F>(vt, k)` reads slot k as a member-function pointer. Under the MS ABI, a complete single-inheritance
    class's member pointer is one code pointer; a size check guards that.
  - `hulk_vcallN<F>(&objptr, vt, k, args...)` reads the object and the slot only after the arguments are evaluated.
    clang evaluates `(obj->*m)` before its arguments.
  - MSVC 7.1 inlines it to the original's `call [edi+0x70]`.
- 0x00264050 uses the same helper. Its MSVC proof waits for integ3's thiscallpend extension: MSVC pushes Read's
  constant argument after FUN_0026fd50, not before slot 16 as the original does.

## 2026-11-20 integ4: x64bounds, counted pointers and relational contracts
- 0x00327590 (`tex[i * 2] = a` through the stream's texture coordinate pointer) was a false crash64: the harness
  fuzzed both the pointer and the set index, and a 32-bit address that wraps into a mapped page has no 64-bit
  counterpart. gen d3dPrimBufferStream now says what the game guarantees: f_1c (the vertex format's flags & 15) is the
  count of float pairs f_38 points at (`HULK_COUNT_BYTES(f_1c, 8)`), and the block's contract `ge(arg3, 0)
  lt(arg3, this->f_1c)` bounds the index by that field. The x64 run is equivalent at 186 of 200 (14 inputs have
  count 0, so no index is valid).
- Two items on one parameter used to overwrite each other in equiv64 (the last one won). They now intersect.
- Adding `#include "compat/pre.h"` to d3dPrimBufferStream.cpp changed the clang code hash of another block in the TU
  (0x00327860): a header include can move a neighbour's Wine hash, so re-prove the TU's equivalents.
- The checker annotation macros moved from records.h to compat/hulk_annot.h so include/gen can use them.

## 2026-11-20 fix126 (D152): range contracts on 0x0009faa0 / 0x0009fb20, with play3 evidence

- Both functions' exp(-dt/tau) leaves the double range for a negative ratio, where the original's x87 keeps a 15-bit
  exponent. They now carry `ge` contracts: dt and tau >= 0 (HULK_PRE_GE, `// pre: ge(...)`), with every XBE caller
  cited.
- Evidence: a Wine build with HULK_TRACE_FUNCS probes on the three functions, replaying play3 to 60120 (job 100781;
  build/fix126/scripts/argrange.py reads the `fcall` lines).
  - 0x9faa0: a in [0, 0.033333]; b is 2.0, 0.3 or 0.1.
  - 0x9fb20: dt in [0, 0.033333]; tau 0.1 or 1.0.
  - No value was negative or NaN. 0 occurs, so the contracts are `ge`, not `gt`.
- The contract changes the checker view, so the MSVC runs were redone too.
- Including compat/pre.h changed the clang code of 0x000a74c0 (re-proven) in the same TU.
- 0x000a97e0 is not contracted: its decay uses `shake[i].time + dt`, whose member word needs a memory contract (a new
  D152 item, integ3).
- 0x002e11e0 (PrimGroupStreamed, D80: x and y in st, z through a float slot) lands here too; its MSVC proof needed a
  36,000-unit budget.

## 2026-11-20 decl1: start-up declaration stops (find1/find2/find3), census S11, recs1 Q5

- 17 TUs. find1 F8/F10/F12b/F13: the FE things' file name, controllers, sound manager and View are pointers in
  0x000fc060, and its constructors are called by their addresses. 0x000fc1c0 passes the path as a pointer, and the
  call returns the callee's char. 0x000bc3c0 / 0x000f7080 / 0x000f76c0 / 0x000f7790 are free __stdcall functions that
  callers had declared as members (now `static __stdcall`). 0x00294ed0's key is `unsigned short`.
- find2 G4/G6: the inventory slots 3 / 4 take a 64-bit key as two words. Natively their views pass the halves; the
  32-bit side keeps the u64 behind `#if defined(HULK_PTR64)`, so 0x00266220 stays a MATCH.
- find2 G13/G15/G16/G18: the FE callback wrappers take (const char*, void*). 0x000fc1b0 returns the widget as a
  pointer. 0x00088670 calls the free fastcall 0x00086380 through a distinct `FUN_00086380(void*)` declaration: with the
  TU's own definition (`target`) visible, MSVC inlined the call and the equivalence run saw a call missing. The
  CSimControllerManager and CSimController constructors take their pointers.
- find3 (World init): 0x002023e0's definition loses an unused second fastcall parameter. The callers call it as a
  member, so the declarations now agree natively. 0x00200c10 / 0x001cfb20 take the World as `hulk_intptr`. CLocator
  0x001fbf40 is a record with its vftable stored by address, calling pure3d::Entity's constructor 0x0027b070 by its
  address. The caller of 0x001d1900 declares the parameter `hulk_intptr`, as defined.
- census1 S11: CSoundSystem's three C++ spellings of the allocator 0x0008d710 are now the C declaration (the sound heap
  was never created natively). Its 0x340 / 0x20 / 0x28 literal sizes stay: gen's 32-bit sizes for those command
  classes differ from the literals, so they go to the records/allocation lane.
- recs1 Q5: 0x00203e90's callback and the om attribute slots' object words are `hulk_intptr`, on the definitions and
  their callers. MSVC code and checker views are unchanged, so no re-proofs.
- Re-proven at 3,000 compared inputs (MSVC and Wine; hashes recorded by a queue job): 0x000fc060, 0x000c1790,
  0x000c1f70, 0x000c3900, 0x00088670, 0x000f7a80, and 0x001f1270 .. 0x001f16e0 (8 blocks).

## 2026-11-20 integ4: D154, revoking unsound proofs
- The D153 audit re-proved 149 --wine proofs under the fail-closed vsplit guard: 146 still prove, 0x00272df0 and
  0x00296160 take splits only our own code makes, and 0x000b0a50 fails on inputs whose original rewrites its own
  .rdata literals (fix126's EQUIV_SEEDS=1550 repro; an ro_write checker item). Their old ledger lines still proved
  them and the ledger is append-only, so `unproven-accept` refused. `tree_tu.py revoke` now names unsound runs in
  config/proof-revoked.jsonl. A key built from the whole JSON line would break the first time a line is
  re-serialized, so the key is a fixed set of a run's identifying fields, plus the (code, checker) pair: a host
  with lagging tools cannot re-create the unsound proof.

## 2026-11-20 decl1: fight::Context on a record (drive1's 0x0010b2c0 stop); the 0x00203e90 callers; `target` overloads

- **fight::Context's words: include/decls/fight_context.h `HulkFightContext`.** 0x0010b2c0 called the list getter
  0x00232780 as a member (the definition is free) and constructed fight::Context through a local constructor with no
  native definition. 0x00236840 (the constructor) and 0x002368d0 (the destructor) were local polymorphic stand-ins: the
  constructor stored clang's own vftable, and fight's list (0x00232a80) then called through it. The context's object
  at +0x10 was an int, which fight's list reads as its `next` link at native +0x18.
  - The constructor and destructor now use the record and store the game's vftable 0x00427e80 by address. The
    constructor calls pure3d::Entity's constructor 0x0027b070 by its address.
  - The callers allocate `HULK_FIGHT_CONTEXT_SIZE` and construct through 0x00236840's address.
  - The list head 0x00232780 allocates a pointer.
- **0x00203e90's callers declare its definition's flags as `bool`.** 0x00206320's CWorldStreamManager view started
  with `char pad0[4]` for the vftable, so natively every later word sat 4 bytes early. The x64 gate showed it as
  `layout` at the 0x002660a0 call once the declaration changed. The view now opens with `void* vftable`.
- **Four `target` overloads in CTimeManager.cpp (0x00086280, 0x000862d0, 0x00086380, 0x000865d0) had no unique 64-bit
  symbol,** so native_unbound could not bind callers by address (class "definition without a unique 64-bit symbol",
  132 names tree-wide). They are now named by their addresses. This is how the 0x00086380 overload from the
  2026-11-20 batch binds.
- BillboardQuad.cpp gets the G4 key split natively (deferred from batch 4+U while sweep2 held the file).

## 2026-11-20 integ4: D152b, contracts along a call chain
- A D152 contract on a callee broke its caller's proof: fix126's `ge(a, 0)` on 0x0009faa0 changed 0x000a1b30's
  checker view, and the re-proof was unsupported because the original, fed a fuzzed negative frame time, passed it
  straight on. The game never does that (play3 job 100781). The fix belongs in the caller: it states its own domain,
  including the camera time-constant global it passes (D152b). A verify-time probe of every XBE caller then showed
  the same thing one level up, 0x000a1ca0. The chain ends at 0x000a75d0, a virtual, whose callers can't be matched.
- In MSVC mode D152 compared inputs as drawn (the macro is nothing there). An input outside the function's
  contracted domain is no input of the function either way, so range items are now repaired in both modes.
- The harness redraws a global after every call. A contracted global is redrawn inside its range rather than
  pinned: the contract bounds the value, it doesn't claim nothing writes it.

## 2026-11-20 decl1: definitions named by address (no unique 64-bit symbol); the string hashes' caller declarations

- **Overloaded placeholder names.** native_mac binds a caller's `FUN_<addr>` to the definition at that address
  through the definition's 64-bit symbol, found by demangled form or, failing that, by qualified name. A definition
  whose qualified name it shares with others (`target`, `Target`, `Set`, `Fn`, `Go`, `Forward`, `ProcessManager`
  overloads in one namespace or class) has no unique 64-bit symbol, so no caller binds to it (native_unbound class
  "definition without a unique 64-bit symbol": 79 names after 8a8c12c41).
  - build/decl1/scripts/gen_uniq.py renamed the 55 such definitions that have unbound callers, plus their group mates
    (82 definitions in 28 TUs), to `FUN_<addr>`, together with members' declarations in their class bodies. Pins were
    redone with `tree_tu.py pin --records`.
  - Kept: 0x001cc600 stays `target`. 0x001cc620 (equivalent) calls a distinct `FUN_001cc600(char)` declaration, and
    a definition of that name makes the call `FUN_001cc600(0)` ambiguous. Its group mates are renamed, so `target`
    is unique.
  - An `equiv-conv:` line names the function (0x00249630). A rename has to update it, or the checker reports
    `unresolved_convention`.
- **0x002672f0 / 0x002673a0 (string hashes, defined with `const char*`).**
  - build/decl1/scripts/gen_hash.py retyped every caller declaration whose first parameter was a 32-bit integer
    (49 declarations or casts in 21 files, include/game/global.h among them; 23 files with the hand fixes) to the pointer-sized integer of the same
    32-bit type.
  - Three declarations returned `void*` from the int hash, and the records stored it in a pointer field (natively
    8 bytes in a 4-byte slot): CSoundVoiceManager's Entry_1f4420.value, Sequence's Entry_257b30.name and
    ChannelSendVolumes' tag. They are now `unsigned`.
  - Callers whose argument is their own `int` parameter remain for the Q3 pass (unk_0240b0, unk_1f0630, unk_1efb80,
    CSoundCommand_SetLoopPitchEvent, Condition.cpp, Track.cpp).
- 0x00207960 passes its one-byte flag union to 0x00203e90's `bool` natively as `flag.on != 0` (`HULK_PTR64` branch).
  MSVC 7.1 pushes the parameter's whole word, which the 32-bit side keeps.
- 2026-11-20 (decl1) The two no-prelude iso TUs left out of 67f3d89a8 (unk_0240b0.iso_00027630 and iso_00029010) include compat/ptr.h, as the other iso TUs do, and declare 0x002672f0 with hulk_intptr. A TU marked `(tree_prelude.h: not needed)` has no hulk_intptr, so a generator that writes it there makes the TU fail to compile (`tu_failed`) and materialize refuses its equivalent blocks as unproven.

## 2026-11-20 integ4: the frame-time contract chain
- 0x0009faa0's `ge(a, 0) ge(b, 0)` is back (withdrawn in eb4c8feaa). Each caller now states its own domain:
  0x000a1b30, 0x000a1ca0, 0x000a38c0 and 0x000a75d0 (CChaseCamera::vfunc_35) take a frame time >= 0, and the
  camera time-constant globals they pass on (DAT_0049ec8c, ecd8, eccc, ec84, ec88) are >= 0. Each global has a
  single reader and no writer. The chain ends at vfunc_35's vftable slot, which no caller probe can follow.
- The --wine trap check could not see past D152b's outside-domain drop (fixed in D152c). With the fix, every link
  traps on a planted -1.4e-45.

## gfx1: the native graphics backend's ABI cut (2026-11-20)

- The pddi backend natively is cut at the draw sink, not at bgfx's API: draw_sink.h's packets were already plain
  fixed-width structs, so one extern "C" function per DrawSink member (bgfx_bridge.h) lets the MS-ABI front end use the
  Itanium bgfx sink unchanged. Bridge arguments avoid bool / 8 / 16-bit integers: clang's Windows AArch64 lowering does
  not mark them zeroext/signext (only Darwin's does), so an Apple-compiled callee would read garbage upper bits.
- MS ABI never reuses a base's tail padding: a stand-in whose base is {vftable, refcount} puts its first word at +0x10
  natively, where the game's pddiObject has f_08 at +0xc. bgfxObject is packed to 4 natively.
- Several game slots were declared int on one side and float / pointer on the other (prim buffer stream Position,
  EndPrims, the framebuffer-effect settings): on 32-bit both travel on the stack; natively ints, floats and pointers
  travel in different registers or widths. A slot's type must be settled from the original's callee (fld vs mov, ret N)
  and its callers, then made to agree in gen, the tree and the stand-ins.
- With ASLR off (lldb's default) native start-up takes a different path (stops in the front end); debug with
  `settings set target.disable-aslr false`.

## 2026-11-20 integ5: proof-integrity findings (post contracts, D157, equiv speed, sharded proofs)

- Post contracts landed (2d40b0115), then a bug in them (74443f404): equiv64 `_post_proven` compared a block pin's `@v`
  with each ledger line's view, but `@v` is the digest of the msvc and wine views together, so no tree block's post was
  ever used outside `EQ64_OFF=postproof`. It failed closed (false layouts, never a false pass). Lesson: a regress case run
  with a development switch (`postproof`) does not exercise the production path; the forced x64 gate on the real block
  (0x001fa7d0) found it. 0x001fa7d0 left the x64 baseline (944aa58ad).
- D157 (e5a2d3e62): verify reports equivalent blocks whose exact (addr, mode, code) the unproven baseline lists
  (`unproven_baseline_exempt`) instead of failing; HEAD's whole-tree verify failed only on those 148 modes.
- gfx1's gen slot-type change (35ed44382) broke two regress cases' copies of the edited blocks (compile_error); a gen or
  tree signature change needs `grep -l` over tests/equiv/cases for the old symbol.
- equiv.py speed (D155a, f8f67fd1d): a slow proof is ~90% Python hook logic (per instruction and per stubbed call);
  bypassing the unicorn binding's wrappers gives 1.05-1.2x on the same host (mac2: 0x88020 177 -> 149 s). A laptop A/B
  under load showed the opposite (contention): measure speed on one queue host. Bigger gains need the hook logic out of
  Python; sharding (D155c, 8bbae1421) is the wall-clock lever: N jobs on disjoint seed classes, merged with per-field
  default-deny rules, compared inputs counted by distinct keys. An unsharded run compares ~1% of its (seed, overlay,
  patch) triples twice (801 keys for 810 compared): follow-up to count distinct inputs everywhere.

## 2026-11-20 ckpt1: play3's coverage and the first semantic checkpoints against the original (D155, D158)

- **Coverage mode** (`HULK_COVER=<list>`, Wine build; `tools/cover.py`; docs/checkpoints.md "Coverage"): one-shot int3 at
  every listed address, armed before the initializers; the first execution restores the byte and notes the frame. It
  leaves the game unchanged: play3 with 160,640 block leaders armed gates ok against a plain control, and the landing
  pair (control 104695, proof 104986, studio, HEAD aa72b3ad1, `--gfx --replay play3 --frames 60000`, private input
  copies) is GATE ok (only 5880/5910/34260; prng 0 of 2,013 differ).
- **play3 reaches 15,379 of 27,486 functions** (56.0%; 66.9% of the bytes by function, ~58% by basic block): game 59%,
  engine 51%, platform/xbox 20% (its D3D layer is replaced by bgfx under `--gfx`). 12,849 functions are first entered
  before frame 1,000; the later half of play3 adds almost nothing. 2,054 tree functions sit on lld-ICF-folded
  addresses (a hit there cannot say which ran). Unreached: whole TUs worth 209 KB, most of the front end, the memory
  card, movies (recordings run no-fmv), ~40 move families (FireBeam, Surf, BallAndChain, ...).
- **Semantic probe, first results** (not landed yet; ckpt1 phase 3 step 2): per-subsystem tags read in the original
  (hook XBE in xemu) and the Wine build. Two from-boot xemu replays of play3 (studio, mac2) agree on flow, clock,
  Hulk, camera, actors and mission at every frame to 56,594, but **not on the particle RNG after ~12,920** (the
  original itself; matches the recording's prng checkpoints ending at 12,900) nor on the sound code's own generators
  (an observable, not game state). Against that reference the Wine build matches flow, clock and mission everywhere;
  its known transients localise to **camera float drift from frame 5,875** (the 5880/5910 checkpoints) and **Hulk /
  actors float drift from 34,240** (34,260): both "drift" (the quantised hashes agree), so 1-ULP class differences.

## 2026-11-20 ckpt1: the semantic probe against the original (D155, D158; docs/checkpoints.md)

- `src/platform/sdl/ckpt/ckpt_probe.{h,cpp}` (probe v3): per-subsystem hashes (flow, clock, gameplay RNG, Hulk, camera,
  actors, mission; sound and particle generators apart) with exact float bits plus a quantised copy. In the Wine
  build `HULK_CKREF=1` writes `trace.txt.ckref` (`HULK_CKREF_DUMP=<from>-<to>` logs the values); in the hook-only XBE
  the `probe` flag fills a ring `hybrid_test.py replay --ckref OUT [--ckref-dump F]` drains; `tools/ckpt_ref.py` makes
  two-run references (per frame and tag) and checks a run (`--control` for the proof gate, `--cover` for suspects).
  Wine pair (studio, HEAD fb860bfc6, private input copies): control 105130, proof 105140: ckpt_gate GATE ok (only
  5880/5910/34260; prng 0 of 2,016 differ).
- The ckpt_gate transients 5880/5910/34260 are float drift, not logic: against the original's reference the camera
  drifts from frame 5,875 and Hulk and the actors from 34,240, with the quantised hashes equal.
- The original itself is not deterministic in pure3d's particle generators after about frame 12,920 of play3, nor in
  the sound code's own generators: two xemu runs disagree there, so the references drop those tags frame by frame.

## 2026-11-20 integ6: distinct compared inputs (rev5 follow-up), D160

- Repeats: an unsharded run compared about 1% of its inputs twice. The cause is not the bool-fix rerun (`_bf`), which
  returns before anything is counted. Directed phases rebuild an input that was already compared: a post-phase bound
  redrawn to a value drawn before, two tie compares planting one overlay, and patch / obj / small / loop inputs.
  Instrumented runs: build/integ6/dup.
- Since then every run counts distinct compared inputs (`compared_keys` in every report). A repeat is still compared
  in full but counts as `inputs_repeated`.
- The regress invariant (inputs_run == distinct keys) found a second leak: the uncounted Wine trap-check runs of
  `// pre:` contracts left their keys behind. A merged sharded proof would have counted them; the ledger has no
  sharded lines, so nothing was affected.
- Sample of current ledger proofs re-run with the instrumented checker: 2/25 msvc and 3/14 wine lines had repeats
  while counting exactly 3,000, so they are 1-10 short of 3,000 distinct (0x230ec0 10, 0x2fa4e0 6, 0x175360 5,
  0x256150 2; 0x1e5f10 17 repeats but 3,044 distinct).
- D160 (lead, rev5): no revocations. Every counted input was a genuine full comparison and only the counting standard
  got stricter; D154 is for unsound proofs. Re-proofs meet the new count.
- 0x000a97e0 (lead's triage): the regress fixture `0x000a97e0_native_boolafter` fails --wine at 3,000 inputs, and the
  tree block fails the same way at HEAD (job 105470, seed 1950). The cause is a NaN shake offset: ours calls the
  rotation, while the original's x87 `!= 0` test treats NaN as zero. This is the known held item 8 (a memory-field
  contract on shake[i].time, build/fix126/held/a97e0_pre.patch).
  - The block's wine mode is in config/unproven-baseline.json (no proof exists); the msvc proof re-runs equivalent
    under the current checker (105469, 3,032 inputs, 46/46 edges). Nothing to revoke.
  - Regress fixtures stay at their counts: a fixture tests one checker rule (here boolafter: a bool read after a call),
    never the block. A block's own correctness is its ledger proof at 3,000 or its unproven-baseline entry, and a
    held block's known defect belongs to that entry.

## 2026-11-20 ckpt1: the reference gate travels to the hosts; play3's particle frames are the original's (D161)

- `build/ckpt` (the original's reference checkpoints, local derived data) is one of `wine_build_run.INPUT_DIRS`, so it
  goes to the hosts one way with the other inputs; a build job with a replay checks its run against the recording's
  reference (`nb-out/ckref-check.json`, `summary.json` `ckref`). `ckpt_gate`'s GATE line carries the reference gate's
  status (`GATE ok (ref: ok)`) and `--require-ref` fails when it cannot run. Wine pair (studio, HEAD d69586757,
  private input copies): control 105887, proof 106018 (from a private clone of the change, seeded): the same image
  (d9693ed2), GATE ok (ref: ok), also with `--require-ref`; the proof's own check found the reference on the host.
  A first proof (106011) failed on a variable clash in the new job-side check, fixed before landing.
- The 143 play3 frames after 12,923 where the Wine build's particle tag differed from a two-run reference are the
  original's own: a third original run disagrees with the two runs' agreement at 12,923 and 13,542 too (the
  point/plane/sphere and sprite-emitter generators; the first sprite updater's state is equal in all). Two runs can
  agree there by chance, so references are now made from three runs (`ckpt_ref.py make A B C`).
- docs/checkpoints.md has the proposed D155 rule (R1-R5, not implemented; the user decides) and the follow-ups
  (shared records for the probe's pointer chain; the probe calling the game's getters).

## 2026-11-20 integ7: range contracts on object words (held item 8); 0x000a97e0's field items

- `// pre: ge(*this+0xf4.f32, 0)` names a word of the object in ecx (type suffix required); the macro names the field
  (`HULK_PRE_GE(shake[0].time, 0.0f)`) and tools/pre_field.py's i386 probe ties the two. The word is drawn inside its
  range at every memory epoch; its writers are a census (typed stores over the tree, raw stores in the RTTI family's
  methods) cited in the block's `// pre-writers:`. Landed a4b4c3bfc (rev5; regress 727/727).
- 0x000a97e0 (the six camera shakes' elapsed times >= 0; writers 0x000a9390 and the block itself): MSVC and --wine
  equivalent at 3,000 with the field items alone (105757 / 105758; no x87_range input), and 12,000 more --wine inputs
  (105883-105886) found nothing. Still not a proof in --wine: dt is free, and dt = -1000 with time 0 makes clang's
  exp(-t) overflow (0 * inf, a NaN rotation) where the original's x87 stays finite. Random draws miss it; a planted input
  (`EQUIV_ON=plant:...`, regress only) shows it (`0x000a97e0_native_orange_negdt`). Only the MSVC proof is recorded;
  --wine / --x64 wait for a dt contract, whose D152b obligations reach the five derived cameras' vfunc_35 (0x000abb90
  passes a clock callee's result as dt).
- The checker digest now covers tools/pre_field.py (a change there changes level 2's verdicts).

## 2026-11-20 ckpt1: block coverage counted by windows (D162/D163 piece 1, rev5 ADOPT)

- `HULK_COVER_EPOCH=n` (with `HULK_COVER`): every n frames the frame hook re-arms the blocks hit in the window just
  ended, so the coverage file records, per block, the windows it ran in (a 256-window bitmap; `cover.py report
  --frames FROM-TO` counts only windows inside a reference's compared frames). play3 at n=300 (job 106050): of 85,504
  hit blocks, 25.5% ran in a single window (mostly load and init code), 27.6% in at most two, 32.2% in at most five;
  the two historical float-bug functions ran in 7-136 windows per block. D162's minimum is therefore two windows within
  one reference. Wine pair on the default env: control 107197 (gfx2, 65e8e60c1), proof 107231 seeded from it: GATE ok
  (ref: ok), --require-ref.
- The reference manifest (piece 2, 559d63013): `config/ckpt-refs.json`, play3 from three original runs.

## 2026-11-20 nat2 (D131, D133, D134, D135): one name per free, the game's operator new, LoadObject's operator delete

- The game's global `operator new` / `new[]` are 0x0008d690 / 0x0008d6d0 themselves (unk_08ceb0.cpp, `??2` / `??_U`
  blocks); CActorManager.cpp's inline copy is gone. A HULK_PTR64-only `extern "C" FUN_0008d690/FUN_0008d6d0(unsigned)`
  serves the callers that name the allocator by its address (D35); the 32-bit builds bind those names by address.
- content::LoadObject's `operator delete` / `delete[]` are 0x00263f30 / 0x00263f40, static members of gen
  content::LoadObject defined in LoadStream.cpp. 0x00263f40 jumps to the scalar 0x0008d330, not to delete[] (x64t21's
  design table had it wrong). 0x00263f30 needs `__declspec(noinline)`: MSVC 7.1 otherwise inlines it into the same TU's
  0x00264470, whose call then names the global delete. Every gen descendant's compiler-generated `??_G` now calls the
  member (the 7 `.iso_` ScriptReader/TextBible/... blocks needed no edit). tools/wine_link.py's `??_G` synthesis accepts a
  class's static operator delete.
- D134: every free call is spelled by its original target (gen_sites2.py keyed on the XBE call target, plus hand fixes):
  1,925 byte-matched sites left config/free-name-baseline.json (1,927 -> 2: CSoundSystem 0x1f1c80, whose --x64 run
  crashed in equiv64 when this started, and one known). The integer-typed frees got their objects' records
  (TeleportToLocator/DriftToPosition/PropSpawn tracks, six AI conditions, IntArray, Obj_22eda0, LightsChooserCache, the
  writer Object of 0x31a440, CFMVManager); 26 setters that returned the free's eax are bool (`mov al, 1`); six implicit
  LoadObject `??_G` became explicit functions (D114 shape).
- Two equivalents failed at HEAD with the current checker and were fixed on the original's frame: 0x002bf680 keeps the
  loaded image in the frame word the original uses (as B4 did for 0x295620), 0x00201cd0 copies with the inline memcpy
  (rep movsd) instead of a word loop the checker timed out on.
- The checker's call pairing mapped an unaddressed `??_V@YAXPAX@Z` to 0x0008d6d0 in Image32 0x2c00b0: an
  `// equiv-map: ??_V@YAXPAX@Z = 0x0008d340` line fixes the pairing (a hint, not a relaxation).
- D133: the dead free-helper declarations are gone (common.h's SweepTrack_DeleteThis / operator_delete / ai_free /
  ai_delete, the engine/game headers' `thunk` / `opdel` / `Free` / `FUN_0008d3x0` / `thunk_FUN_00267090`, ~360 in TUs).

## 2026-11-21 ckpt2: the `ckpt` ledger kind and the weekly audit (D162/D163 pieces 4 and 5, rev5 ADOPT)

- **The `ckpt` ledger kind (piece 4).** `tools/ckpt_ledger.py record` appends one line per validated block to
  `config/ckpt-ledger.jsonl`. It is a file of its own, so no reader of the proof ledger can count it, and
  `ledger_line_proves` also rejects a `kind: ckpt` line wherever it appears.
  - **What a line covers:** only (addr, wine, wine code hash). It counts in exactly three places: materialize's D126
    gate, verify's `proof: ckpt (wine)` status, and `hash --proven` (the pin follows the code; nothing goes into the
    proof ledger). It never counts for `--from-ledger`, carry, post contracts, the x64 gate or the unproven ratchet.
  - **What a line carries:** the changed blocks' window bitmaps, so R2 is recomputed whenever the line is read.
  - **Read-time checks:** wine mode and the block's current code; the line, its run and its validator not revoked;
    not dated inside a pause; R4 against the current allowlist entry and its tags; R2 within one reference against the
    current manifest.
- **Binding (rev5):** every check refers to one image. The pair is linked without ICF (`summary.json` `link_noicf`),
  and every coverage replay runs the proof job's own image (`ckpt_ledger.py cover` writes the sha1 of the image it
  ran). The hit file is the one the blocks report read, and the proof workspace's sources hash as the job's
  `sources.json.gz`. A proof workspace materializes with `unproven-accept --workspace`:
  - materialize takes those entries only with `HULK_CKPT_WORKSPACE=1`;
  - that variable is recorded in the build's `off`, so such a build is a proof side only, never a control;
  - verify always fails on these entries.
- **Revoking:** `revoke --kind ckpt` revokes one block's ckpt lines; `revoke all --kind ckpt --validator DIGEST`
  revokes every line recorded under that validator and refuses new ones.
- **The weekly audit (piece 5).** `tools/ckpt_audit.py`:
  - **Sample:** 5% per allowlist entry (ceil), seeded by the week id over the lines that count at HEAD and were dated
    before that Monday. A slot whose line stops counting is redrawn from the stored seeded order.
  - **Proofs:** msvc, `--wine` and `--x64` at 3,000 inputs at HEAD.
  - **On a failure in any mode:** the block's ckpt lines are revoked and a pause is opened. An msvc failure is also
    recorded as `equiv_suspect`, a D154 candidate for the lead, never revoked automatically. An x64 failure is recorded
    as `x64_report`.
  - **Lifting a pause:** only the user, with a decision id.
  - **A skipped audit:** `record` refuses while the previous week's audit is not fully judged.
- Tests: tests/test_ckpt_ledger.py (15), tests/test_ckpt_audit.py (7). The mutation runs caught every mutation: 15 of
  15 for piece 4, 15 of 15 for piece 5. regress: REGRESS. Wine pair: PAIR.

## 2026-11-21 ckpt2: play3's 16 particle frames after 14,584 are the original's intra-frame timing, not a divergence

- **The frames.** Against the three-run reference, every Wine build (control 107197 and proof 107231 alike) differs
  in the particle tag at 16 frames between 14,584 and 14,670. These are all of the reference frames kept after
  12,917, the frames where the three original runs agree.
- **The generators.** The tag's moving words are two Marsaglia multiply-with-carry generators, both stepped by
  0x143100 (`z*0x9069`, `w*0x4650`): the plane/sphere generator (0x554bfc) and the sprite emitter (0x554c04).
- **The test.** Field dumps at 14,584 from the Wine build (107694, image 105752) and from a fourth original run in
  xemu (107687), and the number of steps between their states:
  - The original's state lies on the Wine build's sequence, inside its 14,584 -> 14,585 step: 24 of that frame's 73
    plane-generator draws, and 72 of the sprite emitter's 135.
  - Both draw the same numbers. The original is less than one frame's spawns ahead at the probe point (the
    audio-driven event timing after ~12,918).
  - The fourth original run itself differs from the reference at 14,584 and agrees with it at 14,585 and 14,587.
- **Conclusion.** These are coincidences of the originals' intra-frame split, like 12,923 and 13,542 before. Nothing
  in the Wine build needs fixing.
- **Follow-up (probe v4, design to rev5 first).** The exact particle-hash comparison stays as it is. The
  generator-stream position only adds a classification to a frame that already differs ("same stream, original ahead
  by K draws, K under one frame's spawns"). It never turns a difference into a match, and a frame whose streams don't
  align stays a plain failure (tools/ckpt_mwc.py; rev5: on demand, v4 waits until a regression needs it twice).

## 2026-11-21 gfx3: the World's and CGame's pointer words; the native game loop quit through an unbound `return true`

- **Pad views of all-pointer objects.** Every word of the World (32-bit 0x00..0x5c: vftable, 21 managers, f58) and of
  CGame (0x00..0x50) is a pointer. A view's `char pad[N]` in that range is therefore exactly `void* pad[N/4]`: the
  32-bit layout is unchanged, and natively the words land where the records put them. verify found no code, code-hash
  or checker-view change across 131 TUs, so the rewrite needed no re-proofs (C11, 98b351ec3).
- **The 0x00090790 stop.** The stop was not in the measure at all. CGame's frame update 0x00086980 read the stats
  manager at HulkGame+0x48 through 32-bit pads, which natively is +0x24's manager. The stats loop then ran garbage
  Measure entries, which read a null player.
- **A loop that quits on frame 1.** After the platform queue moved to its real word, 0x00087630 asks 0x0008db20
  whether to go on. That function returns 0x0008ed50, a `bool X::f()` member that is ICF'd to `return true`. Its
  callers declared it `int(int)` and `bool member(T*)`, so it bound to nothing natively, the missing stub returned 0,
  the loop set mode 8, and the game shut down cleanly (a free of an unallocated block in teardown then aborts). This
  is an instance of CLAUDE.md's "declare it as defined" rule. Declaring both as defined (C12a) fixes it.
- **CActorManager.** The manager has no vftable and six pointer words (+0x00 world, +0x04 / +0x08 its two
  sub-objects, +0x124 the main actor, +0x344 / +0x348 reference-counted objects). Its ~70 views disagree natively. The
  most serious: 0x000243f0 stores the world pointer as an `int`, so natively every `world->+0x44` read through the
  manager faults on a truncated address (the next stop, 0x00024800 from 0x00086cb0). The full layout is in
  include/decls/actor_manager.h (gfx3's draft, not landed) and in build/gfx3/actor-census.md.

## 2026-11-21 integ8: return postconditions (D165, rev5 ADOPT)
- **`// post: ge(ret, 0)`.** A function may state that every return lies in a range, NaN never. The source returns
  through `HULK_POST_RET_GE(v, c)` on every `return`: a statement expression natively, `(v)` under MSVC 7.1, so a
  matches block keeps its bytes. The block's own runs check the original's return (eax, eax:edx or st0). One outside
  refutes it (`post_refuted`); a proof needs 50 checked returns and 2 distinct values (`post_unverified` otherwise).
- **Matches blocks get a `post` ledger kind.** 0x00085f80 (the clock's elapsed seconds) is byte-matched, so it has no
  equiv proof to carry its post. A run of a matches block that states a return post now gives a `post` line per mode,
  written only by `hash --proven`, revocable with `revoke --kind post`, and proving nothing else.
- **Callers draw the return in range, per mode.** A direct, non-tail call's stub draws the result inside the callee's
  range when the callee's post is proven in the caller's own mode. A msvc line never serves a --wine caller. The
  accepted callees go into the caller's checker view, by the evidence's identity (code, view, post and domain), not by
  the run that proved it. A mutant caller (0x1c04e0 with `step >= 0.0f &&`) is equivalent with the draw and fails
  without it.
- **0x00085f80 needs no domain.** The counter is `unsigned __int64` (MSVC's u64->double: fild of the low 63 bits plus
  2^63), and the scale DAT_003ffaa4 is the `.rdata` constant 1e-6 that no run draws. So the `.i64` object words and the
  `.rdata` global item planned for D165 were dropped (rev5): no block needs them yet.
- **A hole in integ4's out-parameter posts.** Post lines were not in the checker view, so a post added or edited
  after a proof still matched the old code and view, and callers relied on a post no run had checked. Every post line is
  now in the view. 0x001f87e0 was re-proved under its new view, and 0x001fa7d0 (which draws its out-parameter) still
  passes the forced x64 gate: equivalent, and `layout` with the post switched off.
- Re-proved callers whose views now name 0x85f80's post: 0xabb90 0xd05f0 0xec360 0x1bfcc0 0x1c04e0 (msvc and --wine at
  3,000). Regress r2 747/747. tests/test_ret_post.py. The x64 harness does not draw returns yet (fail-closed).

## 2026-11-21 decl1: the callee-declaration rewrites that equivalent blocks held back (batch K)

- gen_decl ran again on a fresh relocation map with equivalent blocks allowed: 55 TUs, 52 equivalent blocks re-proven
  at 3,000 compared inputs, MSVC and --wine.
  - Most of the earlier deferred list (287 sites) had meanwhile landed through other lanes, nat2's new/delete batch
    most of all.
  - 0x001f1c80 (CSoundSystem) calls the free as `operator delete`, so the free-name baseline is down to 1 entry
    (CUnlockablesManager.GS 0x00094fb0, script2's).
- **A binding fix exposes allocation sizes.** Spelling the allocator 0x0008d690 by its own name lets the --x64 harness
  see the allocation, and 29 blocks with 32-bit literal sizes became new `layout` failures. Examples: the caster
  factories' `Alloc(0x20)`, FEThingsBase_3's TextButton (0x15c on 32-bit, 0x168 natively) and CTokenString.
  - Those TUs' allocator declarations are left as they were (exclusions in build/decl1/exclR.txt).
  - The allocation sizes are their own task: a `sizeof(record)` per site, checked against gen's size.
- Left out for other lanes' open batches: unk_0240b0.cpp, CStatsManager.cpp and CTimeManager.cpp (gfx4's C12b), and
  CCharacterTemplateManager.cpp (gfx1's 0x00047890).
- The replay pins stay untouched. The ControllerXBox `GetTime` declaration that 0x00269170 calls is excluded.

## 2026-11-21 integ8: 0x000a97e0's dt chain and guarded shake times landed (D152b, D164 (b))
- **The dt contract.** 0x000a97e0 (CGameCamera::vfunc_35) states `ge(arg2, 0)`. Its six call sites are
  0x000985b0, 0x000a75d0, 0x000a8520, 0x000abb90, 0x000ac420 and 0x000acad0. In play3 to 60,000 (job 100781) all
  55,843 calls pass dt in [0, 0.033333].
- **The callers' own domains (D152b).** Each caller that passes its own dt states it: 0x985b0, 0xa8520 (matches) and
  0xacad0 state `ge(arg2, 0)`. 0xac420 (matches) declares the float as an int, so it states
  `range(arg2, 0, 0x7f800000)`: the bits of +0 to +inf. Their callers are vftable slots only. 0xa75d0 already stated
  it. 0xabb90 passes min(clock, 0.1), which D165's `ge(ret, 0)` on 0x00085f80 now keeps non-negative in its proofs.
- **The guarded shake times** (integ7's items `ge(time) if gt(duration)`, with the constructor census) are in the tree
  block again. The `--wine` proof needs them: with dt alone, input 1950 still failed on a stale negative time.
  0xa97e0 is now proven in both modes and leaves the unproven baseline.
- **0x000a89c0** (CDramaticCamera) had its clang code changed by the pre.h include, and was re-proved in `--wine`.
- Wine pair (studio): control 108981 (45cd75af4), proof 108991, play3 60000: GATE ok (ref: ok). No trap: integ7's frame
  8,730 trap came from unguarded idle shakes, and the guard now covers them.

## 2026-11-21 gfx4: CActorManager's views on its pointer words (C12b)

- **One batch (D172).** The actor manager's six pointer words (+0x00 world, +0x04 / +0x08 the two sub-objects, +0x124
  the main actor, +0x344 / +0x348 the reference-counted objects; include/decls/actor_manager.h) now sit in pointer-sized
  members in every view that reaches them: the ~70 `this` views in unk_0240b0*.cpp and the owners.h stubs (gfx3's
  amfix.py), and 134 external functions in 60 TUs. In each external function the World view's `char` pads in 0x00..0x5c
  became `void*` words and the manager view's pads were split at the six words (build/gfx4/scripts/amloc.py finds both
  views by the block, then wfix.py / amfix.py). Pads split on the 32-bit offsets keep MSVC's code, code hashes and checker
  views: across the whole tree verify found no MSVC code change and no view change except where a type changed.
- **Callee types as defined.** The manager's setters take pointers and a float: 0x00029b50 `(Ref*, Ref*, float)` and
  0x00029bb0 `(void* key, Thing*, float)` still MATCH with those types, 0x00025590 takes its two names as pointers and
  the remaining time as a float, and 0x00025240 takes a float. Their callers passed handles as `int` / `unsigned` and
  the value as an `int` (natively a float travels in another register). Ten equivalent blocks whose view or clang code
  moved were re-proven (msvc and wine at 3,000).
- **0x00024e90** matches again once the provider is held in a local: the inline cast loaded the int handle before the
  header and changed the register allocation. It is a matches block now (it was equivalent).
- **Native.** Start-up no longer faults in 0x00024800 (the world pointer 0x000243f0 stored is whole). It now runs
  through 0x00086cb0 and hangs in the game loop with unbound callees (0x0023f720 / 0x0023f760 / 0x001b93a0 from
  0x00086cb0, and decl1's family). Pointer words the manager receives from other objects are still held as `int` by
  those objects' own views (a fighter's +0x12c, CSPHulkPropInstance's +0xa0 -> +0x10 handle that 0x001d72e0 returns):
  they bind now, but the values stay truncated until those classes get records.

## 2026-11-21 integ9: x64 return-post draws, `rooverlay`, D174 closed

- **x64 callers of a return post (D165 follow-up; rev5 ADOPT).** equiv64 now draws a direct callee's return inside
  its `// post:` range when the post is accepted in both 32-bit modes (msvc and wine lines; the native callee returns
  through HULK_POST_RET_* or traps, so no x64 evidence for the callee is needed). Only after a `call rel32` to the
  stub, never the function under check, never an ambiguous `// sym:`. The AST digest's `calleepost` part holds the
  accepted evidence, and x64_gate reruns the direct callers of a return-post block whose post or proof lines moved.
  The latent equiv64 `post_fill` TypeError on `("ret", cond)` items is fixed. At 3,000 inputs, 0x000abb90 goes from
  `layout` (a read past CHypnoticCamera at +0x4a0 on a negative clock step; the gate's short runs never hit it) to
  equivalent.
- **0x000b0a50 --wine (D154's revocation): root cause.** Seed 1550 points b into .rdata (rdata_ptrs). A directed patch
  steered `walk->count` through b and overwrote the literals "YAxis"/"XAxis" (0x00405f98, 0x00405fa0). The original's
  strcmp read them, but ours reads its own copies, so call #57 differed. New Wine-mode rule `rooverlay` (rowrite's
  input side): directed inputs never patch the original's .rdata, even through a pointer. Those runs are counted
  (`inputs_rooverlay`), and a run they dominate is `rooverlay_dominated`. The re-run at 3,000 no longer differs, but it
  is `split_unpinned` (3 inputs), so the block's wine mode stays unproven until `// vclass:` evidence pins its splits.
- **D174 closed with evidence.** Every tree pre/post item is `.f32`. No block that uses a 64-bit type is unproven or
  revoked, and its x64-baseline entries are layout/ptrtrunc/crash64. equiv.py never draws .rdata (globals_ is
  .data/BINKDATA/DOLBY), and equiv64's HULK_RDATA loads the XBE bytes on both sides. .i64 object words and .rdata
  range items reopen as their own D item when a block's failure is a 64-bit word's domain.

## 2026-11-21 gfx4/gfx5: the frame time as a float (C13)

- 0x00087630 hands CGame's update 0x00086a40 the frame time as a float, and the update passes it on to the controller
  managers (0x000af3c0, 0x000b0080), the message overlay (0x000d6c30) and the sound update (0x001eb2a0, which also
  takes a bool). The sources took it as an int all the way down: identical MSVC code (the value is only moved), but
  natively a float travels in a vector register, and every callee's definition disagreed with its callers' IR
  signature, so none bound. All are typed as defined now; MSVC code unchanged, six equivalent blocks re-proven for
  their checker views. 0x000c5180's third argument (a C30*) waits for Menu_c5180 records.

## 2026-11-21 gfx5: the game loop's frame callees and the debug object (C14)

- **The debug object's switches.** DAT_004dd6e8 is a debug menu whose release build keeps only stubs: 0x0023f760
  returns its third argument (the switch's default) and 0x0023f720 returns false. Their definitions were a free
  `__stdcall` function and a vfunc stand-in with the same bytes, while every caller passes `this`; natively no caller
  bound, and the missing-function stub returned 0, so each switch whose default is on was off: the simulation
  (0x00087630 "Enable simulation"), the frontend and overlays (0x001b93a0), physics (0x001b5da0), lighting
  (0x001c82c0), vsync (0x001b86f0). They are members now, `bool (const char*, int, bool)`.
- **Names without an address bind nothing natively.** native_unbound.plan_link binds only names that carry an XBE
  address (`FUN_<addr>`, the `_<addr>` suffix); the Wine binding map's position bindings of other names (0x00086a40's
  `C10_86a40::F` ...) are not used. 0x00086a40's eight callees carry their addresses now.
- **Old table, new object in 0x001b93a0.** `DAT_0052c2a8->v85(DAT_0052c2a8->v86() == 0)`: the original reads the
  vftable once and the device again after v86; clang read both before. integ9's Wine-mode rooverlay made it visible
  (HEAD's source fails --wine at 3 of 41 inputs); hulk_slot spells the original's order.

## 2026-11-21 gfx6: CPhysicalController typed (C15)

gen CPhysicalController now names the words its constructor 0x000b23c0 writes and 0x000b0a50 fills (name lists,
4-point nodes, axis rows, the device, the callbacks); the 19 functions of CPhysicalController.cpp and unk_0b0440.cpp
that use the controller derive from it. A gen-derived view whose constructor / destructor the original inlines the
vftable stores into is written as an explicit function storing the game's vftables by address (a local polymorphic
view's own vftable is clang's natively), and the `eh vector constructor/destructor iterator` calls pass sizeof(cell).
Also 0x000af170 (CGameController's source) and 0x000d6c30 (COverlayManager's view) on their records. Native start-up
passes the controller set-up and the first frame callees and stops in 0x00207410 (CWorldStreamManager's 32-bit views).

## 2026-11-21 decl2: constructors called by address; allocation sizes from gen (batch C1)

- **The constructors the native run missed (gfx1's `missing-continue` list) were local polymorphic stand-ins.**
  Each declared a base-class constructor that no build defines natively (`Base(const char*, int)` of the script
  bindings, `Branch_23c620(int)`, `Entity_292d70()`, `Obj()`), and each got clang's own vftable natively. They are now
  records that store the game's vftables by address and call the real constructors by their addresses:
  - 0x00106e90 (CPatrolPathManager): the Closure<1> is include/game/script_bind.h's ScriptClosure<ScriptMethod1<...>>
    with the instantiation's Method1 / Closure1 vftables. The manager stores its own vftable by address.
  - 0x0023c620 fight::Bank: fight::Branch's constructor is Branch::Build 0x00232e90, called as declared there
    (`Branch* (unsigned)`), then the Bank vftable 0x004288b4.
  - 0x00292d70 pure3d::Camera: pure3d::Entity's constructor 0x0027b070 by address, the Entity words as
    `void* vftable; int words[3]`, then gen Camera's scalars.
  - 0x001b6990: the object is the zeroed block that 0x001b6850 constructs (ZeroBlock).
- **Allocation sizes (decl1's held-out list).** Naming the allocator FUN_0008d690 lets the x64 gate see 32-bit literal
  sizes, so each site now uses `sizeof` of gen's class and a view of the class's real words:
  - 0x00056b30, 0x0023ce70, 0x0023de30, 0x0023d780: views on fight::Condition's words (vftable, f_04, f_08).
    fight::Condition's constructor 0x00234590 is declared as defined, `void* (void*)`.
  - 0x00139710: the constructor 0x00133c20 is declared returning `void*`.
  - 0x001328a0: gen hulkfight::GameStateCondition had one word too many (`int f_18`: 0x1c, but the factory allocates
    0x18 and writes up to +0x14). The word is gone and the size is recorded.
- Still open: FallAction 0x00138c50 (gen 0x30, allocation 0x38), HitThrowAction 0x001573a0 (gen 0x34, allocation
  0x40), StopTrack 0x0023e9a0 (gen 0x14, allocation 0x18). Each needs the class's words from its constructor first.
  0x001a1090 is a multi-base polymorphic stand-in that returns the object as u32.
- Held out (D181): 0x00094fb0 and 0x001e7470 (CUnlockablesManager / CSPManager closures). 0x00094fb0's --wine run
  hits the stub-snprintf case: SetName's strlen runs past the 0x20-byte buffer the stubbed 0x000964a0 leaves
  unterminated (0x2e vs 0x22). 0x001e7470 has one --wine input with a byte difference (0x40 vs 0x3f) in the object
  passed to a 0x0027b040 call, and in an 8-way split two shards hit nothing but timeouts. Both need integ9's checker
  fixes first. The diffs are in build/decl2 (unlock-94fb0.diff, stream-1e7470.diff).
- Callee declarations from batch K, after C13 / C14: in unk_0240b0 0x000436f0 and 0x00232bb0 are declared as defined.
  In CTimeManager, FUN_0008db80 is `extern "C" unsigned char` everywhere except 0x00086a40's (gfx5's), and the
  allocator is declared as defined. 0x00086790 and 0x00086ad0 are re-proven in both modes. CStatsManager's allocator
  is declared as defined.

## 2026-11-21 integ10: D177 slot pairing, D181 shard merges and the FUN_000964a0 model

- **vsplit/msplit paired the wrong call (rev5's required fix).** A re-run took the split from OUR k-th call, k being the
  original's call index: clang calls strcmp out of line where MSVC inlines it (0x000b0a50), so every later index named
  another call. Calls now pair by slot: the n-th indirect call through the same displacement on each side; no partner, no
  split (`vpair`). clang's -O0 code calls a slot through a register (`mov eax, [ecx+0x3c]; call eax`): the slot is the
  displacement of the load that set it, found going back through the straight-line code; without that the first draft
  took no split at all in --wine mode. `vpair_moved` counts inputs on which the raw index named another call.
- D177 audit (rev5's scope): the 149 --wine proofs of the D153 audit and their MSVC runs plus 0x00264050 at 3,000, and
  a 300-input screen of the other equivalent blocks whose original has an ambiguous slot call (368 blocks, both modes).
  Result: no committed proof rested on a misaligned split. Every MSVC run (150) had the same split either way
  (vpair_moved 0). In --wine, 9 proven blocks met a moved pairing (0x0007ced0 0x000bd1b0 0x000e9370 0x000edb60 0x000ee340
  0x001c1460 0x002f6960 0x002b8090 0x000dd350): all are equivalent at 3,000 under the final checker with no split re-run
  at all (jobs 111136-111144), so nothing is revoked. 0x000dd350's 300/3,000-input failure on a new stubexit input was the
  snprintf fill below, not a split (raw index, model off: fail too, job 110856).
- `// vclass:` (D177) lands with the pairing: 0x000b0a50, 0x00272df0, 0x00296160 proven MSVC and --wine at 3,000
  (jobs 111123-111128) and leave the unproven baseline. Side finding for the lead: 0x000b9bf0, 0x000c9bd0 and
  0x00232870 have --wine proofs from before rooverlay (3d027e12e) and come out `rooverlay_dominated` (unsupported) in 300-input runs.
- **D181 (a)**: `hash --proven` crashed merging shards from before 3d027e12e (no `post` in the report). Shards merge
  only under the checker digest they ran (merge_shards refuses another; the merge applies this checker's verdict rules
  to their counts); a report without `post` states none.
- **D181 (b)**: FUN_000964a0 (`_vsnprintf` plus the game's NUL on -1) is run as MSVC's rules by the stub
  (SNPRINTF_MODELS, keyed by address and the XBE bytes' SHA-1; `modelled_calls`): the random fill had left the name
  buffer of 0x00094fb0 / 0x000dd350 unterminated and strlen read frame neighbours that differ. Not "always terminate":
  len == n leaves no NUL, as MSVC does. The native shim agrees: src/platform/sdl/host/crt_posix.cpp vsnprintf_ms (and
  host_crt_posix.cpp's _snprintf) write n bytes without a NUL and return n when the output is exactly n long, -1 and no
  NUL when longer (the wrapper then terminates at n - 1).

## 2026-11-21 gfx8: C18, the native main loop
- The pure3d context (DAT_0052c2b4, gen owners::X_28f9a0) had ~11 views written as `char pad[8]` / `pad[0xd8]` /
  `pad[0xe4]` before one word: natively each read or wrote the helper (+8) instead of f08 (+0x10), or `a` instead of
  `d`. 0x00294080's `value = 0` cleared the low half of the helper pointer (0x1_xxxxxxxx -> 0x100000000), the next
  0x0028fa40 faulted reading it. A fault address of exactly 0x100000000 is a heap pointer whose low half a 32-bit
  view zeroed.
- 0x001f1270's 20-byte object is CSoundSystem (singleton DAT_004e370c, its script bindings' object): managers.h's
  record is now HulkSoundSystem; the 0x524-byte CSoundResourceManager it allocates is decls/sound_resources.h's.
- After C18 native start-up runs the main loop (Lua GC, controller polls) and presents frames with 0 draws, unpaced.

## 2026-11-21 render1: the native replay harness
- Natively the link's per-caller site hooks were refused whenever another function of the caller's object referenced
  the callee's name. Two of the three refusals were different names for the same address (0x00086630 and 0x00088c30
  each declare their own `FUN_00267f00`), which was enough to fix them. The real overlap (0x00087e30 vs 0x00086000) needed
  relocation surgery: a Mach-O object's relocations name symbols by index, so a new undefined symbol appended at the
  end of the table (the undefined range ends it, so no index moves) lets one function's calls go elsewhere.
- A virtual function's entry hook must also take its vftable slots: the pad poll 0x00269170 had no direct caller
  at all ("no references"), so the hook never ran until rtti.s pointed the slot at it.
- The shared host SDL3 is headless by construction (SDL_VIDEO=OFF), so "real renderer" runs failed at SDL video init
  before reaching bgfx; with video on, bgfx Metal comes up and presents.

## recs2: the scenario manager's hidden pointers and the probe's World crash (2026-11-21)
- gen CScenarioManager's `_pad_04[8]` held two pointers (the World at +4, another at +8). Every native view had been
  4 or 8 bytes short, and 0x001cfb20 truncated the World into an int. Natively, offsets from f_0c on are 32-bit + 0xc.
- 0x00088e40's flag at the World's 32-bit +0x9c is a byte of a manager pointer natively, so the sim's "name set" test
  in 0x00087630 was true every frame.
- A flow-tag record can be solved by brute force: the hash covers four small words (boot step, world, actor
  manager, mission state), so trying ~1,100 candidates per frame recovers the reference's values without an xemu
  dump (build/recs2/scripts/flow_solve.py). For play3 the boot step goes 6 -> 0 at frame 1; mission state is 4 at
  13,200, 5 at 31,200 and 0 at 33,600.

## 2026-11-21 wasm2: the standalone wasm port, its scheduler, setjmp/longjmp and optimised code
- clang devirtualizes a call on a member object whose type it knows (`drive->b.v0()`); cl 7.1 goes through the
  vftable. The callee is then a virtual method no map binds; a probe per method (`p->m(args)`) compiled with the TU
  makes the call virtual again (31 methods in 24 TUs; fusion-frenzy-decomp's wasm port did the same).
- Binaryen's Asyncify can be driven entirely from inside the module: the `asyncify.start_unwind` etc. imports are
  replaced by the pass's own functions, so a C driver loop (on the removelist) switches fibers with no JS. setjmp
  falls out of the same machinery: unwind, keep a copy of the Asyncify data and the stack pointer, rewind; longjmp
  puts the copy back and rewinds into the setjmp. Lua does ~50 setjmps a second of play at ~700 bytes each.
- State hashes catch host bytes on game stacks: a frame-rate report printed on the game's stack changed the state
  hash, and the C library's heap layout (the environment's bytes) puts host pointers into dead stack bytes. Host
  work now runs on its own stack, and the runners pass identical environments.
- The indirect-call dispatcher's binary search over 28,000 entries was 35% of the compiled run; a hash table
  removed it (compiled 2,200 -> 3,500 frames/s after START). Compiling the game's code without -O0's `optnone`
  gave 3,500 -> 6,300 compiled and 1,500 -> 4,900 under node, but the -O1 build's game state differs from -O0's
  from frame 1, through several TUs (LoadStream.cpp first by a prefix search): checkpoints have to decide.

## 2026-11-21 wasm3: play3 on the wasm port

- The wasm port replays play3 against the original's reference checkpoints (tools/native_replay.py, the compiled
  build): all 60,000 frames in 31 s (about 2,000 update frames/s), every gameplay tag equal to frame 445, flow to
  8,586. The replay hooks are native_hooks.h's rows, placed by renaming in tools/wasm_port.py; the probe runs at the
  original's 32-bit offsets.
- What it took, besides the hooks: a void function whose callers read eax. `ParamBranch<T>::vfunc_6` (`fn(p);`, 147
  blocks in 43 fight TUs) passes fn's result through in the original, and 0x235290 parses a nested condition group
  only when it is non-null: with 0 the fight data's stream lost 4 bytes and the reader skipped a ~4 GB "length".
  Natively the same wall waits. Stopgap on wasm: the last call's eax is handed back by void entries (EAX_PASS);
  the fix is the source's (HULK_PORT_ABI, lead D204).
- A dynamic_cast to a stand-in class name (`FrameControllerLoader_297680`) needs the Wine link's descriptor rules
  (wrapper namespace, address suffix, unique leaf name), or the scenegraph loader calls through null.
- BinkOpen must succeed even with no picture: the replay's no-fmv stops the new game's movie on its first render,
  which needs it opened; failing the open, the clock reset one frame early (frame 440).
- DirectSound positions have to advance as the Wine mixer's voices do (800 output frames a DoWork); lockstep I/O
  (the drive thread steps on the main thread's turns) ports as two semaphores in the cooperative scheduler.
- First divergence now: frame 446, the gameplay RNG (6 draws in the reference's frame 445, 4 here): CAmbientsManager's
  spawn search (0x7a420) finds no active cell in the wasm build.

## 2026-11-21 gfx11: native start-up, unbound callees under the first Lua crash
- The native run's `missing-continue` trace lines (HULK_NATIVE_MISSING=continue) are the exact worklist of unbound
  callees reached, in order; tools' plan_link class per name tells why (build/gfx11/scripts/why.py).
- MSVC 7.1 mangles a block-scope function declaration inside a namespace member as global; clang (MS ABI) puts it in
  the enclosing namespace, so `void FUN_x(); FUN_x();` inside fight::... never binds natively.
- A C++-linkage CRT declaration in a namespace (`extern int __cdecl _sprintf(...)`) binds on 32-bit through the map but
  natively stays a stub that returns without writing.
- Local polymorphic script-binding stand-ins crash only when Lua calls them (slot 2 of clang's short vftable): the
  rtti baseline (~600 Function/Method/Closure entries) is the list to convert to include/game/script_bind.h records.

## 2026-11-21 wasm4: the wasm inputs at HEAD, EAX_PASS gone (D205)

- `tools/wasm_inputs.py` builds the wasm port's inputs at one commit as a queue job (materialize, the binding map
  from `wine_link.py --no-inventory --no-link`, the snapshot; written under the job workspace's `wasm-in/`, never
  the host checkout's `build/`): job 111363 at bf539653d, 11 minutes on mac2. The wasm build no longer reads wasm1's
  snapshot of ~7c6f421a7.
- The Wine map names a HULK_PORT_ABI function with the 32-bit void (`X`); the port build defines it with a result.
  `wasm_port.py` binds the definition and callers' declarations by the name with the void spelled `H`/`I`/`PAX`/`_N`/
  `D`/`E` (147 ParamBranch blocks were otherwise left without a definition on the new snapshot).
- EAX_PASS (every void hands back the last packed call's eax) hid five more voids whose callers read eax. Without it
  the first divergence moved from 446 to 439. Bisecting with a debugging build that hands eax back only for the void
  blocks in an address set (61 replays to frame 450) found exactly five: 0x00292a50 pure3d::Camera::vfunc_18
  (slot 16's char), 0x001d6be0 CSPHulkPropInstance::vfunc_15 (int), 0x00048650 CAxisCondition::vfunc_8 (vfunc_9's
  bool; gen's slot 8 is `CControllerCondition_ret8`), 0x00048440 CControllerCondition::vfunc_7 (a `jmp [eax+0x20]`
  that hands slot 8 its caller's argument and returns its bool: the tree's view passed no argument) and 0x00023e60
  (0x00088fb0's unsigned). They return it under HULK_PORT_ABI; 32-bit code unchanged (all MATCH). The 64-bit build
  has the same bugs.
- play3 on wasm (-O0, compiled): all 60,000 frames in 31 to 38 s, every gameplay tag equal to the reference through frame
  445 (rng first differs at 446), particle now to 651 (was 565).
- The frame-446 rng divergence is not "no active ambient cell": the cells 0x0007bbd0 builds come from the tile table
  (CAmbientsManager::vfunc_1, "BitDef"), and the tiles around the hulk's tile 229 have no road bits in either of the
  two tables loaded at frame 439, so 0x0007a420 finds no cell from the data. Frame 445 draws 4 here (0x0007a420 1,
  0x0007a8f0 2: the one path is 270+ units away, one more after them); the reference draws 6.

## 2026-11-21 wasm5: the region game data parses on wasm (MyBufferStream::vfunc_3's eax)

- Oracle: a Wine build replaying play3 matches the reference at every probed frame, so its HULK_TRACE_FUNCS /
  HULK_TRACE_SPAN probes (studio, a private `git archive HEAD` workspace) say what the reference does where the wasm run
  differs. The default workspace ships the checkout's dirty TUs and materialize then refuses their unproven blocks.
- Frame 445's two extra draws in the reference are CSPHulkPropInstance's per-frame update (0x001d8fc0:
  `rng->FUN_00078780() < 0.005f` for a prop whose physics object is awake): two props woken at 445 by
  AICollisionSolverAgent's contact callback (0x001b2560 -> UnitUpdate 0x001b0090 -> 0x001d7510).
- The wasm run had 24 props in the world where the Wine build has 45, from 98 CSPManager records instead of 220:
  every region's game data buffer (0x001fab00 -> 0x00337c20) failed to parse. 0x00337c20 reads the stream's slot 3
  as the bytes read (`read(&size, 4) < 4`); 0x001fa9e0 is a void in the source that leaves the clamped count in eax.
  It returns the count under HULK_PORT_ABI now (the 32-bit code is unchanged). Records, entries and world objects
  then match the Wine build (220 / 215 / 45). The first divergence stays rng 446: in the reference the props collide
  from frame 442 (0x001b2560 called 5, 5, 20, 21 times in 442..445); on wasm it runs only twice, at 441.

## 2026-11-21 wasm6: the narrowphase overlap test returns its bool on the port builds (rng 446 -> camera 541)

- Wine-build probes (jobs 111395/111396) and wasm entry hooks: SweepAndPrune (0x002ed3d0) hands 0x00302ed0 the same
  pairs on both (157, 451, 311, 310, 309 in frames 441..445), but on wasm almost no pair reached the contact list.
- 0x00302b70 tests `a->Check(b, field)` (slot 12) in al; every volume's slot 12 is 0x003068a0
  (physics::CollisionVolume::vfunc_12), a void in the source that tail-calls the box test 0x00306790 and leaves its
  bool in eax. On wasm the caller read a stale result word. It returns the bool under HULK_PORT_ABI now (Ret_3068a0;
  the 32-bit code is unchanged, code ok/ok view ok).
- wasm play3: the props collide and wake as in the reference; the first divergence moves from rng 446 to camera 541
  (float drift; rng 542). All 60,000 frames in 37.9 s.
- Native note: 0x003068a0 passes its third argument (the caller's int `field`) as `void*` to 0x00306790, which reads
  it as a float: fine on x86 and wasm stack slots, a register-class mismatch on arm64 / x86-64.

## 2026-11-21 wasm6: member-function-pointer forwarders keep their argument on wasm (camera 541 -> rng 542)

- play3's camera diverged at 541 (pitch): CChaseCamera's input (0x000a2100) negated the stick's y because
  DAT_004dd83b (camera invert y) was 1 on wasm and 0 in the Wine build. The front end's camera-invert selectors
  (0x000b5ad0 -> TextSelector slot 25 -> 0x000f8b90 Set(1) -> CallbackHolderInt::vfunc_0 0x000be220) reached the
  option callbacks 0x000bbd80 / 0x000bbda0 with 0 instead of 1.
- 0x000be1c0 / 0x000be1f0 / 0x000be220 (CallbackHolder, ...Float, ...Int <CFrontEndCallback>::vfunc_0) are one 8-byte
  forwarder, `mov eax, ecx; mov ecx, [eax+4]; jmp [eax+8]`: the caller's stack argument goes on to (object->*fn)
  untouched. The tree's source is one no-argument stand-in for the three (`(mObject->*fn)()`), so the int and
  float holders drop their argument on every port. tools/wasm_port.py now writes the entries of blocks with those
  bytes from the XBE (forwarders(): `this` becomes [this+4], dispatch to [this+8] with the caller's arguments).
  The 64-bit builds have the same bug (the source passes nothing); they need their own fix.
- Also tried, no effect at 541/542: the 64-bit float passes (castfix / fpcvt / x87ext with softx87 math) on the wasm
  IR. Not landed (25% slower); parked in build/wasm6/parked.
- wasm play3: first divergence 541 camera -> 542 rng (hulk x/z, camera x/z also at 542).

### wasm7: fight actions' still-running byte (542 -> 751)
- 542: Wine-build probes (111409-111412) vs wasm entry hooks: at 542 wasm started a new fight move (6 CAction::vfunc_3
  starts, one a CHeadTrackerAction drawing the extra rng step); Wine started none. One frame earlier the node list
  runner 0x00231f20 calls slot 5 of each child action and tests al; fight::ExecuteAction::vfunc_5 (0x002396f0) and
  fight::QueuedNodeAction::vfunc_5 (0x0023a210) are void in the source but end in 0x00231ee0 (`unsigned char`) and
  leave its still-running byte in al (Wine 0x...01, wasm 0): the runner saw the child finished and moved on.
- Fix: both return 0x00231ee0's byte under HULK_PORT_ABI (32-bit code unchanged); same batch: CButtonCondition slot 8
  (0x000484c0) returns slot 9's bool (0x00048440, wasm4, passes it on).
- Tool: wasm_port.py HULK_WASM_DEBUG_VOIDRET=1 (debugging packer): an indirect call with an integer result that reaches
  a block leaving the result word untouched calls the host's ff_dbg_voidret(target, caller TU). On play3 (60,000
  frames) 37 (target, TU) pairs, mostly pddi/d3d and frontend; game logic: CButtonCondition::vfunc_8,
  fight::ExecuteAction/QueuedNodeAction::vfunc_5, CAlertStatusCondition::vfunc_8 (0x0004a4e0, from 812: returns
  0x00059a30's pointer, tested in al: open), FUN_001cbd10 (CEventManager). tools/eaxscan.py + eaxcand.py: the static scan.
- Note: wasm_port.py compiles the snapshot's sources (HULK_WASM_SNAP/src), not the checkout: a source fix is tested by
  patching a private snapshot copy (build/wasm7/snap) or with fresh wasm_inputs.
- wasm play3: first divergence 542 rng -> 751 rng (hulk/camera to 941).

### wasm7: the HULK_WASM_DEBUG_VOIDRET batch (sound 2 -> 779)
- One play3 run of the voidret build listed the reached void-read sites; this batch fixes the game-logic ones whose eax
  is a real result: 0x002469f0 (stream read callback tail-returns 0x002647e0's bool), 0x002a3740
  (ParticleSystem::vfunc_7 returns 0 or 0x002a4150's char), 0x001d36e0 (ScriptHandler::FUN_001d36e0: sh_ProcessFile's
  status from 0x001d3600; gen/global.h declares it int under HULK_PORT_ABI). wasm play3: sound tag 2 -> 779; rng
  still 751.
- Left (eax incidental or not decidable statically): the d3dContext/pddiBaseContext render-state slots, frontend
  FEContainer slots, boot-time drive/allocator slots, the free callback 0x001e8830, CAlertStatusCondition::vfunc_8
  (0x0004a4e0: al of a heap pointer, address-dependent), and the audio sequencer family: SeqAction*::vfunc_2 (14
  blocks) leave the caller's eax (0x0025dc20's queue pointer, their first argument) and 0x0025dc20 tail-returns it
  to the SeqCommand vfunc_0s (likely the sound divergence at 779).

### wasm7: the native float passes on wasm (751 -> 779)
- 751: props draw the rng when their PhysicsObject is awake (bit 1 of +0x1f4, 0x002f55d0). A prop went to sleep at
  750 on both builds, but the Wine build woke it with an impulse (0x002f5db0 -> vfunc_13) and wasm did not. The
  impulse sequences (probe 0x002f5db0, HULK_TRACE_SPAN of the impulse and state words, Wine 111420 vs wasm hooks)
  agree in count from 449 to 739; the first value difference is frame 450, impulse 10: linear z and angular x/y one
  ULP apart with identical positions and velocities: a float result rounding difference.
- wasm_port.py now applies tools/native_float.py's passes to every TU (fpfix: castfix, fpcvt, x87ext with softx87
  math in src/platform/wasm/host/x87.cpp, wasm6's parked set) plus retfix64: a `float` call of a `hulk_freg`
  definition reads the double, as the Wine build's retfix does. The parked set alone left 751; retfix64 moved it.
  HULK_WASM_FPFIX=0 turns them off.
- wasm play3: first divergence 751 rng -> 779 rng (sound also 779, actors 780); 60,000 frames in 72 s (54-61 s
  before on the same busy laptop: the passes cost ~20%).

### wasm8: slot-8 condition entities under HULK_PORT_ABI (779 -> 870)
- 779: a fight ExecuteAction (0x002394c0) in the Wine build evaluated a condition list that wasm skipped. The fresh
  HULK_WASM_DEBUG_VOIDRET run on the fpfix build listed CAlertStatusCondition::vfunc_8 (0x0004a4e0) from frame 741
  (7,752 reads): it is `return obj->FUN_000592a0()->FUN_00059a30()` in the original (0x00059a30 returns its word
  +0x10, the fighter's entity), and its caller vfunc_7 (0x0004a500) tests that entity, so on wasm the condition was
  always false. Same shape in CMotionStateCondition::vfunc_8 (0x0004a260, read by 0x0004a280 from frame 2677).
- Both return the entity under HULK_PORT_ABI (gen/global.h: CAlertStatusCondition / CGrappleAlertStatusCondition
  vfunc_8 `void*` under HULK_PORT_ABI only); the 32-bit code is unchanged (MATCH, relocs ok). The 64-bit builds
  read the same garbage today: the fix serves them too.
- wasm play3: first divergence 779 rng -> 870 actors (float drift, window 840..870); rng now first differs at 2711.
- 870 (actors, a soldier spawned at 857): its name carried the encounter map's count (`...+a-as+100.0` in Wine,
  `...+0` on wasm) because the encounter map (0x001f9530 inserts, 0x001f9630 finds) stayed empty: the node pool's
  slot 3, core::MemoryPool::vfunc_3 (0x0026fe00), tail-returns slot 13's block and the void block returned none, so
  every insert got a null node. MemoryPool::vfunc_3 and MemoryTwoWayAllocator::vfunc_3 (0x0026d410, same shape)
  return the block under HULK_PORT_ABI, and gen/core.h's IMemoryAllocator slot 3 family is `void*` there. The name
  now matches; 870 does not move: the spawned soldier is updated (turns and steps) in its spawn frame 858 on wasm
  and only from 859 in Wine (actor words at the first 0x00059c10 call of 858/859, Wine 111430/111433 vs a wasm hook).
- wasm9 (D212), 870 (actors): the soldier spawned at 857 moves in its spawn frame on wasm because its
  CPathGraphAgent (constructor 0x00105f50) leaves +0x5d (path ready), +0x8c, +0x9c, +0xb4, +0xc0, +0xd0
  uninitialized and 0x00104d00 tests +0x5d (and +0xb4) before the queued path request is served. Wine (and the Xbox)
  hand back a fresh zero block (span at 0x00104d00, job 111439: +0x5c word 0 at 858, 0x101 at 859); the wasm heap
  hands back a recycled one (+0x5d = 0x94), so 0x00104d00 steered toward the waypoint (+0x2064 dir, +0x2070 = 1.0)
  one frame early. Actor +0x640 (contact list Ent28[128] at +0x638, FUN_00038e80) is written in 858 on both builds:
  not a cause. The port builds zero those words under HULK_PORT_ABI. wasm play3: 870 -> 2010 (actors), 60,000
  frames in 98 s. The wasm and Wine heaps lay out the same spawn differently (agent - actor 0x27f0 vs 0x3f80):
  further uninitialized reads can surface the same way.
- (wasm10, 11-22) **wasm play3 2010 actors: a leaked CPathAgent's CMoveAgent, not an uninitialised word.** The
  soldier spawned in 2005 moves in 2006 on the reference and in Wine because its CPathGraphAgent (0x00105f50) gets back
  the very 0xf4 block of the soldier killed in 1997, whose stale +0x5d (path ready = 1) and waypoint the constructor
  leaves in place (Wine 111442, span of the constructor's block). On wasm the game heap (heap 0xc) differed from frame
  513: a CPathAgent's `??_G` 0x00105e30 was still the pre-D114 `CPathAgent::~CPathAgent() {}` (iso TU), and the port
  builds bound its destructor call to that empty definition instead of the body 0x00105060, so the agent never released
  its CMoveAgent (+0x60), which kept the CCharacterGolem (refcount 1 of 9): both leaked (Wine 111444/111446/111448:
  heap sequences, golem and move agent AddRef/Release). Fix: the explicit `??_G` (D114 form); wasm9's zeroing of the
  constructor's words under HULK_PORT_ABI (edaa58140) is reverted: it masked this leak at 858 and is wrong at 2005.
  wasm play3: first divergence 2010 actors -> 2313 particle (actors ok to 3780; camera 5875, rng 8195), then an unbound
  0x0035618d trap at 8640. Fifteen more `??_G` blocks are still in the empty `X::~X() {}` form while the original
  calls a body by address (same leak class on the port builds; listed in build/wasm10/RESUME.md). On the Xbox the
  pddi d3d objects and texture staging buffers came from the game heap too (operator new 0x0008d690 in XBE code,
  e.g. 0x00326900 +0xcc); only XDK resource memory did not, and the wasm shim already takes that from the host.
- (wasm10, 11-22) **The rest of the empty `X::~X() {}` `??_G` stand-ins (18 blocks in 18 TUs: 0x0005b770, 0x0007af60,
  0x000d83f0, 0x0023b4f0, 0x0027e900, 0x00286500, 0x0028e040/60/80, 0x00295600, 0x002a5040, 0x002a7580, 0x002aaef0,
  0x002ac550, 0x002c3a80, 0x002d66e0, 0x003250f0; 0x00105e30 above) are D114's explicit functions**: each original
  `??_G` calls its destructor's body by address, which the port builds skipped. All MATCH with relocs ok and /GX-; the
  18 TUs dropped `// cl-flags: /GX` (14 left: docs/tech-debt.md). wasm play3: first divergence 2313 particle -> 3810
  actors (camera 5875 is the Wine build's known 5880 transient window); the run still stops at 8640 on an unbound
  0x0035618d (XCreateSaveGame: the wasm host has no row for it). A wasm snapshot built before a `??_G` rename needs
  its report.json symbol for the address updated, or the vftable keeps clang's own `??_G`.
- (wasm12, 11-22) **wasm play3's stop at ~8690 was the save dialog's OK button: ten `void` getters that return a
  dynamic_cast in eax.** FEContainer's slots 38..46 (0x000e47b0, 0x000e47e0, 0x000e4810, 0x000e4840, 0x000e4870,
  0x000e48a0, 0x000e48d0, 0x000e4900, 0x000e4930) end `call __RTDynamicCast; add esp, 0x14; ret 4`, and fight's
  0x00232f00 `ret`: the cast is their return value, but the blocks were `void`, which MSVC 7.1 compiles to the same
  bytes and the port builds to a function that returns nothing. The layout parser 0x000f4e90 stores the dialog's
  buttons (+0x998/0x99c/0x9a0) from slot 42 (0x000e4840 -> slot 39 -> slot 37), so on wasm the FEGenericDialog built
  at frame 439 kept three null buttons, and the "game saved" dialog (0x000d9080 -> 0x000be230 -> 0x000e5f00, mode 2)
  called slot 8 of a null button. All ten now return the cast (`void*`, new `??` symbols pinned; MATCH, relocs ok).
  wasm play3 now runs to 60000 (80 s); first divergence still 3810 actors. wasm11's init-time stack at the "miss" was
  the first ff_dispatch_miss hit, which is a legitimate kernel-slot call (0xe0000123, RtlInitializeCriticalSection
  during the static initializers): kernel and host-method calls all go through ff_dispatch_miss, so a breakpoint
  there stops at init; break on ff_fatal instead. Scan used: every discarded `__RTDynamicCast` / `FUN_00344e74`
  statement in src/ against the original's next instructions (the other eight sites really discard it).

- **wasm13 (2026-11-22): the wasm play3 actors divergence at 3810 is the CRT qsort's order of equal elements.**
  The first field difference (f=3786, an NPC's x step) traces back through the LocomotionSteerDriver accumulator
  (0x00228da0), the steer angle (LocomotionSteerAction 0x0015e7d0), the agent's desired direction (+0x2064, written
  by CAvoidBehaviour::vfunc_4 0x00109c00 = normalize(w + 0.9 d + 0.1 c)) to d = RoutAction+0x1c (RoutAction::vfunc_5
  0x00122520), which RoutAction's constructor 0x0011fef0 never writes: the original reads the heap block's stale bytes
  (0xd, 0, -1.0), wasm read zeros because the block was another one. Heap 0xd's live sets (whole-run 0x266e00/0x267090
  trace, Wine vs wasm) first differ at f=2733: the scenario event queue ItemQueue::FUN_001cbfe0 qsorts its items with
  comparator 0x001cb3a0, which never returns 0 (`prio[a] > prio[b] ? -1 : 1`), so the order of equal-priority items
  is whatever the CRT's qsort makes of it; the wasm host's qsort (wasi-libc) visits two type-0x1b items in the
  reverse order of the Xbox's (Wine's msvcrt agrees with the Xbox), and the CScenarioParams / LuaAction blocks are
  created and freed in another order from there. The native builds have the same difference (docs/native-mac.md
  "Known differences left: qsort"). A fix needs a qsort with the Xbox CRT's order of equal elements (a clean-room
  question for the lead). Aid landed: HULK_WATCH silences the wasm host's per-call lines (1b50f0dca).
- (wasm14, 11-22) **Most of the wasm -O1 vs -O0 game-hash difference was stack garbage.** Game code copies uninitialised
  locals into heap records (4,096 0x40-byte records at frame 1). At -O0 the garbage comes from the shadow stack and
  shifts with frame sizes: making only 0x265210 -O1 (16 bytes less frame) shifted it by 16 bytes. The wasm front end
  now zero-initialises locals (-ftrivial-auto-var-init=zero; play3 on -O0 keeps every tag's first divergence). The
  rest was a source bug: the sprite constructor 0x2be440 passed 0x2bdaf0 a five-word rect, and 0x2bdaf0 reads six
  (RectInts.i14, the original's spill of the column width at [esp+0x24]), so some sprite u values were 2.0 or 8.0.
  With six words, -O0 and -O1 give the same game hash at frame 1 (D187 unproven-accept). Every build that compiles
  0x2be440 read past the rect, the native builds included. On play3, -O1 still diverges at frame 672 (rng).

## 2026-11-22 wasm15: the wasm build runs without a replay

- A free run (no recording) stopped after frame ~100-150 (and once past it, after ~4,100): the main thread spun
  without ever yielding or presenting. First stall: a sound bank load (0x001e9bf0, inside 0x001eab10) polls the drive
  pump 0x00272df0 until the drive thread finishes the request, but the threads are cooperative and nothing in that
  loop waits or sleeps, so the drive thread never ran (a replay's lockstep I/O steps it at the pump). Second: the
  front end's movies spin on BinkWait, which keeps time on the virtual clock, and in a free run that clock moves only
  1 us per QueryPerformanceCounter read: ~30,000 game updates without a Swap per movie frame (the CKPT probe counted
  640k updates for 4,000 frames). Fixes, both only without a replay: the pump is a time slice (ff_poll), and a
  BinkWait whose frame isn't due moves the clock to it. play3's records stay byte-identical (60,039 frames vs the HEAD
  build).
- Now: no input -> GS_FRONTEND forever (30,000 frames in 3.5 s, ~10,000 frames/s). With START then A presses
  (HULK_INPUT gained an analog-button mask, `/1` = A): GS_PREGAME, GS_PRESSSTART, GS_GAME from frame 644-1,604, and
  60,000 frames in 82 s (~900-1,000 frames/s in the game). HULK_GS=1 logs the GS_ state's changes.
- Seen on the way: the 04:04 build of wasm14 (before its last commits) and HEAD's build differ on play3 from frame
  11,483 (sound first, 11,481); HEAD against HEAD + these fixes is identical.

## 2026-11-22 wasmq: the port builds' qsort orders equal elements as the Xbox CRT does (actors 3810 -> camera 10196)

- Cause (wasm13): ItemQueue::FUN_001cbfe0 sorts its events with 0x001cb3a0, which never returns 0. The wasm host's
  wasi-libc qsort put two equal-priority type-0x1b events at frame 2733 in the opposite order to the original. Heap
  0xd's blocks were then reused in another order, an uninitialised RoutAction word read zeros, and actors diverged
  at 3810.
- Clean-room (user D217 (a)): the XBE's qsort ran as a black box under Unicorn (the comparator is a hooked `ret`),
  recording the output permutation and the comparator's call pairs; no instruction of it was read.
  - Equal arrays up to 8 elements give n(n-1)/2 calls (1,0),(2,1),...: a repeated scan for the greatest element.
  - From 9 elements on: a median of three at (0, n/2, n-1), scans toward the middle element that follow it through
    swaps, and the smaller part first.
  - A model written from that matched 4,500 random cases on its first try (widths 1..0x101, lengths up to 3000,
    three-way, never-zero and random comparators).
- src/platform/sdl/crt/hulk_qsort.h (header only) serves the wasm host (crt.c) and the native glue (`hulk_ncrt_qsort`,
  now a glue row of native_crt_table.h). The Wine image is unchanged: msvcrt's qsort, and crt_posix.cpp is `!_WIN32`.
  tests/test_qsort_xbe.py is the differential test (it generates the expected behaviour at run time; nothing derived
  from the XBE is stored). Method: docs/qsort.md.
- play3 on wasm to 60,000 frames (41 s): actors now match to 10,380. Camera 5875-5925 is the known transient window;
  the first lasting divergence is camera 10196 / rng 10198.

## 2026-11-22 wapp1: the wasm2c app renders (D190, milestone 1)

- The pddi front end (src/platform/sdl/pddi) runs inside the wasm module, compiled through wasm_port's i686 -> wasm32
  path; the draw sink crosses the module boundary as `hulk` gfx_* imports implemented by the runner with the bgfx sink
  (Metal). Front-end units must be llvm-linked into one module before bind_tu: a vftable emitted in one unit names
  methods another unit defines, and bind_tu gives only a TU's own functions synthetic dispatch addresses (otherwise
  the slot holds a wasm table index: "indirect call to 0x000003ab").
- play3 to 60,000: records are byte-identical between the headless build, the app with the game's d3d layer on the
  null device, and the app with the pddi front end on bgfx noop: the graphics path changes nothing the game reads.
- Comparing i686 COFF objects for D194: clang writes a time stamp at header offset 4 (zero it before comparing).

## 2026-11-22 wapp1: input, audio, pacing and the bundle of the wasm2c app (D190, milestones 2-4)

- DirectSoundDoWork runs about three times a game frame, so the wasm host's null DirectSound (800 frames of 48 kHz a
  DoWork) moves voices about 1.5x faster than real time in free play: fine for replays (the Wine build's frame clock),
  wrong for heard audio, whose streams the game refills from the positions it reads. The app's free play reads
  positions from the real-time mixer instead (as the Wine build's device clock).
- With the pddi front end the game's own SwapBuffers (and its vblank wait) never runs: a present is one d3d_null Swap
  (one 60 Hz field of virtual clock). Free play adds the second field when 0x005554a0 is clear (gameplay), so game time
  matches the 30 fps pacing.
- play3 records stay byte-identical with Metal drawing: the graphics path changes nothing the game reads.

## 2026-11-22 wasm15: softx87's divisions by long division in 32-bit digits (same quotients, faster)

- softx87's `fdiv` (128-bit mantissa quotient, truncated) did a bit-at-a-time restoring division (128 steps); it now
  divides in 32-bit digits (Knuth's algorithm D: the divisor's top bit is already set, so no normalising shift). The
  quotient is floor(A * 2^128 / B) either way, so every result is the same: 30M random operand pairs gave identical
  results against the old code. `fdivu` (division by a small integer in the series) takes 32-bit digits instead of
  16-bit ones (2 divisions per word instead of 4).
- The Wine image carries softx87 (fyl2x's log10 and the 64-bit builds' x87ext): pair 111481 (control, HEAD
  a34b4362c) / 111483 (proof) on studio, play3 to 60,000, ckpt_gate GATE ok (ref: ok), the image differing only in
  hulk-strict.exe. (The first control, 111480, never started: pinned to the laptop with needs `wine`, which the
  laptop doesn't offer; it has only `wine-gfx`.)
- wasm (compiled, wasm2c): play3's records byte-identical through 12,000 frames; first 12,000 frames on studio 21.1 ->
  18.1 s. A wasm2c microbenchmark of softx87 (emcc -O1, clang -O2): sin 0.60 -> 0.42 us, acos 2.0 -> 0.63 us, atan2
  1.1 -> 0.47 us, fsqrt 1.2 -> 0.24 us.

## 2026-11-22 wapp2: the wasm2c app's "Invalid call_indirect" trap was the window's resize handler

- The app trapped within a second (`hulk-aot: trap: Invalid call_indirect`, frame 16-32, no input needed). lldb with
  `b wasm_rt_trap`: func_types_eq_slowpath <- hulk_platform_pump (src/platform/wasm/gfx/gfx.c) <- the front end's
  platformAfterFrame. The front end registers its resize handler (sdl_platform.cpp onResize) with
  `hulk_platform_set_resize_handler`; compiled through the i686 path, that function as a value is its synthetic
  dispatch address, and gfx.c called it through a C function pointer, i.e. a wasm call_indirect with an index that is
  no table entry of that type. It only runs when the window resizes, and macOS resizes it on its own here (640x480 ->
  1056x1025 on this display) shortly after it opens; wapp1's runs never saw a resize. Not stale objects and not the
  gamepad. gfx.c now keeps the address and calls it through ff_call (ff_dispatch), as the vblank callback is.
- The lead's build recipe (cp of build/wasm's objects, then a `--only` compile of the two hooked TUs) linked tree
  objects of whatever inputs build/wasm last had. wasm_app.py now records the inputs a build directory's objects come
  from (app-inputs.json: snapshot digest, binding map, wasm_port.py / wasm_ir.py, build knobs) and compiles every TU
  when they differ or are unknown; from the IR cache a full compile is ~7 minutes on 2 jobs (from nothing, inputs at
  HEAD: 7.5 minutes for the whole app build). `wasm_port.py link` printed "link rc 1" and exited 0, so `aot` could
  build an app from an older hulk.wasm: it now exits nonzero and removes hulk.wasm. aot --app's object cache key now
  covers src/platform/sdl/input/ (run/app/input.cpp includes hulk_input.cpp).
- With a gamepad connected the SDL layer stops reading the keyboard (kb_active); the app merges the keyboard into
  pad 0 instead (buttons OR, triggers max, a stick the keyboard pushes overrides). Window title without "(native)"
  (the runner names the window; no pddi-layer edit).
- play3 to 60,000 at a34b4362c (inputs a34b4362c988): the headless build's records are a prefix of the app's with
  `HULK_GFX_RENDERER=null` (as wapp1 checked). Keyboard-scripted free run: gameplay at ~frame 1,000, 30 fps, no trap.

## 2026-11-22 wasm15: the wasm arena's first fit starts at a bound per exact size

- A counting build of arena.c showed the first-fit walk visiting ~100M blocks over play3's first 12,000 frames
  (about 250k allocations, nearly all freed again: d3d_null's 48-byte surface headers from GetSurfaceLevel and
  similar churn). The per-class bounds (wasm14) start a 48-byte search at the first free block of 32..63 bytes, which
  may be too small, and the walk then crosses every used block up to the next hole that fits.
- `arena_lbn[k]` (appended to the sim block) bounds sizes 16k bytes for k = 1..64 exactly: no free block of 16k bytes
  or more lies below it. An allocation of 16k bytes starts there and moves the bounds of k and above to the block it
  takes; a free lowers the bounds its merged block can serve; a merge moves bounds off a vanished block start. Still
  first fit in address order, so every address is the same: play3's records byte-identical through 60,000 frames
  (with the next change too). First 12,000 frames on studio 17.8 -> 17.3 s (timing job 111485).

## 2026-11-22 waud1: one deterministic audio model (D222)

- The app's free play read voice status and positions from the real-time mixer (wapp1), so game state followed the
  host's audio device: two free runs with the same frame-indexed input (`HULK_INPUT`) at different speeds gave
  different game hashes. dsound_null.c is now the only model the game reads; outside replays its voices run on the
  virtual clock's 48 kHz (`SIM->ds_clock` 1, synced to `SIM->clock` at every DirectSound call), and the app's mixer is
  a mirror driven by the same calls and advances (`ff_audio_tick` -> `aud_tick`), rendering what the model played.
  The same two runs now give the same game state (paced 96 s vs unpaced under load 9 s; HEAD's app: 1.38M words
  differ). One leftover outside audio: with Metal the arena holds pddi front-end objects whose words point into the
  module's own malloc heap (above 1 GB), and that heap's layout follows host history (a paced run's log lines moved it
  by 0x18 bytes), so the game hash can differ while every differing word is such a pointer (3,905 of 3,905). Rollback
  with graphics needs those allocations in the arena or outside the hashed state.
- In gameplay the virtual clock keeps to real time exactly (35.01 game s in 35.01 real s): no field snapping or
  rate correction beyond +-0.05% was needed. Start-up movies (BinkWait jumps the clock) and loads run the virtual clock
  up to ~10x real time; the mixer drops those frames (silent in the capture) and the queue returns to ~67 ms.
- Replays keep 800 frames a DoWork: play3's records are byte-identical. With the virtual clock (`HULK_DS_CLOCK=time`)
  play3's sound* tag diverges from frame 586 (194 of 780 records) while every other tag is unchanged, so the
  reference's sound records follow the DoWork clock the recording was checked with.
- `HULK_KEY_SCRIPT` times keys by wall clock (tenths of a second since the first poll), so it cannot give
  identical runs at different speeds; determinism tests use `HULK_INPUT` (frame-indexed) in the app.
- `HULK_ROLLTEST=A:B` (sched.c): a snapshot at a fiber switch (every fiber suspended, all state in linear memory),
  restore at B, re-simulate to B: identical headless and in the app with `null`; with Metal the run traps after the
  restore with the mixer off too (the pddi front end's statics outside the snapshot), not an audio issue. Save paths
  are game state: identical runs need the same save directory paths.

## 2026-11-22 wasm15: softx87's fdivu in three divisions

- fdivu (a 128-bit mantissa over a small integer, the series' factorial steps) divides in digits of 48, 48 and 32
  bits: every partial remainder is below the divisor (< 2^16), so a remainder and the next 48-bit digit still fit in
  64 bits. Three divisions instead of four, the same quotient (50M random cases and every divisor 1..65535 identical).
- Wine pair 111487 (control, HEAD 37916f45b) / 111488 (proof) on studio, play3 to 60,000: GATE ok (ref: ok), only
  hulk-strict.exe differs. wasm: play3 records byte-identical through 60,000 frames; with the arena bounds, first
  12,000 frames on studio 17.8 -> 16.7 s (timing job 111486). wasm2c microbenchmark: sin -18%.
- Measured on the way: compiling the wasm host's x87.cpp at -O3 instead of -O1 gives the same records and next to no
  gain once fdivu is fast; softx87 built natively for arm64 (even with __int128 products) is only ~20% faster than
  through wasm2c, so native imports for it would not pay. softx87 is near its limit without changing its results;
  the rest of the early frames' trig cost is the series' term count.

## 2026-11-22 fps1: a 60 fps option in the game's own menus (D224)

- The five "per-frame constants" docs/subsystems.md listed as 60 fps risks are not per-frame (read block by block):
  0x18170's 1/30 is a height ratio, 0xfee10's a per-golem phase step in a constructor, 0x2b1df0's animation frames to
  seconds, 0x38660's 1/60 degrees / 60, and the controller/drive callbacks' 1/60 steps run inside the disconnect pause
  loop. An XBE scan for 1/30 and 1/60 (float and double, .rdata/.data references and immediates) finds no others in
  gameplay code (0x4a0e14's 1/60 is the front end's, which runs at 60 anyway). 60 fps is a pacing change only.
- The options screens are text (misc.rcf frontend\fe_real.txt / fe_run.txt; `AddNamedValueInt NAME DEFAULT CALLBACK`,
  `AddTextSelector`). NamedValueInt's Create (0x000f8e70) refuses a value whose callback name isn't registered
  (0x000df9e0's lookup), and a selector shows its first choice until code sets it (vfunc_25, the choice index): the
  camera selectors are set by 0x000b5ad0 from the front end's set-up 0x000c3ea0 and the pause menu's 0x000bcf40. The
  app injects its item through an archive overlay and three entry hooks (docs/wasm-port.md "The frame-rate option").
- Before waud1's deterministic audio model landed, free runs of the app took real time from the mixer: the same
  scripted input gave the Hulk two different paths (left trigger) run to run. With the model the runs repeat exactly
  (the comparison below was made on both, with the same result).
- At 60 the Hulk's walk, attacks and jump timings match 30 at equal game time (0.2 units over 47 s); a jump peaks 0.5
  units higher (smaller integration steps). Left-trigger moves end up to 9 units apart, less than the same plan at 30
  started one frame later (37): sensitivity to input timing, not the rate.

## 2026-11-22 wroll1: rollback with graphics in the wasm2c app; the tree's module globals in the snapshot (D225, D227)

- With Metal the app's game state held three kinds of host history: the pddi front end's C allocations (texture
  levels, prim buffer copies) in the module's own malloc heap, the front end's statics outside the snapshot, and the
  sink's bgfx handle values in front-end objects. Now the allocations are the arena's (`wasm_gfx.py` C_RENAME), the
  statics a snapshotted data section (`hulk_pddi_state`), and the front end sees only ids gfx.c gives out, with
  stamps; after a restore the runner's objects whose stamps differ are dropped and made again from the restored CPU
  copies (0.05-0.4 ms; 9-561 objects in the tests). Paced (95 s) and unpaced-under-load (5.8 s) Metal runs with the
  same `HULK_INPUT` end in the same game state; the frames after a restore are pixel-identical to an unrestored run.
- With a renderer the game never waits in gameplay, so `HULK_ROLLTEST` (snapshot at a fiber switch) never fired:
  rolltest now suspends and resumes the running fiber at each frame's end (`ff_frame_checkpoint`, only with it set).
- A rollback across PRESSSTART -> GAME (1200:2500) differed with `null` too, i.e. headless as well: the tree's own
  globals with no XBE address (function-local statics and guards, stand-ins like globalTextBible, the XboxDrive) are
  module data above 1 GB and were not restored; CSPManager 0x001e4760's local static registered its atexit entry a
  second time (4 words in the sim block). `wasm_port.py` puts them (73, not ??_R0) in `hulk_game_state`, which the
  snapshot carries; hashed apart from the game hash (vftable pointers move with the build).
- fe_options.c (fps1) kept the frame-rate setting and the game objects it watches in host statics: now in
  `hulk_game_state`. A rolltest 4000:5200 across a menu toggle at 4800 is identical: the restore puts the rate back
  to 30 and the re-simulated toggle makes it 60 again. play3's records stay byte-identical (headless, app with `null`
  and the overlay, app with Metal).

## wasmq3: play3's camera cut at 10196 (wasm, 2026-11-22)

- play3 on the wasm build lost the camera for good at 10196 (rng 10198): CCameraManager cuts from the chase camera to a
  script camera through a CBlendCamera, whose 0x00098500 reads each camera's state. A Wine probe (exit probes with
  dereferences on 0x98500/0xa04c0/0x9f8c0, f=10196) against the wasm hooks: the script camera's state is identical in
  both (its d = 90.00001 is the original's too); the chase camera's position is 0,0,0 on wasm. 0x98500 takes the
  position from slot 27's eax (`Vector* v27(Vector*)`), and CChaseCamera::vfunc_27 (0x000a0f40), CDramaticCamera's
  (0x000a8f70) and CGameCamera's (0x000a93e0) are void with eax = the out pointer in the original: the HULK_PORT_ABI
  class. They now return `hulk_eaxptr` (gen CGameCamera's slot 27 and its four overrides too); MSVC and the Wine build
  keep void (blocks MATCH, code hashes unchanged). play3's first persistent divergence moves from 10196 to rng 10847
  (actors 10860 float drift, particle 10869, camera 10928).
- Next (same day): rng 10847 came from ProjectileMissile::vfunc_5 (0x00194ba0), void in the source though the original
  ends in a call to 0x001dc0d0 whose result (the missile's owner node) stays in eax and 0x0019e910 reads (`fr.owner =
  vfunc_5()`); on wasm the owner was always null. A HULK_WASM_DEBUG_VOIDRET build (host hook printing each distinct
  void block an integer-result indirect call reaches, with the frame) listed it among 49 such blocks in play3's first
  20,000 frames; most are calls whose result nobody reads. With it returning `hulk_eaxptr`, play3 on wasm has no
  persistent divergence to 60000: only transient runs (camera 5875-5925, 34240-34282, 38673-38684, 38961-38964, 46930;
  particle 14584-14601, 14659-14670; hulk 34240-34281; actors 34260, 47160-47340, 48360, 49200-49290).
- 2026-11-22 (wmov1, D231): **Bink movies in the wasm app, and why they were black.** (1) PlayerBink (0x333de0) treats
  BinkCopyToBufferRect's 0 as "copied": only then does it hand the frame to CRadMovieRenderLoop::vfunc_3, which clears,
  draws the tiles and presents. The null model's 1 (a failed tile) meant no present at all during the start-up movies
  (mode 7's frame loop never draws: 0x86cb0 calls only the FMV manager), so each movie ran inside one frame. (2) The
  render loop clears before it begins the frame; bgfxContext opened a view for that clear after the last frame's draws,
  and bgfx ran it after the new frame's view 0, wiping the tiles. Fixed for the wasm front end only (HULK_PDDI_WASM);
  the Wine and native builds have the same bug (follow-up with a Wine pair). (3) BinkWait's virtual-clock jump played
  movies at the host's draw rate; the runner now sleeps to a per-movie wall-clock anchor, which only decides when
  BinkWait returns. Free runs with the same HULK_INPUT (holding B through a skip) under different CPU load end in the
  same game hash; rolltests across a movie (100:160) and across a skip (110:200) are identical.

## 2026-11-22 fps2: the same game at any display rate (D228a)

fps1's 60 fps changed the step (a jump peaked 0.5 units higher). Now the simulation always takes the original's fields
and the runner draws extra frames. The draw sink was the right seam: the bgfx sink draws only from a packet's vertex
constants (plus textures, state, buffers), so recording each update's sink calls and lerping the constants of matched
draws gives in-between frames with no tree change and no path back into the game. What we learned:
- The shader serial (`pddiBaseShader` +0xc) is a change serial, new at every set-up: keyed on it, 97% of the front
  end's draws never matched. The shader kind plus the prim buffer serial, combiner hash, texture ordinals and pass
  match 99.5% of draws.
- Camera-space translations move with distance when the camera turns (things 2,700 units away moved 37 units in one
  update with a 0.8 degree turn): a jump test has to be relative (40 units + 0.3 x distance), or every far draw snaps.
- Elementwise lerp of composite matrices (bone x modelview, world x view x projection) is enough at 30 Hz steps: the
  shrink is 1 - cos(theta/2), invisible below 20 degrees an update, and decomposition is not possible for composites.
- A present clock independent of the update clock handles a 75 Hz display (2-3 presents an update at their true
  times); at whole ratios it realigns every update and the last present is the update's own frame.
- Input latency is unchanged to the first present (~2 ms after the pad's sample); the update's full pose arrives
  period - display period later (16.7 ms at 60, 25 at 120).


## 2026-11-22 wopt1: Video / Gameplay Options, the remastered switch, render resolution; invisible menu text

- Invisible front-end text on the port builds (titles and unselected items; the highlighted item readable): not the
  bgfx backend. 0x000dedd0 CDisplayEffect::DrawableText::vfunc_1 is a tail-jump forwarder (`mov ecx,[ecx+8]; mov
  eax,[ecx]; jmp [eax+0x3c]`): Font slot 15 SetColour with the caller's stack argument. Its source called `p->f15()`
  without it, so the drop-shadow effect (0x000dee60: getColor / setColor(shadow) / draw / setColor(saved)) left the font
  colour 0 (alpha 0). Found by logging the text draws' vertex colours (0x00000000 while the TextButton's colour words
  held 0xffffffff). Fixed in dd2d265b0 (MSVC 7.1 emits the same jmp for `p->f15(colour)`).
- The same class: blocks whose original code is a tail jump through a vftable with no stack access of their own pass
  the caller's arguments on; a source that declares no parameters drops them on every port build (wasm, 64-bit) while
  MSVC still matches. A scan of the 52 such blocks (`mov ecx,[ecx+N]; mov eax,[ecx]; jmp [eax+M]` and kin), with each
  slot's arity from the other implementations' `ret N`, found 0x0025e710 om::MetaEntity::vfunc_4 (fixed); open:
  0x00099330 (same slot as 0x00099320, which forwards four), 0x002beaa0 / 0x002beab0, 0x0022a930, 0x00333ca0.
- The settings layer is one table (port_settings.c); the front end's own menu machinery does the rest: a text
  selector over a named int per setting, built by the misc.rcf overlay, three entry hooks shared by every item. The
  game's top-level tabs (Options / Story Mode / Extras) are the "main" screen's horizontal buttons: a free run reaches
  them by B from story_mode, then left, then A (HULK_INPUT presses of 2-3 frames; the first ~60 frames after a screen
  opens ignore input; a selector at its last choice does not wrap).
- Render resolution can live entirely in the runner: the module asks for a 640x480 frame and reads back only that
  size, so the scene target, the frame copies and the copy targets of the frame's size are made larger there and the
  passes into them get scaled viewports. 1x and 3x runs of the same HULK_INPUT give byte-identical checkpoint records;
  the game hash with Metal differs between two runs at the same setting (front-end pointers into the malloc heap).

## 2026-11-22 nat3: the last native (64-bit macOS) pass (D221)

- Native start-up at HEAD still stops at play3 frame 0 on a local script stand-in's vftable (Lua's slot-2 call). A
  private diagnostic that points only the script stand-ins' local vftables at the game's (compile-time, never landed)
  measured the rest: with it, start-up runs every script and loads the front end's first p3d far enough to need
  six more source fixes in an afternoon, each one a 32-bit view or an unaddressed name (docs/native-build.md "nat3").
- A name the Wine map binds by position can stand for different addresses at different call sites
  (LoadStream::Init: 0x002640f0 in Destroy, 0x00263f50 in Target): natively it is one unbound name. Write each
  call's own address name.
- Script invokes that propagated another instantiation's signature (`(const char*, int)` for `(float, float)`) match
  on 32-bit (stack slots) and pass the wrong registers natively; 220 got typed HULK_PTR64 branches by a generator.
- Redirecting every local vftable to the game's crashes earlier than redirecting none: the game's slot functions
  then run on stand-in objects built with 32-bit pads. Vftables and records go together.
- The wasm build needs none of this (32-bit data at XBE addresses, packers for declaration mismatches): that is the
  whole gap between the two ports.

## 2026-11-22: gcmp1, the intro's missing scenery in the wasm app (a data name that bound nothing)

- **Symptom.** In the app's in-engine intro (the fly-around of the base, the soldier with the VR headset) the canyon
  backdrop, the helicopter, the jeeps, the officers and the subtitle text were missing. Compared with the Wine build
  (`--gfx`) on play3 without the press that skips the intro: game state identical (every ckref tag), app frame N =
  Wine GameClock frame N-192 (the app's screenshot numbering counts presents), same draw count per frame (239 at 750)
  — the draws reached the sink, but 48 a frame carried a world matrix with a zero 3x3, collapsing them to a point.
- **Cause.** 0x00295e20 `pure3d::scenegraph::Node::vfunc_17` returned `&one` from a block-scope `extern float one`
  (the original: 0x4c9f38, the identity matrix). MSVC matched and the relocations were ok, but on the wasm link `one`
  bound nothing and became a zero-filled named stub, so every root TransformNode combined its local matrix with
  zeros. Found by debug hooks on the matrix stack (PushLoadMatrix of a zero 3x3) and TransformNode::vfunc_17 (world
  zero, parent a plain Node). The void-eax run-time scan over the intro showed nothing new.
- **Fix.** The DAT_ name (DAT_004c9f38), and the two other data names the wasm link stubbed: the audio Sequence pool
  (DAT_004e7620 with its free FUN_00247550, as 0x00257c90) and the shared 0.0f (DAT_003f335c in 0x000d94e0, D187
  unproven-accept). play3 headless records byte-identical before and after (60,000 frames).
- **Guard.** `wasm_port.py link` lists the data names it stubs (`data_undefined` in link.json) and fails on one that
  config/wasm-data-stubs.json (only shrinks; now just `??_7type_info@@6B@`) doesn't list. Function stubs stay reported.

## 2026-11-22 wvid1: aspect ratio, HUD frame, draw distance and fog in the app (D234, D235)

- **Widescreen is the game's own path.** The app reports the chosen aspect through `bgfxDisplay::vfunc_16` (the
  frame stays an anamorphic 640x480, as an Xbox 16:9 480p mode) and the runner draws the scene target at that shape.
  Hor+ cameras, the HUD's text layout and the movie scaling follow by themselves; the corner brackets are fixed 4:3
  models (HUD Frame: Screen Edges reuses HULK_HUD=edge).
- **16:9 changes the simulation, as remaster.md 3.3 predicted.** On fps2's 8,000-frame HULK_INPUT run the checkpoint
  records match 4:3 through the front end, the load and ~1,000 gameplay frames, then rng/legacy diverge at record
  4,342 (~frame 7,000), particles 4,728, hulk/camera 4,773, actors 4,800; flow, clock, mission, sound never. User
  decision D234: a per-session setting (replays and tests pin 4:3; netplay peers share it).
- **Draw distance leaves the simulation alone but not the game hash.** Setting World::Render's fade floats only while
  it runs: all ten checkpoint tags identical over 8,000 frames; the game hash identical to frame 7,010 and different
  from 7,020, when rooms past 295 units first come into view: pure3d's per-frame render lists' tails past the faithful
  high-water mark, the pddi front end's vids/serials of prim buffers uploaded at their first draw, and the arena
  allocator's bounds after those uploads. World::Render's own list of drawn rooms (+0x54c) is write-only. D235: also a
  per-session setting. Resident rooms reach only 340-390 units in the first mission (14-16 rooms), so Far is 400.
- **Game hashes don't compare across app builds any more**: the settings' menu handlers are module data whose address
  the game's NamedValueInt objects hold, so two builds differ from frame ~10; compare settings within one build
  (`HULK_DRAWDIST_FORCE` compares the hook alone with identical menus).

## 2026-11-22 wui1: the app finds the game on first launch

- The app no longer needs a terminal or a hand-copied disc: started with nothing on the command line and nothing
  remembered, it shows an alert ("Hulk needs your own copy of the game: choose the extracted disc folder or its
  default.xbe"; Choose Folder... / Choose default.xbe... / Quit) and the system's open panel (SDL3's file dialog over
  NSOpenPanel; `wasm_app.py sdl` now builds SDL with `SDL_DIALOG=ON`). run/app/start.cpp, docs/wasm-port.md
  "First launch".
- The check reads the player's file at run time: "XBEH", the certificate's title ID (0x56550039), and every archive
  the disc's own rcfs.txt lists. A wrong pick says why (no default.xbe, another game's title ID, the missing archives)
  and asks again. The choice is kept in ~/Library/Application Support/HulkUD/game.txt; Option held at launch or
  `--choose-game` asks again. The command line keeps priority and scripted runs (HULK_NO_UI, HULK_INPUT,
  HULK_KEY_SCRIPT, HULK_INPUT_SOURCE, HULK_CKPT) never prompt.
- Testing note: with no window SDL runs NSAlert / NSOpenPanel `runModal`, so the dialog's callback has run when the
  call returns. A locked screen leaves the alert up with no way to click it from a shell (System Events sees no
  windows; screencapture fails): the flow was driven through start.cpp with SDL's entry points mocked (9 cases), and
  the real alert seen in `sample` (NSAlert runModal).

## 2026-11-22 wpack1: texture and model override packs in the app

- **Keys at the sink (D9 option A).** `tex-<XXH64(le32 format, le32 width, le32 height, level-0 bytes)>` over what the
  app's draw sink receives; tools/texpack_convert.py computes it from the Xbox ImageData payload. No hook in the game.
- **The PNG row question is settled: the Xbox loader flips PNGs like the GameCube one.** A session's dump (8,000
  frames: start-up, menus, the first mission's start) uploaded 624 keys: 574 DDS payloads match their blocks as
  stored, 42 PNG payloads match decoded with rows flipped, none as stored; 8 are run-time textures. Every texture is
  uploaded bottom row first, so Dolphin pack PNGs (GX order) are used unchanged.
- **The user's Dolphin pack as an app pack**: `texpack_convert.py pack` wrote 2,308 textures (hard links to the
  pack's files, no extra disk) into the user's Application Support mods folder. In the scripted run 381 swaps of 363
  replacements, 2.6 s of decode + BC encode on worker threads, 68 MB CPU cache, 41.5 MB on the GPU, index 0.7 ms;
  checkpoint records identical to the run without the pack, HULK_ROLLTEST identical with it (6500:7600, 1200:2500).
- **Replacement beside the original, never instead of it.** The original texture stays alive and complete, so the
  menu can switch packs live, and draws counted by an occlusion query keep sampling it (the game reads their pixel
  counts; an alpha-tested HD replacement could change them).
- **Models, minimal**: `mdl-<key>.obj` per prim buffer (key over the packed vertices), attributes the OBJ lacks
  (vertex colours = baked world lighting, UV set 2, skin weights) taken from the nearest original vertex. A test pack
  that scaled the first mission's skinned groups by 1.3 and dropped half the HUD models' triangles drew as expected;
  records identical. Skinned replacement by joint name (remaster.md R5) is the documented next step.

## 2026-11-22 wasmq4: the wasm build's last camera-only frames (0x0009ffc0's asin)

- **Re-scoped first.** Against play3.ckref the wasm build (after wasmq3) and every Wine build since decl2 (110325, to
  111488) give identical records except camera 38,673, 38,684, 38,961-38,964 and 46,930, which only wasm missed. The
  rest (camera 5,875-5,925; hulk/camera 34,240-34,282; actors 34,260, 47,160-47,340, 48,360, 49,200-49,290; particle
  14,584-14,670) is shared, and the particle frames are the reference's own noise (checkpoints.md "The 16 frames after
  14,584"). The shared list is now in docs/checkpoints.md.
- **The camera frames were 1-ULP pos_y differences** (Wine 111517 / wasm ckdump), no propagation. CChaseCamera
  (vftable 0x405604) state 6, 0x000a6400: the pitch target f.q came out 8 float ULPs off after the clamp to
  `lo2 = -deg - (o48 + f470)`; o48 is 0x0009ffc0's `asinf(v) * 57.295776f`.
- **Cause: a library name bound to a game function.** The source called `asinf`, which binds (bindings.json, by
  position) to the game's clamping asin 0x000189c0. The original keeps that call's st0 result unrounded for the
  product (fmul dword; fstp dword), and so does the Wine build (x87-keep code); the port builds took the declared
  `float` return and rounded the angle to a float before the product. Fix: declare and call the definition
  (`fn_f7aff818::FUN_000189c0`, hulk_freg) and round the product once; still MATCH with relocations ok. `asinf` is the
  only libm name in the binding map that resolves to a game function, so there is no sibling.
- **How it was found:** Wine probes (FUNCS/EXIT on the camera family, SPAN of the camera object) against wasm entry
  hooks; calls inside one TU do not reach wasm entry hooks, so the last step used debug calls compiled into a private
  snapshot copy (an `extern "C" ffh_<name>` that the hook host file defines links fine).
- **Two side results.** Wine's msvcrt asin equals x87 code at PC 53 (fsub/fadd/fmul/fsqrt rounded to 53 bits, then
  fpatan) on all 8,281 arguments of one frame, while softx87's asin (unrounded root) differs on 1,354; Wine's acos is
  musl's (0 of 15,764 differ). Switching wasm's asin to the PC-53 root, or acos to musl/libm, changed no play3 record
  in 60,000 frames, so nothing changed there.

## 2026-11-22 wr2: R2 cheap wins in the app as runner passes (D236: mipmaps, anisotropic, MSAA, pack disk cache)
- **The runner's pass interface** (run/app/rm_pass.h, remaster.md 5.3 in its R2 form): passes register themselves and
  see the settings (one `gfx_quality` import), every draw packet, draw submissions, prim-buffer writes, the scene
  target's first pass and the end of the game's frame; app.cpp and interp.cpp's replays reach the sink only through it.
  wvid1's fog override moved into it unchanged.
- **55% of the game's textures have no mips** (347 of 624 the scripted run uploads: DXT1 64x64/128x128 world
  textures); others have partial chains. Full chains made by the runner from the game's own levels: 25 ms of encoding
  for the run. bgfx's Metal renderer has a single anisotropy level (16x, a reset flag), so the option is Off / 16x.
- **MSAA on the scene target works through bgfx as is**: its Metal views store and resolve (StoreAndMultisampleResolve),
  blits read the resolved texture, so the frame copies, the effects' targets and the present are unchanged. Occlusion
  queries count samples; the runner divides. 8x costs 3.7x the GPU time of 4x at 1920x1440 (every game view stores 8
  samples).
- **Game state:** checkpoint records byte-identical with every option on; a HULK_GAMEDUMP at frame 8,000 differs from
  the same run with the options off in 6 words, all three options' menu values (a setting's value is a menu
  NamedValueInt). play3 with null: records identical to the control app.
- **Shadows** are stencil volumes (about 5 stencil draws a frame in gameplay); the game makes no shadow render target
  (the scripted run makes 320x240 and 2 x 160x120 effect targets and one frame copy), so there is no resolution to
  raise; MSAA and the render resolution already apply to them.
- **Pack disk cache**: <app dir>/cache/textures; first launch 3.1 s of decode + encode, next launch 0.14 s of reads.

## 2026-11-22 wmodel1: model replacement feasibility (docs/model-replacement.md)

- **Pre-lit placed props are baked in world space, one `mdl` key per placement** (vertex flags 0x2021/0x2022/0x2032):
  the sandbag mesh `bunker_bunkerBagsShape` drew under 8 keys with identical topology and different positions. A
  per-prop replacement needs an instance fitter (rigid fit to each placement). Dynamic props and vehicles (0x2011) are
  in model space, one key per mesh (colour variants and damage states are separate meshes).
- Census (tools/p3d.py over the extracted .p3d): rooms 1.18 M triangles in 784 files (at most 2,461 a file); 37
  distinct skins of 2.2k-3.8k triangles; about 110 vehicle meshes of 100-500; about 770 props (median 45); 805 files
  carry collision chunks, which a draw-time replacement never touches.
- tools/mesh_remodel.py (`fit` parametric cylinder/box per part, `smooth` PN triangles with straight edges at hard
  vertices, UVs from the original triangle underneath): the desert tutorial's 8-sided barrel group as 32-sided ribbed
  drums looked clearly better with the original texture; PN smoothing of a hard-edged car barely shows. Free app runs
  are not deterministic (real-time mixer): compare packs by ckref, not the game hash.

## 2026-11-22 wand1: the wasm2c app on Android

- **Cross-platform determinism holds.** The same hulk.wasm run through wasm2c and compiled by Apple clang (macOS app)
  and by the NDK clang 21 (arm64 Android 12+, APK in the emulator) writes byte-identical play3 checkpoint records
  (`HULK_GFX_RENDERER=null`; two modules, 60,243 and 60,244 frames in common, 0 differ; the macOS .ckref is a byte prefix of the Android one).
  Both use the C compilers' defaults (`-O2 -fno-strict-aliasing`, FP contraction left at the default): wasm2c emits
  one float operation a statement, so nothing fuses. A Vulkan-rendered replay gives the same records: the renderer
  does not reach game state. This is the property co-op lockstep needs between macOS and Android peers.
- Android windows created SDL_WINDOW_FULLSCREEN never send a pixel-size event: the runner must report the size
  itself, and only once the pddi display is up (bgfxDisplay::hostResize returns before initialisation and the pending
  flag was lost).
- Storage Access Framework folders give content URIs, not paths, and the game opens files by path: the chooser copies
  the disc (2.2 GB) into the app's files dir. adb-written files in Android/data/<pkg> stay unreadable to the app
  (and1); `run-as` copies work on debug builds.
- Emulator speed (swiftshader, laptop under load 35): ~260 frames/s headless, 5-20 frames/s rendered at 2400x1080;
  not representative of a device GPU.

## 2026-11-22 whang1: the app's saves without a save folder; a hang after a mission summary (tabled)

- **Save folder.** `hulk_app_start` (run/app/start.cpp) returned early when the game came from the command line
  (argv, HULK_XBE, HULK_DATA_DIR) before it set HULK_SAVE_DIR, so xapi.c fell back to `build/wasm/save` under the
  working directory: a played launch from the repo saved there, one through `open ... --args` (working directory /)
  had no writable folder. With an unwritable folder play3 stalls at the level-1 summary (GS_PAUSE at 8718, never
  POSTGAME): the game polls XFindFirstSaveGame and GetDiskFreeSpaceExA for a save that never succeeds. Now every
  interactive run saves in `<app dir>/save` (an explicit HULK_SAVE_DIR still wins); a scripted or test run (HULK_INPUT,
  HULK_KEY_SCRIPT, HULK_INPUT_SOURCE, HULK_CKPT, HULK_ROLLTEST, HULK_NO_UI) never defaults to it (run-local
  `build/wasm/save` unless HULK_SAVE_DIR) and exits 2 on a HULK_SAVE_DIR inside ~/Library/Application Support/HulkUD
  unless HULK_APP_DIR is set, so tests never touch the player's saves; the app prints where it saves, and xapi.c
  warns once when the save folder can't be made.
- **The reported hang (tabled by the user).** The user's session (launched from the repo, so its saves are in
  build/wasm/save) got past level 1: four saves, one per mission summary (the folder is a hash of the save's name, the
  mission; each save empties the previous folder): 19:15 (level 1, the folder play3 makes at 8718), 19:20, 19:25, and
  "Need-To-Know" at 19:31 (complete). The hang came after that summary and its save. Ruled out with play3 (it passes
  every summary to 60,000): every remastered setting pinned, null and Metal (aspect 4:3 and Window at 4:3), the texture
  pack, lockstep I/O off. Not covered by play3: 16:9 (changes the simulation, D234), the free-play movie and audio
  paths (off in replays; play3 is recorded with no-fmv, so no FMV ever plays in it). From a copy of the user's save
  a free run (Metal hidden, the user's settings) loads into gameplay: Continue Game, the Church menu, Return to
  Gameplay, "Press START" (A works too). Free runs can't follow play3's input: free play plays the level-start FMV and
  an unskippable ~3,300-frame in-engine intro. Scripts and the way back in: build/whang1/RESUME.md.
  First thing to check when it comes back (lead, from wskip1): the game's out-of-memory loop FUN_0008d320 spins
  forever when the streaming code can't get a temp heap (wskip1 hit it by jumping c00m02's script state early); a
  load after a summary under heap pressure from a remastered setting (wider aspect or Far draw distance loading or
  keeping more) would hang the same way: sample the hung process and look for 0x8d320. (The texture pack and MSAA
  live in the runner, not the game heap.) wskip1's free run passes summary -> save -> continue on the current build.

## 2026-11-22 wprof1: a profile of the macOS app (draw calls, uploads, pacing)

- The user's hypotheses (no draw batching, vertex data re-uploaded) do not hold where it matters: prim buffers are
  uploaded once at their first draw after a change (0-0.8 vertex buffer uploads an update in gameplay, ~8 KB; static
  world geometry and skinned meshes never again), and 90-360 draws an update cost ~1-2 us each to encode on Metal.
  Only 3-6 consecutive draws an update could merge; 20-130 differ only in their vertex constants (instancing).
- The remastered defaults (1080p, 60 fps by interpolation, the pack) take ~3 ms an update unpaced: the game in the
  module 43% of the main thread (x87 helpers 7.7%, ff_dispatch 4.6%), bgfx Metal encoding 25%, GPU wait 10%, interp
  9%, bgfx Metal's per-frame transient MTLBuffer (newBufferWithBytes + blit) 4.6%. Paced at 60: ~15% of a core.
- interp.cpp's pacing wait yields for the tail of each wait; timers wake 1-2 ms late under load. A mach_wait_until
  version spun less but woke later on a loaded laptop (load ~35): kept as it is until measured idle (docs/wasm-port.md
  "Profile").
- A scripted `HULK_INPUT` run parses the script with sscanf every frame (host/frame.c; ~1% of a fast run): test-only.
- `HULK_GFX_STATS=N` (run/app/gfxstats.cpp) logs the counts; docs/wasm-port.md "Profile (wprof1)".
## 2026-11-22 wr2: the far-field prototype (D236 item 4; docs/far-field.md)
- **Matching the game's room buffers to the disc's rooms** needs vertex positions, not prim groups: the game splits a
  prim group into several prim buffers (33..139 vertices in downtown), the positions it hands the sink differ from
  the file's in the last bits ((x, 4.8e-06, z) for (x, 0, z): a quarter-unit grid matches), and downtown day / dusk /
  night (and the tutorial and the outskirts) share most geometry, so a position names several locations and the
  location is decided by votes. Then ~1,600 of the game's downtown buffers are rooms' (~17% of its buffer draws).
- **The game draws 2 to 8 rooms a frame** in downtown (the open measurement of remaster.md 3.3): the rest are
  resident but culled, or not resident. The visible skyline beyond is the location's background drawables.
- **Most room shaders live in the location's district files**, not in the room files (6,198 of 6,773 downtown prim
  groups found no TEX until the districts were read for shaders too).
- **A room draw's constants are the camera's** (rooms are in world space), so a far room drawn as a copy of the
  frame's first world-pass room draw lands in place; the first room draw into the scene target is not always the
  world's (another scene pass draws rooms for the map), hence "the scene pass with the most room draws last frame".
- Cost as prototyped: one draw per prim group (~1,000-3,800 a frame in downtown); docs/far-field.md has the plan.

## 2026-11-22 wasmq4 (2): the shared actors drift from 47,160 (0x0001b510's damage)

- **Reference side by xemu field dumps** (queue jobs on mac2 / studio, -snapshot, build/wasmq4/scripts/submit_xemu.sh:
  ckpt1's xemu_ref.sh plus hybrid/hooks.cpp and exclude.txt shipped as files, since a queue workspace has no hybrid/):
  111531 at 47,160, 111530 at 34,240. At 47,160 only actor 5's health differs: 433dc293 in the original, 433dc292 in both
  builds.
- **Writer by Wine HULK_TRACE_WATCH on the absolute health word** (the actor's address from a SPAN of 0x00040970's ecx;
  heap addresses are stable within a lineage): 0x0003b1c0 SetHealth from 0x00043350 (damage) from 0x000437a0, called by
  0x0001b510 (CWeaponCollisionAction's spawn action) with the damage. 0x00043350 itself rounds at every step, as the
  original does; the damage it is given was already one ULP off.
- **Cause:** 0x0001b510 interpolates the hit's damage (`t * (hi - lo) + lo`), scales it by the multiplier and by the
  attacker's strength words; the original keeps all of it in st(0) and rounds once when storing, the source rounded the
  interpolated value to a `float` twice on the way (`float v`). Now `hulk_freg v` and `(hulk_freg)` on the first product;
  MSVC code unchanged (D187: Wine-mode unproven-accept, re-pinned). wasm and Wine (111547) play3 to 60,000: the actors
  frames 47,160-49,290 are gone, nothing new; both builds give the same records.
- **34,240 (Hulk y, open).** Watch on the Hulk node's matrix row: in frame 34,240 the last writer is 0x0022ca90 (matrix
  product) under Pose::Update, giving 401d45b4 against the original's 401d45b3, so one of its inputs differs. 0x0022ca90's
  float sums already evaluate at double in both clang builds (-ffp-eval-method=double: a hulk_freg rewrite changes neither
  code hash), and the softx87 asin/acos variants changed nothing there either.
- **Probe notes.** HULK_TRACE_FUNCS/EXIT are link-time (`--env`), SPAN/FROM/MAX/WATCH/XDEREF run-time (`--replay-env`);
  hot probes (matrix functions) need `--replay-timeout` well above the 300 s default. A wasm entry hook does not see calls
  made inside the defining TU, even at -O0 (HULK_WASM_OPT_EXCLUDE): for those, compile `ffh_<name>` debug calls into a
  private snapshot copy, which link against the hook host file.

## 2026-11-22: wasm builds and tests on the queue (wbuild1)

- `tools/wasm_build_job.py` (host side `tools/wasm_build_run.py`) builds the headless hulk-aot or the app (and
  Hulk.app) on mac2 / studio (new `wasm` cap) and runs play3 / rolltest / input tests there, alone or against a control
  on the same host (docs/compute.md "Wasm builds and tests"). Cold builds take 80-100 s on 8 slots against 21-24 min
  on the loaded laptop; a warm app rebuild 29 s; play3 to 60,000 frames 70 s.
- The toolchain is the laptop's own Homebrew Emscripten copied to ~/hulk-jobs/wasm/tc and used `FROZEN_CACHE`, so the
  C library in the module is the same bytes; records of the same commit built remotely and locally are byte-identical
  (headless 2,500 frames, app with null 3,000). emcc's link of the standalone module still runs node
  (`compiler.mjs --symbols-only`): the hosts take nodejs.org's own build (Homebrew's node links ~20 Homebrew dylibs).
- Free-run game hashes depend on the run's directories (save / data paths are game state): the same executable run
  twice in different directories differs from frame 310 (just after the START press); in the same directory it is
  identical. The tests run every role in one directory.
- The app also needs bimg's 3rdparty/stb (texpack.cpp includes stb_image by a path relative to bimg/include).
- mac1 has no Command Line Tools (no xcrun, no SDK): it cannot build or link the runner; it stays without `wasm`.
- A Metal device works over ssh on mac2 and studio with `HULK_GFX_HIDDEN=1` (both have a console login).
- wasm_app.py's app-inputs.json now also covers src/platform/sdl/host/native_hooks.h (the replay hooks wasm_port
  places in the TUs they name at bind time): a hooks edit used to relink stale objects. Existing build dirs compile
  every TU once.

## 2026-11-22 wlight1: per-pixel lighting and health-orb lights in the app (docs/lighting.md)

- The user asked for per-pixel lighting and for health orbs to light the ground. Both are one runner pass
  (run/app/lighting.cpp) with its own bgfx shaders (run/app/shaders, tools/rm_shaders.py): the faithful shaders and
  the Wine image are unchanged. The per-pixel fragment shader includes the faithful combiner (`fs_vp_stage.sh`) with
  its two vertex colours replaced by macros that light the pixel, so every combiner key keeps its exact combine.
- play3 draws no skin-program draws in the frames dumped (tutorial, city): Hulk and the characters come through the
  fixed-function path with two-sided lighting (vertex program 6), props through program 0 lit, the world unlit.
- A health orb is a pair of additive draws (a 6-vertex camera-space sprite, then a 14-vertex mesh with the same
  texture), twice a frame; the mesh's content key differs between locations, the pair's shape does not. The textures
  are grey and the draws carry no colour: the light is the orbs' green. Found with two dev switches
  (`HULK_LIGHT_DUMP`, `HULK_LIGHT_HIDE`): hiding one texture's draws at a shot frame names the effect in one run.
- The world's draws are before the effects in a frame, so the lights go to world space (the frame's view is the
  modelview of every static world draw: 115 identical at the city frame) and apply from the next frame. Lights only
  touch draws whose prim buffer's bounding sphere reaches them: 180-220 per-pixel draws a frame became 30-90.
- Tool lesson: editing tools/wasm_port.py in a workspace makes `wasm_app.py build` recompile every TU (the tool's
  digest is in app-inputs.json); the shader step therefore lives in wasm_app.py (and wasm_android.py).

## 2026-11-22 wskip1: a star that skips the two tutorial missions (the app)

- **What.** Gameplay Options > Tutorial Skip (remastered-only, default On; faithful Off). In c00m01 and c00m02 a
  spinning star waits ~4 units behind the Hulk where play starts; walking into it ends the mission through the game's
  own bindings (src/platform/wasm/gfx/tutorial_skip.c; docs/wasm-port.md "Tutorial skip").
- **Mission state is not enough.** Setting c00m01's progress to "complete" does nothing until the mission's last
  stage polls it, so the skip calls the success sequence the mission's ending calls (progress, the next mission to
  acquire, MISSION_SUCCESS; for c00m02 the next mission, the XP and MISSION_IMMEDIATELOAD). Jumping c00m02's script
  state to "complete" during its intro started a later stage's streaming: a temp heap with no room left, and the game
  spins in its out-of-memory loop FUN_0008d320 (sampled: UpdateSimulation > Lua > 0x002080b0 > 0x002047c0 >
  0x00266e00 > 0x0008d320). A hang whose stack ends in 0x0008d320 is the game's own allocation failure.
- **"In play" needs more than a controller slot.** c00m02's in-engine intro gives the Hulk slot 0 and moves him while
  the camera cuts close; the star waits for the game camera (camera manager flags, world +8 then +4, & 0x5e == 0, as
  cm_IsGameCameraActive), no letterbox (nism_IsLetterBoxOn's two floats on the logic view's +0x14), the logic view
  within 14 units and the Hulk standing for 45 updates.
- **Drawing through the game's pddi from host code.** The context *(0x52c2a8) slot 30/31 (begin/end prims), the
  stream's +8 / +0x10 vertex pointers and FUN_0008ef00 (next vertex), the device *(0x52c2a0) slot 11 ("simple") and
  shader slot 6 (BLMD, LIT, 2SID) work the same with the pddi front end and the game's own d3d layer. A transparent
  disc drawn with depth writes hid the Hulk behind it: context slots 62/63 set and read the z write.
- **Checks.** Free runs (Metal hidden, HULK_INPUT): c00m01 skip -> Mission Success -> Save (save.dat written) ->
  Continue -> c00m02; c00m02 skip -> c01m10 loads and plays to its own Mission Success. Off: the checkpoint records of
  a 12,000-frame run identical to HEAD's app. HULK_ROLLTEST 6450:6600 (placement, the shaders' creation) and
  6650:6800 (the skip) identical (game, state and gfx hashes). Two On runs of 18,000 frames: identical records.
  Queue (wbuild1): candidate 111569 vs control 111568 (HEAD 686761671): play3 to 60,000 (null) records identical
  (111571); rolltests 6650:6800 and 11990:12100 across both skips identical (111573, Metal hidden). The `input` pair
  (111572) differs from frame 10 by game hash, as any new settings row does (the row's named int and handler are
  game-held module data); the checkpoint records of that 14,000-frame run with the setting off are identical.

## 2026-11-22 wpkg1: the game from an .iso or a compressed disc pack; AV1 movies; one-file texture packs (D237)

- The disc is mostly already-compressed media: zstd at any level or chunk size gives ~84% (2.45 -> 2.06 GB). The
  movie archives are 99-100% (Bink) and sound.rcf 88%; rooms.rcf 44%, art.rcf 61%. The size win is the movies:
  1,226 MB of Bink -> 205 MB as AV1 + Opus, so the AV1 pack is 1.045 GB.
- What the game reads of a movie (HULK_DISC_TRACE over play3): each movie archive's 60-byte header and directory,
  and for an opened movie the first 1 KiB (bink_null.c takes 44 bytes). So the AV1 pack keeps 64 KiB of every movie
  and zeros the rest, and the records stay byte-identical.
- The Bink sound tracks are 6 mono tracks per movie (ids 0..5 at header offset 44 + 8n): at 48 kbit/s each Opus is
  bigger than the AV1 picture of the 640x336 movies; 32 kbit/s mono.
- Pipes both ways to a child (stdin list in, "ok" lines out) deadlock once both fill (~240 lines here): texbake reads
  its list from a file. `adb exec-in` returns before the device has written the last bytes: poll the size, then mv.
- HEAD's own app build diverges from the reference at 5875 (camera), 14584, 34240, 34260 on play3 (control 111575):
  compare candidates to a control, not to the reference alone.
- The Android build at HEAD failed in gfxstats.cpp (macOS-only CLOCK_UPTIME_RAW): fixed in 66ec42785.

## 2026-11-22 wapk1: one APK plus one file (the game, AV1 movies and the HD texture pack) for Android

- The user's ask, after a scope change: an APK beside one packed file to load. Android's picker grants only the file
  picked, so the texture pack travels inside the disc pack: `disc_pack.py build SRC OUT --texpack F.hulkpack` stores
  its files under `.hulk/texpacks/<name>/` (a pack SRC keeps its AV1 movies and texture packs). texpack.cpp lists them
  as a one-file pack when HULK_DATA_DIR is a pack; disc.c now lists a `.hulk/` folder when asked for it directly.
- Android FFmpeg plays AV1 packs: dav1d 1.5.1 (meson + NDK, static, in libavcodec.so), FFmpeg's Opus decoder (needs
  libswresample: configure drops it silently otherwise, "Disabled opus_decoder because not all dependencies are
  satisfied: swresample"), the Matroska demuxer. 30 s to build.
- The emulator's Vulkan device is llvmpipe (`adb shell cmd gpu vkjson`): BC native, ~17 frames/s with Vulkan; its GLES
  (ANGLE on SwiftShader) lists no S3TC. bgfx decodes a format the device lacks to BGRA8 at upload
  (getViableTextureFormat), so Mali handhelds (no textureCompressionBC) work at 4-8x texture memory.
- `native_replay.py run` without `--data` reads isos/extracted whatever XBE path follows `--`: pass `--data PACK` to
  test a pack. A HULK_SAVE_DIR reused between replays carries a save and diverges play3 from frame 450.
- A first try stored the pack in the APK (assets, stored, AssetManager.openFd as `fd:N@OFF`): it installed (1.31 GB,
  streamed install in 5 s) and replayed identically, but the user chose the separate file; the patch is
  build/wapk1/apk-assets.patch (local).
## 2026-11-22 wquit1: Quit in the app's menus; the pack status line

- **Quit.** "Quit Game" at the end of the main menu's Story Mode column quits at once. The game's front-end functions
  ("OnSelect function NAME") are looked up by name at parse time (0x000df970, from FEDoFunction's constructor); an
  entry hook answers our names with host handler objects, the same trick as fps1's int callbacks, so a menu item can
  call any host code. The window's close button, Cmd+Q and the menu share one path (a quit request the pddi pump turns
  into ExitProcess(0)); it waits while the game holds a file open for writing (a save), and the runner's proc_exit
  closes the movies, audio and SDL. Tested: the menu item, Cmd+Q (System Events keystroke) and the close button (AX
  click) all exit 0 with the same log lines.
- **The front end has room for 66 screens.** fe_real.txt has 63; a 67th (a "Texture and Model Packs" screen, then a
  one-line dummy screen) crashes the parse at frame ~92 with a call through null in the DollyScript reader, while
  4 KB of comments or ten extra named ints don't.
- **And almost no heap.** A No/Yes confirm screen for Quit (and a pause-menu "Quit to Desktop" with its screen) worked
  in free runs, but play3 then hung at frame ~26,500: the menus are parsed again at 26,654, and the extra screen left a
  later level load out of game heap (`sample` on the hung app: 0x00266e00 -> the out-of-memory spin 0x0008d320). The
  control at the same base passes. Bisected with HULK_-prefixed knobs (the module's environment takes only HULK_*
  variables: a first round of WQ_* knobs silently did nothing), on clean bases (a `--workspace` older than the
  checkout's HEAD ships its files over the newer HEAD): the overlay text, not the code, and only the screen. So Quit
  has no confirm, and a row past a screen's nine places now gets no named int.
- **Video Options had outgrown its nine locators** (12 rows at 62e7c5c90: Anti-Aliasing, Far Field, Lighting and
  Dynamic Lights never showed). Texture Pack moved to Gameplay Options, which now ends with the packs' status, and
  Anti-Aliasing shows again; Far Field, Lighting and Dynamic Lights still have no item.
- **Status text at run time.** A TextLabel's text setter (0x000f8500) takes a string id, and a name that is no id is
  shown as written: host text can go into a label without touching the string table. It runs only when the screen
  opens, so runs that never open it keep the same game memory whatever packs are installed.
- The story menu's cursor ignored d-pad presses in its first ~half second after opening; scripted menu runs need
  generous gaps.
