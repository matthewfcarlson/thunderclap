// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 9/10, incomplete)
// FUN_0026e140 @ 0x0026e140
typedef unsigned int uint;
struct Entry { char data[0x108]; uint length; Entry* next; };
struct Allocator { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Entry* allocate(uint); };
int __cdecl FUN_0026ef40(void*, const void*, uint, int);
struct Handler {
 char pad0[0x68]; char buffer[0x58]; int state; Allocator* allocator; Entry* head;
 void FUN_0026e0e0(); void FUN_0026e030();
 void target(const void* source, uint length);
};
void Handler::target(const void* source, uint length) {
 if (state == 3) {
  if (FUN_0026ef40(buffer, source, length, 0) < 0) { FUN_0026e0e0(); FUN_0026e030(); }
  return;
 }
 Entry* item = allocator->allocate(length);
 unsigned char* dest = (unsigned char*)item;
 for (uint i = 0; i < 0x110; ++i) dest[i] = 0;
 const unsigned char* src = (const unsigned char*)source;
 for (uint j = 0; j < length; ++j) dest[j] = src[j];
 item->length = length;
 if (!head) { head = item; return; }
 Entry* tail = head;
 while (tail->next) tail = tail->next;
 tail->next = item;
}
