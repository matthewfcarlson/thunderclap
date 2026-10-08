"""Small MSVC demangler for RTTI type-descriptor names (".?AVFoo@ns@@").

Covers the subset seen in RTTI: nested names, templates, back-references and
common type codes. Raises DemangleError on anything it doesn't understand.
"""

PRIMITIVES = {
    "C": "signed char", "D": "char", "E": "unsigned char", "F": "short",
    "G": "unsigned short", "H": "int", "I": "unsigned int", "J": "long",
    "K": "unsigned long", "M": "float", "N": "double", "O": "long double",
    "X": "void", "Z": "...",
}
EXT_PRIMITIVES = {
    "N": "bool", "J": "__int64", "K": "unsigned __int64", "W": "wchar_t",
}
CV = {"A": "", "B": "const ", "C": "volatile ", "D": "const volatile "}
CALLCONV = {"A": "__cdecl", "E": "__thiscall", "G": "__stdcall", "I": "__fastcall"}


class DemangleError(Exception):
    pass


class _Parser:
    def __init__(self, s):
        self.s = s
        self.i = 0
        self.names = []  # name back-references (0-9)
        self.types = []  # type back-references (0-9)

    def peek(self, n=1):
        return self.s[self.i:self.i + n]

    def take(self, n=1):
        if self.i + n > len(self.s):
            raise DemangleError("unexpected end")
        r = self.s[self.i:self.i + n]
        self.i += n
        return r

    def ident(self):
        end = self.s.find("@", self.i)
        if end < 0:
            raise DemangleError("unterminated identifier")
        r = self.s[self.i:end]
        self.i = end + 1
        return r

    def number(self):
        neg = self.peek() == "?"
        if neg:
            self.take()
        c = self.take()
        if c.isdigit():
            v = int(c) + 1
        else:
            v = 0
            while c != "@":
                if not "A" <= c <= "P":
                    raise DemangleError("bad number")
                v = v * 16 + (ord(c) - ord("A"))
                c = self.take()
        return -v if neg else v

    def fragment(self):
        c = self.peek()
        if c.isdigit():
            self.take()
            idx = int(c)
            if idx >= len(self.names):
                raise DemangleError("bad name backref")
            return self.names[idx]
        if self.peek(2) == "?$":
            self.take(2)
            # Templates get their own back-reference tables.
            saved = (self.names, self.types)
            self.names, self.types = [], []
            name = self.ident()
            self.names.append(name)
            args = []
            while self.peek() != "@":
                args.append(self.template_arg())
            self.take()
            self.names, self.types = saved
            frag = "%s<%s>" % (name, ",".join(args))
            self.names.append(frag)
            return frag
        frag = self.ident()
        self.names.append(frag)
        return frag

    def qualified_name(self):
        parts = []
        while self.peek() != "@":
            parts.append(self.fragment())
        self.take()
        return "::".join(reversed(parts))

    def template_arg(self):
        if self.peek(2) == "$0":
            self.take(2)
            return str(self.number())
        return self.type()

    def type(self):
        start = self.i
        c = self.take()
        if c.isdigit():
            idx = int(c)
            if idx >= len(self.types):
                raise DemangleError("bad type backref")
            return self.types[idx]
        if c in PRIMITIVES:
            return PRIMITIVES[c]
        if c == "$" and self.peek(2) == "$C":
            # $$C<cv><type>: cv-qualified type in template arguments.
            self.take(2)
            cv = CV.get(self.take())
            if cv is None:
                raise DemangleError("bad cv")
            r = cv + self.type()
        elif c == "_":
            e = self.take()
            if e not in EXT_PRIMITIVES:
                raise DemangleError("unknown extended type _" + e)
            r = EXT_PRIMITIVES[e]
        elif c in "VUT":
            r = {"V": "class ", "U": "struct ", "T": "union "}[c] + self.qualified_name()
        elif c == "W":
            self.take()  # underlying type, usually 4
            r = "enum " + self.qualified_name()
        elif c in "PQRSA":
            if self.peek() == "6":
                self.take()
                r = self.function_pointer()
            else:
                cv = CV.get(self.take())
                if cv is None:
                    raise DemangleError("bad cv")
                r = "%s%s %s" % (cv, self.type(), "&" if c == "A" else "*")
        else:
            raise DemangleError("unknown type code " + c)
        if self.i - start > 1:
            self.types.append(r)
        return r

    def function_pointer(self):
        cc = CALLCONV.get(self.take(), "")
        ret = self.type()
        args = []
        if self.peek() == "X":
            self.take()
        else:
            while self.peek() not in ("@", "Z"):
                args.append(self.type())
            if self.peek() == "@":
                self.take()
        if self.take() != "Z":
            raise DemangleError("bad function type")
        return "%s (%s *)(%s)" % (ret, cc, ",".join(args))


def demangle_type_name(mangled):
    """'.?AVDriver@choreo2@@' -> 'choreo2::Driver'."""
    if not (mangled.startswith(".?AV") or mangled.startswith(".?AU")):
        raise DemangleError("not a type descriptor name")
    p = _Parser(mangled[4:])
    name = p.qualified_name()
    if p.i != len(p.s):
        raise DemangleError("trailing data")
    return name
