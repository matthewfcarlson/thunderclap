class Node { public: virtual void a0(); virtual void a1(); virtual Node* a2(Node*, Node*); virtual Node* a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual Node* a8(); };
class Entity { public: virtual void a0(); virtual void a1(); virtual void a6(); virtual void a7(); virtual void a8(); };
class MetaEntity : public Entity { public: virtual Node* a2(Node*,Node*); virtual Node* a3(); virtual void a4(); virtual void vfunc_5(Node*); };
void MetaEntity::vfunc_5(Node* arg) { Node* p = ((Node*)this)->a8(); Node* q = p->a3(); q->a2(arg,(Node*)this); }