#include <iostream>
#include "Function.h"

int main() {

	Function GenMcCormick(McCormick, { 0.00001, 0.000001 }, 0.1);
	GenMcCormick.print(&GenMcCormick.run(50, 10));

	Function GenMatyas(Matyas, { 0.00001, 0.00001 }, 0.5);
	GenMatyas.print(&GenMatyas.run(2000, 200));

	return 0;
}