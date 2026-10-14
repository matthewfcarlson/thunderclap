import sys,json
# usage: gen.py spec.json   spec: {fn, cls, ns:[...], items:[[ty,name,setter]], reg, cnt, enumsym, enumcount}
sp=json.load(open(sys.argv[1]))
cls=sp['cls']; ns=sp['ns']; items=sp['items']; fn=sp['fn']
addr={'Name':'00234a90','Script':'00234c00','IntConstRange':'002348e0','Vector':'00234e50','FloatConstRange':'00234960','EnumConstList':'00234cc0','Bool':'00234860','String':'002349e0','Branch':'00235170','ConditionGroup':'00235220','NameConstList':'00234ba0'}
full="::".join(["hulkfight"]+ns) if sp.get('prefix','hulkfight') else "::".join(ns)
nsopen="".join(f"namespace {n} {{\n" for n in (["hulkfight"]+ns if sp.get('prefix','hulkfight') else ns))
nsclose="}\n"*len(["hulkfight"]+ns if sp.get('prefix','hulkfight') else ns)
o=["inline void* operator new(unsigned int, void* p) throw() { return p; }","void* FUN_0008d690(unsigned int size);","",nsopen+f"class {cls} {{","public:"]
for ty,n,s in items: o.append(f"    void FUN_{int(s,16):08x}();")
o.append("};\n"+nsclose)
for ty in sorted(set(i[0] for i in items)):
    o.append(f"""class __declspec(novtable) Param{ty}Base {{
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_{addr[ty]}(const char* name);
    Param{ty}Base(const char* name) {{ FUN_{addr[ty]}(name); }}
}};""")
o.append("namespace fight {")
for ty in sorted(set(i[0] for i in items)):
    if ty=="EnumConstList":
        o.append(f"""template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {{
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) {{ count = c; names = n; setter = s; }}
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
}};""")
    else:
        o.append(f"""template <class T>
class Param{ty} : public Param{ty}Base {{
public:
    Param{ty}(const char* name, void (T::*s)()) : Param{ty}Base(name) {{ setter = s; }}
    virtual void v0();
    void (T::*setter)();
    int unused14;
}};""")
o.append("}\n")
o.append(f"struct ParamRegistry {{\n}};\nextern ParamRegistry DAT_{sp['reg']};\nextern int DAT_{sp['cnt']};\n")
if sp.get('enumsym'):
    o.append(f"extern const char* DAT_{sp['enumsym']}[{sp.get('enumcount_n',1)}];\n")
    if str(sp['enumcount']).startswith('DAT_'): o.append(f"extern int {sp['enumcount']};\n")
o.append("void FUN_002347b0(ParamRegistry* reg, void** params, int count);\n")
N=len(items)
o.append(f"void FUN_{fn}()\n{{\n    if (DAT_{sp['cnt']} == 0) {{\n        void* params[{N}];\n        void* mem;")
for i,(ty,n,s) in enumerate(items):
    sz="0x20" if ty=="EnumConstList" else "0x18"
    if ty=="EnumConstList":
        ec=sp['enumcount']  # a decimal literal, or DAT_xxxxxxxx for a count read from a global
        ctor=f'fight::ParamEnumConstList<{full}::{cls}>("{n}", DAT_{sp["enumsym"]}, {ec}, &{full}::{cls}::FUN_{int(s,16):08x})'
    else:
        ctor=f'fight::Param{ty}<{full}::{cls}>("{n}", &{full}::{cls}::FUN_{int(s,16):08x})'
    o.append(f"        mem = FUN_0008d690({sz});\n        params[{i}] = 0;\n        if (mem)\n            params[{i}] = new (mem) {ctor};")
o.append(f"        FUN_002347b0(&DAT_{sp['reg']}, params, {N});\n    }}\n    DAT_{sp['cnt']}++;\n}}")
open(f'build/farm/bench/claude-equiv/work/0x{fn}.cpp','w').write('\n'.join(o)+'\n')
