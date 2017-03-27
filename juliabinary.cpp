//
// Mandebrot map for non linear dynamics and chaos
//


// includes

#include <cmath>
#include <complex>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::complex_literals;

// constants

// functions

int julia(complex<double> z, complex<double> c, int n)
{
	z = z*z + c;
	
	//cout << abs(z) << "\n";

	if (abs(z) > 2)
		return 0;
	
	else if (n == 0)
		return 1;	

	else
		return julia(z, c, n-1);	
}

int main()
{
	double xpix = 10000;
	double ypix = 10000;
	double xscale = 2.75;
	double yscale = 2.75;

	// -0.4 +0.6 
	// -0.835 -0.2321
	
	complex<double> c(-0.1,0.651);

	int nitt = 255;
	
	ofstream juliabinary;
	juliabinary.open("juliabinary.pbm");
	
	juliabinary << "P1" << "\n" << xpix << " " << ypix << "\n";
		
	double ymin = -1.35;
	double xmin = -1.35;

	for (double k = 0; k < xpix; k++)
	{
		for (double l = 0; l < ypix; l++)
		{
			double re = xmin + k/xpix*xscale;
			double im = ymin + l/ypix*yscale;	

			complex<double> z0(re,im);
			
			//cout << z0 << " ";

			juliabinary << (julia(z0, c, nitt)) << " ";

			if ( l == ypix - 1)
				juliabinary << "\n";
		}
	}

}























