#!/usr/bin/env python3
"""LoRA SFT of a local Qwen on the farm dataset, via unsloth (MLX or CUDA).

Takes build/farm/dataset/hulk-sft-v1.jsonl (see tools/export_dataset.py), plus
--extra files in the same schema (hulk-matches-v1.jsonl, external-halo.jsonl), and
trains one row per assistant turn: prompt = template(system, user, prior turns,
generation prompt), completion = what the template renders for that assistant
turn (<think>…</think> + submit_cpp tool call, in the model's own tool-call
syntax). Prompt tokens are masked out of the loss. With --turns final (default)
only the matching submission is a target; failed attempts and their diffs stay
in its prompt, so the model learns to fix from feedback without imitating misses.

Runs on the training box. On Apple Silicon use Unsloth Studio's env (MLX backend):
  ~/.unsloth/studio/unsloth_studio/bin/python tools/train_sft_unsloth.py \
      --model unsloth/Qwen3.6-35B-A3B --precision bf16
Output: build/dataset/ulk-1-lora/ (adapter) + optional merged GGUF (--export-gguf).
"""
import argparse
import json
import os
import random

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DEFAULT_DATA = os.path.join(ROOT, "build/farm/dataset/hulk-sft-v1.jsonl")
DEFAULT_EXTRA = [os.path.join(ROOT, "build/farm/dataset", f) for f in ("hulk-matches-v1.jsonl", "hulk-equiv-v1.jsonl", "external-halo.jsonl")]
DEFAULT_OUT = os.path.join(ROOT, "build/dataset/ulk-1-lora")

# submit_cpp schema, byte-matched to farm/src/farm.ts toolParameters.
SUBMIT_CPP = {
    "type": "function",
    "function": {
        "name": "submit_cpp",
        "description": "Compile a complete C++ translation unit with MSVC 7.1 and diff the best-matching function against the target.",
        "parameters": {
            "type": "object",
            "properties": {"code": {"type": "string", "description": "Complete .cpp translation unit"}},
            "required": ["code"],
        },
    },
}


def to_template(m):
    """Dataset message -> chat-template message (Qwen reads reasoning_content)."""
    out = {"role": m["role"], "content": m.get("content") or ""}
    if m.get("reasoning"):
        out["reasoning_content"] = m["reasoning"]
    if m.get("tool_calls"):
        out["tool_calls"] = [
            {"type": "function", "function": {
                "name": c["name"],
                "arguments": c["arguments"] if isinstance(c["arguments"], dict) else json.loads(c["arguments"]),
            }}
            for c in m["tool_calls"]
        ]
    return out


def render(tok, msgs, gen_prompt):
    return tok.apply_chat_template(msgs, tools=[SUBMIT_CPP], tokenize=False, add_generation_prompt=gen_prompt)


def pairs_for_conversation(ex, tok):
    """(prompt, completion) text per assistant turn, both rendered by the model's template.

    The completion is the template's rendering of history+turn minus its rendering of
    history+generation prompt, so think tags and tool-call syntax match serving exactly.
    """
    msgs = [to_template(m) for m in ex["messages"]]
    out = []
    for i, m in enumerate(msgs):
        if m["role"] != "assistant":
            continue
        prompt = render(tok, msgs[:i], True)
        full = render(tok, msgs[: i + 1], False)
        if not full.startswith(prompt):
            raise SystemExit(f"{ex['id']} turn {i}: template is not prefix-stable; can't split prompt/completion")
        out.append((prompt, full[len(prompt):].rstrip("\n")))
    return out


