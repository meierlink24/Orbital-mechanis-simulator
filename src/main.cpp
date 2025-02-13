#include "OrbitalElements.h"
#include "orbital_calculations.h"
#include "utils.h"
#include <iostream>

int main() {
    // Example: Earth's orbital elements (approximate values)
    OrbitalElements earthOrbit(
        1.00000011L,   // Semi-major axis (AU)
        0.01671022L,   // Eccentricity
        0.00005L,      // Inclination (degrees)
        -11.26064L,    // Longitude of the ascending node (degrees)
        102.94719L,     // Argument of perihelion (degrees)
        356.0470L,      // Mean anomaly (degrees)
        2451545.0L      // Reference epoch (J2000.0)
    );

    // Set the current time (days since epoch)
    earthOrbit.t = 2451545.0L + 365.25L; // 1 year after epoch

    // Compute the mean anomaly at the current time
    earthOrbit.M = earthOrbit.M0 + earthOrbit.n * (earthOrbit.t - earthOrbit.t0);

    // Compute the eccentric anomaly
    earthOrbit.computeEccentricAnomaly();

    // Print the orbital elements
    printOrbitalElements(earthOrbit);

    // Compute and print the position and velocity
    long double x, y, z, vx, vy, vz;
    computePositionAndVelocity(earthOrbit, x, y, z, vx, vy, vz);

    std::cout << "Position (x, y, z): (" << x << ", " << y << ", " << z << ") AU\n";
    std::cout << "Velocity (vx, vy, vz): (" << vx << ", " << vy << ", " << vz << ") AU/day\n";

    return 0;
}