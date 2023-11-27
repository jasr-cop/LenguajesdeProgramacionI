#include <string>
#include <iostream>
#include <regex>
#include <locale>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <conio.h>

#include "CGeneral.hpp"

#pragma once
class CEmpleado
{
public:
	CEmpleado();
	~CEmpleado();
	std::string generaRfc(std::string& sNombre, std::string& sAppPaterno, std::string& sAppMaterno, std::string& sFechaNacimiento);

	bool validarFecha(std::string const& fechaNacimiento);

private:

	std::string sNombre;
	std::string sApellidoPaterno;
	std::string sApellidoMaterno;
	std::string sRfc;
	int iDia;
	int iMes;
	int iAnio;
	
	

};

