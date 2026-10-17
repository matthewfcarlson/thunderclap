// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0029e640 @ 0x0029e640
struct ItemList { char pad[0x10]; int capacity; int count; void** items; }; void __stdcall FUN_002a1180(int); void __stdcall FUN_0029e640(ItemList* list) { if (!list) return; int n=0; while (n < list->count && n < list->capacity && list->items[n]) ++n; FUN_002a1180(n); }