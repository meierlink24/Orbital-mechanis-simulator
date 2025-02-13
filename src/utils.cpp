#include "utils.h"

void printOrbitalElements(const OrbitalElements& elements) {
    std::cout << "Orbital Elements:\n";
    std::cout << "  Semi-major axis (a): " << elements.a << " AU\n";
    std::cout << "  Eccentricity (e): " << elements.e << "\n";
    std::cout << "  Inclination (i): " << elements.i << " degrees\n";
    std::cout << "  Longitude of the ascending node (Ω): " << elements.Ω << " degrees\n";
    std::cout << "  Argument of perihelion (ω): " << elements.ω << " degrees\n";
    std::cout << "  Mean anomaly (M): " << elements.M << " degrees\n";
    std::cout << "  Eccentric anomaly (E): " << elements.E << " radians\n";
}