def load_pairs(paths, tok, split, thinking, turns):
    pairs, n_conv = [], 0
    for path in paths:
        with open(path) as f:
            for line in f:
                ex = json.loads(line)
                if ex["split"] != split:
                    continue
                if thinking == "with" and not ex["has_thinking"]:
                    continue
                if thinking == "without":
                    for m in ex["messages"]:
                        m.pop("reasoning", None)
                n_conv += 1
                got = pairs_for_conversation(ex, tok)
                pairs.extend(got[-1:] if turns == "final" else got)
    return pairs, n_conv


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--data", default=DEFAULT_DATA)
    ap.add_argument("--extra", nargs="*", default=[p for p in DEFAULT_EXTRA if os.path.exists(p)],
                    help="more datasets in the same schema (train/val/test split field honoured)")
    ap.add_argument("--turns", choices=["final", "all"], default="final",
                    help="final: train only on the matching submission; all: every attempt (ulk-1)")
    ap.add_argument("--model", default="unsloth/Qwen3.6-35B-A3B")
    ap.add_argument("--precision", choices=["bf16", "8bit", "4bit"], default="bf16")
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--epochs", type=float, default=2)
    ap.add_argument("--max-steps", type=int, default=-1, help="override epochs (smoke tests)")
    ap.add_argument("--limit", type=int, default=0, help="train on the first N rows only (smoke tests)")
    ap.add_argument("--lr", type=float, default=1e-4)
    ap.add_argument("--rank", type=int, default=32)
    ap.add_argument("--batch", type=int, default=1)
    ap.add_argument("--accum", type=int, default=16)
    ap.add_argument("--max-seq", type=int, default=8192)
    ap.add_argument("--thinking", choices=["with", "without", "both"], default="both",
                    help="train on reasoning tokens: with-thinking examples only / strip all reasoning / keep as-is")
    ap.add_argument("--save-steps", type=int, default=200)
    # MoE: LoRA on attention (full + linear/GatedDeltaNet) and the shared expert only.
    # Leaf "gate_proj" etc. would also wrap every routed expert (switch_mlp): 2.5B
    # trainable params on Qwen3.6-35B-A3B, 113 GB peak, ~10 tok/s.
    ap.add_argument("--targets", default="q_proj,k_proj,v_proj,o_proj,in_proj_qkv,in_proj_z,out_proj,shared_expert",
                    help="comma-separated LoRA targets (leaf or parent module names); "
                         "dense models: q_proj,k_proj,v_proj,o_proj,gate_proj,up_proj,down_proj")
    ap.add_argument("--export-gguf", default="", help="also write a merged GGUF of this quant type, e.g. q8_0")
    args = ap.parse_args()

    import unsloth
    from unsloth import FastLanguageModel

    mlx = getattr(unsloth, "DEVICE_TYPE", "") == "mlx"
    model, tok = FastLanguageModel.from_pretrained(
        args.model,
        max_seq_length=args.max_seq,
        load_in_4bit=args.precision == "4bit",
        load_in_8bit=args.precision == "8bit",
        load_in_16bit=args.precision == "bf16",
        **({"text_only": True} if mlx else {}),
    )
    model = FastLanguageModel.get_peft_model(
        model,
        r=args.rank,
        lora_alpha=args.rank * 2,
        lora_dropout=0,
        target_modules=args.targets.split(","),
        use_gradient_checkpointing="mlx" if mlx else "unsloth",
        random_state=3407,
        max_seq_length=args.max_seq,
    )

    files = [args.data] + list(args.extra)
    print("data:", ", ".join(os.path.basename(f) for f in files))
    train, n_conv = load_pairs(files, tok, "train", args.thinking, args.turns)
    # val stays Hulk-transcript-only so loss is comparable with ulk-1
    val, _ = load_pairs([args.data], tok, "val", args.thinking, args.turns)
    random.Random(3407).shuffle(train)
    # Drop rather than truncate: truncation would cut the tool call mid-way.
    fits = lambda rows: [r for r in rows if len(tok(r[0] + r[1], add_special_tokens=False)["input_ids"]) <= args.max_seq]
    n_all = len(train)
    train, val = fits(train), fits(val)
    print(f"train rows: {len(train)} from {n_conv} conversations ({n_all - len(train)} over --max-seq dropped); val rows: {len(val)}")
    if args.limit:
        train = train[: args.limit]
    p, c = train[0]
    print("---- sample completion ----\n" + c[-600:] + "\n---------------------------")

    from datasets import Dataset
    to_ds = lambda rows: Dataset.from_list([{"prompt": p, "completion": c} for p, c in rows])

    if mlx:
        from unsloth_zoo.mlx.trainer import MLXTrainer, MLXTrainingConfig
        cfg = MLXTrainingConfig(
            per_device_train_batch_size=args.batch,
            gradient_accumulation_steps=args.accum,
            num_train_epochs=int(args.epochs) if args.max_steps < 0 else -1,
            max_steps=args.max_steps,
            learning_rate=args.lr,
            lr_scheduler_type="cosine",
            warmup_ratio=0.03,
            warmup_steps=0,
            logging_steps=1,
            output_dir=args.out,
            save_steps=args.save_steps,
            eval_steps=args.save_steps,
            max_seq_length=args.max_seq,
            completion_only_loss=True,
            append_eos=False,  # the template already closes the turn
            seed=3407,
        )
        trainer = MLXTrainer(model=model, tokenizer=tok, train_dataset=to_ds(train),
                             eval_dataset=to_ds(val[:64]) if val else None, args=cfg)
    else:
        from trl import SFTConfig, SFTTrainer
        trainer = SFTTrainer(
            model=model, processing_class=tok, train_dataset=to_ds(train),
            args=SFTConfig(
                output_dir=args.out, per_device_train_batch_size=args.batch,
                gradient_accumulation_steps=args.accum, num_train_epochs=args.epochs,
                max_steps=args.max_steps, learning_rate=args.lr, lr_scheduler_type="cosine",
                warmup_ratio=0.03, logging_steps=1, save_steps=args.save_steps, bf16=True,
                optim="adamw_8bit", max_length=args.max_seq, completion_only_loss=True,
                report_to=[], seed=3407,
            ),
        )
    trainer.train()
    model.save_pretrained(args.out, tok, save_method="lora") if mlx else model.save_pretrained(args.out)
    tok.save_pretrained(args.out)
    print(f"adapter saved to {args.out}")

    if args.export_gguf:
        model.save_pretrained_gguf(args.out + "-gguf", tok, quantization_method=args.export_gguf)
        print(f"merged GGUF saved to {args.out}-gguf")


if __name__ == "__main__":
    main()
