#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "ResultsSimu.hh"

ActionInitialization::ActionInitialization()
{
}

ActionInitialization::~ActionInitialization()
{
}

void ActionInitialization::Build() const
{
    SetUserAction(new PrimaryGeneratorAction());

    SetUserAction(new ResultsSimu());
}
