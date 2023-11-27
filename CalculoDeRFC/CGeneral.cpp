#include "CGeneral.hpp"

CGeneral::CGeneral()
{
}

CGeneral::~CGeneral()
{
}

// Validar solo letras
bool CGeneral::validarLetras(char* cCadena)
{
	int i = 0;
	while (cCadena[i] != '\0')
	{
		// Validar que solo sean letras
		if (cCadena[i] >= 65 && cCadena[i] <= 90 || cCadena[i] >= 97 && cCadena[i] <= 122 || cCadena[i] == 32)
		{
			i++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

// Validar solo números
bool CGeneral::validarNumeros(char* cCadena)
{
	int i = 0;
	while (cCadena[i] != '\0')
	{
		// Validar que solo sean numeros
		if (cCadena[i] >= 48 && cCadena[i] <= 57)
		{
			i++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

//Validar que la fecha sea valida
bool CGeneral::validarFecha(char* cCadena)
{
	int i = 0;
	int iDia = 0;
	int iMes = 0;
	int iAnio = 0;
	int iContador = 0;

	while (cCadena[i] != '\0')
	{
		// Validar que solo sean números
		if (cCadena[i] >= 48 && cCadena[i] <= 57)
		{
			i++;
		}
		else
		{
			return false;
		}
	}

	iDia = atoi(cCadena);
	iMes = atoi(cCadena + 3);
	iAnio = atoi(cCadena + 6);
	if (iDia > 31 || iDia < 1)
	{
		return false;
	}
	if (iMes > 12 || iMes < 1)
	{
		return false;
	}
	if (iAnio < 1900 || iAnio > 2019)
	{
		return false;
	}

	return true;
}

// Validar que la fecha sea valida con el siguiente formto: dd-mm-aaaa
bool CGeneral::esFechaValida(const std::string& sFecha) 
{	
	// Se obtiene la fecha actual con valores enteros.
	std::istringstream ss(sFecha);
	
	int iDia	= 0;
	int iMes	= 0;
	int iAnio 	= 0;
	char cGuion1 = ' ';
	char cGuion2 = ' ';

	// Se asignan los valores a las variables.
	ss >> iDia >> cGuion1 >> iMes >> cGuion2 >> iAnio;

	// Se valida que la fecha sea correcta.
	if (ss.fail() || cGuion1 != '-' || cGuion2 != '-' || !ss.eof()) 
	{
		return false;
	}

	//std::chrono::year_month_day fechaValidada{ std::chrono::year{iAnio}, std::chrono::month{iMes}, std::chrono::day{iDia} };
	
	return 0;// fechaValidada.ok();
}


std::string CGeneral::convertirMayusculas(std::string sTexto)
{
	for (char& c : sTexto)
	{
		c = toupper(c);
	}
	return sTexto;
}

void CGeneral::convertirCadenaMayusculas(char* cCadena)
{
	for (int i = 0; i < strlen(cCadena); i++)
	{
		cCadena[i] = toupper(cCadena[i]);
	}
}

void CGeneral::convertirCadenaMinusculas(char* cCadena)
{
	for (int i = 0; i < strlen(cCadena); i++)
	{
		cCadena[i] = tolower(cCadena[i]);
	}
}

std::string CGeneral::quitarArticulos(std::string sPalabra)
{
	std::unordered_map<std::string, std::string> mArticulos = {
		{"DEL ", ""},
		{"LOS ", ""},
		{"EL ", ""},
		{"LA ", ""},
		{"LAS ", ""},
		{"DE ", ""},
		{"LA ", ""},
		{"Y ", ""},
		{"A ", ""},
		{"DEL ", ""},
		{"LOS ", ""},
		{"EL ", ""},
		{"LAS ", ""},
		{"DE ", ""},
		{"LA ", ""},
		{"Y ", ""},
		{"A ", ""}
	};

	for (auto const& mArticulo : mArticulos)
	{
		size_t pos = sPalabra.find(mArticulo.first);
		if (pos != std::string::npos)
		{
			sPalabra.replace(pos, mArticulo.first.length(), mArticulo.second);
		}
	}

	return sPalabra;
}

bool CGeneral::esVocal(char letra)
{
	return (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U');
}


char CGeneral::validarNombres(std::string sNombres) 
{
	size_t espacio = sNombres.find(' ');

	if (espacio != std::string::npos) 
	{	
		std::cout << sNombres[espacio + 1] << std::endl;
		return sNombres[espacio + 1];
	}
	else 
	{
		std::cout << sNombres[0] << std::endl;
		return sNombres[0];
	}

	return 0;
}


void CGeneral::calcularHomoclave(std::string sNombreCompleto, std::string sFechaNacimiento, std::string& sRfc)
{
    int  iNum1              = 0;
    int  iNum2              = 0;
    int  i                  = 0;
    int  iDiv               = 0;
    int  iMod               = 0;
    int  nIndice            = 0;
    int  iRfcAnumeroSuma    = 0;
    int  iSumaParcial       = 0;
    int  iModuloVerificador = 0;
    long lValorSuma         = 0L;
    std::stringstream sNombreEnNumero;
    std::string hc          = "";

    std::unordered_map<std::string, int> tablaRFC1 = 
    {
        {"&", 10},
        {"Ñ", 10},
        {"A", 11},
        {"B", 12},
        {"C", 13},
        {"D", 14},
        {"E", 15},
        {"F", 16},
        {"G", 17},
        {"H", 18},
        {"I", 19},
        {"J", 21},
        {"K", 22},
        {"L", 23},
        {"M", 24},
        {"N", 25},
        {"O", 26},
        {"P", 27},
        {"Q", 28},
        {"R", 29},
        {"S", 32},
        {"T", 33},
        {"U", 34},
        {"V", 35},
        {"W", 36},
        {"X", 37},
        {"Y", 38},
        {"Z", 39},
        {"0", 0},
        {"1", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9}
    };

    std::unordered_map<int, std::string> tablaRFC2 = 
    {
        {0, "1"},
        {1, "2"},
        {2, "3"},
        {3, "4"},
        {4, "5"},
        {5, "6"},
        {6, "7"},
        {7, "8"},
        {8, "9"},
        {9, "A"},
        {10, "B"},
        {11, "C"},
        {12, "D"},
        {13, "E"},
        {14, "F"},
        {15, "G"},
        {16, "H"},
        {17, "I"},
        {18, "J"},
        {19, "K"},
        {20, "L"},
        {21, "M"},
        {22, "N"},
        {23, "P"},
        {24, "Q"},
        {25, "R"},
        {26, "S"},
        {27, "T"},
        {28, "U"},
        {29, "V"},
        {30, "W"},
        {31, "X"},
        {32, "Y"}
    };

    std::unordered_map<std::string, int> tablaRFC3 = 
    {
        {"A", 10},
        {"B", 11},
        {"C", 12},
        {"D", 13},
        {"E", 14},
        {"F", 15},
        {"G", 16},
        {"H", 17},
        {"I", 18},
        {"J", 19},
        {"K", 20},
        {"L", 21},
        {"M", 22},
        {"N", 23},
        {"O", 25},
        {"P", 26},
        {"Q", 27},
        {"R", 28},
        {"S", 29},
        {"T", 30},
        {"U", 31},
        {"V", 32},
        {"W", 33},
        {"X", 34},
        {"Y", 35},
        {"Z", 36},
        {"0", 0},
        {"1", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"", 24},
        {" ", 37}
    };
    
    sNombreEnNumero << "0";

    for (char c : sNombreCompleto)
    {
        if (tablaRFC1.count(std::string(1, c)))
        {
            sNombreEnNumero << tablaRFC1[std::string(1, c)];
        }
        else
        {
            sNombreEnNumero << "00";
        }
    }

    for (i = 0; i < sNombreEnNumero.str().length() - 1; i++)
    {
        iNum1 = stoi(std::string(1, sNombreEnNumero.str()[i])) * 10;
        iNum2 = stoi(std::string(1, sNombreEnNumero.str()[i + 1]));
        lValorSuma += (iNum1 + iNum2) * iNum2;
    }

    iDiv    = lValorSuma % 1000;
    iMod    = iDiv % 34;
    iDiv    = (iDiv - iMod) / 34;
    nIndice = 0;
    hc      = "";

    while (nIndice <= 1)
    {
        if (tablaRFC2.count((nIndice == 0) ? iDiv : iMod))
        {
            hc += tablaRFC2[(nIndice == 0) ? iDiv : iMod];
        }
        else
        {
            hc += "Z";
        }

        nIndice++;
    }

    sRfc += hc;

    iRfcAnumeroSuma = 0;
    iSumaParcial = 0;

    for (char c : sRfc)
    {
        if (tablaRFC3.count(std::string(1, c)))
        {
            iRfcAnumeroSuma = tablaRFC3[std::string(1, c)];
            iSumaParcial += (int)(iRfcAnumeroSuma * (14 - (sRfc.find(c) + 1)));
        }
    }

    iModuloVerificador = iSumaParcial % 11;

    if (iModuloVerificador == 0)
    {
        sRfc += "0";
    }
    else
    {
        iSumaParcial = 11 - iModuloVerificador;
        if (iSumaParcial == 10)
        {
            sRfc += "A";
        }
        else
        {
            sRfc += std::to_string(iSumaParcial);
        }
    }
}
