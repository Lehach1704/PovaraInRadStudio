#ifndef PatternsH
#define PatternsH

#include "povara.h"

template<class Type>
class Iterator
{
protected:
	Iterator() {}

public:
	virtual ~Iterator() {}
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Type CurrentItem() const = 0;
};

template<class Type>
class Decorator : public Iterator<Type>
{
protected:
    Iterator<Type> *Iter;

public:
    Decorator(Iterator<Type> *iter) {Iter = iter;}
    virtual ~Decorator() { delete Iter; }
    void First() {Iter->First(); }
    void Next() {Iter->Next(); }
    bool IsDone() const { return Iter->IsDone(); }
    Type CurrentItem() const { return Iter->CurrentItem(); }
};

#endif // PatternsH
