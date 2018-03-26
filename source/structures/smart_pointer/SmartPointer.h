
template<class T>
struct SmartPointerHelper {

	T * obj;
	int counts;
};

template<class T>
class SmartPointer{
	public:
		SmartPointer() : helper(nullptr){
			
		}
		SmartPointer(T* newValue){
			helper = new SmartPointerHelper();	
			helper->count = 1;
			helper->obj = newValue;
		}
		SmartPointer(const SmartPointer & p){
			helper = p.helper;
			if(helper != nullptr){
				helper->count++;
			}	
		}
		SmartPointer(SmartPointer && p){
			helper = p.helper;
			p.helper = nullptr;
		}
		
		virtual ~SmartPointer(){
			removeIfShould();
		}

		const SmartPointer & operator=(const SmartPointer & p){
			removeIfShould();	
			helper = p.helper;
			if(helper != nullptr){
				helper->count++;
			}
		}
		T & operator*(){
			if(helper == nullptr){
				throw std::runtime_exception("trying to dereference empty pointer");
			} else {
				return helper->obj;
			}
		}
		
		T * operator->(){
			if(helper == nullptr){
				throw std::runtime_exception("trying to dereference empty pointer");
			} else {
				return &(helper->obj);
			}

		}

	private:
		bool checkIfShouldRemove(){
			if(helper != nullptr){
				return helper->counts == 1;
			} else {
				return false;
			}
		}
		void removeIfShould(){
			if(checkIfShouldRemove()){
				delete helper->obj;
				delete helper;
				helper = nullptr;
			}
		}


		SmartPointerHelper<T> * helper;

};

