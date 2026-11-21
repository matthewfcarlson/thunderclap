"""LLVM IR helpers for the wasm32 port build (tools/wasm_port.py, docs/wasm-port.md).

Adapted from the owner's sibling project's wasm port (fusion-frenzy-decomp tools/wasm_port.py): parsing of clang's
i686-pc-windows-msvc IR, x86 argument layouts, the packers that call a generic entry with x86-placed arguments, the
generic entries that unpack them by the definition's own type, and the retarget to wasm32.
"""
import re
import zlib

DATALAYOUT = "e-m:e-p:32:32-p10:8:8-p20:8:8-i64:64-i128:128-n32:64-S128-ni:1:10:20"
TRIPLE = "wasm32-unknown-emscripten"

NAME = r'@(?:"[^"]+"|[-\w.$]+)'
LOCAL = r'%(?:"[^"]+"|[-\w.$]+)'
TOKEN = re.compile(NAME + r'(?![-\w.$])')
CCS = ("x86_thiscallcc", "x86_stdcallcc", "x86_fastcallcc", "x86_vectorcallcc", "x86_regcallcc")
PARAM_ATTR = re.compile(r'^(noundef|nonnull|noalias|nocapture|readonly|writeonly|readnone|returned|signext|zeroext|'
                        r'inreg|dead_on_unwind|dead_on_return|writable|immarg|nofree|noundef|swiftself|'
                        r'align \d+|dereferenceable\(\d+\)|dereferenceable_or_null\(\d+\)|'
                        r'captures\([^)]*\)|range\([^)]*\)|nofpclass\([^)]*\)|initializes\([^)]*\)|'
                        r'byval\([^)]*\)|sret\([^)]*\)|byref\([^)]*\)|elementtype\([^)]*\)|inalloca\([^)]*\))\s*')


def irname(tok):
    """'@"x"' / '@x' -> x."""
    return tok[2:-1] if tok.startswith('@"') else tok[1:]


def at(name):
    return "@" + name if re.fullmatch(r"[-\w.$]+", name) and not name[0].isdigit() else '@"%s"' % name


def matching(s, i):
    """Index just past the bracket that closes s[i] ('(', '{', '[', '<')."""
    pairs = {"(": ")", "{": "}", "[": "]", "<": ">"}
    stack = []
    j = i
    while j < len(s):
        c = s[j]
        if c == '"':
            j = s.index('"', j + 1)
        elif c in pairs:
            stack.append(pairs[c])
        elif stack and c == stack[-1]:
            stack.pop()
            if not stack:
                return j + 1
        j += 1
    raise ValueError("unbalanced: " + s[i:i + 80])


def split_top(s):
    """Split at commas outside brackets and quotes."""
    out, depth, cur, q = [], 0, [], False
    for c in s:
        if c == '"':
            q = not q
        if not q:
            if c in "({[<":
                depth += 1
            elif c in ")}]>":
                depth -= 1
            elif c == "," and depth == 0:
                out.append("".join(cur).strip())
                cur = []
                continue
        cur.append(c)
    if "".join(cur).strip():
        out.append("".join(cur).strip())
    return out


def parse_type(s):
    """(type, rest) for the type at the start of s."""
    s = s.lstrip()
    if s[0] in "{[<":
        j = matching(s, 0)
        return s[:j], s[j:]
    if s.startswith("<{"):
        j = matching(s, 1) + 1
        return s[:j], s[j:]
    m = re.match(r'(%(?:"[^"]+"|[-\w.$]+)|i\d+|float|double|x86_fp80|half|ptr|void|label|metadata)', s)
    if not m:
        raise ValueError("type? " + s[:60])
    return m.group(1), s[m.end():]


