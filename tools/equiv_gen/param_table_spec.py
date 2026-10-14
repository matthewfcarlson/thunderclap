import sys,re,subprocess,json
a=sys.argv[1]
t=subprocess.run(['build/venv/bin/python','tools/packet.py','show',a],capture_output=True,text=True).stdout
ctor={'00234a90':'Name','00234c00':'Script','002348e0':'IntConstRange','00234e50':'Vector','00234960':'FloatConstRange','00234cc0':'EnumConstList','00234860':'Bool','002349e0':'String','00235170':'Branch','00234ba0':'NameConstList'}
data=dict(re.findall(r'^\s+(0x[0-9a-f]+) = (.*)$',t,re.M))
asm=re.findall(r'^\s+[0-9a-f]{4}  (.*)$',t,re.M)
items=[];cur=None;vf=None
cls=None
for i,l in enumerate(asm):
    m=re.match(r'call FUN_(0023[45][0-9a-f]{3})$',l)
    if m and m.group(1) in ctor:
        nm=re.match(r'push (0x[0-9a-f]+)',asm[i-2]).group(1)
        cur=[ctor[m.group(1)],data[nm].strip('"'),None,nm]
    m=re.match(r'mov dword ptr \[esi \+ 0x10\], (0x[0-9a-f]+)',l)
    if m and cur and cur[0]=='EnumConstList': enumsym=m.group(1)[2:]
    elif m and cur: cur[2]=m.group(1)[2:]; items.append(cur[:3]); cur=None
    m=re.match(r'mov edi, dword ptr \[(0x[0-9a-f]+)\]',l)
    if m: enumcount=m.group(1)[2:].zfill(8)
    m=re.match(r'mov dword ptr \[esi \+ 0x14\], (\d+)',l)
    if m and cur and cur[0]=='EnumConstList': enumcount=m.group(1)
    m=re.match(r'mov dword ptr \[esi \+ 0x18\], (0x[0-9a-f]+)',l)
    if m and cur and cur[0]=='EnumConstList': cur[2]=m.group(1)[2:]; items.append(cur[:3]); cur=None
    m=re.match(r'mov dword ptr \[esi\], (0x[0-9a-f]+)',l)
    if m:
        v=data[m.group(1)]; mm=re.search(r'<class ([\w:]+)>',v); cls=mm.group(1)
    m=re.match(r'push (0x[0-9a-f]+)$',l)
    if m and i+1<len(asm) and asm[i+1].startswith('call FUN_002347b0'): reg=m.group(1)[2:]
    m=re.match(r'inc dword ptr \[(0x[0-9a-f]+)\]',l)
    if m: cnt=m.group(1)[2:]
parts=cls.split('::')
prefix = parts[0]=='hulkfight'
ns=parts[1:-1] if prefix else parts[:-1]
sp={'fn':a[2:],'cls':parts[-1],'ns':ns,'prefix':prefix,'reg':reg.zfill(8),'cnt':cnt.zfill(8),'items':items}
# enum
if any(i[0]=='EnumConstList' for i in items): sp.update(enumsym=enumsym.zfill(8),enumcount=enumcount,enumcount_n=int(enumcount) if str(enumcount).isdigit() else 1)
json.dump(sp,sys.stdout)
