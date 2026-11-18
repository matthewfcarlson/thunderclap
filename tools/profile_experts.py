#!/usr/bin/env python3
"""Profile MoE expert routing on the farm dataset (input for domain expert pruning).

Teacher-forces each conversation (prompt + every assistant turn) through an MLX
Qwen3-Next model and records, per layer and expert:
  - routed-token counts, split into prompt tokens (asm/packet) and assistant tokens
  - summed router probability
  - REAP saliency: summed router weight * ||expert output||
Writes an .npz and prints how many experts per layer cover 90/99/99.9% of routing.

Runs on the training box with mlx-lm (Unsloth Studio's env has it):
  ~/.unsloth/studio/unsloth_studio/bin/python tools/profile_experts.py \
      --model lmstudio-community/Qwen3-Coder-Next-MLX-4bit --limit 1500
"""
import argparse
import json
import os
import random
import sys
import time

import mlx.core as mx
import numpy as np

sys.path.insert(0, os.path.dirname(__file__))
from train_sft_unsloth import DEFAULT_DATA, ROOT, pairs_for_conversation  # noqa: E402

CHUNK = 2048


class Stats:
    def __init__(self, n_layers, n_experts):
        z = lambda: mx.zeros((n_layers, n_experts), dtype=mx.float32)
        self.count_prompt, self.count_asst, self.gate, self.reap = z(), z(), z(), z()
        self.boundary = 0  # tokens before this absolute position are prompt
        self.offset = 0    # absolute position of the current chunk's first token


def patch_moe(model, stats):
    from mlx_lm.models import qwen3_next

    blocks = [l.mlp for l in model.layers if isinstance(l.mlp, qwen3_next.Qwen3NextSparseMoeBlock)]
    for i, b in enumerate(blocks):
        b._lid = i

    def call(self, x):
        gates = mx.softmax(self.gate(x), axis=-1, precise=True)
        k = self.top_k
        inds = mx.argpartition(gates, kth=-k, axis=-1)[..., -k:]
        scores = mx.take_along_axis(gates, inds, axis=-1)
        if self.norm_topk_prob:
            scores = scores / scores.sum(axis=-1, keepdims=True)
        y = self.switch_mlp(x, inds)  # (B, L, k, D)

        # Record routing (batch size 1).
        L = x.shape[1]
        pos = mx.arange(L) + stats.offset
        is_prompt = (pos < stats.boundary).astype(mx.float32)[:, None]  # (L, 1)
        fi, fs = inds[0], scores[0]
        norms = mx.linalg.norm(y[0].astype(mx.float32), axis=-1)  # (L, k)
        lid = self._lid
        row = lambda acc, v: acc[lid].at[fi.reshape(-1)].add(v.reshape(-1))
        stats.count_prompt[lid] = row(stats.count_prompt, mx.broadcast_to(is_prompt, fi.shape))
        stats.count_asst[lid] = row(stats.count_asst, mx.broadcast_to(1 - is_prompt, fi.shape))
        stats.gate[lid] = row(stats.gate, fs.astype(mx.float32))
        stats.reap[lid] = row(stats.reap, fs.astype(mx.float32) * norms)

        y = (y * scores[..., None]).sum(axis=-2)
        shared = mx.sigmoid(self.shared_expert_gate(x)) * self.shared_expert(x)
        return y + shared

    qwen3_next.Qwen3NextSparseMoeBlock.__call__ = call
    return len(blocks), blocks[0].num_experts


def coverage(counts, q):
    """Experts per layer needed to cover fraction q of routed tokens."""
    s = np.sort(counts, axis=1)[:, ::-1]
    c = np.cumsum(s, axis=1) / np.maximum(s.sum(axis=1, keepdims=True), 1)
    return (c < q).sum(axis=1) + 1


def save(args, stats, n_tok, n_prompt, n_conv):
    out = {k: np.array(getattr(stats, k)) for k in ("count_prompt", "count_asst", "gate", "reap")}
    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    np.savez(args.out, model=args.model, tokens=n_tok, prompt_tokens=n_prompt, conversations=n_conv, **out)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--model", default="lmstudio-community/Qwen3-Coder-Next-MLX-4bit")
    ap.add_argument("--data", default=DEFAULT_DATA)
    ap.add_argument("--limit", type=int, default=1500, help="conversations to profile (0 = all train)")
    ap.add_argument("--max-seq", type=int, default=8192)
    ap.add_argument("--out", default=os.path.join(ROOT, "build/dataset/expert-profile.npz"))
    args = ap.parse_args()

    from mlx_lm import load
    from mlx_lm.models.cache import make_prompt_cache

    model, tok = load(args.model)
    tok = getattr(tok, "_tokenizer", tok)  # HF tokenizer for apply_chat_template

    exs = [json.loads(l) for l in open(args.data)]
    exs = [e for e in exs if e["split"] == "train"]
    random.Random(3407).shuffle(exs)
    if args.limit:
        exs = exs[: args.limit]

    stats = Stats(0, 0)
    n_layers, n_experts = patch_moe(model, stats)
    stats.__init__(n_layers, n_experts)  # sized once the MoE blocks are known
    print(f"{n_layers} MoE layers x {n_experts} experts; profiling {len(exs)} conversations", flush=True)

    n_tok = n_prompt = n_skip = 0
    t0 = time.time()
    for i, ex in enumerate(exs):
        pairs = pairs_for_conversation(ex, tok)
        if not pairs:
            continue
        # Last turn's prompt already contains every earlier turn: one pass covers the whole
        # conversation. Earlier assistant turns count as "prompt" here; the first-turn prompt
        # length marks where the packet ends and model-written text begins.
        first_prompt, _ = pairs[0]
        prompt, completion = pairs[-1]
        ids = tok(prompt + completion, add_special_tokens=False)["input_ids"]
        if len(ids) > args.max_seq:
            n_skip += 1
            continue
        stats.boundary = len(tok(first_prompt, add_special_tokens=False)["input_ids"])
        cache = make_prompt_cache(model)
        for s in range(0, len(ids), CHUNK):
            stats.offset = s
            model(mx.array(ids[s : s + CHUNK])[None], cache=cache)
            mx.eval(stats.count_prompt, stats.count_asst, stats.gate, stats.reap)
        n_tok += len(ids)
        n_prompt += stats.boundary
        if (i + 1) % 50 == 0:
            dt = time.time() - t0
            print(f"{i + 1}/{len(exs)} convs, {n_tok / 1e6:.2f}M tokens, {n_tok / dt:.0f} tok/s", flush=True)
        if (i + 1) % 250 == 0:
            save(args, stats, n_tok, n_prompt, i + 1)  # partial results survive an interrupted run

    out = save(args, stats, n_tok, n_prompt, len(exs))
    print(f"saved {args.out}: {n_tok} tokens ({n_prompt} packet), {n_skip} conversations over --max-seq skipped")

    total = out["count_prompt"] + out["count_asst"]
    print(f"\nexperts per layer (of {n_experts}) covering routed tokens: min / median / max over {n_layers} layers")
    for name, c in (("all", total), ("packet", out["count_prompt"]), ("model-written", out["count_asst"]), ("REAP", out["reap"])):
        cells = []
        for q in (0.9, 0.99, 0.999):
            v = coverage(c, q)
            cells.append(f"{q:.1%}: {v.min():3d}/{int(np.median(v)):3d}/{v.max():3d}")
        never = int((c == 0).sum())
        print(f"  {name:13s} " + "   ".join(cells) + f"   never used: {never}/{c.size}")


if __name__ == "__main__":
    main()
