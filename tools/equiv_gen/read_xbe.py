import sys
sys.path.insert(0,'tools')
from xbe import Xbe
x=Xbe('isos/extracted/default.xbe')
va=int(sys.argv[1],16); n=int(sys.argv[2])
o=x.offset(va)
d=x.data[o:o+n]
for i in range(0,n,4): print(hex(va+i), hex(int.from_bytes(d[i:i+4],'little')))
