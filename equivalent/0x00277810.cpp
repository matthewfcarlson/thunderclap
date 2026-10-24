// STATUS: equivalent (tools/equiv.py level 3: 3074 inputs, branch coverage 29/30; --wine 674 inputs)
// core::CementLibrary::vfunc_3_adj4 @ 0x00277810
struct Callback_277810 { virtual void s0(); virtual void release(); virtual void s2(); virtual void complete(unsigned); };
struct File { virtual void s0(); virtual void s1(); virtual void s2(); virtual void read(void*,unsigned,int); virtual void s4(); virtual void seek(unsigned); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void* get(); virtual void s17(); virtual void async(void*,int); virtual void s19(); virtual void s20(); virtual void s21(); virtual unsigned status(); virtual bool ready(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void mode(int); };
struct Result_277810 { void FUN_00277630(unsigned, void*, unsigned); };
struct Owner_277810 { Result_277810* FUN_00272bc0(); void FUN_00272ba0(void*); };
void* __cdecl FUN_00266eb0(unsigned,unsigned,unsigned);
struct Whole { void FUN_00277410(int); };
struct LibraryBase { char pad0[8]; unsigned allocator; char padC[8]; Owner_277810* owner; File* file; unsigned state; unsigned char header[60]; void* buffer; char pad60[8]; Callback_277810* callback; unsigned context; void target(unsigned); };
void LibraryBase::target(unsigned step) {
 if(state==1) { state=2; if(callback) {callback->complete(context); callback->release(); callback=0; context=0;} return; }
 Whole* whole=(Whole*)((char*)this-4); void* cb=whole ? this : 0;
 if(step==0) { if(!file->ready()) {whole->FUN_00277410(2); return;} file->mode(1); file->seek(0); file->read(header,60,1); file->async(cb,1); }
 else if(step==1) { if(file->status()!=0) return; const char* magic="ATG CORE CEMENT LIBRARY"; bool valid=true; for(unsigned i=0;i<24;++i) if(header[i]!=(unsigned char)magic[i]) {valid=false; break;} if(header[32]!=2 || header[35]==0 || header[33]>=2 || header[34]!=0) valid=false;
 if(!valid) {whole->FUN_00277410(2); return;} buffer=FUN_00266eb0(allocator,*(unsigned*)(header+40),16); file->seek(*(unsigned*)(header+36)); file->read(buffer,*(unsigned*)(header+40),1); file->async(cb,2);
 } else if(step==2) { if(file->status()!=0) {whole->FUN_00277410(2); return;} file->mode(0); if(*(unsigned*)(header+52)>0) {unsigned a=allocator; void* gp=file->get(); owner->FUN_00272bc0()->FUN_00277630(a, gp, 16);} owner->FUN_00272ba0(whole); whole->FUN_00277410(1); }
}
