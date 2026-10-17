// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_0024c060 @ 0x0024c060
struct Item { Item* next; char pad[0xc0]; int state; }; extern Item* DAT_004e61e8;
// equiv-conv: FUN_0024bc70 eax
void FUN_0024bc70(Item*);
void FUN_0024c060() { for (Item* item = DAT_004e61e8; item; item = item->next) { do { FUN_0024bc70(item); } while (item->state == 3); } }