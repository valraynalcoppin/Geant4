#ifndef ResultsSimu_h
#define ResultsSimu_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class ResultsSimu : public G4UserRunAction
{
    public :
        ResultsSimu();
        ~ResultsSimu() override;
        void BeginOfRunAction(const G4Run* run) override;
        void EndOfRunAction(const G4Run* run) override;
        void AddEdep(G4double edep);
        void AddEventEdep(G4double const fEdepSlice[200]);
        
    private:
    G4double TotfEdep;
    G4int fNbEvents;
    G4double fTotEdepSlice[200];
    G4double fTotMoyEdepSlice[200];
};

#endif