class Param:
    __slots__ = ("type", "byval", "sret", "inreg", "ext", "name")

    def __init__(self, text):
        self.byval = self.sret = None
        self.inreg = False
        self.ext = ""
        t, rest = parse_type(text)
        self.type = t
        rest = rest.strip()
        while True:
            m = PARAM_ATTR.match(rest)
            if not m:
                break
            a = m.group(1)
            if a.startswith("byval("):
                self.byval = a[6:-1]
            elif a.startswith("sret("):
                self.sret = a[5:-1]
            elif a == "inreg":
                self.inreg = True
            elif a in ("signext", "zeroext"):
                self.ext = a
            rest = rest[m.end():]
        self.name = rest.strip() or None

    def key(self):
        return "%s%s%s%s" % (self.type, "/byval(%s)" % self.byval if self.byval else "",
                             "/sret" if self.sret else "", "/inreg" if self.inreg else "")


class Sig:
    """A function type with its x86 calling convention."""

    def __init__(self, cc, ret, params, varargs):
        self.cc, self.ret, self.params, self.varargs = cc, ret, params, varargs

    def key(self, types=None):
        """Canonical text: two declarations call alike on wasm iff equal (struct names expanded through TYPES)."""
        def t(x):
            return expand(x, types) if types is not None else x
        k = "%s %s(%s%s)" % (self.cc or "c", t(self.ret), ",".join(
            t(p.type) + p.key()[len(p.type):].replace(p.byval or "\0", t(p.byval) if p.byval else "")
            for p in self.params), ",..." if self.varargs else "")
        return re.sub(r"\bptr\b", "i32", k)      # one wasm type

    def ir_type(self):
        return "%s (%s%s)" % (self.ret, ", ".join(p.type for p in self.params), ", ..." if self.varargs else "")


FUNC_LINE = re.compile(r'^(define|declare) (.*?)(' + NAME + r')\(', re.M)


def parse_func_line(line):
    """(kind, prefix words, name, Sig, rest-after-params) for a define/declare line."""
    m = FUNC_LINE.match(line)
    if not m:
        return None
    kind, prefix, name = m.group(1), m.group(2), irname(m.group(3))
    i = m.end() - 1
    j = matching(line, i)
    params = split_top(line[i + 1:j - 1])
    varargs = bool(params) and params[-1] == "..."
    if varargs:
        params = params[:-1]
    words = prefix.split()
    cc = next((w for w in words if w in CCS), None)
    ret = ret_type(prefix)
    return kind, prefix, name, Sig(cc, ret, [Param(p) for p in params], varargs), line[j:]


RET_ATTRS = re.compile(r'\b(noundef|nonnull|noalias|signext|zeroext|inreg|align \d+|dereferenceable\(\d+\)|'
                       r'dereferenceable_or_null\(\d+\)|range\([^)]*\)|nofpclass\([^)]*\))\s*')


def ret_type(prefix):
    """The return type at the end of a define/declare/call prefix."""
    p = RET_ATTRS.sub("", prefix).strip()
    if p.endswith("}") or p.endswith(">") or p.endswith("]"):
        # an aggregate: find its opening bracket
        depth = 0
        for k in range(len(p) - 1, -1, -1):
            if p[k] in "}>]":
                depth += 1
            elif p[k] in "{<[":
                depth -= 1
                if depth == 0:
                    if k > 0 and p[k - 1] == "<":
                        k -= 1
                    return p[k:]
    return p.split()[-1]


TYPEDEF = re.compile(r'^(%(?:"[^"]+"|[-\w.$]+)) = type (.*)$', re.M)


def typedefs(ir):
    return {m.group(1): m.group(2).strip() for m in TYPEDEF.finditer(ir)}


def expand(t, types, depth=0):
    """A type with its named structs replaced by their bodies (for comparing types across modules)."""
    if types is None or depth > 20:
        return t
    return re.sub(r'%(?:"[^"]+"|[-\w.$]+)', lambda m: expand(types.get(m.group(0), "opaque"), types, depth + 1)
                  if m.group(0) in types else m.group(0), t)


