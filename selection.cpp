//============================================================================
// Name        : selection.cpp
// Author      : Hikari Vanish
// Version     :
// Copyright   : dszjs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include "ClassChoice.h"
#include "sqlite3.h"
using namespace std;
using namespace course;
void writeToFile(vector<ClassChoice> choiceVec) {
	ofstream ofs("./result.txt", ios::app);
	if (!ofs)
		return;
	ofs << "--------------------------------------" << endl;
	for (vector<ClassChoice>::const_iterator iter = choiceVec.begin();
			iter != choiceVec.end(); ++iter) {
		ofs << iter->schedule << "   ||   " << iter->courseId << endl;
	}
	ofs << endl;
	ofs.flush();
	ofs.close();
}
int main() {

	sqlite3* db;
	sqlite3** dbb = &db;
	int rc;
	const char * dbpath = "./hikari_course.db";
	rc = sqlite3_open(dbpath, dbb);
	if (rc)
		return 1;
	return 0;
}
