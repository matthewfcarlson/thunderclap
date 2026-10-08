class Reader { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); };
class BinReader { public: char pad[8]; Reader *reader; void vfunc_4(); };
void BinReader::vfunc_4() { reader->f(); }