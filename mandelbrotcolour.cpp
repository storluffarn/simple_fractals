//
//
// Mandebrot map for non linear dynamics and chaos
//

// includes

#include <cmath>
#include <complex>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::complex_literals;

// constants

// functions

int mandelcheck(complex<double> z, complex<double> c, int n)
{
	z = z*z + c;
	
	if (abs(z) > 2)
		return n;
	
	else if (n == 0)
		return 0;	

	else
		return mandelcheck(z, c, n-1);	
}

int main()
{
	double pix = 10000+1;
	double scale = 0.007/pix;
	int gradient = 8;

	int nitt = 50;
	
	ofstream mandelbinary;
	mandelbinary.open("mandelcolour.pgm");
	
	mandelbinary << "P2" << "\n" << pix << " " << pix << "\n" << "255" << "\n";

		
	// -0.4 +0.6
	// -0.835 -0.2321

	// -0.4243 +0.6095
	// -0-8305 -0.2353
		
	double xmid = -0.8305;
	double ymid = -0.2353;

	for (double k = 0; k < pix; k++)
	{
		for (double l = 0; l < pix; l++)
		{
			double re = xmid-pix/2*scale + l*scale;
			double im = ymid-pix/2*scale + k*scale;

			complex<double> c(re,im);
			//cout << c << endl;
			
			double pixeldata = gradient*(mandelcheck(0, c, nitt));
			
			if (pixeldata >= 255)
			   	mandelbinary << 255  << " ";
			
			else mandelbinary << pixeldata  << " ";

			if ( l == pix - 1)
				mandelbinary << "\n";
		}
	}
}























