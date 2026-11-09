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
    G4Material* phantomMaterial =
        nist -> FindOrBuildMaterial("G4_WATER");

    /*
    G4Box* solidphantom = 
        new G4Box(
            "Phantom",
            20.0 *cm,
            20.0 *cm,
            20.0 *cm
        );

    G4LogicalVolume* logicphantom =
        new G4LogicalVolume(
            solidphantom,
            phantomMaterial,
            "phantom"
        );

    G4VPhysicalVolume* physicalphantom =
        new G4PVPlacement(
        nullptr,
        G4ThreeVector(0., 0., 0.),
        logicphantom,
        "phantom",
        logicWorld,
        false,
        0,
        true
        ); */

    // Création du volume solide
    G4Box* solidslice =
        new G4Box(
            "slice",
            20.*cm,
            20.*cm,
            1.*mm
        );

    // Création du volume logique 
    G4LogicalVolume* logicslice =
        new G4LogicalVolume(
            solidslice,
            phantomMaterial,
            "slice"
        );

    // Création des 200 volumes physiques
    for (G4int i = 0; i < 200; i++)
    {
        G4double z =
            -20.*cm + (i + 0.5)*2.*mm;

        new G4PVPlacement(
            nullptr,
            G4ThreeVector(0., 0., z),
            logicslice,
            "slice",
            logicWorld,
            false,
            i,
            true
        );
    }




    return physicalWorld;
}
void DetectorConstruction::ConstructSDandField()
{
    SensitiveDetector* sensDet =
        new SensitiveDetector("DetectorWater");

    G4SDManager* sdManager =
        G4SDManager::GetSDMpointer();

    sdManager->AddNewDetector(sensDet);

    SetSensitiveDetector("slice", sensDet);
}

