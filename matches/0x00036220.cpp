class Thing { public: char pad[0x1b24]; int value; void Change(char up); };
void Thing::Change(char up) { if (up) ++value; else --value; }