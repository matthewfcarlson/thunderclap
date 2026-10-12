namespace pure3d {
struct pddiBaseContext { unsigned int vfunc_89(unsigned int); };
struct d3dContext : pddiBaseContext {
 char pad[0x424];
 unsigned int field424, field428, field42c, field430, field434, field438, field43c, field440, field444, field448;
 unsigned int vfunc_89(unsigned int);
};
unsigned int d3dContext::vfunc_89(unsigned int selector) {
 switch(selector) {
 case 0x101: return field424;
 case 0x102: return field434;
 case 0x103: return field43c;
 case 0x104: return field440;
 case 0x105: return field444;
 case 0x106: return field448;
 case 0x500001: return field428;
 case 0x500002: return field438;
 case 0x500004: return field42c;
 case 0x500005: return field430;
 default: return pddiBaseContext::vfunc_89(selector);
 }
}
}