SIZES = {"i1": (1, 1), "i8": (1, 1), "i16": (2, 2), "i32": (4, 4), "i64": (8, 8), "float": (4, 4), "double": (8, 8),
         "ptr": (4, 4), "half": (2, 2), "x86_fp80": (16, 16), "i128": (16, 16)}


def layout(t, types):
    """(size, align) of an IR type under the wasm32 data layout (msvc's layout: i64 and double align 8)."""
    t = t.strip()
    if t in SIZES:
        return SIZES[t]
    if t.startswith("%"):
        body = types.get(t)
        if body is None or body == "opaque":
            return 0, 1
        return layout(body, types)
    packed = t.startswith("<{")
    if packed or t.startswith("{"):
        inner = t[2:-2] if packed else t[1:-1]
        off, al = 0, 1
        for f in split_top(inner):
            s, a = layout(f, types)
            if packed:
                a = 1
            off = (off + a - 1) // a * a + s
            al = max(al, a)
        return (off + al - 1) // al * al, al
    m = re.match(r'\[(\d+) x (.*)\]$', t)
    if m:
        s, a = layout(m.group(2), types)
        return int(m.group(1)) * s, a
    m = re.match(r'<(\d+) x (.*)>$', t)
    if m:
        s, a = layout(m.group(2), types)
        return int(m.group(1)) * s, int(m.group(1)) * s
    raise ValueError("layout? " + t)


# ---------------------------------------------------------------------------------------------- x86 layout
REGS = {"eax": 0, "ecx": 1, "edx": 2, "ebx": 3, "esi": 6, "edi": 7}


def x86_layout(sig, types, locs=None):
    """[(param index, register name | stack offset, size)], stack bytes: where x86 passes each parameter. LOCS (an
    `// equiv-conv` line's list) overrides the convention: a register name or "stack" per parameter."""
    regs = ["ecx", "edx"] if sig.cc == "x86_fastcallcc" else (["ecx"] if sig.cc == "x86_thiscallcc" else [])
    out, off = [], 0
    for k, p in enumerate(sig.params):
        if locs is not None:
            loc = locs[k] if k < len(locs) else "stack"
            if loc in REGS:
                out.append((k, loc, 4))
                continue
            size = layout(p.byval, types)[0] if p.byval else layout(p.type, types)[0]
            out.append((k, off, size))
            off += (size + 3) // 4 * 4
            continue
        if sig.cc == "x86_thiscallcc" and k == 0:
            out.append((k, regs.pop(0), 4))
            continue
        if sig.cc == "x86_fastcallcc" and p.inreg and regs:
            out.append((k, regs.pop(0), 4))
            continue
        size = layout(p.byval, types)[0] if p.byval else layout(p.type, types)[0]
        out.append((k, off, size))
        off += (size + 3) // 4 * 4
    return out, off


def ret_kind(t):
    if t == "void":
        return "void"
    if t in ("float", "double", "x86_fp80"):
        return "fp"
    return "int"


# ---------------------------------------------------------------------------------------------- packers and entries
class Emitter:
    def __init__(self):
        self.lines = []
        self.n = 0

    def v(self):
        self.n += 1
        return "%%v%d" % self.n

    def __call__(self, s):
        self.lines.append("  " + s)


def store_arg(e, p, val, dst, types):
    """Store parameter value VAL (of P's type) at DST (ptr)."""
    if p.byval:
        size = layout(p.byval, types)[0]
        e("call void @llvm.memcpy.p0.p0.i32(ptr align 1 %s, ptr align 1 %s, i32 %d, i1 false)" % (dst, val, size))
    elif p.type == "i1":
        z = e.v()
        e("%s = zext i1 %s to i8" % (z, val))
        e("store i8 %s, ptr %s, align 1" % (z, dst))
    else:
        e("store %s %s, ptr %s, align 1" % (p.type, val, dst))


