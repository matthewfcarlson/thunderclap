// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 9/10, incomplete)
// FUN_0026e140 @ 0x0026e140
typedef unsigned int uint_26e140;
extern "C" void* memset(void*, int, uint_26e140);
extern "C" void* memcpy(void*, const void*, uint_26e140);
struct Entry_26e140 { char data[0x108]; uint_26e140 length; Entry_26e140* next; };
struct Allocator { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Entry_26e140* allocate(uint_26e140); };
int __cdecl FUN_0026ef40(void*, const void*, uint_26e140, int);
struct Handler_26e140 {
 char pad0[0x68]; char buffer[0x58]; int state; Allocator* allocator; Entry_26e140* head;
 void FUN_0026e0e0(); void FUN_0026e030();
 void target(const void* source, uint_26e140 length);
};
void Handler_26e140::target(const void* source, uint_26e140 length) {
 if (state == 3) {
  if (FUN_0026ef40(buffer, source, length, 0) < 0) { FUN_0026e0e0(); FUN_0026e030(); }
  return;
 }
 Entry_26e140* item = allocator->allocate(length);
 memset(item, 0, 0x110);
 memcpy(item, source, length);
 item->length = length;
 if (!head) { head = item; return; }
 Entry_26e140* tail = head;
 while (tail->next) tail = tail->next;
 tail->next = item;
}
