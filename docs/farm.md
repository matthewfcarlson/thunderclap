# Matching farm

Cheap models do bulk matching in parallel. Claude's effort goes to tooling and the hard cases.

```
tools/packet.py queue            # build/farm/queue.txt: game functions ≤96 bytes, smallest first (~18k)
ExportDecomp.java <queue> <dir>  # Ghidra C hints → build/farm/ghidra_c/<addr>.c (optional, batch)
tools/packet.py build --queue …  # build/farm/packets/<addr>.txt
farm/run.sh --limit 200 --concurrency 8
tools/farm_stats.py              # success and cost per tier
```

Setup: `cd farm && npm install`. The OpenRouter key comes from pi's credential store (`pi auth print-api-key --provider openrouter`) at launch and never sits in a file.

## Design: why it's cheap

- **Everything is precomputed** (`tools/packet.py`, no LLM tokens):
  - target asm with symbolized calls, and data refs annotated as strings, floats or vftables;
  - the owning class and its vtable from RTTI, with the target slot marked;
  - Ghidra's decompile as a hint.

  A worker gets one message and has no read/bash/edit tools to explore with.
- **One tool, `submit_cpp`**: compiles with cl 13.10 under wibo and replies with a *compact* diff (mismatches ±1 line of context). On a match it writes `matches/<addr>.cpp` and returns `control: terminate`, so the run ends without another model call.
- **Static system prompt** (`farm/src/prompt.ts`) holding the MSVC 7.1 idioms and a worked example. It's byte-stable so providers can cache the prefix.
- **Tiered escalation** (`farm/tiers.json`): GLM-5.3-flash → DeepSeek-v4.1-flash → Claude Haiku 5.5, 5 submissions each. A higher tier starts fresh with the packet plus only the *best* previous attempt and its diff, not the whole transcript.

## Design: why it's durable and parallel

- Runs on [pi-durable](https://github.com/earendil-works/pi/tree/main/packages/durable) over SQLite (`build/farm/farm.sqlite`). Every model turn and tool call is checkpointed. Kill the process and rerun the same command: the session index (`hulk.index` doc) maps `addr:tier` to its conversation, `requestId` makes the submission exactly-once, and `harness.resume()` continues unfinished runs.
- Per-conversation `hulk.job` document: attempts, best score, best code and diff, status.
- N concurrent conversations in one process (`--concurrency`). `compare.py` builds in temp dirs, so workers never collide.
- Ledger: `build/farm/results.jsonl` (addr, tier, model, status, attempts, cost, tokens, time). Matched or fully tried functions are skipped on the next run.

## Outputs and caveats

- `matches/<addr>.cpp` holds one self-contained TU per function, with invented names and ad-hoc class stubs. These are **verified codegen**, not final source. Consolidation into real headers and files comes with the split/objdiff setup.
- The worker's code is untrusted model output compiled by `cl.exe` under wibo. It is never executed.
