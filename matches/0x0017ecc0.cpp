extern void* __cdecl alloc(unsigned int);
class Track {
public:
  void Init();
  int vfptr;
  int a4;
  int a8;
  int a12;
  int a16;
  unsigned char flag;
};
void* __cdecl make_track() {
  Track* p = (Track*)alloc(0x18);
  if (p) {
    p->Init();
    p->flag = 1;
    p->a8 = 1;
    p->vfptr = 0x417d18;
    p->a12 = 0;
    p->a16 = 0xbf800000;
    return p;
  }
  return 0;
}
