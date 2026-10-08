# 08: Farm strategies for large functions

## Goal
Raise the match rate for functions over 96 bytes, where GPT-6 Luna matches ~0–8% today (see `docs/journal.md`, "Large functions"), without blowing the budget. Design and *offline-evaluate* strategies; the farm owner integrates them.

## Context
- Farm: `farm/src/farm.ts` (pi-durable; one `submit_cpp` tool; tiers in `farm/*.json`), prompt in `farm/src/prompt.ts`, packets from `tools/packet.py`, diff and score from `tools/compare.py` (LCS-aligned; tags `!!`/`--`/`++`).
- Benchmarks: `build/farm/bench/large30.txt` (30 functions, 97–1500 B) with results in `build/farm/bench/large-luna*.jsonl`. Every attempt's code is in `build/farm/work/<tag>/<addr>/`.
- **Don't run the main farm or touch `build/farm/farm.sqlite`** (the sweep is using it). Use `farm/run.sh --bench <name> …`, which has its own DB and ledger, and keep spend under ~$2 per experiment. Spend is visible in `build/farm/bench/<name>.jsonl`.

## Ideas to evaluate
1. **Similar-function retrieval:** find already-matched functions with similar opcode sequences (n-gram or edit distance, like coddog) and include 1–3 of their verified TUs in the packet. Large functions often inline small matched helpers.
2. **Staged matching:** ask for the prologue and the first basic blocks, score on the aligned prefix, then extend. Variant: give the model the function's basic-block structure explicitly.
3. **Better hints:** a cleaned-up Ghidra decompile (types from RTTI, called functions renamed to matched names), plus the expected stack frame size and saved registers from the prologue.
4. **Stronger tiers:** Claude Sonnet 5.5 (~$2/$10 per M tokens) before GPT-6 Astra ($10/$50). Measure $/match on large30.
5. **More attempts, cheaply:** free local models (the user's Macs; see `farm/endpoints.json` in `docs/farm.md`) with 15–30 attempts.

## Deliverables
- For each idea tried: match rate, average best score and $/match on `large30` vs the Luna baseline, written up in `docs/journal.md`.
- Implementation in `tools/packet.py` or `farm/src/prompt.ts` behind a flag, in a branch/PR, ready for the farm owner to merge.

## Done when
- At least two strategies are measured, and a recommendation with numbers says what the large-function sweep should use.
