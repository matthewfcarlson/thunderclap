#!/usr/bin/env python3
"""LoRA SFT of Qwen3.8-Flash-Next on the farm dataset, via unsloth.

Takes build/farm/dataset/hulk-sft-v1.jsonl (see tools/export_dataset.py) and
trains one row per assistant turn: prompt = template(system, user, prior turns,
generation prompt), completion = <think>…</think> + <tool_call>submit_cpp tool call.
Prompt tokens are masked out of the loss.

Runs on the training box (Apple Silicon or CUDA with unsloth installed):
  pip install unsloth
  build/venv/bin/python tools/train_sft_unsloth.py \
      --model unsloth/Qwen3.8-Flash-Next --export-gguf
Output: build/dataset/ulk-1-lora/ (adapter) + optional merged GGUF for LM Studio.
"""
import argparse
import json
import os
import re

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DEFAULT_DATA = os.path.join(ROOT, "build/farm/dataset/hulk-sft-v1.jsonl")
DEFAULT_EXTERNAL = os.path.join(ROOT, "build/farm/dataset/external-halo.jsonl")
DEFAULT_OUT = os.path.join(ROOT, "build/dataset/ulk-1-lora")

# Qwen3 renders tool calls Hermes-style; the chat template emits these tags.
OPEN_THINK, CLOSE_THINK = "<think>\n", "\n</think>\n\n"
OPEN_TOOL, CLOSE_TOOL = "<tool_call>\n", "\n</tool_call>"

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


def render_completion(msg):
    """Raw assistant text the model must emit: think block, then Hermes tool call."""
    parts = []
    r = msg.get("reasoning")
    if r:
        parts.append(f"{OPEN_THINK}{r}{CLOSE_THINK}")
    if msg.get("content"):
        parts.append(msg["content"])
    for c in msg.get("tool_calls", []):
        args = c["arguments"] if isinstance(c["arguments"], str) else json.dumps(c["arguments"])
        parts.append(f'{OPEN_TOOL}{{"name": {json.dumps(c["name"])}, "arguments": {args}}}{CLOSE_TOOL}')
    return "\n".join(p for p in parts if p)


def rows_for_conversation(ex, tok, max_seq):
    """One training row per assistant turn of the conversation."""
    msgs = ex["messages"]
    system = [m for m in msgs if m["role"] in ("system", "user")]
    later = []  # already-seen (assistant, tool) suffix turns, rendered as-is
    rows = []
    for m in msgs:
        if m["role"] != "assistant":
            later.append(m)
            continue
        prefix = later or system
        prompt = tok.apply_chat_template(
            prefix, tools=[SUBMIT_CPP], tokenize=False, add_generation_prompt=True
        )
        completion = render_completion(m) + tok.eos_token
        ids = tok(prompt, add_special_tokens=False)
        cids = tok(completion, add_special_tokens=False)
        input_ids = ids["input_ids"] + cids["input_ids"]
        if len(input_ids) > max_seq:
            return []
        labels = [-100] * len(ids["input_ids"]) + cids["input_ids"][:]
        rows.append({"input_ids": input_ids, "labels": labels})
        later.append(m)
    return rows


