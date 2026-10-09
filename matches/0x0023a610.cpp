extern "C" int __cdecl _isspace(int);
class Reader { public: virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3(); virtual int Read(); virtual void Advance(); };
class Parser { public: char pad[8]; Reader *reader; };
int __fastcall target(Parser *p) { int count=0; char c=(char)p->reader->Read(); while (_isspace((int)c) && c!='\n') { p->reader->Advance(); ++count; c=(char)p->reader->Read(); } return count; }