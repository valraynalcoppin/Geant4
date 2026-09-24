#include "SensitiveDetector.hh"

#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"


SensitiveDetector::SensitiveDetector(const G4String& name)
    : G4VSensitiveDetector(name),
      fEdep(0.)
{
}

SensitiveDetector::~SensitiveDetector()
{
}

void SensitiveDetector::Initialize(G4HCofThisEvent* hce)
{
    fEdep = 0.;
}

G4bool SensitiveDetector::ProcessHits(
    G4Step* step,
    G4TouchableHistory* history)
{
    fEdep += step->GetTotalEnergyDeposit();
    
    if (step->GetPreStepPoint()->GetStepStatus() == fGeomBoundary)
    {
        G4cout << "\n\n";
        G4cout <<"Particule  "
               << step->GetTrack()->GetParticleDefinition()->GetParticleName()
               <<G4endl;
        G4cout <<"TrackID " 
               <<step->GetTrack()->GetTrackID()
               <<G4endl;
        G4cout <<"ParentID "
               << step->GetTrack()->GetParentID()
               <<G4endl;
        G4ThreeVector pos =
            step->GetPreStepPoint()->GetPosition();
        G4cout <<"Entree dans le detecteur "
               <<"x = " << pos.x() / cm
               <<" cm "
               <<"y = " << pos.y() / cm
               <<" cm "
               <<"z = " << pos.z() / cm 
               <<" cm "
               <<G4endl;

        if (step->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma")
        {
            G4cout <<"\nPosition de creation en cm "
                   << step->GetTrack()->GetVertexPosition() / cm
                   <<G4endl;
            G4cout <<"Energie du gamma au step d'entree"
                   <<step->GetPreStepPoint()->GetKineticEnergy() / MeV
                   <<" MeV "
                   << G4endl;
        }
        
    }


    return true;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent* hce)
{
    G4cout << "Energie deposee = "
           << fEdep / MeV
           << " MeV"
           << G4endl;
}
