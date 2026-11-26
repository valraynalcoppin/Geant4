# include "ResultsSimu.hh"

#include "G4Run.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
#include <fstream>

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
    for (G4int i=0;i<200;i++){
        fTotEdepSlice[i]=0;
    }
};


void ResultsSimu::AddEdep(G4double edep)
{
    TotfEdep += edep;
    fNbEvents++;
}

void ResultsSimu::AddEventEdep(G4double const fEdepSlice[200])
{
    for (G4int i=0;i<200;i++)
    {
        fTotEdepSlice[i]+=fEdepSlice[i];
        fTotMoyEdepSlice[i]=fTotEdepSlice[i]/10000;
    }
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
    for (G4int i=0;i<200;i++)
    {
    G4cout << "Energy by slice of the run : "
          << fTotEdepSlice[i]
          << " Average Energy : "
          << fTotMoyEdepSlice[i]
          << G4endl;
    }

    std::ofstream file("profil_bragg.csv");
    if (!file.is_open())
    {
        G4cout << "Erreur lors de la creation du fichier" << G4endl;
        return;
    }
    file << "Slice,Profondeur_cm,Energie_moyenne_MeV" << '\n';
    for (G4int i=1; i<200; i++)
    {
        G4double profondeur = -20.0 + (i + 0.5) * 0.2;
        G4double energieMoyenne = fTotEdepSlice[i] / fNbEvents / MeV;
        file << i << ","
            << profondeur <<","
            << energieMoyenne << '\n';
    }
    file.close();
}

