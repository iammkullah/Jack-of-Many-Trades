#ifndef GEOMETRYTESTER_H_
#define GEOMETRYTESTER_H_

#include <string>
#include "Geometry.h"

class GeometryTester {
public:
	GeometryTester();

	// point
	void testa();
	void testb();
	void testc();

	// line
	void testd();
	void teste();
	void testf();

	// rect
	void testg();
	void testh();
	void testi();

	// circle
	void testj();
	void testk();
	void testl();

	// depth, dim, area, polymorphic
	void testm();
	void testn();
	void testo();
	void testp();
	void testq();

	// exceptions
	void testr();
	void tests();
	void testt();

	// scene
	void testu();
	void testv();
	void testw();
	void testx();
	void testy();

	// unused
	void testz();

private:

	// three overloaded versions
	void errorOut_(const std::string& errMsg, unsigned int errBit);
	void errorOut_(const std::string& errMsg, const std::string& errRes, unsigned int errBit);
	void errorOut_(const std::string& errMsg, int errRes, unsigned int errBit);
	void passOut_();

	char error_;
	std::string funcname_;

	std::string blankpage_; // for this cw only!
};

#endif /* GEOMETRYTESTER_H_ */