#include <iostream>
#include <boost/thread/thread.hpp>
void hello()
{
	std::cout<<"hello world,i am a thread"<<std::endl;

}
int main()
{
	boost::thread thrd(&hello);
	thrd.join();
	system("pause");
}