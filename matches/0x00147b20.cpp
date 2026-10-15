int __cdecl findThing(int);
void* __cdecl allocThing(int);
class Built {
  public:
    int init(int, void*, int, int, void*, int, int);
};
class GrappleExecuteTrack {
    char p0[0x14];
    int a;
    char p18[8];
    int b;
    int c;

  public:
    int vfunc_10(int x, int y, int z);
};
int GrappleExecuteTrack::vfunc_10(int x, int y, int z) {
    int v = findThing(z);
    if (v) {
        Built* p = (Built*)allocThing(0x68);
        if (p) {
            int bb = b;
            int aa = a;
            return p->init(x, this, aa, bb, &c, y, v);
        }
    }
    return 0;
}