#!/usr/bin/env python3
"""Alias of tools/wine_gfx.py (renamed: the 32-bit clang image run under Wine is the "Wine build").
Kept so old commands and imports (python tools/native_gfx.py, import native_gfx) keep working."""
import os, sys, importlib, runpy
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
if __name__ == "__main__":
    runpy.run_module("wine_gfx", run_name="__main__", alter_sys=True)
else:
    sys.modules[__name__] = importlib.import_module("wine_gfx")
