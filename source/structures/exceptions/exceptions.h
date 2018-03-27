#ifndef MY_EXCEPTIONS
#define MY_EXCEPTIONS

#include <exception>
#include <string>
#include <sstream>

namespace my_lib{
	namespace exception{

	struct empty_exception : public std::exception{
		empty_exception(std::string what){
			std::stringstream ss;	
			ss << "The acessed element is empty: " << what;
			wh = ss.str();
		}

		std::string what(){
			return wh;
		}

		private:
		std::string wh;

	};
	struct noNextException : public std::exception{
		noNextException(std::string what){
			std::stringstream ss;
			ss << "the iterator has no next to be acessed" << what;
			wh = ss.str();	
		}

		std::string what() {
			return wh;
		}
		private:
		std::string wh;
	};
	}
}


#endif
