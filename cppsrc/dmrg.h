#ifndef DMRG_H
#define DMRG_H

#include "block.h"
#include "supblock.h"
#include "setting.h"
#include "gqn.h"
#include "site.h"


/**
The frontend of SNAKE.

	@author Cheng.Guo <Cheng.Guo@physik.lmu.de>

*/
class DMRG{
public:
    DMRG();

    ~DMRG();
    void fDMRG();
    void iDMRG();
    void iDMRG_ReadParameters();
    void tDMRG();
    void FTDMRG();
    void mkdir();
    void iDMRG2tDMRG();
    ///Caculate the average value of onsite operator;
    void CalN();


public:
    int ChainLength;
    int fDMRGSweepTimes;
    int FTDMRGStepNum;
    int tDMRGStepNum;
    int KeptStatesNum;

private:
  Block *left,*right,*newleft,*newright;
  SupBlock *supblock;
	int NewLeftL, NewRightL;
	int fDMRG_finalNewLeftL;
  ///The number of site which are exact.
  //int n;
  vector<GQN> TargetGQN;
  vector<LaGenMatDouble> H;
  vector<LaGenMatComplex> Ut;
  vector<double> HoppingIntegrals;
	vector<double> OnSitePotentials;
	vector<double> TwoSitesInteraction;
    //Trotter terms of the real-time evolution operator
  vector<LaGenMatComplex> rt_OP;
  //The time-dependent Trotter term of the impurity and the first site of the real-time evolution operator
  vector<LaGenMatComplex> rt_td_impurity_OP;

private:
  void fDMRG_Sweep2Right(int StartChainLength, int EndChainLength);
  void iDMRG_ReadFreesites();
  void fDMRG_Sweep2Left(int StartChainLength, int EndChainLength);
    void ReadSavedLRBlocks(int LeftChainLength);
    void AddTwoSites(int LeftChainLength, int RightChainLength);
    void tDMRG_ReadParameters();
};
#endif