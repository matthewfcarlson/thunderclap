"""The runner's sampler bindings (wvk1, run/app/rm_bind.cpp): every runner texture binding, submit and sink draw goes
through rm (so a program's declared samplers are bound, or given dummies, at every submit), and rm_bind.cpp's table
knows each runner sampler's stage as the shaders declare it."""
import glob
import os
import re
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
APP = os.path.join(ROOT, "src/platform/wasm/run/app")

# bgfx / sink calls that bind, consume or drop texture bindings; only rm_bind.cpp makes them (rm_pass.cpp's sink pass
# sets, copies, effect quads and the present are each followed by rm::bindingsDropped)
DIRECT = re.compile(r"\b(bgfx::setTexture|bgfx::submit|bgfx::touch|hulk_gfx_sink_submit_draw)\s*\(")
DROPPERS = re.compile(r"\b(hulk_gfx_sink_set_pass|hulk_gfx_sink_copy_frame|hulk_gfx_sink_fx_draw|hulk_gfx_sink_present)\s*\(")


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


def code_lines(path):
    for n, line in enumerate(read(path).split("\n"), 1):
        yield n, line.split("//", 1)[0]


class RmBind(unittest.TestCase):
    def test_no_direct_calls(self):
        bad = []
        for f in sorted(glob.glob(os.path.join(APP, "*.cpp"))):
            if os.path.basename(f) == "rm_bind.cpp":
                continue
            for n, line in code_lines(f):
                if DIRECT.search(line):
                    bad.append("%s:%d: %s" % (os.path.basename(f), n, line.strip()))
        self.assertEqual(bad, [], "use rm::bindTexture / rm::submit / rm::touch / rm::sinkDraw")

    def test_droppers_noted(self):
        lines = list(code_lines(os.path.join(APP, "rm_pass.cpp")))
        bad = []
        for i, (n, line) in enumerate(lines):
            if DROPPERS.search(line) and not any("bindingsDropped(" in l for _, l in lines[i + 1:i + 3]):
                bad.append("rm_pass.cpp:%d: %s" % (n, line.strip()))
        others = []
        for f in sorted(glob.glob(os.path.join(APP, "*.cpp"))):
            if os.path.basename(f) in ("rm_pass.cpp", "rm_bind.cpp"):
                continue
            for n, line in code_lines(f):
                if DROPPERS.search(line):
                    others.append("%s:%d" % (os.path.basename(f), n))
        self.assertEqual(bad, [])
        self.assertEqual(others, [], "sink pass/copy/effect/present calls go through rm (rm_pass.cpp)")

    def test_sampler_stages(self):
        src = read(os.path.join(APP, "rm_bind.cpp"))
        known = {m.group(1): int(m.group(2)) for m in re.finditer(r'\{"(s_\w+)", (\d+), k\w+\}', src)}
        self.assertIn("s_rmShadow", known)
        bad = []
        for f in sorted(glob.glob(os.path.join(APP, "shaders", "*.s[ch]"))):
            for m in re.finditer(r"\bSAMPLER\w*\(\s*(\w+)\s*,\s*(\d+)\s*\)", read(f)):
                name, stage = m.group(1), int(m.group(2))
                g = re.fullmatch(r"s_(?:rmTex|pddiTex)(\d)", name)
                want = int(g.group(1)) if g else known.get(name)
                if want != stage:
                    bad.append("%s: %s at %d (rm_bind.cpp: %s)" % (os.path.basename(f), name, stage, want))
        self.assertEqual(bad, [])


if __name__ == "__main__":
    unittest.main()