def as_i32(e, p, val):
    """An x86 register value for parameter value VAL."""
    if p.type == "i32":
        return val
    v = e.v()
    if p.type == "ptr":
        e("%s = ptrtoint ptr %s to i32" % (v, val))
    elif p.type in ("i8", "i16", "i1"):
        e("%s = %s %s %s to i32" % (v, "sext" if p.ext == "signext" else "zext", p.type, val))
    elif p.type == "float":
        e("%s = bitcast float %s to i32" % (v, val))
    else:
        return "0"
    return v


def from_i32(e, p, reg):
    if p.type == "i32":
        return reg
    v = e.v()
    if p.type == "ptr":
        e("%s = inttoptr i32 %s to ptr" % (v, reg))
    elif p.type in ("i8", "i16", "i1"):
        e("%s = trunc i32 %s to %s" % (v, reg, p.type))
    elif p.type == "float":
        e("%s = bitcast i32 %s to float" % (v, reg))
    else:
        e("%s = zext i32 %s to %s" % (v, reg, p.type))
    return v


def packer(name, sig, target, types, indirect=False, locs=None):
    """An internal function of SIG's type that calls the generic entry TARGET (or ff_dispatch with the leading
    pointer argument when INDIRECT) with the arguments in x86 places."""
    e = Emitter()
    params = (["ptr %fp"] if indirect else []) + ["%s %%a%d" % (p.type, k) for k, p in enumerate(sig.params)]
    head = "define internal %s %s(%s) {" % (sig.ret, at(name), ", ".join(params))
    places, size = x86_layout(sig, types, locs)
    regs = {"ecx": "0", "edx": "0"}
    e("%st = alloca i8, i32 " + str(max(size, 4)) + ", align 8")
    e("call void @llvm.memset.p0.i32(ptr align 8 %%st, i8 0, i32 %d, i1 false)" % max(size, 4))
    e("%rb = alloca [16 x i8], align 8")
    e("call void @llvm.memset.p0.i32(ptr align 8 %rb, i8 0, i32 16, i1 false)")
    for k, place, _ in places:
        p = sig.params[k]
        if place in regs:
            regs[place] = as_i32(e, p, "%%a%d" % k)
        elif place in REGS:             # eax, ebx, esi, edi: the host's register file
            v = as_i32(e, p, "%%a%d" % k)
            d = e.v()
            e("%s = getelementptr inbounds [8 x i32], ptr @ff_regs, i32 0, i32 %d" % (d, REGS[place]))
            e("store i32 %s, ptr %s, align 4" % (v, d))
        else:
            d = e.v()
            e("%s = getelementptr inbounds i8, ptr %%st, i32 %d" % (d, place))
            store_arg(e, p, "%%a%d" % k, d, types)
    if indirect:
        f = e.v()
        e("%s = ptrtoint ptr %%fp to i32" % f)
        e("call void @ff_dispatch(i32 %s, i32 %s, i32 %s, ptr %%st, ptr %%rb)" % (f, regs["ecx"], regs["edx"]))
    else:
        e("call void %s(i32 %s, i32 %s, ptr %%st, ptr %%rb)" % (at(target), regs["ecx"], regs["edx"]))
    load_ret(e, sig.ret, "%rb")
    return [head] + e.lines + ["}"]


def load_ret(e, t, rb):
    k = ret_kind(t)
    if k == "void":
        e("ret void")
    elif k == "fp":
        d = e.v()
        e("%s = getelementptr inbounds i8, ptr %s, i32 8" % (d, rb))
        v = e.v()
        e("%s = load double, ptr %s, align 8" % (v, d))
        if t == "float":
            w = e.v()
            e("%s = fptrunc double %s to float" % (w, v))
            v = w
        e("ret %s %s" % (t, v))
    else:
        v = e.v()
        e("%s = load %s, ptr %s, align 8" % (v, t, rb))
        e("ret %s %s" % (t, v))


