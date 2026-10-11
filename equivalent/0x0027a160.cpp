// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 23/24, incomplete)
// FUN_0027a160 @ 0x0027a160
typedef unsigned int U;
struct Table { U size; U *entries; };
// equiv-conv: FUN_0027a0f0 esi ecx eax
U FUN_0027a0f0(unsigned char *dst, U count, U tag);
// equiv-conv: FUN_00279f80 ecx stack stack stack stack stack
U FUN_00279f80(U length, const unsigned char *src, U position, U *distance, U *run, Table *table);
// equiv-conv: FUN_0027a050 ecx stack stack stack stack
U FUN_0027a050(U position, const unsigned char *src, U length, U *distance, U *run);
void __cdecl FUN_0027a160(const unsigned char *src, U length, unsigned char *dst, U *written, U tableSize, Table *table, unsigned char fast) {
 table->size=tableSize; table->entries=(U *)(table+1);
 table->entries[tableSize*3+2]=0; table->entries[0]=tableSize;
 table->entries[2]=~0U; table->entries[1]=~0U;
 U position=0, output=0, start=0, literals=0, distance, run=0, state=~0U;
 if (!length) { *written=0; return; }
 for (;;) {
  if (run>4 && (distance&15)!=0) {
   if (literals) {
    output+=FUN_0027a0f0(dst+output,literals,state&~255U);
    U j=0;
    for (;j+4<=literals;j+=4) *(U *)(dst+output+j)=*(const U *)(src+start+j);
    for (;j<literals;++j) dst[output+j]=src[start+j];
    output+=literals; state=literals;
   }
   output+=FUN_0027a0f0(dst+output,run,(state&~255U)|((distance<<4)&255));
   dst[output++]=(unsigned char)(distance>>4);
   state=run;
   if (fast) position+=run;
   else { U remaining=run; if(remaining) do { ++position; state=FUN_00279f80(length,src,position,&distance,&run,table); } while (--remaining); }
   literals=0; start=position;
   if (fast) state=FUN_00279f80(length,src,position,&distance,&run,table);
  } else {
   ++literals; ++position;
   state=FUN_00279f80(length,src,position,&distance,&run,table);
   if (!fast && (unsigned char)state) state=FUN_0027a050(position,src,length,&distance,&run);
  }
  if (position>=length) break;
 }
 if(literals) {
  U n=literals; output+=FUN_0027a0f0(dst+output,n,n&~255U);
  U j=0;
  for(;j+4<=n;j+=4) *(U *)(dst+output+j)=*(const U *)(src+start+j);
  for(;j<n;++j) dst[output+j]=src[start+j];
  output+=n;
 }
 *written=output;
}
