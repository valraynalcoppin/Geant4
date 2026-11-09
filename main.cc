#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"

int main()
{
    auto* runManager = new G4RunManager();

    //Geometrie
    runManager->SetUserInitialization(
        new DetectorConstruction()
    );

    //physique
    runManager->SetUserInitialization(
        new PhysicsList()
    );

    //Actions
    runManager->SetUserInitialization(
        new ActionInitialization()
    );

    //Initialisation
    runManager->Initialize();

    runManager->BeamOn(10000);

    delete runManager;

    return 0;
}
