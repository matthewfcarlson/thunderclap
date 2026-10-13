#!/usr/bin/env python3
"""Generate equivalence sources for constructors that register script bindings inline.

A manager constructor (CSPManager 0x001e7470, CCameraManager 0x0009dd20, ...) fetches the script
registry (FUN_001d4c90) and then registers N bindings, with MSVC having inlined the small
Method<n>/Closure<n> constructors. This script reads the registrations in order from the
disassembly and emits the declarations and one macro line per registration. The hand-written part
(the class, the members initialised before and after) lives in a template file with two markers:

    @@DECLS@@   declarations: forward class, Base/Method<n>/Closure<n>, Entry, Registry, macros
    @@REGS@@    the registration lines (inside the function; `r` is the Registry*, `this` the owner)

usage: inlined_regs.py ADDR TEMPLATE [OUT]     (OUT defaults to build/farm/bench/claude-equiv/work/ADDR.cpp)

Registration shapes recognised (each is `new` + null check + FUN_001d3b70(name, obj)):
  G  inline Method<n> + Closure<n>: Base ctor FUN_001d0480(name, n), vptr, fn at +0x1c, one
     FUN_001d04d0(type DAT) per result/argument (result at +0x18, arguments at +0x10...), owner at +0x20
  E  out-of-line constructor on the new object: FUN_xxx(name, [owner,] fn)   (0x24 or 0x20 bytes)
  M  out-of-line Method constructor FUN_xxx(name, fn), then the Closure vptr and owner stored inline
  O  no allocation: registry->FUN_xxx(name, [owner,] fn)
"""
import os, re, subprocess, sys

ROOT = os.path.dirname(os.path.abspath(__file__))
PY = os.path.join(ROOT, '../../build/venv/bin/python')
PK = os.path.join(ROOT, '../../tools/packet.py')


def packet(addr):
    return subprocess.run([PY, PK, 'show', addr], capture_output=True, text=True).stdout


def parse_packet(txt):
    asm, _, data = txt.partition('Data referenced:')
    ins = []
    for l in asm.splitlines():
        m = re.match(r'  ([0-9a-f]{4})  (.*)$', l)
        if m:
            ins.append((int(m.group(1), 16), m.group(2).strip()))
    strings, vft, funcs = {}, {}, set()
    for l in data.splitlines():
        m = re.match(r'  (0x[0-9a-f]+) = "(.*)"$', l)
        if m: strings[int(m.group(1), 16)] = m.group(2)
        m = re.match(r'  (0x[0-9a-f]+) = (\S.*)::vftable$', l)
        if m: vft[int(m.group(1), 16)] = m.group(2)
        m = re.match(r'  (0x[0-9a-f]+) = &FUN_', l)
        if m: funcs.add(int(m.group(1), 16))
    return ins, strings, vft, funcs


def split_top(s):
    out, d, cur = [], 0, ''
    for ch in s:
        if ch == '<': d += 1
        if ch == '>': d -= 1
        if ch == ',' and d == 0: out.append(cur); cur = ''
        else: cur += ch
    out.append(cur)
    return [x.strip() for x in out]


def cxx(t):
    t = re.sub(r'\b(class|struct)\s+', '', t.strip())
    return t.replace(' *', '*')


def parse_vft(name):
    m = re.match(r'(Method|Closure)(\d)<(.*)>$', name)
    kind, n, args = m.group(1), int(m.group(2)), [cxx(a) for a in split_top(m.group(3))]
    return kind, n, args          # args = [owner, result, a1..an]


BASE_ALIAS = {'float': 'Float', 'bool': 'Bool', 'int': 'Int', 'void': 'Void', 'const char*': 'String',
              'char*': 'CharPtr', 'math::Vector': 'Vector'}


def args_to_alias(t):
    return BASE_ALIAS.get(t) or re.sub(r'\W+', '_', t).strip('_').title().replace('_', '')


