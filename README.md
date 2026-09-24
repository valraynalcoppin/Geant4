# Geant4 Electron Detector Simulation

A small Geant4 project developed to learn particle transport, detector simulation, and data collection with C++.

## Overview

This project simulates a beam of high-energy electrons traveling through an air volume and interacting with a silicon detector.

The current simulation includes:

* A cubic air world of 1 m × 1 m × 1 m
* 1 GeV primary electrons
* A beam traveling along the +z direction
* A Gaussian transverse beam profile
* A silicon detector of 10 cm × 10 cm × 1 cm
* A custom sensitive detector
* Energy deposition measurement in the silicon
* Tracking of secondary particles such as gamma rays
* Terminal-based output without graphical visualization

## Current Setup

### Primary beam

The primary particle is an electron (`e-`) with:

* Energy: 1 GeV
* Initial z position: -40 cm
* Direction: +z
* Transverse position: Gaussian distribution
* Beam sigma: 2 cm

For each event, a new transverse position `(x, y)` is generated.

### Detector

The detector is made of silicon (`G4_Si`).

Its dimensions are:

```text
10 cm × 10 cm × 1 cm
```

and it is centered at:

```text
(x, y, z) = (0, 0, 0)
```

Therefore, its front face is located at approximately:

```text
z = -0.5 cm
```

## Sensitive Detector

The silicon volume is associated with a custom `SensitiveDetector`.

For each event, the detector:

1. Resets the deposited energy
2. Processes each `G4Step` occurring in the detector
3. Adds the deposited energy from each step
4. Prints the total deposited energy at the end of the event

The simulation therefore provides an event-by-event measurement of:

```text
Total deposited energy [MeV]
```

The sensitive detector also prints information about particles entering the detector, including:

* Particle type
* Track ID
* Parent ID
* Position at detector entrance
* Particle creation position
* Particle kinetic energy

This makes it possible to study primary and secondary particles.

## Particle Generation and Tracking

The simulation starts with primary electrons:

```text
e- (TrackID = 1, ParentID = 0)
```

Secondary particles can be generated during the simulation.

For example:

```text
e- (TrackID = 1)
   |
   └── gamma (TrackID = 2, ParentID = 1)
```

This allows the study of particle production and transport inside the simulation.

## Running the Simulation

After setting up the Geant4 environment, go to the project build directory:

```bash
cd ~/mon-espace/geant4/MonProjet/build
```

Build the project with:

```bash
cmake --build . -j4
```

Then run:

```bash
./MonProjet
```

The number of simulated events is currently defined in `main.cc` using:

```cpp
runManager->BeamOn(10);
```

## Example Output

Example output from the simulation:

```text
Particule  e-
TrackID 1
ParentID 0
Entree dans le detecteur x = 0.27 cm y = -2.42 cm z = -0.5 cm

Particule gamma
TrackID 2
ParentID 1
Entree dans le detecteur x = 0.25 cm y = -2.42 cm z = -0.5 cm

Position de creation en cm (0.27, -2.42, -19.47)
Energie du gamma 19.12 MeV

Energie deposee = 3.77 MeV
```

## Project Structure

```text
MonProjet/
├── CMakeLists.txt
├── main.cc
├── src
  ├── ActionInitialization.cc
  ├── DetectorConstruction.cc
  ├── PhysicsList.cc
  ├── PrimaryGeneratorAction.cc
  ├── SensitiveDetector.cc
├──include
  ├── ActionInitialization.hh
  ├── DetectorConstruction.hh
  ├── PhysicsList.hh
  ├── PrimaryGeneratorAction.hh
  ├── SensitiveDetector.hh
└── build/
```

## Goals

The main goal of this project is to progressively learn how to build and analyze Geant4 simulations.

Planned developments include:

* Statistical analysis of deposited energy
* Data export
* Multiple detector volumes
* Beam parameter studies
* Magnetic and electric fields

## Learning Approach

This project is mainly a learning exercise.

The simulation is developed progressively to understand the role of the main Geant4 components:

## Requirements

* C++
* Geant4
* CMake
* A C++ compiler
* Linux environment

## Status

**Work in progress**

The project is currently focused on understanding the fundamentals of particle generation, transport, detector sensitivity, energy deposition, and secondary particle tracking.
