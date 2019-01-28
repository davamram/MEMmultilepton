#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

using namespace std;

class ConfigParser
{
  public:
  ConfigParser();
  ~ConfigParser();

  void LoadConfig(string);
  void GetConfigFromFile(string);
  void GetHypotheses(int*, string**, int**, int**, int**);

  void ReadIntegrationRange();
  void ReadJetChoice();
  void ReadOptim();

  ifstream fconf;

  int nHyp;
  string* sHyp;
  int* Hyp;
  int *index_hyp;
  
  int doTTLL, doTTHfl, doTTHsl, doTTW, doTTWJJ, doTTbarfl, doTTbarsl, doTLLJ, doWZJJ, doTHJ;
  int nPointsHypTTLL, nPointsHypTTHsl, nPointsHypTTHfl, nPointsHypTTW, nPointsHypTTWJJ, nPointsHypTTbarfl, nPointsHypTTbarsl, nPointsHypTLLJ, nPointsHypWZJJ, nPointsHypTHJ;
  double valJetTFfracmin, valJetTFfracmax, valNeutMaxE;
  string valJetChoice;
  int valOptim, valOptimTopLep, valOptimTopHad, valOptimHiggs, valOptimW;
  double valCsvThresh;
  string valPdf, valMadgraphDir, valTFfile;
  int valGenerator;
  double valComEnergy;
  int valVerbosity;
  int valTFChoice, valTFOption;
  int valDoMinimization;
  int nJetSyst;

  void ReadOptionValue(string*, int*);
  void ReadOptionValue(string*, double*);
  void ReadOptionValue(string*, string*);

  void SetTransferFunction(string);
  void SetMadgraphDir(string);

  private:
};

#endif
