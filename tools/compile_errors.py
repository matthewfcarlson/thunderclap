#!/usr/bin/env python3
"""Mine farm transcripts for compile errors: frequency by MSVC error code, examples, recovery rate.

  tools/compile_errors.py [db ...]     (default: every build/farm/**/*.sqlite)
"""
import collections
import glob
import json
import os
import re
import sqlite3
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
ERR = re.compile(r"error (C\d{4}): (.*)")


def tool_results(db):
    con = sqlite3.connect("file:%s?mode=ro" % db, uri=True)
    for conv, rec in con.execute("select conversation_id, record from entries order by id"):
        r = json.loads(rec)
        if r.get("kind") != "pi.tool-result":
            continue
        m = r.get("model") or []
        msg = m[0] if isinstance(m, list) and m else m
        text = "".join(c.get("text", "") for c in (msg.get("content") or []) if isinstance(c, dict))
        yield conv, text


def main(dbs):
    dbs = dbs or [p for p in glob.glob(os.path.join(ROOT, "build/farm/**/*.sqlite"), recursive=True)]
    codes, examples, attempts, compile_fail = collections.Counter(), {}, 0, 0
    recovered = collections.Counter()  # error code -> next submission in the same conversation compiled
    for db in dbs:
        last = {}
        for conv, text in tool_results(db):
            attempts += 1
            errs = ERR.findall(text)
            if text.startswith("COMPILE_ERROR"):
                compile_fail += 1
            prev = last.get((db, conv))
            if prev and not text.startswith("COMPILE_ERROR"):
                for c in prev:
                    recovered[c] += 1
            seen = set()
            for code, msg in errs:
                if code in seen:
                    continue
                seen.add(code)
                codes[code] += 1
                # normalize identifiers so similar messages group
                examples.setdefault(code, collections.Counter())[re.sub(r"'[^']*'", "'…'", msg)[:110]] += 1
            last[(db, conv)] = seen if text.startswith("COMPILE_ERROR") else set()
    print("submissions %d, compile failures %d (%.1f%%)" % (attempts, compile_fail, 100 * compile_fail / max(attempts, 1)))
    print("%-6s %6s %9s  %s" % ("code", "count", "recovered", "most common message"))
    for code, n in codes.most_common(25):
        msg, _ = examples[code].most_common(1)[0]
        print("%-6s %6d %8.0f%%  %s" % (code, n, 100 * recovered[code] / n, msg))


if __name__ == "__main__":
    main(sys.argv[1:])
