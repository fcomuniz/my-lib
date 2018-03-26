#ifndef MY_EXCEPTIONS
#define MY_EXCEPTIONS

#include <exception>
#include <string>

struct empty_exception : public std::exception{
	empty_exception(std::string what): wh(what){
					
	}

	std::string what(){
		return wh;
	}

	private:
	std::string wh;

};

#endif
