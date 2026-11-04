#!/usr/bin/env python3
"""A glibc sysroot for linking the x86-64 Linux native build on a Mac (tools/native_elf.py --target linux-x64).

  build/venv/bin/python tools/linux_sysroot.py [OUT_DIR]        # default build/elf1/sysroot-x64 (about 70 MB)

Debian 11 (bullseye) packages, the base of Steam Runtime 3 "sniper" that SteamOS games run in: glibc 2.31, the
kernel headers, GCC 10's libstdc++ and libgcc (start files). Each .deb is fetched from deb.debian.org into its own
directory, checked against the SHA-256 pinned below (taken from bullseye's Packages index), unpacked with `ar` and
`tar` (nothing from the packages is run), and absolute symlinks are made relative so the tree works under
--sysroot. Only headers and link-time libraries are used: nothing here runs on the Mac.
"""
import hashlib
import os
import subprocess
import sys
import tempfile
import urllib.request

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MIRROR = "https://deb.debian.org/debian/"
PACKAGES = [
    ("pool/main/g/glibc/libc6_2.31-13+deb11u11_amd64.deb",
     "05f7264da867b37f4c5ce49266b558ea1e81e05a9464f623152fca70f3550282"),
    ("pool/main/g/glibc/libc6-dev_2.31-13+deb11u11_amd64.deb",
     "e7f7b45d9c5cfcf37609f0b6efd3c645272c812144703af89dfd32218fcb0fd3"),
    ("pool/main/l/linux/linux-libc-dev_5.10.223-1_amd64.deb",
     "e3be603bd12377bb90fcfb0f2048ca3a81c886e49d6f09945b82159d1c54f7b2"),
    ("pool/main/g/gcc-10/libgcc-10-dev_10.2.1-6_amd64.deb",
     "3b711374092b84e732c4e73cf33e02cff02e34a5f105eb6467de8d9038e4cd9d"),
    ("pool/main/g/gcc-10/libgcc-s1_10.2.1-6_amd64.deb",
     "e478f2709d8474165bb664de42e16950c391f30eaa55bc9b3573281d83a29daf"),
    ("pool/main/g/gcc-10/libstdc++-10-dev_10.2.1-6_amd64.deb",
     "20b1f56863dcc5f187d6cb53b2aa6149bd013be4ec67e10c2c31a22fda619a01"),
    ("pool/main/g/gcc-10/libstdc++6_10.2.1-6_amd64.deb",
     "5c155c58935870bf3b4bfe769116841c0d286a74f59eccfd5645693ac23f06b1"),
    ("pool/main/libx/libxcrypt/libcrypt1_4.4.18-4_amd64.deb",
     "f617952df0c57b4ee039448e3941bccd3f97bfff71e9b0f87ca6dae15cb3f5ef"),
]


def main():
    out = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/elf1/sysroot-x64"))
    dl = os.path.join(os.path.dirname(out), "dl", "debs")
    os.makedirs(dl, exist_ok=True)
    os.makedirs(out, exist_ok=True)
    for path, sha in PACKAGES:
        deb = os.path.join(dl, os.path.basename(path))
        if not os.path.exists(deb):
            urllib.request.urlretrieve(MIRROR + path, deb + ".part")
            os.replace(deb + ".part", deb)
        if hashlib.sha256(open(deb, "rb").read()).hexdigest() != sha:
            sys.exit("%s: SHA-256 mismatch" % deb)
        with tempfile.TemporaryDirectory(dir=os.path.dirname(dl)) as t:
            subprocess.run(["ar", "x", deb], cwd=t, check=True)
            data = next(n for n in os.listdir(t) if n.startswith("data.tar"))
            subprocess.run(["tar", "-xf", os.path.join(t, data), "-C", out], check=True)
    for d, dirs, files in os.walk(out):
        for n in dirs + files:
            p = os.path.join(d, n)
            if os.path.islink(p) and os.readlink(p).startswith("/"):
                target = os.path.join(out, os.readlink(p).lstrip("/"))
                os.unlink(p)
                os.symlink(os.path.relpath(target, d), p)
    print(out)


if __name__ == "__main__":
    main()
