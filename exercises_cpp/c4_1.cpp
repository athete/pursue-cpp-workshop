#include <iostream>
#include <cmath>
#include <string>

class Particle 
{
protected:
    std::string name;
    double mass; // in MeV/c^2
    double charge; // in elementary charge units

public:
    Particle(std::string n, double m, double c) : name(n), mass(m), charge(c) {}

    virtual void displayInfo() = 0; // Pure virtual function for displaying info

    double computeEnergy(double fractionOfC) 
    {
        double c = 299792458; // Speed of light in m/s
        double v = fractionOfC * c;
        double gamma = 1 / std::sqrt(1 - (v * v) / (c * c));
        return gamma * mass * 1e6; // Energy in eV (1 MeV = 1e6 eV)
    }

    std::string getName() const 
    {
        return name;
    }

    virtual ~Particle() {}
};

class Electron : public Particle 
{
    ...
};

class Muon : public Particle 
{
    ...
};

class Tau : public Particle 
{
    ...
};

int main() 
{
    ...

    return 0;
}