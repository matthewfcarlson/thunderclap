#!/usr/bin/env python3
"""Merge a train_sft_unsloth.py LoRA into its base and write quantized MLX models.

  ~/.unsloth/studio/unsloth_studio/bin/python tools/export_merged.py \
      ~/ulk/ulk-1 --bits 8 4
Writes <adapter>-bf16/ (merged), then <adapter>-mlx-<N>bit/ per --bits, ready for
LM Studio / oMLX. --keep-bf16 keeps the 67 GB merged copy (needed for GGUF).
"""
import argparse
import os
import shutil
import subprocess
import sys


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("adapter", help="adapter dir (has adapter_config.json)")
    ap.add_argument("--bits", type=int, nargs="+", default=[8, 4])
    ap.add_argument("--group-size", type=int, default=64)
    ap.add_argument("--max-seq", type=int, default=8192)
    ap.add_argument("--keep-bf16", action="store_true")
    args = ap.parse_args()

    adapter = os.path.abspath(os.path.expanduser(args.adapter)).rstrip("/")
    merged = adapter + "-bf16"

    if not os.path.exists(os.path.join(merged, "config.json")):
        from unsloth import FastLanguageModel

        model, tok = FastLanguageModel.from_pretrained(
            adapter, max_seq_length=args.max_seq, load_in_4bit=False, load_in_16bit=True, text_only=True
        )
        model.save_pretrained_merged(merged, tok, save_method="merged_16bit")
        del model
        print(f"merged bf16 -> {merged}", flush=True)

    for bits in args.bits:
        out = f"{adapter}-mlx-{bits}bit"
        if os.path.exists(out):
            shutil.rmtree(out)
        subprocess.run(
            [sys.executable, "-m", "mlx_vlm.convert", "--hf-path", merged, "--mlx-path", out,
             "-q", "--q-bits", str(bits), "--q-group-size", str(args.group_size)],
            check=True,
        )
        print(f"{bits}-bit -> {out}", flush=True)

    if not args.keep_bf16:
        shutil.rmtree(merged)


if __name__ == "__main__":
    main()
