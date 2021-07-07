deep_btag_cut=0.2783; //for UL18 => 0.0490: loose, 0.2783: medium, 0.7100: tight 
DAK8_topcut = 0.920; //0.470 ;//1% mistag rate (0.920 // 0.1% mistag)

int nmuon = 0;
for(int mu=0; mu<nmuons; mu++)
  {
    if(muonpt[mu]<30.) continue;  
    if(fabs(muoneta[mu])>2.5)  continue;
    nmuon++;
  }
if (nmuon>0) return kFalse;
if(PFMET<40) return kFalse;

int smljet=0;
int nbjetAK4 = 0;
int nbjetAK4_lead = 0;

float btagwt = 1.;
float btag_eff = 1;

std::vector<TLorentzVector> bjv;

for(int ijet=0; ijet<npfjetAK4; ijet++)
  {
    if(pfjetAK4jetID[ijet]==0) continue;
    if(pfjetAK4btag_DeepFlav[fjet] > deep_btag_cut && abs(pfjetAK4hadronflav[fjet])==5) continue;
    if(fabs(pfjetAK4eta[ijet])>2.5) continue;
    pfjetAK4pt[ijet] *= pfjetAK4JEC[ijet];
    pfjetAK4mass[ijet] *= pfjetAK4JEC[ijet];
    if(isMC)
      {
	pfjetAK4pt[ijet] *= (1+pfjetAK4reso[ijet]) ;
	pfjetAK4mass[ijet] *= (1+pfjetAK4reso[ijet]) ;
      }
    if(pfjetAK4pt[ijet]<50.) continue;
    pfjetAK4pt[fjet] = pfjetAK4pt[ijet];
    pfjetAK4mass[fjet] = pfjetAK4mass[ijet];
    pfjetAK4eta[fjet] = pfjetAK4eta[ijet];
    pfjetAK4y[fjet] = pfjetAK4y[ijet];
    pfjetAK4phi[fjet] = pfjetAK4phi[ijet];
    pfjetAK4hadronflav[fjet] = pfjetAK4hadronflav[ijet];
    pfjetAK4partonflav[fjet] = pfjetAK4partonflav[ijet];
    pfjetAK4btag_DeepFlav[fjet] = pfjetAK4btag_DeepFlav[ijet];
    TLorentzVector bv;
    bv.SetPtEtaPhiM(pfjetAK4pt[fjet],pfjetAK4y[fjet],pfjetAK4phi[fjet],pfjetAK4mass[fjet]);
    bjv.push_back(bv);
    smljet++;
  }
npfjetAK4 = fjet;

  int nelec1 = 0;
  for(int ie=0; ie<nelecs; ie++) {
    if (elpt[ie]<30.) continue;
    if(fabs(eleta[ie])>2.5)  continue; 

     // if(!elmvaid[ie]) continue;

    if(!elmvaid_noIso[ie]) continue;
    elpt[nelec1] = elpt[ie];
    eleta[nelec1] = eleta[ie];
    elphi[nelec1] = elphi[ie];
    elp[nelec1] = elp[ie];
    elmvaid[nelec1] = elmvaid[ie];
    elmvaid_noIso[nelec1] = elmvaid_noIso[ie];
    elpfiso[nelec1] = elpfiso[ie];
    elcharge[nelec1] = elcharge[ie];
     
    nelec1++;
    if(nelec1 >= njetmx) break;
    
  }
  nelecs = nelec1;

