#include <iostream>
class Crayon {
	private:
		std::string color = "";
		int length = 0;
	public:
		Crayon();
		Crayon(const std::string &i, const int &c);
		bool operator==(const Crayon &other) const;
		friend bool isZany(const Crayon &t);
		friend std::ostream &operator<<(std::ostream &out, const Crayon &c);
};
