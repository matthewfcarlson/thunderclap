#!/usr/bin/env python3
"""Alias of tools/equiv_wine_sample.py (renamed: the 32-bit Wine build)."""
import os, sys, importlib, runpy
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
if __name__ == "__main__":
    runpy.run_module("equiv_wine_sample", run_name="__main__", alter_sys=True)
else:
    sys.modules[__name__] = importlib.import_module("equiv_wine_sample")