def find_items(ins, strings, vft, funcs):
    """Return (items, first, last) for the run of registrations."""
    items, i, n = [], 0, len(ins)
    first = None
    started = False
    while i < n:
        off, t = ins[i]
        if t in ('push 0x24', 'push 0x20') and any(x[1] == 'call FUN_0008d690' for x in ins[i + 1:i + 3]):
            j = i
            while ins[j][1] != 'call FUN_001d3b70':
                j += 1
            body = [x[1] for x in ins[i:j + 1]]
            s = ' '.join(body)
            size = int(t.split()[1], 16)
            if 'call FUN_001d0480' in body:
                k = body.index('call FUN_001d0480')
                ob = re.match(r'mov ecx, (\w+)$', body[k - 1]).group(1)
                s = s.replace('[' + ob, '[ebp')
                kk = body[k - 3].split()[1]
                kk = 0 if kk == 'ebx' else int(kk, 0)
                name = int(re.match(r'push (0x[0-9a-f]+)', body[k - 2]).group(1), 16)
                vts = [int(x, 16) for x in re.findall(r'\[ebp\], (0x[0-9a-f]+)', s)]
                fn = int(re.search(r'\[ebp \+ 0x1c\], (0x[0-9a-f]+)', s).group(1), 16)
                dats = [int(x, 16) for x in re.findall(r'push (0x4[89][0-9a-f]{4})\b', ' '.join(body[k + 1:]))]
                # result store must go to +0x18 first, then arguments in order from +0x10
                stores = re.findall(r'mov byte ptr \[ebp \+ (0x[0-9a-f]+)\], al', s)
                want = ['0x18'] + ['0x%x' % (0x10 + x) for x in range(len(dats) - 1)]
                assert stores == want, (hex(off), stores, want)
                assert len(vts) == 2 and vft[vts[0]].startswith('Method') and vft[vts[1]].startswith('Closure'), hex(off)
                assert size == 0x24 and re.search(r'\[ebp \+ 0x20\], \w+', s)
                items.append(dict(k='G', name=name, vts=vts, fn=fn, dats=dats, kk=kk, off=off))
            elif re.search(r'mov ecx, (\w+) call FUN_\w+ mov dword ptr \[\1\], 0x[0-9a-f]+ mov dword ptr \[\1 \+ 0x20\], \w+ ', s):
                m = re.search(r'push (0x[0-9a-f]+) push (0x[0-9a-f]+) mov ecx, (\w+) call (FUN_\w+) mov dword ptr \[\3\], (0x[0-9a-f]+)', s)
                items.append(dict(k='M', fn=int(m.group(1), 16), name=int(m.group(2), 16), ctor=m.group(4),
                                  vt=int(m.group(5), 16), off=off))
            else:
                m = re.search(r'((?:push \w+ )+)mov ecx, eax call (FUN_\w+)', s)
                assert m, (hex(off), s)
                pushes = re.findall(r'push (\w+)', m.group(1))
                items.append(dict(k='E', size=size, pushes=pushes, ctor=m.group(2), off=off))
            if first is None: first = off
            i = j + 1
            continue
        if t == 'call FUN_001d4c90':
            started = True
        if first is not None or started:
            j = i
            while j < n and not ins[j][1].startswith('call'):
                j += 1
            s = ' '.join(x[1] for x in ins[i:j + 1])
            m = re.match(r'((?:push (?:0x[0-9a-f]+|e[a-ds][xip]) )+)mov ecx, (?:edi|esi|ebx|ebp) call (FUN_\w+)$', s) if j < n else None
            if m and 'FUN_001d' not in m.group(2):
                pushes = re.findall(r'push (\w+)', m.group(1))
                for take in (3, 2):
                    if len(pushes) >= take:
                        try:
                            classify(pushes[-take:], strings, funcs)
                            break
                        except SystemExit:
                            continue
                else:
                    raise SystemExit('cannot classify O at 0x%x: %s' % (off, s))
                if first is None: first = off
                items.append(dict(k='O', pushes=pushes[-take:], ctor=m.group(2), off=off))
                i = j + 1
                continue
            if first is not None and t != 'call FUN_001d4c90':
                break
        i += 1
    return items, first


def classify(pushes, strings, funcs):
    """Argument kinds in call order (pushes are right to left)."""
    kinds = []
    for p in pushes:
        if re.match(r'e[a-ds][xip]$', p): kinds.append('o')
        else:
            v = int(p, 16)
            if v in strings: kinds.append('n')
            elif v in funcs or v < 0x400000: kinds.append('f')
            else: raise SystemExit('cannot classify push ' + p)
    return kinds[::-1]


