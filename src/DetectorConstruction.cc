#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"

#include "G4SDManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

DetectorConstruction::DetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    // Gestionnaire des matériaux
    G4NistManager* nist = G4NistManager::Instance();

    // Matériau du monde
    G4Material* worldMaterial =
        nist->FindOrBuildMaterial("G4_AIR");

    // Dimensions du monde
    G4double worldSize = 1.0 * m;

    // Solide du monde
    G4Box* solidWorld =
        new G4Box(
            "World",
            worldSize / 2,
            worldSize / 2,
            worldSize / 2
        );

    // Volume logique du monde
    G4LogicalVolume* logicWorld =
        new G4LogicalVolume(
            solidWorld,
            worldMaterial,
            "World"
        );

    // Volume physique du monde
    G4VPhysicalVolume* physicalWorld =
        new G4PVPlacement(
            nullptr,
            G4ThreeVector(),
            logicWorld,
            "World",
            nullptr,
            false,
            0,
            true
        );

    // Detecteur
    G4Material* detectorMaterial =
        nist -> FindOrBuildMaterial("G4_Si");

    G4double detectorXY = 10.0*cm;
    G4double thickness = 1.0*cm;

    G4Box* soliddetector = 
        new G4Box(
            "detector",
            detectorXY / 2,
            detectorXY / 2,
            thickness / 2
        );

    G4LogicalVolume* logicdetector =
        new G4LogicalVolume(
            soliddetector,
            detectorMaterial,
            "detector"
        );

    G4VPhysicalVolume* physicaldetector =
        new G4PVPlacement(
        nullptr,
        G4ThreeVector(0., 0., 0.),
        logicdetector,
        "detector",
        logicWorld,
        false,
        0,
        true
        );


    return physicalWorld;
}
void DetectorConstruction::ConstructSDandField()
{
    SensitiveDetector* detectorSI =
        new SensitiveDetector("DetectorSI");

    G4SDManager* sdManager =
        G4SDManager::GetSDMpointer();

    sdManager->AddNewDetector(detectorSI);

    SetSensitiveDetector("detector", detectorSI);
}

