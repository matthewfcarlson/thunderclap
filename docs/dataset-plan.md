# Fine-tune dataset: context + thinking traces from matched functions

Goal: turn the farm's successful runs into an SFT dataset (later RL), fine-tune
Qwen3.8-Flash-Next locally, and serve it as a farm tier — closing the data
flywheel: matches → dataset → stronger local model → more matches.

## What we already have

| Source | What it holds | Notes |
|---|---|---|
| `build/farm/farm.sqlite` | Full pi-durable transcripts: packet, thinking, `submit_cpp` code, diff feedback | **4,424 conversations ended `match`; 3,158 (71%) contain thinking blocks.** 31,772 entries in matched conversations. |
| `build/farm/work/<tag>/<addr>/` | Raw per-attempt files: `t0_prompt.txt`, `t0_a1.cpp`… | Fallback for pre-farm matches without transcripts |
| `matches/<addr>.cpp` | Verified winner per function (git) | Ground truth for cross-checks |
| `build/farm/results.jsonl` | Ledger: model, tier, attempts, cost, tokens | Joins + model metadata |
| `build/farm/difficulty.jsonl` | Difficulty score per function | Stratification / held-out split |

Transcript structure (verified):
- `pi.system` — the static system prompt (byte-stable, also in `farm/src/prompt.ts`)
- `pi.user` — the packet (asm + Ghidra hint + class/vtable context)
- `pi.assistant` — `thinking` text + `toolCall submit_cpp {code}` + usage
- `pi.tool-result` — the compact diff report the next attempt sees

Job state (`status`, `attempts`, `history` of score+note) is rebuilt from
`document_revisions` (base row + `["s",…]`/`["a",…]` deltas).

**Urgency:** the db prunes old conversations (entry ids reach 223k, only 8,829
conversations remain). Export before more history disappears.

## Plan

### 1. Snapshot the db (do first)
```
sqlite3 build/farm/farm.sqlite ".backup build/farm/dataset/farm-snapshot.sqlite"
```
Never query the live db directly (locks block the farm). All tooling reads the
snapshot; re-snapshot after each farm session.

### 2. Exporter — `tools/export_dataset.py`
Reads the snapshot, emits `build/farm/dataset/raw/<addr>.json` (one file per
conversation, verbatim) and `dataset/hulk-sft-v1.jsonl` (curated, chat format):

```json
{"id":"0x00213600:t0:a3","addr":"0x00213600","size":53,"tier":0,
 "model":"z-ai/glm-5.3-flash","attempt":3,"outcome":"match","score":1.0,
 "messages":[
  {"role":"system","content":"<system prompt>"},
  {"role":"user","content":"<packet>"},
  {"role":"assistant","content":"<thinking text>","tool_calls":[
     {"name":"submit_cpp","arguments":{"code":"<cpp>"}}]},
  {"role":"tool","content":"<diff report>"}]}
```
- Verify final code is byte-identical to `matches/<addr>.cpp` (or `score==1` in the delta); drop mismatches.
- Strip `thinkingSignature` and model-specific wrappers; keep thinking text verbatim.
- Multi-turn: keep the attempt→diff→attempt chain up to the winning turn (cap 6 turns) so the model learns to read diffs, not just answer cold.
- Filters: dedupe identical packets (trivial `ret` stubs dominate small functions); drop any code hitting the FORBIDDEN asm/pragma pattern (compare.py already rejects it, but assert at export).

### 3. Splits and balance
- Split by **function**, not attempt, into train/val/test 96/2/2.
- Stratify by size and difficulty so the model isn't only taught tiny functions.
- Track a "no-thinking" subset separately (models with thinking off); decide per-run whether to train without reasoning or distill reasoning later.

### 4. Training (Qwen3.8-Flash-Next)
- **Format:** Qwen3 chat template with reasoning enabled — thinking renders as `<think>…</think>` before the tool call. Mask loss to assistant tokens only.
- **LoRA** first (r=32, α=64, lr 1e-4, 2–3 epochs, seq 8k, packing on) on an Apple Silicon box (MLX/Unsloth); full FT only if LoRA plateaus.
- **Eval:** match-rate on held-out packets via the farm itself — `farm/endpoints.json` already supports `<endpoint>/<model>` tiers, so the fine-tuned model is served by LM Studio/llama.cpp and run A/B against the current tier on the same queue.
- Naming: `ulk-1` (v1), snapshot + LoRA adapter versioned together.

### 5. Beyond SFT
RL (GRPO) is a natural second step: reward is exactly verifiable (compare.py
diff/score), prompts are cheap, and the farm is already the harness.

## Action items
1. Snapshot + `mkdir build/farm/dataset` (URGENT — pruning risk)
2. `tools/export_dataset.py` + counts report (matched w/ thinking, token histogram)
3. Cross-check winners vs `matches/`
4. Train LoRA v1, A/B via a held-out queue