def gen(addr, tmpl):
    ins, strings, vft, funcs = parse_packet(packet(addr))
    items, first = find_items(ins, strings, vft, funcs)
    owner = None
    dat_of = {}          # type -> DAT address
    arities, alias_types = set(), set()
    entry, reg_o, raws = {}, {}, {}
    lines, spec_types, glue_types = [], {}, set()

    def sname(a): return strings[a]

    for it in items:
        k = it['k']
        if k == 'G':
            km, n, args = parse_vft(vft[it['vts'][1]])
            kmm, nm, argsm = parse_vft(vft[it['vts'][0]])
            assert args == argsm and n == nm == it['kk'], hex(it['off'])
            owner = owner or args[0]
            assert owner == args[0]
            types = args[1:]
            real = types[:1] + types[1:]
            if n == 0: assert len(it['dats']) == 1
            else: assert len(it['dats']) == n + 1, hex(it['off'])
            for t, d in zip(types, it['dats']):
                assert dat_of.setdefault(t, d) == d, (t, hex(d), hex(dat_of[t]))
                alias_types.add(t)
            arities.add(n)
            glue_types.add((n, tuple(args)))
            lines.append('G%d(%s, %08x%s)' % (n, '"%s"' % sname(it['name']), it['fn'],
                         ''.join(', ' + args_to_alias(t) for t in types)))
        elif k == 'E':
            kinds = classify(it['pushes'], strings, funcs)
            assert kinds in (['n', 'o', 'f'], ['n', 'f']), (hex(it['off']), kinds)
            nm = [p for p in it['pushes'] if not re.match(r'e[a-ds][xip]$', p) and int(p, 16) in strings][0]
            fn = [p for p in it['pushes'] if not re.match(r'e[a-ds][xip]$', p) and int(p, 16) not in strings][0]
            entry[(it['ctor'], tuple(kinds))] = it['size']
            lines.append('E%s(%s, %s, %08x)' % ('' if 'o' in kinds else 'F', '"%s"' % sname(int(nm, 16)),
                         it['ctor'][4:], int(fn, 16)))
        elif k == 'O':
            kinds = classify(it['pushes'], strings, funcs)
            assert kinds in (['n', 'o', 'f'], ['n', 'f']), (hex(it['off']), kinds)
            nm = [p for p in it['pushes'] if not re.match(r'e[a-ds][xip]$', p) and int(p, 16) in strings][0]
            fn = [p for p in it['pushes'] if not re.match(r'e[a-ds][xip]$', p) and int(p, 16) not in strings][0]
            reg_o[(it['ctor'], tuple(kinds))] = 1
            lines.append('O%s(%s, %s, %08x)' % ('' if 'o' in kinds else 'F', '"%s"' % sname(int(nm, 16)),
                         it['ctor'][4:], int(fn, 16)))
        elif k == 'M':
            km, n, args = parse_vft(vft[it['vt']])
            assert km == 'Closure'
            owner = owner or args[0]
            raws[it['ctor']] = 1
            spec_types[(n, tuple(args))] = 1
            lines.append('M%d(%s, %s, %08x%s)' % (n, '"%s"' % sname(it['name']), it['ctor'][4:], it['fn'],
                         ''.join(', ' + args_to_alias(t) for t in args[1:])))
    arities_m = {n for n, _ in spec_types}
    for key in spec_types:
        assert key not in glue_types, 'type used by both G and M: %r' % (key,)

    o = []
    t_ = open(tmpl).read()
    mo = re.search(r'//@owner (\w+)', t_)
    ow = owner or (mo.group(1) if mo else 'Unused')
    o.append('// FUN_%s @ %s  (generated by tools/equiv_gen/inlined_regs.py)' % (addr[2:], addr))
    o.append('typedef unsigned int size_t;')
    o.append('void* operator new(size_t) throw();')
    o.append('inline void* operator new(size_t, void* p) throw() { return p; }')
    o.append('void* FUN_0008d690(unsigned int);')
    o.append('char FUN_001d04d0(const void*) throw();')
    o.append('class %s;' % ow)
    o.append('namespace math { class Vector { public: float x, y, z; }; }')
    o.append('typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;')
    o.append('typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;')
    used = set(dat_of) | {a for _, args in spec_types for a in args[1:]}
    for t in sorted(used):
        if t not in BASE_ALIAS:
            o.append('typedef %s %s;' % (t, args_to_alias(t)))
    o.append('extern char ' + ', '.join('DAT_%08x' % d for d in sorted(set(dat_of.values()))) + ';')
    for t, d in sorted(dat_of.items(), key=lambda x: x[1]):
        o.append('#define t%s DAT_%08x' % (args_to_alias(t), d))
    o.append('class Base { public: virtual void v(); char p[12]; char a[8]; char result; char z[3]; Base(const char*, int) throw(); };')
    for n in sorted(arities | arities_m):
        tp = ''.join(', class A%d' % i for i in range(1, n + 1))
        ta = ''.join(', A%d' % i for i in range(1, n + 1))
        params = ''.join(', const void* a%d' % i for i in range(1, n + 1))
        init = ''.join(' a[%d] = FUN_001d04d0(a%d);' % (i - 1, i) for i in range(1, n + 1))
        o.append('template<class C, class R%s> class Method%d : public Base { public: void (*f)(); '
                 'Method%d(const char* n, void (*x)(), const void* r%s) : Base(n, %d) { f = x; result = FUN_001d04d0(r);%s } '
                 'virtual void v(); };' % (tp, n, n, params, n, init))
        cp = ''.join(', const void* a%d' % i for i in range(1, n + 1))
        ca = ''.join(', a%d' % i for i in range(1, n + 1))
        o.append('template<class C, class R%s> class Closure%d : public Method%d<C, R%s> { public: C* owner; '
                 'Closure%d(const char* n, C* o, void (*f)(), const void* r%s) : Method%d<C, R%s>(n, f, r%s) { owner = o; } '
                 'virtual void v(); };' % (tp, n, n, ta, n, cp, n, ta, ca))
    for (n, args) in sorted(spec_types):
        # closure whose Method part was built out of line: just a vptr and the owner
        o.append('template<> class Closure%d<%s> { public: virtual void v(); char pad[0x1c]; %s* owner; '
                 'Closure%d(%s* o) { owner = o; } };' % (n, ', '.join(args), ow, n, ow))
    rr = ['class Registry { public:', '    void FUN_001d3b70(const char*, void*);']
    for (c, kinds), _ in sorted(reg_o.items()):
        rr.append('    void %s(const char*, %svoid (*)());' % (c, ow + '*, ' if 'o' in kinds else ''))
    rr.append('};')
    o.extend(rr)
    ee = ['class Entry { public:']
    for (c, kinds), _ in sorted(entry.items()):
        ee.append('    void* %s(const char*, %svoid (*)());' % (c, ow + '*, ' if 'o' in kinds else ''))
    ee.append('};')
    o.extend(ee)
    for c in sorted(raws):
        o.append('class Raw_%s { public: void %s(const char*, void (*)()); };' % (c[4:], c))
    o.append('Registry* FUN_001d4c90();')
    o.append('#define FN(b) extern void FUN_##b();')
    for n in sorted(arities):
        ta = ''.join(', A%d' % i for i in range(1, n + 1))
        tp = ''.join(', A%d' % i for i in range(1, n + 1))
        ds = ''.join(', &t##A%d' % i for i in range(1, n + 1))
        o.append('#define G%d(n, b, R%s) { FN(b) r->FUN_001d3b70(n, new Closure%d<%s, R%s>(n, this, FUN_##b, &t##R%s)); }'
                 % (n, tp, n, ow, ta, ds))
    for n in sorted(arities_m):
        ta = ''.join(', A%d' % i for i in range(1, n + 1))
        o.append('#define M%d(n, c, b, R%s) { FN(b) void* m = FUN_0008d690(0x24); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, FUN_##b); '
                 'x = new (m) Closure%d<%s, R%s>(this); } r->FUN_001d3b70(n, x); }' % (n, ta, n, ow, ta))
    if any('o' in k for (_, k) in entry):
        o.append('#define E(n, c, b) { FN(b) Entry* e = (Entry*)FUN_0008d690(0x24); void* x = 0; if (e) x = e->FUN_##c(n, this, FUN_##b); r->FUN_001d3b70(n, x); }')
    if any('o' not in k for (_, k) in entry):
        sz = [v for (_, k), v in entry.items() if 'o' not in k][0]
        o.append('#define EF(n, c, b) { FN(b) Entry* e = (Entry*)FUN_0008d690(0x%x); void* x = 0; if (e) x = e->FUN_##c(n, FUN_##b); r->FUN_001d3b70(n, x); }' % sz)
    if any('o' in k for (_, k) in reg_o):
        o.append('#define O(n, c, b) { FN(b) r->FUN_##c(n, this, FUN_##b); }')
    if any('o' not in k for (_, k) in reg_o):
        o.append('#define OF(n, c, b) { FN(b) r->FUN_##c(n, FUN_##b); }')
    decls = '\n'.join(o)
    t = t_
    assert '@@DECLS@@' in t and '@@REGS@@' in t
    return t.replace('@@DECLS@@', decls).replace('@@REGS@@', '\n'.join(lines)), len(items), first


if __name__ == '__main__':
    addr, tmpl = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else os.path.join(ROOT, '../../build/farm/bench/claude-equiv/work', addr + '.cpp')
    src, n, first = gen(addr, tmpl)
    open(out, 'w').write(src)
    print('%s: %d registrations, first at 0x%x -> %s' % (addr, n, first, out))
