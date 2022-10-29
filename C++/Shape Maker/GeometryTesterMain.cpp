#include <iostream>
#include "GeometryTester.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

	for(int i=1; i<argc; i++) {
		switch (argv[i][0]) {
		case 'a': { GeometryTester t; t.testa(); } break;
		case 'b': { GeometryTester t; t.testb(); } break;
		case 'c': { GeometryTester t; t.testc(); } break;
		case 'd': { GeometryTester t; t.testd(); } break;
		case 'e': { GeometryTester t; t.teste(); } break;
		case 'f': { GeometryTester t; t.testf(); } break;
		case 'g': { GeometryTester t; t.testg(); } break;
		case 'h': { GeometryTester t; t.testh(); } break;
		case 'i': { GeometryTester t; t.testi(); } break;
		case 'j': { GeometryTester t; t.testj(); } break;
		case 'k': { GeometryTester t; t.testk(); } break;
		case 'l': { GeometryTester t; t.testl(); } break;
		case 'm': { GeometryTester t; t.testm(); } break;
		case 'n': { GeometryTester t; t.testn(); } break;
		case 'o': { GeometryTester t; t.testo(); } break;
		case 'p': { GeometryTester t; t.testp(); } break;
		case 'q': { GeometryTester t; t.testq(); } break;
		case 'r': { GeometryTester t; t.testr(); } break;
		case 's': { GeometryTester t; t.tests(); } break;
		case 't': { GeometryTester t; t.testt(); } break;
		case 'u': { GeometryTester t; t.testu(); } break;
		case 'v': { GeometryTester t; t.testv(); } break;
		case 'w': { GeometryTester t; t.testw(); } break;
		case 'x': { GeometryTester t; t.testx(); } break;
		case 'y': { GeometryTester t; t.testy(); } break;
		case 'z': { GeometryTester t; t.testz(); } break;
		default: { cout << "Options are a -- y." << endl; } break;
	       	}
	}
	return 0;
}
