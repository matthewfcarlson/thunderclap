// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 24/26, incomplete)
// FUN_001effc0 @ 0x001effc0
struct Context { unsigned int a, b; };
struct Event_1effc0 {
 virtual void slot0();
 virtual void fire(Context*, unsigned int);
 unsigned int unused;
 Event_1effc0* next;
 float time;
};
struct List_1effc0 { char pad[16]; Event_1effc0* first; int count; };
extern unsigned int DAT_004e3748;
struct Player_1effc0 {
 char pad[8];
 List_1effc0* list;
 float time;
 int completed;
 unsigned char active;
 char pad15[3];
 Context context;
 unsigned int arg;
 void FUN_001eed20();
 void FUN_001effc0(float delta);
};
void Player_1effc0::FUN_001effc0(float delta) {
 if (!active || !list) return;
 float previous = time;
 time = delta + time;
 int count = list->count;
 for (int i = 0; i < count; ++i) {
  List_1effc0* current = list;
  Event_1effc0* event = 0;
  if (i >= 0 && i < current->count) {
   event = current->first;
   for (int j = 0; event && j < i; ++j) event = event->next;
  }
  if (event && event->time >= previous && event->time <= time) {
   ++DAT_004e3748;
   event->fire(&context, arg);
   ++completed;
   if (completed == count) {
    active = 0;
    FUN_001eed20();
    return;
   }
  }
 }
}
