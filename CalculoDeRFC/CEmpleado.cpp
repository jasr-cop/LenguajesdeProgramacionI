#include "CEmpleado.hpp"

#include <algorithm>
#include <array>
#include <iostream>

CEmpleado::CEmpleado() : 
	sNombre(""), 
	sApellidoPaterno(""), 
	sApellidoMaterno(""), 
	iDia(0), 
	iMes(0), 
	iAnio(0)
{
}

CEmpleado::~CEmpleado()
{
}

std::string CEmpleado::generaRfc(std::string& sNombre, std::string& sAppPaterno, std::string& sAppMaterno, std::string& sFechaNacimiento)
{
	CGeneral objGeneral;

	std::string sRfc = "";
	
	sNombre				= objGeneral.convertirMayusculas(sNombre);
	sApellidoPaterno	= objGeneral.convertirMayusculas(sAppPaterno);
	sApellidoMaterno	= objGeneral.convertirMayusculas(sAppMaterno);
	sApellidoPaterno	= objGeneral.quitarArticulos(sApellidoPaterno);
	sApellidoMaterno	= objGeneral.quitarArticulos(sApellidoMaterno);

	sRfc += sApellidoPaterno[0];


	for (char c : sApellidoPaterno)
	{
		if (objGeneral.esVocal(c))
		{
			sRfc += c;
			break;
		}
	}

	sRfc += sApellidoMaterno[0];

	sRfc += objGeneral.validarNombres(sNombre);
	//sRfc += sNombre[0];
	//11011978
	sRfc += sFechaNacimiento.substr(6, 2) + sFechaNacimiento.substr(2, 2) + sFechaNacimiento.substr(0, 2);

	objGeneral.calcularHomoclave(sApellidoPaterno + " " + sApellidoMaterno + " " + sNombre, sFechaNacimiento, sRfc);

	std::cout << "RFC: " << sRfc << std::endl;

	return sRfc;
}

bool CEmpleado::validarFecha(std::string const &fechaNacimiento)
{
	std::regex fechaFormato("\\d{2}-\\d{2}-\\d{4}");
	
	if (!std::regex_match(fechaNacimiento, fechaFormato)) 
	{
		return false;
	}

	int dia = std::stoi(fechaNacimiento.substr(0, 2));
	int mes = std::stoi(fechaNacimiento.substr(3, 2));
	
	if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
		return false;
	}
	
	return true;
}