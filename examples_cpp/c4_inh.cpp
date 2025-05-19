#include <iostream>
using namespace std;

// Base class
class Particle 
{
public:
    float mass;

    // Constructor
    Particle(float mass, float quirkiness, float meanlifetime) 
        : mass(mass), quirkiness(quirkiness), meanlifetime(meanlifetime) 
    { 
        cout << "Particle Constructor Called. Assigning mass, quirkiness, and mean lifetime..." << endl; 
    }

    void ParticleFunction() 
    {
        cout << "Function of Particle Class. Just printing!" << endl;
    }

private:
    float quirkiness;

protected:
    float meanlifetime;
};

// Derived class
class Muon : public Particle 
{
public:
    int charge;
    float spin;

    // Constructor
    Muon(int charge, float spin, float mass, float quirkiness, float meanlifetime) 
        : charge(charge), spin(spin), Particle(mass, quirkiness, meanlifetime) 
    { 
        cout << "Muon Constructor Called. Assigning charge and spin." << endl; 
    }

    void MuonFunction() 
    {
        cout << "Function of Muon Class. Just printing!" << endl;
    }

    void PrintLifeTime()
    {
        cout << "Mean Lifetime: " << meanlifetime << endl; // Accessing protected member from base class
    }
};

int main() 
{
    Muon mu(1, 0.5, 0.1057, 1.0, 10.0);
    mu.MuonFunction();
    mu.ParticleFunction();
    cout << "Charge: " << mu.charge << endl;
    cout << "Spin: " << mu.spin << endl;
    cout << "Mass: " << mu.mass << endl;
    mu.PrintLifeTime(); // Calling function to print meanlifetime
    return 0;
}