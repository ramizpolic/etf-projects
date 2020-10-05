#include <iostream>
#include <cmath>

#define SQR(X) (X)*(X)

class Vektor3d {
	double koordinate[3];
	mutable int counter;
	public:
		//Vektor3d() { counter = 0; }
		void Postavi(double x, double y, double z) {
			Vektor3d::koordinate[0] = x; Vektor3d::koordinate[1] = y; Vektor3d::koordinate[2] = z;
			counter = 0;
		}
		void Ocitaj(double &x, double &y, double &z) const {
			x = Vektor3d::koordinate[0]; y = Vektor3d::koordinate[1]; z = Vektor3d::koordinate[2];
		}
		void Ispisi() const {
			std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
			++counter;
		}
		double DajX() const { return koordinate[0]; }
		double DajY() const { return koordinate[1]; }
		double DajZ() const { return koordinate[2]; }
		
		Vektor3d &PostaviX(const double& x) { Vektor3d::koordinate[0] = x; counter = 0; return *this; }
		Vektor3d &PostaviY(const double& y) { Vektor3d::koordinate[1] = y; counter = 0; return *this; }
		Vektor3d &PostaviZ(const double& z) { Vektor3d::koordinate[2] = z; counter = 0; return *this; }
		
		int DajBrojIspisa() const { return counter; };
		
		double DajDuzinu() const { return std::sqrt(SQR(koordinate[0]) + SQR(koordinate[1]) + SQR(koordinate[2])); }
		Vektor3d &PomnoziSaSkalarom(double s) { koordinate[0] *= s; koordinate[1] *= s; koordinate[2] *= s; return *this; }
		Vektor3d &SaberiSa(const Vektor3d &v) { 
			koordinate[0] += v.koordinate[0]; 
			koordinate[1] += v.koordinate[1]; 
			koordinate[2] += v.koordinate[2]; 
			return *this; 
		}
		
		friend Vektor3d ZbirVektora(const Vektor3d& v1, const Vektor3d& v2);
};

Vektor3d ZbirVektora(const Vektor3d& v1, const Vektor3d& v2) {
	Vektor3d v3;
	v3.Postavi(v1.koordinate[0] + v2.koordinate[0], v1.koordinate[1] + v2.koordinate[1], v1.koordinate[2] + v2.koordinate[2]);
	return v3;
}

int main () {

	return 0;
}