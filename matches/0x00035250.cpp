struct Blk { unsigned int d[16]; };
class Source { public: void* Get(); };
class Image { public: Blk* Data(); };
class C {
public:
  char pad[0x10];
  Source* member;
  void Run(unsigned int* p);
  void Finish(Blk* b);
};
void C::Run(unsigned int* p) {
  Blk local;
  void* x = member->Get();
  if (x) {
    Image* q = (Image*)((char*)x + 0x10);
    Blk* src = q->Data();
    local = *src;
  }
  local.d[12] = p[0];
  local.d[13] = p[1];
  local.d[14] = p[2];
  Finish(&local);
}
