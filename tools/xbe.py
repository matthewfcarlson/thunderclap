"""Minimal XBE image loader: section table and virtual-address reads."""
import struct
from dataclasses import dataclass


DATA_SECTIONS = {".rdata", ".data", "BINKDATA", "DOLBY", "$$XTIMAGE", "$$XSIMAGE"}


@dataclass
class Section:
    name: str
    va: int
    vsize: int
    raw: int
    rsize: int
    flags: int

    @property
    def executable(self) -> bool:
        # The XBE "executable" flag is set on .rdata/.data too, so classify by name.
        return self.name not in DATA_SECTIONS

    def contains(self, va: int) -> bool:
        return self.va <= va < self.va + self.vsize


class Xbe:
    def __init__(self, path):
        self.data = open(path, "rb").read()
        self.base, = struct.unpack_from("<I", self.data, 0x104)
        nsec, sec_va = struct.unpack_from("<II", self.data, 0x11C)
        self.sections = []
        for i in range(nsec):
            o = sec_va - self.base + i * 56
            fl, va, vs, ra, rs, name_va = struct.unpack_from("<IIIIII", self.data, o)
            self.sections.append(Section(self._hdr_cstr(name_va), va, vs, ra, rs, fl))

    def _hdr_cstr(self, va):
        o = va - self.base
        return self.data[o:self.data.index(b"\0", o)].decode("latin1")

    def section_of(self, va):
        for s in self.sections:
            if s.contains(va):
                return s
        return None

    def offset(self, va):
        """File offset for a VA, or None if unmapped / in BSS."""
        s = self.section_of(va)
        if s is None or va - s.va >= s.rsize:
            return None
        return s.raw + (va - s.va)

    def u32(self, va):
        o = self.offset(va)
        if o is None or o + 4 > len(self.data):
            return None
        return struct.unpack_from("<I", self.data, o)[0]

    def cstr(self, va, limit=4096):
        o = self.offset(va)
        if o is None:
            return None
        end = self.data.find(b"\0", o, o + limit)
        return None if end < 0 else self.data[o:end].decode("latin1")

    def is_code(self, va):
        s = self.section_of(va)
        return s is not None and s.executable
