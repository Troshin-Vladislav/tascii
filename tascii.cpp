#include <iostream>

class Limit{

private:
	unsigned short int begin = 1;
	unsigned short int end = 127;

public:
	
	// contructor
	Limit(unsigned short int begin, unsigned short int end){
		this->begin = begin;
		this->end = end;
	}

	void setBegin(unsigned short int b){
		if( b > 0 ){
			this->begin = b;
		}
	}

	void setEnd(unsigned short int e){
		if( e < 128){
			this->end = e;
		}
	}

	unsigned short int getBegin(){
		return this->begin;
	}

	unsigned short int getEnd(){
		return this->end;
	}

};

int main(int argc, char *argv[]){

	Limit lim(1, 127);

	if( argc >= 2 ){
		lim.setBegin( static_cast<unsigned short int>( std::stoi(argv[1]) ) );
	}

	if( argc >= 3 ){
		lim.setEnd( std::stoi(argv[2]) );
	}

	for(unsigned short int ch = lim.getBegin(); ch < lim.getEnd() ; ch++){
		printf("%i(%X): %c\n", ch, ch, ch);
	}

	return 0;
}