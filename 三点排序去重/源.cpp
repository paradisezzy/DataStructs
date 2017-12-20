#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>c
using namespace std;
class Pnt3D {
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Pnt3D() :m_x(0.0), m_y(0.0), m_z(0.0) {};
	Pnt3D(double x, double y, double z) :m_x(x), m_y(y), m_z(z) {};
	bool operator<(const Pnt3D&);
	bool operator==(const Pnt3D&);
	friend ifstream& operator>>(ifstream&, Pnt3D&);
	friend ostream& operator<<(ostream&, Pnt3D&);
};
ifstream& operator>>(ifstream& in, Pnt3D& p) {
	in >> p.m_x >> p.m_y >> p.m_z;
	return in;
}k
ostream& operator<<(ostream&out, Pnt3D&p)
{
	out << p.m_x << " " << p.m_y << " " << p.m_z << endl;
	return out;
}
bool Pnt3D::operator<(const Pnt3D& p) {
	if (m_x < p.m_x)  return true;
	else if (abs(m_x - p.m_x) < 1e-10&&m_y < p.m_y) return true;
	else if (abs(m_x - p.m_x) < 1e-10&&abs(m_y - p.m_y) < 1e-10&&m_z < p.m_z) return true;
	return false;
}
bool Pnt3D::operator==(const Pnt3D&p)
{
	if (abs(m_x - p.m_x) < 1e-10&&abs(m_y - p.m_y) < 1e-10&& abs(m_z - p.m_z < 1e-10))
		return true;
	else
		return false;
}
int main()
{
	/*ofstream outfile("apple.text");
	if(outfile)
	{
	outfile<<3<<4<<5<<endl;
	}
	else{
	cerr << "file can not open!" << endl;
	}*/
	vector<Pnt3D> v;
	ifstream infile("apple.txt");
	if (infile)
	{
		Pnt3D p;
		while (infile >> p)
		{

			cout << p << endl;
			v.push_back(p);
		}
		cerr << v.size() << endl;
	}
	else
	{
		cerr << "file can not open!" << endl;
		exit(0);
	}
	infile.close();
	sort(v.begin(), v.end());
	cerr << v[0];
	int repCount = 0, unRepCount = 0;
	vector<Pnt3D>::iterator it = v.begin();
	while (it != v.end() - 1)
	{
		if (*it == *(it + 1))
		{
			it = v.erase(it);
			++repCount;
		}
		else
		{
			++unRepCount;
			++it;
		}
	

	}
	cout << repCount << " " << ++unRepCount << endl;
	return 0;
}
