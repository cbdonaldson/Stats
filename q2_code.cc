// Program to illustrate use of ROOT random number and histogram classes
// Glen Cowan, RHUL, Physics, November 2007

#include <iostream>
#include <cmath>
#include <TH1D.h>
#include <TFile.h>
#include <TRandom3.h>

using namespace std;

int main(){

// Open output file (apparently needs to be done before booking)

  TFile* file = new TFile("simpleMC.root", "recreate");

// Book histograms

  TH1D* h_saw = new TH1D("h_saw", "sawtooth pdf",  100,  0, 1.0);

// Create a TRandom3 object to generate random numbers

  int seed = 45617;
  TRandom3* ran = new TRandom3(seed);

// Generate some random numbers and fill histograms

  const int numValues = 10000000;

  for (int i=0; i<numValues; ++i){
    double r = ran->Rndm();             // uniform in ]0,1]
    double x = pow(r,0.5);
    h_saw->Fill(x);
  }

// Store all histograms in the output file and close up

  file->Write();
  file->Close();

  return 0;
}
