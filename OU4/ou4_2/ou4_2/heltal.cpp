#include <cstdlib>
// Integer class 

class Heltal{
	public:
		Heltal(int);
		int get();
		void set(int);
		int getfib();
		
	private:
		int val;
		int fibcalc(int);
	};
 
Heltal::Heltal(int n){
	val = n;
	
	}
 
int Heltal::get(){
	return val;
	}

int Heltal::getfib(){
	return fibcalc(Heltal::get());
}
 
void Heltal::set(int n){
	val = n;
	}
	

// Method for calculating fibonacci series for a value in heltal.

int Heltal::fibcalc(int n){
	if(n<=1){
		return n;
	}

	else{
		return Heltal::fibcalc(n - 1) + Heltal::fibcalc(n - 2);
	}
}




extern "C"{
	Heltal* Heltal_new(int n) {return new Heltal(n);}
	int Heltal_get(Heltal* heltal) {return heltal->get();}

	//Bridging code between python and c++
	int Heltal_getfib(Heltal* heltal) {return heltal->getfib();}
	
	void Heltal_set(Heltal* heltal, int n) {heltal->set(n);}
	void Heltal_delete(Heltal* heltal){
		if (heltal){
			delete heltal;
			heltal = nullptr;
			}
		}
	}