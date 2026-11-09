#ifndef SensitiveDetector_h
#define SensitiveDetector_h 1

# include "G4VSensitiveDetector.hh"

class G4Step;
class G4TouchableHistory;
class G4HCofThisEvent;

class SensitiveDetector : public G4VSensitiveDetector
{
public :
    SensitiveDetector(const G4String& name);
    ~SensitiveDetector() override;

    void Initialize(G4HCofThisEvent* hce) override;
    G4bool ProcessHits(G4Step* step,
                    G4TouchableHistory* history) override;
    
    void EndOfEvent(G4HCofThisEvent* hce) override;

    G4double GetEdep() const;
private:
    G4double fEdep;
    G4double fEdepSlice[200];

};

#endif
