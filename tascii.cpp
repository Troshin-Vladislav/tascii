#include <iostream>
#include <stdio.h>
#include <getopt.h>

/* @init classes	*/
class Limit;
class Option;

/* @init functions	*/
void help();
void line_ascii(Limit lim, Option);
void show_tascii(Limit lim);
bool is_beetwen(int, int, int);

/*  @implements classes */
class Limit{

private:
	unsigned short int begin = 1;
	unsigned short int end = 127;
	unsigned short int bound = 10;

public:
	
	// contructor
	Limit(unsigned short int begin, unsigned short int end){
		this->begin = begin;
		this->end = end;
	}

	// setters

	void setBegin(unsigned short int b){
		if( is_beetwen(b, 0, 128) ){
			this->begin = b;
		}
	}

	void setEnd(unsigned short int e){
		if( is_beetwen(e, 0, 128) ){
			this->end = e;
		}
	}
	
	void setBound(unsigned short int b){
		if( is_beetwen(b, 1, 254) ){
			this->bound = b;
		}
	}

	// getters

	unsigned short int getBegin(){
		return this->begin;
	}

	unsigned short int getEnd(){
		return this->end;
	}

	unsigned short int getBound(){
		return this->bound;
	}

};

class Option{
	public:
		bool hex = false;
		bool dec = false;
		bool line = false;
};


int main(int argc, char *argv[]){

	Limit lim(1, 127);
	Option setting;
	int opt;
	struct option long_opt[] = {
		{"start", 1, 0, 's'},
		{"finish", 1, 0, 'f'},
		{"bound", 1, 0, 'b'},
		{"inline", 0, 0, 'i'},
		{"hex", 0, 0, 'H'},
		{"dec", 0, 0, 'D'},
		{"help", 0, 0, 'h'},
		{0, 0, 0, 0}
	};
	int opt_index;

	while( true ){
		if( ( opt = getopt_long(argc, argv, "s:f:b:ihHD", long_opt, &opt_index) ) == -1 )
			break;

		switch( opt ){
			case 's':
				lim.setBegin( std::stoi( optarg ) );
				break;
			case 'f':
				lim.setEnd( std::stoi( optarg ) );
				break;
			case 'b':
				lim.setBound( std::stoi( optarg ) );
				break;
			case 'i':
				setting.line = true;
				break;
			case 'H':
				setting.hex = true;
				break;
			case 'D':
				setting.dec = true;
				break;
			case 'h':
				help();
				break;
		}
	}

	if( setting.line ){
		line_ascii(lim, setting);
	}
	else{
		show_tascii(lim);
	}

	return 0;
}


/*  @implements functions */


/*
 * function - check number between start and end
 */
bool is_beetwen(int number, int start, int end){
	if( (number >= start) && (number <= end) )
		return true;
	else
		return false;
}

/*
 * function - print table ascii in line
 */
void line_ascii(Limit lim, Option opt){
	int cntout = 0;

	for(unsigned short int ch = lim.getBegin(); ch < lim.getEnd() ; ch++){
		
		if( cntout >= lim.getBound() ){
			std::cout << std::endl;
			cntout = 0;
		}
		
		// print digits by if
		if( opt.hex ) printf("[%X]", ch);
		if( opt.dec ) printf("(%.3i)", ch);


		switch( ch ){
			case '\0':
				printf("'\\0' ");
				break;
			case '\a':
				printf("'\\a' ");
				break;
			case '\t':
				printf("'\\t' ");
				break;
			case '\n':
				printf("'\\n' ");
				break;
			case '\v':
				printf("'\\v' ");
				break;
			case '\r':
				printf("'\\r' ");
				break;
			case 0xC:
				printf("'\\x0C' ");
				break;
			case 0xE:
				printf("'\\x0E' ");
				break;
			case 0xF:
				printf("'\\x0F' ");
				break;
			default:
				printf("'%c' ", ch);
		}

		// printf("'%c' ", ch);

		cntout++;
		
	}

	std::cout << std::endl;
}

/*
 * function - show table ascii 
 */
void show_tascii(Limit lim){
	for(unsigned short int ch = lim.getBegin(); ch < lim.getEnd() ; ch++){

		switch( ch ){
			case '\0':
				printf("%i(%X): \\0\n", ch, ch);
				break;
			case '\a':
				printf("%i(%X): \\a\n", ch, ch);
				break;
			case '\t':
				printf("%i(%X): \\t\n", ch, ch);
				break;
			case '\n':
				printf("%i(%X): \\n\n", ch, ch);
				break;
			case '\v':
				printf("%i(%X): \\v\n", ch, ch);
				break;
			case '\r':
				printf("%i(%X): \\r\n", ch, ch);
				break;
			case 0xC:
				printf("%i(%X): \\x0C\n", ch, ch);
				break;
			case 0xE:
				printf("%i(%X): \\x0E\n", ch, ch);
				break;
			case 0xF:
				printf("%i(%X): \\x0F\n", ch, ch);
				break;
			default:
				printf("%i(%X): %c\n", ch, ch, ch);
		}


	}
}

/*
 * function - print help page 
 */
void help(){
	// usage message
	std::cout << "usage: tascii [options]" << std::endl;

	// help messages
	std::cout << "  --start <int>,  -s <int>:\t" 	<< "code for start" 					<< std::endl;
	std::cout << "  --finish <int>,  -f <int>:\t" 	<< "code for finish" 					<< std::endl;
	std::cout << "  --bound <int>,  -b <int>:\t" 	<< "count char outputing on console" 	<< std::endl;
	std::cout << "  --inline,  -i:\t\t" 			<< "inline mode print" 					<< std::endl;
	std::cout << "  --hex,  -H:\t\t\t" 				<< "print heximal code"		 			<< std::endl;
	std::cout << "  --dec,  -D:\t\t\t" 				<< "print decimal code"		 			<< std::endl;
	std::cout << "  --help,  -h:\t\t\t" 			<< "print help page and exit" 			<< std::endl;
	
	exit(0);
}