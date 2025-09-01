#include <iostream>
#include <iomanip>
#include <sys/utsname.h>




int main()
{
	std::cout << "------------ GNU ------------" << std::endl;
	std::cout << std::left;
	std::cout << std::setw(15) << "GNU version: " << __GNUC__ << " : " << __GNUC_MINOR__ << " : " << __GNUC_PATCHLEVEL__ <<  std::endl;
	std::cout << std::setw(15) << "c++ version: " << __cplusplus << std::endl;
	
	std::cout << "------------ operating system ------------" << std::endl;
	struct utsname info;
	if(uname(&info) == 0)
	{
		std::cout <<  std::setw(15) << "OS: " << info.sysname << std::endl;
		std::cout <<  std::setw(15) << "release: " << info.release << std::endl;
		std::cout <<  std::setw(15) << "version: " << info.version << std::endl;
		std::cout <<  std::setw(15) << "architecture: " << info.machine << std::endl;
	}
}