def entry(name, sig, target, types, locs=None):
    """`void NAME(i32 ecx, i32 edx, ptr stack, ptr ret)`: TARGET (of SIG) called with x86-placed arguments."""
    e = Emitter()
    places, _ = x86_layout(sig, types, locs)
    args = [None] * len(sig.params)
    for k, place, _ in places:
        p = sig.params[k]
        if place in ("ecx", "edx"):
            args[k] = from_i32(e, p, "%" + place)
        elif place in REGS:
            d = e.v()
            e("%s = getelementptr inbounds [8 x i32], ptr @ff_regs, i32 0, i32 %d" % (d, REGS[place]))
            v = e.v()
            e("%s = load i32, ptr %s, align 4" % (v, d))
            args[k] = from_i32(e, p, v)
        else:
            d = e.v()
            e("%s = getelementptr inbounds i8, ptr %%st, i32 %d" % (d, place))
            if p.byval:
                args[k] = d
            else:
                v = e.v()
                e("%s = load %s, ptr %s, align 1" % (v, "i8" if p.type == "i1" else p.type, d))
                if p.type == "i1":
                    w = e.v()
                    e("%s = trunc i8 %s to i1" % (w, v))
                    v = w
                args[k] = v
    call = "call %s %s(%s)" % (sig.ret, at(target), ", ".join(
        "%s%s %s" % (p.type, " byval(%s)" % p.byval if p.byval else "", a) for p, a in zip(sig.params, args)))
    k = ret_kind(sig.ret)
    if k == "void":
        e(call)
        sret = next((a for p, a in zip(sig.params, args) if p.sret), None)
        if sret:
            e("store ptr %s, ptr %%rb, align 8" % sret)        # x86 returns the sret pointer in eax
    else:
        r = e.v()
        e("%s = %s" % (r, call))
        if k == "fp":
            d = e.v()
            e("%s = getelementptr inbounds i8, ptr %%rb, i32 8" % d)
            if sig.ret == "float":
                w = e.v()
                e("%s = fpext float %s to double" % (w, r))
                r = w
            e("store double %s, ptr %s, align 8" % (r, d))
        else:
            e("store %s %s, ptr %%rb, align 8" % (sig.ret, r))
    e("ret void")
    return ["define void %s(i32 %%ecx, i32 %%edx, ptr %%st, ptr %%rb) {" % at(name)] + e.lines + ["}"]


# ---------------------------------------------------------------------------------------------- binding
def coff_names(n):
    """IR spellings of a COFF symbol name."""
    out = {n, "\x01" + n, "\\01" + n}
    if not n.startswith("?"):
        m = re.match(r'^[_@](.*?)(@\d+)?$', n)
        if m:
            out.add(m.group(1))
    return out

ALIAS = re.compile(r'^(' + NAME + r') = (?:[\w]+ )*?alias .*, ptr (' + NAME + r')\s*$', re.M)


VCALL = re.compile(r'^(\s*)(%[-\w.]+ = )?((?:tail |notail )?call )(.*?)@ff_([0-9a-f]{8})\(')


def x86_words(args, tag, indent, head, types, notes):
    """Variadic arguments laid out as x86 pushes them, in 4-byte words: wasm puts a double or an i64 at the next
    multiple of 8 in its variadic buffer and passes a byval struct as a pointer to a copy, where x86 has them in
    consecutive 4-byte stack slots. Each becomes i32 words (instructions appended to HEAD), so a callee that walks
    the list x86-style (`// port-va: x86`) reads what the original's did."""
    def emit(text):
        name = "%%ffx.%s.%d" % (tag, len(head))
        head.append("%s%s = %s" % (indent, name, text))
        return name
    out = []
    for a in args:
        t, rest = parse_type(a)
        val, attrs = rest.strip(), ""
        while True:
            am = PARAM_ATTR.match(val)
            if not am or not am.group(0):
                break
            attrs += am.group(0)
            val = val[am.end():]
        if t in ("double", "i64"):
            v = emit("bitcast double %s to i64" % val) if t == "double" else val
            out += ["i32 noundef " + emit("trunc i64 %s to i32" % v),
                    "i32 noundef " + emit("trunc i64 %s to i32" % emit("lshr i64 %s, 32" % v))]
            notes["variadic x86 layout: 8-byte argument"] += 1
        elif "byval(" in attrs:
            size = layout(re.search(r'byval\((.*?)\)', attrs).group(1), types)[0]
            for k in range(0, size, 4):
                g = emit("getelementptr inbounds i8, ptr %s, i32 %d" % (val, k))
                n = min(4, size - k)        # a tail shorter than a word: x86 pushes what follows, the port zeroes
                w = emit("load i%d, ptr %s, align 1" % (8 * n, g))
                out.append("i32 noundef " + (w if n == 4 else emit("zext i%d %s to i32" % (8 * n, w))))
            notes["variadic x86 layout: struct by value"] += 1
        else:
            out.append(a)
    return out


