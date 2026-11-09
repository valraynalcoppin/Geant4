# include "ResultsSimu.hh"

#include "G4Run.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

ResultsSimu::ResultsSimu()
    : G4UserRunAction(),
      TotfEdep(0.),
      fNbEvents(0)
{
};

ResultsSimu::~ResultsSimu()
{
}

void ResultsSimu::BeginOfRunAction(const G4Run* run)
{
    TotfEdep=0.;
    fNbEvents=0;
};


void ResultsSimu::AddEdep(G4double edep)
{
    TotfEdep += edep;
    fNbEvents++;
}

void ResultsSimu::EndOfRunAction(const G4Run* run)
{
    /* G4cout << "Results of the Run" << G4endl;

    G4cout << "Number of Events : "
           << fNbEvents
           << G4endl;

    G4cout << "Total energy on the detector: "
           << TotfEdep / MeV
           << " MeV"
           << G4endl;

    if (fNbEvents > 0)
    {
        G4cout << "Energie moyenne par evenement : "
               << TotfEdep / fNbEvents / MeV
               << " MeV"
               << G4endl;
    }*/
}

