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

<<<<<<< HEAD
  TH1D* h_ac = new TH1D("h_ac", "sawtooth_ac pdf",  100,  0, 1.0);

// Create a TRandom3 object to generate random numbers

  int seed = 45647;
=======
  TH1D* h_a = new TH1D("h_a", "r1 + r2 - 1", 100, -1.0, 1.0);
  TH1D* h_b = new TH1D("h_b", "r1 + r2 + r3 + r4 - 2", 100, -2.0, 2.0); 
  TH1D* h_c = new TH1D("h_c", "r1 + ... + r12 - 6", 100, -4.0, 4.0);

// Create a TRandom3 object to generate random numbers

  int seed = 54321;
>>>>>>> fb581e936aca423d2695bba25f022d4a73cbf619
  TRandom3* ran = new TRandom3(seed);

// Generate some random numbers and fill histograms

  const int numValues = 10000000;
<<<<<<< HEAD

  for (int i=0; i<numValues; ++i){
    double r = ran->Rndm();             // uniform in ]0,1]
    double x = pow(r,0.5);
    h_saw->Fill(x);
  }
=======
  const double xi = 1.0;               
  int j=0;
  int a=2;
  int b=4;
  int c=12;

  for (int i=0; i<numValues; ++i){            
    double sum_a = 0.0;
    double sum_b = 0.0;
    double sum_c = 0.0;


    for (j=0; j<a; j++){                 // Generate random numbers and sum for part (a)
    double r1 = ran->Rndm();
    sum_a += r1;
}
  sum_a += -1;
  h_a->Fill(sum_a);


    for (j=0; j<b; j++){                 // Generate random numbers and sum for part (b)
    double r2 = ran->Rndm();
    sum_b += r2;
}
  sum_b += -2;
  h_b->Fill(sum_b);


    for (j=0; j<c; j++){                 // Generate random numbers and sum for part (c)
    double r3 = ran->Rndm();
    sum_c += r3;
}
    sum_c += -6;
    h_c->Fill(sum_c);
}  
>>>>>>> fb581e936aca423d2695bba25f022d4a73cbf619

// Store all histograms in the output file and close up

  file->Write();
  file->Close();

  return 0;
}
