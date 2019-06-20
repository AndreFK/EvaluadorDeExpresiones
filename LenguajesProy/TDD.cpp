#include "stdafx.h"
#include "TDD.h"



bool TDD::test() {
	Parser ptest = Parser();
	Parser ptest1 = Parser();
	Parser ptest2 = Parser();
	Parser ptest3 = Parser();
	Parser ptest4 = Parser();

	ptest.buildCommand(test0);
	ptest1.buildCommand(test1);
	ptest2.buildCommand(test2);
	ptest3.buildCommand(test3);
	ptest4.buildCommand(test4);

	ptest.buildPost(ptest.words);
	ptest1.buildPost(ptest1.words);
	ptest2.buildPost(ptest2.words);
	ptest3.buildPost(ptest3.words);
	ptest4.buildPost(ptest4.words);

	byte res = byte{ 0 }; //Feature de c++ 17 -> std::byte

	int i = to_integer<int>(res);

	if (ptest.answer() != 3) {
		cout << "Test 1 fallido!" << " Expected = 3 Result = " << ptest.answer() << endl;
		return false;
	}
	else if (ptest1.answer() != -2) {
		cout << "Test 2 fallido!" << " Expected = -2 Result = " << ptest1.answer() << endl;
		return false;
	}
	else if (ptest2.answer() != i) {
		cout << "Test 3 fallido!" << " Expected = 0 Result = " << ptest2.answer() << endl;
		return false;
	}
	else if (ptest3.answer() != 81) {
		cout << "Test 4 fallido!" << " Expected = 81 Result = " << ptest3.answer() << endl;
		return false;
	}
	else if (ptest4.answer() != 256) {
		cout << "Test 5 fallido!" << " Expected = 256 Result = " << ptest4.answer() << endl;
		return false;
	}
	else {
		cout << "TESTS EXITOSOS" << endl;
		cout << "Test 1 | Expected =   3 | Result = " << ptest.answer() << endl;
		cout << "Test 2 | Expected =  -2 | Result = " << ptest1.answer() << endl;
		cout << "Test 3 | Expected =   0 | Result = " << ptest2.answer() << endl;
		cout << "Test 4 | Expected =  81 | Result = " << ptest3.answer() << endl;
		cout << "Test 5 | Expected = 256 | Result = " << ptest4.answer() << endl;
		return true;
	}

}

TDD::~TDD()
{
}
