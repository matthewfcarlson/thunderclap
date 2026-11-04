"""The name-to-address convention for functions (docs/consolidation-plan.md section 13, docs/equivalence.md).

A function keeps the original's address in its name in one of two forms:

  FUN_000480a0          Ghidra's placeholder (also thunk_FUN_, LAB_)
  SetArc_000480a0       a meaningful name with the address as a suffix: `_` and eight lowercase hex digits, `00` first

The suffix form applies to the *leaf* identifier only (the function's own name, not its class or namespace:
`Obj_480a0::SetArc_000480a0` reads 0x000480a0, `Ctor_001d0480::Ctor_001d0480` is a constructor and reads nothing).
The name before the suffix has at least two characters and starts with a letter (`v_001d0480`, a placeholder virtual
named after its class's constructor, is not the convention). Callers check the address is in the XBE's .text before
using it (a data name such as `g_vftable_0042d2dc` is not a function name).
"""
import re

PLACEHOLDER = re.compile(r"(?:^|_)(?:FUN|thunk_FUN|LAB)_([0-9a-fA-F]{8})$")
SUFFIXED = re.compile(r"([A-Za-z][A-Za-z0-9_]*?)_(00[0-9a-f]{6})")
# the leaf identifier of a C++ MSVC symbol (`?Name@Scope@@...`, not `??0`, `??_7`, ...) or a C one (`_Name`, `_Name@8`,
# `@Name@8`)
# placeholder and data-name prefixes the tools read by their own rules (DAT_, PTR_, the data generator's kinds):
# never the suffix convention
NOT_SUFFIX = {"FUN", "thunk_FUN", "LAB", "DAT", "PTR", "SUB", "UNK", "BYTE", "WORD", "DWORD", "FLOAT", "hulk_at",
              "vtbl", "rttiTD", "data", "func", "flt", "dbl", "fltTbl", "tbl", "ptrTbl", "unk", "unkBss", "struct", "zero",
              "DataLayout", "DataRec"}
_MS_LEAF = re.compile(r"\?([A-Za-z_]\w*)@")
_C_LEAF = re.compile(r"[_@]?([A-Za-z_]\w*?)(?:@\d+)?")


def suffix_address(ident):
    """`SetArc_000480a0` -> 0x000480a0; None for a placeholder (FUN_..., read by the placeholder rules) or anything else."""
    if not ident:
        return None
    m = SUFFIXED.fullmatch(ident)
    if not m or len(m.group(1)) < 2 or m.group(1) in NOT_SUFFIX or PLACEHOLDER.search(ident):
        return None
    return int(m.group(2), 16)


def leaf_of_symbol(sym):
    """The function's own identifier in an object-file symbol, or None (special members, operators, `??_C@` ...)."""
    if sym.startswith("??"):
        return None
    if sym.startswith("?"):
        m = _MS_LEAF.match(sym)
        return m.group(1) if m else None
    m = _C_LEAF.fullmatch(sym)
    return m.group(1) if m else None


def leaf_of_qualified(q):
    """The leaf of a demangled qualified name (`fn_0002e790::Obj::SetArc_000480a0` -> `SetArc_000480a0`)."""
    return re.sub(r"\(.*$", "", q).split("::")[-1].strip() if q else None


def symbol_suffix_address(sym):
    """suffix_address of an object-file symbol's leaf."""
    return suffix_address(leaf_of_symbol(sym))


def ident_address(ident):
    """Either form, for a plain identifier: `FUN_000480a0` or `SetArc_000480a0` -> 0x000480a0 (`thunk_FUN_x` is the
    thunk, not x: None)."""
    m = re.fullmatch(r"(?:FUN|LAB)_([0-9a-fA-F]{8})", ident or "")
    if m:
        return int(m.group(1), 16)
    return suffix_address(ident)
