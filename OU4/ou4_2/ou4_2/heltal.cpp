#include <cstdlib>
// Integer class 

class Heltal{
	public:
		Heltal(int);
		int get();
		void set(int);
		int fib();
	private:
		int val;
	};
 
Heltal::Heltal(int n){
	val = n;
	}
 
int Heltal::get(){
	return val;
	}
 
void Heltal::set(int n){
	val = n;
	}
	

// Methods for calculating fibonacci series for a value in heltal.

int Heltal::fib(){
	if(Heltal::get()<=1){
		return Heltal::get();
	}

	else{
		Heltal temp1 = Heltal::Heltal(Heltal::get() - 1);
		Heltal temp2 = Heltal::Heltal(Heltal::get() - 1);
		return temp1.fib() + temp2.fib();
	}
}


extern "C"{
	Heltal* Heltal_new(int n) {return new Heltal(n);}
	int Heltal_get(Heltal* heltal) {return heltal->get();}

	//Bridging code between python and c++
	int Heltal_fib(Heltal* heltal) {return heltal->fib();}
	
	void Heltal_set(Heltal* heltal, int n) {heltal->set(n);}
	void Heltal_delete(Heltal* heltal){
		if (heltal){
			delete heltal;
			heltal = nullptr;
			}
		}
	}