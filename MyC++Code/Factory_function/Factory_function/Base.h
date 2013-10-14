
class Base
{
public:

	virtual int getInt()=0;
	static Base* create(int i);
};