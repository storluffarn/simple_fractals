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
		return n;
	
	else if (n == 0)
		return 1;	

	else
		return julia(z, c, n-1);	
}

int main()
{
	double pix = 1000+1;	
	double scale = 3/pix;
	double gradient = 1.0;

	complex<double> c(-0.1,0.651);

	int nitt = 255;
	
	ofstream juliabinary;
	juliabinary.open("juliacolor.pgm");
	
	juliabinary << "P2" << "\n" << pix << " " << pix << "\n" << "255" << "\n";
	
	// -0.4 +0.6
	// -0.835 -0.2321
	double ymid = -0.0;
	double xmid = 0.0;
	int pixeldata;

	for (double k = 0; k < pix; k++)
	{
		for (double l = 0; l < pix; l++)
		{
			//double re = xmin + k/xpix*xscale;
			//double im = ymin + l/ypix*yscale;	

			double re = xmid-pix/2*scale + l*scale;
			double im = ymid-pix/2*scale + k*scale;
			  

			complex<double> z0(re,im);
			
			//cout << z0 << endl;
			
			pixeldata = julia(z0, c, nitt);

			if (pixeldata  > 2555 )
				juliabinary << 255 << " ";
			else 
				juliabinary << static_cast<int> (pixeldata/gradient) << " ";

			if ( l == pix - 1)
				juliabinary << "\n";
		}
	}

}























