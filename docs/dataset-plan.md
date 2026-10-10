# Model flywheel: dataset, SFT, RL

Goal: turn the farm's output into a fine-tuning corpus, train Qwen3.8-Flash-Next
locally, and serve it as a farm tier — closing the loop:
matches → dataset → stronger local model → more matches → dataset.

## What we already have

| Source | What it holds | Notes |
|---|---|---|
| `build/farm/farm-snapshot.sqlite` | Full pi-durable transcripts: packet, thinking, `submit_cpp` code, diff feedback | Snapshot taken before pruning loses more; **4,424 matched conversations** |
| `build/farm/dataset/hulk-sft-v1.jsonl` | 4,399 curated chat examples | Multi-turn (attempt→diff→…→match), 1,428 with plaintext thinking |
| `build/farm/dataset/grpo-prompts-v1.jsonl` | 9,136 prompts (4,737 unmatched functions) | Reward surface for RL |
| `build/farm/dataset/raw/` | Verbatim per-conversation exports | 76 MB, re-exportable from the snapshot |
| `matches/<addr>.cpp` | Verified winner per function | Farm's compare verdict is the proof; matches/ is often reformatted/hand-curated (4,111 whitespace-only, 82 exact, 201 curated variants) |
| `tools/export_dataset.py` | Snapshot → dataset exporter | Re-run after every farm session |
| `tools/train_sft_unsloth.py` | LoRA SFT script (unsloth) | Written, untested — needs the training box |

Data facts: p50 example ≈ 960 tokens, p95 ≈ 2.7k, ~5.5M tokens total. Sizes p50
38 B / max 1,502 B. Splits by function: 4,238 train / 68 val / 93 test.
Thinking caveat: luna's reasoning is **encrypted** (`reasoning.encrypted`) —
only plaintext-thinking models (glm-5.3-flash et al.) contribute reasoning
tokens. `--thinking both|with|without` controls what we train on.

## Corpus sources

### 1. Our farm (primary)
In-repo, verified, perfectly matched to serving format. ~4.4k conversations now,
grows with every farm run. Small-function skew is a limitation.

### 2. External decomps (halo — DONE, 1,522 rows)
External repos give **volume and diversity**: MSVC x86 asm→C idioms are a
general skill and our corpus is single-game.

- **punpckhdq/halo** (CC0! — public domain, no license risk): the winner, and
  it needs **no external binary**. `tools/import_external_trainingdata.py halo`
  compiles their real decompiled C with *our* cl 13.10 (`/O2 /Oy- /MT`, PCH
  force-included, tiny XDK-header shims under `build/external/halo-compat/`),
  disassembles the objects with capstone, and emits rows in our packet framing
  (symbolized calls/data from obj relocs; types/constants/prototypes as
  context) → self-contained C TU. Self-verifying: the asm is *our compile* of
  the C, so every pair is consistent by construction.
  - Result: **1,522 unique rows** (`external-halo.jsonl`), p50 ≈ 1k tok,
    p95 ≈ 4k tok. Fails: 122 no-section files (vendored libtiff), 60 compile
    errors (D3D/XDK types), 85 unextracted defs, 16 too-large — all iterable.
  - Pseudo-addresses in packet headers (the number carries no meaning).
- **decomp.me**: API is Cloudflare-challenge-blocked; deprioritized.
- **Windows MSVC decomps** (LEGO Island et al.): same recipe as halo (compile
  their C, disassemble, render) — a future `import` subcommand, per repo.
- **Not useful as code**: Xbox 360 PPC (dc3-decomp) — wrong ISA.

Guards kept: our-compile verification, our packet framing, style anchoring via
training order (external-first, our-data-last), no leaked source anywhere.

### 3. Rejection sampling from our own model (later)
Once ulk-1 serves: sample k completions per unmatched prompt, keep what
compare.py scores, SFT on the survivors (RAFT). No RL infra needed; works on
the Macs with llama.cpp.

## Phases

### Phase A — SFT v1 (ready to run)
- Export: done (4,399 examples; re-export after farm sessions).
- Train: `tools/train_sft_unsloth.py` — LoRA r=32, lr 1e-4, 2 epochs, seq 8k,
  loss on assistant tokens only (`defs…defs` + Hermes tool call). One row per
  assistant turn so diff-feedback turns are learned too.
- Output: `build/dataset/ulk-1-lora/` + optional q4_k_m GGUF for LM Studio.
- Eval: held-out test split via the farm itself (A/B against the current tier
  on the same queue, `farm/endpoints.json` endpoint `mac2/...ulk-1`).

### Phase B — External corpus (halo done)
1. ~~halo import~~ → `external-halo.jsonl`, 1,522 rows.
2. Sweep decomp.dev + Recompendium for more MSVC x86 matching targets (LEGO
   Island next; each is a new `import` subcommand of the same recipe).
3. Train v1 with external+farm data merged (`--data` handles ordering).

### Phase C — RL (GRPO with unsloth)
Reward is perfectly verifiable: `tools/compare.py src addr --json` → `score`
(matched/total instructions) + bonus for `status==match`, minus formatting/
forbidden-pattern penalties. Prompts: `grpo-prompts-v1.jsonl`.
- Needs a CUDA box (unsloth GRPO + vLLM generation) with a small reward server
  that shells out to compare.py — the toolchain runs under wibo already.
- Start from the Phase-A/B LoRA; keep KL modest so it doesn't drift from
  compiling reality.
- If no CUDA budget: RAFT (above) locally instead — 80% of the value, 5% of the
  infra.

### Phase D — Flywheel
ulk-N serves as a cheap tier (`tiers-local.json`) → unmatched queue → new
transcripts → re-export → retrain. Local tier also unblocks night runs without
API spend.

## Next actions
1. Run `tools/train_sft_unsloth.py` on the training box (smoke: `--limit` a few
   hundred rows, smaller `--max-seq`) → ulk-1.
2. Farm A/B eval of ulk-1 on a held-out queue.
3. More external repos (LEGO Island recipe) + halo fail-cause cleanup.
4. GRPO reward server + unsloth GRPO run (or RAFT if local-only).
