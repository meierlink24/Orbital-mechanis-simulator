#ifndef ORBITAL_CALCULATIONS_H
#define ORBITAL_CALCULATIONS_H

#include "OrbitalElements.h"

// Function to compute position and velocity in 3D space
void computePositionAndVelocity(const OrbitalElements& elements, long double& x, long double& y, long double& z, long double& vx, long double& vy, long double& vz);

#endif // ORBITAL_CALCULATIONS_H