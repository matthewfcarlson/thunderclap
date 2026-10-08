#!/usr/bin/env python3
"""Dump XBE header info: hashes, build time, debug path, sections, XDK library versions.
Usage: tools/xbeinfo.py isos/extracted/default.xbe"""
import struct, sys, hashlib
d = open(sys.argv[1],'rb').read()
base, = struct.unpack_from('<I', d, 0x104)
def va2off(va): return va - base
hdr_size, img_size, img_hdr_size, ts, cert_va, nsec, sec_va = struct.unpack_from('<IIIIIII', d, 0x108)
init_flags, entry, tls = struct.unpack_from('<III', d, 0x124)
nlib, lib_va = struct.unpack_from("<II", d, 0x160)
import datetime
print("md5", hashlib.md5(d).hexdigest(), "sha1", hashlib.sha1(d).hexdigest())
print("base %x hdrsize %x imgsize %x time %s" % (base, hdr_size, img_size, datetime.datetime.fromtimestamp(ts, datetime.UTC)))
ek = entry ^ 0xA8FC57AB; ed = entry ^ 0x94859D4B
print("entry retail=%x debug=%x" % (ek, ed))
dbg_path_va, dbg_file_va, dbg_ufile_va = struct.unpack_from('<III', d, 0x14C)
def cstr(va):
    o = va2off(va); return d[o:d.index(b'\0', o)].decode('latin1')
print("debug path:", cstr(dbg_path_va))
tid, = struct.unpack_from('<I', d, va2off(cert_va)+8)
title = d[va2off(cert_va)+0xC:va2off(cert_va)+0xC+80].decode('utf-16le').rstrip('\0')
print("title id %08x %s" % (tid, title))
print("sections:")
for i in range(nsec):
    o = va2off(sec_va) + i*56
    fl, va, vs, ra, rs, name_va = struct.unpack_from('<IIIIII', d, o)
    print("  %-10s va=%08x vsize=%08x raw=%08x rsize=%08x flags=%x" % (cstr(name_va), va, vs, ra, rs, fl))
print("libraries:")
for i in range(nlib):
    o = va2off(lib_va) + i*16
    name = d[o:o+8].rstrip(b'\0').decode(); maj, mnr, bld, fl = struct.unpack_from('<HHHH', d, o+8)
    print("  %-10s %d.%d.%d flags=%x" % (name, maj, mnr, bld, fl))
