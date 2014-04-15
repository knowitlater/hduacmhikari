/*
 * ClassChoice.cpp
 *
 *  Created on: 2014Äê2ÔÂ23ÈÕ
 *      Author: LENOVO
 */

#include "ClassChoice.h"

namespace course {
bool ClassChoice::conflictsWith(ClassChoice& c) {
	if (this->courseId == c.courseId)
		return true;
	for (int i = 0; i < 64; i++) {
		if (this->schedule[i] == '1' && c.schedule[i] == '1')
			return true;
	}
	return false;
}
ClassChoice::ClassChoice(int cid, std::string sc) :
		courseId(cid), schedule(sc) {
}
ClassChoice::ClassChoice() :
		courseId(0), schedule("") {

}

ClassChoice::~ClassChoice() {
}

} /* namespace std */
