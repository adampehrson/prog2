#include <cstdlib>
// Integer class 

class Heltal{
	public:
		Heltal(int);
		int get();
		void set(int);
		int getfib();
		int fibcalc(int);
	private:
		int val;
		int fibnr;
	};
 
Heltal::Heltal(int n){
	val = n;
	fibnr = fibcalc(n);
	}
 
int Heltal::get(){
	return val;
	}
 
void Heltal::set(int n){
	val = n;
	}
	

// Methods for calculating fibonacci series for a value in heltal.

int Heltal::fibcalc(int){
	if(Heltal::get()<=1){
		return Heltal::get();
	}

	else{
		return Heltal::fibcalc(Heltal::get() - 1) + Heltal::fibcalc(Heltal::get() - 2);
	}
}

int Heltal::getfib(){
	return fibnr;
}


extern "C"{
	Heltal* Heltal_new(int n) {return new Heltal(n);}
	int Heltal_get(Heltal* heltal) {return heltal->get();}

	//Bridging code between python and c++
	int Heltal_fib(Heltal* heltal) {return heltal->getfib();}
	
	void Heltal_set(Heltal* heltal, int n) {heltal->set(n);}
	void Heltal_delete(Heltal* heltal){
		if (heltal){
			delete heltal;
			heltal = nullptr;
			}
		}
	}