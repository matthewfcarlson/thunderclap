struct A { A* f592a0(); A* f59a30(); void f37120(int); };
class IntentionClearAction { public: char pad[0x20]; A* field; void vfunc_4(); };
void IntentionClearAction::vfunc_4() { A* x = field->f592a0(); x = x->f59a30(); x->f37120(0); }