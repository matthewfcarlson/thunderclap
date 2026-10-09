struct Script { char pad[0x14]; int arg; int result; };
struct Provider { int Make(int, int, int); };
struct LuaAction { char pad[0x1c]; Script* script; char pad1[4]; int value; bool vfunc_3(int, int); };
int GetThing();
bool LuaAction::vfunc_3(int a, int b) {
 int x = GetThing();
 if (!x) return false;
 Script* s = script;
 int edi = s->result;
 if (edi) {
  int edx = s->arg;
  if (edx && !value) {
   value = ((Provider*)x)->Make(edx, edi, 0);
   return true;
  }
 }
 return false;
}