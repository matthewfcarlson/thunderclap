// STATUS: equivalent (tools/equiv.py level 3: 11840 inputs, branch coverage 16/16; run with --inputs 12000)
// FUN_00334b00 @ 0x00334b00
extern unsigned int __cdecl FUN_00368660();
extern unsigned int __cdecl FUN_0026fd50(unsigned int, unsigned int);
struct GlobalData { char pad[8]; char data; };
extern GlobalData *DAT_00555ba8;
struct Owner;
struct Stream {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void slot3(unsigned int, unsigned int, unsigned int);
 virtual void slot4(); virtual void slot5(unsigned int);
 virtual void slot6(unsigned int *);
 virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual unsigned int slot16(); virtual void slot17();
 virtual void slot18(void *, Owner *);
};
struct Owner {
 char pad0[0x20]; unsigned int busy;
 char pad24[4]; unsigned int id;
 char pad2c[0x18]; unsigned int previous;
 unsigned int current; Stream *stream;
 unsigned int total; unsigned int offset;
 unsigned int position; unsigned int result;
 unsigned int transfer; char pad64[0xc];
 unsigned int source; unsigned int capacity;
 unsigned int savedId; unsigned int timestamp;
 unsigned char flag; char pad81[3]; unsigned int residue;
 void FUN_00334b00();
};
// equiv-conv: FUN_00334b00 esi
void Owner::FUN_00334b00() {
 if (flag == 1 || busy != 0) return;
 unsigned int remaining = offset < total ? total - offset : 0;
 unsigned int size = 0x4000;
 if (capacity < size || remaining == 0) {
  previous = current;
  return;
 }
 savedId = id;
 timestamp = FUN_00368660();
 busy = 1;
 if (remaining > size) transfer = size;
 else {
  transfer = remaining;
  size = FUN_0026fd50(remaining, stream->slot16());
 }
 unsigned int oldOffset = offset;
 unsigned int alignment = stream->slot16();
 unsigned int remainder = oldOffset % alignment;
 if (remainder) {
  residue = remainder;
  offset = oldOffset - remainder;
  position -= remainder;
 }
 stream->slot5(offset);
 stream->slot3(source, size, 1);
 stream->slot6(&result);
 if (DAT_00555ba8) stream->slot18(&DAT_00555ba8->data, this);
 else stream->slot18(0, this);
}
