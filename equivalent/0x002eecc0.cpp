// STATUS: equivalent (tools/equiv.py level 3: 27 inputs, branch coverage 18/18)
// FUN_002eecc0 @ 0x002eecc0
struct Item { virtual void slot0(); virtual void clear(); };
struct Record { unsigned value; char rest[16]; };
struct Bits { unsigned count; unsigned words[1]; };
struct State {
 Item** begin; Item** end; char pad08[8]; Bits* bits;
 unsigned* values; unsigned valueCount; char pad1c[8];
 Record* records; unsigned recordCount;
 void* begin2; void* end2; char pad34[8];
 Item** begin3; Item** end3; char pad44[8];
 void* begin4; void* end4;
 void reset();
};
void State::reset() {
 unsigned i;
 for (i=0; i<(unsigned)(end-begin); ++i) begin[i]->clear();
 end=begin;
 for(i=0;i<valueCount;++i) values[i]=0;
 valueCount=0;
 for(i=0;i<recordCount;++i) records[i].value=0;
 recordCount=0;
 for(i=0;i<(unsigned)(end3-begin3);++i) begin3[i]->clear();
 end3=begin3;
 end2=begin2;
 unsigned n=(bits->count+31u)>>5;
 unsigned* words=bits->words;
 for(i=0;i<n;++i) words[i]=0;
 end4=begin4;
}
