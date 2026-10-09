void Refresh();
class Thing { char pad[8]; public: char value; void Update(char); };
void Thing::Update(char x) { if (value != x) Refresh(); value = x; }