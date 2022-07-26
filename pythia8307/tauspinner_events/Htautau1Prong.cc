// Headers and Namespaces.
// Include Pythia headers.
#include "Pythia8/Pythia.h"
#ifndef HEPMC2
#include "Pythia8Plugins/HepMC3.h"
#else
#include "Pythia8Plugins/HepMC2.h"
#endif

//Let Pythia8:: be implicit
using namespace Pythia8;

// Important particles
set<int> Particles;

// Get Higgs and its products data
void GetParticles(const Pythia &gen, const int iHiggs)
{
  // Add important particles to the set
  Particles.insert(iHiggs);

  // If the particle decayed
  if(0 > gen.event[iHiggs].status())
    {
      // Get the first and last decay products
      const int First = gen.event[iHiggs].daughter1();
      const int Last  = gen.event[iHiggs].daughter2();

      // For each daughter...
      for(int i = First; i <= Last; i++)
	{
	  // Add all particles from the first decay to the last to the set
	  GetParticles(gen, i);
	};
    };
}

// Display relevant Higgs data
void analyseParticles(const Pythia &gen)
{
  // For all the interesting particles
  for(auto iHiggs : Particles){
    // Print  no and ID
    cout << iHiggs << "\t\t" << gen.event[iHiggs].id() << "\t\t" << gen.event[iHiggs].px() << "\t\t" <<
      gen.event[iHiggs].py() << "\t\t" << gen.event[iHiggs].pz() << "\t\t" << gen.event[iHiggs].pT() <<
      "\t\t" << gen.event[iHiggs].eta() << "\t\t" << gen.event[iHiggs].xProd() << "\t\t" << gen.event[iHiggs].yProd()
         << "\t\t" <<gen.event[iHiggs].zProd() << "\t\t" << gen.event[iHiggs].tProd() << "\t\t"<< gen.event[iHiggs].tau() << 
      "\t\t" << gen.event[iHiggs].y() << endl;
  };
}

// Write data to a file
void writeParticles(const Pythia &gen)
{
  std::ofstream file ("1ProngEvents/HTauTau_1Prong_Validation.txt");
  // For all the interesting particles
  file << "no" << "\t\t" << "id" << "\t\t" << "pX" << "\t\t" << "pY" << "\t\t" << "pZ" <<
    "\t\t" << "pT" << "\t\t" << "eta" << "\t\t" << "X-Prod" << "\t\t" << "Y-Prod" << "\t\t" << "Z-Prod" <<
    "\t\t" << "t-prod" << "\t\t" << "tau" << "\t\t" << "true-eta" << endl;
  for(auto iHiggs : Particles){
    // Write index and id
    file << iHiggs << "\t\t" << gen.event[iHiggs].id() << "\t\t" << gen.event[iHiggs].px() << "\t\t" <<
      gen.event[iHiggs].py() << "\t\t" << gen.event[iHiggs].pz() << "\t\t" << gen.event[iHiggs].pT() <<
      "\t\t" << gen.event[iHiggs].eta() << "\t\t" << gen.event[iHiggs].xProd() << "\t\t" << gen.event[iHiggs].yProd()
	 << "\t\t" <<gen.event[iHiggs].zProd() << "\t\t" << gen.event[iHiggs].tProd() << "\t\t"<< gen.event[iHiggs].tau()
         << "\t\t" << gen.event[iHiggs].y() << endl;
  }
  file.close();
}

// Begin main program
int main(){
  // Interface for conversion from Pythia8::Event to HepMC
  // event. Specify file where HepMC events will be stored.
  Pythia8::Pythia8ToHepMC higgsHepMC("1ProngEvents/HTauTau_1Prong.dat");
  
  // Set up generation 
  // Declare Pythia object
  Pythia8::Pythia gen;
  // Specify the particle collision
  gen.readString("SoftQCD:all = off");
  gen.readString("HardQCD:all = off");
  gen.readString("PDF:pSet = 8");

  // Specify the particle collision
  gen.readString("Beams:idA = 2212");
  gen.readString("Beams:idB = 2212");

  // Set CM energy to 13 TeV
  gen.readString("Beams:eCM = 13000");

  // Set Higgs parity -  1 is even (default), 2 is odd
  gen.readString("HiggsH1:parity = 1");

  // Turn on gg -> H
  gen.readString("HiggsSM::gg2H = on");

  // Force H -> TauTau
  gen.readString("25:onMode = off");
  gen.readString("25:8:onMode = on");

  // Select Tau decays
  gen.readString("15:onMode = off");
  gen.readString("15:0:onMode = on");
  gen.readString("211:onMode = off");
  gen.readString("111:onMode = off");

  // Disable initial and final state radiation
  gen.readString("PartonLevel:FSR = off");
  gen.readString("PartonLevel:ISR = off");

  // Select pion decays
  gen.readString("25:onMode = off");
  gen.readString("25:8:onMode = on");
  
  //pythia.readString("15:onIfMatch = -211 -211 211");
  const int iEvent = 100;
  //const int iHiggs = 0;
  gen.readString("Next:numberShowEvent = 100");
  
  // Initialise and show configuration
  gen.init();
  gen.settings.listChanged();
  gen.particleData.listChanged();
  
  // Generate iEvent events
  for (int i = 0; i < iEvent; i++){
    if(gen.next()){
      // Clear the particle set before every event
      Particles.clear();
      // Get interesting particles and process them
      // (5 chosen as this is where h0 is first seen)
      GetParticles(gen, 5);

      cout << "no" << "\t\t" << "id" << "\t\t" << "pX" << "\t\t" << "pY" << "\t\t" << "pZ" <<
	"\t\t" << "pT" << "\t\t" << "eta" << "\t\t" << "X-Prod" << "\t\t" << "Y-Prod" << "\t\t"
	   << "Z-Prod" << "\t\t" << "t-prod" << "\t\t" << "tau" << "\t\t"<< "true-eta" << endl;
      analyseParticles(gen);
      writeParticles(gen);
      // Construct new empty HepMC event, fill it and write out
      higgsHepMC.writeNextEvent( gen );
    }
    else
      {
	// Oooops
	cerr << "gen.next() returned false" << endl;
      };
      };
  gen.stat();
}