def vararg_call(line, deftys, notes, x86va=(), types=None):
    """A direct call of a variadic game function, spelled with the definition's own type: callers declare such
    functions with other fixed parameters or results (`int` for `void`), which wasm would trap on. Arguments past
    the definition's fixed ones go variadic; a result the definition doesn't have is 0, one of the other kind
    (pointer for int) is converted. A callee in X86VA walks its list x86-style: its variadic arguments are laid out
    as x86 words (x86_words)."""
    m = VCALL.match(line)
    if not m:
        return line
    callee = int(m.group(5), 16)
    ty = deftys.get(callee)
    if not ty or not ty[2]:
        return line
    ret, fixed = ty[0], ty[1]
    open_ = m.end() - 1
    close = matching(line, open_)
    args = split_top(line[open_ + 1:close - 1])
    want_fn = "%s (%s)" % (ret, ", ".join(fixed + ["..."]))
    pre = m.group(4)
    x86 = callee in x86va
    if re.search(r'\(([^()]*)\)\s*$', pre) and pre.strip().endswith(")") and \
            pre.strip().endswith("(%s)" % ", ".join(fixed + ["..."])) and ret_type(re.sub(r'\([^()]*\)\s*$', '', pre)) == ret \
            and not x86:
        return line                                   # already the definition's type
    caller_ret = ret_type(re.sub(r'\([^()]*\)\s*$', '', pre).strip() or "void")
    head = []
    new_args = []
    for i, a in enumerate(args):
        t, rest = parse_type(a)
        val = rest.strip()
        while True:                 # the attributes, then the value (a constant expression may have spaces)
            am = PARAM_ATTR.match(val)
            if not am or not am.group(0):
                break
            val = val[am.end():]
        if i < len(fixed) and t != fixed[i]:
            tmp = "%%ffv.%d.%d" % (zlib.crc32(line.encode()), len(head))
            if t == "i32" and fixed[i] == "ptr":
                head.append("%s%s = inttoptr i32 %s to ptr" % (m.group(1), tmp, val))
            elif t == "ptr" and fixed[i] == "i32":
                head.append("%s%s = ptrtoint ptr %s to i32" % (m.group(1), tmp, val))
            elif {t, fixed[i]} == {"i32", "float"}:     # the same 4 bytes on x86's stack (an int 0 for 0.0f)
                head.append("%s%s = bitcast %s %s to %s" % (m.group(1), tmp, t, val, fixed[i]))
            else:
                notes["variadic fixed argument of another type"] += 1
                return line
            new_args.append("%s %s" % (fixed[i], tmp))
        else:
            new_args.append(a)
    if len(args) < len(fixed):
        notes["variadic call with too few arguments"] += 1
        return line
    if x86:
        new_args = new_args[:len(fixed)] + x86_words(new_args[len(fixed):], zlib.crc32(line.encode()), m.group(1),
                                                     head, types or {}, notes)
    call = "%s%s%s @ff_%s(%s)%s" % (m.group(1), m.group(3), want_fn, m.group(5), ", ".join(new_args), line[close:])
    lhs = m.group(2)
    notes["variadic call retyped"] += 1
    if not lhs:
        if ret != "void":           # an unnamed result would take the next value number
            call = "%s%%ffr.%d = %s" % (m.group(1), zlib.crc32(line.encode()), call.lstrip())
        return "\n".join(head + [call])
    if ret == caller_ret:
        return "\n".join(head + [m.group(1) + lhs + call.lstrip()])
    if {ret, caller_ret} == {"i32", "ptr"}:     # eax either way
        r = "%%ffr.%d" % zlib.crc32(line.encode())
        conv = "ptrtoint ptr %s to i32" if ret == "ptr" else "inttoptr i32 %s to ptr"
        return "\n".join(head + ["%s%s = %s" % (m.group(1), r, call.lstrip()),
                                 "%s%s%s" % (m.group(1), lhs, conv % r)])
    if ret == "void":
        return "\n".join(head + [call, "%s%s%s" % (m.group(1), lhs,
                                                    "add i32 0, 0" if caller_ret == "i32" else
                                                    "inttoptr i32 0 to ptr" if caller_ret == "ptr" else
                                                    "fadd %s 0.0, 0.0" % caller_ret)])
    notes["variadic result of another type"] += 1
    return line


