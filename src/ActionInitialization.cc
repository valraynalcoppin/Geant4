#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"

ActionInitialization::ActionInitialization()
{
}

ActionInitialization::~ActionInitialization()
{
}

void ActionInitialization::Build() const
{
    SetUserAction(new PrimaryGeneratorAction());
}
