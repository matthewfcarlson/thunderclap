#!/usr/bin/env python3
"""Alias of tools/wine_ffmpeg.py (renamed: the 32-bit clang image run under Wine is the "Wine build").
Kept so old commands and imports (python tools/native_ffmpeg.py, import native_ffmpeg) keep working."""
import os, sys, importlib, runpy
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
if __name__ == "__main__":
    runpy.run_module("wine_ffmpeg", run_name="__main__", alter_sys=True)
else:
    sys.modules[__name__] = importlib.import_module("wine_ffmpeg")
