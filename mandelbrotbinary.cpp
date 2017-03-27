//
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

int mandelcheck(complex<double> z, complex<double> c, int n)
{
	z = z*z + c;
	
	 //cout << z << " " << c << "\n";

	if (abs(z) > 2)
		return 0;
	
	else if (n == 0)
		return 1;	

	else
		return mandelcheck(z, c, n-1);	
}

int main()
{
	double pix = 10000+1;
	double scale = 0.007/pix;

	int nitt = 50;
	
	//vector<int> pixelArr;
	
	ofstream mandelbinary;
	mandelbinary.open("mandelbinary.pbm");
	
	mandelbinary << "P1" << "\n" << pix << " " << pix << "\n";

	// -0.416 / 0.603
	double xmid = -0.8305;
	double ymid = -0.2353;
 
	for (double k = 0; k < pix; k++)
	{   
		for (double l = 0; l < pix; l++)
		{
			double re = xmid-pix/2*scale + l*scale;
			double im = ymid-pix/2*scale + k*scale;
			
			complex<double> c(re,im);
		
			mandelbinary << (mandelcheck(0, c, nitt)) << " ";

		
			if ( l == pix - 1)
				mandelbinary << "\n";
		}
	}   

}





















