
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

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

public:
	static void convert(std::string const &str);
};

#endif
