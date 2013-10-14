#include "Derived.h"
Base* Base::create(int i)
{

	return new Derived(i);
}