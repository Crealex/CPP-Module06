
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <climits>

class ScalarConverter
{
private:

	// *** CANONICAL METHODS***
	ScalarConverter();
	ScalarConverter(const ScalarConverter& cpy);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter& rhs);

	// *** FIND TYPE METHODS ***

	static bool	_isChar(std::string const &str);
	static bool	_isInt(std::string const &str);
	static bool	_isFloat(std::string const &str);
	static bool	_isSpecialFloat(std::string const &str);
	static bool	_isDouble(std::string const &str);
	static bool	_isSpecialDouble(std::string const &str);

	// *** CONVERS;ION FROM ALL TYPES ***

	static void _convertFromChar(std::string const &str);
	static void _convertFromInt(std::string const &str);
	static void _convertFromFloat(std::string const &str);
	static void _convertFromSpecialFloat(std::string const &str);
	static void _convertFromDouble(std::string const &str);
	static void _convertFromSpecialDouble(std::string const &str);

	// *** PRINT DECIMAL NUMEBRS ***

	static void _printFloat(float const f);
	static void _printDouble(double const d);

	// *** DISPLAY RESULT

	static void _displayResult(int i, char c, float f, double d);

public:
	static void convert(std::string const &str);
};

#endif
