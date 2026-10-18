// STATUS: equivalent (tools/equiv.py level 3: 3074 inputs, branch coverage 23/24, incomplete)
// FUN_0027a160 @ 0x0027a160
// FUN_0027a160 @ 0x0027a160
typedef unsigned int U_27a160;
struct Table_27a160 { U_27a160 size; U_27a160 *entries; };
// equiv-conv: FUN_0027a0f0 ecx eax esi
U_27a160 FUN_0027a0f0(U_27a160 count, U_27a160 tag, unsigned char *dst);
// equiv-conv: FUN_00279f80 ecx stack stack stack stack stack
U_27a160 FUN_00279f80(U_27a160 length, const unsigned char *src, U_27a160 position, U_27a160 *distance, U_27a160 *run, Table_27a160 *table);
// equiv-conv: FUN_0027a050 ecx stack stack stack stack
U_27a160 FUN_0027a050(U_27a160 position, const unsigned char *src, U_27a160 length, U_27a160 *distance, U_27a160 *run);
void __cdecl FUN_0027a160(const unsigned char *src, U_27a160 length, unsigned char *dst, U_27a160 *written, U_27a160 tableSize, Table_27a160 *table, unsigned char fast) {
 table->size=tableSize; table->entries=(U_27a160 *)(table+1);
 table->entries[tableSize*3+2]=0; table->entries[0]=tableSize;
 table->entries[2]=~0U; table->entries[1]=~0U;
 U_27a160 position=0, output=0, start=0, literals=0, distance, run=0, state=~0U;
 if (!length) { *written=0; return; }
 for (;;) {
  if (run>4 && (distance&15)!=0) {
   if (literals) {
    output+=FUN_0027a0f0(literals, state&~255U, dst+output);
    U_27a160 j=0;
    for (;j+4<=literals;j+=4) *(U_27a160 *)(dst+output+j)=*(const U_27a160 *)(src+start+j);
    for (;j<literals;++j) dst[output+j]=src[start+j];
    output+=literals; state=literals;
   }
   output+=FUN_0027a0f0(run, (state&~255U)|((distance<<4)&255), dst+output);
   dst[output++]=(unsigned char)(distance>>4);
   state=run;
   if (fast) position+=run;
   else { U_27a160 remaining=run; if(remaining) do { ++position; state=FUN_00279f80(length,src,position,&distance,&run,table); } while (--remaining); }
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
  U_27a160 n=literals; output+=FUN_0027a0f0(n, n&~255U, dst+output);
  U_27a160 j=0;
  for(;j+4<=n;j+=4) *(U_27a160 *)(dst+output+j)=*(const U_27a160 *)(src+start+j);
  for(;j<n;++j) dst[output+j]=src[start+j];
  output+=n;
 }
 *written=output;
}
