int __cdecl findThing(int);
void* __cdecl allocThing(int);
class ExecuteAction_147b20 {
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
        ExecuteAction_147b20* p = (ExecuteAction_147b20*)allocThing(0x68);
        if (p) {
            int bb = b;
            int aa = a;
            return p->init(x, this, aa, bb, &c, y, v);
        }
    }
    return 0;
}