def deleting_dtor(ir, sym, resolved):
    """IR for a scalar deleting destructor cl emitted and clang doesn't (clang emits one with its vftable):
    `void* X::`scalar deleting destructor'(unsigned flags) { this->~X(); if (flags & 1) delete this; return this; }`."""
    cls = sym[len("??_G"):].split("@@")[0]
    names = set(resolved) | set(irname(t) for t in re.findall(r'^(?:define|declare) [^@]*(' + NAME + r')\(', ir, re.M))
    dtor = next((n for n in sorted(names) if n.startswith("??1%s@@" % cls)), None)
    delete = next((n for n in sorted(names) if n.startswith("??3@")), "??3@YAXPAX@Z")
    body = ["define x86_thiscallcc ptr %s(ptr %%this, i32 %%flags) {" % at(sym)]
    if dtor:
        body.append("  call x86_thiscallcc void %s(ptr %%this)" % at(dtor))
    body += ["  %b = and i32 %flags, 1", "  %c = icmp ne i32 %b, 0", "  br i1 %c, label %del, label %done", "del:",
             "  call void %s(ptr %%this)" % at(delete), "  br label %done", "done:", "  ret ptr %this", "}"]
    have = set(irname(t) for t in re.findall(r'^(?:define|declare) [^@]*(' + NAME + r')\(', ir, re.M))
    if dtor and dtor not in have:
        body.append("declare x86_thiscallcc void %s(ptr)" % at(dtor))
    if delete not in have:
        body.append("declare void %s(ptr)" % at(delete))
    return ir + "\n" + "\n".join(body) + "\n"


def retarget(s):
    s = re.sub(r'^target datalayout = .*$', 'target datalayout = "%s"' % DATALAYOUT, s, count=1, flags=re.M)
    s = re.sub(r'^target triple = .*$', 'target triple = "%s"' % TRIPLE, s, count=1, flags=re.M)
    s = re.sub(r'\b(?:%s) ' % "|".join(CCS), '', s)
    s = re.sub(r'\b(dllimport|dllexport) ', '', s)
    s = re.sub(r'^!llvm\.linker\.options = .*\n', '', s, flags=re.M)
    s = re.sub(r'^@llvm\.global_ctors = .*\n', '', s, flags=re.M)
    s = re.sub(r'"(target-cpu|target-features|tune-cpu)"="[^"]*"', '', s)
    return s


# ---------------------------------------------------------------------------------------------- compile


CALL = re.compile(r'\b(?:tail |musttail |notail )?call ((?:[^@%(\n]|\([^()\n]*\))*?)(' + NAME + '|' + LOCAL + r')\(')
