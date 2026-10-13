#!/usr/bin/env python3
"""Generate the parameter-reader blocks of big "read the character definition" functions (0x000464c0).

Such a function is mostly hundreds of
    lea eax, [ebx + OFF] ; push eax ; push "Name" ; mov ecx, ebp ; mov [eax], DEFAULT ; call FUN_0027aa20
i.e. `this->field = DEFAULT; props->GetFloat("Name", &this->field);` (FUN_0027aa20 float, FUN_0027a9d0 int,
FUN_0027ab00 Vec3). This script expands those blocks from the disassembly; everything else (string
copies, loops over name tables, virtual calls) is hand-written in a template.

Template markers:
    @@GEN 0xFROM 0xTO@@      the blocks in [FROM, TO) of the original (every instruction must be recognised)
    //@field 0xOFF SIZE DECL  a hand-declared member (SIZE bytes) for @@FIELDS@@
    @@FIELDS@@               members for all generated and hand-declared fields, with padding
usage: props_reader.py 0xADDR TEMPLATE [OUT]
"""
import os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from inlined_regs import parse_packet, packet, ROOT

GET = {'FUN_0027aa20': 'float', 'FUN_0027a9d0': 'int', 'FUN_0027ab00': 'vec'}


def fl(v):
    if v == 0: return '0.0f'
    f = struct.unpack('<f', struct.pack('<I', v))[0]
    if f == int(f) and abs(f) < 1e9: return '%d.0f' % int(f)
    s = '%.9g' % f
    if float(s) != f or struct.unpack('<I', struct.pack('<f', float(s)))[0] != v: s = '%.9g' % f
    if '.' not in s and 'e' not in s: s += '.0'
    return s + 'f'


def gen_range(ins, strings, lo, hi, fields):
    seq = [(o, t) for o, t in ins if lo <= o < hi]
    out, i, n = [], 0, len(seq)
    while i < n:
        off, t = seq[i]
        m = re.match(r'lea (e[acd]x), \[ebx \+ (0x[0-9a-f]+)\]$', t)
        if not m:
            raise SystemExit('unrecognised at 0x%x: %s' % (off, t))
        r, o = m.group(1), int(m.group(2), 16)
        j, pushes, stores, ecx = i + 1, [], {}, False
        while j < n and not seq[j][1].startswith('call'):
            u = seq[j][1]
            if u == 'push ' + r: pushes.append('R')
            elif re.match(r'push 0x3f', u): pushes.append(int(u.split()[1], 16))
            elif u == 'mov ecx, ebp': ecx = True
            else:
                mm = re.match(r'mov dword ptr \[%s(?: \+ ((?:0x)?[0-9a-f]+))?\], (\w+)$' % r, u)
                if not mm: raise SystemExit('unrecognised at 0x%x: %s' % (seq[j][0], u))
                stores[int(mm.group(1) or '0', 16)] = mm.group(2)
            j += 1
        c = seq[j][1].split()[1]
        assert c in GET and ecx and len(pushes) == 2, hex(off)
        name = strings[[p for p in pushes if p != 'R'][0]]
        ty = GET[c]
        val = lambda v: 0 if v == 'esi' else int(v, 16)
        field = 'f%03x' % o
        res = ''
        if i + (j - i) + 1 < n:
            mb = re.match(r'mov byte ptr \[ebx \+ (0x[0-9a-f]+)\], al$', seq[j + 1][1])
            if mb and ty == 'float':
                res = 'this->b%03x = ' % int(mb.group(1), 16)
                fields[int(mb.group(1), 16)] = (1, 'char b%03x;' % int(mb.group(1), 16))
                j += 1
        if ty == 'float':
            pre = 'this->%s = %s; ' % (field, fl(val(stores[0]))) if 0 in stores else ''
            out.append('%s%sprops->%s("%s", &this->%s);' % (pre, res, c, name, field))
            fields[o] = (4, 'float %s;' % field)
        elif ty == 'int':
            pre = 'this->%s = %d; ' % (field, val(stores[0])) if 0 in stores else ''
            out.append('%sprops->%s("%s", &this->%s);' % (pre, c, name, field))
            fields[o] = (4, 'int %s;' % field)
        else:
            pre = ''.join('this->%s.%s = %s; ' % (field, 'xyz'[k // 4], fl(val(stores[k]))) for k in sorted(stores))
            out.append('%sprops->%s("%s", &this->%s);' % (pre, c, name, field))
            fields[o] = (12, 'Vec3 %s;' % field)
        i = j + 1
    return out


def gen(addr, tmpl):
    ins, strings, vft, funcs = parse_packet(packet(addr))
    fields = {}
    text = open(tmpl).read()
    for m in re.finditer(r'//@field (0x[0-9a-f]+) (\d+|0x[0-9a-f]+) (.*)', text):
        fields[int(m.group(1), 16)] = (int(m.group(2), 0), m.group(3))
    text = re.sub(r'//@field .*\n', '', text)

    def rep(m):
        lines = gen_range(ins, strings, int(m.group(1), 16), int(m.group(2), 16), fields)
        return '\n'.join('    ' + l for l in lines)
    text = re.sub(r'[ \t]*@@GEN (0x[0-9a-f]+) (0x[0-9a-f]+)@@', rep, text)
    fl_ = []
    pos = 0
    for o in sorted(fields):
        size, decl = fields[o]
        assert o >= pos, 'overlap at 0x%x (previous ends 0x%x)' % (o, pos)
        if o > pos: fl_.append('    char pad%03x[0x%x];' % (pos, o - pos))
        fl_.append('    ' + decl)
        pos = o + size
    return text.replace('@@FIELDS@@', '\n'.join(fl_))


if __name__ == '__main__':
    addr, tmpl = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else os.path.join(ROOT, '../../build/farm/bench/claude-equiv/work', addr + '.cpp')
    open(out, 'w').write(gen(addr, tmpl))
    print('%s -> %s' % (addr, out))
