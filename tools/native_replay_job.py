#!/usr/bin/env python3
"""Alias of tools/wine_replay_job.py (renamed: the 32-bit clang image run under Wine is the "Wine build").
Kept so old commands and imports (python tools/native_replay_job.py, import native_replay_job) keep working."""
import os, sys, importlib, runpy
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
if __name__ == "__main__":
    runpy.run_module("wine_replay_job", run_name="__main__", alter_sys=True)
else:
    sys.modules[__name__] = importlib.import_module("wine_replay_job")
