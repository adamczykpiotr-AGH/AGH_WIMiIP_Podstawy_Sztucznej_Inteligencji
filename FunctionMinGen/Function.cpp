#include "Function.h"

ftype Function::McCormick_(vector<ftype>& v) {
	ftype x = v[0];
	ftype y = v[1];

	return (ftype) (sin(x + y) + (x - y) * (x - y) - 1.5 * x + 2.5 * y + 1);
}

ftype Function::Himmelblau_(vector<ftype>& v) {
	ftype x = v[0];
	ftype y = v[1];

	return (ftype) (x*x + y - 11) * (x * x + y - 11) + (x + y * y - 7) * (x + y * y - 7);
}

ftype Function::Matyas_(vector<ftype>& v) {
	ftype x = v[0];
	ftype y = v[1];
	
	return (ftype) (0.26 * (x * x + y * y) - 0.48 * x * y);
}

Function::Function(unsigned short function, std::vector<double> precision, double mutationRate) {

	m_mutationRate = mutationRate;

	switch (function) {

		case McCormick: {
			m_function = McCormick_;

			gealib::parameter x("x", -1.5, 4., precision.at(0));
			gealib::parameter y("y", -3.0, 4., precision.at(1));
			m_params = { x, y };

			break;
		}

		case Himmelblau: {
			m_function = Himmelblau_;

			gealib::parameter x("x", -5., 5., precision.at(0));
			gealib::parameter y("y", -5., 5., precision.at(1));
			m_params = { x, y };

			break;
		}

		case Matyas: {
			m_function = Matyas_;

			gealib::parameter x("x", -10., 10., precision.at(0));
			gealib::parameter y("y", -10., 10., precision.at(1));
			m_params = { x, y };

			break;
		}
		
		default: {
			throw new std::exception("Incorrect function name!");
		}
	};
}

void Function::run(size_t iterations, size_t showProgress, std::vector<double>* outcome) {

	gealib::ga ga(m_function);

	for (const auto& param : m_params) {
		ga.add_parameter(param);
	}
	
	ga.set_mutation_rate(m_mutationRate);

	ga.run(iterations, showProgress, outcome, false);
}

std::vector<double> Function::run(size_t iterations, size_t showProgress) {
		
	std::vector<double> returnVec;

	run(iterations, showProgress, &returnVec);

	return returnVec;
}

void Function::print(std::vector<double>* outcome) {

	std::string params = "";

	std::cout << "\nCalculated minimum: \n\n";

	for (size_t i = 0; i < outcome->size(); i++) {
		params += m_params[i].name;
		params += ", ";
		std::cout << m_params[i].name << " = " << (*outcome)[i] << "\n";
	}

	params = params.substr(0, params.length() - 2); //remove last ", "

	std::cout << "f(" << params << ") = " << m_function(*outcome) << "\n\n";
}
