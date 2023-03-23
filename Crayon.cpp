#include <iostream>

#include "Crayon.h"

Crayon::Crayon() {
	color = "";
	length = 0;
}

Crayon::Crayon(const std::string &i, const int &c) {
	color = i;
	length = c;
}

bool Crayon::operator==(const Crayon &other) const {
	return ((color == other.color) &&
		(length == other.length));
}

bool isZany(const Crayon &t) {
	return (t.color == "Purple");
}

std::ostream &operator<<(std::ostream &out, const Crayon &c) {
	out << c.color << " [" << c.length << "]";
	return out;
}
