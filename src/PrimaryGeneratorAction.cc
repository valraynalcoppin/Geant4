#include "PrimaryGeneratorAction.hh"
#include "Randomize.hh"

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    fParticleGun = new G4ParticleGun(1);

    G4ParticleTable* particleTable =
        G4ParticleTable::GetParticleTable();

    G4ParticleDefinition* particle =
        particleTable->FindParticle("e-");

    fParticleGun->SetParticleDefinition(particle);

    fParticleGun->SetParticleEnergy(1.0 * GeV);

   

    fParticleGun->SetParticleMomentumDirection(
        G4ThreeVector(0., 0., 1.)
    );
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    G4double sigma = 2.0 * cm;
    G4double x = G4RandGauss::shoot(0., sigma);
    G4double y = G4RandGauss::shoot(0., sigma);

    G4cout << "Position d'envoi "
           << " x = " << x/ cm
           << " cm "
           << " y = " << y / cm
           << " cm "
           << G4endl;

    fParticleGun->SetParticlePosition(
        G4ThreeVector(x, y, -40. * cm)
    );

    fParticleGun->GeneratePrimaryVertex(event);
}
