/* A simple measurment converter program
 * Written by dev-dmitrii-g*/

#include <iomanip>
#include <getopt.h>
#include <unistd.h>
#include <iostream>
#include <cmath>

#define PROGRAM_NAME "./mc" 
#define VERSION "1.0"
#define AUTHOR "dev-dmitrii-g"

using std::cout, std::cin, std::endl, std::modf, std::fixed, std::setprecision;

/* Displays a hint message */
void hint() 
{
	cout << "Try '" << PROGRAM_NAME << " --help' for more information." << endl; 
}

/* Displays intended program usage */
void help()
{
	cout << "Usage: "<< PROGRAM_NAME << " [OPTION]..." << endl;
	cout << "A command-line utility for bidirectional conversion between metric and imperial units." << endl;
	cout << "  -m, --metric\t\tconvert value from metric to imperial units" << endl;
	cout << "  -i, --imperial\t\tconvert value from imperial to metric units" << endl;
	cout << "  -h, --help\t\tdisplay this help and exit" << endl;
	cout << "  -v, --version\t\toutput version information and exit" << endl;
}

/* Displays intended program usage */
void version()
{
	cout << PROGRAM_NAME << " " << VERSION << endl;
	cout << "Written by " << AUTHOR << "." << endl;
}

/* Converts metric units to imperial units */
void metric()
{
	float m, ft, in, iptr;
	cout << "Enter metric unit (m): "; cin >> m;
	ft = m * 3.28084;
	in = modf(ft, &iptr) * 12;
	cout << floor(ft) << "\'" << fixed << setprecision(2) << in << "\"" << endl;
}

/* Converts imperial units to metric units */
void imperial()
{
	float m, in;
	int ft;
	cout << "Enter imperial unit (ft): "; cin >> ft;
	cout << "Enter imperial unit (in): "; cin >> in;
	m = (ft * 0.3048) + (in * 0.0254);
	cout << fixed << setprecision(2) << m << "m" << endl;
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		hint();
		return 1;
	}

	int opt;
	int option_index = 0;

	static struct option long_options[] = {
		{"help",	no_argument,	0,	'h'},
		{"version",	no_argument,	0,	'v'},
		{"metric",	no_argument,	0,	'm'},
		{"imperial",no_argument,	0,	'i'},
		{0,			0,				0,	0}
	};

	while ((opt = getopt_long(argc, argv, "hvmi", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 'h': help(); break;
			case 'v': version(); break;
			case 'm': metric(); break;
			case 'i': imperial(); break;
			default: hint(); return 1;
		}
	}
	return 0;
}
