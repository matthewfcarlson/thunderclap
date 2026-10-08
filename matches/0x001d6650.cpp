class Object { public: char pad[0x1e8]; int value; void Set(int); };
void Object::Set(int value) { this->value = value; }