def collate(batch, pad_id):
    import torch
    n = max(len(b["input_ids"]) for b in batch)
    input_ids, labels, attn = [], [], []
    for b in batch:
        k = n - len(b["input_ids"])
        input_ids.append(b["input_ids"] + [pad_id] * k)
        labels.append(b["labels"] + [-100] * k)
        attn.append([1] * len(b["input_ids"]) + [0] * k)
    return {
        "input_ids": torch.tensor(input_ids),
        "labels": torch.tensor(labels),
        "attention_mask": torch.tensor(attn),
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--data", nargs="+", default=[DEFAULT_DATA, DEFAULT_EXTERNAL],
                    help="JSONL files in training order: external first, ours last (style anchoring)")
    ap.add_argument("--model", default="unsloth/Qwen3.8-Flash-Next")
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--epochs", type=float, default=2)
    ap.add_argument("--lr", type=float, default=1e-4)
    ap.add_argument("--rank", type=int, default=32)
    ap.add_argument("--batch", type=int, default=4)
    ap.add_argument("--accum", type=int, default=8)
    ap.add_argument("--max-seq", type=int, default=8192)
    ap.add_argument("--thinking", choices=["with", "without", "both"], default="both",
                    help="train on reasoning tokens: with plaintext thinking only / strip it / keep both")
    ap.add_argument("--export-gguf", action="store_true", help="also write a merged q4_k_m GGUF for LM Studio")
    args = ap.parse_args()

    from unsloth import FastLanguageModel
    from unsloth.chat_models import UnslothTrainer, UnslothTrainingArguments  # noqa: F401
    from transformers import Trainer

    model, tok = FastLanguageModel.from_pretrained(
        args.model, max_seq_length=args.max_seq, dtype=None, load_in_4bit=True
    )
    model = FastLanguageModel.get_peft_model(
        model,
        r=args.rank,
        lora_alpha=args.rank * 2,
        lora_dropout=0,
        target_modules=["q_proj", "k_proj", "v_proj", "o_proj", "gate_proj", "up_proj", "down_proj"],
        use_gradient_checkpointing="unsloth",
    )

    # Discover the tool-call tags from the tokenizer's own template.
    dummy = tok.apply_chat_template(
        [{"role": "user", "content": "hi"},
         {"role": "assistant", "content": "", "tool_calls": [{"name": "f", "arguments": {"a": 1}}]},
         {"role": "tool", "content": "ok"}],
        tools=[SUBMIT_CPP], tokenize=False, add_generation_prompt=False)
    open_tag = OPEN_TOOL.strip() in dummy
    close_tag = CLOSE_TOOL.strip() in dummy
    if not (open_tag and close_tag):
        raise SystemExit("chat template has no Hermes tool-call tags; adjust the tag constants")

    rows, n_drop = [], 0
    for path in args.data:
        if not os.path.exists(path):
            print(f"warning: {path} missing, skipping")
            continue
        n_file = 0
        with open(path) as f:
            for line in f:
                ex = json.loads(line)
                if "split" in ex and ex["split"] != "train":
                    continue
                if "has_thinking" in ex and args.thinking != "both" and (ex["has_thinking"] == (args.thinking == "without")):
                    continue
                for m in ex["messages"]:
                    if m["role"] == "assistant" and args.thinking == "without":
                        m.pop("reasoning", None)
                got = rows_for_conversation(ex, tok, args.max_seq)
                if not got and ex["messages"]:
                    n_drop += 1
                n_file += len(got)
                rows.extend(got)
        print(f"{os.path.basename(path)}: {n_file} rows")
    print(f"training rows: {len(rows)} (dropped {n_drop} over-long conversations)")

    import torch

    class DS(torch.utils.data.Dataset):
        def __len__(self): return len(rows)
        def __getitem__(self, i): return rows[i]

    trainer = Trainer(
        model=model,
        train_dataset=DS(),
        data_collator=lambda b: collate(b, tok.pad_token_id or tok.eos_token_id),
        args=__import__("transformers").TrainingArguments(
            output_dir=args.out,
            per_device_train_batch_size=args.batch,
            gradient_accumulation_steps=args.accum,
            num_train_epochs=args.epochs,
            learning_rate=args.lr,
            lr_scheduler_type="cosine",
            warmup_ratio=0.03,
            logging_steps=10,
            save_strategy="epoch",
            bf16=True,
            optim="adamw_8bit",
            report_to=[],
            seed=3407,
        ),
    )
    trainer.train()
    model.save_pretrained(args.out)
    tok.save_pretrained(args.out)
    print(f"adapter saved to {args.out}")

    if args.export_gguf:
        model.save_pretrained_gguf(args.out + "-gguf", tok, quantization_method="q4_k_m")
        print(f"merged GGUF saved to {args.out}-gguf (drop into LM Studio, add an endpoint in farm/endpoints.json)")


if __name__ == "__main__":
    main()
